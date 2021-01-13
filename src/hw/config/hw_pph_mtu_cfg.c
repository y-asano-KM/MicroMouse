/* ============================================================ */
/* ファイル名 : hw_pph_mtu_cfg.c                                */
/* 機能       : MTU処理用ユーザ設定                             */
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

/* 本体 */
#include "hw_pph_mtu_pac.h"
#include "hw_pph_mtu_cfg_pac.h"


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
/* --------------- */
/* MTU機能設定情報 */ 
/* --------------- */
/* MTU0 */
const ST_HwPph_Mtu_CfgMtu0 CST_HwPph_Mtu_CfgMtu0 = {
  /* タイマコントロールレジスタ(TCR)設定用 */
  CEN_HwPph_Mtu_CfgSelPriscalerMtu0,    /* enSelPriscaler */
  CEN_HwPph_Mtu_CfgSelClkEdgeMtu0,      /* enSelClkEdge */
  CEN_HwPph_Mtu_CfgCntrClrMtu0,         /* enCntrClr */

  /* タイマモードレジスタ(TMDR)設定用 */
  CEN_HwPph_Mtu_CfgSelMdMtu0,           /* enSelMd */
  CU1_HwPph_Mtu_CfgBufAMtu0,            /* u1BufA */
  CU1_HwPph_Mtu_CfgBufBMtu0,            /* u1BufB */
  CU1_HwPph_Mtu_CfgBufEMtu0,            /* u1BufE */

  /* タイマI/Oコントロールレジスタ(TIOR)設定用 */
  CEN_HwPph_Mtu_CfgIoACtrlMtu0,         /* enIoCtrlA */
  CEN_HwPph_Mtu_CfgIoBCtrlMtu0,         /* enIoCtrlB */
  CEN_HwPph_Mtu_CfgIoCCtrlMtu0,         /* enIoCtrlC */
  CEN_HwPph_Mtu_CfgIoDCtrlMtu0,         /* enIoCtrlD */

  /* タイマ割り込み許可レジスタ(TIER)設定用 */
  CU1_HwPph_Mtu_CfgEnbTGIEAMtu0,        /* u1EnbTGIEA */
  CU1_HwPph_Mtu_CfgEnbTGIEBMtu0,        /* u1EnbTGIEB */
  CU1_HwPph_Mtu_CfgEnbTGIECMtu0,        /* u1EnbTGIEC */
  CU1_HwPph_Mtu_CfgEnbTGIEDMtu0,        /* u1EnbTGIED */
  CU1_HwPph_Mtu_CfgEnbTCIEVMtu0,        /* u1EnbTCIEV */
                                        /* u1EnbTCIEU */ /* Memo:MTU0機能なし */
                                        /* u1EnbTTGE2 */ /* Memo:MTU0機能なし */
  CU1_HwPph_Mtu_CfgEnbTTGEMtu0,         /* u1EnbTTGE */
  CU1_HwPph_Mtu_CfgEnbTGIEEMtu0,        /* u1EnbTGIEE */
  CU1_HwPph_Mtu_CfgEnbTGIEFMtu0         /* u1EnbTGIEF */

  /* タイマアウトプットマスタ許可レジスタ(TOER)設定用 */
                                        /* u1EnbMTIOC3B */ /* Memo:MTU0機能なし */
                                        /* u1EnbMTIOC4A */ /* Memo:MTU0機能なし */
                                        /* u1EnbMTIOC4B */ /* Memo:MTU0機能なし */
                                        /* u1EnbMTIOC3D */ /* Memo:MTU0機能なし */
                                        /* u1EnbMTIOC4C */ /* Memo:MTU0機能なし */
                                        /* u1EnbMTIOC4D */ /* Memo:MTU0機能なし */
};

/* MTU1 */
/* ToDo:未実装 */

/* MTU2 */
/* ToDo:未実装 */

/* MTU3 */
const ST_HwPph_Mtu_CfgMtu3 CST_HwPph_Mtu_CfgMtu3 = {
  /* タイマコントロールレジスタ(TCR)設定用 */
  CEN_HwPph_Mtu_CfgSelPriscalerMtu3,    /* enSelPriscaler */
  CEN_HwPph_Mtu_CfgSelClkEdgeMtu3,      /* enSelClkEdge */
  CEN_HwPph_Mtu_CfgCntrClrMtu3,         /* enCntrClr */

  /* タイマモードレジスタ(TMDR)設定用 */
  CEN_HwPph_Mtu_CfgSelMdMtu3,           /* enSelMd */
  CU1_HwPph_Mtu_CfgBufAMtu3,            /* u1BufA */
  CU1_HwPph_Mtu_CfgBufBMtu3,            /* u1BufB */
                                        /* u1BufE */ /* Memo:MTU3機能なし */

  /* タイマI/Oコントロールレジスタ(TIOR)設定用 */
  CEN_HwPph_Mtu_CfgIoACtrlMtu3,         /* enIoCtrlA */
  CEN_HwPph_Mtu_CfgIoBCtrlMtu3,         /* enIoCtrlB */
  CEN_HwPph_Mtu_CfgIoCCtrlMtu3,         /* enIoCtrlC */
  CEN_HwPph_Mtu_CfgIoDCtrlMtu3,         /* enIoCtrlD */

  /* タイマ割り込み許可レジスタ(TIER)設定用 */
  CU1_HwPph_Mtu_CfgEnbTGIEAMtu3,        /* u1EnbTGIEA */
  CU1_HwPph_Mtu_CfgEnbTGIEBMtu3,        /* u1EnbTGIEB */
  CU1_HwPph_Mtu_CfgEnbTGIECMtu3,        /* u1EnbTGIEC */
  CU1_HwPph_Mtu_CfgEnbTGIEDMtu3,        /* u1EnbTGIED */
  CU1_HwPph_Mtu_CfgEnbTCIEVMtu3,        /* u1EnbTCIEV */
                                        /* u1EnbTCIEU */ /* Memo:MTU3機能なし */
                                        /* u1EnbTTGE2 */ /* Memo:MTU3機能なし */
  CU1_HwPph_Mtu_CfgEnbTTGEMtu3,         /* u1EnbTTGE */
                                        /* u1EnbTGIEE */ /* Memo:MTU3機能なし */
                                        /* u1EnbTGIEF */ /* Memo:MTU3機能なし */

  /* タイマアウトプットマスタ許可レジスタ(TOER)設定用 */
  CU1_HwPph_Mtu_CfgEnbMTIOC3BMtu3,      /* u1EnbMTIOC3B */
                                        /* u1EnbMTIOC4A */ /* Memo:MTU3機能なし */
                                        /* u1EnbMTIOC4B */ /* Memo:MTU3機能なし */
  CU1_HwPph_Mtu_CfgEnbMTIOC3DMtu3       /* u1EnbMTIOC3D */
                                        /* u1EnbMTIOC4C */ /* Memo:MTU3機能なし */
                                        /* u1EnbMTIOC4D */ /* Memo:MTU3機能なし */
};

/* MTU4 */
const ST_HwPph_Mtu_CfgMtu4 CST_HwPph_Mtu_CfgMtu4 = {
  /* タイマコントロールレジスタ(TCR)設定用 */
  CEN_HwPph_Mtu_CfgSelPriscalerMtu4,    /* enSelPriscaler */
  CEN_HwPph_Mtu_CfgSelClkEdgeMtu4,      /* enSelClkEdge */
  CEN_HwPph_Mtu_CfgCntrClrMtu4,         /* enCntrClr */

  /* タイマモードレジスタ(TMDR)設定用 */
  CEN_HwPph_Mtu_CfgSelMdMtu4,           /* enSelMd */
  CU1_HwPph_Mtu_CfgBufAMtu4,            /* u1BufA */
  CU1_HwPph_Mtu_CfgBufBMtu4,            /* u1BufB */
                                        /* u1BufE */ /* Memo:MTU3機能なし */

  /* タイマI/Oコントロールレジスタ(TIOR)設定用 */
  CEN_HwPph_Mtu_CfgIoACtrlMtu4,         /* enIoCtrlA */
  CEN_HwPph_Mtu_CfgIoBCtrlMtu4,         /* enIoCtrlB */
  CEN_HwPph_Mtu_CfgIoCCtrlMtu4,         /* enIoCtrlC */
  CEN_HwPph_Mtu_CfgIoDCtrlMtu4,         /* enIoCtrlD */

  /* タイマ割り込み許可レジスタ(TIER)設定用 */
  CU1_HwPph_Mtu_CfgEnbTGIEAMtu4,        /* u1EnbTGIEA */
  CU1_HwPph_Mtu_CfgEnbTGIEBMtu4,        /* u1EnbTGIEB */
  CU1_HwPph_Mtu_CfgEnbTGIECMtu4,        /* u1EnbTGIEC */
  CU1_HwPph_Mtu_CfgEnbTGIEDMtu4,        /* u1EnbTGIED */
  CU1_HwPph_Mtu_CfgEnbTCIEVMtu4,        /* u1EnbTCIEV */
                                        /* u1EnbTCIEU */ /* Memo:MTU4機能なし */
  CU1_HwPph_Mtu_CfgEnbTTGE2Mtu4,        /* u1EnbTTGE2 */
  CU1_HwPph_Mtu_CfgEnbTTGEMtu4,         /* u1EnbTTGE */
                                        /* u1EnbTGIEE */ /* Memo:MTU4機能なし */
                                        /* u1EnbTGIEF */ /* Memo:MTU4機能なし */

  /* タイマアウトプットマスタ許可レジスタ(TOER)設定用 */
                                        /* u1EnbMTIOC3B */ /* Memo:MTU4機能なし */
  CU1_HwPph_Mtu_CfgEnbMTIOC4AMtu4,      /* u1EnbMTIOC4A */
  CU1_HwPph_Mtu_CfgEnbMTIOC4BMtu4,      /* u1EnbMTIOC4B */
                                        /* u1EnbMTIOC3D */ /* Memo:MTU4機能なし */
  CU1_HwPph_Mtu_CfgEnbMTIOC4CMtu4,      /* u1EnbMTIOC4C */
  CU1_HwPph_Mtu_CfgEnbMTIOC4DMtu4       /* u1EnbMTIOC4D */
};

/* MTU5 */
/* ToDo:未実装 */


/* ============================================================ */
/* const変数定義(static)                                        */
/* ============================================================ */


/* ============================================================ */
/* 関数形式マクロ定義                                           */
/* ============================================================ */


/* ============================================================ */
/* 関数定義                                                     */
/* ============================================================ */


