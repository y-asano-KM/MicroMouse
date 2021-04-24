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
const ST_AppCtrl_Accel_PwmPeriodMap CSTA_AppCtrl_Accel_PwmPeriodMapStraight[CU4_AppCtrl_Accel_SizePwmPeriodMap] = {
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

const ST_AppCtrl_Accel_PwmPeriodMap CSTA_AppCtrl_Accel_PwmPeriodMapRotation[CU4_AppCtrl_Accel_SizePwmPeriodMap] = {
/* u4ElapsedTime, u2PwmPeriod */
  {(U4)16000,    (U2)16000},
  {(U4)24000,    (U2)8000},
  {(U4)564000,   (U2)4000},
  {(U4)572000,   (U2)8000},
  {(U4)588000,   (U2)16000},
  {CU4_Max,      (U2)20000}
};
#elif defined(OP_AppCtrl_Accel_LogicTypePulseCnt)
/* 直進時目標パルス数(90mm) */
const U2 CU2_AppCtrl_Accel_PwmTargetPulseCntStraight = (U2)253; /* 238.7324146=(2*400)dist/48pi/2 */

/* 旋回時目標パルス数(90deg) */
const U2 CU2_AppCtrl_Accel_PwmTargetPulseCntRotation = (U2)139; /* 135.4166667=(2*400)((65/2)*(deg/180))/48pi */

/* [us]直進時出力目標周期 */
const U2 CU2_AppCtrl_Accel_PwmTargetPeriodStraight = (U2)2000;

/* [us]旋回時出力目標周期 */
const U2 CU2_AppCtrl_Accel_PwmTargetPeriodRotation = (U2)4000;

/* [us]直進時出力初期周期 */
const U2 CU2_AppCtrl_Accel_PwmPeriodInitStraight = (U2)16000;

/* [us]旋回時出力初期周期 */
const U2 CU2_AppCtrl_Accel_PwmPeriodInitRotation = (U2)16000;

/* [us]出力周期上限値 */
const U2 CU2_AppCtrl_Accel_PwmPeriodMax = (U2)20000;

/* [us]出力周期下限値 */
const U2 CU2_AppCtrl_Accel_PwmPeriodMin = (U2)1000;
#else
/* None */
#endif


/* ============================================================ */
/* 関数形式マクロ定義                                           */
/* ============================================================ */


/* ============================================================ */
/* 関数定義                                                     */
/* ============================================================ */

