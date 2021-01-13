/* ============================================================ */
/* ファイル名 : hw_drv_buzzer.c                                 */
/* 機能       : ブザー制御処理                                  */
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
#include "hw_srv_interrupt.h"
#include "hw_pph_port_pac.h"
#include "hw_pph_port_cfg_pac.h"
#include "hw_pph_intctrl_pac.h"
#include "hw_pph_intctrl_cfg_pac.h"
#include "hw_pph_mtu_pac.h"
#include "hw_pph_mtu_cfg_pac.h"

/* 本体 */
#include "hw_drv_buzzer.h"
#include "hw_drv_buzzer_pac.h"


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */
/* -------------------------- */
/* ポートコンフィグレーション */
/* -------------------------- */
#define CST_HwDrv_Bz_Port_Cfg            CST_HwPph_Port_CfgPB3

/* ------------ */
/* ポート識番号 */
/* ------------ */
#define CEN_HwDrv_Bz_Port_Id             CEN_HwPph_Port_Id_PB3

/* ----------------------- */
/* MTUコンフィグレーション */
/* ----------------------- */
/* MTU機能設定情報 */
#define CST_HwDrv_Bz_Mtu_Cfg             CST_HwPph_Mtu_CfgMtu0

/* タイマレジスタ識別 */
#define CEN_HwDrv_Bz_Mtu_IdPwmTmrCnt     CEN_HwPph_Mtu_IdTCNT_MTU0
#define CEN_HwDrv_Bz_Mtu_IdPwmPeriod     CEN_HwPph_Mtu_IdTGR_MTU0B
#define CEN_HwDrv_Bz_Mtu_IdPwmOffTime    CEN_HwPph_Mtu_IdTGR_MTU0A

/* [us]最低OFF時間 */
#define CU2_HwDrv_Bz_MinOffTimePwm       ((U2)((FL)((FL)20.0F / CFL_HwDrv_Bz_PwmTmrLsb)))

/* [us]最低周期 */
#define CU2_HwDrv_Bz_MinPeriodPwm        ((U2)((U2)2 * CU2_HwDrv_Bz_MinOffTimePwm))

/* タイマレジスタ初期値 */
#define CU2_HwDrv_Bz_PeriodInitPwm       ((U2)((U2)((FL)((FL)1000.0F / CFL_HwDrv_Bz_PwmTmrLsb)) - (U2)1))
#define CU2_HwDrv_Bz_OffTimeInitPwm      ((U2)((U2)(CU2_HwDrv_Bz_PeriodInitPwm + (U2)1) / (U2)2))

/* モータ動作開始ビット位置 */
#define CU1_HwDrv_Bz_Mtu_StartBitPos     CU1_HwPph_Mtu_StartBitPosMtu0

/* モータ動作開始ビットマスク */
#define CU1_HwDrv_Bz_Mtu_StartBitMsk    ((U1)((U1)1 << CU1_HwDrv_Bz_Mtu_StartBitPos))


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
/* 関数名 : McU2_HwDrv_Bz_changeFreqToTimer                     */
/*          周波数[Hz]からタイマー値への変換                    */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 周波数[Hz]からタイマー値へ変換する                  */
/* 制約   : 最大5KHz                                            */
/* ============================================================ */
#define McU2_HwDrv_Bz_changeFreqToTimer(tu4Freq)    ((U2)McXX_grdMax((((U4)CFL_HwDrv_Bz_PwmTmrFreq * (U4)10000000) / (tu4Freq)), (U4)62000))


/* ============================================================ */
/* 関数定義                                                     */
/* ============================================================ */
/* ============================================================ */
/* 関数名 : FnVD_HwDrv_Bz_init                                  */
/*          ブザードライバ初期化                                */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 初期化する                                          */
/* 制約   : 割り込み禁止中に実行すること                        */
/* ============================================================ */
VD FnVD_HwDrv_Bz_init(VD)
{
  /* MTU設定 */
  FnVD_HwPph_Mtu_cfgMtu0(&CST_HwDrv_Bz_Mtu_Cfg);
  FnVD_HwPph_Mtu_setTimerCounter(CEN_HwDrv_Bz_Mtu_IdPwmTmrCnt, (U2)0);
  FnVD_HwPph_Mtu_setTimerGeneralRegister(CEN_HwDrv_Bz_Mtu_IdPwmPeriod,  CU2_HwDrv_Bz_PeriodInitPwm);
  FnVD_HwPph_Mtu_setTimerGeneralRegister(CEN_HwDrv_Bz_Mtu_IdPwmOffTime, CU2_HwDrv_Bz_OffTimeInitPwm);

  /* ポート設定 */
  FnVD_HwPph_Port_cfg(&CST_HwDrv_Bz_Port_Cfg);
}


/* ============================================================ */
/* 関数名 : FnVD_HwDrv_Mtr_setPlusWidthBoth                     */
/*          ブザー駆動周波数設定                                */
/* 引数   : tu4Freq   [Hz]周波数                                */
/* 戻り値 : なし                                                */
/* 概要   : ブザー駆動周波数を設定する                          */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_HwDrv_Bz_setFreq(U4 tu4Freq)
{
  U2 tu2PeriodTimer;
  U2 tu2OffTimeTimer;

  tu2PeriodTimer  = (U2)(McU2_HwDrv_Bz_changeFreqToTimer(tu4Freq) - (U2)1);
  tu2OffTimeTimer = (U2)(tu2PeriodTimer + (U2)1) / (U2)2;
  tu2PeriodTimer  = McXX_grdMin(tu2PeriodTimer,  CU2_HwDrv_Bz_MinPeriodPwm);
  tu2OffTimeTimer = McXX_grdMin(tu2OffTimeTimer, CU2_HwDrv_Bz_MinOffTimePwm);

  FnVD_HwPph_Mtu_setTimerGeneralRegister(CEN_HwDrv_Bz_Mtu_IdPwmPeriod,  tu2PeriodTimer);
  FnVD_HwPph_Mtu_setTimerGeneralRegister(CEN_HwDrv_Bz_Mtu_IdPwmOffTime, tu2OffTimeTimer);
}


/* ============================================================ */
/* 関数名 : FnVD_HwDrv_Bz_ctrlStpAndGo                          */
/* 引数   : tu1Req  ブザー制御要求(0:動作停止, 1:動作開始)      */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : ブザー出力を停止/開始する                           */
/* 制約   : 割り込み禁止が解除される                            */
/* ============================================================ */
VD FnVD_HwDrv_Bz_ctrlStpAndGo(U1 tu1Req)
{
  U1 tu1EnbBit;
  U1 tu1ReqBit;

  tu1EnbBit = CU1_HwDrv_Bz_Mtu_StartBitMsk;
  tu1ReqBit = (U1)((U1)(tu1Req & (U1)0x01) << CU1_HwDrv_Bz_Mtu_StartBitPos);

  DI();
  FnVD_HwPph_Mtu_ctrlStpAndGo(tu1EnbBit, tu1ReqBit);
  EI();
}


