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
#if defined(OP_PfCmn_EvaLedMediation)
  #include "pf_led_ctrl_eva_pac.h"
#endif


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */
#if defined(OP_PfCmn_ExistFuncInitialLedChk)
  /* [ms]イニシャル点灯時間 */
  #define CU2_PfLed_Ctrl_InitialOnTime    ((U2)((U2)1000 / (U2)CU1_PrjCmn_MainPeriod))
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

#if defined(OP_PfCmn_ExistFuncInitialLedChk)
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

#if defined(OP_PfCmn_ExistFuncInitialLedChk)
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
  U1 tu1LedReq0;
  U1 tu1LedReq1;
  U1 tu1LedReq2;
  U1 tu1LedReq3;
  U1 tu1BatVolLow;

#if defined(OP_PfCmn_ExistFuncInitialLedChk)
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
#if defined(OP_PfCmn_ExistFuncInitialLedChk)
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

#if defined(OP_PfCmn_EvaLedMediation)
    /* 評価用調停処理 */
    FnVD_PfLed_CtrlEva_mediate(&tu1LedReq0, &tu1LedReq1, &tu1LedReq2, &tu1LedReq3);
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

