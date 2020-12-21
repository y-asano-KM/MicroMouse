/* ============================================================ */
/* ファイル名 : hw_pph_clk.c                                    */
/* 機能       : クロック処理                                    */
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
#include "hw_pph_reg_pac.h"

/* 本体 */
#include "hw_pph_clk_pac.h"
#include "hw_pph_clk_cfg_pac.h"


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */
#define CU2_HwPph_Clk_ProtectKey    ((U2)0x00A5)    /* 保護解除キー */
#define CU1_HwPph_Clk_PLLCR2_Stop   ((U1)0x01)      /* PLL動作停止 */
#define CU4_HwPph_Clk_SCKCR_Fix0    ((U4)0x1)       /* SCKCRレジスタ固定値ビット0設定値 */
#define CU4_HwPph_Clk_SCKCR_Fix1    ((U4)0x1)       /* SCKCRレジスタ固定値ビット1設定値 */


/* ============================================================ */
/* 型定義                                                       */
/* ============================================================ */


/* ============================================================ */
/* 関数プロトタイプ宣言(static)                                 */
/* ============================================================ */
static VD FnVD_HwPph_Clk_enbClkSetting(VD);
static VD FnVD_HwPph_Clk_dibClkSetting(VD);


/* ============================================================ */
/* 変数定義(extern)                                             */
/* ============================================================ */


/* ============================================================ */
/* 変数定義(static)                                             */
/* ============================================================ */


/* ============================================================ */
/* const変数定義(extern)                                        */
/* ============================================================ */


/* ============================================================ */
/* const変数定義(static)                                        */
/* ============================================================ */


/* ============================================================ */
/* 関数形式マクロ定義                                           */
/* ============================================================ */


/* ============================================================ */
/* 関数定義                                                     */
/* ============================================================ */
/* ============================================================ */
/* 関数名 : FnVD_HwPph_Clk_enbClkSetting                        */
/*          クロック関連レジスタ保護解除                        */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : クロック関連レジスタの保護を解除する                */
/* 制約   : 割り込み禁止中に実行すること                        */
/* ============================================================ */
#pragma inline (FnVD_HwPph_Clk_enbClkSetting)
VD FnVD_HwPph_Clk_enbClkSetting(VD)
{
  ST_PRCR tstPRCR;

  tstPRCR.u2Val = stRegSys0.stPRCR.u2Val;
  tstPRCR.stBit.b1PRC0 = (U2)1;
  tstPRCR.stBit.b1PRC1 = (U2)1;
  tstPRCR.stBit.b8PRKEY = CU2_HwPph_Clk_ProtectKey;
  stRegSys0.stPRCR.u2Val = tstPRCR.u2Val;
}


/* ============================================================ */
/* 関数名 : FnVD_HwPph_Clk_dibClkSetting                        */
/*          クロック関連レジスタ保護                            */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : クロック関連レジスタを保護する                      */
/* 制約   : 割り込み禁止中に実行すること                        */
/* ============================================================ */
#pragma inline (FnVD_HwPph_Clk_dibClkSetting)
VD FnVD_HwPph_Clk_dibClkSetting(VD)
{
  ST_PRCR tstPRCR;

  tstPRCR.u2Val = stRegSys0.stPRCR.u2Val;
  tstPRCR.stBit.b1PRC0 = (U2)0;
  tstPRCR.stBit.b1PRC1 = (U2)0;
  tstPRCR.stBit.b8PRKEY = CU2_HwPph_Clk_ProtectKey;
  stRegSys0.stPRCR.u2Val = tstPRCR.u2Val;
}


/* ============================================================ */
/* 関数名 : FnVD_HwPph_Clk_cfg                                  */
/*          クロック設定                                        */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 各種クロック設定を行う                              */
/* 制約   : 割り込み禁止中に実行すること                        */
/*          スタートアップにて1回のみ実行すること               */
/* ============================================================ */
VD FnVD_HwPph_Clk_cfg(VD)
{
  ST_PLLCR   tstPLLCR;
  ST_PLLCR2  tstPLLCR2;
  ST_PLLWTCR tstPLLWTCR;
  ST_SCKCR   tstSCKCR;
  ST_SCKCR2  tstSCKCR2;
  ST_SCKCR3  tstSCKCR3;
  ST_BCKCR   tstBCKCR;

  /* 保護解除 */
  FnVD_HwPph_Clk_enbClkSetting();

  /* PLL停止 */
  stRegSys0.stPLLCR2.u1Val = CU1_HwPph_Clk_PLLCR2_Stop;

  /* PLLWTCRレジスタ設定 */ /* Note:PLL停止時に設定すること */
  tstPLLWTCR.u1Val = (U1)0x00;
  tstPLLWTCR.stBit.b5PSTS = (U1)CEN_HwPph_Clk_CfgPllWaitTim_;
  stRegSys0.stPLLWTCR.u1Val = tstPLLWTCR.u1Val;

  /* PLLCRレジスタ設定 */ /* Note:PLL停止時に設定すること */
  tstPLLCR.u2Val = (U2)0x0000;
  tstPLLCR.stBit.b2PLIDIV = (U2)CEN_HwPph_Clk_CfgPllIDiv_;
  tstPLLCR.stBit.b6STC    = (U2)CEN_HwPph_Clk_CfgFreqMul_;
  stRegSys0.stPLLCR.u2Val = tstPLLCR.u2Val;

  /* PLLCR2レジスタ設定 */
  tstPLLCR2.u1Val = (U1)0x00;
  tstPLLCR2.stBit.b1PLLEN = CU1_HwPph_Clk_CfgPllStop_;
  stRegSys0.stPLLCR2.u1Val = tstPLLCR2.u1Val;

  /* SCKCRレジスタ設定 */
  tstSCKCR.u4Val = (U4)0x00000000;
  tstSCKCR.stBit.b4Fix0   = CU4_HwPph_Clk_SCKCR_Fix0;
  tstSCKCR.stBit.b4Fix1   = CU4_HwPph_Clk_SCKCR_Fix1;
  tstSCKCR.stBit.b4PCKB   = (U4)CEN_HwPph_Clk_CfgPphClkB_;
  tstSCKCR.stBit.b4PCKA   = (U4)CEN_HwPph_Clk_CfgPphClkA_;
  tstSCKCR.stBit.b4BCK    = (U4)CEN_HwPph_Clk_CfgExtBusClk_;
  tstSCKCR.stBit.b1PSTOP0 = (U4)CU1_HwPph_Clk_CfgSdRamClkPortStop_;
  tstSCKCR.stBit.b1PSTOP1 = (U4)CU1_HwPph_Clk_CfgBusClkPortStop_;
  tstSCKCR.stBit.b4ICK    = (U4)CEN_HwPph_Clk_CfgSysClk_;
  tstSCKCR.stBit.b4FCK    = (U4)CEN_HwPph_Clk_CfgFlashIfClk_;
  stRegSys0.stSCKCR.u4Val = tstSCKCR.u4Val;

  /* SCKCR2レジスタ設定 */
  tstSCKCR2.u2Val = (U2)0x0000;
  tstSCKCR2.stBit.b4IEBCK = (U2)CEN_HwPph_Clk_CfgIeBusClk_;
  tstSCKCR2.stBit.b4UCK   = (U2)CEN_HwPph_Clk_CfgUsbClk_;
  stRegSys0.stSCKCR2.u2Val = tstSCKCR2.u2Val;

  /* BCKCRレジスタ設定 */
  tstBCKCR.u1Val = (U1)0x00;
  tstBCKCR.stBit.b1BCLKDIV = CU1_HwPph_Clk_CfgExtBusClkDiv_;
  stRegSys0.stBCKCR.u1Val = tstBCKCR.u1Val;

  /* SCKCR3レジスタ設定 */
  tstSCKCR3.u2Val = (U2)0x0000;
  tstSCKCR3.stBit.b3CKSEL = (U2)CEN_HwPph_Clk_CfgSrcSel_;
  stRegSys0.stSCKCR3.u2Val = tstSCKCR3.u2Val;

  /* 保護 */
  FnVD_HwPph_Clk_dibClkSetting();
}

