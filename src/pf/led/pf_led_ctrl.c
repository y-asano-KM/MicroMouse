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

#define OP_PfSche_Main_TestLed
#if defined(OP_PfSche_Main_TestLed)
  /* ToDo:テスト用のため最終的には削除する */
  #include "hw_srv_schedule.h"
#endif


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */


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
static F1 f1PfLed_Ctrl_ReqLed;
#define fPfLed_Ctrl_ReqLed0  f1PfLed_Ctrl_ReqLed.Flag.fBit0
#define fPfLed_Ctrl_ReqLed1  f1PfLed_Ctrl_ReqLed.Flag.fBit1
#define fPfLed_Ctrl_ReqLed2  f1PfLed_Ctrl_ReqLed.Flag.fBit2
#define fPfLed_Ctrl_ReqLed3  f1PfLed_Ctrl_ReqLed.Flag.fBit3


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
  /* Memo:fPfLed_Ctrl_ReqLed0の初期化を兼ねる */
  /* Memo:fPfLed_Ctrl_ReqLed1の初期化を兼ねる */
  /* Memo:fPfLed_Ctrl_ReqLed2の初期化を兼ねる */
  /* Memo:fPfLed_Ctrl_ReqLed3の初期化を兼ねる */
  f1PfLed_Ctrl_ReqLed.u1Val = (U1)0x00;
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
#if defined(OP_PfSche_Main_TestLed)
  /* ToDo:テスト用のため最終的には削除する */
  U4 tu4MainCnt;
  U4 tu4Int1msCnt;
#endif
  U1 tu1LedReq0;
  U1 tu1LedReq1;
  U1 tu1LedReq2;
  U1 tu1LedReq3;
  U1 tu1BatVolLow;

  /* バッテリー電圧低下状態取得 */
  tu1BatVolLow = FnU1_PfBat_Moni_getStsVoltageLow();

  if (0) {
    /* 何もしない */
  }
  else if (tu1BatVolLow == (U1)C_ON) {
    tu1LedReq0 = (U1)C_OFF;
    tu1LedReq1 = (U1)C_OFF;
    tu1LedReq2 = (U1)C_OFF;
    tu1LedReq3 = (U1)C_OFF;
  }
  else {
#if defined(OP_PfSche_Main_TestLed)
    /* ToDo:テスト用のため最終的には削除する */
    /* 確認用LED点灯処理 */
    tu4MainCnt   = FnU4_HwSrv_Sche_getMainCnt();
    tu4Int1msCnt = FnU4_HwSrv_Sche_getInt1msCnt();

    tu1LedReq0 = (((U4)(tu4MainCnt & (U4)0x00000080) == (U4)0) ? (U1)C_ON : (U1)C_OFF);
    tu1LedReq1 = tu1LedReq0;
    tu1LedReq2 = (((U4)(tu4Int1msCnt & (U4)0x00000100) == (U4)0) ? (U1)C_ON : (U1)C_OFF);
    tu1LedReq3 = tu1LedReq2;
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

