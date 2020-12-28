/* ============================================================ */
/* ファイル名 : hw_drv_switch.c                                 */
/* 機能       : スイッチ制御処理                                */
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
#include "hw_pph_port_pac.h"
#include "hw_pph_port_cfg_pac.h"

/* 本体 */
#include "hw_drv_switch.h"
#include "hw_drv_switch_pac.h"


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */
/* コンフィグレーション */
#define CST_HwDrv_Swt_Port_CfgSwtR CST_HwPph_Port_CfgPC2
#define CST_HwDrv_Swt_Port_CfgSwtC CST_HwPph_Port_CfgPC3
#define CST_HwDrv_Swt_Port_CfgSwtL CST_HwPph_Port_CfgP31

/* ポート識番号 */
#define CEN_HwDrv_Swt_Port_IdSwtR  CEN_HwPph_Port_Id_PC2
#define CEN_HwDrv_Swt_Port_IdSwtC  CEN_HwPph_Port_Id_PC3
#define CEN_HwDrv_Swt_Port_IdSwtL  CEN_HwPph_Port_Id_P31


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
/* ============================================================ */
/* 関数名 : FnVD_HwDrv_Swt_init                                 */
/*          スイッチ入力初期化                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 初期化する                                          */
/* 制約   : 割り込み禁止中に実行すること                        */
/* ============================================================ */
VD FnVD_HwDrv_Swt_init(VD)
{
  /* SW_R:タクトスイッチR*/
  FnVD_HwPph_Port_cfg(&CST_HwDrv_Swt_Port_CfgSwtR);

  /* SW_C:タクトスイッチC */
  FnVD_HwPph_Port_cfg(&CST_HwDrv_Swt_Port_CfgSwtC);

  /* SW_L:タクトスイッチL */
  FnVD_HwPph_Port_cfg(&CST_HwDrv_Swt_Port_CfgSwtL);
}


/* ============================================================ */
/* 関数名 : FnU1_HwDrv_Swt_getTactSwtRightSignal                */
/*          タクトスイッチR入力レベル取得                       */
/* 引数   : なし                                                */
/* 戻り値 : タクトスイッチR入力レベル (0:OFF, 1:ON)             */
/* 概要   : タクトスイッチR入力レベルを提供する                 */
/*          (モーメンタリースイッチ)                            */
/* 制約   : なし                                                */
/* ============================================================ */
U1 FnU1_HwDrv_Swt_getTactSwtRightSignal(VD)
{
  U1 tu1Ret;

  tu1Ret = FnU1_HwPph_Port_getInLv(CEN_HwDrv_Swt_Port_IdSwtR);

  return (tu1Ret);
}


/* ============================================================ */
/* 関数名 : FnU1_HwDrv_Swt_getTactSwtCenterSignal               */
/*          タクトスイッチC入力レベル取得                       */
/* 引数   : なし                                                */
/* 戻り値 : タクトスイッチC入力レベル (0:OFF, 1:ON)             */
/* 概要   : タクトスイッチC入力レベルを提供する                 */
/*          (モーメンタリースイッチ)                            */
/* 制約   : なし                                                */
/* ============================================================ */
U1 FnU1_HwDrv_Swt_getTactSwtCenterSignal(VD)
{
  U1 tu1Ret;

  tu1Ret = FnU1_HwPph_Port_getInLv(CEN_HwDrv_Swt_Port_IdSwtC);

  return (tu1Ret);
}


/* ============================================================ */
/* 関数名 : FnU1_HwDrv_Swt_getTactSwtLeftSignal                 */
/*          タクトスイッチL入力レベル取得                       */
/* 引数   : なし                                                */
/* 戻り値 : タクトスイッチL入力レベル (0:OFF, 1:ON)             */
/* 概要   : タクトスイッチL入力レベルを提供する                 */
/*          (モーメンタリースイッチ)                            */
/* 制約   : なし                                                */
/* ============================================================ */
U1 FnU1_HwDrv_Swt_getTactSwtLeftSignal(VD)
{
  U1 tu1Ret;

  tu1Ret = FnU1_HwPph_Port_getInLv(CEN_HwDrv_Swt_Port_IdSwtL);

  return (tu1Ret);
}


