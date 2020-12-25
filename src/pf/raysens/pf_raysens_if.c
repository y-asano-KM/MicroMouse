/* ============================================================ */
/* ファイル名 : pf_raysens_if.c                                 */
/* 機能       : 光学センサI/F処理                               */
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
#include "hw_drv_raysens.h"

/* 本体 */
#include "pf_raysens_if_pac.h"


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
/* ToDo:センサ値取得処理を仮実装 */
static U2 u2PfRaySens_If_R;
static U2 u2PfRaySens_If_FR;
static U2 u2PfRaySens_If_FL;
static U2 u2PfRaySens_If_L;


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
/* 関数名 : FnVD_PfRaySens_If_initHw                            */
/*          光学センサI/F処理初期化(HW用)                       */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : ハードウェア層の初期化を行う                        */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_PfRaySens_If_initHw(VD)
{
  FnVD_HwDrv_RaySens_init();
}


/* ============================================================ */
/* 関数名 : FnVD_PfRaySens_If_initPf                            */
/*          光学センサI/F処理初期化(PF用)                       */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 光学センサI/F処理の初期化を行う                     */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_PfRaySens_If_initPf(VD)
{
  u2PfRaySens_If_R  = (U2)0;
  u2PfRaySens_If_FR = (U2)0;
  u2PfRaySens_If_FL = (U2)0;
  u2PfRaySens_If_L  = (U2)0;
}


/* ============================================================ */
/* 関数名 : FnVD_PfRaySens_If_renewVal                          */
/*          センサ値更新                                        */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : センサ値を更新する                                  */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_PfRaySens_If_renewVal(VD)
{
  /* ToDo:センサ値取得処理を仮実装 */
  /* センサ右側 */
  FnVD_HwDrv_RaySens_renewVal(CEN_HwDrv_RaySens_Id_R);
  u2PfRaySens_If_R = FnU2_HwDrv_RaySens_getVal(CEN_HwDrv_RaySens_Id_R);

  /* センサ前方左側 */
  FnVD_HwDrv_RaySens_renewVal(CEN_HwDrv_RaySens_Id_FL);
  u2PfRaySens_If_FR = FnU2_HwDrv_RaySens_getVal(CEN_HwDrv_RaySens_Id_FL);

  /* センサ前方右側 */
  FnVD_HwDrv_RaySens_renewVal(CEN_HwDrv_RaySens_Id_FR);
  u2PfRaySens_If_FL = FnU2_HwDrv_RaySens_getVal(CEN_HwDrv_RaySens_Id_FR);

  /* センサ左側 */
  FnVD_HwDrv_RaySens_renewVal(CEN_HwDrv_RaySens_Id_L);
  u2PfRaySens_If_L  = FnU2_HwDrv_RaySens_getVal(CEN_HwDrv_RaySens_Id_L);
}


/* ============================================================ */
/* 関数名 : FnU2_PfRaySens_If_getValRight                       */
/*          センサ値取得(右側)                                  */
/* 引数   : なし                                                */
/* 戻り値 : センサ値                                            */
/* 概要   : センサ値を提供する                                  */
/* 制約   : なし                                                */
/* ============================================================ */
U2 FnU2_PfRaySens_If_getValRight(VD)
{
  return (u2PfRaySens_If_R);
}


/* ============================================================ */
/* 関数名 : FnU2_PfRaySens_If_getValFrontRight                  */
/*          センサ値取得(前方右側)                              */
/* 引数   : なし                                                */
/* 戻り値 : センサ値                                            */
/* 概要   : センサ値を提供する                                  */
/* 制約   : なし                                                */
/* ============================================================ */
U2 FnU2_PfRaySens_If_getValFrontRight(VD)
{
  return (u2PfRaySens_If_FR);
}


/* ============================================================ */
/* 関数名 : FnU2_PfRaySens_If_getValFrontLeft                   */
/*          センサ値取得(前方左側)                              */
/* 引数   : なし                                                */
/* 戻り値 : センサ値                                            */
/* 概要   : センサ値を提供する                                  */
/* 制約   : なし                                                */
/* ============================================================ */
U2 FnU2_PfRaySens_If_getValFrontLeft(VD)
{
  return (u2PfRaySens_If_FL);
}


/* ============================================================ */
/* 関数名 : FnU2_PfRaySens_If_getValLeft                        */
/*          センサ値取得(右側)                                  */
/* 引数   : なし                                                */
/* 戻り値 : センサ値                                            */
/* 概要   : センサ値を提供する                                  */
/* 制約   : なし                                                */
/* ============================================================ */
U2 FnU2_PfRaySens_If_getValLeft(VD)
{
  return (u2PfRaySens_If_L);
}

