/* ============================================================ */
/* ファイル名 : hw_drv_mtr.c                                    */
/* 機能       : モータ制御処理                                  */
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
#include "hw_pph_intctrl_pac.h"
#include "hw_pph_intctrl_cfg_pac.h"
#include "hw_pph_port_pac.h"
#include "hw_pph_port_cfg_pac.h"
#include "hw_pph_mtu_pac.h"
#include "hw_pph_mtu_cfg_pac.h"

/* 本体 */
#include "hw_drv_mtr.h"
#include "hw_drv_mtr_pac.h"


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */
/* -------------------------- */
/* ポートコンフィグレーション */
/* -------------------------- */
/* モータON/OFF切り替えポート */
#define CST_HwDrv_Mtr_Port_CfgEnb               CST_HwPph_Port_CfgP15

/* 右モータ回転方向制御ポート */
#define CST_HwDrv_Mtr_Port_CfgDirR              CST_HwPph_Port_CfgPC5

/* 左モータ回転方向制御ポート */
#define CST_HwDrv_Mtr_Port_CfgDirL              CST_HwPph_Port_CfgPC6

/* 右モータPWM出力ポート */
#define CST_HwDrv_Mtr_Port_CfgPwmR              CST_HwPph_Port_CfgP17

/* 左モータPWM出力ポート */
#define CST_HwDrv_Mtr_Port_CfgPwmL              CST_HwPph_Port_CfgPE2

/* ------------ */
/* ポート識番号 */
/* ------------ */
/* モータON/OFF切り替えポート */
#define CEN_HwDrv_Mtr_Port_IdEnb                CEN_HwPph_Port_Id_P15

/* 右モータ回転方向制御ポート */
#define CEN_HwDrv_Mtr_Port_IdDirR               CEN_HwPph_Port_Id_PC5

/* 左モータ回転方向制御ポート */
#define CEN_HwDrv_Mtr_Port_IdDirL               CEN_HwPph_Port_Id_PC6

/* ----------------------- */
/* MTUコンフィグレーション */
/* ----------------------- */
/* 右モータPWM出力用 */
/* MTU機能設定情報 */
#define CST_HwDrv_Mtr_Mtu_CfgPwmR               CST_HwPph_Mtu_CfgMtu3

/* タイマレジスタ識別 */
#define CEN_HwDrv_Mtr_Mtu_IdPwmRTmrCnt          CEN_HwPph_Mtu_IdTCNT_MTU3
#define CEN_HwDrv_Mtr_Mtu_IdPwmRPeriod          CEN_HwPph_Mtu_IdTGR_MTU3A
#define CEN_HwDrv_Mtr_Mtu_IdPwmROnTime          CEN_HwPph_Mtu_IdTGR_MTU3B
#define CEN_HwDrv_Mtr_Mtu_IdPwmRNextPeriod      CEN_HwPph_Mtu_IdTGR_MTU3C

/* [us]最低ON時間 */
#define CU2_HwDrv_Mtr_MinOnTimePwmR             ((U2)((FL)((FL)20.0F / CFL_HwDrv_Mtr_PwmRTmrLsb)))

/* [us]最低周期 */
#define CU2_HwDrv_Mtr_MinPeriodPwmR             ((U2)((U2)2 * CU2_HwDrv_Mtr_MinOnTimePwmR))

/* タイマレジスタ初期値 */
#define CU2_HwDrv_Mtr_PeriodInitPwmR            ((U2)((U2)((FL)((FL)16000.0F / CFL_HwDrv_Mtr_PwmRTmrLsb)) - (U2)1))
#define CU2_HwDrv_Mtr_OnTimeInitPwmR            CU2_HwDrv_Mtr_MinOnTimePwmR
#define CU2_HwDrv_Mtr_NextPeriodInitPwmR        ((U2)((U2)((FL)((FL)16000.0F / CFL_HwDrv_Mtr_PwmRTmrLsb)) - (U2)1))

/* モータ動作開始ビット位置 */
#define CU1_HwDrv_Mtr_Mtu_StartBitPosR          CU1_HwPph_Mtu_StartBitPosMtu3

/* 左モータPWM出力用 */
/* MTU機能設定情報 */
#define CST_HwDrv_Mtr_Mtu_CfgPwmL               CST_HwPph_Mtu_CfgMtu4

/* タイマレジスタ識別 */
#define CEN_HwDrv_Mtr_Mtu_IdPwmLTmrCnt          CEN_HwPph_Mtu_IdTCNT_MTU4
#define CEN_HwDrv_Mtr_Mtu_IdPwmLPeriod          CEN_HwPph_Mtu_IdTGR_MTU4A
#define CEN_HwDrv_Mtr_Mtu_IdPwmLOnTime          CEN_HwPph_Mtu_IdTGR_MTU4B
#define CEN_HwDrv_Mtr_Mtu_IdPwmLNextPeriod      CEN_HwPph_Mtu_IdTGR_MTU4C

/* [us]最低ON時間 */
#define CU2_HwDrv_Mtr_MinOnTimePwmL             ((U2)((FL)((FL)20.0F / CFL_HwDrv_Mtr_PwmLTmrLsb)))

/* [us]最低周期 */
#define CU2_HwDrv_Mtr_MinPeriodPwmL             ((U2)((U2)2 * CU2_HwDrv_Mtr_MinOnTimePwmL))

/* タイマレジスタ初期値 */
#define CU2_HwDrv_Mtr_PeriodInitPwmL            ((U2)((U2)((FL)((FL)16000.0F / CFL_HwDrv_Mtr_PwmLTmrLsb)) - (U2)1))
#define CU2_HwDrv_Mtr_OnTimeInitPwmL            CU2_HwDrv_Mtr_MinOnTimePwmL
#define CU2_HwDrv_Mtr_NextPeriodInitPwmL        ((U2)((U2)((FL)((FL)16000.0F / CFL_HwDrv_Mtr_PwmLTmrLsb)) - (U2)1))

/* モータ動作開始ビット位置 */
#define CU1_HwDrv_Mtr_Mtu_StartBitPosL          CU1_HwPph_Mtu_StartBitPosMtu4

/* モータ動作開始ビットマスク */
#define CU1_HwDrv_Mtr_Mtu_StartBitMskR          ((U1)((U1)1 << CU1_HwDrv_Mtr_Mtu_StartBitPosR))
#define CU1_HwDrv_Mtr_Mtu_StartBitMskL          ((U1)((U1)1 << CU1_HwDrv_Mtr_Mtu_StartBitPosL))
#define CU1_HwDrv_Mtr_Mtu_StartBitMskB          ((U1)(CU1_HwDrv_Mtr_Mtu_StartBitMskR | CU1_HwDrv_Mtr_Mtu_StartBitMskL))

/* 時間からタイマー値への変換係数 */
#define CU4_HwDrv_Mtr_changeTimeToTimerGain     ((U4)4096)

/* ---------- */
/* 割り込み用 */
/* ---------- */
/* 右モータパルス数取得用 */
#define CEN_HwDrv_Mtr_IntCtrl_VecId_PwmR        CEN_HwPph_IntCtrl_VecId_TPU9_TGI9B_MTU3_TGIB3
#define CEN_HwDrv_Mtr_IntCtrl_Priority_PwmR     CEN_HwPph_IntCtrl_CfgPriority_TPU9_TGI9B_MTU3_TGIB3
#define CU1_HwDrv_Mtr_IntCtrl_EnbInt_PwmR       ((U1)C_ON)

/* 左モータパルス数取得用 */
#define CEN_HwDrv_Mtr_IntCtrl_VecId_PwmL        CEN_HwPph_IntCtrl_VecId_TPU10_TGI10B_MTU4_TGIB4
#define CEN_HwDrv_Mtr_IntCtrl_Priority_PwmL     CEN_HwPph_IntCtrl_CfgPriority_TPU10_TGI10B_MTU4_TGIB4
#define CU1_HwDrv_Mtr_IntCtrl_EnbInt_PwmL       ((U1)C_ON)


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
/* [回]モータ パルス数 */
static U2 u2HwDrv_Mtr_PulseCntrR;
static U2 u2HwDrv_Mtr_PulseCntrL;


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
/* 関数名 : McU2_HwDrv_Mtr_changeTimeToTimer                    */
/*          時間[us]からタイマー値への変換                      */
/* 引数   : tu2Tim [us]時間                                     */
/*          tflLsb [us]LSB                                      */
/* 戻り値 : なし                                                */
/* 概要   : 時間[us]からタイマー値へ変換する                    */
/* 制約   : なし                                                */
/* ============================================================ */
#define McU2_HwDrv_Mtr_changeTimeToTimer(tu2Tim, tflLsb)    ((U2)((U4)(((U4)(tu2Tim) * (U4)((FL)CU4_HwDrv_Mtr_changeTimeToTimerGain / (tflLsb))) / CU4_HwDrv_Mtr_changeTimeToTimerGain)))


/* ============================================================ */
/* 関数定義                                                     */
/* ============================================================ */
/* ============================================================ */
/* 関数名 : FnVD_HwDrv_Mtr_clrPulseCntr                         */
/*          モータパルス数クリア                                */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 初期化する                                          */
/* 制約   : 割り込み禁止が解除される                            */
/* ============================================================ */
VD FnVD_HwDrv_Mtr_clrPulseCntr(VD)
{
  DI();
  u2HwDrv_Mtr_PulseCntrR = (U2)0;
  u2HwDrv_Mtr_PulseCntrL = (U2)0;
  EI();
}


/* ============================================================ */
/* 関数名 : FnVD_HwDrv_Mtr_getPulseCntr                         */
/*          モータパルス数取得                                  */
/* 引数   : tpu2PlusCntrR  右モータパルス数                     */
/*          tpu2PlusCntrR  左モータパルス数                     */
/* 戻り値 : なし                                                */
/* 概要   : モータパルス数を提供する                            */
/* 制約   : 割り込み禁止が解除される                            */
/* ============================================================ */
VD FnVD_HwDrv_Mtr_getPulseCntr(U2 * tpu2PulseCntrR, U2 * tpu2PulseCntrL)
{
  DI();
  *tpu2PulseCntrR = u2HwDrv_Mtr_PulseCntrR;
  *tpu2PulseCntrL = u2HwDrv_Mtr_PulseCntrL;
  EI();
}


/* ============================================================ */
/* 関数名 : FnVD_HwDrv_Mtr_cntPulseRight                        */
/*          右モータパルス数カウント(割り込み)                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 右モータのパルス数をカウントする                    */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_HwDrv_Mtr_cntPulseRight(VD)
{
  McXX_incU2Max(u2HwDrv_Mtr_PulseCntrR);
}


/* ============================================================ */
/* 関数名 : FnVD_HwDrv_Mtr_cntPulseLeft                         */
/*          左モータパルス数カウント(割り込み)                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 左モータのパルス数をカウントする                    */
/* 制約   : なし                                                */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_HwDrv_Mtr_cntPulseLeft(VD)
{
  McXX_incU2Max(u2HwDrv_Mtr_PulseCntrL);
}


/* ============================================================ */
/* 関数名 : FnVD_HwDrv_Mtr_init                                 */
/*          モータドライバ初期化                                */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 初期化する                                          */
/* 制約   : 割り込み禁止中に実行すること                        */
/* ============================================================ */
VD FnVD_HwDrv_Mtr_init(VD)
{
  /* 割り込み設定 */
  /* 右モータパルス数取得用割り込み */
  FnVD_HwPph_IntCtrl_setPriority(CEN_HwDrv_Mtr_IntCtrl_VecId_PwmR, CEN_HwDrv_Mtr_IntCtrl_Priority_PwmR);
  FnVD_HwPph_IntCtrl_setEnbInt(CEN_HwDrv_Mtr_IntCtrl_VecId_PwmR, CU1_HwDrv_Mtr_IntCtrl_EnbInt_PwmR);
  FnVD_HwPph_IntCtrl_clrIntReq(CEN_HwDrv_Mtr_IntCtrl_VecId_PwmR);

  /* 左モータパルス数取得用割り込み */
  FnVD_HwPph_IntCtrl_setPriority(CEN_HwDrv_Mtr_IntCtrl_VecId_PwmL, CEN_HwDrv_Mtr_IntCtrl_Priority_PwmL);
  FnVD_HwPph_IntCtrl_setEnbInt(CEN_HwDrv_Mtr_IntCtrl_VecId_PwmL, CU1_HwDrv_Mtr_IntCtrl_EnbInt_PwmL);
  FnVD_HwPph_IntCtrl_clrIntReq(CEN_HwDrv_Mtr_IntCtrl_VecId_PwmL);

  /* MTU設定 */
  /* 右モータPWM出力 */
  FnVD_HwPph_Mtu_cfgMtu3(&CST_HwDrv_Mtr_Mtu_CfgPwmR);
  FnVD_HwPph_Mtu_setTimerCounter(CEN_HwDrv_Mtr_Mtu_IdPwmRTmrCnt, (U2)0);
  FnVD_HwPph_Mtu_setTimerGeneralRegister(CEN_HwDrv_Mtr_Mtu_IdPwmRPeriod,     CU2_HwDrv_Mtr_PeriodInitPwmR);
  FnVD_HwPph_Mtu_setTimerGeneralRegister(CEN_HwDrv_Mtr_Mtu_IdPwmROnTime,     CU2_HwDrv_Mtr_OnTimeInitPwmR);
  FnVD_HwPph_Mtu_setTimerGeneralRegister(CEN_HwDrv_Mtr_Mtu_IdPwmRNextPeriod, CU2_HwDrv_Mtr_NextPeriodInitPwmR);

  /* 左モータPWM出力 */
  FnVD_HwPph_Mtu_cfgMtu4(&CST_HwDrv_Mtr_Mtu_CfgPwmL);
  FnVD_HwPph_Mtu_setTimerCounter(CEN_HwDrv_Mtr_Mtu_IdPwmLTmrCnt, (U2)0);
  FnVD_HwPph_Mtu_setTimerGeneralRegister(CEN_HwDrv_Mtr_Mtu_IdPwmLPeriod,     CU2_HwDrv_Mtr_PeriodInitPwmL);
  FnVD_HwPph_Mtu_setTimerGeneralRegister(CEN_HwDrv_Mtr_Mtu_IdPwmLOnTime,     CU2_HwDrv_Mtr_OnTimeInitPwmL);
  FnVD_HwPph_Mtu_setTimerGeneralRegister(CEN_HwDrv_Mtr_Mtu_IdPwmLNextPeriod, CU2_HwDrv_Mtr_NextPeriodInitPwmL);

  /* ポート設定 */
  /* motor_EN:モータON/OFF切り替え */
  FnVD_HwPph_Port_cfg(&CST_HwDrv_Mtr_Port_CfgEnb);

  /* CW/CCW_R:右モータCS/CCW */
  FnVD_HwPph_Port_cfg(&CST_HwDrv_Mtr_Port_CfgDirR);

  /* CW/CCW_L:左モータCS/CCW */
  FnVD_HwPph_Port_cfg(&CST_HwDrv_Mtr_Port_CfgDirL);

  /* motor_R_PWM:右モータPWM */
  FnVD_HwPph_Port_cfg(&CST_HwDrv_Mtr_Port_CfgPwmR);

  /* motor_L_PWM:左モータPWM */
  FnVD_HwPph_Port_cfg(&CST_HwDrv_Mtr_Port_CfgPwmL);

  /* モータ パルス数初期化 */
  FnVD_HwDrv_Mtr_clrPulseCntr();
}


/* ============================================================ */
/* 関数名 : FnVD_HwDrv_Mtr_setEnbPort                           */
/*          モータON/OFF切り替えポート出力レベル設定            */
/* 引数   : tu1Req  (0:禁止, 1:許可)                            */
/* 戻り値 : なし                                                */
/* 概要   : モータON/OFF切り替えポートの出力レベルを設定する    */
/* 制約   : 割り込み禁止が解除される                            */
/* ============================================================ */
VD FnVD_HwDrv_Mtr_setEnbPort(U1 tu1Req)
{
  DI();
  FnVD_HwPph_Port_setOutLv(CEN_HwDrv_Mtr_Port_IdEnb, tu1Req);
  EI();
}


/* ============================================================ */
/* 関数名 : FnVD_HwDrv_Mtr_setRotDirPortBoth                    */
/*          モータ回転方向制御ポート出力レベル設定              */
/* 引数   : tu1ReqR  右モータ(0:前転, 1:後転)                   */
/*          tu1ReqL  左モータ(0:前転, 1:後転)                   */
/* 戻り値 : なし                                                */
/* 概要   : モータ回転方向制御ポートの出力レベルを設定する      */
/* 制約   : 割り込み禁止が解除される                            */
/* ============================================================ */
VD FnVD_HwDrv_Mtr_setRotDirPortBoth(U1 tu1ReqR, U1 tu1ReqL)
{
  DI();
  FnVD_HwPph_Port_setOutLv(CEN_HwDrv_Mtr_Port_IdDirR, tu1ReqR);
  FnVD_HwPph_Port_setOutLv(CEN_HwDrv_Mtr_Port_IdDirL, tu1ReqL);
  EI();
}


/* ============================================================ */
/* 関数名 : FnVD_HwDrv_Mtr_setRotDirPortRight                   */
/*          右モータ回転方向制御ポート出力レベル設定            */
/* 引数   : tu1Req  (0:前転, 1:後転)                            */
/* 戻り値 : なし                                                */
/* 概要   : 右モータ回転方向制御ポートの出力レベルを設定する    */
/* 制約   : 割り込み禁止が解除される                            */
/* ============================================================ */
VD FnVD_HwDrv_Mtr_setRotDirPortRight(U1 tu1Req)
{
  DI();
  FnVD_HwPph_Port_setOutLv(CEN_HwDrv_Mtr_Port_IdDirR, tu1Req);
  EI();
}


/* ============================================================ */
/* 関数名 : FnVD_HwDrv_Mtr_setRotDirPortLeft                    */
/*          左モータ回転方向制御ポート出力レベル設定            */
/* 引数   : tu1Req  (0:前転, 1:後転)                            */
/* 戻り値 : なし                                                */
/* 概要   : 左モータ回転方向制御ポートの出力レベルを設定する    */
/* 制約   : 割り込み禁止が解除される                            */
/* ============================================================ */
VD FnVD_HwDrv_Mtr_setRotDirPortLeft(U1 tu1Req)
{
  DI();
  FnVD_HwPph_Port_setOutLv(CEN_HwDrv_Mtr_Port_IdDirL, tu1Req);
  EI();
}


/* ============================================================ */
/* 関数名 : FnVD_HwDrv_Mtr_setPulseWidthBoth                    */
/*          モータ出力設定                                      */
/* 引数   : tu2PeriodR   [us]右モータタイマ周期                 */
/*          tu2OnTimeR   [us]右モータON出力時間                 */
/*          tu2PeriodL   [us]右モータタイマ周期                 */
/*          tu2OnTimeL   [us]右モータON出力時間                 */
/* 戻り値 : なし                                                */
/* 概要   : モータ回転方向制御ポートの出力レベルを設定する      */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_HwDrv_Mtr_setPulseWidthBoth(U2 tu2PeriodR, U2 tu2OnTimeR, U2 tu2PeriodL, U2 tu2OnTimeL)
{
  U2 tu2PeriodTimerR;
  U2 tu2OnTimeTimerR;
  U2 tu2PeriodTimerL;
  U2 tu2OnTimeTimerL;

  tu2PeriodTimerR = McU2_HwDrv_Mtr_changeTimeToTimer(tu2PeriodR, CFL_HwDrv_Mtr_PwmRTmrLsb) - (U2)1;
  tu2PeriodTimerR = McXX_grdMin(tu2PeriodTimerR, CU2_HwDrv_Mtr_MinPeriodPwmR);

  tu2OnTimeTimerR = McU2_HwDrv_Mtr_changeTimeToTimer(tu2OnTimeR, CFL_HwDrv_Mtr_PwmRTmrLsb);
  tu2OnTimeTimerR = (U2)McXX_grdMin(tu2OnTimeTimerR, CU2_HwDrv_Mtr_MinOnTimePwmR);

  tu2PeriodTimerL = McU2_HwDrv_Mtr_changeTimeToTimer(tu2PeriodL, CFL_HwDrv_Mtr_PwmLTmrLsb) - (U2)1;
  tu2PeriodTimerL = McXX_grdMin(tu2PeriodTimerL, CU2_HwDrv_Mtr_MinPeriodPwmL);

  tu2OnTimeTimerL = McU2_HwDrv_Mtr_changeTimeToTimer(tu2OnTimeL, CFL_HwDrv_Mtr_PwmLTmrLsb);
  tu2OnTimeTimerL = (U2)McXX_grdMin(tu2OnTimeTimerL, CU2_HwDrv_Mtr_MinOnTimePwmL);

  FnVD_HwPph_Mtu_setTimerGeneralRegister(CEN_HwDrv_Mtr_Mtu_IdPwmRNextPeriod, tu2PeriodTimerR);
  FnVD_HwPph_Mtu_setTimerGeneralRegister(CEN_HwDrv_Mtr_Mtu_IdPwmLNextPeriod, tu2PeriodTimerL);
  FnVD_HwPph_Mtu_setTimerGeneralRegister(CEN_HwDrv_Mtr_Mtu_IdPwmROnTime,     tu2OnTimeTimerR);
  FnVD_HwPph_Mtu_setTimerGeneralRegister(CEN_HwDrv_Mtr_Mtu_IdPwmLOnTime,     tu2OnTimeTimerL);
}


/* ============================================================ */
/* 関数名 : FnVD_HwDrv_Mtr_setPulseWidthRight                   */
/*          右モータ出力設定                                    */
/* 引数   : tu2Period   [us]右モータタイマ周期                  */
/*          tu2OnTime   [us]右モータON出力時間                  */
/* 戻り値 : なし                                                */
/* 概要   : 右モータ回転方向制御ポートの出力レベルを設定する    */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_HwDrv_Mtr_setPulseWidthRight(U2 tu2Period, U2 tu2OnTime)
{
  U2 tu2PeriodTimer;
  U2 tu2OnTimeTimer;
 
  tu2PeriodTimer = McU2_HwDrv_Mtr_changeTimeToTimer(tu2Period, CFL_HwDrv_Mtr_PwmRTmrLsb) - (U2)1;
  tu2PeriodTimer = McXX_grdMin(tu2PeriodTimer, CU2_HwDrv_Mtr_MinPeriodPwmR);

  tu2OnTimeTimer = McU2_HwDrv_Mtr_changeTimeToTimer(tu2OnTime, CFL_HwDrv_Mtr_PwmRTmrLsb);
  tu2OnTimeTimer = (U2)McXX_grdMin(tu2OnTimeTimer, CU2_HwDrv_Mtr_MinOnTimePwmR);
  
  FnVD_HwPph_Mtu_setTimerGeneralRegister(CEN_HwDrv_Mtr_Mtu_IdPwmRNextPeriod, tu2PeriodTimer);
  FnVD_HwPph_Mtu_setTimerGeneralRegister(CEN_HwDrv_Mtr_Mtu_IdPwmROnTime,     tu2OnTimeTimer);
}


/* ============================================================ */
/* 関数名 : FnVD_HwDrv_Mtr_setPulseWidthLeft                    */
/*          左モータ出力設定                                    */
/* 引数   : tu2Period   [us]左モータタイマ周期                  */
/*          tu2OnTime   [us]左モータON出力時間                  */
/* 戻り値 : なし                                                */
/* 概要   : 左モータ回転方向制御ポートの出力レベルを設定する    */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_HwDrv_Mtr_setPulseWidthLeft(U2 tu2Period, U2 tu2OnTime)
{
  U2 tu2PeriodTimer;
  U2 tu2OnTimeTimer;

  tu2PeriodTimer = McU2_HwDrv_Mtr_changeTimeToTimer(tu2Period, CFL_HwDrv_Mtr_PwmLTmrLsb) - (U2)1;
  tu2PeriodTimer = McXX_grdMin(tu2PeriodTimer, CU2_HwDrv_Mtr_MinPeriodPwmL);

  tu2OnTimeTimer = McU2_HwDrv_Mtr_changeTimeToTimer(tu2OnTime, CFL_HwDrv_Mtr_PwmLTmrLsb);
  tu2OnTimeTimer = (U2)McXX_grdMin(tu2OnTimeTimer, CU2_HwDrv_Mtr_MinOnTimePwmL);

  FnVD_HwPph_Mtu_setTimerGeneralRegister(CEN_HwDrv_Mtr_Mtu_IdPwmLNextPeriod, tu2PeriodTimer);
  FnVD_HwPph_Mtu_setTimerGeneralRegister(CEN_HwDrv_Mtr_Mtu_IdPwmLOnTime,     tu2OnTimeTimer);
}


/* ============================================================ */
/* 関数名 : FnVD_HwDrv_Mtr_ctrlStpAndGoBoth                     */
/*          モータ出力開始                                      */
/* 引数   : tu1ReqR 右モータ制御要求(0:動作停止, 1:動作開始)    */
/*        : tu1ReqL 左モータ制御要求(0:動作停止, 1:動作開始)    */
/* 戻り値 : なし                                                */
/* 概要   : モータ出力を停止/開始する                           */
/* 制約   : 割り込み禁止が解除される                            */
/* ============================================================ */
VD FnVD_HwDrv_Mtr_ctrlStpAndGoBoth(U1 tu1ReqR, U1 tu1ReqL)
{
  U1 tu1EnbBit;
  U1 tu1ReqBit;

  tu1EnbBit  = CU1_HwDrv_Mtr_Mtu_StartBitMskB;
  tu1ReqBit  = (U1)((U1)(tu1ReqR & (U1)0x01) << CU1_HwDrv_Mtr_Mtu_StartBitPosR);
  tu1ReqBit |= (U1)((U1)(tu1ReqL & (U1)0x01) << CU1_HwDrv_Mtr_Mtu_StartBitPosL);

  DI();
  FnVD_HwPph_Mtu_ctrlStpAndGo(tu1EnbBit, tu1ReqBit);
  EI();
}


/* ============================================================ */
/* 関数名 : FnVD_HwDrv_Mtr_ctrlStpAndGoRight                    */
/*          右モータ出力開始                                    */
/* 引数   : tu1Req  右モータ制御要求(0:動作停止, 1:動作開始)    */
/* 戻り値 : なし                                                */
/* 概要   : 右モータ出力を停止/開始する                         */
/* 制約   : 割り込み禁止が解除される                            */
/* ============================================================ */
VD FnVD_HwDrv_Mtr_ctrlStpAndGoRight(U1 tu1Req)
{
  U1 tu1EnbBit;
  U1 tu1ReqBit;

  tu1EnbBit = CU1_HwDrv_Mtr_Mtu_StartBitMskR;
  tu1ReqBit = (U1)((U1)(tu1Req & (U1)0x01) << CU1_HwDrv_Mtr_Mtu_StartBitPosR);

  DI();
  FnVD_HwPph_Mtu_ctrlStpAndGo(tu1EnbBit, tu1ReqBit);
  EI();
}


/* ============================================================ */
/* 関数名 : FnVD_HwDrv_Mtr_ctrlStpAndGoLeft                     */
/*          左モータ出力開始                                    */
/* 引数   : tu1Req  左モータ制御要求(0:動作停止, 1:動作開始)    */
/* 戻り値 : なし                                                */
/* 概要   : 左モータ出力を停止/開始する                         */
/* 制約   : 割り込み禁止が解除される                            */
/* ============================================================ */
VD FnVD_HwDrv_Mtr_ctrlStpAndGoLeft(U1 tu1Req)
{
  U1 tu1EnbBit;
  U1 tu1ReqBit;

  tu1EnbBit = CU1_HwDrv_Mtr_Mtu_StartBitMskL;
  tu1ReqBit =  (U1)((U1)(tu1Req & (U1)0x01) << CU1_HwDrv_Mtr_Mtu_StartBitPosL);

  DI();
  FnVD_HwPph_Mtu_ctrlStpAndGo(tu1EnbBit, tu1ReqBit);
  EI();
}


/* ============================================================ */
/* 関数名 : FnVD_HwDrv_Mtr_reset                                */
/*          モータリセット処理                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : モータリセット処理                                  */
/* 制約   : タイマー(MTU)停止時に実行すること                   */
/* ============================================================ */
VD FnVD_HwDrv_Mtr_reset(VD)
{
  FnVD_HwPph_Mtu_setTimerCounter(CEN_HwDrv_Mtr_Mtu_IdPwmRTmrCnt, (U2)0);
  FnVD_HwPph_Mtu_setTimerGeneralRegister(CEN_HwDrv_Mtr_Mtu_IdPwmRPeriod,     CU2_HwDrv_Mtr_PeriodInitPwmR);
  FnVD_HwPph_Mtu_setTimerGeneralRegister(CEN_HwDrv_Mtr_Mtu_IdPwmROnTime,     CU2_HwDrv_Mtr_OnTimeInitPwmR);
  FnVD_HwPph_Mtu_setTimerGeneralRegister(CEN_HwDrv_Mtr_Mtu_IdPwmRNextPeriod, CU2_HwDrv_Mtr_NextPeriodInitPwmR);

  FnVD_HwPph_Mtu_setTimerCounter(CEN_HwDrv_Mtr_Mtu_IdPwmLTmrCnt, (U2)0);
  FnVD_HwPph_Mtu_setTimerGeneralRegister(CEN_HwDrv_Mtr_Mtu_IdPwmLPeriod,     CU2_HwDrv_Mtr_PeriodInitPwmL);
  FnVD_HwPph_Mtu_setTimerGeneralRegister(CEN_HwDrv_Mtr_Mtu_IdPwmLOnTime,     CU2_HwDrv_Mtr_OnTimeInitPwmL);
  FnVD_HwPph_Mtu_setTimerGeneralRegister(CEN_HwDrv_Mtr_Mtu_IdPwmLNextPeriod, CU2_HwDrv_Mtr_NextPeriodInitPwmL);
}
