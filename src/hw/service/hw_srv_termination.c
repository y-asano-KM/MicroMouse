/* ============================================================ */
/* ファイル名 : hw_srv_termination.c                            */
/* 機能       : 終了処理                                        */
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
#include "hw_core_termination_pac.h"

/* 本体 */
#include "hw_srv_termination.h"
#include "hw_srv_termination_cfg_pac.h"


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
/*          停止処理                                            */
/* 引数   : tu4Code  終了コード                                 */
/* 戻り値 : なし                                                */
/* 概要   : 割り込み禁止/全ポート初期化後に無限ループ           */
/* 制約   : 戻らない                                            */
/* ============================================================ */
VD FnVD_HwSrv_Termination_kill(U4 tu4Code)
{
  FnVD_HwCore_Termination_kill(tu4Code);
}

