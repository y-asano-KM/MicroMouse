#if !defined(INCLUDED_app_plan_mode_pac_h)
#define INCLUDED_app_plan_mode_pac_h
/* ============================================================ */
/* ファイル名 : app_plan_mode_pac.h                             */
/* 機能       :                                                 */
/* ============================================================ */

/* ============================================================ */
/* インクルード                                                 */
/* ============================================================ */
/* プロジェクト共通 */
#include "prj_cmn_option.h"
#include "prj_cmn_type.h"
#include "prj_cmn_macro.h"

/* カテゴリ共通 */
#include "app_cmn_option.h"
#include "app_cmn_option_pac.h"

/* 個別 */
#include "pf_switch_ctrl.h"

/* 本体 */


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */


/* ============================================================ */
/* 型定義                                                       */
/* ============================================================ */
/* 動作モードを示す列挙型 */
typedef enum
{
  CEN_AppPln_Mode_Normal = 0,     /* 通常 */
  CEN_AppPln_Mode_Search,         /* 探索 */
  CEN_AppPln_Mode_Num
}EN_AppPln_Mode;

/* ============================================================ */
/* 関数プロトタイプ宣言(extern)                                 */
/* ============================================================ */
extern VD FnVD_AppPln_Mode_init(VD);
extern VD FnVD_AppPln_Mode_transition_permit_judge(VD);
extern VD FnVD_AppPln_Mode_transition_judge(VD);
extern EN_AppPln_Mode FnEN_AppPln_Mode_get(VD);


/* ============================================================ */
/* 変数宣言(extern)                                             */
/* ============================================================ */


/* ============================================================ */
/* const変数宣言(extern)                                        */
/* ============================================================ */


/* ============================================================ */
/* 関数形式マクロ定義                                           */
/* ============================================================ */
/* ============================================================ */
/* 関数名 : McU1_XxYyy_getSignal                                */
/*          関数和名をここへ記述                                */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 関数箱型コメントの形式を示す                        */
/* 制約   : なし                                                */
/* ============================================================ */


#endif
