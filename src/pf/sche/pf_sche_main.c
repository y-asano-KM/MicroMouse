/* ============================================================ */
/* ファイル名 : pf_sche_main.c                                  */
/* 機能       : PFメインスケジュール                            */
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
#include "pf_switch_ctrl_pac.h"
#include "pf_bat_monitor_pac.h"
#include "pf_bled_ctrl_pac.h"
#include "pf_led_ctrl_pac.h"
#include "pf_bz_ctrl_pac.h"
#include "app_controll.h"
#include "app_recgwall.h"
#include "app_map.h"
#include "app_plan_mode.h"

/* 本体 */
#include "pf_sche_main.h"


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
const U4 CU4_PfSche_Main_Dummy = (U4)0;


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
/* 関数名 : FnVD_PfSche_wrapMainProc                            */
/*          PFメインスケジュール                                */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : メイン処理の実行順を管理する                        */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_PfSche_wrapMainProc(VD)
{
  /* HW入力値取得 */
  FnVD_PfIf_Hw_input();

  /* スイッチ入力制御処理 */
  FnVD_PfSwt_Ctrl_proc();

  /* バッテリー電圧低下判定 */
  FnVD_PfBat_Moni_jdgVoltageLow();

  /* 壁認識処理 */
  FnVD_AppRcg_detectWall();

  /* 走行モード遷移判定 */
  FnVD_AppPln_Mode_jdgTransition();

  /* CONTROLLメイン処理 */
  FnVD_AppCtrl_mngTsk();

  /* 自車位置情報更新 */
  FnVD_AppMap_updatePosition();

  /* 壁情報更新 */
  FnVD_AppMap_updateWall();

  /* LED制御 */
  FnVD_PfLed_Ctrl_mediate();

  /* バッテリー電圧監視用LED制御 */
  FnVD_PfBled_Ctrl_mediate();

  /* ブザー制御 */
  FnVD_PfBz_Ctrl_mediate();

  /* HW出力値指示 */
  FnVD_PfIf_Hw_output();
}

