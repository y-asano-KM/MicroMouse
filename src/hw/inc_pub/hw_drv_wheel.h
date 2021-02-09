#if !defined(INCLUDED_hw_drv_wheel_h)
#define INCLUDED_hw_drv_wheel_h
/* ============================================================ */
/* ファイル名 : hw_drv_wheel.h                                  */
/* 機能       :                                                 */
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


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */


/* ============================================================ */
/* 型定義                                                       */
/* ============================================================ */


/* ============================================================ */
/* 関数プロトタイプ宣言(extern)                                 */
/* ============================================================ */
void vd_g_InitializeWheel(void);
void vd_g_set_WheelMtrModeR(S1 s1_a_set);
void vd_g_set_WheelMtrModeL(S1 s1_a_set);
void vd_g_set_WheelMtrPower(U1 u1_a_set);
void vd_g_set_WheelCycleTimeR(U2 u2_a_set);
void vd_g_set_WheelCycleTimeL(U2 u2_a_set);

/* ============================================================ */
/* 変数宣言(extern)                                             */
/* ============================================================ */


/* ============================================================ */
/* const変数宣言(extern)                                        */
/* ============================================================ */


/* ============================================================ */
/* 関数形式マクロ定義                                           */
/* ============================================================ */
/* ============================================================ */
/* 関数名 : McU1_XxYyy_getSignal                                */
/*          関数和名をここへ記述                                */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 関数箱型コメントの形式を示す                        */
/* 制約   : なし                                                */
/* ============================================================ */


#endif