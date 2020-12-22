/* ============================================================ */
/* ファイル名 : hw_pph_adc.c                                    */
/* 機能       : A/D変換処理                                     */
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
#include "hw_pph_reg_pac.h"

/* 本体 */
#include "hw_pph_adc_pac.h"
#include "hw_pph_adc_cfg_pac.h"


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */
#define CU2_HwPph_Adc_ProtectKey         ((U2)0xA5)        /* 保護解除キー */
#define CU4_HwPph_Adc_MSTPCR_MSTP_Reset  ((U4)0x0)         /* モジュールストップ状態の解除 */
#define CU4_HwPph_Adc_MSTPCR_MSTP_Stp    ((U4)0x1)         /* モジュールストップ状態へ遷移 */
#define CU2_HwPph_Adc_ADSSTR01_Init      ((U2)0x1414)      /* ADSSTR01初期値 */
#define CU2_HwPph_Adc_ADSSTR23_Init      ((U2)0x1414)      /* ADSSTR23初期値 */
#define CU4_HwPph_Adc_ChMsk              ((U4)0x001FFFFF)  /* チャネルマスク */


/* ============================================================ */
/* 型定義                                                       */
/* ============================================================ */


/* ============================================================ */
/* 関数プロトタイプ宣言(static)                                 */
/* ============================================================ */
static VD FnVD_HwPph_Adc_enbStpModuleSetting(VD);
static VD FnVD_HwPph_Adc_dibStpModuleSetting(VD);
static VD FnVD_HwPph_Adc_clrAllBuf(VD);
static VD FnVD_HwPph_Adc_clrAllDataReg(VD);


/* ============================================================ */
/* 変数定義(extern)                                             */
/* ============================================================ */


/* ============================================================ */
/* 変数定義(static)                                             */
/* ============================================================ */
static U2 u2aHwPph_Adc_Buf[CU1_HwPph_Adc_ChNum];    /* A/D変換結果 */
static volatile U2 u2HwPph_Adc_Dmy;                 /* ダミーリード用 */
static U2 u2aHwPph_Adc_Buf[CU1_HwPph_Adc_ChNum];    /* A/D変換結果 */


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
/* 関数名 : FnVD_HwPph_Adc_enbStpModuleSetting                  */
/*          モジュール停止制御レジスタ保護解除                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : モジュール停止制御レジスタの保護を解除する          */
/* 制約   : 割り込み禁止中に実行すること                        */
/* ============================================================ */
#pragma inline (FnVD_HwPph_Adc_enbStpModuleSetting)
static VD FnVD_HwPph_Adc_enbStpModuleSetting(VD)
{
  ST_PRCR tstPRCR;

  tstPRCR.u2Val = stRegSys0.stPRCR.u2Val;
  tstPRCR.stBit.b1PRC1 = (U2)1;
  tstPRCR.stBit.b8PRKEY = CU2_HwPph_Adc_ProtectKey;
  stRegSys0.stPRCR.u2Val = tstPRCR.u2Val;
}


/* ============================================================ */
/* 関数名 : FnVD_HwPph_Adc_dibStpModuleSetting                  */
/*          モジュール停止制御レジスタ保護                      */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : モジュール停止制御レジスタの保護する                */
/* 制約   : 割り込み禁止中に実行すること                        */
/* ============================================================ */
#pragma inline (FnVD_HwPph_Adc_dibStpModuleSetting)
static VD FnVD_HwPph_Adc_dibStpModuleSetting(VD)
{
  ST_PRCR tstPRCR;

  tstPRCR.u2Val = stRegSys0.stPRCR.u2Val;
  tstPRCR.stBit.b1PRC1 = (U2)0;
  tstPRCR.stBit.b8PRKEY = CU2_HwPph_Adc_ProtectKey;
  stRegSys0.stPRCR.u2Val = tstPRCR.u2Val;
}


/* ============================================================ */
/* 関数名 : FnVD_HwPph_Adc_clrAllBuf                            */
/*          全A/D変換結果バッファクリア                         */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : A/D変換結果バッファをクリアする                     */
/* 制約   :                                                     */
/* ============================================================ */
static VD FnVD_HwPph_Adc_clrAllBuf(VD)
{
  U1 tu1Idx;

  for (tu1Idx = (U1)CEN_HwPph_Adc_Ch_00; tu1Idx <= (U1)CEN_HwPph_Adc_Ch_20; tu1Idx++) {
    u2aHwPph_Adc_Buf[tu1Idx] = (U2)0x0000;
  }
}


/* ============================================================ */
/* 関数名 : FnVD_HwPph_Adc_clrAllDataReg                        */
/*          A/D変換結果レジスタクリア                           */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : A/D変換結果レジスタをクリアする                     */
/* 制約   :                                                     */
/* ============================================================ */
static VD FnVD_HwPph_Adc_clrAllDataReg(VD)
{
  U1 tu1Idx;

  if (CU1_HwPph_Adc_CfgReadClrEnb_ == (U1)C_ON) {
    /* リードクリア */
    for (tu1Idx = (U1)CEN_HwPph_Adc_Ch_00; tu1Idx <= (U1)CEN_HwPph_Adc_Ch_20; tu1Idx++) {
      u2HwPph_Adc_Dmy = stRegS12AD.staADDRy[tu1Idx].u2Val;
    }
  }
}


/* ============================================================ */
/* 関数名 : FnVD_HwPph_Adc_resetModuleStp                       */
/*          モジュール停止制御レジスタ解除設定                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : モジュール停止を解除する                            */
/* 制約   : 割り込み禁止中に実行すること                        */
/* ============================================================ */
VD FnVD_HwPph_Adc_resetModuleStp(VD)
{
  ST_MSTPCRA tstMSTPCRA;

  /* 保護解除 */
  FnVD_HwPph_Adc_enbStpModuleSetting();

  /* モジュールストップコントロールレジスタ設定(解除) */
  tstMSTPCRA.u4Val = (U4)0xFFFFFFFF;
  tstMSTPCRA.stBit.b1MSTPA17 = CU4_HwPph_Adc_MSTPCR_MSTP_Reset;  /* S12AD */
  stRegSys0.stMSTPCRA.u4Val &= tstMSTPCRA.u4Val;

  /* 保護 */
  FnVD_HwPph_Adc_dibStpModuleSetting();
}


/* ============================================================ */
/* 関数名 : FnVD_HwPph_Adc_stpModuleStp                         */
/*          モジュール停止制御レジスタ遷移設定                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : モジュール停止へ遷移する                            */
/* 制約   : 割り込み禁止中に実行すること                        */
/* ============================================================ */
VD FnVD_HwPph_Adc_stpModuleStp(VD)
{
  ST_MSTPCRA tstMSTPCRA;

  /* 保護解除 */
  FnVD_HwPph_Adc_enbStpModuleSetting();

  /* モジュールストップコントロールレジスタ設定(解除) */
  tstMSTPCRA.u4Val = (U4)0x00000000;
  tstMSTPCRA.stBit.b1MSTPA17 = CU4_HwPph_Adc_MSTPCR_MSTP_Stp;  /* S12AD */
  stRegSys0.stMSTPCRA.u4Val |= tstMSTPCRA.u4Val;

  /* 保護 */
  FnVD_HwPph_Adc_dibStpModuleSetting();
}


/* ============================================================ */
/* 関数名 : FnVD_HwPph_Adc_cfg                                  */
/*          A/D変換機能設定                                     */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : A/D変換機能を設定する                               */
/* 制約   : 割り込み禁止中に実行すること                        */
/* ============================================================ */
VD FnVD_HwPph_Adc_cfg(VD)
{
  ST_ADCSR    tstADCSR;
  ST_ADCER    tstADCER;
  ST_ADSSTR01 tstADSSTR01;

  /* A/D変換停止 */
  tstADCSR.u1Val = stRegS12AD.stADCSR.u1Val;
  tstADCSR.stBit.b1TRGE = (U1)0;
  stRegS12AD.stADCSR.u1Val = tstADCSR.u1Val;  /* 同期/非同期トリガー禁止選定 */
  tstADCSR.stBit.b1ADST = (U1)0;
  stRegS12AD.stADCSR.u1Val = tstADCSR.u1Val;  /* A/D変換停止 */

  /* A/D コントロールレジスタ設定 */
  tstADCSR.u1Val = (U1)0x00;
  tstADCSR.stBit.b1EXTRG = (U1)0;
  tstADCSR.stBit.b1TRGE  = (U1)0;
  tstADCSR.stBit.b2CKS   = (U1)CEN_HwPph_Adc_CfgSelClk_;
  tstADCSR.stBit.b1ADIE  = (U1)CU1_HwPph_Adc_CfgIntEnb_;
  tstADCSR.stBit.b1ADCS  = (U1)0;
  tstADCSR.stBit.b1ADST  = (U1)0;
  stRegS12AD.stADCSR.u1Val = tstADCSR.u1Val;

  /* A/D チャネル選択レジスタ0, 1 初期化 */ /* 変換前に使用する */
  stRegS12AD.staADANSi[0].u2Val = (U2)0x0000;  /* A/D変換対象なし */
  stRegS12AD.staADANSi[0].u2Val = (U2)0x0000;  /* A/D変換対象なし */

  /* A/D 変換値加算モード選択レジスタ0, 1 初期化 */
  stRegS12AD.staADADSi[0].u2Val = (U2)0x0000;  /* 非加算モード */
  stRegS12AD.staADADSi[0].u2Val = (U2)0x0000;  /* 非加算モード */

  /* A/D 変換値加算回数選択レジスタ */
  stRegS12AD.stADADC.u1Val = (U1)0x00;  /* 加算なし */

  /* A/D コントロール拡張レジスタ */
  tstADCER.u2Val = (U2)0x0000;
  tstADCER.stBit.b1ACE    = (U2)CU1_HwPph_Adc_CfgReadClrEnb_;
  tstADCER.stBit.b1ADRFMT = (U2)CEN_HwPph_Adc_CfgFormat_;
  stRegS12AD.stADCER.u2Val = tstADCER.u2Val;

  /* A/D 開始トリガ選択レジスタ */
  /* Memo:ソフトトリガーを使用するため設定不要(ADCSR.EXTRG = 0, ADCSR.TRGE = 0) */

  /* A/D 変換拡張入力コントロールレジスタ */
  stRegS12AD.stADEXICR.u2Val = (U2)0x0000;  /* Memo:温度センサ、内部基準電圧 未使用 */

  /* A/D サンプリングステートレジスタ01 */
  tstADSSTR01.u2Val = CU2_HwPph_Adc_ADSSTR01_Init;
  tstADSSTR01.stBit.b8SST1 = (U2)CU1_HwPph_Adc_CfgSamplingTime_;
  stRegS12AD.stADSSTR01.u2Val = tstADSSTR01.u2Val;

  /* A/D サンプリングステートレジスタ23 */
  stRegS12AD.stADSSTR23.u2Val = CU2_HwPph_Adc_ADSSTR23_Init;  /* Memo:温度センサ未使用 */

  /* 全A/D変換バッファクリア */
  FnVD_HwPph_Adc_clrAllBuf();

  /* 全A/D変換結果レジスタクリア */
  FnVD_HwPph_Adc_clrAllDataReg();
}


/* ============================================================ */
/* 関数名 : FnVD_HwPph_Adc_selTargetCh                          */
/*          A/D変換対象選択                                     */
/* 引数   : tu4Set  変換対象とするチャネル                      */
/*          tu4Clr  変換対象としないチャネル                    */
/* 戻り値 : なし                                                */
/* 概要   : A/D変換の対象チャネルを設定する                     */
/* 制約   :                                                     */
/* ============================================================ */
VD FnVD_HwPph_Adc_selTargetCh(U4 tu4Set, U4 tu4Clr)
{
  WD tstSet;
  WD tstClr;
  U2 tu2Val;

  tstSet.u4Val = tu4Set & (U4)0x001FFFFF;
  tstClr.u4Val = tu4Clr & (U4)0x001FFFFF;

  tu2Val = stRegS12AD.staADANSi[0].u2Val;
  tu2Val |= (U2)tstSet.HWord.b16L;
  tu2Val &= (U2)~(tstClr.HWord.b16L);
  stRegS12AD.staADANSi[0].u2Val = tu2Val;

  tu2Val = stRegS12AD.staADANSi[1].u2Val;
  tu2Val |= (U2)tstSet.HWord.b16H;
  tu2Val &= (U2)~(tstClr.HWord.b16H);
  stRegS12AD.staADANSi[1].u2Val = tu2Val;
}


/* ============================================================ */
/* 関数名 : FnEN_HwPph_Adc_getSts                               */
/*          A/D変換実行ステータス取得                           */
/* 引数   : なし                                                */
/* 戻り値 : A/D変換実行ステータス                               */
/*          EN_HwPph_Adc_Sts型                                  */
/*          CEN_HwPph_Adc_Sts_Idle 待機状態(停止中)             */
/*          CEN_HwPph_Adc_Sts_Run  実行中                       */
/* 概要   : A/D変換の実行ステータスを提供する                   */
/* 制約   :                                                     */
/* ============================================================ */
EN_HwPph_Adc_Sts FnEN_HwPph_Adc_getSts(VD)
{
  ST_ADCSR         tstADCSR;
  EN_HwPph_Adc_Sts tenSts;

  tstADCSR.u1Val = stRegS12AD.stADCSR.u1Val;
  tenSts = ((tstADCSR.stBit.b1ADST == (U1)C_OFF) ? CEN_HwPph_Adc_Sts_Idle : CEN_HwPph_Adc_Sts_Run);

  return (tenSts);
}


/* ============================================================ */
/* 関数名 : FnVD_HwPph_Adc_start                                */
/*          A/D変換開始トリガー発行                             */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : A/D変換をソフトウェアトリガーで開始する             */
/* 制約   : 割り込み禁止中に実行すること                        */
/* ============================================================ */
VD FnVD_HwPph_Adc_start(VD)
{
  ST_ADCSR tstADCSR;

  tstADCSR.u1Val = stRegS12AD.stADCSR.u1Val;
  tstADCSR.stBit.b1ADST = (U1)1;
  stRegS12AD.stADCSR.u1Val = tstADCSR.u1Val;
}


/* ============================================================ */
/* 関数名 : FnVD_HwPph_Adc_end                                  */
/*          A/D変換停止                                         */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : A/D変換を停止する                                   */
/* 制約   : 割り込み禁止中に実行すること                        */
/* ============================================================ */
VD FnVD_HwPph_Adc_end(VD)
{
  ST_ADCSR tstADCSR;

  /* A/D変換停止 */
  tstADCSR.u1Val = stRegS12AD.stADCSR.u1Val;
  tstADCSR.stBit.b1TRGE = (U1)0;
  stRegS12AD.stADCSR.u1Val = tstADCSR.u1Val;  /* 同期/非同期トリガー禁止選定 */
  tstADCSR.stBit.b1ADST = (U1)0;
  stRegS12AD.stADCSR.u1Val = tstADCSR.u1Val;  /* A/D変換停止 */
}


/* ============================================================ */
/* 関数名 : FnVD_HwPph_Adc_renewBuf                             */
/*          A/D変換結果バッファ更新                             */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : A/D変換結果をバッファへ格納する                     */
/* 制約   : 割り込み禁止中に実行すること                        */
/* ============================================================ */
VD FnVD_HwPph_Adc_renewBuf(VD)
{
  WD       tstTarget;
  ST_ADDRy tstADDRy;
  U2       tu2Val;
  U1       tu1Idx;

  tstTarget.HWord.b16L = (U4)stRegS12AD.staADANSi[0].u2Val;
  tstTarget.HWord.b16H = (U4)stRegS12AD.staADANSi[1].u2Val;
  for (tu1Idx = (U1)CEN_HwPph_Adc_Ch_00; tu1Idx <= (U1)CEN_HwPph_Adc_Ch_20; tu1Idx++) {

    /* 変換対象のチャネルのみA/D変換結果更新する */
    if ((U4)(tstTarget.u4Val & (U4)((U4)1 << (U4)tu1Idx)) != (U4)0) {
       tstADDRy.u2Val = stRegS12AD.staADDRy[tu1Idx].u2Val;
       if (0) {
         /* 加算モード(左詰め) */ /* Memo:加算モード未使用 */
         tu2Val = tstADDRy.stAdd.stBit.b14AD;
#if (0)
         /* ToDo:変換回数で割って平均値とすること */
#endif
       }
       else if (CEN_HwPph_Adc_CfgFormat_ == CEN_HwPph_Adc_Format_Right) {
         /* 右詰め */
         tu2Val = tstADDRy.stRight.stBit.b12AD;
       }
       else {
         /* 左詰め */
         tu2Val = tstADDRy.stLeft.stBit.b12AD;
       }
       u2aHwPph_Adc_Buf[tu1Idx] = tu2Val;
    }
  }
}


/* ============================================================ */
/* 関数名 : FnVD_HwPph_Adc_getVal                               */
/*          A/D変換値取得                                       */
/* 引数   : tenCh   チャネル番号                                */
/* 戻り値 : A/D変換値                                           */
/* 概要   : A/D変換値を返す                                     */
/* 制約   : 規定外のチャネル番号の場合は0を返す                 */
/* ============================================================ */
U2 FnU2_HwPph_Adc_getVal(EN_HwPph_Adc_Ch tenCh)
{
  U2 tu2Ret;

  tu2Ret = (U2)0;
  if ((U1)tenCh < CU1_HwPph_Adc_ChNum) {
    tu2Ret = u2aHwPph_Adc_Buf[tenCh];
  }

  return (tu2Ret);
}


