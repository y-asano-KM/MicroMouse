#if !defined(INCLUDED_app_ctrl_accel_local_h)
#define INCLUDED_app_ctrl_accel_local_h
/* ============================================================ */
/* ファイル名 : app_ctrl_accel_local.h                          */
/* 機能       : 加減速制御                                      */
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
#include "app_cmn_option_pac.h"

/* 個別 */

/* 本体 */


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */
#if defined(OP_AppCtrl_Accel_LogicTypeTable)
  #define CU4_AppCtrl_Accel_SizePwmFreqMap    ((U4)10)
#endif


/* ============================================================ */
/* 型定義                                                       */
/* ============================================================ */
#if defined(OP_AppCtrl_Accel_LogicTypeTable)
/* PWM出力周波数制御 */
typedef struct {
  U4 u4ElapsedTime;   /* [us]経過時間 */
  U2 u2PwmFreq;       /* [us]PWM周波数*/
} ST_AppCtrl_Accel_PwmFreqMap;
#endif


/* ============================================================ */
/* 関数プロトタイプ宣言(extern)                                 */
/* ============================================================ */
#if defined(OP_AppCtrl_Accel_LogicTypeTable)
extern U2 FnU2_AppCtrl_Accel_ctrlPwmFreq(U4 tu4ElapsedTime, U4 tu4SizePwmFreqMap, const ST_AppCtrl_Accel_PwmFreqMap tstaPwmFreqMap[]);
#endif


/* ============================================================ */
/* 変数宣言(extern)                                             */
/* ============================================================ */


/* ============================================================ */
/* const変数宣言(extern)                                        */
/* ============================================================ */
#if defined(OP_AppCtrl_Accel_LogicTypeTable)
extern const ST_AppCtrl_Accel_PwmFreqMap CSTA_AppCtrl_Accel_PwmFreqMap1[CU4_AppCtrl_Accel_SizePwmFreqMap];
extern const ST_AppCtrl_Accel_PwmFreqMap CSTA_AppCtrl_Accel_PwmFreqMap2[CU4_AppCtrl_Accel_SizePwmFreqMap];
#endif


/* ============================================================ */
/* 関数形式マクロ定義                                           */
/* ============================================================ */


#endif
