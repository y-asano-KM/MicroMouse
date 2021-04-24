/* ============================================================ */
/* ファイル名 : app_ctrl_accel_cfg_local.h                      */
/* 機能       : 加減速制御                                      */
/* ============================================================ */
#define SECTION_APP

/* ============================================================ */
/* インクルード                                                 */
/* ============================================================ */
/* プロジェクト共通 */
#include "prj_cmn_section.h"
#include "prj_cmn_option.h"
#include "prj_cmn_type.h"
#include "prj_cmn_macro.h"

/* カテゴリ共通 */
#include "app_cmn_option.h"
#include "app_cmn_option_pac.h"

/* 個別 */

/* 本体 */
#include "app_ctrl_accel_local.h"


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


/* ============================================================ */
/* const変数定義(static)                                        */
/* ============================================================ */
#if defined(OP_AppCtrl_Accel_LogicTypePhysical)
/* None */
#elif defined(OP_AppCtrl_Accel_LogicTypeTable)
/* PWM出力周波数制御マップ */
/* Memo:u2Timeは必ず昇順とすること */
const ST_AppCtrl_Accel_PwmPeriodMap CSTA_AppCtrl_Accel_PwmPeriodMap1[CU4_AppCtrl_Accel_SizePwmPeriodMap] = {
/* u4ElapsedTime, u2PwmPeriod */
  {(U4)16000,    (U2)16000},
  {(U4)24000,    (U2)8000},
  {(U4)28000,    (U2)4000},
  {(U4)522000,   (U2)2000},
  {(U4)526000,   (U2)4000},
  {(U4)534000,   (U2)8000},
  {(U4)550000,   (U2)16000},
  {CU4_Max,      (U2)20000}
};

const ST_AppCtrl_Accel_PwmPeriodMap CSTA_AppCtrl_Accel_PwmPeriodMap2[CU4_AppCtrl_Accel_SizePwmPeriodMap] = {
/* u4ElapsedTime, u2PwmPeriod */
  {(U4)16000,    (U2)16000},
  {(U4)24000,    (U2)8000},
  {(U4)564000,   (U2)4000},
  {(U4)572000,   (U2)8000},
  {(U4)588000,   (U2)16000},
  {CU4_Max,      (U2)20000}
};
#elif defined(OP_AppCtrl_Accel_LogicTypePulseCnt)
const U2 CU2_AppCtrl_Accel_PwmTargetPulseCnt1 = (U2)248;
const U2 CU2_AppCtrl_Accel_PwmTargetPulseCnt2 = (U2)133;
const U2 CU2_AppCtrl_Accel_PwmTargetPeriod1   = (U2)2000;
const U2 CU2_AppCtrl_Accel_PwmTargetPeriod2   = (U2)4000;
const U2 CU2_AppCtrl_Accel_PwmPeriodInit1     = (U2)32000;
const U2 CU2_AppCtrl_Accel_PwmPeriodInit2     = (U2)64000;
const U2 CU2_AppCtrl_Accel_PwmMaxPeriod       = (U2)64000;
const U2 CU2_AppCtrl_Accel_PwmMinPeriod       = (U2)250;
#else
/* None */
#endif


/* ============================================================ */
/* 関数形式マクロ定義                                           */
/* ============================================================ */


/* ============================================================ */
/* 関数定義                                                     */
/* ============================================================ */

