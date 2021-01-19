/* ============================================================ */
/* ファイル名 : pf_sche_init.c                                  */
/* 機能       : PF初期化スケジュール                            */
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
#include "pf_if_hw_pac.h"
#include "pf_bat_if_pac.h"
#include "pf_bat_monitor_pac.h"
#include "pf_bled_ctrl_pac.h"
#include "pf_switch_if_pac.h"
#include "pf_switch_ctrl_pac.h"
#include "pf_raysens_if_pac.h"
#include "pf_led_ctrl_pac.h"
#include "pf_bz_ctrl_pac.h"
#include "pf_mtr_if_pac.h"

/* 本体 */
#include "pf_sche_init.h"


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
/* 関数名 : FnVD_PfSche_wrapInitProc                            */
/*          PF初期化スケジュール                                */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 初期化処理の実行順を管理する                        */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_PfSche_wrapInitProc(VD)
{
  /* -------------------- */
  /* ハードウェア層初期化 */
  /* -------------------- */
  FnVD_PfIf_Hw_init();

  /* ---------- */
  /* PF層初期化 */
  /* ---------- */
  /* 光学センサI/F処理初期化 */
  FnVD_PfRaySens_If_initPf();

  /* LED制御初期化 */
  FnVD_PfLed_Ctrl_init();

  /* ブザー制御初期化 */
  FnVD_PfBz_Ctrl_init();

  /* バッテリーI/F処理初期化 */
  FnVD_PfBat_If_initPf();

  /* バッテリー監視初期化 */
  FnVD_PfBat_Moni_init();
  FnVD_PfBled_Ctrl_init();

  /* スイッチ入力I/F処理初期化 */
  FnVD_PfSwt_If_initPf();

  /* スイッチ入力処理初期化 */
  FnVD_PfSwt_Ctrl_init();

  /* モータI/F処理初期化 */
  FnVD_PfMtr_If_initPf();

  /* -------------- */
  /* アプリ層初期化 */
  /* -------------- */
  /* ToDo:未実装 */
}

