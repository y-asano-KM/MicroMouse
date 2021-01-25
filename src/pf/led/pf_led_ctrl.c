/* ============================================================ */
/* ファイル名 : pf_led_ctrl.c                                   */
/* 機能       : LED制御                                         */
/* ============================================================ */
#define SECTION_PF

/* ============================================================ */
/* インクルード                                                 */
/* ============================================================ */
/* プロジェクト共通 */
#include "prj_cmn_section.h"
#include "prj_cmn_option.h"
#include "prj_cmn_type.h"
#include "prj_cmn_macro.h"

/* カテゴリ共通 */
#include "pf_cmn_option.h"
#include "pf_cmn_option_pac.h"

/* 個別 */
#include "pf_bat_monitor_pac.h"

/* 本体 */
#include "pf_led_ctrl_pac.h"

#define OP_PfLed_Ctrl_Test
#if defined(OP_PfLed_Ctrl_Test)
  #define OP_PfLed_Ctrl_TestRaySens
  #define OP_PfLed_Ctrl_TestSw  1
/*  #define OP_PfLed_Ctrl_TestMtr */

  /* ToDo:テスト用のため最終的には削除する */
  #include "hw_srv_schedule.h"
  #if defined(OP_PfLed_Ctrl_TestSw)
    #include "pf_switch_ctrl_pac.h"
  #endif
  #if defined(OP_PfLed_Ctrl_TestRaySens)
    #include "pf_raysens_if_pac.h"
  #endif
  #if defined(OP_PfLed_Ctrl_TestMtr)
    #include "pf_mtr_if_pac.h"
  #endif
#endif


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */
#if defined(OP_PfLed_Ctrl_ExistFuncInitialChk)
  /* [ms]イニシャル点灯時間 */
  #define CU2_PfLed_Ctrl_InitialOnTime    ((U2)((U2)1500 / (U2)CU1_PrjCmn_MainPeriod))
#endif

/* ============================================================ */
/* 型定義                                                       */
/* ============================================================ */


/* ============================================================ */
/* 関数プロトタイプ宣言(static)                                 */
/* ============================================================ */


/* ============================================================ */
/* 変数定義(extern)                                             */
/* ============================================================ */


/* ============================================================ */
/* 変数定義(static)                                             */
/* ============================================================ */
/* 点灯要求 */
static F1 f1PfLed_Ctrl_ReqLed;
#define fPfLed_Ctrl_ReqLed0  f1PfLed_Ctrl_ReqLed.Flag.fBit0
#define fPfLed_Ctrl_ReqLed1  f1PfLed_Ctrl_ReqLed.Flag.fBit1
#define fPfLed_Ctrl_ReqLed2  f1PfLed_Ctrl_ReqLed.Flag.fBit2
#define fPfLed_Ctrl_ReqLed3  f1PfLed_Ctrl_ReqLed.Flag.fBit3

#if defined(OP_PfLed_Ctrl_ExistFuncInitialChk)
static U2 u2PfLed_Ctrl_InitialTimer;       /* [ms]イニシャル点灯時間(LSB:CU1_PrjCmn_MainPeriod) */
#endif


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
/* 関数名 : FnVD_PfLed_Ctrl_init                                */
/*          LED制御処理初期化                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : LED制御処理の初期化を行う                           */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_PfLed_Ctrl_init(VD)
{
  /* 点灯要求初期化 */
  /* Memo:fPfLed_Ctrl_ReqLed0の初期化を兼ねる */
  /* Memo:fPfLed_Ctrl_ReqLed1の初期化を兼ねる */
  /* Memo:fPfLed_Ctrl_ReqLed2の初期化を兼ねる */
  /* Memo:fPfLed_Ctrl_ReqLed3の初期化を兼ねる */
  f1PfLed_Ctrl_ReqLed.u1Val = (U1)0x00;

#if defined(OP_PfLed_Ctrl_ExistFuncInitialChk)
  /* イニシャル点灯時間初期化 */
  u2PfLed_Ctrl_InitialTimer = (U2)0;
#endif
}


/* ============================================================ */
/* 関数名 : FnVD_PfLed_Ctrl_mediate                             */
/*          LED消灯/点灯要求調停処理                            */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 各種点灯条件/消灯条件の優先度より出力値を調停する   */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_PfLed_Ctrl_mediate(VD)
{
#if defined(OP_PfLed_Ctrl_Test)
  /* ToDo:テスト用のため最終的には削除する */
  U4 tu4MainCnt;
  U4 tu4Int1msCnt;
  #if defined(OP_PfLed_Ctrl_TestRaySens)
  U2 tu2RaySensR;
  U2 tu2RaySensFR;
  U2 tu2RaySensFL;
  U2 tu2RaySensL;
  #endif
  #if defined(OP_PfLed_Ctrl_TestMtr)
  U2 tu2PlusCntR;
  U2 tu2PlusCntL;
  #endif
  #if defined(OP_PfLed_Ctrl_TestSw)
    #if (OP_PfLed_Ctrl_TestSw == 0)
  U1 tu1TactSwtRS;
  U1 tu1TactSwtCS;
  U1 tu1TactSwtLS;
  U1 tu1TactSwtRL;
  U1 tu1TactSwtCL;
  U1 tu1TactSwtLL;
    #else
  U1 tu1TactSwtRM;
  U1 tu1TactSwtCM;
  U1 tu1TactSwtLM;
    #endif
  #endif
#endif
  U1 tu1LedReq0;
  U1 tu1LedReq1;
  U1 tu1LedReq2;
  U1 tu1LedReq3;
  U1 tu1BatVolLow;

#if defined(OP_PfLed_Ctrl_ExistFuncInitialChk)
  /* イニシャル吹鳴時間 */
  McXX_incU2Max(u2PfLed_Ctrl_InitialTimer);
#endif

  /* バッテリー電圧低下状態取得 */
  tu1BatVolLow = FnU1_PfBat_Moni_getStsVoltageLow();

  if (0) {
    /* 何もしない */
  }
  else if (tu1BatVolLow == (U1)C_ON) {
    /* バッテリー電圧低下中は消灯 */
    tu1LedReq0 = (U1)C_OFF;
    tu1LedReq1 = (U1)C_OFF;
    tu1LedReq2 = (U1)C_OFF;
    tu1LedReq3 = (U1)C_OFF;
  }
#if defined(OP_PfLed_Ctrl_ExistFuncInitialChk)
  else if (u2PfLed_Ctrl_InitialTimer < CU2_PfLed_Ctrl_InitialOnTime) {
    /* イニシャルLED点灯チェック */
    tu1LedReq0 = (U1)C_ON;
    tu1LedReq1 = (U1)C_ON;
    tu1LedReq2 = (U1)C_ON;
    tu1LedReq3 = (U1)C_ON;
  }
#endif
  else {
    /* 上記以外 */
    tu1LedReq0 = (U1)C_OFF;
    tu1LedReq1 = (U1)C_OFF;
    tu1LedReq2 = (U1)C_OFF;
    tu1LedReq3 = (U1)C_OFF;

#if defined(OP_PfLed_Ctrl_Test)
    /* ToDo:テスト用のため最終的には削除する */
    /* 確認用LED点灯処理 */
    /* メイン処理/1ms割り込み処理実行回数取得 */
    tu4MainCnt   = FnU4_HwSrv_Sche_getMainCnt();
    tu4Int1msCnt = FnU4_HwSrv_Sche_getInt1msCnt();

    /* 基本パターン */
    /* LED0,3:640ms周期(疑似2Hz), LED1,2:256ms周期(疑似4Hz) */
    tu1LedReq0 = (((U4)(tu4MainCnt & (U4)0x00000040) == (U4)0) ? (U1)C_ON : (U1)C_OFF);
    tu1LedReq1 = (((U4)(tu4Int1msCnt & (U4)0x00000080) == (U4)0) ? (U1)C_ON : (U1)C_OFF);
    tu1LedReq2 = tu1LedReq1;
    tu1LedReq3 = tu1LedReq0;

  #if defined(OP_PfLed_Ctrl_TestSw)
    #if (OP_PfLed_Ctrl_TestSw == 0)
    /* タクトスイッチ取得(短押し/長押し) */
    tu1TactSwtRS = FnU1_PfSwt_Ctrl_getTactSwtRightShortPush();
    tu1TactSwtCS = FnU1_PfSwt_Ctrl_getTactSwtCenterShortPush();
    tu1TactSwtLS = FnU1_PfSwt_Ctrl_getTactSwtLeftShortPush();
    tu1TactSwtRL = FnU1_PfSwt_Ctrl_getTactSwtRightLongPush();
    tu1TactSwtCL = FnU1_PfSwt_Ctrl_getTactSwtCenterLongPush();
    tu1TactSwtLL = FnU1_PfSwt_Ctrl_getTactSwtLeftLongPush();

    /* 短押しでOFF */
    tu1LedReq0 = ((tu1TactSwtLS == (U1)C_OFF) ? tu1LedReq0 : (U1)C_OFF);
    tu1LedReq1 = ((tu1TactSwtCS == (U1)C_OFF) ? tu1LedReq1 : (U1)C_OFF);
    tu1LedReq2 = ((tu1TactSwtCS == (U1)C_OFF) ? tu1LedReq2 : (U1)C_OFF);
    tu1LedReq3 = ((tu1TactSwtRS == (U1)C_OFF) ? tu1LedReq3 : (U1)C_OFF);

    /* 長押しでON */
    tu1LedReq0 = ((tu1TactSwtLL == (U1)C_OFF) ? tu1LedReq0 : (U1)C_ON);
    tu1LedReq1 = ((tu1TactSwtCL == (U1)C_OFF) ? tu1LedReq1 : (U1)C_ON);
    tu1LedReq2 = ((tu1TactSwtCL == (U1)C_OFF) ? tu1LedReq2 : (U1)C_ON);
    tu1LedReq3 = ((tu1TactSwtRL == (U1)C_OFF) ? tu1LedReq3 : (U1)C_ON);
    #else
    tu1TactSwtRM = FnU1_PfSwt_Ctrl_getTactSwtRightMomentary();
    tu1TactSwtCM = FnU1_PfSwt_Ctrl_getTactSwtCenterMomentary();
    tu1TactSwtLM = FnU1_PfSwt_Ctrl_getTactSwtLeftMomentary();
 
    /* SW ONで消灯 */
    tu1LedReq0 = ((tu1TactSwtLM == (U1)C_OFF) ? tu1LedReq0 : (U1)C_OFF);
    tu1LedReq1 = ((tu1TactSwtCM == (U1)C_OFF) ? tu1LedReq1 : (U1)C_OFF);
    tu1LedReq2 = ((tu1TactSwtCM == (U1)C_OFF) ? tu1LedReq2 : (U1)C_OFF);
    tu1LedReq3 = ((tu1TactSwtRM == (U1)C_OFF) ? tu1LedReq3 : (U1)C_OFF);
    #endif
  #endif
    
  #if defined(OP_PfLed_Ctrl_TestRaySens)
    /* センサ電圧値取得 */
    tu2RaySensR  = FnU2_PfRaySens_If_getValRight();
    tu2RaySensFR = FnU2_PfRaySens_If_getValFrontRight();
    tu2RaySensFL = FnU2_PfRaySens_If_getValFrontLeft();
    tu2RaySensL  = FnU2_PfRaySens_If_getValLeft();

    /* 壁検出で消灯 */
    tu1LedReq0 = ((tu2RaySensL  > (U2)30) ? (U1)C_OFF : tu1LedReq0);
    tu1LedReq1 = ((tu2RaySensFL > (U2)30) ? (U1)C_OFF : tu1LedReq1);
    tu1LedReq2 = ((tu2RaySensFR > (U2)30) ? (U1)C_OFF : tu1LedReq2);
    tu1LedReq3 = ((tu2RaySensR  > (U2)30) ? (U1)C_OFF : tu1LedReq3);
  #endif

  #if defined(OP_PfLed_Ctrl_TestMtr)
    /* モータパルス数取得 */
    tu2PlusCntR = FnU2_PfMtr_If_getPulseCountRight();
    tu2PlusCntL = FnU2_PfMtr_If_getPulseCountLeft();

    /* モータパルス数取得用割り込み発生で消灯 */
    tu1LedReq0 = ((tu2PlusCntL > (U2)0) ? (U1)C_OFF : tu1LedReq0);
    tu1LedReq3 = ((tu2PlusCntR > (U2)0) ? (U1)C_OFF : tu1LedReq3);
  #endif
#endif
  }

  fPfLed_Ctrl_ReqLed0 = tu1LedReq0;
  fPfLed_Ctrl_ReqLed1 = tu1LedReq1;
  fPfLed_Ctrl_ReqLed2 = tu1LedReq2;
  fPfLed_Ctrl_ReqLed3 = tu1LedReq3;
}


/* ============================================================ */
/* 関数名 : FnU1_PfLed_Ctrl_getReqLed0                          */
/*          LED0消灯/点灯要求出力値取得                         */
/* 引数   : なし                                                */
/* 戻り値 : LED0消灯/点灯要求出力値                             */
/* 概要   : LED0消灯/点灯要求出力値を提供する                   */
/* 制約   : なし                                                */
/* ============================================================ */
U1 FnU1_PfLed_Ctrl_getReqLed0(VD)
{
  return (fPfLed_Ctrl_ReqLed0);
}


/* ============================================================ */
/* 関数名 : FnU1_PfLed_Ctrl_getReqLed1                          */
/*          LED1消灯/点灯要求出力値取得                         */
/* 引数   : なし                                                */
/* 戻り値 : LED1消灯/点灯要求出力値                             */
/* 概要   : LED1消灯/点灯要求出力値を提供する                   */
/* 制約   : なし                                                */
/* ============================================================ */
U1 FnU1_PfLed_Ctrl_getReqLed1(VD)
{
  return (fPfLed_Ctrl_ReqLed1);
}


/* ============================================================ */
/* 関数名 : FnU1_PfLed_Ctrl_getReqLed2                          */
/*          LED2消灯/点灯要求出力値取得                         */
/* 引数   : なし                                                */
/* 戻り値 : LED2消灯/点灯要求出力値                             */
/* 概要   : LED2消灯/点灯要求出力値を提供する                   */
/* 制約   : なし                                                */
/* ============================================================ */
U1 FnU1_PfLed_Ctrl_getReqLed2(VD)
{
  return (fPfLed_Ctrl_ReqLed2);
}


/* ============================================================ */
/* 関数名 : FnU1_PfLed_Ctrl_getReqLed3                          */
/*          LED3消灯/点灯要求出力値取得                         */
/* 引数   : なし                                                */
/* 戻り値 : LED3消灯/点灯要求出力値                             */
/* 概要   : LED3消灯/点灯要求出力値を提供する                   */
/* 制約   : なし                                                */
/* ============================================================ */
U1 FnU1_PfLed_Ctrl_getReqLed3(VD)
{
  return (fPfLed_Ctrl_ReqLed3);
}

