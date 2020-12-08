#if !defined(INCLUDED_hw_pph_clk_pac_h)
#define INCLUDED_hw_pph_clk_pac_h
/* ============================================================ */
/* ファイル名 : hw_pph_clk_pac.h                                */
/* 機能       : クロック処理                                    */
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
/* PLL入力分周比選択(PLLCR.PLIDIV) */
typedef enum {
  CEN_HwPph_Clk_PllIDiv_1 = 0x0,  /* 1分周 */
  CEN_HwPph_Clk_PllIDiv_2 = 0x1,  /* 2分周 */
  CEN_HwPph_Clk_PllIDiv_4 = 0x2   /* 4分周 */
} EN_HwPph_Clk_PllIDiv;

/* 周波数逓倍率設定(PLLCR.STC) */
typedef enum {
  CEN_HwPph_Clk_FreqMul_08 = 0x07,  /*  8倍 */
  CEN_HwPph_Clk_FreqMul_10 = 0x09,  /* 10倍 */
  CEN_HwPph_Clk_FreqMul_12 = 0x0B,  /* 12倍 */
  CEN_HwPph_Clk_FreqMul_16 = 0x0F,  /* 16倍 */
  CEN_HwPph_Clk_FreqMul_20 = 0x13,  /* 20倍 */
  CEN_HwPph_Clk_FreqMul_24 = 0x17,  /* 24倍 */
  CEN_HwPph_Clk_FreqMul_25 = 0x18,  /* 25倍 */
  CEN_HwPph_Clk_FreqMul_50 = 0x31   /* 50倍 */
} EN_HwPph_Clk_FreqMul;

/* PLLウェイト時間設定(PLLWTCR.PSTS) */
typedef enum {
  CEN_HwPph_Clk_PllWaitTim_0000016Cyc = 0x00,  /* 待機時間 =      16サイクル */
  CEN_HwPph_Clk_PllWaitTim_0000032Cyc = 0x01,  /* 待機時間 =      32サイクル */
  CEN_HwPph_Clk_PllWaitTim_0000064Cyc = 0x02,  /* 待機時間 =      64サイクル */
  CEN_HwPph_Clk_PllWaitTim_0000512Cyc = 0x03,  /* 待機時間 =     512サイクル */
  CEN_HwPph_Clk_PllWaitTim_0001024Cyc = 0x04,  /* 待機時間 =    1024サイクル */
  CEN_HwPph_Clk_PllWaitTim_0002048Cyc = 0x05,  /* 待機時間 =    2048サイクル */
  CEN_HwPph_Clk_PllWaitTim_0004096Cyc = 0x06,  /* 待機時間 =    4096サイクル */
  CEN_HwPph_Clk_PllWaitTim_0016384Cyc = 0x07,  /* 待機時間 =   16384サイクル */
  CEN_HwPph_Clk_PllWaitTim_0032768Cyc = 0x08,  /* 待機時間 =   32768サイクル */
  CEN_HwPph_Clk_PllWaitTim_0065536Cyc = 0x09,  /* 待機時間 =   65536サイクル */
  CEN_HwPph_Clk_PllWaitTim_0131072Cyc = 0x0A,  /* 待機時間 =  131072サイクル */
  CEN_HwPph_Clk_PllWaitTim_0262144Cyc = 0x0B,  /* 待機時間 =  262144サイクル */
  CEN_HwPph_Clk_PllWaitTim_0524288Cyc = 0x0C,  /* 待機時間 =  524288サイクル */
  CEN_HwPph_Clk_PllWaitTim_1048576Cyc = 0x0D,  /* 待機時間 = 1048576サイクル */
  CEN_HwPph_Clk_PllWaitTim_2097152Cyc = 0x0E,  /* 待機時間 = 2097152サイクル */
  CEN_HwPph_Clk_PllWaitTim_4194304Cyc = 0x0F   /* 待機時間 = 4194304サイクル */
} EN_HwPph_Clk_PllWaitTim;

/* 周辺モジュールクロックB選択(SCKCR.PCKB) */
typedef enum {
  CEN_HwPph_Clk_PphClkB_Div01 = 0x0,  /*  1分周 */
  CEN_HwPph_Clk_PphClkB_Div02 = 0x1,  /*  2分周 */
  CEN_HwPph_Clk_PphClkB_Div04 = 0x2,  /*  4分周 */
  CEN_HwPph_Clk_PphClkB_Div08 = 0x3,  /*  8分周 */
  CEN_HwPph_Clk_PphClkB_Div16 = 0x4,  /* 16分周 */
  CEN_HwPph_Clk_PphClkB_Div32 = 0x5,  /* 32分周 */
  CEN_HwPph_Clk_PphClkB_Div64 = 0x6   /* 64分周 */
} EN_HwPph_Clk_PphClkB;

/* 周辺モジュールクロックA選択(SCKCR.PCKA) */
typedef enum {
  CEN_HwPph_Clk_PphClkA_Div01 = 0x0,  /*  1分周 */
  CEN_HwPph_Clk_PphClkA_Div02 = 0x1,  /*  2分周 */
  CEN_HwPph_Clk_PphClkA_Div04 = 0x2,  /*  4分周 */
  CEN_HwPph_Clk_PphClkA_Div08 = 0x3,  /*  8分周 */
  CEN_HwPph_Clk_PphClkA_Div16 = 0x4,  /* 16分周 */
  CEN_HwPph_Clk_PphClkA_Div32 = 0x5,  /* 32分周 */
  CEN_HwPph_Clk_PphClkA_Div64 = 0x6   /* 64分周 */
} EN_HwPph_Clk_PphClkA;

/* 外部バスクロック選択(SCKCR.BCK) */
typedef enum {
  CEN_HwPph_Clk_ExtBusClk_Div01 = 0x0,  /*  1分周 */
  CEN_HwPph_Clk_ExtBusClk_Div02 = 0x1,  /*  2分周 */
  CEN_HwPph_Clk_ExtBusClk_Div04 = 0x2,  /*  4分周 */
  CEN_HwPph_Clk_ExtBusClk_Div08 = 0x3,  /*  8分周 */
  CEN_HwPph_Clk_ExtBusClk_Div16 = 0x4,  /* 16分周 */
  CEN_HwPph_Clk_ExtBusClk_Div32 = 0x5,  /* 32分周 */
  CEN_HwPph_Clk_ExtBusClk_Div64 = 0x6   /* 64分周 */
} EN_HwPph_Clk_ExtBusClk;

/* システムクロック選択(SCKCR.ICK) */
typedef enum {
  CEN_HwPph_Clk_SysClk_Div01 = 0x0,  /*  1分周 */
  CEN_HwPph_Clk_SysClk_Div02 = 0x1,  /*  2分周 */
  CEN_HwPph_Clk_SysClk_Div04 = 0x2,  /*  4分周 */
  CEN_HwPph_Clk_SysClk_Div08 = 0x3,  /*  8分周 */
  CEN_HwPph_Clk_SysClk_Div16 = 0x4,  /* 16分周 */
  CEN_HwPph_Clk_SysClk_Div32 = 0x5,  /* 32分周 */
  CEN_HwPph_Clk_SysClk_Div64 = 0x6   /* 64分周 */
} EN_HwPph_Clk_SysClk;

/* FlashIFクロック選択(SCKCR.FCK) */
typedef enum {
  CEN_HwPph_Clk_FlashIfClk_Div01 = 0x0,  /*  1分周 */
  CEN_HwPph_Clk_FlashIfClk_Div02 = 0x1,  /*  2分周 */
  CEN_HwPph_Clk_FlashIfClk_Div04 = 0x2,  /*  4分周 */
  CEN_HwPph_Clk_FlashIfClk_Div08 = 0x3,  /*  8分周 */
  CEN_HwPph_Clk_FlashIfClk_Div16 = 0x4,  /* 16分周 */
  CEN_HwPph_Clk_FlashIfClk_Div32 = 0x5,  /* 32分周 */
  CEN_HwPph_Clk_FlashIfClk_Div64 = 0x6   /* 64分周 */
} EN_HwPph_Clk_FlashIfClk;

/* IEBUSクロック選択(SCKCR2.IEBCK) */ /* Memo:IE-Bus(Inter Equipment Bus) */
typedef enum {
  CEN_HwPph_Clk_IeBusClk_Div02 = 0x1,  /*  2分周 */
  CEN_HwPph_Clk_IeBusClk_Div04 = 0x2,  /*  4分周 */
  CEN_HwPph_Clk_IeBusClk_Div08 = 0x3,  /*  8分周 */
  CEN_HwPph_Clk_IeBusClk_Div16 = 0x4,  /* 16分周 */
  CEN_HwPph_Clk_IeBusClk_Div32 = 0x5,  /* 32分周 */
  CEN_HwPph_Clk_IeBusClk_Div64 = 0x6,  /* 64分周 */
  CEN_HwPph_Clk_IeBusClk_Div06 = 0xC   /*  6分周 */
} EN_HwPph_Clk_IeBusClk;

/* USBクロック選択(SCKCR2.UCK) */
typedef enum {
  CEN_HwPph_Clk_UsbClk_NoUse = 0x1,  /* USB未使用時 */
  CEN_HwPph_Clk_UsbClk_Div03 = 0x2,  /* 3分周 */
  CEN_HwPph_Clk_UsbClk_Div04 = 0x3   /* 4分周 */
} EN_HwPph_Clk_UsbClk;

/* クロックソース選択(SCKCR3.CKSEL) */
typedef enum {
  CEN_HwPph_Clk_SrcSel_LOCO = 0x0,  /* LOCO選択 */
  CEN_HwPph_Clk_SrcSel_HOCO = 0x1,  /* HOCO選択 */
  CEN_HwPph_Clk_SrcSel_Main = 0x2,  /* メインクロック発振器選択 */
  CEN_HwPph_Clk_SrcSel_Sub  = 0x3,  /* サブクロック発振器選択 */
  CEN_HwPph_Clk_SrcSel_PLL  = 0x4   /* PLL回路選択 */
} EN_HwPph_Clk_SrcSel;


/* ============================================================ */
/* 関数プロトタイプ宣言(extern)                                 */
/* ============================================================ */
extern VD FnVD_HwPph_Clk_init(VD);


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
