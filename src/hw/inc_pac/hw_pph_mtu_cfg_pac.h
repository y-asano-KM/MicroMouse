#if !defined(INCLUDED_hw_pph_mtu_cfg_pac_h)
#define INCLUDED_hw_pph_mtu_cfg_pac_h
/* ============================================================ */
/* ファイル名 : hw_pph_mtu_cfg_pac.h                            */
/* 機能       : MTU処理用ユーザ設定                             */
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
#include "hw_pph_mtu_pac.h"


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */
/* --------------- */
/* MTU機能設定情報 */ 
/* --------------- */
/* MTU0 */ /* ブザー */
/* タイマコントロールレジスタ(TCR)設定用 */
#define CEN_HwPph_Mtu_CfgSelPriscalerMtu0   CEN_HwPph_Mtu_SelPriscalerMtu0_PClkDiv0004
#define CEN_HwPph_Mtu_CfgSelClkEdgeMtu0     CEN_HwPph_Mtu_SelClkEdge_Rising
#define CEN_HwPph_Mtu_CfgCntrClrMtu0        CEN_HwPph_Mtu_CntrClrMtu0_TGRB

/* タイマモードレジスタ(TMDR)設定用 */
#define CEN_HwPph_Mtu_CfgSelMdMtu0          CEN_HwPph_Mtu_SelMdMtu0_Pwm1
#define CU1_HwPph_Mtu_CfgBufAMtu0           ((U1)C_OFF)
#define CU1_HwPph_Mtu_CfgBufBMtu0           ((U1)C_OFF)
#define CU1_HwPph_Mtu_CfgBufEMtu0           ((U1)C_OFF)

/* タイマI/Oコントロールレジスタ(TIOR)設定用 */
#define CEN_HwPph_Mtu_CfgIoACtrlMtu0        CEN_HwPph_Mtu_IoCtrlMtu0_InitHiCmprLo
#define CEN_HwPph_Mtu_CfgIoBCtrlMtu0        CEN_HwPph_Mtu_IoCtrlMtu0_InitLoCmprHi
#define CEN_HwPph_Mtu_CfgIoCCtrlMtu0        CEN_HwPph_Mtu_IoCtrlMtu0_DibOut
#define CEN_HwPph_Mtu_CfgIoDCtrlMtu0        CEN_HwPph_Mtu_IoCtrlMtu0_DibOut

/* タイマ割り込み許可レジスタ(TIER)設定用 */
#define CU1_HwPph_Mtu_CfgEnbTGIEAMtu0       ((U1)C_OFF)
#define CU1_HwPph_Mtu_CfgEnbTGIEBMtu0       ((U1)C_OFF)
#define CU1_HwPph_Mtu_CfgEnbTGIECMtu0       ((U1)C_OFF)
#define CU1_HwPph_Mtu_CfgEnbTGIEDMtu0       ((U1)C_OFF)
#define CU1_HwPph_Mtu_CfgEnbTCIEVMtu0       ((U1)C_OFF)
#define CU1_HwPph_Mtu_CfgEnbTCIEUMtu0       /* MTU0機能なし */
#define CU1_HwPph_Mtu_CfgEnbTTGE2Mtu0       /* MTU0機能なし */
#define CU1_HwPph_Mtu_CfgEnbTTGEMtu0        ((U1)C_OFF)
#define CU1_HwPph_Mtu_CfgEnbTGIEEMtu0       ((U1)C_OFF)
#define CU1_HwPph_Mtu_CfgEnbTGIEFMtu0       ((U1)C_OFF)

/* タイマアウトプットマスタ許可レジスタ(TOER)設定用 */
#define CU1_HwPph_Mtu_CfgEnbMTIOC3BMtu0     /* MTU0機能なし */
#define CU1_HwPph_Mtu_CfgEnbMTIOC4AMtu0     /* MTU0機能なし */
#define CU1_HwPph_Mtu_CfgEnbMTIOC4BMtu0     /* MTU0機能なし */
#define CU1_HwPph_Mtu_CfgEnbMTIOC3DMtu0     /* MTU0機能なし */
#define CU1_HwPph_Mtu_CfgEnbMTIOC4CMtu0     /* MTU0機能なし */
#define CU1_HwPph_Mtu_CfgEnbMTIOC4DMtu0     /* MTU0機能なし */

/* MTU1 */
/* ToDo:未実装 */

/* MTU2 */
/* ToDo:未実装 */

/* MTU3 */ /* 右モータ */
/* タイマコントロールレジスタ(TCR)設定用 */
#define CEN_HwPph_Mtu_CfgSelPriscalerMtu3   CEN_HwPph_Mtu_SelPriscalerMtu3_PClkDiv0016
#define CEN_HwPph_Mtu_CfgSelClkEdgeMtu3     CEN_HwPph_Mtu_SelClkEdge_Rising
#define CEN_HwPph_Mtu_CfgCntrClrMtu3        CEN_HwPph_Mtu_CntrClrMtu3_TGRA

/* タイマモードレジスタ(TMDR)設定用 */
#define CEN_HwPph_Mtu_CfgSelMdMtu3          CEN_HwPph_Mtu_SelMdMtu3_Pwm1
#define CU1_HwPph_Mtu_CfgBufAMtu3           ((U1)C_ON)
#define CU1_HwPph_Mtu_CfgBufBMtu3           ((U1)C_OFF)
#define CU1_HwPph_Mtu_CfgBufEMtu3           /* MTU3機能なし */

/* タイマI/Oコントロールレジスタ(TIOR)設定用 */
#define CEN_HwPph_Mtu_CfgIoACtrlMtu3        CEN_HwPph_Mtu_IoCtrlMtu3_InitLoCmprLo
#define CEN_HwPph_Mtu_CfgIoBCtrlMtu3        CEN_HwPph_Mtu_IoCtrlMtu3_InitLoCmprHi
#define CEN_HwPph_Mtu_CfgIoCCtrlMtu3        CEN_HwPph_Mtu_IoCtrlMtu3_DibOut
#define CEN_HwPph_Mtu_CfgIoDCtrlMtu3        CEN_HwPph_Mtu_IoCtrlMtu3_DibOut

/* タイマ割り込み許可レジスタ(TIER)設定用 */
#define CU1_HwPph_Mtu_CfgEnbTGIEAMtu3       ((U1)C_OFF)
#define CU1_HwPph_Mtu_CfgEnbTGIEBMtu3       ((U1)C_ON)
#define CU1_HwPph_Mtu_CfgEnbTGIECMtu3       ((U1)C_OFF)
#define CU1_HwPph_Mtu_CfgEnbTGIEDMtu3       ((U1)C_OFF)
#define CU1_HwPph_Mtu_CfgEnbTCIEVMtu3       ((U1)C_OFF)
#define CU1_HwPph_Mtu_CfgEnbTCIEUMtu3       /* MTU3機能なし */
#define CU1_HwPph_Mtu_CfgEnbTTGE2Mtu3       /* MTU3機能なし */
#define CU1_HwPph_Mtu_CfgEnbTTGEMtu3        ((U1)C_OFF)
#define CU1_HwPph_Mtu_CfgEnbTGIEEMtu3       /* MTU3機能なし */
#define CU1_HwPph_Mtu_CfgEnbTGIEFMtu3       /* MTU3機能なし */

/* タイマアウトプットマスタ許可レジスタ(TOER)設定用 */
#define CU1_HwPph_Mtu_CfgEnbMTIOC3BMtu3     ((U1)C_OFF)
#define CU1_HwPph_Mtu_CfgEnbMTIOC4AMtu3     /* MTU0機能なし */
#define CU1_HwPph_Mtu_CfgEnbMTIOC4BMtu3     /* MTU0機能なし */
#define CU1_HwPph_Mtu_CfgEnbMTIOC3DMtu3     ((U1)C_OFF)
#define CU1_HwPph_Mtu_CfgEnbMTIOC4CMtu3     /* MTU0機能なし */
#define CU1_HwPph_Mtu_CfgEnbMTIOC4DMtu3     /* MTU0機能なし */

/* MTU4 */ /* 左モータ */
/* タイマコントロールレジスタ(TCR)設定用 */
#define CEN_HwPph_Mtu_CfgSelPriscalerMtu4   CEN_HwPph_Mtu_SelPriscalerMtu4_PClkDiv0016
#define CEN_HwPph_Mtu_CfgSelClkEdgeMtu4     CEN_HwPph_Mtu_SelClkEdge_Rising
#define CEN_HwPph_Mtu_CfgCntrClrMtu4        CEN_HwPph_Mtu_CntrClrMtu4_TGRA

/* タイマモードレジスタ(TMDR)設定用 */
#define CEN_HwPph_Mtu_CfgSelMdMtu4          CEN_HwPph_Mtu_SelMdMtu4_Pwm1
#define CU1_HwPph_Mtu_CfgBufAMtu4           ((U1)C_ON)
#define CU1_HwPph_Mtu_CfgBufBMtu4           ((U1)C_OFF)
#define CU1_HwPph_Mtu_CfgBufEMtu4           /* MTU4機能なし */

/* タイマI/Oコントロールレジスタ(TIOR)設定用 */
#define CEN_HwPph_Mtu_CfgIoACtrlMtu4        CEN_HwPph_Mtu_IoCtrlMtu4_InitLoCmprLo
#define CEN_HwPph_Mtu_CfgIoBCtrlMtu4        CEN_HwPph_Mtu_IoCtrlMtu4_InitLoCmprHi
#define CEN_HwPph_Mtu_CfgIoCCtrlMtu4        CEN_HwPph_Mtu_IoCtrlMtu4_DibOut
#define CEN_HwPph_Mtu_CfgIoDCtrlMtu4        CEN_HwPph_Mtu_IoCtrlMtu4_DibOut

/* タイマ割り込み許可レジスタ(TIER)設定用 */
#define CU1_HwPph_Mtu_CfgEnbTGIEAMtu4       ((U1)C_OFF)
#define CU1_HwPph_Mtu_CfgEnbTGIEBMtu4       ((U1)C_ON)
#define CU1_HwPph_Mtu_CfgEnbTGIECMtu4       ((U1)C_OFF)
#define CU1_HwPph_Mtu_CfgEnbTGIEDMtu4       ((U1)C_OFF)
#define CU1_HwPph_Mtu_CfgEnbTCIEVMtu4       ((U1)C_OFF)
#define CU1_HwPph_Mtu_CfgEnbTCIEUMtu4       /* MTU4機能なし */
#define CU1_HwPph_Mtu_CfgEnbTTGE2Mtu4       ((U1)C_OFF)
#define CU1_HwPph_Mtu_CfgEnbTTGEMtu4        ((U1)C_OFF)
#define CU1_HwPph_Mtu_CfgEnbTGIEEMtu4       /* MTU4機能なし */
#define CU1_HwPph_Mtu_CfgEnbTGIEFMtu4       /* MTU4機能なし */

/* タイマアウトプットマスタ許可レジスタ(TOER)設定用 */
#define CU1_HwPph_Mtu_CfgEnbMTIOC3BMtu4     /* MTU4機能なし */
#define CU1_HwPph_Mtu_CfgEnbMTIOC4AMtu4     ((U1)C_ON)
#define CU1_HwPph_Mtu_CfgEnbMTIOC4BMtu4     ((U1)C_OFF)
#define CU1_HwPph_Mtu_CfgEnbMTIOC3DMtu4     /* MTU4機能なし */
#define CU1_HwPph_Mtu_CfgEnbMTIOC4CMtu4     ((U1)C_OFF)
#define CU1_HwPph_Mtu_CfgEnbMTIOC4DMtu4     ((U1)C_OFF)

/* MTU5 */
/* ToDo:未実装 */


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
/* --------------- */
/* MTU機能設定情報 */ 
/* --------------- */
extern const ST_HwPph_Mtu_CfgMtu0 CST_HwPph_Mtu_CfgMtu0;
/* ToDo:MTU1未実装 */
/* ToDo:MTU2未実装 */
extern const ST_HwPph_Mtu_CfgMtu3 CST_HwPph_Mtu_CfgMtu3;
extern const ST_HwPph_Mtu_CfgMtu4 CST_HwPph_Mtu_CfgMtu4;
/* ToDo:MTU5未実装 */


/* ============================================================ */
/* 関数形式マクロ定義                                           */
/* ============================================================ */


#endif
