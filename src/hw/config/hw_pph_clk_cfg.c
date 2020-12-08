/* ============================================================ */
/* ファイル名 : hw_pph_clk_cfg.c                                */
/* 機能       : クロック処理用ユーザ設定                        */
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
#include "hw_pph_clk_pac.h"
#include "hw_pph_clk_cfg_pac.h"


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
/* ------------------- */
/* PLLWTCRレジスタ設定 */
/* ------------------- */
/* PLLウェイト時間設定(PLLWTCR.PSTS) */
const EN_HwPph_Clk_PllWaitTim CEN_HwPph_Clk_PllWaitTim = CEN_HwPph_Clk_PllWaitTim_4194304Cyc;

/* ----------------- */
/* PLLCRレジスタ設定 */
/* ----------------- */
/* PLL入力分周比選択(PLLCR.PLIDIV) */
const EN_HwPph_Clk_PllIDiv CEN_HwPph_Clk_PllIDiv = CEN_HwPph_Clk_PllIDiv_1;

/* 周波数逓倍率設定(PLLCR.STC) */
const EN_HwPph_Clk_FreqMul CEN_HwPph_Clk_FreqMul = CEN_HwPph_Clk_FreqMul_16;

/* ------------------ */
/* PLLCR2レジスタ設定 */
/* ------------------ */
/* PLL停止制御(PLLCR2.PLLEN) */
const U1 CU1_HwPph_Clk_PllStop = (U1)0;

/* ----------------- */
/* SCKCRレジスタ設定 */
/* ----------------- */
/* 周辺モジュールクロックB選択(SCKCR.PCKB) */
const EN_HwPph_Clk_PphClkB CEN_HwPph_Clk_PphClkB = CEN_HwPph_Clk_PphClkB_Div04;

/* 周辺モジュールクロックA選択(SCKCR.PCKA) */
const EN_HwPph_Clk_PphClkA CEN_HwPph_Clk_PphClkA = CEN_HwPph_Clk_PphClkA_Div02;

/* 外部バスクロック選択(SCKCR.BCK) */
const EN_HwPph_Clk_ExtBusClk CEN_HwPph_Clk_ExtBusClk = CEN_HwPph_Clk_ExtBusClk_Div04;

/* SDCLK端子出力制御(SCKCR.PSTOP0) */
const U1 CU1_HwPph_Clk_SdRamClkPortStop = (U1)1;

/* BCLK端子出力制御(SCKCR.PSTOP1) */
const U1 CU1_HwPph_Clk_BusClkPortStop = (U1)1;

/* システムクロック選択(SCKCR.ICK) */
const EN_HwPph_Clk_SysClk CEN_HwPph_Clk_SysClk = CEN_HwPph_Clk_SysClk_Div02;

/* FlashIFクロック選択(SCKCR.FCK) */
const EN_HwPph_Clk_FlashIfClk CEN_HwPph_Clk_FlashIfClk = CEN_HwPph_Clk_FlashIfClk_Div04;

/* ------------------ */
/* SCKCR2レジスタ設定 */
/* ------------------ */
/* IEBUSクロック選択(SCKCR2.IEBCK) */
const EN_HwPph_Clk_IeBusClk CEN_HwPph_Clk_IeBusClk = CEN_HwPph_Clk_IeBusClk_Div04;

/* USBクロック選択(SCKCR2.UCK) */
const EN_HwPph_Clk_UsbClk CEN_HwPph_Clk_UsbClk = CEN_HwPph_Clk_UsbClk_Div04;

/* ------------------ */
/* SCKCR3レジスタ設定 */
/* ------------------ */
/* クロックソース選択(SCKCR3.CKSEL) */
const EN_HwPph_Clk_SrcSel CEN_HwPph_Clk_SrcSel = CEN_HwPph_Clk_SrcSel_PLL;

/* ------------------ */
/* BCKCRレジスタ設定 */
/* ------------------ */
/* BCLK端子出力選択(BCKCR.BCLKDIV) */
const U1 CU1_HwPph_Clk_ExtBusClkDiv = (U1)1;

/* ============================================================ */
/* const変数定義(static)                                        */
/* ============================================================ */


/* ============================================================ */
/* 関数形式マクロ定義                                           */
/* ============================================================ */


/* ============================================================ */
/* 関数定義                                                     */
/* ============================================================ */
