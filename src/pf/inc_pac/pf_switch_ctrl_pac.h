#if !defined(INCLUDED_pf_switch_ctrl_pac_h)
#define INCLUDED_pf_switch_ctrl_pac_h
/* ============================================================ */
/* ファイル名 : pf_switch_ctrl_pac.h                            */
/* 機能       : スイッチ入力制御                                */
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
extern VD FnVD_PfSwt_Ctrl_init(VD);
extern VD FnVD_PfSwt_Ctrl_proc(VD);
extern U1 FnU1_PfSwt_Ctrl_getTactSwtRightMomentary(VD);
extern U1 FnU1_PfSwt_Ctrl_getTactSwtCenterMomentary(VD);
extern U1 FnU1_PfSwt_Ctrl_getTactSwtLeftMomentary(VD);
extern U1 FnU1_PfSwt_Ctrl_getTactSwtRightShortPush(VD);
extern U1 FnU1_PfSwt_Ctrl_getTactSwtCenterShortPush(VD);
extern U1 FnU1_PfSwt_Ctrl_getTactSwtLeftShortPush(VD);
extern U1 FnU1_PfSwt_Ctrl_getTactSwtRightLongPush(VD);
extern U1 FnU1_PfSwt_Ctrl_getTactSwtCenterLongPush(VD);
extern U1 FnU1_PfSwt_Ctrl_getTactSwtLeftLongPush(VD);


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
