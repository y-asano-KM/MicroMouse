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
#if defined(OP_AppCtrl_Accel_LogicTypePhysical)
  /* None */
#elif defined(OP_AppCtrl_Accel_LogicTypeTable)
  #define CU4_AppCtrl_Accel_SizePwmPeriodMap    ((U4)10)
#elif defined(OP_AppCtrl_Accel_LogicTypePulseCnt)
  /* None */
#else
  /* None */
#endif


/* ============================================================ */
/* 型定義                                                       */
/* ============================================================ */
#if defined(OP_AppCtrl_Accel_LogicTypePhysical)
/* None */
#elif defined(OP_AppCtrl_Accel_LogicTypeTable)
/* PWM出力周波数制御 */
typedef struct {
  U4 u4ElapsedTime;   /* [us]経過時間 */
  U2 u2PwmPeriod;     /* [us]PWM周期*/
} ST_AppCtrl_Accel_PwmPeriodMap;
#elif defined(OP_AppCtrl_Accel_LogicTypePulseCnt)
/* None */
#else
/* None */
#endif


/* ============================================================ */
/* 関数プロトタイプ宣言(extern)                                 */
/* ============================================================ */
#if defined(OP_AppCtrl_Accel_LogicTypePhysical)
/* None */
#elif defined(OP_AppCtrl_Accel_LogicTypeTable)
extern U2 FnU2_AppCtrl_Accel_ctrlPwmPeriod(U4 tu4ElapsedTime, U4 tu4SizePwmPeriodMap, const ST_AppCtrl_Accel_PwmPeriodMap tstaPwmPeriodMap[]);
#elif defined(OP_AppCtrl_Accel_LogicTypePulseCnt)
extern U2 FnU2_AppCtrl_Accel_ctrlPwmPeriod(U2 tu2PulseCnt, U2 tu2TargetPulseCnt, U2 tu2TargetPwmPeriod, U2 tu2PwmPeriodInit);
#else
/* None */
#endif


/* ============================================================ */
/* 変数宣言(extern)                                             */
/* ============================================================ */


/* ============================================================ */
/* const変数宣言(extern)                                        */
/* ============================================================ */
#if defined(OP_AppCtrl_Accel_LogicTypePhysical)
/* None */
#elif defined(OP_AppCtrl_Accel_LogicTypeTable)
extern const ST_AppCtrl_Accel_PwmPeriodMap CSTA_AppCtrl_Accel_PwmPeriodMap1[CU4_AppCtrl_Accel_SizePwmPeriodMap];
extern const ST_AppCtrl_Accel_PwmPeriodMap CSTA_AppCtrl_Accel_PwmPeriodMap2[CU4_AppCtrl_Accel_SizePwmPeriodMap];
#elif defined(OP_AppCtrl_Accel_LogicTypePulseCnt)
extern const U2 CU2_AppCtrl_Accel_PwmTargetPulseCnt1;
extern const U2 CU2_AppCtrl_Accel_PwmTargetPulseCnt2;
extern const U2 CU2_AppCtrl_Accel_PwmTargetPeriod1;
extern const U2 CU2_AppCtrl_Accel_PwmTargetPeriod2;
extern const U2 CU2_AppCtrl_Accel_PwmPeriodInit1;
extern const U2 CU2_AppCtrl_Accel_PwmPeriodInit2;
extern const U2 CU2_AppCtrl_Accel_PwmMaxPeriod;
extern const U2 CU2_AppCtrl_Accel_PwmMinPeriod;
#else
/* None */
#endif


/* ============================================================ */
/* 関数形式マクロ定義                                           */
/* ============================================================ */


#endif
