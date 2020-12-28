/* ============================================================ */
/* ファイル名 : hw_pph_port.c                                   */
/* 機能       : ポート処理                                      */
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
#include "hw_pph_port_pac.h"


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */
#define CU1_HwPph_Port_MskBit0    ((U1)0x01)


/* ============================================================ */
/* 型定義                                                       */
/* ============================================================ */
typedef union {
  U2 u2Val;
  struct {
    U1 u1Pin;
    U1 u1Grp;
  } stNum;
} ST_HwPph_Port_IdConv;


/* ============================================================ */
/* 関数プロトタイプ宣言(static)                                 */
/* ============================================================ */
static VD FnVD_HwPph_Port_getNumGrpPin(EN_HwPph_Port_Id tenId, U1 * tpu1GrpNum, U1 * tpu1PinNum); /* Note:inline */
static U1 FnU1_HwPph_Port_createPinMsk(U1 tu1PinNum); /* Note:inline */
static VD FnVD_HwPph_Port_cfgRegPORTn(volatile U1 __evenaccess * tpu1Reg, U1 tu1Req, U1 tu1Msk); /* Note:inline */
static VD FnVD_HwPph_Port_enbPFS(VD); /* Note:inline */
static VD FnVD_HwPph_Port_dibPFS(VD); /* Note:inline */


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
/* 関数名 : FnVD_HwPph_Port_getNumGrpPin                        */
/*          ポートグループ/ピン番号取得                         */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : ポート識別IDよりグループとピンを特定する            */
/* 制約   : なし                                                */
/*          処理速度優先とするためインライン関数とする          */
/* ============================================================ */
#pragma inline (FnVD_HwPph_Port_getNumGrpPin)
static VD FnVD_HwPph_Port_getNumGrpPin(EN_HwPph_Port_Id tenId, U1 * tpu1GrpNum, U1 * tpu1PinNum)
{
  ST_HwPph_Port_IdConv tstId;

  tstId.u2Val = (U2)tenId;
  *tpu1GrpNum = tstId.stNum.u1Pin;
  *tpu1PinNum = tstId.stNum.u1Grp;
}


/* ============================================================ */
/* 関数名 : FnU1_HwPph_Port_createPinMsk                        */
/*          ピン位置マスク生成                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 該当ピンのマスク値を生成する                        */
/* 制約   : なし                                                */
/*          処理速度優先とするためインライン関数とする          */
/* ============================================================ */
#pragma inline (FnU1_HwPph_Port_createPinMsk)
static U1 FnU1_HwPph_Port_createPinMsk(U1 tu1PinNum)
{
  U1 tu1Ret;

  tu1Ret = (U1)((U1)1 << tu1PinNum);

  return (tu1Ret);
}


/* ============================================================ */
/* 関数名 : FnVD_HwPph_Port_cfgRegPORTn                         */
/*          ポート機能設定(PORTn)                               */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : PORTn関連レジスタ設定処理                           */
/* 制約   : 割り込み禁止中に実行すること                        */
/*          処理速度優先とするためインライン関数とする          */
/* ============================================================ */
#pragma inline (FnVD_HwPph_Port_cfgRegPORTn)
static VD FnVD_HwPph_Port_cfgRegPORTn(volatile U1 __evenaccess * tpu1Reg, U1 tu1Req, U1 tu1Msk)
{
  U1 tu1Val;

  tu1Val = *tpu1Reg;
  if (tu1Req == (U1)C_OFF) {
    tu1Val &= (U1)~tu1Msk;
  }
  else {
    tu1Val |= tu1Msk;
  }
  *tpu1Reg = tu1Val;  
}


/* ============================================================ */
/* 関数名 : FnVD_HwPph_Port_enbPFS                              */
/*          PmnPFSレジスタ書き込み許可処理                      */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : PmnPFSレジスタの書き込み保護を解除する              */
/* 制約   : 割り込み禁止中に実行すること                        */
/*          処理速度優先とするためインライン関数とする          */
/* ============================================================ */
#pragma inline (FnVD_HwPph_Port_enbPFS)
static VD FnVD_HwPph_Port_enbPFS(VD)
{
  ST_PWPR tstPWPR;

  tstPWPR.u1Val = stRegMPC.stPWPR.u1Val;

  /* PFSWEビットを書き込み許可にする */
  tstPWPR.stBit.b1B0WI = (U1)C_OFF;
  stRegMPC.stPWPR.u1Val = tstPWPR.u1Val;

  /* PmnPFSレジスタを書き込み許可にする */
  tstPWPR.stBit.b1PFSWE = (U1)C_ON;
  stRegMPC.stPWPR.u1Val = tstPWPR.u1Val;
}


/* ============================================================ */
/* 関数名 : FnVD_HwPph_Port_dibPFS                              */
/*          PmnPFSレジスタ書き込み禁止処理                      */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : PmnPFSレジスタの書き込み保護する                    */
/* 制約   : 割り込み禁止中に実行すること                        */
/*          処理速度優先とするためインライン関数とする          */
/* ============================================================ */
#pragma inline (FnVD_HwPph_Port_dibPFS)
static VD FnVD_HwPph_Port_dibPFS(VD)
{
  ST_PWPR tstPWPR;

  tstPWPR.u1Val = stRegMPC.stPWPR.u1Val;

  /* PmnPFSレジスタを書き込み禁止にする */
  tstPWPR.stBit.b1PFSWE = (U1)C_OFF;
  stRegMPC.stPWPR.u1Val = tstPWPR.u1Val;

  /* PFSWEビットを書き込み禁止にする */
  tstPWPR.stBit.b1B0WI = (U1)C_ON;
  stRegMPC.stPWPR.u1Val = tstPWPR.u1Val;
}


/* ============================================================ */
/* 関数名 : FnVD_HwPph_Port_initForStartup                      */
/*          ポート初期化(スタートアップ用)                      */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : ハード初期値に頼らずソフトにて初期値設定を行う      */
/* 制約   : 割り込み禁止中に実行すること                        */
/* ============================================================ */
VD FnVD_HwPph_Port_initForStartup(VD)
{
  ST_PCR  tstPCR;  /* プルアップ制御レジスタ */
  ST_PDR  tstPDR;  /* ポート方向レジスタ */
  ST_PMR  tstPMR;  /* ポートモードレジスタ */
#if 1 /* 64ピンパッケージ限定 */
  ST_PSRA tstPSRA; /* ポート切り替えレジスタA */
#endif

  /* Memo:不要な信号を出力させないようにするため全てのGPIOを汎用入力ポートモードに設定する(PCR, PDR, PMRの順に設定する) */
#if 1 /* 64ピン */
  /* P0 */ /* idx = 0 */
  tstPCR.u1Val = stRegPORTm.staPCR[0].u1Val;
  tstPCR.stBit.b1B5 = (U1)0;
  stRegPORTm.staPCR[0].u1Val = tstPCR.u1Val;

  tstPDR.u1Val = stRegPORTm.staPDR[0].u1Val;
  tstPDR.stBit.b1B5 = (U1)0;
  stRegPORTm.staPDR[0].u1Val = tstPDR.u1Val;

  tstPMR.u1Val = stRegPORTm.staPMR[0].u1Val;
  tstPMR.stBit.b1B5 = (U1)0;
  stRegPORTm.staPMR[0].u1Val = tstPMR.u1Val;

  /* P1 */ /* idx = 1 */
  tstPCR.u1Val = stRegPORTm.staPCR[1].u1Val;
  tstPCR.stBit.b1B4 = (U1)0;
  tstPCR.stBit.b1B5 = (U1)0;
  tstPCR.stBit.b1B6 = (U1)0;
  tstPCR.stBit.b1B7 = (U1)0;
  stRegPORTm.staPCR[1].u1Val = tstPCR.u1Val;

  tstPDR.u1Val = stRegPORTm.staPDR[1].u1Val;
  tstPDR.stBit.b1B4 = (U1)0;
  tstPDR.stBit.b1B5 = (U1)0;
  tstPDR.stBit.b1B6 = (U1)0;
  tstPDR.stBit.b1B7 = (U1)0;
  stRegPORTm.staPDR[1].u1Val = tstPDR.u1Val;

  tstPMR.u1Val = stRegPORTm.staPMR[1].u1Val;
  tstPMR.stBit.b1B4 = (U1)0;
  tstPMR.stBit.b1B5 = (U1)0;
  tstPMR.stBit.b1B6 = (U1)0;
  tstPMR.stBit.b1B7 = (U1)0;
  stRegPORTm.staPMR[1].u1Val = tstPMR.u1Val;

  /* P2 */ /* idx = 2 */
  tstPCR.u1Val = stRegPORTm.staPCR[2].u1Val;
  tstPCR.stBit.b1B6 = (U1)0;
  tstPCR.stBit.b1B7 = (U1)0;
  stRegPORTm.staPCR[2].u1Val = tstPCR.u1Val;

  tstPDR.u1Val = stRegPORTm.staPDR[2].u1Val;
  tstPDR.stBit.b1B6 = (U1)0;
  tstPDR.stBit.b1B7 = (U1)0;
  stRegPORTm.staPDR[2].u1Val = tstPDR.u1Val;

  tstPMR.u1Val = stRegPORTm.staPMR[2].u1Val;
  tstPMR.stBit.b1B6 = (U1)0;
  tstPMR.stBit.b1B7 = (U1)0;
  stRegPORTm.staPMR[2].u1Val = tstPMR.u1Val;

  /* P3 */ /* idx = 3 */
  tstPCR.u1Val = stRegPORTm.staPCR[3].u1Val;
  tstPCR.stBit.b1B0 = (U1)0;
  tstPCR.stBit.b1B1 = (U1)0;
  tstPCR.stBit.b1B5 = (U1)0;
  stRegPORTm.staPCR[3].u1Val = tstPCR.u1Val;

  tstPDR.u1Val = stRegPORTm.staPDR[3].u1Val;
  tstPDR.stBit.b1B0 = (U1)0;
  tstPDR.stBit.b1B1 = (U1)0;
  tstPDR.stBit.b1B5 = (U1)0;
  stRegPORTm.staPDR[3].u1Val = tstPDR.u1Val;

  tstPMR.u1Val = stRegPORTm.staPMR[3].u1Val;
  tstPMR.stBit.b1B0 = (U1)0;
  tstPMR.stBit.b1B1 = (U1)0;
  tstPMR.stBit.b1B5 = (U1)0;
  stRegPORTm.staPMR[3].u1Val = tstPMR.u1Val;

  /* P4 */ /* idx = 4 */
  tstPCR.u1Val = stRegPORTm.staPCR[4].u1Val;
  tstPCR.stBit.b1B0 = (U1)0;
  tstPCR.stBit.b1B1 = (U1)0;
  tstPCR.stBit.b1B2 = (U1)0;
  tstPCR.stBit.b1B3 = (U1)0;
  tstPCR.stBit.b1B4 = (U1)0;
  tstPCR.stBit.b1B6 = (U1)0;
  stRegPORTm.staPCR[4].u1Val = tstPCR.u1Val;

  tstPDR.u1Val = stRegPORTm.staPDR[4].u1Val;
  tstPDR.stBit.b1B0 = (U1)0;
  tstPDR.stBit.b1B1 = (U1)0;
  tstPDR.stBit.b1B2 = (U1)0;
  tstPDR.stBit.b1B3 = (U1)0;
  tstPDR.stBit.b1B4 = (U1)0;
  tstPDR.stBit.b1B6 = (U1)0;
  stRegPORTm.staPDR[4].u1Val = tstPDR.u1Val;

  tstPMR.u1Val = stRegPORTm.staPMR[4].u1Val;
  tstPMR.stBit.b1B0 = (U1)0;
  tstPMR.stBit.b1B1 = (U1)0;
  tstPMR.stBit.b1B2 = (U1)0;
  tstPMR.stBit.b1B3 = (U1)0;
  tstPMR.stBit.b1B4 = (U1)0;
  tstPMR.stBit.b1B6 = (U1)0;
  stRegPORTm.staPMR[4].u1Val = tstPMR.u1Val;

  /* P5 */ /* idx = 5 */
  tstPCR.u1Val = stRegPORTm.staPCR[5].u1Val;
  tstPCR.stBit.b1B4 = (U1)0;
  tstPCR.stBit.b1B5 = (U1)0;
  stRegPORTm.staPCR[5].u1Val = tstPCR.u1Val;

  tstPDR.u1Val = stRegPORTm.staPDR[5].u1Val;
  tstPDR.stBit.b1B4 = (U1)0;
  tstPDR.stBit.b1B5 = (U1)0;
  stRegPORTm.staPDR[5].u1Val = tstPDR.u1Val;

  tstPMR.u1Val = stRegPORTm.staPMR[5].u1Val;
  tstPMR.stBit.b1B4 = (U1)0;
  tstPMR.stBit.b1B5 = (U1)0;
  stRegPORTm.staPMR[5].u1Val = tstPMR.u1Val;

  /* P6 */ /* idx = 6 */
  /* 64Pinは無し */

  /* P7 */ /* idx = 7 */
  /* 64Pinは無し */

  /* P8 */ /* idx = 8 */
  /* 64Pinは無し */

  /* P9 */ /* idx = 9 */
  /* 64Pinは無し */

  /* PA */ /* idx = 10 */
  tstPCR.u1Val = stRegPORTm.staPCR[10].u1Val;
  tstPCR.stBit.b1B0 = (U1)0;
  tstPCR.stBit.b1B1 = (U1)0;
  tstPCR.stBit.b1B3 = (U1)0;
  tstPCR.stBit.b1B4 = (U1)0;
  tstPCR.stBit.b1B6 = (U1)0;
  stRegPORTm.staPCR[10].u1Val = tstPCR.u1Val;

  tstPDR.u1Val = stRegPORTm.staPDR[10].u1Val;
  tstPDR.stBit.b1B0 = (U1)0;
  tstPDR.stBit.b1B1 = (U1)0;
  tstPDR.stBit.b1B3 = (U1)0;
  tstPDR.stBit.b1B4 = (U1)0;
  tstPDR.stBit.b1B6 = (U1)0;
  stRegPORTm.staPDR[10].u1Val = tstPDR.u1Val;

  tstPMR.u1Val = stRegPORTm.staPMR[10].u1Val;
  tstPMR.stBit.b1B0 = (U1)0;
  tstPMR.stBit.b1B1 = (U1)0;
  tstPMR.stBit.b1B3 = (U1)0;
  tstPMR.stBit.b1B4 = (U1)0;
  tstPMR.stBit.b1B6 = (U1)0;
  stRegPORTm.staPMR[10].u1Val = tstPMR.u1Val;

  /* PB */ /* idx = 11 */
  tstPCR.u1Val = stRegPORTm.staPCR[11].u1Val;
  tstPCR.stBit.b1B0 = (U1)0;
  tstPCR.stBit.b1B1 = (U1)0;
  tstPCR.stBit.b1B3 = (U1)0;
  tstPCR.stBit.b1B5 = (U1)0;
  tstPCR.stBit.b1B6 = (U1)0;  /* PSRA = 0 */
  tstPCR.stBit.b1B7 = (U1)0;  /* PSRA = 0 */
  stRegPORTm.staPCR[11].u1Val = tstPCR.u1Val;

  tstPDR.u1Val = stRegPORTm.staPDR[11].u1Val;
  tstPDR.stBit.b1B0 = (U1)0;
  tstPDR.stBit.b1B1 = (U1)0;
  tstPDR.stBit.b1B3 = (U1)0;
  tstPDR.stBit.b1B5 = (U1)0;
  tstPDR.stBit.b1B6 = (U1)0;  /* PSRA = 0 */
  tstPDR.stBit.b1B7 = (U1)0;  /* PSRA = 0 */
  stRegPORTm.staPDR[11].u1Val = tstPDR.u1Val;

  tstPMR.u1Val = stRegPORTm.staPMR[11].u1Val;
  tstPMR.stBit.b1B0 = (U1)0;
  tstPMR.stBit.b1B1 = (U1)0;
  tstPMR.stBit.b1B3 = (U1)0;
  tstPMR.stBit.b1B5 = (U1)0;
  tstPMR.stBit.b1B6 = (U1)0;  /* PSRA = 0 */
  tstPMR.stBit.b1B7 = (U1)0;  /* PSRA = 0 */
  stRegPORTm.staPMR[11].u1Val = tstPMR.u1Val;

  /* PC */ /* idx = 12 */
  tstPCR.u1Val = stRegPORTm.staPCR[12].u1Val;
  tstPCR.stBit.b1B0 = (U1)0;  /* PSRA = 1 */
  tstPCR.stBit.b1B1 = (U1)0;  /* PSRA = 1 */
  tstPCR.stBit.b1B2 = (U1)0;
  tstPCR.stBit.b1B3 = (U1)0;
  tstPCR.stBit.b1B4 = (U1)0;
  tstPCR.stBit.b1B5 = (U1)0;
  tstPCR.stBit.b1B6 = (U1)0;
  tstPCR.stBit.b1B7 = (U1)0;
  stRegPORTm.staPCR[12].u1Val = tstPCR.u1Val;

  tstPDR.u1Val = stRegPORTm.staPDR[12].u1Val;
  tstPDR.stBit.b1B0 = (U1)0;  /* PSRA = 1 */
  tstPDR.stBit.b1B1 = (U1)0;  /* PSRA = 1 */
  tstPDR.stBit.b1B2 = (U1)0;
  tstPDR.stBit.b1B3 = (U1)0;
  tstPDR.stBit.b1B4 = (U1)0;
  tstPDR.stBit.b1B5 = (U1)0;
  tstPDR.stBit.b1B6 = (U1)0;
  tstPDR.stBit.b1B7 = (U1)0;
  stRegPORTm.staPDR[12].u1Val = tstPDR.u1Val;

  tstPMR.u1Val = stRegPORTm.staPMR[12].u1Val;
  tstPMR.stBit.b1B0 = (U1)0;  /* PSRA = 1 */
  tstPMR.stBit.b1B1 = (U1)0;  /* PSRA = 1 */
  tstPMR.stBit.b1B2 = (U1)0;
  tstPMR.stBit.b1B3 = (U1)0;
  tstPMR.stBit.b1B4 = (U1)0;
  tstPMR.stBit.b1B5 = (U1)0;
  tstPMR.stBit.b1B6 = (U1)0;
  tstPMR.stBit.b1B7 = (U1)0;
  stRegPORTm.staPMR[12].u1Val = tstPMR.u1Val;

  /* PD */ /* idx = 13 */
  /* 64Pinは無し */

  /* PE */ /* idx = 14 */
  tstPCR.u1Val = stRegPORTm.staPCR[14].u1Val;
  tstPCR.stBit.b1B0 = (U1)0;
  tstPCR.stBit.b1B1 = (U1)0;
  tstPCR.stBit.b1B2 = (U1)0;
  tstPCR.stBit.b1B3 = (U1)0;
  tstPCR.stBit.b1B4 = (U1)0;
  tstPCR.stBit.b1B5 = (U1)0;
  stRegPORTm.staPCR[14].u1Val = tstPCR.u1Val;

  tstPDR.u1Val = stRegPORTm.staPDR[14].u1Val;
  tstPDR.stBit.b1B0 = (U1)0;
  tstPDR.stBit.b1B1 = (U1)0;
  tstPDR.stBit.b1B2 = (U1)0;
  tstPDR.stBit.b1B3 = (U1)0;
  tstPDR.stBit.b1B4 = (U1)0;
  tstPDR.stBit.b1B5 = (U1)0;
  stRegPORTm.staPDR[14].u1Val = tstPDR.u1Val;

  tstPMR.u1Val = stRegPORTm.staPMR[14].u1Val;
  tstPMR.stBit.b1B0 = (U1)0;
  tstPMR.stBit.b1B1 = (U1)0;
  tstPMR.stBit.b1B2 = (U1)0;
  tstPMR.stBit.b1B3 = (U1)0;
  tstPMR.stBit.b1B4 = (U1)0;
  tstPMR.stBit.b1B5 = (U1)0;
  stRegPORTm.staPMR[14].u1Val = tstPMR.u1Val;

  /* PF */ /* idx = 15 */
  /* 64Pinは無し */

  /* PG */ /* idx = 16 */
  /* 64Pinは無し */

  /* PH, PIはUMにも記載なし */

  /* PJ */ /* idx = 18 */
  /* 64Pinは無し */

  /* PSRA */
  tstPSRA.u1Val = stRegPORT.stPSRA.u1Val;
  tstPSRA.stBit.b1PSEL6 = (U1)0;
  tstPSRA.stBit.b1PSEL7 = (U1)0;
  stRegPORT.stPSRA.u1Val = tstPSRA.u1Val;
#endif
}


/* ============================================================ */
/* 関数名 : FnVD_HwPph_Port_initToKill                          */
/*          ポート初期化(システム停止用)                        */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : システム停止時に行うポート設定                      */
/* 制約   : 割り込み禁止中に実行すること                        */
/* ============================================================ */
VD FnVD_HwPph_Port_initToKill(VD)
{
  ST_PDR  tstPDR;  /* ポート方向レジスタ */
  ST_PMR  tstPMR;  /* ポートモードレジスタ */

  /* Memo:不要な信号を出力させないようにするため全てのGPIOを汎用入力ポートモードに設定する(PDR, PMRの順に設定する) */
#if 1 /* 64ピン */
  /* P0 */ /* idx = 0 */
  tstPDR.u1Val = stRegPORTm.staPDR[0].u1Val;
  tstPDR.stBit.b1B5 = (U1)0;
  stRegPORTm.staPDR[0].u1Val = tstPDR.u1Val;

  tstPMR.u1Val = stRegPORTm.staPMR[0].u1Val;
  tstPMR.stBit.b1B5 = (U1)0;
  stRegPORTm.staPMR[0].u1Val = tstPMR.u1Val;

  /* P1 */ /* idx = 1 */
  tstPDR.u1Val = stRegPORTm.staPDR[1].u1Val;
  tstPDR.stBit.b1B4 = (U1)0;
  tstPDR.stBit.b1B5 = (U1)0;
  tstPDR.stBit.b1B6 = (U1)0;
  tstPDR.stBit.b1B7 = (U1)0;
  stRegPORTm.staPDR[1].u1Val = tstPDR.u1Val;

  tstPMR.u1Val = stRegPORTm.staPMR[1].u1Val;
  tstPMR.stBit.b1B4 = (U1)0;
  tstPMR.stBit.b1B5 = (U1)0;
  tstPMR.stBit.b1B6 = (U1)0;
  tstPMR.stBit.b1B7 = (U1)0;
  stRegPORTm.staPMR[1].u1Val = tstPMR.u1Val;

  /* P2 */ /* idx = 2 */
  tstPDR.u1Val = stRegPORTm.staPDR[2].u1Val;
  tstPDR.stBit.b1B6 = (U1)0;
  tstPDR.stBit.b1B7 = (U1)0;
  stRegPORTm.staPDR[2].u1Val = tstPDR.u1Val;

  tstPMR.u1Val = stRegPORTm.staPMR[2].u1Val;
  tstPMR.stBit.b1B6 = (U1)0;
  tstPMR.stBit.b1B7 = (U1)0;
  stRegPORTm.staPMR[2].u1Val = tstPMR.u1Val;

  /* P3 */ /* idx = 3 */
  tstPDR.u1Val = stRegPORTm.staPDR[3].u1Val;
  tstPDR.stBit.b1B0 = (U1)0;
  tstPDR.stBit.b1B1 = (U1)0;
  tstPDR.stBit.b1B5 = (U1)0;
  stRegPORTm.staPDR[3].u1Val = tstPDR.u1Val;

  tstPMR.u1Val = stRegPORTm.staPMR[3].u1Val;
  tstPMR.stBit.b1B0 = (U1)0;
  tstPMR.stBit.b1B1 = (U1)0;
  tstPMR.stBit.b1B5 = (U1)0;
  stRegPORTm.staPMR[3].u1Val = tstPMR.u1Val;

  /* P4 */ /* idx = 4 */
  tstPDR.u1Val = stRegPORTm.staPDR[4].u1Val;
  tstPDR.stBit.b1B0 = (U1)0;
  tstPDR.stBit.b1B1 = (U1)0;
  tstPDR.stBit.b1B2 = (U1)0;
  tstPDR.stBit.b1B3 = (U1)0;
  tstPDR.stBit.b1B4 = (U1)0;
  tstPDR.stBit.b1B6 = (U1)0;
  stRegPORTm.staPDR[4].u1Val = tstPDR.u1Val;

  tstPMR.u1Val = stRegPORTm.staPMR[4].u1Val;
  tstPMR.stBit.b1B0 = (U1)0;
  tstPMR.stBit.b1B1 = (U1)0;
  tstPMR.stBit.b1B2 = (U1)0;
  tstPMR.stBit.b1B3 = (U1)0;
  tstPMR.stBit.b1B4 = (U1)0;
  tstPMR.stBit.b1B6 = (U1)0;
  stRegPORTm.staPMR[4].u1Val = tstPMR.u1Val;

  /* P5 */ /* idx = 5 */
  tstPDR.u1Val = stRegPORTm.staPDR[5].u1Val;
  tstPDR.stBit.b1B4 = (U1)0;
  tstPDR.stBit.b1B5 = (U1)0;
  stRegPORTm.staPDR[5].u1Val = tstPDR.u1Val;

  tstPMR.u1Val = stRegPORTm.staPMR[5].u1Val;
  tstPMR.stBit.b1B4 = (U1)0;
  tstPMR.stBit.b1B5 = (U1)0;
  stRegPORTm.staPMR[5].u1Val = tstPMR.u1Val;

  /* P6 */ /* idx = 6 */
  /* 64Pinは無し */

  /* P7 */ /* idx = 7 */
  /* 64Pinは無し */

  /* P8 */ /* idx = 8 */
  /* 64Pinは無し */

  /* P9 */ /* idx = 9 */
  /* 64Pinは無し */

  /* PA */ /* idx = 10 */
  tstPDR.u1Val = stRegPORTm.staPDR[10].u1Val;
  tstPDR.stBit.b1B0 = (U1)0;
  tstPDR.stBit.b1B1 = (U1)0;
  tstPDR.stBit.b1B3 = (U1)0;
  tstPDR.stBit.b1B4 = (U1)0;
  tstPDR.stBit.b1B6 = (U1)0;
  stRegPORTm.staPDR[10].u1Val = tstPDR.u1Val;

  tstPMR.u1Val = stRegPORTm.staPMR[10].u1Val;
  tstPMR.stBit.b1B0 = (U1)0;
  tstPMR.stBit.b1B1 = (U1)0;
  tstPMR.stBit.b1B3 = (U1)0;
  tstPMR.stBit.b1B4 = (U1)0;
  tstPMR.stBit.b1B6 = (U1)0;
  stRegPORTm.staPMR[10].u1Val = tstPMR.u1Val;

  /* PB */ /* idx = 11 */
  tstPDR.u1Val = stRegPORTm.staPDR[11].u1Val;
  tstPDR.stBit.b1B0 = (U1)0;
  tstPDR.stBit.b1B1 = (U1)0;
  tstPDR.stBit.b1B3 = (U1)0;
  tstPDR.stBit.b1B5 = (U1)0;
  tstPDR.stBit.b1B6 = (U1)0;  /* PSRA = 0 */
  tstPDR.stBit.b1B7 = (U1)0;  /* PSRA = 0 */
  stRegPORTm.staPDR[11].u1Val = tstPDR.u1Val;

  tstPMR.u1Val = stRegPORTm.staPMR[11].u1Val;
  tstPMR.stBit.b1B0 = (U1)0;
  tstPMR.stBit.b1B1 = (U1)0;
  tstPMR.stBit.b1B3 = (U1)0;
  tstPMR.stBit.b1B5 = (U1)0;
  tstPMR.stBit.b1B6 = (U1)0;  /* PSRA = 0 */
  tstPMR.stBit.b1B7 = (U1)0;  /* PSRA = 0 */
  stRegPORTm.staPMR[11].u1Val = tstPMR.u1Val;

  /* PC */ /* idx = 12 */
  tstPDR.u1Val = stRegPORTm.staPDR[12].u1Val;
  tstPDR.stBit.b1B0 = (U1)0;  /* PSRA = 1 */
  tstPDR.stBit.b1B1 = (U1)0;  /* PSRA = 1 */
  tstPDR.stBit.b1B2 = (U1)0;
  tstPDR.stBit.b1B3 = (U1)0;
  tstPDR.stBit.b1B4 = (U1)0;
  tstPDR.stBit.b1B5 = (U1)0;
  tstPDR.stBit.b1B6 = (U1)0;
  tstPDR.stBit.b1B7 = (U1)0;
  stRegPORTm.staPDR[12].u1Val = tstPDR.u1Val;

  tstPMR.u1Val = stRegPORTm.staPMR[12].u1Val;
  tstPMR.stBit.b1B0 = (U1)0;  /* PSRA = 1 */
  tstPMR.stBit.b1B1 = (U1)0;  /* PSRA = 1 */
  tstPMR.stBit.b1B2 = (U1)0;
  tstPMR.stBit.b1B3 = (U1)0;
  tstPMR.stBit.b1B4 = (U1)0;
  tstPMR.stBit.b1B5 = (U1)0;
  tstPMR.stBit.b1B6 = (U1)0;
  tstPMR.stBit.b1B7 = (U1)0;
  stRegPORTm.staPMR[12].u1Val = tstPMR.u1Val;

  /* PD */ /* idx = 13 */
  /* 64Pinは無し */

  /* PE */ /* idx = 14 */
  tstPDR.u1Val = stRegPORTm.staPDR[14].u1Val;
  tstPDR.stBit.b1B0 = (U1)0;
  tstPDR.stBit.b1B1 = (U1)0;
  tstPDR.stBit.b1B2 = (U1)0;
  tstPDR.stBit.b1B3 = (U1)0;
  tstPDR.stBit.b1B4 = (U1)0;
  tstPDR.stBit.b1B5 = (U1)0;
  stRegPORTm.staPDR[14].u1Val = tstPDR.u1Val;

  tstPMR.u1Val = stRegPORTm.staPMR[14].u1Val;
  tstPMR.stBit.b1B0 = (U1)0;
  tstPMR.stBit.b1B1 = (U1)0;
  tstPMR.stBit.b1B2 = (U1)0;
  tstPMR.stBit.b1B3 = (U1)0;
  tstPMR.stBit.b1B4 = (U1)0;
  tstPMR.stBit.b1B5 = (U1)0;
  stRegPORTm.staPMR[14].u1Val = tstPMR.u1Val;

  /* PF */ /* idx = 15 */
  /* 64Pinは無し */

  /* PG */ /* idx = 16 */
  /* 64Pinは無し */

  /* PH, PIはUMにも記載なし */

  /* PJ */ /* idx = 18 */
  /* 64Pinは無し */
#endif
}


/* ============================================================ */
/* 関数名 : FnVD_HwPph_Port_cfg                                 */
/*          ポート機能設定                                      */
/* 引数   : tpstCfg  レジスタ設定情報                           */
/* 戻り値 : なし                                                */
/* 概要   : ポートの機能設定を行う                              */
/* 制約   : 割り込み禁止中に実行すること                        */
/*          設定済みのポートに対して再度設定を行わないこと      */
/* ============================================================ */
VD FnVD_HwPph_Port_cfg(const ST_HwPph_Port_Cfg * tpstCfg)
{
  ST_PmnPFS tstPFS;
  U1 tu1GrpNum;
  U1 tu1PinNum;
  U1 tu1PinMsk;

  /* ------ */
  /* 前処理 */
  /* ------ */
  /* ポートグループ/ピン番号取得 */
  FnVD_HwPph_Port_getNumGrpPin(tpstCfg->enId, &tu1GrpNum, &tu1PinNum);

  /* ピン位置マスク生成 */
  tu1PinMsk = FnU1_HwPph_Port_createPinMsk(tu1PinNum);

  /* -------------- */
  /* 汎用ポート設定 */
  /* -------------- */
  if (tpstCfg->stPortCfg.stReg.b1PDR == (U1)C_OFF) {
    /* 入力モード設定時 */
    /* プルアップ制御レジスタ設定 */
    FnVD_HwPph_Port_cfgRegPORTn(&stRegPORTm.staPCR[tu1GrpNum].u1Val, tpstCfg->stPortCfg.stReg.b1PCR, tu1PinMsk);
  }
  else {
    /* 出力モード設定時 */
    /* オープンドレイン制御レジスタ設定 */
    FnVD_HwPph_Port_cfgRegPORTn(&stRegPORTm.sta2ODRi[tu1GrpNum][0].u1Val, tpstCfg->stPortCfg.stReg.b1ODR0, tu1PinMsk);
    FnVD_HwPph_Port_cfgRegPORTn(&stRegPORTm.sta2ODRi[tu1GrpNum][1].u1Val, tpstCfg->stPortCfg.stReg.b1ODR1, tu1PinMsk);

    /* 駆動能力制御レジスタ設定 */
    FnVD_HwPph_Port_cfgRegPORTn(&stRegPORTm.staDSCR[tu1GrpNum].u1Val, tpstCfg->stPortCfg.stReg.b1DSCR, tu1PinMsk);

    /* ポート出力データレジスタ設定 */
    FnVD_HwPph_Port_cfgRegPORTn(&stRegPORTm.staPODR[tu1GrpNum].u1Val, tpstCfg->stPortCfg.stReg.b1PODR, tu1PinMsk);
  }

  /* ------------ */
  /* 兼用機能設定 */
  /* ------------ */
  if (tpstCfg->stPortCfg.stReg.b1PMR == (U1)C_ON) {
    /* 保護解除 */
    FnVD_HwPph_Port_enbPFS();

    tstPFS.u1Val = sta2RegPmnPFS[tu1GrpNum][tu1PinNum].u1Val;
    tstPFS.stBit.b5PSEL = tpstCfg->stMpcCfg.stReg.b5PSEL;
    tstPFS.stBit.b1ISEL = tpstCfg->stMpcCfg.stReg.b1ISEL;
    tstPFS.stBit.b1ASEL = tpstCfg->stMpcCfg.stReg.b1ASEL;
    sta2RegPmnPFS[tu1GrpNum][tu1PinNum].u1Val = tstPFS.u1Val;

    /* 保護する */
    FnVD_HwPph_Port_dibPFS();
  }

  /* ---------------------- */
  /* ポート方向、モード切替 */
  /* ---------------------- */
  /* ポート方向レジスタ設定 */
  /* Note:兼用出力モードの場合、この処理で一瞬だけ汎用出力モードとなることに注意 */
  FnVD_HwPph_Port_cfgRegPORTn(&stRegPORTm.staPDR[tu1GrpNum].u1Val, tpstCfg->stPortCfg.stReg.b1PDR, tu1PinMsk);

  /* ポートモードレジスタ設定 */
  FnVD_HwPph_Port_cfgRegPORTn(&stRegPORTm.staPMR[tu1GrpNum].u1Val, tpstCfg->stPortCfg.stReg.b1PMR, tu1PinMsk);
}


/* ============================================================ */
/* 関数名 : FnU1_HwPph_Port_getInLv                             */
/*          汎用入力ポートの入力レベル取得                      */
/* 引数   : tenId  ポート識別ID                                 */
/* 戻り値 : (0:Low, 1:High)                                     */
/* 概要   : 汎用ポートかつ入力ポートに設定されたポートへの      */
/*          入力レベルを取得する                                */
/* 制約   : なし                                                */
/* ============================================================ */
U1 FnU1_HwPph_Port_getInLv(EN_HwPph_Port_Id tenId)
{
  U1 tu1GrpNum;
  U1 tu1PinNum;
  U1 tu1Ret;

  /* ポートグループ/ピン番号取得 */
  FnVD_HwPph_Port_getNumGrpPin(tenId, &tu1GrpNum, &tu1PinNum);

  /* 入力レベル取得 */
  tu1Ret = stRegPORTm.staPIDR[tu1GrpNum].u1Val;
  tu1Ret >>= tu1PinNum;
  tu1Ret &= CU1_HwPph_Port_MskBit0;

  return (tu1Ret);
}


/* ============================================================ */
/* 関数名 : FnVD_HwPph_Port_setOutLv                            */
/*          汎用出力ポートの出力レベル設定                      */
/* 引数   : tenId  ポート識別ID                                 */
/*          tu1OutLv              出力レベルの設定値            */
/* 戻り値 : (0:Low, 1:High)                                     */
/* 概要   : 汎用ポートかつ出力ポートに設定されたポートへの      */
/*          出力レベルを設定する                                */
/* 制約   : 割り込み禁止中に実行すること                        */
/* ============================================================ */
VD FnVD_HwPph_Port_setOutLv(EN_HwPph_Port_Id tenId, U1 tu1OutLv)
{
  U1 tu1GrpNum;
  U1 tu1PinNum;
  U1 tu1PinMsk;

  /* ポートグループ/ピン番号取得 */
  FnVD_HwPph_Port_getNumGrpPin(tenId, &tu1GrpNum, &tu1PinNum);

  /* ピン位置マスク生成 */
  tu1PinMsk = FnU1_HwPph_Port_createPinMsk(tu1PinNum);

  /* 出力レベル設定 */
  FnVD_HwPph_Port_cfgRegPORTn(&stRegPORTm.staPODR[tu1GrpNum].u1Val, tu1OutLv, tu1PinMsk);
}

