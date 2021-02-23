#if !defined(INCLUDED_app_controll_h)
#define INCLUDED_app_controll_h
/* ============================================================ */
/* ファイル名 : app_controll.h                                  */
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
#include "app_cmn_option.h"

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
U1 u1_g_get_MtrModeR(void);                       /* 右モーター モード */
U1 u1_g_get_MtrModeL(void);                       /* 左モーター モード */
U1 u1_g_get_MtrPowerMode(void);                   /* モータ励磁 */

U2 u2_g_get_CycleTimeR(void);                     /* 右モータ周期とパルス幅(1ms割り込み) */
U2 u2_g_get_CycleTimeL(void);                     /* 左モータ周期とパルス幅(1ms割り込み) */

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
