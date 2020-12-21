/* ============================================================ */
/* ファイル名 : hw_pph_cmt_cfg.c                                */
/* 機能       : CMT処理用ユーザ設定                             */
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
#include "prj_sche_main.h"

/* 本体 */
#include "hw_pph_cmt_pac.h"
#include "hw_pph_cmt_cfg_pac.h"


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
const ST_HwPph_Cmt_Cfg CST_HwPph_Cmt_CfgUnit[CU1_HwPph_Cmt_ChNum] = {
/* enSelClk,                         u1IntEnb, u2Compare */
  {CEN_HwPph_Cmt_CfgUnit0SelClk_Div, (U1)0,    CU2_HwPph_Cmt_CfgUnit0CompareVal},   /* CEN_HwPph_Cmt_Ch_0 */  /* 時刻取得用タイマー */
  {CEN_HwPph_Cmt_CfgUnit1SelClk_Div, (U1)1,    CU2_HwPph_Cmt_CfgUnit1CompareVal},   /* CEN_HwPph_Cmt_Ch_1 */  /* 1ms定期割り込み */
  {CEN_HwPph_Cmt_CfgUnit2SelClk_Div, (U1)0,    CU2_HwPph_Cmt_CfgUnit2CompareVal},   /* CEN_HwPph_Cmt_Ch_2 */  /* Memo:未使用 */
  {CEN_HwPph_Cmt_CfgUnit3SelClk_Div, (U1)0,    CU2_HwPph_Cmt_CfgUnit3CompareVal}    /* CEN_HwPph_Cmt_Ch_3 */  /* Memo:未使用 */
};


/* ============================================================ */
/* const変数定義(static)                                        */
/* ============================================================ */


/* ============================================================ */
/* 関数形式マクロ定義                                           */
/* ============================================================ */


/* ============================================================ */
/* 関数定義                                                     */
/* ============================================================ */


