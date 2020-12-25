/* ============================================================ */
/* ファイル名 : hw_drv_raysens.c                                */
/* 機能       : 光学センサ処理                                  */
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
#include "hw_pph_adc_pac.h"

/* 本体 */
#include "hw_drv_raysens.h"
#include "hw_drv_raysens_pac.h"


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */
/* コンフィグレーション */
#define CST_HwDrv_RaySens_Port_CfgLedR   CST_HwPph_Port_CfgP05
#define CST_HwDrv_RaySens_Port_CfgLedFR  CST_HwPph_Port_CfgPB5
#define CST_HwDrv_RaySens_Port_CfgLedFL  CST_HwPph_Port_CfgP27
#define CST_HwDrv_RaySens_Port_CfgLedL   CST_HwPph_Port_CfgP54
#define CST_HwDrv_RaySens_Port_CfgAdcR   CST_HwPph_Port_CfgP46
#define CST_HwDrv_RaySens_Port_CfgAdcFR  CST_HwPph_Port_CfgPE1
#define CST_HwDrv_RaySens_Port_CfgAdcFL  CST_HwPph_Port_CfgP44
#define CST_HwDrv_RaySens_Port_CfgAdcL   CST_HwPph_Port_CfgP42

/* ポート識番号 */
#define CEN_HwDrv_RaySens_Port_IdLedR   CEN_HwPph_Port_Id_P05
#define CEN_HwDrv_RaySens_Port_IdLedFR  CEN_HwPph_Port_Id_PB5
#define CEN_HwDrv_RaySens_Port_IdLedFL  CEN_HwPph_Port_Id_P27
#define CEN_HwDrv_RaySens_Port_IdLedL   CEN_HwPph_Port_Id_P54

/* A/D変換チャネル番号 */
#define CEN_HwDrv_RaySens_Adc_ChR       CEN_HwPph_Adc_Ch_06
#define CEN_HwDrv_RaySens_Adc_ChFR      CEN_HwPph_Adc_Ch_09
#define CEN_HwDrv_RaySens_Adc_ChFL      CEN_HwPph_Adc_Ch_04
#define CEN_HwDrv_RaySens_Adc_ChL       CEN_HwPph_Adc_Ch_02


/* ============================================================ */
/* 型定義                                                       */
/* ============================================================ */


/* ============================================================ */
/* 関数プロトタイプ宣言(static)                                 */
/* ============================================================ */
static VD FnVD_HwDrv_RaySens_clrVal(VD);


/* ============================================================ */
/* 変数定義(extern)                                             */
/* ============================================================ */


/* ============================================================ */
/* 変数定義(static)                                             */
/* ============================================================ */
static U2 u2HwDrv_RaySens_Val[CU1_HwDrv_RaySens_IdNum];


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
/* 関数名 : FnVD_HwDrv_RaySens_clrVal                           */
/*          センサ値クリア                                      */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : センサ値をクリアする                                */
/* 制約   : 割り込み禁止中に実行すること                        */
/* ============================================================ */
static VD FnVD_HwDrv_RaySens_clrVal(VD)
{
  U1 tu1Idx;

  for (tu1Idx = (U1)CEN_HwDrv_RaySens_Id_R; tu1Idx <= (U1)CEN_HwDrv_RaySens_Id_L; tu1Idx++) {
    u2HwDrv_RaySens_Val[tu1Idx] = (U2)0;
  }
}


/* ============================================================ */
/* 関数名 : FnVD_HwDrv_RaySens_init                             */
/*          光学センサ初期化                                    */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 初期化する                                          */
/* 制約   : 割り込み禁止中に実行すること                        */
/* ============================================================ */
VD FnVD_HwDrv_RaySens_init(VD)
{
  /* センサ用LEDポート初期化 */
  /* SLED_R:センサLED右側 */
  FnVD_HwPph_Port_cfg(&CST_HwDrv_RaySens_Port_CfgLedR);

  /* SLED_FR:センサLED右前 */
  FnVD_HwPph_Port_cfg(&CST_HwDrv_RaySens_Port_CfgLedFR);

  /* SLED_FL:センサLED左前 */
  FnVD_HwPph_Port_cfg(&CST_HwDrv_RaySens_Port_CfgLedFL);

  /* SLED_L:センサLED左側 */
  FnVD_HwPph_Port_cfg(&CST_HwDrv_RaySens_Port_CfgLedL);

  /* アナログ入力端子ポート初期化 */
  /* AN3:右センサ */
  FnVD_HwPph_Port_cfg(&CST_HwDrv_RaySens_Port_CfgAdcR);

  /* AN1:右前センサ */
  FnVD_HwPph_Port_cfg(&CST_HwDrv_RaySens_Port_CfgAdcFR);

  /* AN2:左前センサ */
  FnVD_HwPph_Port_cfg(&CST_HwDrv_RaySens_Port_CfgAdcFL);

  /* AN4:左センサ */
  FnVD_HwPph_Port_cfg(&CST_HwDrv_RaySens_Port_CfgAdcL);

  /* センサ値クリア */
  FnVD_HwDrv_RaySens_clrVal();
}


/* ============================================================ */
/* 関数名 : FnVD_HwDrv_RaySens_renewVal                         */
/*          センサ値更新                                        */
/* 引数   : tenId  センサ識別番号                               */
/* 戻り値 : なし                                                */
/* 概要   : センサ値を提供する                                  */
/* 制約   : センサ識別IDが規定外の場合は0を何もしない           */
/*          割り込み禁止が解除される                            */
/* ============================================================ */
VD FnVD_HwDrv_RaySens_renewVal(EN_HwDrv_RaySens_Id tenId)
{
  EN_HwPph_Port_Id tenPortId;
  EN_HwPph_Adc_Ch  tenAdcCh;
  EN_HwPph_Adc_Sts tenAdcSts;
  U4               tu4Set;
  U1               tu1Err;

  tu1Err = (U1)C_OFF;
  if (tenId == CEN_HwDrv_RaySens_Id_R) {
    tenAdcCh  = CEN_HwDrv_RaySens_Adc_ChR;
    tenPortId = CEN_HwDrv_RaySens_Port_IdLedR;
  }
  else if (tenId == CEN_HwDrv_RaySens_Id_FR) {
    tenAdcCh  = CEN_HwDrv_RaySens_Adc_ChFR;
    tenPortId = CEN_HwDrv_RaySens_Port_IdLedFR;
  }
  else if (tenId == CEN_HwDrv_RaySens_Id_FL) {
    tenAdcCh  = CEN_HwDrv_RaySens_Adc_ChFL;
    tenPortId = CEN_HwDrv_RaySens_Port_IdLedFL;
  }
  else if (tenId == CEN_HwDrv_RaySens_Id_L) {
    tenAdcCh  = CEN_HwDrv_RaySens_Adc_ChL;
    tenPortId = CEN_HwDrv_RaySens_Port_IdLedL;
  }
  else {
    tu1Err = (U1)C_ON;
  }

  if (tu1Err == (U1)C_OFF) {
    /* 割り込み禁止 */
    DI();

    /* センサ用LED点灯 */
    FnVD_HwPph_Port_setOutLv(tenPortId, (U1)C_ON);

    /* A/D変換対象設定 */
    tu4Set = (U4)((U4)1 << (U4)tenAdcCh);
    FnVD_HwPph_Adc_selTargetCh(tu4Set, (U4)~tu4Set);

    /* A/D変換開始 */
    FnVD_HwPph_Adc_start();

    /* A/D変換待ち */ /* ToDo:タイムアウト時間を設定すること */
    do {
      tenAdcSts = FnEN_HwPph_Adc_getSts();
    } while (tenAdcSts == CEN_HwPph_Adc_Sts_Run);

    /* センサ用LED消灯 */
    FnVD_HwPph_Port_setOutLv(tenPortId, (U1)C_OFF);

    /* A/D変換結果更新 */
    FnVD_HwPph_Adc_renewBuf();

    /* A/D変換結果取得 */
    u2HwDrv_RaySens_Val[tenId] = FnU2_HwPph_Adc_getVal(tenAdcCh);

    /* 割り込み許可 */
    EI();
  }
}


/* ============================================================ */
/* 関数名 : FnU2_HwDrv_RaySens_getVal                           */
/*          センサ値取得                                        */
/* 引数   : tenId  センサ識別番号                               */
/* 戻り値 : なし                                                */
/* 概要   : センサ値を提供する                                  */
/* 制約   : センサ識別IDが規定外の場合は0を返す                 */
/* ============================================================ */
U2 FnU2_HwDrv_RaySens_getVal(EN_HwDrv_RaySens_Id tenId)
{
  U2 tu2Ret;

  tu2Ret = (U2)0;
  if ((U1)tenId < CU1_HwDrv_RaySens_IdNum) {
    tu2Ret = u2HwDrv_RaySens_Val[tenId];
  }

  return (tu2Ret);
}


