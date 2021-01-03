#if !defined(INCLUDED_hw_srv_chkmemn_pac_h)
#define INCLUDED_hw_srv_chkmemn_pac_h
/* ============================================================ */
/* ファイル名 : hw_srv_chkmemn_pac.h                            */
/* 機能       : メモリ監視                                      */
/* ============================================================ */

/* ============================================================ */
/* インクルード                                                 */
/* ============================================================ */
/* プロジェクト共通 */
#include "prj_cmn_option.h"
#include "prj_cmn_type.h"
#include "prj_cmn_macro.h"

/* カテゴリ共通 */
#include "hw_cmn_option.h"
#include "hw_cmn_option_pac.h"

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


/* ============================================================ */
/* 変数宣言(extern)                                             */
/* ============================================================ */


/* ============================================================ */
/* const変数宣言(extern)                                        */
/* ============================================================ */


/* ============================================================ */
/* 関数形式マクロ定義                                           */
/* ============================================================ */
extern VD FnVD_HwSrv_ChkMem_init(VD);
extern VD FnVD_HwSrv_ChkMem_proc(VD);
extern U1 FnU1_HwSrv_ChkMem_getIntStackOverFlowFlg(VD);
extern U1 FnU1_HwSrv_ChkMem_getUsrStackOverFlowFlg(VD);


#endif
