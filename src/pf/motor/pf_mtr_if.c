/* ============================================================ */
/* ファイル名 : pf_mtr_if.c                                     */
/* 機能       : モータI/F処理                                   */
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
#include "hw_drv_mtr.h"
#include "pf_mtr_ctrl_pac.h"
#include "app_controll.h"

/* 本体 */
#include "pf_mtr_if.h"
#include "pf_mtr_if_pac.h"


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
/* [回]モータパルス数 */
static U2 u2PfMtr_If_RightMtrPulseCount;
static U2 u2PfMtr_If_LeftMtrPulseCount;


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
/* 関数名 : FnVD_PfMtr_If_initHw                                */
/*          モータI/F処理初期化(HW用)                           */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : ハードウェア層の初期化を行う                        */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_PfMtr_If_initHw(VD)
{
  FnVD_HwDrv_Mtr_init();
}


/* ============================================================ */
/* 関数名 : FnVD_PfMtr_If_initPf                                */
/*          モータI/F処理初期化(PF用)                           */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : モータI/F処理の初期化を行う                         */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_PfMtr_If_initPf(VD)
{
  /* モータパルス数初期化 */
  u2PfMtr_If_RightMtrPulseCount = (U2)0;
  u2PfMtr_If_LeftMtrPulseCount  = (U2)0;
}


/* ============================================================ */
/* 関数名 : FnVD_PfMtr_If_setReq                                */
/*          モータ出力要求設定                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : モータを出力する                                    */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_PfMtr_If_setReq(VD)
{
  U2 tu2PeriodR;
  U2 tu2OnTimeR;
  U2 tu2PeriodL;
  U2 tu2OnTimeL;
  U1 tu1RotDirPortR;
  U1 tu1RotDirPortL;
  U1 tu1Enb;
  U1 tu1ResetReq;

  /* ------------ */
  /* 調停結果取得 */
  /* ------------ */
  tu1Enb         = FnU1_PfMtr_Ctrl_getCtrlEnb();
  tu1RotDirPortR = FnU1_PfMtr_Ctrl_getRightMtrRotDirReq();
  tu2PeriodR     = FnU2_PfMtr_Ctrl_getRightMtrPeriod();
  tu2OnTimeR     = FnU2_PfMtr_Ctrl_getRightMtrOnTime();
  tu1RotDirPortL = FnU1_PfMtr_Ctrl_getLeftMtrRotDirReq();
  tu2PeriodL     = FnU2_PfMtr_Ctrl_getLeftMtrPeriod();
  tu2OnTimeL     = FnU2_PfMtr_Ctrl_getLeftMtrOnTime();
  tu1ResetReq    = u1AppCtrl_getResetPulseCntReq();

  /* -------- */
  /* 出力設定 */
  /* -------- */
  /* 非駆動時はパルス数クリア */
  if (   (tu1Enb == (U1)C_OFF)
      || (tu1ResetReq == (U1)C_ON)) {

    FnVD_PfMtr_If_clrPulseCntr();
  }

  /* モータ出力許可設定 */
  FnVD_HwDrv_Mtr_setEnbPort(tu1Enb);

  /* モータ回転方向設定 */
  FnVD_HwDrv_Mtr_setRotDirPortBoth(tu1RotDirPortR, tu1RotDirPortL);

  /* モータPWM設定 */
  FnVD_HwDrv_Mtr_setPulseWidthBoth(tu2PeriodR, tu2OnTimeR, tu2PeriodL, tu2OnTimeL);

  /* モータ制御開始/停止 */
  FnVD_HwDrv_Mtr_ctrlStpAndGoBoth(tu1Enb, tu1Enb);
}


/* ============================================================ */
/* 関数名 : FnVD_PfMtr_If_clrPulseCntr                          */
/*          モータパルス数クリア                                */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : モータパルス数をクリアする                          */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_PfMtr_If_clrPulseCntr(VD)
{
  FnVD_HwDrv_Mtr_clrPulseCntr();
}


/* ============================================================ */
/* 関数名 : FnVD_PfMtr_If_renewPulseCntr                        */
/*          モータパルス数更新                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : モータパルス数を更新する                            */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_PfMtr_If_renewPulseCntr(VD)
{
  FnVD_HwDrv_Mtr_getPulseCntr(&u2PfMtr_If_RightMtrPulseCount, &u2PfMtr_If_LeftMtrPulseCount);
}


/* ============================================================ */
/* 関数名 : FnU2_PfMtr_If_getRightMtrPulseCount                 */
/*          右モータパルス数取得                                */
/* 引数   : なし                                                */
/* 戻り値 : [回]右モータパルス数(LSB:1回)                       */
/* 概要   : 右モータパルス数を提供する                          */
/* 制約   : なし                                                */
/* ============================================================ */
U2 FnU2_PfMtr_If_getRightMtrPulseCount(VD)
{
  return (u2PfMtr_If_RightMtrPulseCount);
}


/* ============================================================ */
/* 関数名 : FnU2_PfMtr_If_getLeftMtrPulseCount                  */
/*          左モータパルス数取得                                */
/* 引数   : なし                                                */
/* 戻り値 : [回]左モータパルス数(LSB:1回)                       */
/* 概要   : 左モータパルス数を提供する                          */
/* 制約   : なし                                                */
/* ============================================================ */
U2 FnU2_PfMtr_If_getLeftMtrPulseCount(VD)
{
  return (u2PfMtr_If_LeftMtrPulseCount);
}

