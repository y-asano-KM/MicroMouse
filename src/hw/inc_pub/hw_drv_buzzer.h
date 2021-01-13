#if !defined(INCLUDED_hw_drv_buzzer_h)
#define INCLUDED_hw_drv_buzzer_h
/* ============================================================ */
/* ファイル名 : hw_drv_buzzer.h                                 */
/* 機能       : ブザー制御処理                                  */
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
/* [MHz]ブザー用タイマカウント周波数 */
/* CFL_HwPph_Clk_CfgPphClkBFreq, CEN_HwPph_Mtu_CfgSelPriscalerMtu0に依存 */
#define CFL_HwDrv_Bz_PwmTmrFreq      ((FL)12.0F)

/* [us]ブザー用タイマLSB */
#define CFL_HwDrv_Bz_PwmTmrLsb       ((FL)((FL)1.0F / CFL_HwDrv_Bz_PwmTmrFreq))

/* [Hz]ブザー駆動周期凡例 */
#define CU4_HwDrv_Bz_Scale_C         ((U4)1047)
#define CU4_HwDrv_Bz_Scale_CSharp    ((U4)1109)
#define CU4_HwDrv_Bz_Scale_D         ((U4)1175)
#define CU4_HwDrv_Bz_Scale_DSharp    ((U4)1245)
#define CU4_HwDrv_Bz_Scale_E         ((U4)1319)
#define CU4_HwDrv_Bz_Scale_F         ((U4)1397)
#define CU4_HwDrv_Bz_Scale_FSharp    ((U4)1480)
#define CU4_HwDrv_Bz_Scale_G         ((U4)1568)
#define CU4_HwDrv_Bz_Scale_GSharp    ((U4)1661)
#define CU4_HwDrv_Bz_Scale_A         ((U4)1760)
#define CU4_HwDrv_Bz_Scale_ASharp    ((U4)1865)
#define CU4_HwDrv_Bz_Scale_B         ((U4)1976)


/* ============================================================ */
/* 型定義                                                       */
/* ============================================================ */


/* ============================================================ */
/* 関数プロトタイプ宣言(extern)                                 */
/* ============================================================ */
extern VD FnVD_HwDrv_Bz_init(VD);
extern VD FnVD_HwDrv_Bz_setFreq(U4 tu4Freq);
extern VD FnVD_HwDrv_Bz_ctrlStpAndGo(U1 tu1Req);


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
