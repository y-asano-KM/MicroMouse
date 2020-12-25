/* ============================================================ */
/* ファイル名 : pf_bled_ctrl.c                                  */
/* 機能       : バッテリー監視用LED制御                         */
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
#include "pf_bled_ctrl_pac.h"


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
static F1 f1PfBled_Ctrl_ReqLed;
#define fPfBled_Ctrl_ReqLed0  f1PfBled_Ctrl_ReqLed.Flag.fBit0
#define fPfBled_Ctrl_ReqLed1  f1PfBled_Ctrl_ReqLed.Flag.fBit1


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
/* 関数名 : FnVD_PfBled_Ctrl_init                               */
/*          バッテリー監視用LED制御処理初期化                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : バッテリー監視用LED制御処理の初期化を行う           */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_PfBled_Ctrl_init(VD)
{
  /* Memo:fPfBled_Ctrl_ReqLed0の初期化を兼ねる */
  /* Memo:fPfBled_Ctrl_ReqLed1の初期化を兼ねる */
  f1PfBled_Ctrl_ReqLed.u1Val = (U1)0x00;
}


/* ============================================================ */
/* 関数名 : FnVD_PfBled_Ctrl_mediate                            */
/*          バッテリー監視用LED消灯/点灯要求調停処理            */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 各種点灯条件/消灯条件の優先度より出力値を調停する   */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_PfBled_Ctrl_mediate(VD)
{
  U1 tu1LedReq0;
  U1 tu1LedReq1;
  U1 tu1BatVolLow;

  /* バッテリー電圧低下状態取得 */
  tu1BatVolLow = FnU1_PfBat_Moni_getStsVoltageLow();

  if (0) {
    /* 何もしない */
  }
  else if (tu1BatVolLow == (U1)C_ON) {
    tu1LedReq0 = (U1)C_OFF;
    tu1LedReq1 = (U1)C_ON;
  }
  else {
    tu1LedReq0 = (U1)C_ON;
    tu1LedReq1 = (U1)C_OFF;
  }

  fPfBled_Ctrl_ReqLed0 = tu1LedReq0;
  fPfBled_Ctrl_ReqLed1 = tu1LedReq1;
}


/* ============================================================ */
/* 関数名 : FnU1_PfBled_Ctrl_getReqLed0                         */
/*          バッテリー監視用LED0消灯/点灯要求出力値取得         */
/* 引数   : なし                                                */
/* 戻り値 : バッテリー監視用LED0消灯/点灯要求出力値             */
/* 概要   : バッテリー監視用LED0消灯/点灯要求出力値を提供する   */
/* 制約   : なし                                                */
/* ============================================================ */
U1 FnU1_PfBled_Ctrl_getReqLed0(VD)
{
  return (fPfBled_Ctrl_ReqLed0);
}


/* ============================================================ */
/* 関数名 : FnU1_PfBled_Ctrl_getReqLed1                         */
/*          バッテリー監視用LED1消灯/点灯要求出力値取得         */
/* 引数   : なし                                                */
/* 戻り値 : バッテリー監視用LED1消灯/点灯要求出力値             */
/* 概要   : バッテリー監視用LED1消灯/点灯要求出力値を提供する   */
/* 制約   : なし                                                */
/* ============================================================ */
U1 FnU1_PfBled_Ctrl_getReqLed1(VD)
{
  return (fPfBled_Ctrl_ReqLed1);
}
