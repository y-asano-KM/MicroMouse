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
#if defined(OP_AppCmn_LogicTypePhysical)
  /* None */
#elif defined(OP_AppCmn_LogicTypeTable)
  #include "app_ctrl_accel_local.h"
#elif defined(OP_AppCmn_LogicTypePulseCnt)
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
#if (0)
  #define OP_AppCtrl_DbgCont
#endif
/* 2msの周期設定 *1000して与える  */
#define CU4_AppCtrl_DbgSpd                    ((U4)2)

#if (0)
  #define OP_AppCtrl_EnbStopWait
  #if defined(OP_AppCtrl_EnbStopWait)
/* [us]停車時間 */
    #define CU4_AppCtrl_StopTim               ((U4)3000)
  #endif
#endif

/* [mm/s]最低速度 */
#define CU4_AppCtrl_MinSpd                    ((U4)100)

/* [mm/s]通常速度 */
#define CU4_AppCtrl_NrmlSpd                   ((U4)500)

/* [mm/s]最低速度 */
#define CU4_AppCtrl_TurnSpd                   ((U4)200)

/* 加速値 */
#define CU4_AppCtrl_AccelVal                  ((U4)2)

/* 1区画 */
#define CU1_AppCtrl_OneBlock                  ((U1)2)

/* 半区画 */
#define CU1_AppCtrl_HalfBlock                 ((U1)1)

/* タイマー発振数 */
#define CU4_AppCtrl_TimerClk                  ((U4)6000000)

/* PID制御:比例項パラメータ */
#define CFL_AppCtrl_CoefP                     ((FL)0.3F)

/* PID制御:積分項パラメータ */
#define CFL_AppCtrl_CoefI                     ((FL)0.3F)

/* PID制御:微分項パラメータ */
#define CFL_AppCtrl_CoefD                     ((FL)0.003F)

/* 中央に置いた時の右センサリファレンス */
#define CS4_AppCtrl_SensRefR                  ((S4)60)

/* 中央に置いた時の左センサリファレンス */
#define CS4_AppCtrl_SensRefL                  ((S4)60)

/* [mm]タイヤ軽(直径) */
#define CFL_AppCtrl_TireDiameter              ((FL)48.0F)

/* [mm]トレッド幅 */
#define CFL_AppCtrl_TreadWidth                ((FL)64.0F)

/* 演算精度用ゲイン */
#define CU4_AppCtrl_Gain                      ((U4)8192)

/* [1/mm]目標走行距離から目標パルス数への変換係数 */
#define CU4_AppCtrl_DistToPulseCntCoef        ((U4)((FL)(CU4_AppCtrl_Gain * (U4)2 * (U4)400) / (CFL_AppCtrl_TireDiameter * CFL_Pi)))

/* [mm]目標走行距離から目標パルス数への変換係数 */
#define CU4_AppCtrl_AngleDegToPulseCntCoef    ((U4)((FL)CU4_AppCtrl_Gain * (CFL_AppCtrl_TreadWidth / (FL)2.0F) * (CFL_Pi / CFL_SemiCircleDeg)))

/* [mm]半ブロック分の長さ */
#define CFL_AppCtrl_HalfBlockLen              ((FL)90.0F)
#define CU2_AppCtrl_HalfBlockLen              ((U2)CFL_AppCtrl_HalfBlockLen)

/* [mm]1ブロック分の長さ */
#define CFL_AppCtrl_BlockLen                  ((FL)(CFL_AppCtrl_HalfBlockLen * (FL)2.0F))

/* [mm]タイヤの円周 */
#define CDB_AppCtrl_TireCircuit               ((DB)(CDB_Pi * (DB)CFL_AppCtrl_TireDiameter))

/* [mm]旋回時にタイヤが動く距離 */
#define CFL_AppCtrl_TreadCircuit              ((FL)((DB)CFL_AppCtrl_TireDiameter * CDB_Pi))

/* [deg]ステッピングモータ(1-2相励磁)のステップ角 */
#define CDB_AppCtrl_StepDeg                   ((DB)((DB)1.8 / (DB)2.0))

/* [mm]1ステップで進む距離 */
#define CFL_AppCtrl_StepLen                   ((FL)(CDB_AppCtrl_TireCircuit * CDB_AppCtrl_StepDeg / CDB_CircleDeg))

/* [us]直進時間 */
#if defined(OP_AppCmn_LogicTypePhysical)
  #define CU4_AppCtrl_StraightDrvTim         ((U4)500)
#elif defined(OP_AppCmn_LogicTypeTable)
  #define CU4_AppCtrl_StraightDrvTim         ((U4)550)
#elif defined(OP_AppCmn_LogicTypePulseCnt)
  #define CU4_AppCtrl_StraightDrvTim         ((U4)550)
#else
  #define CU4_AppCtrl_StraightDrvTim         ((U4)500)
#endif

/* [us]旋回時間 */
#if defined(OP_AppCmn_LogicTypePhysical)
  #define CU4_AppCtrl_RotationDrvTim         ((U4)540)
#elif defined(OP_AppCmn_LogicTypeTable)
  #define CU4_AppCtrl_RotationDrvTim         ((U4)588)
#elif defined(OP_AppCmn_LogicTypePulseCnt)
  #define CU4_AppCtrl_RotationDrvTim         ((U4)588)
#else
  #define CU4_AppCtrl_RotationDrvTim         ((U4)540)
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
static VD FnVD_AppCtrl_goStraight(U1 tu1Block, U4 tu4Speed);
static VD FnVD_AppCtrl_turn(S2 ts2Deg);
static VD FnVD_AppCtrl_stop(VD);
static VD FnVD_AppCtrl_wait(VD);

/* 割り込み処理 */
static VD FnVD_AppCtrl_ctrlAccel(VD);
static VD FnVD_AppCtrl_ctrlAttitude(VD);
static VD FnVD_AppCtrl_ctrlTimerPulse(VD);


/* ============================================================ */
/* 変数定義(extern)                                             */
/* ============================================================ */


/* ============================================================ */
/* 変数定義(static)                                             */
/* ============================================================ */
/* 走行設定 */
#if defined(OP_AppCtrl_DbgCont)
static U4 u4AppCtrl_StepCntR;                  /* 右モータ1stepごとにカウントアップされる変数(割り込み処理) */
static U4 u4AppCtrl_StepCntL;                  /* 左モータ1stepごとにカウントアップされる変数(割り込み処理) */
#endif
static U4 u4AppCtrl_CurSpdR;                   /* 右モーター 現在速度 */
static U4 u4AppCtrl_CurSpdL;                   /* 左モーター 現在速度 */
static U4 u4AppCtrl_MaxSpdR;                   /* 右モーター 最高速度 */
static U4 u4AppCtrl_MaxSpdL;                   /* 左モーター 最高速度 */
static U4 u4AppCtrl_AccelVal;                  /* 加速値 */
static U4 u4AppCtrl_AccelCnt;                  /* 最高速度に達したカウント */
static U4 u4AppCtrl_StepCnt;                   /* 走行ステップ数 */

static U1 u1AppCtrl_NextAct;                   /* 次回進行方向 */
#if defined(OP_AppCmn_LogicTypePhysical)
static U4 u4AppCtrl_TimerCount;                /* 1msごとにカウントアップされる変数(割り込み処理) */
#elif defined(OP_AppCmn_LogicTypeTable)
static U4 u4AppCtrl_TimerCount;                /* 1msごとにカウントアップされる変数(割り込み処理) */
static U1 u1AppCtrl_MtrModePrevR;              /* 右モーター回転方向前回値 */
static U1 u1AppCtrl_MtrModePrevL;              /* 右モーター回転方向前回値 */
#elif defined(OP_AppCmn_LogicTypePulseCnt)
static U1 u1AppCtrl_MtrModePrevR;              /* 右モーター回転方向前回値 */
static U1 u1AppCtrl_MtrModePrevL;              /* 右モーター回転方向前回値 */
#else
/* None */
#endif

static U2 u2AppCtrl_TargetDist;                /* [mm]目標走行距離 */

static U1 u1AppCtrl_ResetPulseCntReq;          /* パルス数クリア要求 */

/* HWへ渡すパラメータ */
static U2 u2AppCtrl_CycTimeR;                  /* 右モータ周期とパルス幅(割り込み処理) */
static U2 u2AppCtrl_CycTimeL;                  /* 左モータ周期とパルス幅(割り込み処理) */
static S1 s1AppCtrl_MtrModeR;                  /* 右モーター回転方向 */
static S1 s1AppCtrl_MtrModeL;                  /* 左モーター回転方向 */
static U1 u1AppCtrl_MtrPowMode;                /* モーター電源状態 */

/* MAPへ渡すパラメータ */
static EN_AppCtrl_Dir    enAppCtrl_Dir;       /* 移動内容を設定する */
static EN_AppCtrl_RunSts enAppCtrl_RunSts;    /* 走行状態を設定する */


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
/* 関数名 : FnVD_AppCtrl_init                                   */
/*          初期化処理                                          */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : モジュールで使用する変数の初期化を行う              */
/* 制約   : メイン処理実行前にコールすること                    */
/* ============================================================ */
VD FnVD_AppCtrl_init(VD)
{
#if defined(OP_AppCtrl_DbgCont)
  u4AppCtrl_StepCntR         = (U4)0;                      /* 右モータ1stepごとにカウントアップされる変数 */
  u4AppCtrl_StepCntL         = (U4)0;                      /* 左モータ1stepごとにカウントアップされる変数 */
#endif
  u4AppCtrl_CurSpdR          = (U4)16000;                  /* 右モーター 現在速度 */
  u4AppCtrl_CurSpdL          = (U4)16000;                  /* 左モーター 現在速度 */
  u4AppCtrl_MaxSpdR          = (U4)0;                      /* 右モーター 最高速度 */
  u4AppCtrl_MaxSpdL          = (U4)0;                      /* 左モーター 最高速度 */
  u4AppCtrl_AccelVal         = (U4)0;                      /* 加速値 */
  u4AppCtrl_AccelCnt         = (U4)0;                      /* 最高速度に達したカウント */
  u4AppCtrl_StepCnt          = (U4)0;                      /* 走行ステップ数 */
  s1AppCtrl_MtrModeR         = (U1)C_OFF;                  /* 右モーター回転方向 */
  s1AppCtrl_MtrModeL         = (U1)C_OFF;                  /* 左モーター回転方向 */
  u1AppCtrl_MtrPowMode       = (U1)C_OFF;                  /* モーター励磁 OFF設定 */
  enAppCtrl_Dir              = CEN_AppCtrl_DirUnknown;     /* プランナ指示 方向 */
  enAppCtrl_RunSts           = CEN_AppCtrl_RunStsReady;    /* 動作状況 0:走行中、1:走行完了 */
  u1AppCtrl_NextAct          = CU1_AppPln_ActStop;      /* プランナ指示 方向→内部情報 */
#if defined(OP_AppCmn_LogicTypePhysical)
  u4AppCtrl_TimerCount       = (U4)0;                      /* 1msごとにカウントアップされる変数 */
#elif defined(OP_AppCmn_LogicTypeTable)
  u4AppCtrl_TimerCount       = (U4)0;                      /* 1msごとにカウントアップされる変数 */
  u1AppCtrl_MtrModePrevR     = (U1)C_OFF;                  /* 右モーター回転方向前回値 */
  u1AppCtrl_MtrModePrevL     = (U1)C_OFF;                  /* 左モーター回転方向前回値 */
#elif defined(OP_AppCmn_LogicTypePulseCnt)
  u1AppCtrl_MtrModePrevR     = (U1)C_OFF;                  /* 右モーター回転方向前回値 */
  u1AppCtrl_MtrModePrevL     = (U1)C_OFF;                  /* 左モーター回転方向前回値 */
#else
/* None */
#endif
  u2AppCtrl_TargetDist       = (U2)0;                      /* 目標走行距離 */
  u1AppCtrl_ResetPulseCntReq = (U1)C_OFF;                  /* パルス数クリア要求 */
}


/* ============================================================ */
/* 関数名 : FnVD_AppCtrl_mngTsk                                 */
/*          走行制御(定期処理)                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 走行制御を行う                                      */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_AppCtrl_mngTsk(VD)
{
  U4 tu4CntCur;
  U1 tu1NextBlock;
#if (1)
  U1 tu1NextAct;
  ST_AppMap_CarStt tstMypos;
#endif
  tu4CntCur = FnU4_PfSche_If_getInt1msCnt();

  /* 左右のモータが走行ステップ数に達するまで待機 */
  if (   (tu4CntCur < u4AppCtrl_StepCnt)
      || (tu4CntCur < u4AppCtrl_StepCnt)) {

     FnVD_AppCtrl_wait();
  }
  else{
    /* 走行完了ならば次の指示を取得する */
    if (   (enAppCtrl_RunSts == CEN_AppCtrl_RunStsFinish)
        || (enAppCtrl_RunSts == CEN_AppCtrl_RunStsReady)) {

#if (1)
      /* *********************************** */
      /* plannnerの指示を受け取る            */
      /* *********************************** */
      /* 前後左右どちらに移動するか受け取る予定 IFは変わるため、一旦消す */
      /* MAPに渡す東西南北はどうすれば？残さなきゃいけないかも */
      FnVD_AppMap_getPosition(&tstMypos);
  #if (0)
      FnVD_AppMap_updateWall();
  #endif

      /* 現在地情報(x,y) 現在の進行方向を与え、次の進行方向を得る north=0,east=1,south=2,west=3 */
      (VD)FnU1_AppPln_reqDir(tstMypos.s2X, tstMypos.s2Y, tstMypos.enDir);

      tu1NextAct = FnU1_AppPln_getActReq();
      tu1NextBlock = tu1NextAct >> (U1)4 ;
      enAppCtrl_Dir = (EN_AppCtrl_Dir)(tu1NextAct & (U1)0x0F);
      u1AppCtrl_NextAct = (U1)(tu1NextAct & (U1)0x0F);

  #if (0)
      FnVD_AppMap_updatePosition();
      FnVD_AppMap_updateWall();
  #endif

      enAppCtrl_RunSts = CEN_AppCtrl_RunStsRunning;
#endif
#if (0)
      u1AppCtrl_NextAct = CU1_AppPln_ActGoStraight;
      tu1NextBlock = CU1_AppCtrl_HalfBlock * 2;
      /* 左右旋回、反転の場合は3STEPの走行が必要であるため、制御指示を記憶する */
      enAppCtrl_Dir = (EN_AppCtrl_Dir)u1AppCtrl_NextAct;
      enAppCtrl_RunSts = CEN_AppCtrl_RunStsRunning;
#endif
      /* memo */
      /* 直進の場合は、プランナ指示の区画だけ直進する 2STEP目で走行完了し、次の指示を受ける */
      /* 旋回を含む指示の場合、必ず0.5区画直進する 2STEP目で旋回し、3STEP目で0.5区画直進する 4STEP目で走行完了し、次の指示を受ける */
      /* 停止の場合は、その場で停止し走行完了する(ゴール) */
      /* プランナ指示の元、次回制御を設定 */
      if (u1AppCtrl_NextAct != CU1_AppPln_ActStop) {
        FnVD_AppCtrl_goStraight(CU1_AppCtrl_HalfBlock, CU4_AppCtrl_NrmlSpd);
      }
      else {
        FnVD_AppCtrl_stop();
        enAppCtrl_RunSts = CEN_AppCtrl_RunStsReady;
      }
    }
    /* 1STEP目以降の走行中ならば指示に合わせて動作する */
    else {
      if (u1AppCtrl_NextAct == CU1_AppPln_ActGoStraight) {
        FnVD_AppCtrl_goStraight(CU1_AppCtrl_HalfBlock, CU4_AppCtrl_NrmlSpd);
        u1AppCtrl_NextAct = CU1_AppPln_ActStop;
      }
      else if (u1AppCtrl_NextAct == CU1_AppPln_ActTurnRight) {
        FnVD_AppCtrl_turn((S2)90);
        u1AppCtrl_NextAct = CU1_AppPln_ActGoStraight;
      }
      else if (u1AppCtrl_NextAct == CU1_AppPln_ActTurnLeft) {
        FnVD_AppCtrl_turn((S2)-90);
        u1AppCtrl_NextAct = CU1_AppPln_ActGoStraight;
      }
      else if (u1AppCtrl_NextAct == CU1_AppPln_ActTurnBack) {
        FnVD_AppCtrl_turn((S2)90);
        u1AppCtrl_NextAct = CU1_AppPln_ActTurnRight;
      }
      else {
        /* 1指示に対する動作完了時、停止し次の指示を待つ */
        FnVD_AppCtrl_stop();
        enAppCtrl_RunSts = CEN_AppCtrl_RunStsFinish;
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
/* 関数名 : FnVD_AppCtrl_goStraight                             */
/*          モーター処理（前進）                                */
/* 引数   : int i_block  区画数(半区画=1)                       */
/*        : int i_speed  目標速度                               */
/* 戻り値 : なし                                                */
/* 概要   : 距離、目標速度を指定して左右のモーターを前進する    */
/* 制約   : なし                                                */
/* ============================================================ */
static VD FnVD_AppCtrl_goStraight(U1 tu1Block, U4 tu4Speed)
{
  /* 目標走行距離演算 */
  u2AppCtrl_TargetDist = (U2)tu1Block * CU2_AppCtrl_HalfBlockLen;

#if defined(OP_AppCtrl_DbgCont)
  /* 現在速度を最低速度に設定する */
  u4AppCtrl_CurSpdR = CU4_AppCtrl_MinSpd;
  u4AppCtrl_CurSpdL = CU4_AppCtrl_MinSpd;
#endif

  u4AppCtrl_CurSpdR = CU4_AppCtrl_DbgSpd * CU4_ConvUnitScale;
  u4AppCtrl_CurSpdL = CU4_AppCtrl_DbgSpd * CU4_ConvUnitScale;

  u4AppCtrl_StepCnt = FnU4_PfSche_If_getInt1msCnt();
  u4AppCtrl_StepCnt += CU4_AppCtrl_StraightDrvTim;


#if (0)
  /* ここは見直しが必要 FTやめる 1msの走行距離をちゃんと計算する */
  /* 走行ステップ数算出 */
  /* 1ms割り込み何回で走行が完了するか? */
  /* 現在の1ms割り込み回数に走行する時間を加算する */
  u4AppCtrl_StepCnt = FnU4_PfSche_If_getInt1msCnt();
  u4AppCtrl_StepCnt += (U4)(((FL)tu1Block / (FL)CU1_AppCtrl_OneBlock) * (CFL_AppCtrl_BlockLen / CFL_AppCtrl_StepLen));
#endif
#if defined(OP_AppCtrl_DbgCont)
  /* 最高速度 */
  u4AppCtrl_MaxSpdR = tu4Speed;
  u4AppCtrl_MaxSpdL = tu4Speed;

  /* 加速値 */
  u4AppCtrl_AccelVal = CU4_AppCtrl_AccelVal;
  u4AppCtrl_AccelCnt = (U4)0;
#endif

  /* モーター処理(前進) */
  s1AppCtrl_MtrModeR = (U1)C_OFF;
  s1AppCtrl_MtrModeL = (U1)C_OFF;

  /* モータ励磁をON */
  u1AppCtrl_MtrPowMode = (U1)C_ON;
}


/* ============================================================ */
/* 関数名 : FnVD_AppCtrl_turn                                   */
/*          モーター処理（旋回）                                */
/* 引数   : ts2Deg  [deg]旋回角度                               */
/* 戻り値 : なし                                                */
/* 概要   : 回転角度を指定して旋回する                          */
/* 制約   : なし                                                */
/* ============================================================ */
static VD FnVD_AppCtrl_turn(S2 ts2Deg)
{
  U2 tu2AngleDegAbs;             /* [deg]旋回角度絶対値 */

  /* todo */
  /* 反転も加えないといけない。アングルではなく旋回方向もらうようにする */

  /* 目標走行距離演算 */
  tu2AngleDegAbs = (U2)McXX_calAbs(ts2Deg);
  u2AppCtrl_TargetDist = FnU2_AppCtrl_calDistByAngleDeg(tu2AngleDegAbs);

  /* 回転方向を決定 */
  if (ts2Deg > (S2)0) {
    /* 右旋回 */
    s1AppCtrl_MtrModeR = (U1)C_ON;         /* 右モーター後進 */
    s1AppCtrl_MtrModeL = (U1)C_OFF;        /* 左モーター前進 */
  }
  else {
    /* 左旋回 */
    s1AppCtrl_MtrModeR = (U1)C_OFF;        /* 右モーター前進 */
    s1AppCtrl_MtrModeL = (U1)C_ON;         /* 左モーター後進 */
  }

#if defined(OP_AppCtrl_DbgCont)
  /* 現在速度を最低速度に設定する */
  u4AppCtrl_CurSpdR = CU4_AppCtrl_MinSpd;
  u4AppCtrl_CurSpdL = CU4_AppCtrl_MinSpd;
#endif

  u4AppCtrl_CurSpdR = CU4_AppCtrl_DbgSpd * CU4_ConvUnitScale * (U4)2;
  u4AppCtrl_CurSpdL = CU4_AppCtrl_DbgSpd * CU4_ConvUnitScale * (U4)2;

  u4AppCtrl_StepCnt = FnU4_PfSche_If_getInt1msCnt();
  u4AppCtrl_StepCnt += CU4_AppCtrl_RotationDrvTim;

#if (0)
  /* 走行ステップ数算出 */
  /* 現在の1ms割り込み回数に旋回する時間を加算する */
  u4AppCtrl_StepCnt = FnU4_PfSche_If_getInt1msCnt();
  u4AppCtrl_StepCnt += (U4)(CFL_AppCtrl_TreadCircuit * ((FL)tu2AngleDegAbs / CFL_CircleDeg) / CFL_AppCtrl_StepLen);
#endif
#if defined(OP_AppCtrl_DbgCont)
  /* 最高速度 */
  u4AppCtrl_MaxSpdR = CU4_AppCtrl_TurnSpd;
  u4AppCtrl_MaxSpdL = CU4_AppCtrl_TurnSpd;

  /* 加速値 */
  u4AppCtrl_AccelVal = CU4_AppCtrl_AccelVal;
  u4AppCtrl_AccelCnt = (U4)0;
#endif
  /* モータ励磁をON */
  u1AppCtrl_MtrPowMode = (U1)C_ON;

}


/* ============================================================ */
/* 関数名 : FnVD_AppCtrl_stop                                   */
/*          モーター処理（停止）                                */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : その場で停止する                                    */
/* 制約   : なし                                                */
/* ============================================================ */
static VD FnVD_AppCtrl_stop(VD)
{
  /* モーター処理（停止） */
  s1AppCtrl_MtrModeR = (U1)C_OFF;
  s1AppCtrl_MtrModeL = (U1)C_OFF;

  /* モータ励磁をOFF */
  u1AppCtrl_MtrPowMode = (U1)C_OFF;

  /* 目標走行距離クリア */
  u2AppCtrl_TargetDist = (U2)0;

#if defined(OP_AppCtrl_EnbStopWait)
  u4AppCtrl_StepCnt = FnU4_PfSche_If_getInt1msCnt();
  u4AppCtrl_StepCnt += CU4_AppCtrl_StopTim;
#endif
}


/* ============================================================ */
/* 関数名 : FnVD_AppCtrl_wait                                   */
/*          モーター処理                                        */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : モータが指定ステップ数まで回転するのを待つ          */
/*      減速地点になったら減速する                              */
/* 制約   : なし                                                */
/* ============================================================ */
static VD FnVD_AppCtrl_wait(VD)
{
	U1 tu4TimerCur;

  if (u4AppCtrl_AccelVal > (U4)0) {

		tu4TimerCur = FnU4_PfSche_If_getInt1msCnt();

    /* 加速中 */
    if (u4AppCtrl_AccelCnt != (U4)0) {

      if (   ((u4AppCtrl_StepCnt - tu4TimerCur) < u4AppCtrl_AccelCnt)      /* ToDo:要ラップアラウンド対策 */
          || ((u4AppCtrl_StepCnt - tu4TimerCur) < u4AppCtrl_AccelCnt)) {   /* ToDo:要ラップアラウンド対策 */

        /* 減速地点になったら減速を開始 */
        u4AppCtrl_AccelVal = - CU4_AppCtrl_AccelVal;   /* ToDo:要減算修正 */
      }
    }
    else {
      if (   (u4AppCtrl_StepCnt <= (tu4TimerCur * (U4)2))
          || (u4AppCtrl_StepCnt <= (tu4TimerCur * (U4)2))) {

        /* 中間地点になったら減速を開始 */
        u4AppCtrl_AccelVal = - CU4_AppCtrl_AccelVal;   /* ToDo:要減算修正 */
      }
    }
  }
}


/* ============================================================ */
/* 割り込み処理                                                 */
/* ============================================================ */
/* ============================================================ */
/* 関数名 : FnVD_AppCtrl_mngTskForInt                           */
/*          タイマー割込み(1ms)                                 */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 関数箱型コメントの形式を示す                        */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_AppCtrl_mngTskForInt(VD)
{
  /* 加減速制御 */
  FnVD_AppCtrl_ctrlAccel();

  /* 姿勢制御 */
#if defined(OP_AppCmn_PidMode)
  #if (0)
  FnVD_AppCtrl_ctrlAttitude();
  #endif
#endif

  /* モータ出力周波数演算 */
  FnVD_AppCtrl_ctrlTimerPulse();
}


/* ============================================================ */
/* 関数名 : FnVD_AppCtrl_ctrlAccel                              */
/*          加減速制御                                          */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 右車輪速度/左車輪速度/加速度インデックスを更新する  */
/* 制約   : なし                                                */
/* ============================================================ */
static VD FnVD_AppCtrl_ctrlAccel(VD)
{
#if defined(OP_AppCmn_LogicTypePhysical)
  /* None */
#elif defined(OP_AppCmn_LogicTypeTable)
  /* None */
#elif defined(OP_AppCmn_LogicTypePulseCnt)
  U2 tu2TargetPulseCntR;
  U2 tu2TargetPulseCntL;
  U2 tu2PulseCntR;
  U2 tu2PulseCntL;
  U1 tu1ResetReqR;
  U1 tu1ResetReqL;
#else
/* 実装なし */
#endif

#if defined(OP_AppCmn_LogicTypePhysical)
  /* 1msごとにカウントアップ */
  u4AppCtrl_TimerCount++;

  /* 加減速 */
  u4AppCtrl_CurSpdR += u4AppCtrl_AccelVal;
  u4AppCtrl_CurSpdL += u4AppCtrl_AccelVal;

  /* 最低速度チェック */
  if (   (u4AppCtrl_CurSpdR != (U4)0)
      && (u4AppCtrl_CurSpdR < CU4_AppCtrl_MinSpd)) {

    u4AppCtrl_CurSpdR = CU4_AppCtrl_MinSpd;
  }

  if (   (u4AppCtrl_CurSpdL != (U4)0)
      && (u4AppCtrl_CurSpdL < CU4_AppCtrl_MinSpd)) {

    u4AppCtrl_CurSpdL = CU4_AppCtrl_MinSpd;
  }

  /* 最高速度チェック */
  if (u4AppCtrl_CurSpdR > u4AppCtrl_MaxSpdR) {
    u4AppCtrl_CurSpdR = u4AppCtrl_MaxSpdR;
    if (u4AppCtrl_AccelCnt == (U4)0) {
      u4AppCtrl_AccelCnt = u4AppCtrl_TimerCount;
    }
  }

  if (u4AppCtrl_CurSpdL > u4AppCtrl_MaxSpdL) {
    u4AppCtrl_CurSpdL = u4AppCtrl_MaxSpdL;
    if (u4AppCtrl_AccelCnt == (U4)0) {
      u4AppCtrl_AccelCnt = u4AppCtrl_TimerCount;
    }
  }
#elif defined(OP_AppCmn_LogicTypeTable)
  /* 1msごとにカウントアップ */
  if (u1AppCtrl_MtrPowMode == (U1)C_ON) {
  	/* 操舵方向が変化したらカウンタリセット */
  	if (   (s1AppCtrl_MtrModeR != u1AppCtrl_MtrModePrevR)
        || (s1AppCtrl_MtrModeL != u1AppCtrl_MtrModePrevL)) {

      u4AppCtrl_TimerCount = (U4)0;
    }
    if (u4AppCtrl_TimerCount < (U4)CU2_Max) {
      u4AppCtrl_TimerCount++;
    }

    if (s1AppCtrl_MtrModeR == s1AppCtrl_MtrModeL) {
      /* 直進 */
      u4AppCtrl_CurSpdR = FnU2_AppCtrl_Accel_ctrlPwmPeriod(u4AppCtrl_TimerCount * (U4)1000, CU4_AppCtrl_Accel_SizePwmPeriodMap, &CSTA_AppCtrl_Accel_PwmPeriodMapStraight[0]);
      u4AppCtrl_CurSpdL = u4AppCtrl_CurSpdR;
    }
    else {
      /* 旋回 */
      u4AppCtrl_CurSpdR = FnU2_AppCtrl_Accel_ctrlPwmPeriod(u4AppCtrl_TimerCount * (U4)1000, CU4_AppCtrl_Accel_SizePwmPeriodMap, &CSTA_AppCtrl_Accel_PwmPeriodMapRotation[0]);
      u4AppCtrl_CurSpdL = u4AppCtrl_CurSpdR;
    }
  }
  else {
    u4AppCtrl_TimerCount = (U4)0;
    /* u4AppCtrl_CurSpdR 保持 */
    /* u4AppCtrl_CurSpdL 保持 */
  }

  /* 前回値更新 */
  u1AppCtrl_MtrModePrevR = s1AppCtrl_MtrModeR;
  u1AppCtrl_MtrModePrevL = s1AppCtrl_MtrModeL;
#elif defined(OP_AppCmn_LogicTypePulseCnt)
  if (u1AppCtrl_MtrPowMode == (U1)C_ON) {

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
    if (   (s1AppCtrl_MtrModeR != u1AppCtrl_MtrModePrevR)
        || (s1AppCtrl_MtrModeL != u1AppCtrl_MtrModePrevL)) {

      tu2PulseCntR = (U2)0;
      tu1ResetReqR = (U1)C_ON;
      tu2PulseCntL = (U2)0;
      tu1ResetReqL = (U1)C_ON;
    }
    else {
      tu1ResetReqR = (U1)C_OFF;
      tu1ResetReqL = (U1)C_OFF;
    }

    if (s1AppCtrl_MtrModeR == s1AppCtrl_MtrModeL) {
      /* 直進 */
  #if (1)  /* 算出した目標パルス数で制御 */
      u4AppCtrl_CurSpdR = FnU2_AppCtrl_Accel_ctrlPwmPeriod(tu2PulseCntR, tu2TargetPulseCntR, CU2_AppCtrl_Accel_PwmTargetPeriodStraight, CU2_AppCtrl_Accel_PwmPeriodInitStraight);
      u4AppCtrl_CurSpdL = FnU2_AppCtrl_Accel_ctrlPwmPeriod(tu2PulseCntL, tu2TargetPulseCntL, CU2_AppCtrl_Accel_PwmTargetPeriodStraight, CU2_AppCtrl_Accel_PwmPeriodInitStraight);
  #else    /* 固定の目標パルス数(半マス)で制御 */
      u4AppCtrl_CurSpdR = FnU2_AppCtrl_Accel_ctrlPwmPeriod(tu2PulseCntR, CU2_AppCtrl_Accel_PwmTargetPulseCntStraight, CU2_AppCtrl_Accel_PwmTargetPeriodStraight, CU2_AppCtrl_Accel_PwmPeriodInitStraight);
      u4AppCtrl_CurSpdL = FnU2_AppCtrl_Accel_ctrlPwmPeriod(tu2PulseCntL, CU2_AppCtrl_Accel_PwmTargetPulseCntStraight, CU2_AppCtrl_Accel_PwmTargetPeriodStraight, CU2_AppCtrl_Accel_PwmPeriodInitStraight);
  #endif
    }
    else {
      /* 旋回 */
  #if (1)  /* 算出した目標パルス数で制御 */
      u4AppCtrl_CurSpdR = FnU2_AppCtrl_Accel_ctrlPwmPeriod(tu2PulseCntR, tu2TargetPulseCntR, CU2_AppCtrl_Accel_PwmTargetPeriodRotation, CU2_AppCtrl_Accel_PwmPeriodInitRotation);
      u4AppCtrl_CurSpdL = FnU2_AppCtrl_Accel_ctrlPwmPeriod(tu2PulseCntL, tu2TargetPulseCntL, CU2_AppCtrl_Accel_PwmTargetPeriodRotation, CU2_AppCtrl_Accel_PwmPeriodInitRotation);
  #else    /* 固定の目標パルス数(半マス)で制御 */
      u4AppCtrl_CurSpdR = FnU2_AppCtrl_Accel_ctrlPwmPeriod(tu2PulseCntR, CU2_AppCtrl_Accel_PwmTargetPulseCntRotation, CU2_AppCtrl_Accel_PwmTargetPeriodRotation, CU2_AppCtrl_Accel_PwmPeriodInitRotation);
      u4AppCtrl_CurSpdL = FnU2_AppCtrl_Accel_ctrlPwmPeriod(tu2PulseCntL, CU2_AppCtrl_Accel_PwmTargetPulseCntRotation, CU2_AppCtrl_Accel_PwmTargetPeriodRotation, CU2_AppCtrl_Accel_PwmPeriodInitRotation);
  #endif
    }
  }
  else {
     tu1ResetReqR = (U1)C_ON;
     tu1ResetReqL = (U1)C_ON;
    /* u4AppCtrl_CurSpdR 保持 */
    /* u4AppCtrl_CurSpdL 保持 */
  }

  if (   (tu1ResetReqR == (U1)C_OFF)
      && (tu1ResetReqL == (U1)C_OFF)) {

    u1AppCtrl_ResetPulseCntReq = (U1)C_OFF;
  }
  else {
    u1AppCtrl_ResetPulseCntReq = (U1)C_ON;
  }

  /* 前回値更新 */
  u1AppCtrl_MtrModePrevR = s1AppCtrl_MtrModeR;
  u1AppCtrl_MtrModePrevL = s1AppCtrl_MtrModeL;
#else
  /* 加速制御無効 */
#endif
}


/* ============================================================ */
/* 関数名 : FnVD_AppCtrl_ctrlAttitude                           */
/*          姿勢制御割り込み制御                                */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 関数箱型コメントの形式を示す                        */
/* 制約   : なし                                                */
/* ============================================================ */
static VD FnVD_AppCtrl_ctrlAttitude(VD)
{
  S4 ts4SensDiff;        /* 偏差用変数 */
  S4 ts4SensDiffPrev;    /* 前回偏差用変数 */
  S4 ts4SensR;           /* 右センサ値 */
  S4 ts4SensL;           /* 左センサ値 */
  S4 ts4SensRefR;        /* 中央に置いた時の右センサリファレンス */
  S4 ts4SensRefL;        /* 中央に置いた時の左センサリファレンス */
  U1 tu1WallFlagR;       /* 右に壁があるかどうかのフラグ */
  U1 tu1WallFlagL;       /* 左に壁があるかどうかのフラグ */
  FL tflCtrlMtr;

  tflCtrlMtr = (FL)0.0F;
  /* 1ならば姿勢制御をする */
#if defined(OP_AppCmn_PidMode)
  /*  センサから情報を取得   */
    ts4SensR = (S4)stAppRcg_WallInfoForCtrl.stWallR.u2SensVal;
    ts4SensL = (S4)stAppRcg_WallInfoForCtrl.stWallL.u2SensVal;
    ts4SensRefR = CS4_AppCtrl_SensRefR;
    ts4SensRefL = CS4_AppCtrl_SensRefL;
    tu1WallFlagR = stAppRcg_WallInfoForCtrl.stWallR.u1WallExistance;
    tu1WallFlagL = stAppRcg_WallInfoForCtrl.stWallL.u1WallExistance;

    /* ここの条件分岐で制御系を切り替える */
    if (   (tu1WallFlagR == (U1)C_ON)
        && (tu1WallFlagL == (U1)C_ON)) {

      /* 両側の壁を認識している場合 */
      ts4SensDiff = ts4SensR - ts4SensL;
    }
    else if (   (tu1WallFlagR == (U1)C_ON)
             && (tu1WallFlagL == (U1)C_OFF)) {

      /* 右側だけ壁を認識している場合 */
      ts4SensDiff = (S4)2 * (ts4SensR - ts4SensRefR);  
    }
    else if (   (tu1WallFlagR == (U1)C_OFF)
             && (tu1WallFlagL == (U1)C_ON)) {

      /* 左側だけ壁を認識している場合 */
      ts4SensDiff = (S4)-2 * (ts4SensL - ts4SensRefL);  
    }
    else if (   (tu1WallFlagR == (U1)C_OFF)
             && (tu1WallFlagL == (U1)C_OFF)) {

      /* 両側の壁を認識していない場合 */
      ts4SensDiff = (S4)-1 * (ts4SensR - ts4SensL);
    }
    else {
      /* NOP */
    }

    /* P制御の制御量の計算(比例制御) */
    tflCtrlMtr += (FL)ts4SensDiff * CFL_AppCtrl_CoefP;

    /* D制御の制御量の計算(微分制御) */
    tflCtrlMtr += (FL)(ts4SensDiff - ts4SensDiffPrev) * CFL_AppCtrl_CoefD;

    /* 今回偏差を保持 */
    ts4SensDiffPrev = ts4SensDiff;
#endif

    u4AppCtrl_CurSpdR += (U4)tflCtrlMtr;    /* ToDo:要ガード */
    u4AppCtrl_CurSpdL -= (U4)tflCtrlMtr;    /* ToDo:要ガード */
}


/* ============================================================ */
/* 関数名 : FnVD_AppCtrl_ctrlTimerPulse                         */
/*          モータータイマー制御                                */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : モータータイマーの周期を設定する                    */
/* 制約   : なし                                                */
/* ============================================================ */
static VD FnVD_AppCtrl_ctrlTimerPulse(VD)
{
  /* 左右モーターMTUの周期とパルス幅を設定する */
  u2AppCtrl_CycTimeR = (U2)(CFL_AppCtrl_StepLen / (FL)u4AppCtrl_CurSpdR * (FL)CU4_AppCtrl_TimerClk);
  u2AppCtrl_CycTimeL = (U2)(CFL_AppCtrl_StepLen / (FL)u4AppCtrl_CurSpdL * (FL)CU4_AppCtrl_TimerClk);
}


/* ============================================================ */
/* 関数名 : FnU2_AppCtrl_getCycleTimeR                          */
/*          右モータ周期とパルス幅(割り込み1ms)                 */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   :                                                     */
/* 制約   : なし                                                */
/* ============================================================ */
U2 FnU2_AppCtrl_getCycleTimeR(VD)
{
  return (u2AppCtrl_CycTimeR);
}


/* ============================================================ */
/* 関数名 : FnU2_AppCtrl_getCycleTimeL                          */
/*          左モータ周期とパルス幅(割り込み1ms)                 */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   :                                                     */
/* 制約   : なし                                                */
/* ============================================================ */
U2 FnU2_AppCtrl_getCycleTimeL(VD)
{
  return (u2AppCtrl_CycTimeL);
}


/* ============================================================ */
/* 関数名 : FnU1_AppCtrl_getMtrModeR                            */
/*          右モーター モード                                   */
/* 引数   : なし                                                */
/* 戻り値 : 右モーター回転方向                                  */
/* 概要   : 右モーター回転方向を提供する                        */
/* 制約   : なし                                                */
/* ============================================================ */
U1 FnU1_AppCtrl_getMtrModeR(VD)
{
  return ((U1)s1AppCtrl_MtrModeR);
}


/* ============================================================ */
/* 関数名 : FnU1_AppCtrl_getMtrModeL                            */
/*          左モーター回転方向                                  */
/* 引数   : なし                                                */
/* 戻り値 : 左モーター回転方向                                  */
/* 概要   : 左モーター回転方向を提供する                        */
/* 制約   : なし                                                */
/* ============================================================ */
U1 FnU1_AppCtrl_getMtrModeL(VD)
{
  return ((U1)s1AppCtrl_MtrModeL);
}


/* ============================================================ */
/* 関数名 : FnU1_AppCtrl_getMtrPowerMode                        */
/*          モータ電源状態                                      */
/* 引数   : なし                                                */
/* 戻り値 : モータ電源状態                                      */
/* 概要   : モータ電源状態を提供する                            */
/* 制約   : なし                                                */
/* ============================================================ */
U1 FnU1_AppCtrl_getMtrPowerMode(VD)
{
  return (u1AppCtrl_MtrPowMode);
}


/* ============================================================ */
/* 関数名 : FnU2_AppCtrl_getMtrSpeedR                           */
/*          右モータ周期                                        */
/* 引数   : なし                                                */
/* 戻り値 : [us]右モータ周期                                    */
/* 概要   : 右モータ周期を提供する                              */
/* 制約   : なし                                                */
/* ============================================================ */
U2 FnU2_AppCtrl_getMtrSpeedR(VD)
{
  return ((U2)u4AppCtrl_CurSpdR);
}


/* ============================================================ */
/* 関数名 : FnU2_AppCtrl_getMtrSpeedL                           */
/*          左モータ周期                                        */
/* 引数   : なし                                                */
/* 戻り値 : [us]左モータ周期                                    */
/* 概要   : 左モータ周期を提供する                              */
/* 制約   : なし                                                */
/* ============================================================ */
U2 FnU2_AppCtrl_getMtrSpeedL(VD)
{
  return ((U2)u4AppCtrl_CurSpdL);
}


/* ============================================================ */
/* 関数名 : FnU1_AppCtrl_getResetPulseCntReq                    */
/*          パルス数リセット要求                                */
/* 引数   : なし                                                */
/* 戻り値 : パルス数リセット要求                                */
/* 概要   : パルス数リセット要求を提供する                      */
/* 制約   : なし                                                */
/* ============================================================ */
U1 FnU1_AppCtrl_getResetPulseCntReq(VD)
{
  return (u1AppCtrl_ResetPulseCntReq);
}


/* ============================================================ */
/* 関数名 : FnEN_AppCtrl_getRunStt                              */
/*          移動内容と移動状態出力                              */
/* 引数   : tpenDir 移動内容                                    */
/* 戻り値 : 走行状態                                            */
/* 概要   : 走行状態を提供する                                  */
/* 制約   : なし                                                */
/* ============================================================ */
EN_AppCtrl_RunSts * FnEN_AppCtrl_getRunStt(EN_AppCtrl_Dir* tpenDir)
{
  *tpenDir = enAppCtrl_Dir;

  return (&enAppCtrl_RunSts);
}

