#if !defined(INCLUDED_hw_drv_mtr_h)
#define INCLUDED_hw_drv_mtr_h
/* ============================================================ */
/* ファイル名 : hw_drv_mtr.h                                    */
/* 機能       : モータ制御処理                                  */
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

/* 個別 */

/* 本体 */


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */
/* [MHz]モーター用タイマカウント周波数 */
/* CFL_HwPph_Clk_CfgPphClkBFreq, CEN_HwPph_Mtu_CfgSelPriscalerMtu3に依存 */
/* CFL_HwPph_Clk_CfgPphClkBFreq, CEN_HwPph_Mtu_CfgSelPriscalerMtu4に依存 */
#define CFL_HwDrv_Mtr_PwmRTmrFreq     ((FL)3.0F)
#define CFL_HwDrv_Mtr_PwmLTmrFreq     ((FL)3.0F)

/* [us]モーター用タイマLSB */
#define CFL_HwDrv_Mtr_PwmRTmrLsb      ((FL)((FL)1.0F / CFL_HwDrv_Mtr_PwmRTmrFreq))
#define CFL_HwDrv_Mtr_PwmLTmrLsb      ((FL)((FL)1.0F / CFL_HwDrv_Mtr_PwmLTmrFreq))


/* ============================================================ */
/* 型定義                                                       */
/* ============================================================ */


/* ============================================================ */
/* 関数プロトタイプ宣言(extern)                                 */
/* ============================================================ */
extern VD FnVD_HwDrv_Mtr_clrPulseCntr(VD);
extern VD FnVD_HwDrv_Mtr_getPulseCntr(U2 * tpu2PulseCntrR, U2 * tpu2PulseCntrL);
extern VD FnVD_HwDrv_Mtr_init(VD);
extern VD FnVD_HwDrv_Mtr_setEnbPort(U1 tu1Req);
extern VD FnVD_HwDrv_Mtr_setRotDirPortBoth(U1 tu1ReqR, U1 tu1ReqL);
extern VD FnVD_HwDrv_Mtr_setRotDirPortRight(U1 tu1Req);
extern VD FnVD_HwDrv_Mtr_setRotDirPortLeft(U1 tu1Req);
extern VD FnVD_HwDrv_Mtr_setPulseWidthBoth(U2 tu2PeriodR, U2 tu2OnTimeR, U2 tu2PeriodL, U2 tu2OnTimeL);
extern VD FnVD_HwDrv_Mtr_setPulseWidthRight(U2 tu2Period, U2 tu2OnTime);
extern VD FnVD_HwDrv_Mtr_setPulseWidthLeft(U2 tu2Period, U2 tu2OnTime);
extern VD FnVD_HwDrv_Mtr_ctrlStpAndGoBoth(U1 tu1ReqR, U1 tu1ReqL);
extern VD FnVD_HwDrv_Mtr_ctrlStpAndGoRight(U1 tu1Req);
extern VD FnVD_HwDrv_Mtr_ctrlStpAndGoLeft(U1 tu1Req);
extern VD FnVD_HwDrv_Mtr_reset(VD);


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
