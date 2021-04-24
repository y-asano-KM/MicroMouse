/* ============================================================ */
/* ファイル名 : app_ctrl_accel.c                                */
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


/* ============================================================ */
/* 関数形式マクロ定義                                           */
/* ============================================================ */


/* ============================================================ */
/* 関数定義                                                     */
/* ============================================================ */
#if defined(OP_AppCtrl_Accel_LogicTypePhysical)
/* 実装なし */
#elif defined(OP_AppCtrl_Accel_LogicTypeTable)
/* ============================================================ */
/* 関数名 : FnU2_AppCtrl_Accel_ctrlPwmPeriod                    */
/*          PWM出力周期制御                                     */
/* 引数   : [us]経過時間                                        */
/* 戻り値 : [us]出力周期                                        */
/* 概要   : 出力経過時間に応じてPWM出力周期を制御する           */
/* 制約   : なし                                                */
/* ============================================================ */
U2 FnU2_AppCtrl_Accel_ctrlPwmPeriod(U4 tu4ElapsedTime, U4 tu4SizePwmPeriodMap, const ST_AppCtrl_Accel_PwmPeriodMap tstaPwmPeriodMap[])
{
  U4 tu4Idx;
  U2 tu2PwmPeriod;

  for (tu4Idx = (U4)0; tu4Idx < tu4SizePwmPeriodMap; tu4Idx++) {
    if (tu4ElapsedTime < tstaPwmPeriodMap[tu4Idx].u4ElapsedTime) {
      break;
    }
  }
  tu2PwmPeriod = tstaPwmPeriodMap[tu4Idx].u2PwmPeriod;

  return (tu2PwmPeriod);
}


#elif defined(OP_AppCtrl_Accel_LogicTypePulseCnt)
/* ============================================================ */
/* 関数名 : FnU2_AppCtrl_Accel_ctrlPwmFreq                      */
/*          PWM出力周期制御                                     */
/* 引数   : [回]入力パルス数                                    */
/*          [回]目標パルス数                                    */
/*          [us]目標出力周期                                    */
/*          [us]初期出力周期                                    */
/* 戻り値 : [us]出力周期(補正後)                                */
/* 概要   : パルス数に応じてPWM出力周期を制御する               */
/* 制約   : なし                                                */
/* ============================================================ */
U2 FnU2_AppCtrl_Accel_ctrlPwmPeriod(U2 tu2PulseCnt, U2 tu2TargetPulseCnt, U2 tu2TargetPwmPeriod, U2 tu2PwmPeriodInit)
{
  U2 tu2PwmPeriod;
  U2 tu2Pow;
  U2 tu2Val;

  if (   (tu2TargetPulseCnt <= (U2)1)
      || (tu2TargetPwmPeriod < CU2_AppCtrl_Accel_PwmPeriodMin)
      || (tu2TargetPwmPeriod > CU2_AppCtrl_Accel_PwmPeriodMax)
      || (tu2PwmPeriodInit < CU2_AppCtrl_Accel_PwmPeriodMin)
      || (tu2PwmPeriodInit > CU2_AppCtrl_Accel_PwmPeriodMax)) {

    /* パラメータ異常処理 */
    tu2PwmPeriod = tu2TargetPwmPeriod;
  }
  else {
    tu2Val = tu2PwmPeriodInit / tu2TargetPwmPeriod;

    for (tu2Pow = (U2)0; tu2Val != (U2)1; tu2Pow++) {
      tu2Val >>= (U2)1;
    }

    if (tu2PulseCnt <= (tu2TargetPulseCnt / (U2)2)) {
      if (tu2PulseCnt <= tu2Pow) {
        tu2PwmPeriod =  tu2PwmPeriodInit >> tu2PulseCnt;
      }
      else {
        tu2PwmPeriod =  tu2TargetPwmPeriod;
      }
    }
    else {
      if ((tu2TargetPulseCnt - tu2PulseCnt) <= tu2Pow) {
        tu2PwmPeriod =  tu2PwmPeriodInit << (tu2TargetPulseCnt - tu2PulseCnt);
      }
      else {
        tu2PwmPeriod =  tu2TargetPwmPeriod;
      }
    }
  }

  /* 上下限ガード */
  tu2PwmPeriod = (U2)McXX_grdMed(tu2PwmPeriod, CU2_AppCtrl_Accel_PwmPeriodMin, CU2_AppCtrl_Accel_PwmPeriodMax);

  return (tu2PwmPeriod);
}
#else
/* 実装なし */
#endif

