#if !defined(INCLUDED_hw_pph_cmt_cfg_pac_h)
#define INCLUDED_hw_pph_cmt_cfg_pac_h
/* ============================================================ */
/* ファイル名 : hw_pph_cmt_cfg_pac.h                            */
/* 機能       : CMT処理用ユーザ設定                             */
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
#include "hw_pph_cmt_pac.h"


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */
/* 各CMTユニットの入力クロック分周比設定 */
#define CEN_HwPph_Cmt_CfgUnit0SelClk_Div    CEN_HwPph_Cmt_SelClk_Div032
#define CEN_HwPph_Cmt_CfgUnit1SelClk_Div    CEN_HwPph_Cmt_SelClk_Div032
#define CEN_HwPph_Cmt_CfgUnit2SelClk_Div    CEN_HwPph_Cmt_SelClk_Div008
#define CEN_HwPph_Cmt_CfgUnit3SelClk_Div    CEN_HwPph_Cmt_SelClk_Div008

/* [MHz]各CMTユニットのカウント周波数 */
#define CFL_HwPph_Cmt_CfgUnit0CntClkFreq    McFL_HwPph_Cmt_calCmtCntClkFreq(CEN_HwPph_Cmt_CfgUnit0SelClk_Div)
#define CFL_HwPph_Cmt_CfgUnit1CntClkFreq    McFL_HwPph_Cmt_calCmtCntClkFreq(CEN_HwPph_Cmt_CfgUnit1SelClk_Div)
#define CFL_HwPph_Cmt_CfgUnit2CntClkFreq    McFL_HwPph_Cmt_calCmtCntClkFreq(CEN_HwPph_Cmt_CfgUnit2SelClk_Div)
#define CFL_HwPph_Cmt_CfgUnit3CntClkFreq    McFL_HwPph_Cmt_calCmtCntClkFreq(CEN_HwPph_Cmt_CfgUnit3SelClk_Div)

/* 割り込み信号生成周期[us] */
#define CFL_HwPph_Cmt_CfgUnit0IntPeriod    ((FL)0.0F)
#define CFL_HwPph_Cmt_CfgUnit1IntPeriod    ((FL)1000.0F)
#define CFL_HwPph_Cmt_CfgUnit2IntPeriod    ((FL)0.0F)
#define CFL_HwPph_Cmt_CfgUnit3IntPeriod    ((FL)0.0F)

/* 各CMTユニットのコンペア値設定 */
/* Memo:コンペア値 = 周波数 * 周期 - 1 */
/* Memo:カウンタ値とコンペア値が一致時点から1クロック後に割り込み信号が発生する */
/* Note:未使用のユニットは最大値0xFFFF(初期値)を設定することとする */
#define CU2_HwPph_Cmt_CfgUnit0CompareVal   ((U2)0x7FFF)
#define CU2_HwPph_Cmt_CfgUnit1CompareVal   ((U2)((U2)((FL)(CFL_HwPph_Cmt_CfgUnit1CntClkFreq * CFL_HwPph_Cmt_CfgUnit1IntPeriod)) - (U2)1))
#define CU2_HwPph_Cmt_CfgUnit2CompareVal   ((U2)0xFFFF)
#define CU2_HwPph_Cmt_CfgUnit3CompareVal   ((U2)0xFFFF)


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
extern const ST_HwPph_Cmt_Cfg CST_HwPph_Cmt_CfgUnit[CU1_HwPph_Cmt_ChNum];


/* ============================================================ */
/* 関数形式マクロ定義                                           */
/* ============================================================ */


#endif
