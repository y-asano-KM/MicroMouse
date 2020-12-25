#if !defined(INCLUDED_pf_if_hw_pac_h)
#define INCLUDED_pf_if_hw_pac_h
/* ============================================================ */
/* ファイル名 : pf_if_hw_pac.h                                  */
/* 機能       : HW I/F処理                                      */
/* ============================================================ */

/* ============================================================ */
/* インクルード                                                 */
/* ============================================================ */
/* プロジェクト共通 */
#include "prj_cmn_option.h"
#include "prj_cmn_type.h"
#include "prj_cmn_macro.h"

/* カテゴリ共通 */
#include "pf_cmn_option.h"
#include "pf_cmn_option_pac.h"

/* 個別 */

/* 本体 */


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */


/* ============================================================ */
/* 型定義                                                       */
/* ============================================================ */


/* ============================================================ */
/* 関数プロトタイプ宣言(extern)                                 */
/* ============================================================ */
extern VD FnVD_PfIf_Hw_init(VD);
extern VD FnVD_PfIf_Hw_input(VD);
extern VD FnVD_PfIf_Hw_Output(VD);
extern VD FnVD_PfIf_Hw_inputForInt(VD);
extern VD FnVD_PfIf_Hw_outputForInt(VD);


/* ============================================================ */
/* 変数宣言(extern)                                             */
/* ============================================================ */


/* ============================================================ */
/* const変数宣言(extern)                                        */
/* ============================================================ */


/* ============================================================ */
/* 関数形式マクロ定義                                           */
/* ============================================================ */


#endif