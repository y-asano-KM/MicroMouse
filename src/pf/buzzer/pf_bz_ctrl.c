/* ============================================================ */
/* ファイル名 : pf_bz_ctrl.c                                    */
/* 機能       : ブザー制御                                      */
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
#include "pf_bat_monitor_pac.h"

/* 本体 */
#include "pf_bz_ctrl_pac.h"

#define OP_PfSche_Main_TestBz


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */
/* [Hz]周波数初期値 */
#define CU4_PfBz_Ctrl_InitFreq          ((U4)1047)

/* [ms]バッテリー電圧低下吹鳴周期 */
#define CU1_PfBz_Ctrl_BatVoltLowPeriod  ((U1)((U1)250 / CU1_PrjCmn_MainPeriod))

/* [Hz]バッテリー電圧低下時周波数 */
#define CU4_PfBz_Ctrl_BatVoltLowFreq    ((U4)1976)

#if defined(OP_PfSche_Main_TestBz)
  /* [ms]イニシャル吹鳴1時間 */
  #define CU2_PfBz_Ctrl_Initial1Time    ((U2)((U2)1000 / (U2)CU1_PrjCmn_MainPeriod))

  /* [ms]イニシャル吹鳴2時間 */
  #define CU2_PfBz_Ctrl_Initial2Time    ((U2)((U2)2000 / (U2)CU1_PrjCmn_MainPeriod))

  /* [ms]イニシャル吹鳴3時間 */
  #define CU2_PfBz_Ctrl_Initial3Time    ((U2)((U2)3000 / (U2)CU1_PrjCmn_MainPeriod))

  /* [Hz]イニシャル吹鳴1周波数 */
  #define CU4_PfBz_Ctrl_Initial1Freq    ((U4)1047)

  /* [Hz]イニシャル吹鳴2周波数 */
  #define CU4_PfBz_Ctrl_Initial2Freq    ((U4)1175)

  /* [Hz]イニシャル吹鳴3周波数 */
  #define CU4_PfBz_Ctrl_Initial3Freq    ((U4)1319)
#endif


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
static U4 u4PfBz_Ctrl_Freq;               /* [Hz]出力周波数(LSB:1Hz) */
static U1 u1PfBz_Ctrl_Req;                /* 出力要求値 */
static U2 u2PfBz_Ctrl_InitialTimer;       /* [ms]出力周波数(LSB:CU1_PrjCmn_MainPeriod) */
static U1 u1PfBz_Ctrl_BatVoltLowTimer;    /* [ms]出力周波数(LSB:CU1_PrjCmn_MainPeriod) */


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
/* 関数名 : FnVD_PfBz_Ctrl_init                                 */
/*          ブザー制御処理初期化                                */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : ブザー制御処理の初期化を行う                        */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_PfBz_Ctrl_init(VD)
{
  /* 出力要求値初期化 */
  u4PfBz_Ctrl_Freq = (U4)0;
  u1PfBz_Ctrl_Req = (U1)0;

  /* イニシャル吹鳴時間初期化 */
  u2PfBz_Ctrl_InitialTimer = (U2)0;

  /* バッテリー電圧低下時時間初期化 */
  u1PfBz_Ctrl_BatVoltLowTimer = (U1)0;
}


/* ============================================================ */
/* 関数名 : FnVD_PfBz_Ctrl_mediate                              */
/*          ブザー吹鳴要求調停処理                              */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 各種ブザー吹鳴条件の優先度より出力値を調停する      */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_PfBz_Ctrl_mediate(VD)
{
  U4 tu4Freq;
  U1 tu1Req;
  U1 tu1BatVolLow;

  /* イニシャル吹鳴時間 */
  McXX_incU2Max(u2PfBz_Ctrl_InitialTimer);

#if defined(OP_PfSche_Main_TestBz)
  /* ToDo:テスト用のため最終的には削除する */
  /* バッテリー電圧低下状態取得 */
  tu1BatVolLow = FnU1_PfBat_Moni_getStsVoltageLow();
#endif

  if (0) {
    /* 何もしない */
  }
  else if (tu1BatVolLow == (U1)C_ON) {
    /* バッテリー電圧低下中の吹鳴処理 */
    if (u1PfBz_Ctrl_BatVoltLowTimer <= CU1_PfBz_Ctrl_BatVoltLowPeriod) {
      u1PfBz_Ctrl_BatVoltLowTimer++;
    }
    else {
      u1PfBz_Ctrl_BatVoltLowTimer = (U1)0;
    }

    if (u1PfBz_Ctrl_BatVoltLowTimer <= (U1)(CU1_PfBz_Ctrl_BatVoltLowPeriod / (U1)2)) {
      tu1Req  = (U1)C_ON;
    }
    else {
      tu1Req  = (U1)C_OFF;
    }
    tu4Freq = CU4_PfBz_Ctrl_BatVoltLowFreq;
  }
#if defined(OP_PfSche_Main_TestBz)
  /* ToDo:テスト用のため最終的には削除する */
  else if (u2PfBz_Ctrl_InitialTimer <= CU2_PfBz_Ctrl_Initial1Time) {
    tu1Req  = (U1)C_ON;
    tu4Freq = CU4_PfBz_Ctrl_Initial1Freq;
  }
  else if (u2PfBz_Ctrl_InitialTimer <= CU2_PfBz_Ctrl_Initial2Time) {
    tu1Req  = (U1)C_ON;
    tu4Freq = CU4_PfBz_Ctrl_Initial2Freq;
  }
  else if (u2PfBz_Ctrl_InitialTimer <= CU2_PfBz_Ctrl_Initial3Time) {
    tu1Req  = (U1)C_ON;
    tu4Freq = CU4_PfBz_Ctrl_Initial3Freq;
  }
#endif
  else {
    tu1Req  = (U1)C_OFF;
    tu4Freq = CU4_PfBz_Ctrl_InitFreq;
  }

  u1PfBz_Ctrl_Req  = tu1Req;
  u4PfBz_Ctrl_Freq = tu4Freq;
}


/* ============================================================ */
/* 関数名 : FnU1_PfBz_Ctrl_getReq                               */
/*          ブザー出力要求値取得                                */
/* 引数   : なし                                                */
/* 戻り値 : ブザー出力要求値                                    */
/* 概要   : ブザー出力要求値を提供する                          */
/* 制約   : なし                                                */
/* ============================================================ */
U1 FnU1_PfBz_Ctrl_getReq(VD)
{
  return (u1PfBz_Ctrl_Req);
}


/* ============================================================ */
/* 関数名 : FnU4_PfBz_Ctrl_getFreq                              */
/*          ブザー出力周波数取得                                */
/* 引数   : なし                                                */
/* 戻り値 : [Hz]ブザー出力周波数 (LSB:1Hz)                      */
/* 概要   : ブザー出力周波数を提供する                          */
/* 制約   : なし                                                */
/* ============================================================ */
U4 FnU4_PfBz_Ctrl_getFreq(VD)
{
  return (u4PfBz_Ctrl_Freq);
}

