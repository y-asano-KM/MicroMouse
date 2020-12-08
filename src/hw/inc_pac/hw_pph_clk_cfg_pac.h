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
extern const EN_HwPph_Clk_PllWaitTim CEN_HwPph_Clk_PllWaitTim;
extern const EN_HwPph_Clk_PllIDiv CEN_HwPph_Clk_PllIDiv;
extern const EN_HwPph_Clk_FreqMul CEN_HwPph_Clk_FreqMul;
extern const U1 CU1_HwPph_Clk_PllStop;
extern const EN_HwPph_Clk_PphClkB CEN_HwPph_Clk_PphClkB;
extern const EN_HwPph_Clk_PphClkA CEN_HwPph_Clk_PphClkA;
extern const EN_HwPph_Clk_ExtBusClk CEN_HwPph_Clk_ExtBusClk;
extern const U1 CU1_HwPph_Clk_SdRamClkPortStop;
extern const U1 CU1_HwPph_Clk_BusClkPortStop;
extern const EN_HwPph_Clk_SysClk CEN_HwPph_Clk_SysClk;
extern const EN_HwPph_Clk_FlashIfClk CEN_HwPph_Clk_FlashIfClk;
extern const EN_HwPph_Clk_IeBusClk CEN_HwPph_Clk_IeBusClk;
extern const EN_HwPph_Clk_UsbClk CEN_HwPph_Clk_UsbClk;
extern const EN_HwPph_Clk_SrcSel CEN_HwPph_Clk_SrcSel;
extern const U1 CU1_HwPph_Clk_ExtBusClkDiv;


/* ============================================================ */
/* 関数形式マクロ定義                                           */
/* ============================================================ */


#endif
