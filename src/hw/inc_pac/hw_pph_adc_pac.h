#if !defined(INCLUDED_hw_pph_adc_pac_h)
#define INCLUDED_hw_pph_adc_pac_h
/* ============================================================ */
/* ファイル名 : hw_pph_adc_pac.h                                */
/* 機能       : A/D変換処理                                     */
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
/* チャネル数 */
#define CU1_HwPph_Adc_ChNum  ((U1)21)

/* フルレンジ */
#define CU2_HwPph_Adc_FullRange  ((U2)0x0FFF)

/* [ステート]ADSSTR01.SST1設定最小値 */
#define CU2_HwPph_Adc_ADSSTR01_SST1_Min  ((U2)20)


/* ============================================================ */
/* 型定義                                                       */
/* ============================================================ */
/* チャネル番号定義 */
typedef enum {
  CEN_HwPph_Adc_Ch_00 = 0,   /* #00:チャネル番号0  */
  CEN_HwPph_Adc_Ch_01,       /* #01:チャネル番号1  */
  CEN_HwPph_Adc_Ch_02,       /* #02:チャネル番号2  */
  CEN_HwPph_Adc_Ch_03,       /* #03:チャネル番号3  */
  CEN_HwPph_Adc_Ch_04,       /* #04:チャネル番号4  */
  CEN_HwPph_Adc_Ch_05,       /* #05:チャネル番号5  */
  CEN_HwPph_Adc_Ch_06,       /* #06:チャネル番号6  */
  CEN_HwPph_Adc_Ch_07,       /* #07:チャネル番号7  */
  CEN_HwPph_Adc_Ch_08,       /* #08:チャネル番号8  */
  CEN_HwPph_Adc_Ch_09,       /* #09:チャネル番号9  */
  CEN_HwPph_Adc_Ch_10,       /* #10:チャネル番号10 */
  CEN_HwPph_Adc_Ch_11,       /* #11:チャネル番号11 */
  CEN_HwPph_Adc_Ch_12,       /* #12:チャネル番号12 */
  CEN_HwPph_Adc_Ch_13,       /* #13:チャネル番号13 */
  CEN_HwPph_Adc_Ch_14,       /* #14:チャネル番号14 */
  CEN_HwPph_Adc_Ch_15,       /* #15:チャネル番号15 */
  CEN_HwPph_Adc_Ch_16,       /* #16:チャネル番号16 */
  CEN_HwPph_Adc_Ch_17,       /* #17:チャネル番号17 */
  CEN_HwPph_Adc_Ch_18,       /* #18:チャネル番号18 */
  CEN_HwPph_Adc_Ch_19,       /* #19:チャネル番号18 */
  CEN_HwPph_Adc_Ch_20        /* #20:チャネル番号20 */
} EN_HwPph_Adc_Ch;

/* A/D変換クロック選択 */
typedef enum {
  CEN_HwPph_Adc_SelClk_Div8 = 0x0,  /* PCLK/8 */
  CEN_HwPph_Adc_SelClk_Div4 = 0x1,  /* PCLK/4 */
  CEN_HwPph_Adc_SelClk_Div2 = 0x2,  /* PCLK/2 */
  CEN_HwPph_Adc_SelClk_Div1 = 0x3   /* PCLK   */
} EN_HwPph_Adc_SelClk;

/* 加算回数選択 */
typedef enum {
  CEN_HwPph_Adc_SelAddTime_0 = 0x0,  /* 1回変換(加算なし) */
  CEN_HwPph_Adc_SelAddTime_1 = 0x1,  /* 2回変換(1回加算) */
  CEN_HwPph_Adc_SelAddTime_2 = 0x2,  /* 3回変換(2回加算) */
  CEN_HwPph_Adc_SelAddTime_3 = 0x3   /* 4回変換(3回加算) */
} EN_HwPph_Adc_SelAddTime;

/* A/D変換クロック選択 */
typedef enum {
  CEN_HwPph_Adc_Format_Right = 0,  /* 右詰め */
  CEN_HwPph_Adc_Format_Left  = 1   /* 左詰め */
} EN_HwPph_Adc_Format;

/* A/D変換実行ステータス */
typedef enum {
  CEN_HwPph_Adc_Sts_Idle = 0,  /* 待機状態(停止中) */
  CEN_HwPph_Adc_Sts_Run  = 1   /* 実行中 */
} EN_HwPph_Adc_Sts;


/* ============================================================ */
/* 関数プロトタイプ宣言(extern)                                 */
/* ============================================================ */
extern VD FnVD_HwPph_Adc_resetModuleStp(VD);
extern VD FnVD_HwPph_Adc_stpModuleStp(VD);
extern VD FnVD_HwPph_Adc_cfg(VD);
extern VD FnVD_HwPph_Adc_selTargetCh(U4 tu4Set, U4 tu4Clr);
extern EN_HwPph_Adc_Sts FnEN_HwPph_Adc_getSts(VD);
extern VD FnVD_HwPph_Adc_start(VD);
extern VD FnVD_HwPph_Adc_end(VD);
extern VD FnVD_HwPph_Adc_renewBuf(VD);
extern U2 FnU2_HwPph_Adc_getVal(EN_HwPph_Adc_Ch tenCh);


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
