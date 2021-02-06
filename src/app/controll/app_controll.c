/* ============================================================ */
/* ファイル名 : app_controll.c                                  */
/* 機能       : コントローラ                                    */
/* ============================================================ */
#define SECTION_APP

/* ============================================================ */
/* インクルード                                                 */
/* ============================================================ */
/* プロジェクト共通 */
#include "prj_cmn_section.h"
#include "prj_cmn_option.h"
#include "prj_cmn_type.h"
#include "prj_cmn_macro.h"

/* カテゴリ共通 */
#include "app_cmn_option.h"
#include "app_cmn_option_pac.h"

/* 個別 */

/* 本体 */
#include "app_controll.h"
#include "app_controll_pac.h"

/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */


/* ============================================================ */
/* 型定義                                                       */
/* ============================================================ */


/* ============================================================ */
/* 関数プロトタイプ宣言(static)                                 */
/* ============================================================ */
/* 定期処理 */
static void vd_s_CtrlMtrForward(U1 u1_a_block, U4 u4_a_speed);
static void vd_s_CtrlMtrTurn(S2 s2_a_angle);
static void vd_s_CtrlMtrStop(void);
static void vd_s_CtrlMtrWait(void);

/* 割り込み処理 */
static void vd_s_IntDrvAcclControll(void);
static void vd_s_int_AttitudeControl(void);
static void vd_s_CtrlMtuPulse(void);

/* ============================================================ */
/* 変数定義(extern)                                             */
/* ============================================================ */


/* ============================================================ */
/* 変数定義(static)                                             */
/* ============================================================ */
/* 走行設定 */
static U4 u4_s_TimerCount;                        /* 1mSごとにカウントアップされる変数(割り込み処理) */
static U4 u4_s_StepCountR;                        /* 右モータ1stepごとにカウントアップされる変数(割り込み処理) */
static U4 u4_s_StepCountL;                        /* 左モータ1stepごとにカウントアップされる変数(割り込み処理) */

static U4 u4_s_CurrentSpeedR;                     /* 右モーター 現在速度 */
static U4 u4_s_CurrentSpeedL;                     /* 左モーター 現在速度 */
static U4 u4_s_MaxSpeedR;                         /* 右モーター 最高速度 */
static U4 u4_s_MaxSpeedL;                         /* 左モーター 最高速度 */
static U4 u4_s_AccelValue;                        /* 加速値 */
static U4 u4_s_AccelCount;                        /* 最高速度に達したカウント */
static U4 u4_s_StepCount;                         /* 走行ステップ数 */
static U1 u1_s_PidMode;                           /* 姿勢制御(PID)機能 有効/無効フラグ */

/* HWへ渡すパラメータ */
static U2 u2_s_CycleTimeR;                        /* 右モータ周期とパルス幅(割り込み処理) */
static U2 u2_s_CycleTimeL;                        /* 左モータ周期とパルス幅(割り込み処理) */
static S1 s1_s_MtrModeR;                          /* 右モーター モード */
static S1 s1_s_MtrModeL;                          /* 左モーター モード */
static U1 u1_s_MtrPowerMode;                      /* モーター励磁 ON/OFF設定 */

/* ============================================================ */
/* const変数定義(extern)                                        */
/* ============================================================ */


/* ============================================================ */
/* const変数定義(static)                                        */
/* ============================================================ */


/* ============================================================ */
/* 関数形式マクロ定義                                           */
/* ============================================================ */


/* ============================================================ */
/* 関数定義                                                     */
/* ============================================================ */
/* ============================================================ */
/* 関数名 : vd_g_InitializeController                           */
/*          初期化処理                                          */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : モジュールで使用する変数の初期化を行う              */
/* 制約   : メイン処理実行前にコールすること                    */
/* ============================================================ */
void vd_g_InitializeController(void)
{
    u4_s_TimerCount    = (U4)0;                   /* 1mSごとにカウントアップされる変数 */
    u4_s_StepCountR    = (U4)0;                   /* 右モータ1stepごとにカウントアップされる変数 */
    u4_s_StepCountL    = (U4)0;                   /* 左モータ1stepごとにカウントアップされる変数 */
    u4_s_CurrentSpeedR = (U4)0;                   /* 右モーター 現在速度 */
    u4_s_CurrentSpeedL = (U4)0;                   /* 左モーター 現在速度 */
    u4_s_MaxSpeedR     = (U4)0;                   /* 右モーター 最高速度 */
    u4_s_MaxSpeedL     = (U4)0;                   /* 左モーター 最高速度 */
    u4_s_AccelValue    = (U4)0;                   /* 加速値 */
    u4_s_AccelCount    = (U4)0;                   /* 最高速度に達したカウント */
    u4_s_StepCount     = (U4)0;                   /* 走行ステップ数 */
    s1_s_MtrModeR      = (S1)MTR_STOP;            /* 右モーター モード */
    s1_s_MtrModeL      = (S1)MTR_STOP;            /* 左モーター モード */
    u1_s_PidMode       = (U1)0;                   /* 姿勢制御(PID)機能 有効/無効フラグ */
    u1_s_MtrPowerMode  = (U1)MTR_OFF;             /* モーター励磁 OFF設定 */
}

/* ============================================================ */
/* 関数名 : u1_jdgStepChange                                    */
/*          走行制御                                            */
/* 引数   : なし                                                */
/* 戻り値 : 判定結果(0:正常, 1:異常)                            */
/* 概要   : 走行制御を行う(仮)                                  */
/* 制約   :                                                     */
/* ============================================================ */
U1 u1_jdgStepChange(void)
{
    U1 u1_t_return;

    if(u4_s_StepCountR < u4_s_StepCount || u4_s_StepCountL < u4_s_StepCount){
        u1_t_return = (U1)0;
    }
    else{
        u1_t_return = (U1)1;
    }

    return(u1_t_return);
}

/* ************************************************************************/
/* ************************************************************************/
/* 仮置きコード */
/* plannerの指示を受ける */
static U1 u1_s_next_act;
static U1 u1_s_next_block;
void vd_set_NextActFW(U1 u1_a_next_block)
{
    u1_s_next_act  = VHECLE_FORWORD;
    u1_s_next_block = u1_a_next_block;
}
void vd_set_NextActTurnRight(void)
{
    u1_s_next_act  = VHECLE_TURNRIGHT;
    u1_s_next_block = 0;
}
void vd_set_NextActTurnLeft(void)
{
    u1_s_next_act  = VHECLE_TURNLEFT;
    u1_s_next_block = 0;
}
void vd_set_NextActTurnBack(void)
{
    u1_s_next_act  = VHECLE_TURNBACK;
    u1_s_next_block = 0;
}
void vd_set_NextActStop(void)
{
    u1_s_next_act  = VHECLE_STOP;
    u1_s_next_block = 0;
}

/* ************************************************************************/
/* ************************************************************************/

/* ============================================================ */
/* 関数名 : vd_ControllerMainTask                               */
/*          走行制御(定期処理)                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 走行制御を行う                                      */
/* 制約   : なし                                                */
/* ============================================================ */
void vd_ControllerMainTask(void)
{
    U1 u1_t_next_act;
    U1 u1_t_next_block;

    /* 左右のモータが走行ステップ数に達するまで待機 */
    if(u4_s_StepCountR < u4_s_StepCount || u4_s_StepCountL < u4_s_StepCount){
       vd_s_CtrlMtrWait();
    }
    else{
/* ************************************************************************************************************************** */
/* *********************************** */
/* plannnerの指示を受け取る            */
/* *********************************** */
        u1_t_next_act = u1_s_next_act;
        u1_t_next_block = u1_s_next_block;

/* *********************************** */
/* 何ブロック進む？の情報取得する */
/* vd_s_CtrlMtrForwardの 1stに設定 */
/* *********************************** */

/* ************************************************************************************************************************** */
        /* プランナ指示の元、次回制御を設定 */
        if(u1_t_next_act == (U1)VHECLE_FORWORD){
            vd_s_CtrlMtrForward((U1)1,(U4)NORMAL_SPEED);
        }
        else if(u1_t_next_act == (U1)VHECLE_TURNRIGHT){
            vd_s_CtrlMtrTurn((S2)90);
        }
        else if(u1_t_next_act == (U1)VHECLE_TURNLEFT){
            vd_s_CtrlMtrTurn((S2)-90);
        }
        else if(u1_t_next_act == (U1)VHECLE_TURNBACK){
            vd_s_CtrlMtrTurn((S2)180);
        }
        else {
            vd_s_CtrlMtrStop();
        }
    }
}

/* ============================================================ */
/* 関数名 : vd_s_CtrlMtrForward                                 */
/*          モーター処理（前進）                                */
/* 引数   : int i_block  区画数(半区画=1)                       */
/*        : int i_speed  目標速度                               */
/* 戻り値 : なし                                                */
/* 概要   : 距離、目標速度を指定して左右のモーターを前進する    */
/* 制約   : なし                                                */
/* ============================================================ */
static void vd_s_CtrlMtrForward(U1 u1_a_block, U4 u4_a_speed)
{
    //ステップカウントクリア
    u4_s_StepCountR = 0;
    u4_s_StepCountL = 0;

    //現在速度を最低速度に設定する。
    u4_s_CurrentSpeedR = (S4)MIN_SPEED;
    u4_s_CurrentSpeedL = (S4)MIN_SPEED;

    //走行ステップ数算出
    u4_s_StepCount = (U4)(((FL)u1_a_block / (FL)ONE_BLOCK) * ((FL)BLOCK_LENGTH / (FL)STEP_LENGTH));

    //最高速度
    u4_s_MaxSpeedR = u4_a_speed;
    u4_s_MaxSpeedL = u4_a_speed;

    //加速値
    u4_s_AccelValue = ACCEL_VALUE;
    u4_s_AccelCount = 0;

    //モーター処理（前進）
    s1_s_MtrModeR = (S1)MTR_RUN;
    s1_s_MtrModeL = (S1)MTR_RUN;

    /* モータ励磁をON */
    u1_s_MtrPowerMode = (U1)MTR_ON;
}

/* ============================================================ */
/* 関数名 : vd_s_CtrlMtrTurn                                    */
/*          モーター処理（旋回）                                */
/* 引数   : S2 s2_a_angle … 旋回角度(°)                       */
/*             > 0 … 右旋回                                    */
/*             < 0 … 左旋回                                    */
/* 戻り値 : なし                                                */
/* 概要   : 回転角度を指定して旋回する                          */
/* 制約   : なし                                                */
/* ============================================================ */
static void vd_s_CtrlMtrTurn(S2 s2_a_angle)
{
    U2  u2_t_angle;                               /* 旋回角度 */

    /* モータ励磁をON */
    u1_s_MtrPowerMode = (U1)MTR_ON;

    /* 回転方向を決定 */
    if(s2_a_angle > 0){
        /* 右旋回 */
        u2_t_angle    = s2_a_angle;
        s1_s_MtrModeR = (S1)MTR_BACK;             /* 右モーター後進 */
        s1_s_MtrModeL = (S1)MTR_RUN;              /* 左モーター前進 */
    }
    else{
        /* 左旋回 */
        u2_t_angle      = -s2_a_angle;
        s1_s_MtrModeR = (S1)MTR_RUN;              /* 右モーター前進 */
        s1_s_MtrModeL = (S1)MTR_BACK;             /* 左モーター後進 */
    }

    /* ステップカウントクリア */
    u4_s_StepCountR = (U4)0;
    u4_s_StepCountL = (U4)0;

    /* 現在速度を最低速度に設定する */
	u4_s_CurrentSpeedR = (U4)MIN_SPEED;
	u4_s_CurrentSpeedL = (U4)MIN_SPEED;

    /* 走行ステップ数算出 */
    u4_s_StepCount = (int)((float)TREAD_CIRCUIT * ((float)u2_t_angle / (float)360.0) / (float)STEP_LENGTH);

    /* 最高速度 */
    u4_s_MaxSpeedR = TURN_SPEED;
    u4_s_MaxSpeedL = TURN_SPEED;

    /* 加速値 */
    u4_s_AccelValue = ACCEL_VALUE;
    u4_s_AccelCount = 0;
}

/* ============================================================ */
/* 関数名 : vd_s_CtrlMtrStop                                    */
/*          モーター処理（停止）                                */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : その場で停止する                                    */
/* 制約   : なし                                                */
/* ============================================================ */
static void vd_s_CtrlMtrStop(void)
{
    /* モーター処理（停止） */
    s1_s_MtrModeR = (S1)MTR_STOP;
    s1_s_MtrModeL = (S1)MTR_STOP;

    /* モータ励磁をOFF */
    u1_s_MtrPowerMode = (U1)MTR_OFF;
}

/* ============================================================ */
/* 関数名 : vd_s_CtrlMtrWait                                    */
/*          モーター処理                                        */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : モータが指定ステップ数まで回転するのを待つ          */
/*          減速地点になったら減速する                          */
/* 制約   : なし                                                */
/* ============================================================ */
static void vd_s_CtrlMtrWait(void)
{
    if(u4_s_AccelValue > 0){
        /* 加速中 */
        if(u4_s_AccelCount != 0){
            if(((u4_s_StepCount - u4_s_StepCountR) < u4_s_AccelCount) || ((u4_s_StepCount - u4_s_StepCountL) < u4_s_AccelCount)){
                /* 減速地点になったら減速を開始 */
                u4_s_AccelValue = - (S4)ACCEL_VALUE;
            }
        }
        else{
            if((u4_s_StepCount <= u4_s_StepCountR * (U4)2) || (u4_s_StepCount <= u4_s_StepCountL * (U4)2)){
                /* 中間地点になったら減速を開始 */
                u4_s_AccelValue = - (S4)ACCEL_VALUE;
            }
        }
    }
}

/* ============================================================ */
/* 割り込み処理                                                 */
/* ============================================================ */
/* ============================================================ */
/* 関数名 : vd_g_IntDmtrR                                       */
/*          右モーターMTU割込み処理                             */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 右モーターが１ステップ進む毎の割込み                */
/* 制約   : なし                                                */
/* ============================================================ */
void vd_g_IntDmtrR(void)
{
    /* ステップ数をカウント */
    u4_s_StepCountR++;
}

/* ============================================================ */
/* 関数名 : vd_g_IntDmtrL                                       */
/*          左モーターMTU割込み処理                             */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 左モーターが１ステップ進む毎の割込み                */
/* 制約   : なし                                                */
/* ============================================================ */
void vd_g_IntDmtrL(void)
{
    /* ステップ数をカウント */
    u4_s_StepCountL++;
}

/* ============================================================ */
/* 関数名 : vd_s_IntDrvControll                                 */
/*          タイマー割込み(1ms)                                 */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 関数箱型コメントの形式を示す                        */
/* 制約   : なし                                                */
/* ============================================================ */
void vd_s_IntDrvControll(void)
{
    /* 加減速制御 */
    vd_s_IntDrvAcclControll();

    /* 姿勢制御 */
    vd_s_int_AttitudeControl();

    /* モータ出力周波数演算 */
    vd_s_CtrlMtuPulse();
}

/* ============================================================ */
/* 関数名 : vd_s_IntDrvAcclControll                             */
/*          加減速制御                                          */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 右車輪速度/左車輪速度/加速度インデックスを更新する  */
/* 制約   : なし                                                */
/* ============================================================ */
static void vd_s_IntDrvAcclControll(void)
{
    /* 1msごとにカウントアップ */
    u4_s_TimerCount++;            //

    /* 加減速 */
    u4_s_CurrentSpeedR += u4_s_AccelValue;
    u4_s_CurrentSpeedL += u4_s_AccelValue;

    /* 最低速度チェック */
    if(u4_s_CurrentSpeedR != (U4)0 && u4_s_CurrentSpeedR < (U4)MIN_SPEED){
        u4_s_CurrentSpeedR = (U4)MIN_SPEED;
    }
    if(u4_s_CurrentSpeedL != (U4)0 && u4_s_CurrentSpeedL < (U4)MIN_SPEED){
        u4_s_CurrentSpeedL = (U4)MIN_SPEED;
    }

    /* 最高速度チェック */
    if(u4_s_CurrentSpeedR > u4_s_MaxSpeedR){
        u4_s_CurrentSpeedR = u4_s_MaxSpeedR;
        if(u4_s_AccelCount == (U4)0){
            u4_s_AccelCount = u4_s_StepCountR;
        }
    }
    if(u4_s_CurrentSpeedL > u4_s_MaxSpeedL){
        u4_s_CurrentSpeedL = u4_s_MaxSpeedL;
        if(u4_s_AccelCount == (U4)0){
            u4_s_AccelCount = u4_s_StepCountL;
        }
    }
}

/* ============================================================ */
/* 関数名 : vd_s_int_AttitudeControl                            */
/*          姿勢制御割り込み制御                                */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 関数箱型コメントの形式を示す                        */
/* 制約   : なし                                                */
/* ============================================================ */
static void vd_s_int_AttitudeControl(void)
{
    S4 s4_t_sen_diff;                             /* 偏差用変数 */
    S4 s4_t_r_sen;                                /* 右センサ値 */
    S4 s4_t_l_sen;                                /* 左センサ値 */
    S4 s4_t_r_sen_ref;                            /* 中央に置いた時の右センサリファレンス */
    S4 s4_t_l_sen_ref;                            /* 中央に置いた時の左センサリファレンス */
    U1 u1_t_r_wall_flag;                          /* 右に壁があるかどうかのフラグ */
    U1 u1_t_l_wall_flag;                          /* 左に壁があるかどうかのフラグ */

    FL fl_t_control_motor;

    /* 1ならば姿勢制御をする */
    if(u1_s_PidMode == 1){
/* ************************************************************************************************************************** */
/*  センサから情報を取得   */

        s4_t_r_sen = 0;
        s4_t_l_sen = 0;
        s4_t_r_sen_ref = 0;
        s4_t_l_sen_ref = 0;
        u1_t_r_wall_flag = 0;
        u1_t_l_wall_flag = 0;

/* ************************************************************************************************************************** */

        /* ここの条件分岐で制御系を切り替える */
        /* 両側に壁がある場合 */
        if(u1_t_r_wall_flag == (U1)1 && u1_t_l_wall_flag == (U1)1){
            s4_t_sen_diff = s4_t_r_sen - s4_t_l_sen;
        }
        /* 右側だけ壁がある場合 */
        else if(u1_t_r_wall_flag == (U1)1 && u1_t_l_wall_flag == (U1)0){
            s4_t_sen_diff = (S4)2 * (s4_t_r_sen - s4_t_r_sen_ref);    
        }/* 左側だけ壁がある場合 */
        else if(u1_t_r_wall_flag == (U1)0 && u1_t_l_wall_flag == (U1)1){
            s4_t_sen_diff = (S4)-2 * (s4_t_l_sen - s4_t_l_sen_ref);    
        }/* 両側に壁がない場合 */
        else if(u1_t_r_wall_flag == (U1)0 && u1_t_l_wall_flag == (U1)0){
            s4_t_sen_diff = (S4)0;
        }
        else{
            /* NOP */
        }

        /* P制御の制御量の計算(比例制御) */
        fl_t_control_motor =(FL)s4_t_sen_diff * (FL)PID_KP;

        u4_s_CurrentSpeedR += (U4)((FL)6297 - fl_t_control_motor);
        u4_s_CurrentSpeedL += (U4)((FL)6297 + fl_t_control_motor);
    }
}

/* ============================================================ */
/* 関数名 : vd_s_CtrlMtuPulse                                   */
/*          モーターMTU制御                                     */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : モーターMTUの周期を設定する                         */
/* 制約   : なし                                                */
/* ============================================================ */
static void vd_s_CtrlMtuPulse(void)
{
    /* 左右モーターMTUの周期とパルス幅を設定する */
    u2_s_CycleTimeR = (U2)((FL)STEP_LENGTH / (FL)u4_s_CurrentSpeedR * (FL)MTU_MTR_CLOCK);
    u2_s_CycleTimeL = (U2)((FL)STEP_LENGTH / (FL)u4_s_CurrentSpeedL * (FL)MTU_MTR_CLOCK);
}

/* ============================================================ */
/* 関数名 : u2_g_get_CycleTimeR                                 */
/*          右モータ周期とパルス幅(割り込み1ms)                 */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   :                                                     */
/* 制約   : なし                                                */
/* ============================================================ */
U2 u2_g_get_CycleTimeR(void)
{
    return(u2_s_CycleTimeR);
}

/* ============================================================ */
/* 関数名 : u2_g_get_CycleTimeL                                 */
/*          左モータ周期とパルス幅(割り込み1ms)                 */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   :                                                     */
/* 制約   : なし                                                */
/* ============================================================ */
U2 u2_g_get_CycleTimeL(void)
{
    return(u2_s_CycleTimeL);
}

/* ============================================================ */
/* 関数名 : s1_g_get_MtrModeR                                   */
/*          右モーター モード                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   :                                                     */
/* 制約   : なし                                                */
/* ============================================================ */
S1 s1_g_get_MtrModeR(void)
{
    return(s1_s_MtrModeR);
}

/* ============================================================ */
/* 関数名 : s1_g_get_MtrModeL                                   */
/*          左モーター モード                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   :                                                     */
/* 制約   : なし                                                */
/* ============================================================ */
S1 s1_g_get_MtrModeL(void)
{
    return(s1_s_MtrModeL);
}

/* ============================================================ */
/* 関数名 : u1_g_get_MtrPowerMode                               */
/*          モータ励磁                                          */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   :                                                     */
/* 制約   : なし                                                */
/* ============================================================ */
U1 u1_g_get_MtrPowerMode(void)
{
    return(u1_s_MtrPowerMode);
}

