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
#include "app_map_pac.h"
#include "app_plan_pac.h"
#include "pf_sche_if_pac.h"

/* 本体 */
#include "app_controll.h"
#include "app_controll_pac.h"

/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */
/* デバッグ用仮置き */
#define DEBUG_CONT    0                        /* 0:無効 1:有効 */

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
static U4 u4_s_TimerCount;                        /* 1msごとにカウントアップされる変数(割り込み処理) */
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

static U1 u1_s_next_act;                          /*  */

/* HWへ渡すパラメータ */
static U2 u2_s_CycleTimeR;                        /* 右モータ周期とパルス幅(割り込み処理) */
static U2 u2_s_CycleTimeL;                        /* 左モータ周期とパルス幅(割り込み処理) */
static S1 u1_s_MtrModeR;                          /* 右モーター モード */
static S1 u1_s_MtrModeL;                          /* 左モーター モード */
static U1 u1_s_MtrPowerMode;                      /* モーター励磁 ON/OFF設定 */

/* MAPへ渡すパラメータ */
static t_local_dir en_s_dir;                      /* 移動内容を設定する */
static t_bool en_s_runstt;                        /* 移動状態を設定する */

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
  u4_s_TimerCount    = (U4)0;                          /* 1msごとにカウントアップされる変数 */
  u4_s_StepCountR    = (U4)0;                          /* 右モータ1stepごとにカウントアップされる変数 */
  u4_s_StepCountL    = (U4)0;                          /* 左モータ1stepごとにカウントアップされる変数 */
  u4_s_CurrentSpeedR = (U4)0;                          /* 右モーター 現在速度 */
  u4_s_CurrentSpeedL = (U4)0;                          /* 左モーター 現在速度 */
  u4_s_MaxSpeedR     = (U4)0;                          /* 右モーター 最高速度 */
  u4_s_MaxSpeedL     = (U4)0;                          /* 左モーター 最高速度 */
  u4_s_AccelValue    = (U4)0;                          /* 加速値 */
  u4_s_AccelCount    = (U4)0;                          /* 最高速度に達したカウント */
  u4_s_StepCount     = (U4)0;                          /* 走行ステップ数 */
  u1_s_MtrModeR      = (U1)MTR_STOP;                   /* 右モーター モード */
  u1_s_MtrModeL      = (U1)MTR_STOP;                   /* 左モーター モード */
  u1_s_PidMode       = (U1)0;                          /* 姿勢制御(PID)機能 有効/無効フラグ */
  u1_s_MtrPowerMode  = (U1)MTR_OFF;                    /* モーター励磁 OFF設定 */
  en_s_dir           = (t_local_dir)4;                 /* プランナ指示 方向 */
  en_s_runstt        = (t_bool)1;                      /* 動作状況 0:走行中、1:走行完了 */
  u1_s_next_act      = (U1)VHECLE_STOP;                /* プランナ指示 方向→内部情報 */
}

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

  U1 u1_t_next_block;
  U4 u4_t_1mscnt_now;

//  t_position pst_mypos;

  u4_t_1mscnt_now = FnU4_PfSche_If_getInt1msCnt();

  /* 左右のモータが走行ステップ数に達するまで待機 */
  if(u4_t_1mscnt_now < u4_s_StepCount || u4_t_1mscnt_now < u4_s_StepCount){
     vd_s_CtrlMtrWait();
  }
  else{
    /* 走行完了ならば次の指示を取得する */
    if(en_s_runstt == 1){
#if 0
      /* *********************************** */
      /* plannnerの指示を受け取る            */
      /* *********************************** */
      /* 前後左右どちらに移動するか受け取る予定 IFは変わるため、一旦消す */
      /* MAPに渡す東西南北はどうすれば？残さなきゃいけないかも */
      Fn_MAP_outputPosition(&pst_mypos);
      u1_s_next_act = FnU1_Plan_indicatedir(pst_mypos.x, pst_mypos.y, pst_mypos.dir); /* 現在地情報(x,y) 現在の進行方向を与え、次の進行方向を得る north=0,east=1,south=2,west=3 */
      u1_t_next_block = HALF_BLOCK;
      en_s_dir = (t_local_dir)u1_s_next_act;
#endif
#if 1
      u1_s_next_act = VHECLE_FORWORD;
      u1_t_next_block = HALF_BLOCK;
      /* 左右旋回、反転の場合は3STEPの走行が必要であるため、制御指示を記憶する */
      en_s_dir = (t_local_dir)u1_s_next_act;
      en_s_runstt = (t_bool)0;
#endif
      /* memo */
      /* 直進の場合は、プランナ指示の区画だけ直進する 2STEP目で走行完了し、次の指示を受ける */
      /* 旋回を含む指示の場合、必ず0.5区画直進する 2STEP目で旋回し、3STEP目で0.5区画直進する 4STEP目で走行完了し、次の指示を受ける */
      /* 停止の場合は、その場で停止し走行完了する(ゴール) */
      /* プランナ指示の元、次回制御を設定 */
      if(u1_s_next_act == (U1)VHECLE_FORWORD){
        vd_s_CtrlMtrForward(u1_t_next_block,(U4)NORMAL_SPEED);
        u1_s_next_act = (U1)VHECLE_STOP;
      }
      else if(u1_s_next_act == (U1)VHECLE_TURNRIGHT){
        vd_s_CtrlMtrForward((U1)HALF_BLOCK,(U4)NORMAL_SPEED);
      }
      else if(u1_s_next_act == (U1)VHECLE_TURNLEFT){
        vd_s_CtrlMtrForward((U1)HALF_BLOCK,(U4)NORMAL_SPEED);
      }
      else if(u1_s_next_act == (U1)VHECLE_TURNBACK){
        vd_s_CtrlMtrForward((U1)HALF_BLOCK,(U4)NORMAL_SPEED);
      }
      else {
        vd_s_CtrlMtrStop();
        en_s_runstt = (t_bool)1;
      }
    }
    /* 1STEP目以降の走行中ならば指示に合わせて動作する */
    else {
      if(u1_s_next_act == (U1)VHECLE_FORWORD){
        vd_s_CtrlMtrForward(HALF_BLOCK,(U4)NORMAL_SPEED);
        u1_s_next_act = (U1)VHECLE_STOP;
      }
      else if(u1_s_next_act == (U1)VHECLE_TURNRIGHT){
        vd_s_CtrlMtrTurn((S2)90);
        u1_s_next_act = (U1)VHECLE_FORWORD;
      }
      else if(u1_s_next_act == (U1)VHECLE_TURNLEFT){
        vd_s_CtrlMtrTurn((S2)-90);
        u1_s_next_act = (U1)VHECLE_FORWORD;
      }
      else if(u1_s_next_act == (U1)VHECLE_TURNBACK){
        vd_s_CtrlMtrTurn((S2)180);
        u1_s_next_act = (U1)VHECLE_FORWORD;
      }
      else {
        en_s_runstt = (t_bool)1;
      }
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

#if DEBUG_CONT
  //現在速度を最低速度に設定する。
  u4_s_CurrentSpeedR = (S4)MIN_SPEED;
  u4_s_CurrentSpeedL = (S4)MIN_SPEED;
#endif
  //ここは見直しが必要 FTやめる 1msの走行距離をちゃんと計算する
  //走行ステップ数算出
  //1ms割り込み何回で走行が完了するか？
  //現在の1ms割り込み回数に走行する時間を加算する
  u4_s_StepCount = FnU4_PfSche_If_getInt1msCnt();
  u4_s_StepCount += (U4)(((FL)u1_a_block / (FL)ONE_BLOCK) * ((FL)BLOCK_LENGTH / (FL)STEP_LENGTH));

#if DEBUG_CONT
  //最高速度
  u4_s_MaxSpeedR = u4_a_speed;
  u4_s_MaxSpeedL = u4_a_speed;

  //加速値
  u4_s_AccelValue = ACCEL_VALUE;
  u4_s_AccelCount = 0;
#endif

  //モーター処理（前進）
  u1_s_MtrModeR = (U1)MTR_RUN;
  u1_s_MtrModeL = (U1)MTR_RUN;

  /* モータ励磁をON */
  u1_s_MtrPowerMode = (U1)MTR_ON;
}

/* ============================================================ */
/* 関数名 : vd_s_CtrlMtrTurn                                    */
/*          モーター処理（旋回）                                */
/* 引数   : S2 s2_a_angle … 旋回角度(°)                       */
/*          > 0 … 右旋回                                       */
/*          < 0 … 左旋回                                       */
/* 戻り値 : なし                                                */
/* 概要   : 回転角度を指定して旋回する                          */
/* 制約   : なし                                                */
/* ============================================================ */
static void vd_s_CtrlMtrTurn(S2 s2_a_angle)
{
  U2  u2_t_angle;                 /* 旋回角度 */

  /* 回転方向を決定 */
  if(s2_a_angle > 0){
    /* 右旋回 */
    u2_t_angle  = s2_a_angle;
    u1_s_MtrModeR = (U1)MTR_BACK;       /* 右モーター後進 */
    u1_s_MtrModeL = (U1)MTR_RUN;        /* 左モーター前進 */
  }
  else{
    /* 左旋回 */
    u2_t_angle    = -s2_a_angle;
    u1_s_MtrModeR = (U1)MTR_RUN;        /* 右モーター前進 */
    u1_s_MtrModeL = (U1)MTR_BACK;       /* 左モーター後進 */
  }

#if DEBUG_CONT
  /* 現在速度を最低速度に設定する */
  u4_s_CurrentSpeedR = (U4)MIN_SPEED;
  u4_s_CurrentSpeedL = (U4)MIN_SPEED;
#endif
  /* 走行ステップ数算出 */
  //現在の1ms割り込み回数に旋回する時間を加算する
  u4_s_StepCount = FnU4_PfSche_If_getInt1msCnt();
  u4_s_StepCount += (U4)((FL)TREAD_CIRCUIT * ((FL)u2_t_angle / (FL)360.0) / (FL)STEP_LENGTH);
#if DEBUG_CONT
  /* 最高速度 */
  u4_s_MaxSpeedR = TURN_SPEED;
  u4_s_MaxSpeedL = TURN_SPEED;

  /* 加速値 */
  u4_s_AccelValue = ACCEL_VALUE;
  u4_s_AccelCount = 0;
#endif
  /* モータ励磁をON */
  u1_s_MtrPowerMode = (U1)MTR_ON;

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
  u1_s_MtrModeR = (U1)MTR_STOP;
  u1_s_MtrModeL = (U1)MTR_STOP;

  /* モータ励磁をOFF */
  u1_s_MtrPowerMode = (U1)MTR_OFF;
}

/* ============================================================ */
/* 関数名 : vd_s_CtrlMtrWait                                    */
/*          モーター処理                                        */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : モータが指定ステップ数まで回転するのを待つ          */
/*      減速地点になったら減速する                              */
/* 制約   : なし                                                */
/* ============================================================ */
static void vd_s_CtrlMtrWait(void)
{
	U1 u4_t_1mscnt_now;
	
  if(u4_s_AccelValue > 0){

		u4_t_1mscnt_now = FnU4_PfSche_If_getInt1msCnt();
  	
    /* 加速中 */
    if(u4_s_AccelCount != 0){
      if(((u4_s_StepCount - u4_t_1mscnt_now) < u4_s_AccelCount) || ((u4_s_StepCount - u4_t_1mscnt_now) < u4_s_AccelCount)){
        /* 減速地点になったら減速を開始 */
        u4_s_AccelValue = - (U4)ACCEL_VALUE;
      }
    }
    else{
      if((u4_s_StepCount <= u4_t_1mscnt_now * (U4)2) || (u4_s_StepCount <= u4_t_1mscnt_now * (U4)2)){
        /* 中間地点になったら減速を開始 */
        u4_s_AccelValue = - (U4)ACCEL_VALUE;
      }
    }
  }
}

/* ============================================================ */
/* 割り込み処理                                                 */
/* ============================================================ */
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
  u4_s_TimerCount++;

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
      u4_s_AccelCount = u4_s_TimerCount;
    }
  }
  if(u4_s_CurrentSpeedL > u4_s_MaxSpeedL){
    u4_s_CurrentSpeedL = u4_s_MaxSpeedL;
    if(u4_s_AccelCount == (U4)0){
      u4_s_AccelCount = u4_s_TimerCount;
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
  S4 s4_t_sen_diff;                               /* 偏差用変数 */
  S4 s4_t_r_sen;                                  /* 右センサ値 */
  S4 s4_t_l_sen;                                  /* 左センサ値 */
  S4 s4_t_r_sen_ref;                              /* 中央に置いた時の右センサリファレンス */
  S4 s4_t_l_sen_ref;                              /* 中央に置いた時の左センサリファレンス */
  U1 u1_t_r_wall_flag;                            /* 右に壁があるかどうかのフラグ */
  U1 u1_t_l_wall_flag;                            /* 左に壁があるかどうかのフラグ */

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
/* 関数名 : u1_g_get_MtrModeR                                   */
/*          右モーター モード                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   :                                                     */
/* 制約   : なし                                                */
/* ============================================================ */
U1 u1_g_get_MtrModeR(void)
{
  return(u1_s_MtrModeR);
}

/* ============================================================ */
/* 関数名 : u1_g_get_MtrModeL                                   */
/*          左モーター モード                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   :                                                     */
/* 制約   : なし                                                */
/* ============================================================ */
U1 u1_g_get_MtrModeL(void)
{
  return(u1_s_MtrModeL);
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

/* ============================================================ */
/* 関数名 : Fn_CONTROL_outputStatus                             */
/*          移動内容と移動状態出力                              */
/* 引数   : en_a_dir 移動内容                                   */
/* 戻り値 : en_s_runstt                                         */
/* 概要   :                                                     */
/* 制約   : なし                                                */
/* ============================================================ */
t_bool* Fn_CONTROL_outputStatus(t_local_dir* en_a_dir)
{
  *en_a_dir = en_s_dir;

  return &en_s_runstt;
}

