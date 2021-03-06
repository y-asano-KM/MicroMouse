/* ============================================================ */
/* ファイル名 : pf_bat_if.c                                     */
/* 機能       : バッテリーI/F処理                               */
/* ============================================================ */
#define SECTION_PF

/* ============================================================ */
/* インクルード                                                 */
/* ============================================================ */
/* プロジェクト共通 */
#include "prj_cmn_section.h"
#include "prj_cmn_option.h"
#include "prj_cmn_type.h"
#include "prj_cmn_macro.h"

/* カテゴリ共通 */
#include "pf_cmn_option.h"
#include "pf_cmn_option_pac.h"

/* 個別 */
#include "hw_drv_bat.h"
#include "pf_bled_ctrl_pac.h"

/* 本体 */
#include "pf_bat_if_pac.h"


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
/* バッテリー電圧値 */
static U2 u2PfBat_If_Val;


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
/* 関数名 : FnVD_PfBat_If_initHw                                */
/*          バッテリーI/F処理初期化(HW用)                       */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : ハードウェア層の初期化を行う                        */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_PfBat_If_initHw(VD)
{
  FnVD_HwDrv_Bat_init();
}


/* ============================================================ */
/* 関数名 : FnVD_PfBat_If_initPf                                */
/*          バッテリーI/F処理初期化(PF用)                       */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : バッテリーI/F処理の初期化を行う                     */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_PfBat_If_initPf(VD)
{
  u2PfBat_If_Val  = (U2)0;
}


/* ============================================================ */
/* 関数名 : FnVD_PfBat_If_renewVal                              */
/*          バッテリー電圧値更新                                */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : バッテリー電圧値を更新する                          */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_PfBat_If_renewVal(VD)
{
  FnVD_HwDrv_Bat_renewVal();
  u2PfBat_If_Val = FnU2_HwDrv_Bat_getVal();
}


/* ============================================================ */
/* 関数名 : FnU2_PfBat_If_getVal                                */
/*          バッテリー電圧値取得                                */
/* 引数   : なし                                                */
/* 戻り値 : バッテリー電圧値                                    */
/* 概要   : バッテリー電圧値を提供する                          */
/* 制約   : なし                                                */
/* ============================================================ */
U2 FnU2_PfBat_If_getVal(VD)
{
  return (u2PfBat_If_Val);
}


/* ============================================================ */
/* 関数名 : FnVD_PfBat_If_setReqLed0                            */
/*          バッテリー監視用LED0消灯/点灯要求設定               */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : バッテリー監視用LED0を点灯/消灯させる               */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_PfBat_If_setReqLed0(VD)
{
  U1 tu1ReqLed;

  /* 点灯/消灯要求出力値取得 */
  tu1ReqLed = FnU1_PfBled_Ctrl_getReqLed0();

  /* 出力要求設定 */
  FnVD_HwDrv_Bat_setReqLed0(tu1ReqLed);
}


/* ============================================================ */
/* 関数名 : FnVD_PfBat_If_setReqLed1                            */
/*          バッテリー監視用LED1消灯/点灯要求設定               */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : バッテリー監視用LED1を点灯/消灯させる               */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_PfBat_If_setReqLed1(VD)
{
  U1 tu1ReqLed;

  /* 点灯/消灯要求出力値取得 */
  tu1ReqLed = FnU1_PfBled_Ctrl_getReqLed1();

  /* 出力要求設定 */
  FnVD_HwDrv_Bat_setReqLed1(tu1ReqLed);
}


