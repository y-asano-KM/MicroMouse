/* ============================================================ */
/* ファイル名 : hw_pph_cmt.c                                    */
/* 機能       : CMT処理                                         */
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
#include "hw_pph_cmt_pac.h"


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */
#define CU2_HwPph_Cmt_ProtectKey         ((U2)0xA5)    /* 保護解除キー */
#define CU2_HwPph_Cmt_CMCR_Fix0          ((U2)0x1)     /* CMCRレジスタ固定値ビット0設定値 */
#define CU4_HwPph_Cmt_MSTPCR_MSTP_Reset  ((U4)0x0)     /* モジュールストップ状態の解除 */
#define CU4_HwPph_Cmt_MSTPCR_MSTP_Stp    ((U4)0x1)     /* モジュールストップ状態へ遷移 */


/* ============================================================ */
/* 型定義                                                       */
/* ============================================================ */


/* ============================================================ */
/* 関数プロトタイプ宣言(static)                                 */
/* ============================================================ */
static VD FnVD_HwPph_Cmt_getIdx(EN_HwPph_Cmt_Unit tenUnit, U1 * tpu1UnitIdx, U1 * tpu1ChIdx);
static VD FnVD_HwPph_Cmt_enbStpModuleSetting(VD);
static VD FnVD_HwPph_Cmt_dibStpModuleSetting(VD);


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
/* 関数名 : FnVD_HwPph_Cmt_getIdx                               */
/*          ユニット/チャネルインデックス取得                   */
/* 引数   : tenUnit      ユニット番号                           */
/*          tpu1MainIdx  メインインデックス                     */
/*          tpu1SubIdx   サブインデックス                       */
/* 戻り値 : なし                                                */
/* 概要   : チャネル番号よりユニットとチャネルのインデックス    */
/*          を特定する                                          */
/* 制約   : なし                                                */
/*          処理速度優先とするためインライン関数とする          */
/* ============================================================ */
#pragma inline (FnVD_HwPph_Cmt_getIdx)
static VD FnVD_HwPph_Cmt_getIdx(EN_HwPph_Cmt_Unit tenUnit, U1 * tpu1MainIdx, U1 * tpu1SubIdx)
{
  *tpu1MainIdx = (U1)tenUnit / (U1)2;
  *tpu1SubIdx  = (U1)tenUnit % (U1)2;
}


/* ============================================================ */
/* 関数名 : FnVD_HwPph_Cmt_enbStpModuleSetting                  */
/*          モジュール停止制御レジスタ保護解除                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : モジュール停止制御レジスタの保護を解除する          */
/* 制約   : 割り込み禁止中に実行すること                        */
/* ============================================================ */
#pragma inline (FnVD_HwPph_Cmt_enbStpModuleSetting)
static VD FnVD_HwPph_Cmt_enbStpModuleSetting(VD)
{
  ST_PRCR tstPRCR;

  tstPRCR.u2Val = stRegSys0.stPRCR.u2Val;
  tstPRCR.stBit.b1PRC1 = (U2)1;
  tstPRCR.stBit.b8PRKEY = CU2_HwPph_Cmt_ProtectKey;
  stRegSys0.stPRCR.u2Val = tstPRCR.u2Val;
}


/* ============================================================ */
/* 関数名 : FnVD_HwPph_Cmt_dibStpModuleSetting                  */
/*          モジュール停止制御レジスタ保護                      */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : モジュール停止制御レジスタの保護する                */
/* 制約   : 割り込み禁止中に実行すること                        */
/* ============================================================ */
#pragma inline (FnVD_HwPph_Cmt_dibStpModuleSetting)
static VD FnVD_HwPph_Cmt_dibStpModuleSetting(VD)
{
  ST_PRCR tstPRCR;

  tstPRCR.u2Val = stRegSys0.stPRCR.u2Val;
  tstPRCR.stBit.b1PRC1 = (U2)0;
  tstPRCR.stBit.b8PRKEY = CU2_HwPph_Cmt_ProtectKey;
  stRegSys0.stPRCR.u2Val = tstPRCR.u2Val;
}


/* ============================================================ */
/* 関数名 : FnVD_HwPph_Cmt_resetModuleStp                       */
/*          モジュール停止制御レジスタ解除設定                  */
/* 引数   : tenUnit  ユニット番号                               */
/* 戻り値 : なし                                                */
/* 概要   : モジュール停止を解除する                            */
/* 制約   : 割り込み禁止中に実行すること                        */
/* ============================================================ */
VD FnVD_HwPph_Cmt_resetModuleStp(EN_HwPph_Cmt_Unit tenUnit)
{
  ST_MSTPCRA tstMSTPCRA;
  U1         tu1MainIdx;
  U1         tu1SubIdx;

  /* インデックス取得 */
  FnVD_HwPph_Cmt_getIdx(tenUnit, &tu1MainIdx, &tu1SubIdx);

  /* 保護解除 */
  FnVD_HwPph_Cmt_enbStpModuleSetting();

  /* モジュールストップコントロールレジスタ設定(解除) */
  tstMSTPCRA.u4Val = (U4)0xFFFFFFFF;
  if (tu1MainIdx == (U1)0) {
    /* CMT0-1 */
    tstMSTPCRA.stBit.b1MSTPA15 = CU4_HwPph_Cmt_MSTPCR_MSTP_Reset;
  }
  else {
    /* CMT2-3 */
    tstMSTPCRA.stBit.b1MSTPA14 = CU4_HwPph_Cmt_MSTPCR_MSTP_Reset;
  }
  stRegSys0.stMSTPCRA.u4Val &= tstMSTPCRA.u4Val;

  /* 保護 */
  FnVD_HwPph_Cmt_dibStpModuleSetting();
}


/* ============================================================ */
/* 関数名 : FnVD_HwPph_Cmt_stpModuleStp                         */
/*          モジュール停止制御レジスタ遷移設定                  */
/* 引数   : tenUnit  ユニット番号                               */
/* 戻り値 : なし                                                */
/* 概要   : モジュール停止へ遷移する                            */
/* 制約   : 割り込み禁止中に実行すること                        */
/* ============================================================ */
VD FnVD_HwPph_Cmt_stpModuleStp(EN_HwPph_Cmt_Unit tenUnit)
{
  ST_MSTPCRA tstMSTPCRA;
  U1         tu1MainIdx;
  U1         tu1SubIdx;

  /* インデックス取得 */
  FnVD_HwPph_Cmt_getIdx(tenUnit, &tu1MainIdx, &tu1SubIdx);

  /* 保護解除 */
  FnVD_HwPph_Cmt_enbStpModuleSetting();

  /* モジュールストップコントロールレジスタ設定(解除) */
  tstMSTPCRA.u4Val = (U4)0x00000000;
  if (tu1MainIdx == (U1)0) {
    /* CMT0-1 */
    tstMSTPCRA.stBit.b1MSTPA15 = CU4_HwPph_Cmt_MSTPCR_MSTP_Stp;
  }
  else {
    /* CMT2-3 */
    tstMSTPCRA.stBit.b1MSTPA14 = CU4_HwPph_Cmt_MSTPCR_MSTP_Stp;
  }
  stRegSys0.stMSTPCRA.u4Val |= tstMSTPCRA.u4Val;

  /* 保護 */
  FnVD_HwPph_Cmt_dibStpModuleSetting();
}


/* ============================================================ */
/* 関数名 : FnVD_HwPph_Cmt_stpCnt                               */
/*          CMTカウント動作停止                                 */
/* 引数   : tenUnit  ユニット番号                               */
/* 戻り値 : なし                                                */
/* 概要   : カウント動作を停止する                              */
/* 制約   : 割り込み禁止中に実行すること                        */
/* ============================================================ */
VD FnVD_HwPph_Cmt_stpCnt(EN_HwPph_Cmt_Unit tenUnit)
{
  ST_CMSTRi tstCMSTRi;
  U1        tu1MainIdx;
  U1        tu1SubIdx;

  /* インデックス取得 */
  FnVD_HwPph_Cmt_getIdx(tenUnit, &tu1MainIdx, &tu1SubIdx);

  /* タイマ停止 */
  tstCMSTRi.u2Val = staRegCMTm[tu1MainIdx].stCMSTR.u2Val;
  tstCMSTRi.u2Val &= (U2)~((U2)1 << tu1SubIdx);
  staRegCMTm[tu1MainIdx].stCMSTR.u2Val = tstCMSTRi.u2Val;
}


/* ============================================================ */
/* 関数名 : FnVD_HwPph_Cmt_staCnt                               */
/*          CMTカウント動作開始                                 */
/* 引数   : tenUnit  ユニット番号                               */
/* 戻り値 : なし                                                */
/* 概要   : カウント動作を停止する                              */
/* 制約   : 割り込み禁止中に実行すること                        */
/* ============================================================ */
VD FnVD_HwPph_Cmt_staCnt(EN_HwPph_Cmt_Unit tenUnit)
{
  ST_CMSTRi tstCMSTRi;
  U1        tu1MainIdx;
  U1        tu1SubIdx;

  /* インデックス取得 */
  FnVD_HwPph_Cmt_getIdx(tenUnit, &tu1MainIdx, &tu1SubIdx);

  /* タイマ起動 */
  tstCMSTRi.u2Val = staRegCMTm[tu1MainIdx].stCMSTR.u2Val;
  tstCMSTRi.u2Val |= (U2)((U2)1 << tu1SubIdx);
  staRegCMTm[tu1MainIdx].stCMSTR.u2Val = tstCMSTRi.u2Val;
}


/* ============================================================ */
/* 関数名 : FnVD_HwPph_Cmt_clrCnt                               */
/*          CMTカウンタクリア                                   */
/* 引数   : tenUnit  ユニット番号                               */
/* 戻り値 : なし                                                */
/* 概要   : カウンタをクリアする                                */
/* 制約   : 割り込み禁止中に実行すること                        */
/*          カウンタ動作停止中に実行すること                    */
/* ============================================================ */
VD FnVD_HwPph_Cmt_clrCnt(EN_HwPph_Cmt_Unit tenUnit)
{
  U1 tu1MainIdx;
  U1 tu1SubIdx;

  /* インデックス取得 */
  FnVD_HwPph_Cmt_getIdx(tenUnit, &tu1MainIdx, &tu1SubIdx);

  /* コンペアマッチタイマカウンタクリア */
  staRegCMTm[tu1MainIdx].staCM[tu1SubIdx].stCMCNT.u2Val = (U2)0x0000;
}


/* ============================================================ */
/* 関数名 : FnVD_HwPph_Cmt_setCnt                               */
/*          CMTカウンタ設定                                     */
/* 引数   : tenUnit  ユニット番号                               */
/*          tu2Val   カウンタ設定値                             */
/* 戻り値 : なし                                                */
/* 概要   : カウンタ値を設定する                                */
/* 制約   : 割り込み禁止中に実行すること                        */
/*          カウンタ動作停止中に実行すること                    */
/* ============================================================ */
VD FnVD_HwPph_Cmt_setCnt(EN_HwPph_Cmt_Unit tenUnit, U2 tu2Val)
{
  U1 tu1MainIdx;
  U1 tu1SubIdx;

  /* インデックス取得 */
  FnVD_HwPph_Cmt_getIdx(tenUnit, &tu1MainIdx, &tu1SubIdx);

  /* コンペアマッチタイマカウンタクリア */
  staRegCMTm[tu1MainIdx].staCM[tu1SubIdx].stCMCNT.u2Val = tu2Val;
}


/* ============================================================ */
/* 関数名 : FnU2_HwPph_Cmt_getCnt                               */
/*          CMTカウンタ値取得                                   */
/* 引数   : tenUnit  ユニット番号                               */
/* 戻り値 : カウンタ値                                          */
/* 概要   : カウンタ値を設定する                                */
/* 制約   : 割り込み禁止中に実行すること                        */
/*          カウンタ動作停止中に実行すること                    */
/* ============================================================ */
U2 FnU2_HwPph_Cmt_getCnt(EN_HwPph_Cmt_Unit tenUnit)
{
  U2 tu2Ret;
  U1 tu1MainIdx;
  U1 tu1SubIdx;

  /* インデックス取得 */
  FnVD_HwPph_Cmt_getIdx(tenUnit, &tu1MainIdx, &tu1SubIdx);

  /* コンペアマッチタイマカウンタクリア */
  tu2Ret = staRegCMTm[tu1MainIdx].staCM[tu1SubIdx].stCMCNT.u2Val;

  return (tu2Ret);
}


/* ============================================================ */
/* 関数名 : FnVD_HwPph_Cmt_setCompareValue                      */
/*          CMTカウンタコンペア値設定                           */
/* 引数   : tenUnit  ユニット番号                               */
/*          tu2Val   コンペア設定値                             */
/* 戻り値 : なし                                                */
/* 概要   : コンペア値を設定する                                */
/* 制約   : 割り込み禁止中に実行すること                        */
/*          カウンタ動作停止中に実行すること                    */
/* ============================================================ */
VD FnVD_HwPph_Cmt_setCompareValue(EN_HwPph_Cmt_Unit tenUnit, U2 tu2Val)
{
  U1 tu1MainIdx;
  U1 tu1SubIdx;

  /* インデックス取得 */
  FnVD_HwPph_Cmt_getIdx(tenUnit, &tu1MainIdx, &tu1SubIdx);

  /* コンペアマッチタイマカウンタクリア */
  staRegCMTm[tu1MainIdx].staCM[tu1SubIdx].stCMCOR.u2Val = tu2Val;
}


/* ============================================================ */
/* 関数名 : FnVD_HwPph_Cmt_cfg                                  */
/*          CMT機能設定                                         */
/* 引数   : tenUnit  ユニット番号                               */
/*          tpstCfg  コンフィグデータ                           */
/* 戻り値 : なし                                                */
/* 概要   : CMT機能設定を行う                                   */
/* 制約   : 割り込み禁止中に実行すること                        */
/*          チャネル単位でスタートアップにて1回のみ実行すること */
/* ============================================================ */
VD FnVD_HwPph_Cmt_cfg(EN_HwPph_Cmt_Unit tenUnit, const ST_HwPph_Cmt_Cfg * tpstCfg)
{
  ST_CMSTRi tstCMSTRi;
  ST_CMCR   tstCMCR;
  U1        tu1MainIdx;
  U1        tu1SubIdx;

  /* インデックス取得 */
  FnVD_HwPph_Cmt_getIdx(tenUnit, &tu1MainIdx, &tu1SubIdx);

  /* タイマ停止 */
  tstCMSTRi.u2Val = staRegCMTm[tu1MainIdx].stCMSTR.u2Val;
  tstCMSTRi.u2Val &= (U2)~((U2)1 << tu1SubIdx);
  staRegCMTm[tu1MainIdx].stCMSTR.u2Val = tstCMSTRi.u2Val;

  /* コンペアマッチタイマコントロールレジスタ設定 */
  tstCMCR.u2Val = (U2)0x0000;
  tstCMCR.stBit.b2CKS  = (U2)tpstCfg->enSelClk;
  tstCMCR.stBit.b1CMIE = (U2)tpstCfg->u1IntEnb;
  tstCMCR.stBit.b1Fix0 = CU2_HwPph_Cmt_CMCR_Fix0;
  staRegCMTm[tu1MainIdx].staCM[tu1SubIdx].stCMCR.u2Val = tstCMCR.u2Val;

  /* コンペアマッチタイマカウンタクリア */
  staRegCMTm[tu1MainIdx].staCM[tu1SubIdx].stCMCNT.u2Val = (U2)0x0000;

  /* コンペアマッチタイマコンスタントレジスタ設定 */
  staRegCMTm[tu1MainIdx].staCM[tu1SubIdx].stCMCOR.u2Val = tpstCfg->u2Compare;
}

