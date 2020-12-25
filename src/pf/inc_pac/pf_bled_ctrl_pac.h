#if !defined(INCLUDED_pf_bled_ctrl_pac_h)
#define INCLUDED_pf_bled_ctrl_pac_h
/* ============================================================ */
/* ファイル名 : pf_bled_ctrl_pac.h                              */
/* 機能       : バッテリー監視用LED制御                         */
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
extern VD FnVD_PfBled_Ctrl_init(VD);
extern VD FnVD_PfBled_Ctrl_mediate(VD);
extern U1 FnU1_PfBled_Ctrl_getReqLed0(VD);
extern U1 FnU1_PfBled_Ctrl_getReqLed1(VD);


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