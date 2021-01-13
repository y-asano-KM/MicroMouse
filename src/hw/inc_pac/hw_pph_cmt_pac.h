#if !defined(INCLUDED_hw_pph_cmt_pac_h)
#define INCLUDED_hw_pph_cmt_pac_h
/* ============================================================ */
/* ファイル名 : hw_pph_cmt_pac.h                                */
/* 機能       : CMT処理                                         */
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
#include "hw_pph_clk_cfg_pac.h"

/* 本体 */


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */
/* チャネル数 */
#define CU1_HwPph_Cmt_ChNum    ((U4)4)


/* ============================================================ */
/* 型定義                                                       */
/* ============================================================ */
/* CMTユニット番号定義 */
typedef enum {
  CEN_HwPph_Cmt_Unit_0 = 0,  /* #0:ユニット0 */
  CEN_HwPph_Cmt_Unit_1,      /* #1:ユニット1 */
  CEN_HwPph_Cmt_Unit_2,      /* #2:ユニット2 */
  CEN_HwPph_Cmt_Unit_3       /* #3:ユニット3 */
} EN_HwPph_Cmt_Unit;

/* クロック選択(CMCR.CKS) */
typedef enum {
  CEN_HwPph_Cmt_SelClk_Div008 = 0x0,  /* #00b:PCLK/8  */
  CEN_HwPph_Cmt_SelClk_Div032 = 0x1,  /* #01b:PCLK/32 */
  CEN_HwPph_Cmt_SelClk_Div128 = 0x2,  /* #02b:PCLK/128 */
  CEN_HwPph_Cmt_SelClk_Div512 = 0x3   /* #03b:PCLK/512 */
} EN_HwPph_Cmt_SelClk;

typedef struct {
  EN_HwPph_Cmt_SelClk enSelClk;     /* クロック選択(PCLKベース) */
  U1                  u1IntEnb;     /* コンペアマッチ割り込み(CMIn)許可設定 */
  U2                  u2Compare;    /* コンペア値 */
} ST_HwPph_Cmt_Cfg;

/* ============================================================ */
/* 関数プロトタイプ宣言(extern)                                 */
/* ============================================================ */
extern VD FnVD_HwPph_Cmt_resetModuleStp(EN_HwPph_Cmt_Unit tenUnit);
extern VD FnVD_HwPph_Cmt_stpModuleStp(EN_HwPph_Cmt_Unit tenUnit);
extern VD FnVD_HwPph_Cmt_stpCnt(EN_HwPph_Cmt_Unit tenUnit);
extern VD FnVD_HwPph_Cmt_staCnt(EN_HwPph_Cmt_Unit tenUnit);
extern VD FnVD_HwPph_Cmt_clrCnt(EN_HwPph_Cmt_Unit tenUnit);
extern VD FnVD_HwPph_Cmt_setCnt(EN_HwPph_Cmt_Unit tenUnit, U2 tu2Val);
extern U2 FnU2_HwPph_Cmt_getCnt(EN_HwPph_Cmt_Unit tenUnit);
extern VD FnVD_HwPph_Cmt_setCompareValue(EN_HwPph_Cmt_Unit tenUnit, U2 tu2Val);
extern VD FnVD_HwPph_Cmt_cfg(EN_HwPph_Cmt_Unit tenUnit, const ST_HwPph_Cmt_Cfg * tpstCfg);


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
/* 関数名 : McU2_HwPph_Cmt_getClkDiv                            */
/*          CMT入力クロック分周比取得                           */
/* 引数   : tenDiv      クロック選択                            */
/*          (EN_HwPph_Cmt_SelClk型)                             */
/* 戻り値 : CMT入力クロック分周比                               */
/* 概要   : CMT入力クロック分周比を返す                         */
/* 制約   : なし                                                */
/* ============================================================ */
#define McU2_HwPph_Cmt_getClkDiv(tenDiv)  ((U2)(  ((tenDiv == CEN_HwPph_Cmt_SelClk_Div008) ? (U2)8   : (U2)0) \
                                                + ((tenDiv == CEN_HwPph_Cmt_SelClk_Div032) ? (U2)32  : (U2)0) \
                                                + ((tenDiv == CEN_HwPph_Cmt_SelClk_Div128) ? (U2)128 : (U2)0) \
                                                + ((tenDiv == CEN_HwPph_Cmt_SelClk_Div512) ? (U2)512 : (U2)0)))


/* ============================================================ */
/* 関数名 : McFL_HwPph_Cmt_calCmtCntClkFreq                     */
/*          CMTカウントクロック周波数演算                       */
/* 引数   : tenDiv      クロック選択                            */
/*          (EN_HwPph_Cmt_SelClk型)                             */
/* 戻り値 : [MHz]CMTカウントクロック周波数                      */
/* 概要   : CMTカウントクロック周波数値を返す                   */
/* 制約   : なし                                                */
/* ============================================================ */
#define McFL_HwPph_Cmt_calCmtCntClkFreq(tenDiv)  ((FL)(CFL_HwPph_Clk_CfgPphClkBFreq / (FL)McU2_HwPph_Cmt_getClkDiv(tenDiv)))


#endif
