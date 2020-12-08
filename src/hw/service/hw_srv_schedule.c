/* ============================================================ */
/* ファイル名 : hw_srv_schedule.c                               */
/* 機能       : スケジューラを提供する                          */
/* ============================================================ */
#define SECTION_HW

/* ============================================================ */
/* インクルード                                                 */
/* ============================================================ */
/* プロジェクト共通 */
#include "prj_cmn_section.h"
#include "prj_cmn_option.h"
#include "prj_cmn_type.h"
#include "prj_cmn_macro.h"

/* カテゴリ共通 */
#include "hw_cmn_option.h"
#include "hw_cmn_option_pac.h"

/* 個別 */
#include "hw_pph_clk_pac.h"

/* 本体 */
#include "hw_srv_schedule_cfg_pac.h"
#include "hw_srv_schedule_pac.h"


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
/* 関数名 : FnVD_HwSrv_wrapInitProc                             */
/*          初期化スケジュール                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : ユーザ初期化スケジュールを呼び出す                  */
/* 制約   : 割り込み禁止区間で呼び出すこと                      */
/*          割り込みを許可としないこと                          */
/* ============================================================ */
VD FnVD_HwSrv_wrapInitProc(VD)
{
  /* クロック設定 */
  FnVD_HwPph_Clk_init();

  /* PF/APL初期化処理 */
  if (CPFnVD_HwSrv_Sche_CfgInitProc != CPVD_NULL) {
    CPFnVD_HwSrv_Sche_CfgInitProc();
  }
}


/* ============================================================ */
/* 関数名 : FnVD_HwSrv_wrapMainProc                             */
/*          初期化スケジュール                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : ユーザメインスケジュールを呼び出す                  */
/* 制約   : 無限ループ(戻らない)                                */
/* ============================================================ */
VD FnVD_HwSrv_wrapMainProc(VD)
{
  for ( ; ; ) {
    /* 無限ループ */
    if (CPFnVD_HwSrv_Sche_CfgMainProc != CPVD_NULL) {
      CPFnVD_HwSrv_Sche_CfgMainProc();
    }
  }
}
