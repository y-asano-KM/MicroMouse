#if !defined(INCLUDED_hw_pph_intctrl_cfg_pac_h)
#define INCLUDED_hw_pph_intctrl_cfg_pac_h
/* ============================================================ */
/* ファイル名 : hw_pph_intctrl_cfg_pac.h                        */
/* 機能       : 割り込み制御処理ユーザ設定                      */
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
#include "hw_pph_intctrl_pac.h"


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */
/* 割り込み優先度設定 */
/* 右モータパルス数取得 */
#define CEN_HwPph_IntCtrl_CfgPriority_TPU9_TGI9B_MTU3_TGIB3      CEN_HwPph_IntCtrl_Priority_14

/* 左モータパルス数取得 */
#define CEN_HwPph_IntCtrl_CfgPriority_TPU10_TGI10B_MTU4_TGIB4    CEN_HwPph_IntCtrl_Priority_14

/* 1ms割り込み */
#define CEN_HwPph_IntCtrl_CfgPriority_CMT1_CMI1                  CEN_HwPph_IntCtrl_Priority_10

/* 時刻取得タイマー */
#define CEN_HwPph_IntCtrl_CfgPriority_CMT0_CMI0                  CEN_HwPph_IntCtrl_Priority_DibInt


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


/* ============================================================ */
/* 関数形式マクロ定義                                           */
/* ============================================================ */


#endif
