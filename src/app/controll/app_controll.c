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
#include "app_recgwall_pac.h"
#include "pf_sche_if_pac.h"
#if defined(OP_AppCtrl_Accel_LogicTypePhysical)
  /* None */
#elif defined(OP_AppCtrl_Accel_LogicTypeTable)
  #include "app_ctrl_accel_local.h"
#elif defined(OP_AppCtrl_Accel_LogicTypePulseCnt)
  #include "app_ctrl_accel_local.h"
  #include "pf_mtr_if.h"
#else
  /* None */
#endif

/* 本体 */
#include "app_controll.h"
#include "app_controll_pac.h"


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */
/* デバッグ用仮置き */
#define DEBUG_CONT    0                        /* 0:無効 1:有効 */

#define DEBUG_SPPED   2                        /* 2msの周期設定 *1000して与える  */

/* [mm]タイヤ軽(直径) */
#define CFL_AppCtrl_TireDiameter              ((FL)48.0F)

/* [mm]トレッド幅 */
#define CFL_AppCtrl_TreadWidth                ((FL)64.0F)

/* 演算精度用ゲイン */
#define CU4_AppCtrl_Gain                      ((U4)8192)

/* [1/mm]目標走行距離から目標パルス数への変換係数 */
#define CU4_AppCtrl_DistToPulseCntCoef        ((U4)((FL)(CU4_AppCtrl_Gain * (U4)2 * (U4)400) / (CFL_AppCtrl_TireDiameter * CFL_Pi)))

/* [mm]目標走行距離から目標パルス数への変換係数 */
#define CU4_AppCtrl_AngleDegToPulseCntCoef    ((U4)((FL)CU4_AppCtrl_Gain * (CFL_AppCtrl_TreadWidth / (FL)2.0F) * (CFL_Pi / (FL)180.0F)))

/* [mm]半ブロック分の長さ */
#define CFL_AppCtrl_HalfBlockLen              ((FL)90.0F)
#define CU2_AppCtrl_HalfBlockLen              ((U2)CFL_AppCtrl_HalfBlockLen)

/* [us]直進時間 */
#if defined(OP_AppCtrl_Accel_LogicTypePhysical)
  #define CU4_AppCtrl_StraightDrvTim    ((U4)500)
#elif defined(OP_AppCtrl_Accel_LogicTypeTable)
  #define CU4_AppCtrl_StraightDrvTim    ((U4)550)
#elif defined(OP_AppCtrl_Accel_LogicTypePulseCnt)
  #define CU4_AppCtrl_StraightDrvTim    ((U4)550)
#else
  #define CU4_AppCtrl_StraightDrvTim    ((U4)500)
#endif

/* [us]旋回時間 */
#if defined(OP_AppCtrl_Accel_LogicTypePhysical)
  #define CU4_AppCtrl_RotationDrvTim    ((U4)540)
#elif defined(OP_AppCtrl_Accel_LogicTypeTable)
  #define CU4_AppCtrl_RotationDrvTim    ((U4)588)
#elif defined(OP_AppCtrl_Accel_LogicTypePulseCnt)
  #define CU4_AppCtrl_RotationDrvTim    ((U4)588)
#else
  #define CU4_AppCtrl_RotationDrvTim    ((U4)540)
#endif

#if (0)
  #define OP_AppCtrl_EnbStopWait
/* [us]停車時間 */
  #define CU4_AppCtrl_StopTim    ((U4)3000)
#endif


/* ============================================================ */
/* 型定義                                                       */
/* ============================================================ */


/* ============================================================ */
/* 関数プロトタイプ宣言(static)                                 */
/* ============================================================ */
/* 共通 */
static U2 FnU2_AppCtrl_calDistByAngleDeg(U2 tu2AngleDeg);
static U2 FnU2_AppCtrl_calPulseCntByDist(U2 tu2Dist);

/* 定期処理 */
static VD vd_s_CtrlMtrForward(U1 u1_a_block, U4 u4_a_speed);
static VD vd_s_CtrlMtrTurn(S2 s2_a_angle);
static VD vd_s_CtrlMtrStop(VD);
static VD vd_s_CtrlMtrWait(VD);

/* 割り込み処理 */
static VD vd_s_IntDrvAcclControll(VD);
static VD vd_s_int_AttitudeControl(VD);
static VD vd_s_CtrlMtuPulse(VD);


/* ============================================================ */
/* 変数定義(extern)                                             */
/* ============================================================ */


/* ============================================================ */
/* 変数定義(static)                                             */
/* ============================================================ */
/* 走行設定 */
#if (DEBUG_CONT)
static U4 u4_s_StepCountR;                        /* 右モータ1stepごとにカウントアップされる変数(割り込み処理) */
static U4 u4_s_StepCountL;                        /* 左モータ1stepごとにカウントアップされる変数(割り込み処理) */
#endif
static U4 u4_s_CurrentSpeedR;                     /* 右モーター 現在速度 */
static U4 u4_s_CurrentSpeedL;                     /* 左モーター 現在速度 */
static U4 u4_s_MaxSpeedR;                         /* 右モーター 最高速度 */
static U4 u4_s_MaxSpeedL;                         /* 左モーター 最高速度 */
static U4 u4_s_AccelValue;                        /* 加速値 */
static U4 u4_s_AccelCount;                        /* 最高速度に達したカウント */
static U4 u4_s_StepCount;                         /* 走行ステップ数 */

static U1 u1_s_next_act;                          /*  */
#if defined(OP_AppCtrl_Accel_LogicTypePhysical)
static U4 u4AppCtrl_TimerCount;                   /* 1msごとにカウントアップされる変数(割り込み処理) */
#elif defined(OP_AppCtrl_Accel_LogicTypeTable)
static U4 u4AppCtrl_TimerCount;                   /* 1msごとにカウントアップされる変数(割り込み処理) */
static U1 u1AppCtrl_MtrModeR_prev;
static U1 u1AppCtrl_MtrModeL_prev;
#elif defined(OP_AppCtrl_Accel_LogicTypePulseCnt)
static U1 u1AppCtrl_MtrModeR_prev;
static U1 u1AppCtrl_MtrModeL_prev;
#else
/* None */
#endif

static U2 u2AppCtrl_TargetDist;                   /* [mm]目標走行距離 */

static U1 u1AppCtrl_ResetPulseCntReq;

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
VD vd_g_InitializeController(VD)
{
#if (DEBUG_CONT)
  u4_s_StepCountR    = (U4)0;                          /* 右モータ1stepごとにカウントアップされる変数 */
  u4_s_StepCountL    = (U4)0;                          /* 左モータ1stepごとにカウントアップされる変数 */
#endif
  u4_s_CurrentSpeedR = (U4)16000;                      /* 右モーター 現在速度 */
  u4_s_CurrentSpeedL = (U4)16000;                      /* 左モーター 現在速度 */
  u4_s_MaxSpeedR     = (U4)0;                          /* 右モーター 最高速度 */
  u4_s_MaxSpeedL     = (U4)0;                          /* 左モーター 最高速度 */
  u4_s_AccelValue    = (U4)0;                          /* 加速値 */
  u4_s_AccelCount    = (U4)0;                          /* 最高速度に達したカウント */
  u4_s_StepCount     = (U4)0;                          /* 走行ステップ数 */
  u1_s_MtrModeR      = (U1)MTR_STOP;                   /* 右モーター モード */
  u1_s_MtrModeL      = (U1)MTR_STOP;                   /* 左モーター モード */
  u1_s_MtrPowerMode  = (U1)MTR_OFF;                    /* モーター励磁 OFF設定 */
  en_s_dir           = (t_local_dir)4;                 /* プランナ指示 方向 */
  en_s_runstt        = (t_bool)1;                      /* 動作状況 0:走行中、1:走行完了 */
  u1_s_next_act      = (U1)VHECLE_STOP;                /* プランナ指示 方向→内部情報 */
#if defined(OP_AppCtrl_Accel_LogicTypePhysical)
  u4AppCtrl_TimerCount       = (U4)0;                  /* 1msごとにカウントアップされる変数 */
#elif defined(OP_AppCtrl_Accel_LogicTypeTable)
  u4AppCtrl_TimerCount       = (U4)0;                  /* 1msごとにカウントアップされる変数 */
  u1AppCtrl_MtrModeR_prev    = (U1)C_OFF;
  u1AppCtrl_MtrModeL_prev    = (U1)C_OFF;
#elif defined(OP_AppCtrl_Accel_LogicTypePulseCnt)
  u1AppCtrl_MtrModeR_prev    = (U1)C_OFF;
  u1AppCtrl_MtrModeL_prev    = (U1)C_OFF;
#else
/* None */
#endif
  u2AppCtrl_TargetDist       = (U2)0;
  u1AppCtrl_ResetPulseCntReq = (U1)C_OFF;
}


/* ============================================================ */
/* 関数名 : vd_ControllerMainTask                               */
/*          走行制御(定期処理)                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 走行制御を行う                                      */
/* 制約   : なし                                                */
/* ============================================================ */
VD vd_ControllerMainTask(VD)
{

  U4 u4_t_1mscnt_now;
  U1 u1_t_next_block;
#if (0)
  U1 u1_t_nextact;
  t_position pst_mypos;
#endif
  u4_t_1mscnt_now = FnU4_PfSche_If_getInt1msCnt();

  /* 左右のモータが走行ステップ数に達するまで待機 */
  if (   (u4_t_1mscnt_now < u4_s_StepCount)
      || (u4_t_1mscnt_now < u4_s_StepCount)) {

     vd_s_CtrlMtrWait();
  }
  else{
    /* 走行完了ならば次の指示を取得する */
    if (en_s_runstt == 1) {
#if (0)
      /* *********************************** */
      /* plannnerの指示を受け取る            */
      /* *********************************** */
      /* 前後左右どちらに移動するか受け取る予定 IFは変わるため、一旦消す */
      /* MAPに渡す東西南北はどうすれば？残さなきゃいけないかも */
      Fn_MAP_outputPosition(&pst_mypos);
      (VD)FnU1_Plan_indicatedir(pst_mypos.x, pst_mypos.y, pst_mypos.dir); /* 現在地情報(x,y) 現在の進行方向を与え、次の進行方向を得る north=0,east=1,south=2,west=3 */
      u1_t_nextact = FnU1_Plan_returndir();
      u1_t_next_block = u1_t_nextact >> 4 ;
      en_s_dir = (t_local_dir)(u1_t_nextact & 0x0F);
      u1_s_next_act = u1_t_nextact & 0x0F;
      en_s_runstt = (t_bool)0;
#endif
#if (1)
      u1_s_next_act = VHECLE_FORWORD;
      u1_t_next_block = HALF_BLOCK * 2;
      /* 左右旋回、反転の場合は3STEPの走行が必要であるため、制御指示を記憶する */
      en_s_dir = (t_local_dir)u1_s_next_act;
      en_s_runstt = (t_bool)0;
#endif
      /* memo */
      /* 直進の場合は、プランナ指示の区画だけ直進する 2STEP目で走行完了し、次の指示を受ける */
      /* 旋回を含む指示の場合、必ず0.5区画直進する 2STEP目で旋回し、3STEP目で0.5区画直進する 4STEP目で走行完了し、次の指示を受ける */
      /* 停止の場合は、その場で停止し走行完了する(ゴール) */
      /* プランナ指示の元、次回制御を設定 */
      if (u1_s_next_act != (U1)VHECLE_STOP) {
        vd_s_CtrlMtrForward(HALF_BLOCK,(U4)NORMAL_SPEED);
      }
      else {
        vd_s_CtrlMtrStop();
        en_s_runstt = (t_bool)1;
      }
    }
    /* 1STEP目以降の走行中ならば指示に合わせて動作する */
    else {
      if (u1_s_next_act == (U1)VHECLE_FORWORD) {
        vd_s_CtrlMtrForward(HALF_BLOCK,(U4)NORMAL_SPEED);
        u1_s_next_act = (U1)VHECLE_STOP;
      }
      else if (u1_s_next_act == (U1)VHECLE_TURNRIGHT) {
        vd_s_CtrlMtrTurn((S2)90);
        u1_s_next_act = (U1)VHECLE_FORWORD;
      }
      else if (u1_s_next_act == (U1)VHECLE_TURNLEFT) {
        vd_s_CtrlMtrTurn((S2)-90);
        u1_s_next_act = (U1)VHECLE_FORWORD;
      }
      else if (u1_s_next_act == (U1)VHECLE_TURNBACK) {
        vd_s_CtrlMtrTurn((S2)90);
        u1_s_next_act = (U1)VHECLE_TURNRIGHT;
      }
      else {
        /* 1指示に対する動作完了時、停止し次の指示を待つ */
        vd_s_CtrlMtrStop();
        en_s_runstt = (t_bool)1;
      }
    }
  }
}


/* ============================================================ */
/* 関数名 : FnU2_AppCtrl_calDistByAngleDeg                      */
/*          目標旋回角度から目標走行距離への変換                */
/* 引数   : tu2AngleDeg  [deg]目標旋回角度                      */
/* 戻り値 : [mm]目標走行距離                                    */
/* 概要   : 目標旋回角度から目標走行距離への変換                */
/* 制約   : なし                                                */
/* ============================================================ */
static U2 FnU2_AppCtrl_calDistByAngleDeg(U2 tu2AngleDeg)
{
  U4 tu4Dist;
  U2 tu2Dist;

  tu4Dist = (U4)tu2AngleDeg * CU4_AppCtrl_AngleDegToPulseCntCoef;
  tu4Dist += (CU4_AppCtrl_Gain / (U4)2);
  tu4Dist /= CU4_AppCtrl_Gain;
  tu2Dist = (U2)McXX_grdMax(tu4Dist, (U4)CU2_Max);

  return (tu2Dist);
}


/* ============================================================ */
/* 関数名 : FnU2_AppCtrl_calPulseCntByDist                      */
/*          目標走行距離から目標パルス数への変換                */
/* 引数   : tu2Dist  [mm]目標距離                               */
/* 戻り値 : [回]目標パルス数                                    */
/* 概要   : 目標走行距離から目標パルス数への変換                */
/* 制約   : なし                                                */
/* ============================================================ */
static U2 FnU2_AppCtrl_calPulseCntByDist(U2 tu2Dist)
{
  U4 tu4Step;
  U2 tu2Step;

  tu4Step = (U4)tu2Dist * CU4_AppCtrl_DistToPulseCntCoef;
  tu4Step += (CU4_AppCtrl_Gain / (U4)2);
  tu4Step /= CU4_AppCtrl_Gain;
  tu2Step = (U2)McXX_grdMax(tu4Step, (U4)CU2_Max);

  return (tu2Step);
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
static VD vd_s_CtrlMtrForward(U1 u1_a_block, U4 u4_a_speed)
{
  /* 目標走行距離演算 */
  u2AppCtrl_TargetDist = (U2)u1_a_block * CU2_AppCtrl_HalfBlockLen;

#if (DEBUG_CONT)
  //現在速度を最低速度に設定する。
  u4_s_CurrentSpeedR = (S4)MIN_SPEED;
  u4_s_CurrentSpeedL = (S4)MIN_SPEED;
#endif

  //現在速度をDEBUG_SPPED*1000に設定する。
  u4_s_CurrentSpeedR = (U4)(DEBUG_SPPED * 1000);
  u4_s_CurrentSpeedL = (U4)(DEBUG_SPPED * 1000);

  u4_s_StepCount = FnU4_PfSche_If_getInt1msCnt();
  u4_s_StepCount += CU4_AppCtrl_StraightDrvTim;


#if (0)
  //ここは見直しが必要 FTやめる 1msの走行距離をちゃんと計算する
  //走行ステップ数算出
  //1ms割り込み何回で走行が完了するか？
  //現在の1ms割り込み回数に走行する時間を加算する
  u4_s_StepCount = FnU4_PfSche_If_getInt1msCnt();
  u4_s_StepCount += (U4)(((FL)u1_a_block / (FL)ONE_BLOCK) * ((FL)BLOCK_LENGTH / (FL)STEP_LENGTH));
#endif
#if (DEBUG_CONT)
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
static VD vd_s_CtrlMtrTurn(S2 s2_a_angle)
{
  U2 tu2AngleDegAbs;             /* [deg]旋回角度絶対値 */

  /* todo */
  /* 反転も加えないといけない。アングルではなく旋回方向もらうようにする */

  /* 目標走行距離演算 */
  tu2AngleDegAbs = (U2)McXX_calAbs(s2_a_angle);
  u2AppCtrl_TargetDist = FnU2_AppCtrl_calDistByAngleDeg(tu2AngleDegAbs);

  /* 回転方向を決定 */
  if (s2_a_angle > (S2)0) {
    /* 右旋回 */
    u1_s_MtrModeR = (U1)MTR_BACK;       /* 右モーター後進 */
    u1_s_MtrModeL = (U1)MTR_RUN;        /* 左モーター前進 */
  }
  else {
    /* 左旋回 */
    u1_s_MtrModeR = (U1)MTR_RUN;        /* 右モーター前進 */
    u1_s_MtrModeL = (U1)MTR_BACK;       /* 左モーター後進 */
  }

#if (DEBUG_CONT)
  /* 現在速度を最低速度に設定する */
  u4_s_CurrentSpeedR = (U4)MIN_SPEED;
  u4_s_CurrentSpeedL = (U4)MIN_SPEED;
#endif


  //現在速度をDEBUG_SPPED*2000に設定する。前進より遅い設定
  u4_s_CurrentSpeedR = (U4)(DEBUG_SPPED * 2000);
  u4_s_CurrentSpeedL = (U4)(DEBUG_SPPED * 2000);

  u4_s_StepCount = FnU4_PfSche_If_getInt1msCnt();
  u4_s_StepCount += CU4_AppCtrl_RotationDrvTim;

#if (0)
  /* 走行ステップ数算出 */
  //現在の1ms割り込み回数に旋回する時間を加算する
  u4_s_StepCount = FnU4_PfSche_If_getInt1msCnt();
  u4_s_StepCount += (U4)((FL)TREAD_CIRCUIT * ((FL)tu2AngleDegAbs / (FL)360.0) / (FL)STEP_LENGTH);
#endif
#if (DEBUG_CONT)
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
static VD vd_s_CtrlMtrStop(VD)
{
  /* モーター処理（停止） */
  u1_s_MtrModeR = (U1)MTR_STOP;
  u1_s_MtrModeL = (U1)MTR_STOP;

  /* モータ励磁をOFF */
  u1_s_MtrPowerMode = (U1)MTR_OFF;

  /* 目標走行距離クリア */
  u2AppCtrl_TargetDist = (U2)0;

#if defined(OP_AppCtrl_EnbStopWait)
  u4_s_StepCount = FnU4_PfSche_If_getInt1msCnt();
  u4_s_StepCount += CU4_AppCtrl_StopTim;
#endif
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
static VD vd_s_CtrlMtrWait(VD)
{
	U1 u4_t_1mscnt_now;
	
  if (u4_s_AccelValue > (U4)0) {

		u4_t_1mscnt_now = FnU4_PfSche_If_getInt1msCnt();
  	
    /* 加速中 */
    if (u4_s_AccelCount != (U4)0) {
      if (   ((u4_s_StepCount - u4_t_1mscnt_now) < u4_s_AccelCount)
          || ((u4_s_StepCount - u4_t_1mscnt_now) < u4_s_AccelCount)) {
        /* 減速地点になったら減速を開始 */
        u4_s_AccelValue = - (U4)ACCEL_VALUE;
      }
    }
    else {
      if (   (u4_s_StepCount <= (u4_t_1mscnt_now * (U4)2))
          || (u4_s_StepCount <= (u4_t_1mscnt_now * (U4)2))) {

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
VD vd_s_IntDrvControll(VD)
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
static VD vd_s_IntDrvAcclControll(VD)
{
#if defined(OP_AppCtrl_Accel_LogicTypePhysical)
  /* None */
#elif defined(OP_AppCtrl_Accel_LogicTypeTable)
  /* None */
#elif defined(OP_AppCtrl_Accel_LogicTypePulseCnt)
  U2 tu2TargetPulseCntR;
  U2 tu2TargetPulseCntL;
  U2 tu2PulseCntR;
  U2 tu2PulseCntL;
  U1 tu1ResetReqR;
  U1 tu1ResetReqL;
#else
/* 実装なし */
#endif

#if defined(OP_AppCtrl_Accel_LogicTypePhysical)
  /* 1msごとにカウントアップ */
  u4AppCtrl_TimerCount++;

  /* 加減速 */
  u4_s_CurrentSpeedR += u4_s_AccelValue;
  u4_s_CurrentSpeedL += u4_s_AccelValue;

  /* 最低速度チェック */
  if (u4_s_CurrentSpeedR != (U4)0 && u4_s_CurrentSpeedR < (U4)MIN_SPEED){
    u4_s_CurrentSpeedR = (U4)MIN_SPEED;
  }
  if (u4_s_CurrentSpeedL != (U4)0 && u4_s_CurrentSpeedL < (U4)MIN_SPEED){
    u4_s_CurrentSpeedL = (U4)MIN_SPEED;
  }

  /* 最高速度チェック */
  if (u4_s_CurrentSpeedR > u4_s_MaxSpeedR) {
    u4_s_CurrentSpeedR = u4_s_MaxSpeedR;
    if (u4_s_AccelCount == (U4)0){
      u4_s_AccelCount = u4AppCtrl_TimerCount;
    }
  }
  if (u4_s_CurrentSpeedL > u4_s_MaxSpeedL) {
    u4_s_CurrentSpeedL = u4_s_MaxSpeedL;
    if (u4_s_AccelCount == (U4)0) {
      u4_s_AccelCount = u4AppCtrl_TimerCount;
    }
  }
#elif defined(OP_AppCtrl_Accel_LogicTypeTable)
  /* 1msごとにカウントアップ */
  if (u1_s_MtrPowerMode == (U1)MTR_ON) {
  	/* 操舵方向が変化したらカウンタリセット */
  	if (   (u1_s_MtrModeR != u1AppCtrl_MtrModeR_prev)
        || (u1_s_MtrModeL != u1AppCtrl_MtrModeL_prev)) {

      u4AppCtrl_TimerCount = (U4)0;
    }
    if (u4AppCtrl_TimerCount < (U4)CU2_Max) {
      u4AppCtrl_TimerCount++;
    }

    if (u1_s_MtrModeR == u1_s_MtrModeL) {
      /* 直進 */
      u4_s_CurrentSpeedR = FnU2_AppCtrl_Accel_ctrlPwmPeriod(u4AppCtrl_TimerCount * (U4)1000, CU4_AppCtrl_Accel_SizePwmPeriodMap, &CSTA_AppCtrl_Accel_PwmPeriodMapStraight[0]);
      u4_s_CurrentSpeedL = u4_s_CurrentSpeedR;
    }
    else {
      /* 旋回 */
      u4_s_CurrentSpeedR = FnU2_AppCtrl_Accel_ctrlPwmPeriod(u4AppCtrl_TimerCount * (U4)1000, CU4_AppCtrl_Accel_SizePwmPeriodMap, &CSTA_AppCtrl_Accel_PwmPeriodMapRotation[0]);
      u4_s_CurrentSpeedL = u4_s_CurrentSpeedR;
    }
  }
  else {
    u4AppCtrl_TimerCount = (U4)0;
    /* u4_s_CurrentSpeedR 保持 */
    /* u4_s_CurrentSpeedL 保持 */
  }

  /* 前回値更新 */
  u1AppCtrl_MtrModeR_prev = u1_s_MtrModeR;
  u1AppCtrl_MtrModeL_prev = u1_s_MtrModeL;
#elif defined(OP_AppCtrl_Accel_LogicTypePulseCnt)
  if (u1_s_MtrPowerMode == (U1)MTR_ON) {

    /* 目標パルス数演算 */
    tu2TargetPulseCntR = FnU2_AppCtrl_calPulseCntByDist(u2AppCtrl_TargetDist);
  #if (1)  /* 補正あり */
    tu2TargetPulseCntR = (U2)((U4)tu2TargetPulseCntR * (U4)CU1_AppCtrl_Accel_PwmTargetPulseCntCorrectCoef / (U4)100);
  #endif
    tu2TargetPulseCntL = tu2TargetPulseCntR;

    /* パルス数取得 */
    tu2PulseCntR = FnU2_PfMtr_If_getRightMtrPulseCount();
    tu2PulseCntL = FnU2_PfMtr_If_getLeftMtrPulseCount();

    /* 操舵方向が変化したらパルス数リセット */
    if (   (u1_s_MtrModeR != u1AppCtrl_MtrModeR_prev)
        || (u1_s_MtrModeL != u1AppCtrl_MtrModeL_prev)) {

      tu2PulseCntR = (U2)0;
      tu1ResetReqR = (U1)C_ON;
      tu2PulseCntL = (U2)0;
      tu1ResetReqL = (U1)C_ON;
    }
    else {
      tu1ResetReqR = (U1)C_OFF;
      tu1ResetReqL = (U1)C_OFF;
    }

    if (u1_s_MtrModeR == u1_s_MtrModeL) {
      /* 直進 */
  #if (1)  /* 算出した目標パルス数で制御 */
      u4_s_CurrentSpeedR = FnU2_AppCtrl_Accel_ctrlPwmPeriod(tu2PulseCntR, tu2TargetPulseCntR, CU2_AppCtrl_Accel_PwmTargetPeriodStraight, CU2_AppCtrl_Accel_PwmPeriodInitStraight);
      u4_s_CurrentSpeedL = FnU2_AppCtrl_Accel_ctrlPwmPeriod(tu2PulseCntL, tu2TargetPulseCntL, CU2_AppCtrl_Accel_PwmTargetPeriodStraight, CU2_AppCtrl_Accel_PwmPeriodInitStraight);
  #else    /* 固定の目標パルス数(半マス)で制御 */
      u4_s_CurrentSpeedR = FnU2_AppCtrl_Accel_ctrlPwmPeriod(tu2PulseCntR, CU2_AppCtrl_Accel_PwmTargetPulseCntStraight, CU2_AppCtrl_Accel_PwmTargetPeriodStraight, CU2_AppCtrl_Accel_PwmPeriodInitStraight);
      u4_s_CurrentSpeedL = FnU2_AppCtrl_Accel_ctrlPwmPeriod(tu2PulseCntL, CU2_AppCtrl_Accel_PwmTargetPulseCntStraight, CU2_AppCtrl_Accel_PwmTargetPeriodStraight, CU2_AppCtrl_Accel_PwmPeriodInitStraight);
  #endif
    }
    else {
      /* 旋回 */
  #if (1)  /* 算出した目標パルス数で制御 */
      u4_s_CurrentSpeedR = FnU2_AppCtrl_Accel_ctrlPwmPeriod(tu2PulseCntR, tu2TargetPulseCntR, CU2_AppCtrl_Accel_PwmTargetPeriodRotation, CU2_AppCtrl_Accel_PwmPeriodInitRotation);
      u4_s_CurrentSpeedL = FnU2_AppCtrl_Accel_ctrlPwmPeriod(tu2PulseCntL, tu2TargetPulseCntL, CU2_AppCtrl_Accel_PwmTargetPeriodRotation, CU2_AppCtrl_Accel_PwmPeriodInitRotation);
  #else    /* 固定の目標パルス数(半マス)で制御 */
      u4_s_CurrentSpeedR = FnU2_AppCtrl_Accel_ctrlPwmPeriod(tu2PulseCntR, CU2_AppCtrl_Accel_PwmTargetPulseCntRotation, CU2_AppCtrl_Accel_PwmTargetPeriodRotation, CU2_AppCtrl_Accel_PwmPeriodInitRotation);
      u4_s_CurrentSpeedL = FnU2_AppCtrl_Accel_ctrlPwmPeriod(tu2PulseCntL, CU2_AppCtrl_Accel_PwmTargetPulseCntRotation, CU2_AppCtrl_Accel_PwmTargetPeriodRotation, CU2_AppCtrl_Accel_PwmPeriodInitRotation);
  #endif
    }
  }
  else {
     tu1ResetReqR = (U1)C_ON;
     tu1ResetReqL = (U1)C_ON;
    /* u4_s_CurrentSpeedR 保持 */
    /* u4_s_CurrentSpeedL 保持 */
  }

  if (   (tu1ResetReqR == (U1)C_OFF)
      && (tu1ResetReqL == (U1)C_OFF)) {

    u1AppCtrl_ResetPulseCntReq = (U1)C_OFF;
  }
  else {
    u1AppCtrl_ResetPulseCntReq = (U1)C_ON;
  }

  /* 前回値更新 */
  u1AppCtrl_MtrModeR_prev = u1_s_MtrModeR;
  u1AppCtrl_MtrModeL_prev = u1_s_MtrModeL;
#else
  /* 加速制御無効 */
#endif
}


/* ============================================================ */
/* 関数名 : vd_s_int_AttitudeControl                            */
/*          姿勢制御割り込み制御                                */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 関数箱型コメントの形式を示す                        */
/* 制約   : なし                                                */
/* ============================================================ */
static VD vd_s_int_AttitudeControl(VD)
{
  S4 s4_t_sen_diff;                               /* 偏差用変数 */
  S4 s4_t_sen_pdiff;                              /* 前回偏差用変数 */
  S4 s4_t_r_sen;                                  /* 右センサ値 */
  S4 s4_t_l_sen;                                  /* 左センサ値 */
  S4 s4_t_r_sen_ref;                              /* 中央に置いた時の右センサリファレンス */
  S4 s4_t_l_sen_ref;                              /* 中央に置いた時の左センサリファレンス */
  U1 u1_t_r_wall_flag;                            /* 右に壁があるかどうかのフラグ */
  U1 u1_t_l_wall_flag;                            /* 左に壁があるかどうかのフラグ */

  FL fl_t_control_motor;

  fl_t_control_motor = (FL)0;
  /* 1ならば姿勢制御をする */
#if (OP_AppCmn_PidMode == 1)
  /*  センサから情報を取得   */
    s4_t_r_sen = (S4)st_RecgWall_info_attc.wall_r.u2_sens_val;
    s4_t_l_sen = (S4)st_RecgWall_info_attc.wall_l.u2_sens_val;
    s4_t_r_sen_ref = CTRL_WALL_THRESHOLD_R;
    s4_t_l_sen_ref = CTRL_WALL_THRESHOLD_L;
    u1_t_r_wall_flag = (U1)st_RecgWall_info_attc.wall_r.bl_wall_with;
    u1_t_l_wall_flag = (U1)st_RecgWall_info_attc.wall_l.bl_wall_with;

    /* ここの条件分岐で制御系を切り替える */
    /* 両側の壁を認識している場合 */
    if (u1_t_r_wall_flag == (U1)1 && u1_t_l_wall_flag == (U1)1) {
      s4_t_sen_diff = s4_t_r_sen - s4_t_l_sen;
    }
    /* 右側だけ壁を認識している場合 */
    else if (u1_t_r_wall_flag == (U1)1 && u1_t_l_wall_flag == (U1)0) {
      s4_t_sen_diff = (S4)2 * (s4_t_r_sen - s4_t_r_sen_ref);  
    }/* 左側だけ壁を認識している場合 */
    else if (u1_t_r_wall_flag == (U1)0 && u1_t_l_wall_flag == (U1)1) {
      s4_t_sen_diff = (S4)-2 * (s4_t_l_sen - s4_t_l_sen_ref);  
    }/* 両側の壁を認識していない場合 */
    else if (u1_t_r_wall_flag == (U1)0 && u1_t_l_wall_flag == (U1)0) {
      s4_t_sen_diff = (S4)-1 * (s4_t_r_sen - s4_t_l_sen);
    }
    else {
      /* NOP */
    }

    /* P制御の制御量の計算(比例制御) */
    fl_t_control_motor += (FL)s4_t_sen_diff * (FL)PID_KP;
    /* D制御の制御量の計算(微分制御) */
    fl_t_control_motor += (FL)(s4_t_sen_diff - s4_t_sen_pdiff) * (FL)PID_KD;

    /* 今回偏差を保持 */
    s4_t_sen_pdiff = s4_t_sen_diff;
#endif

    u4_s_CurrentSpeedR += (U4)fl_t_control_motor;
    u4_s_CurrentSpeedL -= (U4)fl_t_control_motor;
}


/* ============================================================ */
/* 関数名 : vd_s_CtrlMtuPulse                                   */
/*          モーターMTU制御                                     */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : モーターMTUの周期を設定する                         */
/* 制約   : なし                                                */
/* ============================================================ */
static VD vd_s_CtrlMtuPulse(VD)
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
U2 u2_g_get_CycleTimeR(VD)
{
  return (u2_s_CycleTimeR);
}


/* ============================================================ */
/* 関数名 : u2_g_get_CycleTimeL                                 */
/*          左モータ周期とパルス幅(割り込み1ms)                 */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   :                                                     */
/* 制約   : なし                                                */
/* ============================================================ */
U2 u2_g_get_CycleTimeL(VD)
{
  return (u2_s_CycleTimeL);
}


/* ============================================================ */
/* 関数名 : u1_g_get_MtrModeR                                   */
/*          右モーター モード                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   :                                                     */
/* 制約   : なし                                                */
/* ============================================================ */
U1 u1_g_get_MtrModeR(VD)
{
  return (u1_s_MtrModeR);
}


/* ============================================================ */
/* 関数名 : u1_g_get_MtrModeL                                   */
/*          左モーター モード                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   :                                                     */
/* 制約   : なし                                                */
/* ============================================================ */
U1 u1_g_get_MtrModeL(VD)
{
  return (u1_s_MtrModeL);
}


/* ============================================================ */
/* 関数名 : u1_g_get_MtrPowerMode                               */
/*          モータ励磁                                          */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   :                                                     */
/* 制約   : なし                                                */
/* ============================================================ */
U1 u1_g_get_MtrPowerMode(VD)
{
  return (u1_s_MtrPowerMode);
}


/* ============================================================ */
/* 関数名 : u2_g_get_MtrSpeedR                                  */
/*          右モータ周期                                        */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   :                                                     */
/* 制約   : なし                                                */
/* ============================================================ */
U2 u2_g_get_MtrSpeedR(VD)
{
  return ((U2)u4_s_CurrentSpeedR);
}


/* ============================================================ */
/* 関数名 : u2_g_get_MtrSpeedL                                  */
/*          左モータ周期                                        */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   :                                                     */
/* 制約   : なし                                                */
/* ============================================================ */
U2 u2_g_get_MtrSpeedL(VD)
{
  return ((U2)u4_s_CurrentSpeedL);
}


/* ============================================================ */
/* 関数名 : u1AppCtrl_getResetPulseCntReq                       */
/*          パルス数リセット要求                                */
/* 引数   : なし                                                */
/* 戻り値 : パルス数リセット要求                                */
/* 概要   :                                                     */
/* 制約   : なし                                                */
/* ============================================================ */
U1 u1AppCtrl_getResetPulseCntReq(VD)
{
  return (u1AppCtrl_ResetPulseCntReq);
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

  return (&en_s_runstt);
}

