#if !defined(INCLUDED_hw_pph_clk_cfg_pac_h)
#define INCLUDED_hw_pph_clk_cfg_pac_h
/* ============================================================ */
/* ファイル名 : hw_pph_clk_cfg_pac.h                            */
/* 機能       : クロック処理用ユーザ設定                        */
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
#include "hw_pph_clk_pac.h"


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */
/* PLLウェイト時間設定 */
#define CEN_HwPph_Clk_CfgPllWaitTim      CEN_HwPph_Clk_PllWaitTim_4194304Cyc

/* PLL停止制御 */
#define CU1_HwPph_Clk_CfgPllStop         ((U1)C_OFF)

/* SDCLK端子出力制御 */
#define CU1_HwPph_Clk_CfgSdRamClkPortStop    ((U1)C_ON)

/* BCLK端子出力制御 */
#define CU1_HwPph_Clk_CfgBusClkPortStop      ((U1)C_ON)

/* 各種クロックの入力クロック分周設定 */
#define CEN_HwPph_Clk_CfgPllIDiv         CEN_HwPph_Clk_PllIDiv_1
#define CEN_HwPph_Clk_CfgFreqMul         CEN_HwPph_Clk_FreqMul_16
#define CEN_HwPph_Clk_CfgPphClkA         CEN_HwPph_Clk_PphClkA_Div02
#define CEN_HwPph_Clk_CfgPphClkB         CEN_HwPph_Clk_PphClkB_Div04
#define CEN_HwPph_Clk_CfgExtBusClk       CEN_HwPph_Clk_ExtBusClk_Div04
#define CEN_HwPph_Clk_CfgSysClk          CEN_HwPph_Clk_SysClk_Div02
#define CEN_HwPph_Clk_CfgFlashIfClk      CEN_HwPph_Clk_FlashIfClk_Div04
#define CEN_HwPph_Clk_CfgIeBusClk        CEN_HwPph_Clk_IeBusClk_Div04
#define CEN_HwPph_Clk_CfgUsbClk          CEN_HwPph_Clk_UsbClk_Div04

/* クロックソース選択 */
#define CEN_HwPph_Clk_CfgSrcSel          CEN_HwPph_Clk_SrcSel_PLL

/* BCLK端子出力選択 */
#define CU1_HwPph_Clk_CfgExtBusClkDiv    ((U1)C_ON)

/* [MHz]メインクロック周波数 */
#define CFL_HwPph_Clk_CfgMainClkFreq        ((FL)12.0F)

/* [MHz]PLL入力クロック周波数 */
#define CFL_HwPph_Clk_CfgPllClkFreq         McFL_HwPph_Clk_calPllClkFreq(CFL_HwPph_Clk_CfgMainClkFreq, CEN_HwPph_Clk_CfgPllIDiv)

/* [MHz]CPUクロック周波数 */
#define CFL_HwPph_Clk_CfgCpuClkFreq         McFL_HwPph_Clk_calCpuClkFreq(CFL_HwPph_Clk_CfgPllClkFreq, CEN_HwPph_Clk_CfgFreqMul)

/* [MHz]周辺モジュールクロックA周波数 */
#define CFL_HwPph_Clk_CfgPphClkAFreq        McFL_HwPph_Clk_calPphClkAFreq(CFL_HwPph_Clk_CfgCpuClkFreq, CEN_HwPph_Clk_CfgPphClkA)

/* [MHz]周辺モジュールクロックB周波数 */
#define CFL_HwPph_Clk_CfgPphClkBFreq        McFL_HwPph_Clk_calPphClkBFreq(CFL_HwPph_Clk_CfgCpuClkFreq, CEN_HwPph_Clk_CfgPphClkB)

/* [MHz]外部バスクロック周波数 */
#define CFL_HwPph_Clk_CfgExtBusClkFreq      McFL_HwPph_Clk_calExtBusClkFreq(CFL_HwPph_Clk_CfgCpuClkFreq, CEN_HwPph_Clk_CfgExtBusClk)

/* [MHz]システムクロック周波数 */
#define CFL_HwPph_Clk_CfgSysClkFreq         McFL_HwPph_Clk_calSysClkFreq(CFL_HwPph_Clk_CfgCpuClkFreq, CEN_HwPph_Clk_CfgSysClk)

/* [MHz]FlashIFクロック周波数 */
#define CFL_HwPph_Clk_CfgFlashIfClkFreq     McFL_HwPph_Clk_calFlashIfClkFreq(CFL_HwPph_Clk_CfgCpuClkFreq, CEN_HwPph_Clk_CfgFlashIfClk)

/* [MHz]IEBUSクロック周波数 */
#define CFL_HwPph_Clk_CfgIeBusClkFreq       McFL_HwPph_Clk_calIeBusClkFreq(CFL_HwPph_Clk_CfgCpuClkFreq, CEN_HwPph_Clk_CfgIeBusClk)

/* [MHz]USBクロック周波数 */
#define CFL_HwPph_Clk_CfgUsbClkFreq         McFL_HwPph_Clk_calUsbClkFreq(CFL_HwPph_Clk_CfgCpuClkFreq, CEN_HwPph_Clk_CfgUsbClk)


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
extern const EN_HwPph_Clk_PllWaitTim CEN_HwPph_Clk_CfgPllWaitTim_;
extern const EN_HwPph_Clk_PllIDiv CEN_HwPph_Clk_CfgPllIDiv_;
extern const EN_HwPph_Clk_FreqMul CEN_HwPph_Clk_CfgFreqMul_;
extern const U1 CU1_HwPph_Clk_CfgPllStop_;
extern const EN_HwPph_Clk_PphClkB CEN_HwPph_Clk_CfgPphClkB_;
extern const EN_HwPph_Clk_PphClkA CEN_HwPph_Clk_CfgPphClkA_;
extern const EN_HwPph_Clk_ExtBusClk CEN_HwPph_Clk_CfgExtBusClk_;
extern const U1 CU1_HwPph_Clk_CfgSdRamClkPortStop_;
extern const U1 CU1_HwPph_Clk_CfgBusClkPortStop_;
extern const EN_HwPph_Clk_SysClk CEN_HwPph_Clk_CfgSysClk_;
extern const EN_HwPph_Clk_FlashIfClk CEN_HwPph_Clk_CfgFlashIfClk_;
extern const EN_HwPph_Clk_IeBusClk CEN_HwPph_Clk_CfgIeBusClk_;
extern const EN_HwPph_Clk_UsbClk CEN_HwPph_Clk_CfgUsbClk_;
extern const EN_HwPph_Clk_SrcSel CEN_HwPph_Clk_CfgSrcSel_;
extern const U1 CU1_HwPph_Clk_CfgExtBusClkDiv_;


/* ============================================================ */
/* 関数形式マクロ定義                                           */
/* ============================================================ */


#endif
