/* ============================================================ */
/* ファイル名 : hw_pph_mtu.c                                    */
/* 機能       : MTU処理                                         */
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
#include "hw_pph_mtu_pac.h"
#include "hw_pph_mtu_cfg_pac.h"


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */
/* 保護解除キー */
#define CU2_HwPph_Mtu_ProtectKey         ((U2)0xA5)

/* モジュールストップ状態の解除 */
#define CU4_HwPph_Mtu_MSTPCR_MSTP_Reset  ((U4)0x0)

/* モジュールストップ状態へ遷移 */
#define CU4_HwPph_Mtu_MSTPCR_MSTP_Stp    ((U4)0x1)

/* TOERレジスタ固定値ビット0設定値 */
#define CU1_HwPph_Mtu_TOER_Fix0          ((U1)0x3)

/* TGRレジスタ初期値 */
#define CU2_HwPph_Mtu_TGR_Init           ((U2)0xFFFFU)


/* ============================================================ */
/* 型定義                                                       */
/* ============================================================ */


/* ============================================================ */
/* 関数プロトタイプ宣言(static)                                 */
/* ============================================================ */
static VD FnVD_HwPph_Mtu_enbStpModuleSetting(VD);
static VD FnVD_HwPph_Mtu_dibStpModuleSetting(VD);


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
/* TCNTレジスタテーブル */
static volatile U2 __evenaccess * const CPU2A_HwPph_Mtu_TblRegTCNT[CU1_HwPph_Mtu_SizeTblRegTCNT] = {
 &stRegMTU.stMTU0_TCNT.u2Val,    /* CEN_HwPph_Mtu_IdTCNT_MTU0 */
 &stRegMTU.stMTU1_TCNT.u2Val,    /* CEN_HwPph_Mtu_IdTCNT_MTU1 */
 &stRegMTU.stMTU2_TCNT.u2Val,    /* CEN_HwPph_Mtu_IdTCNT_MTU2 */
 &stRegMTU.stMTU3_TCNT.u2Val,    /* CEN_HwPph_Mtu_IdTCNT_MTU3 */
 &stRegMTU.stMTU4_TCNT.u2Val,    /* CEN_HwPph_Mtu_IdTCNT_MTU4 */
 &stRegMTU.stMTU5_TCNTU.u2Val,   /* CEN_HwPph_Mtu_IdTCNT_MTU5U */
 &stRegMTU.stMTU5_TCNTV.u2Val,   /* CEN_HwPph_Mtu_IdTCNT_MTU5V */
 &stRegMTU.stMTU5_TCNTW.u2Val    /* CEN_HwPph_Mtu_IdTCNT_MTU5W */
};

/* TGRレジスタテーブル */
static volatile U2 __evenaccess * const CPU2A_HwPph_Mtu_TblRegTGR[CU1_HwPph_Mtu_SizeTblRegTGR] = {
 &stRegMTU.stMTU0_TGRA.u2Val,    /* CEN_HwPph_Mtu_IdTGR_MTU0A */
 &stRegMTU.stMTU0_TGRB.u2Val,    /* CEN_HwPph_Mtu_IdTGR_MTU0B */
 &stRegMTU.stMTU0_TGRC.u2Val,    /* CEN_HwPph_Mtu_IdTGR_MTU0C */
 &stRegMTU.stMTU0_TGRD.u2Val,    /* CEN_HwPph_Mtu_IdTGR_MTU0D */
 &stRegMTU.stMTU0_TGRE.u2Val,    /* CEN_HwPph_Mtu_IdTGR_MTU0E */
 &stRegMTU.stMTU0_TGRF.u2Val,    /* CEN_HwPph_Mtu_IdTGR_MTU0F */
 &stRegMTU.stMTU1_TGRA.u2Val,    /* CEN_HwPph_Mtu_IdTGR_MTU1A */
 &stRegMTU.stMTU1_TGRB.u2Val,    /* CEN_HwPph_Mtu_IdTGR_MTU1B */
 &stRegMTU.stMTU2_TGRA.u2Val,    /* CEN_HwPph_Mtu_IdTGR_MTU2A */
 &stRegMTU.stMTU2_TGRB.u2Val,    /* CEN_HwPph_Mtu_IdTGR_MTU2B */
 &stRegMTU.stMTU3_TGRA.u2Val,    /* CEN_HwPph_Mtu_IdTGR_MTU3A */
 &stRegMTU.stMTU3_TGRB.u2Val,    /* CEN_HwPph_Mtu_IdTGR_MTU3B */
 &stRegMTU.stMTU3_TGRC.u2Val,    /* CEN_HwPph_Mtu_IdTGR_MTU3C */
 &stRegMTU.stMTU3_TGRD.u2Val,    /* CEN_HwPph_Mtu_IdTGR_MTU3D */
 &stRegMTU.stMTU4_TGRA.u2Val,    /* CEN_HwPph_Mtu_IdTGR_MTU4A */
 &stRegMTU.stMTU4_TGRB.u2Val,    /* CEN_HwPph_Mtu_IdTGR_MTU4B */
 &stRegMTU.stMTU4_TGRC.u2Val,    /* CEN_HwPph_Mtu_IdTGR_MTU4C */
 &stRegMTU.stMTU4_TGRD.u2Val,    /* CEN_HwPph_Mtu_IdTGR_MTU4D */
 &stRegMTU.stMTU5_TGRU.u2Val,    /* CEN_HwPph_Mtu_IdTGR_MTU5U */
 &stRegMTU.stMTU5_TGRV.u2Val,    /* CEN_HwPph_Mtu_IdTGR_MTU5V */
 &stRegMTU.stMTU5_TGRW.u2Val     /* CEN_HwPph_Mtu_IdTGR_MTU5W */
};


/* ============================================================ */
/* 関数形式マクロ定義                                           */
/* ============================================================ */


/* ============================================================ */
/* 関数定義                                                     */
/* ============================================================ */
/* ============================================================ */
/* 関数名 : FnVD_HwPph_Mtu_enbStpModuleSetting                  */
/*          モジュール停止制御レジスタ保護解除                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : モジュール停止制御レジスタの保護を解除する          */
/* 制約   : 割り込み禁止中に実行すること                        */
/* ============================================================ */
#pragma inline (FnVD_HwPph_Mtu_enbStpModuleSetting)
static VD FnVD_HwPph_Mtu_enbStpModuleSetting(VD)
{
  ST_PRCR tstPRCR;

  tstPRCR.u2Val = stRegSys0.stPRCR.u2Val;
  tstPRCR.stBit.b1PRC1 = (U2)1;
  tstPRCR.stBit.b8PRKEY = CU2_HwPph_Mtu_ProtectKey;
  stRegSys0.stPRCR.u2Val = tstPRCR.u2Val;
}


/* ============================================================ */
/* 関数名 : FnVD_HwPph_Mtu_dibStpModuleSetting                  */
/*          モジュール停止制御レジスタ保護                      */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : モジュール停止制御レジスタの保護する                */
/* 制約   : 割り込み禁止中に実行すること                        */
/* ============================================================ */
#pragma inline (FnVD_HwPph_Mtu_dibStpModuleSetting)
static VD FnVD_HwPph_Mtu_dibStpModuleSetting(VD)
{
  ST_PRCR tstPRCR;

  tstPRCR.u2Val = stRegSys0.stPRCR.u2Val;
  tstPRCR.stBit.b1PRC1 = (U2)0;
  tstPRCR.stBit.b8PRKEY = CU2_HwPph_Mtu_ProtectKey;
  stRegSys0.stPRCR.u2Val = tstPRCR.u2Val;
}


/* ============================================================ */
/* 関数名 : FnVD_HwPph_Mtu_resetModuleStp                       */
/*          モジュール停止制御レジスタ解除設定                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : モジュール停止を解除する                            */
/* 制約   : 割り込み禁止中に実行すること                        */
/* ============================================================ */
VD FnVD_HwPph_Mtu_resetModuleStp(VD)
{
  ST_MSTPCRA tstMSTPCRA;

  /* 保護解除 */
  FnVD_HwPph_Mtu_enbStpModuleSetting();

  /* モジュールストップコントロールレジスタ設定(解除) */
  tstMSTPCRA.u4Val = (U4)0xFFFFFFFF;
  tstMSTPCRA.stBit.b1MSTPA9 = CU4_HwPph_Mtu_MSTPCR_MSTP_Reset;  /* MTU0-5 */
  stRegSys0.stMSTPCRA.u4Val &= tstMSTPCRA.u4Val;

  /* 保護 */
  FnVD_HwPph_Mtu_dibStpModuleSetting();
}


/* ============================================================ */
/* 関数名 : FnVD_HwPph_Mtu_stpModuleStp                         */
/*          モジュール停止制御レジスタ遷移設定                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : モジュール停止へ遷移する                            */
/* 制約   : 割り込み禁止中に実行すること                        */
/* ============================================================ */
VD FnVD_HwPph_Mtu_stpModuleStp(VD)
{
  ST_MSTPCRA tstMSTPCRA;

  /* 保護解除 */
  FnVD_HwPph_Mtu_enbStpModuleSetting();

  /* モジュールストップコントロールレジスタ設定(解除) */
  tstMSTPCRA.u4Val = (U4)0x00000000;
  tstMSTPCRA.stBit.b1MSTPA9 = CU4_HwPph_Mtu_MSTPCR_MSTP_Stp;  /* MTU0-5 */
  stRegSys0.stMSTPCRA.u4Val |= tstMSTPCRA.u4Val;

  /* 保護 */
  FnVD_HwPph_Mtu_dibStpModuleSetting();
}


/* ============================================================ */
/* 関数名 : FnVD_HwPph_Mtu_ctrlStpAndGo                         */
/*          MTUカウント動作停止/開始制御                        */
/* 引数   : tu1Enb  許可 (0:設定禁止, 1:設定許可)               */
/*          tu1Req  要求 (0:動作停止, 1:動作開始)               */
/*                  bit0:MTU0                                   */
/*                  bit1:MTU1                                   */
/*                  bit2:MTU2                                   */
/*                  bit3:MTU3                                   */
/*                  bit4:MTU4                                   */
/*                  bit5:MTU5U                                  */
/*                  bit6:MTU5V                                  */
/*                  bit7:MTU5W                                  */
/* 戻り値 : なし                                                */
/* 概要   : カウント動作の停止/開始を制御する                   */
/* 制約   : 割り込み禁止中に実行すること                        */
/* ============================================================ */
VD FnVD_HwPph_Mtu_ctrlStpAndGo(U1 tu1Enb, U1 tu1Req)
{
  ST_MTU_TSTR tstMTU_TSTR_Cur;
  ST_MTU_TSTR tstMTU_TSTR_Enb;
  ST_MTU_TSTR tstMTU_TSTR_Req;
  ST_MTU_TSTR tstMTU_TSTR_Set;
  F1          tf1Work;

  if ((U1)(tu1Enb & (U1)0x1F) != (U1)0) {
    /* 設定許可情報をレジスタのビットパターンへ変換 */
    tf1Work.u1Val = tu1Enb;
    tstMTU_TSTR_Enb.u1Val = (U1)0x00;
    tstMTU_TSTR_Enb.stMTU.stBit.b1CST0 = tf1Work.Flag.fBit0;
#if (0)
  /* ToDo:MTU1,2未実装  */
#else
    tstMTU_TSTR_Enb.stMTU.stBit.b1CST1 = tf1Work.Flag.fBit1;
    tstMTU_TSTR_Enb.stMTU.stBit.b1CST2 = tf1Work.Flag.fBit2;
#endif
    tstMTU_TSTR_Enb.stMTU.stBit.b1CST3 = tf1Work.Flag.fBit3;
    tstMTU_TSTR_Enb.stMTU.stBit.b1CST4 = tf1Work.Flag.fBit4;

    /* 動作要求をレジスタのビットパターンへ変換 */
    tf1Work.u1Val = tu1Req;
    tstMTU_TSTR_Req.u1Val = (U1)0x00;
    tstMTU_TSTR_Req.stMTU.stBit.b1CST0 = tf1Work.Flag.fBit0;
#if (0)
  /* ToDo:MTU1,2未実装  */
#else
    tstMTU_TSTR_Req.stMTU.stBit.b1CST1 = tf1Work.Flag.fBit1;
    tstMTU_TSTR_Req.stMTU.stBit.b1CST2 = tf1Work.Flag.fBit2;
#endif
    tstMTU_TSTR_Req.stMTU.stBit.b1CST3 = tf1Work.Flag.fBit3;
    tstMTU_TSTR_Req.stMTU.stBit.b1CST4 = tf1Work.Flag.fBit4;

    /* 設定許可であるビットの要求値を抽出 */
    tstMTU_TSTR_Set.u1Val = (U1)(tstMTU_TSTR_Req.u1Val & tstMTU_TSTR_Enb.u1Val);

    /* 現在のレジスタ値を読み出し */
    tstMTU_TSTR_Cur.u1Val = stRegMTU.stMTU_TSTR.u1Val;

    /* 設定禁止であるビットは現在値を維持 */
    tstMTU_TSTR_Set.u1Val |= (U1)(tstMTU_TSTR_Cur.u1Val & (U1)~tstMTU_TSTR_Enb.u1Val);

    /* 要求書き込み */
    stRegMTU.stMTU_TSTR.u1Val = tstMTU_TSTR_Set.u1Val;
  }

#if (0)
  /* ToDo:MTU5未実装  */
#else
  if ((U1)(tu1Enb & (U1)0xE0) != (U1)0) {
    /* 設定許可情報をレジスタのビットパターンへ変換 */
    tf1Work.u1Val = tu1Enb;
    tstMTU_TSTR_Enb.u1Val = (U1)0x00;
    tstMTU_TSTR_Enb.stMTU5.stBit.b1CSTW5 = tf1Work.Flag.fBit2;
    tstMTU_TSTR_Enb.stMTU5.stBit.b1CSTV5 = tf1Work.Flag.fBit1;
    tstMTU_TSTR_Enb.stMTU5.stBit.b1CSTU5 = tf1Work.Flag.fBit0;

    /* 動作要求をレジスタのビットパターンへ変換 */
    tf1Work.u1Val = tu1Enb;
    tstMTU_TSTR_Req.u1Val = (U1)0x00;
    tstMTU_TSTR_Req.stMTU5.stBit.b1CSTW5 = tf1Work.Flag.fBit2;
    tstMTU_TSTR_Req.stMTU5.stBit.b1CSTV5 = tf1Work.Flag.fBit1;
    tstMTU_TSTR_Req.stMTU5.stBit.b1CSTU5 = tf1Work.Flag.fBit0;

    /* 設定許可であるビットの要求値を抽出 */
    tstMTU_TSTR_Set.u1Val = (U1)(tstMTU_TSTR_Req.u1Val & tstMTU_TSTR_Enb.u1Val);

    /* 現在のレジスタ値を読み出し */
    tstMTU_TSTR_Cur.u1Val = stRegMTU.stMTU5_TSTR.u1Val;

    /* 設定禁止であるビットは現在値を維持 */
    tstMTU_TSTR_Set.u1Val |= (U1)(tstMTU_TSTR_Cur.u1Val & (U1)~tstMTU_TSTR_Enb.u1Val);

    /* 要求書き込み */
    stRegMTU.stMTU5_TSTR.u1Val = tstMTU_TSTR_Set.u1Val;
  }
#endif
}


/* ============================================================ */
/* 関数名 : FnVD_HwPph_Mtu_cfgMtu0                              */
/*          MTU0機能設定                                        */
/* 引数   : tpstCfg  コンフィグデータ                           */
/* 戻り値 : なし                                                */
/* 概要   : MTU0の機能設定を行う                                */
/* 制約   : 割り込み禁止中に実行すること                        */
/*          スタートアップにて1回のみ実行すること               */
/* ============================================================ */
VD FnVD_HwPph_Mtu_cfgMtu0(const ST_HwPph_Mtu_CfgMtu0 * tpstCfg)
{
  ST_MTU_TCR   tstMTU_TCR;
  ST_MTU_TMDR  tstMTU_TMDR;
  ST_MTU_TIORH tstMTU_TIORH;
  ST_MTU_TIORL tstMTU_TIORL;
  ST_MTU_TIER  tstMTU_TIER;
  ST_MTU_TIER2 tstMTU_TIER2;
  ST_MTU_TSTR  tstMTU_TSTR;

  /* タイマー停止 */
  tstMTU_TSTR.u1Val = stRegMTU.stMTU_TSTR.u1Val;
  tstMTU_TSTR.stMTU.stBit.b1CST0 = (U1)C_OFF;
  stRegMTU.stMTU_TSTR.u1Val = tstMTU_TSTR.u1Val;

  /* タイマコントロールレジスタ(TCR)設定用 */
  tstMTU_TCR.u1Val = (U1)0x00;
  tstMTU_TCR.stBit.b3TPSC = (U1)tpstCfg->enSelPriscaler;
  tstMTU_TCR.stBit.b2CKEG = (U1)tpstCfg->enSelClkEdge;
  tstMTU_TCR.stBit.b3CCLR = (U1)tpstCfg->enCntrClr;
  stRegMTU.stMTU0_TCR.u1Val = tstMTU_TCR.u1Val;

  /* タイマモードレジスタ(TMDR)設定用 */
  tstMTU_TMDR.u1Val = (U1)0x00;
  tstMTU_TMDR.stBit.b4MD  = (U1)tpstCfg->enSelMd;
  tstMTU_TMDR.stBit.b1BFA = tpstCfg->u1BufA;
  tstMTU_TMDR.stBit.b1BFB = tpstCfg->u1BufB;
  tstMTU_TMDR.stBit.b1BFE = tpstCfg->u1BufE;
  stRegMTU.stMTU0_TMDR.u1Val = tstMTU_TMDR.u1Val;

  /* タイマI/Oコントロールレジスタ(TIOR)設定用 */
  tstMTU_TIORH.u1Val = (U1)0x00;
  tstMTU_TIORH.stBit.b4IOA = (U1)tpstCfg->enIoCtrlA;
  tstMTU_TIORH.stBit.b4IOB = (U1)tpstCfg->enIoCtrlB;
  stRegMTU.stMTU0_TIORH.u1Val = tstMTU_TIORH.u1Val;

  tstMTU_TIORL.u1Val = (U1)0x00;
  tstMTU_TIORL.stBit.b4IOC = (U1)tpstCfg->enIoCtrlC;
  tstMTU_TIORL.stBit.b4IOD = (U1)tpstCfg->enIoCtrlD;
  stRegMTU.stMTU0_TIORL.u1Val = tstMTU_TIORL.u1Val;

  /* タイマカウンタ初期化 */
  stRegMTU.stMTU0_TCNT.u2Val = (U2)0x0000;

  /* タイマジェネラルレジスタ初期化 */
  stRegMTU.stMTU0_TGRA.u2Val = CU2_HwPph_Mtu_TGR_Init;
  stRegMTU.stMTU0_TGRB.u2Val = CU2_HwPph_Mtu_TGR_Init;
  stRegMTU.stMTU0_TGRC.u2Val = CU2_HwPph_Mtu_TGR_Init;
  stRegMTU.stMTU0_TGRD.u2Val = CU2_HwPph_Mtu_TGR_Init;
  stRegMTU.stMTU0_TGRE.u2Val = CU2_HwPph_Mtu_TGR_Init;
  stRegMTU.stMTU0_TGRF.u2Val = CU2_HwPph_Mtu_TGR_Init;

  /* タイマ割り込み許可レジスタ(TIER)設定用 */
  tstMTU_TIER.u1Val = (U1)0x00;
  tstMTU_TIER.stMTU.stBit.b1TGIEA = tpstCfg->u1EnbTGIEA;
  tstMTU_TIER.stMTU.stBit.b1TGIEB = tpstCfg->u1EnbTGIEB;
  tstMTU_TIER.stMTU.stBit.b1TGIEC = tpstCfg->u1EnbTGIEC;
  tstMTU_TIER.stMTU.stBit.b1TGIED = tpstCfg->u1EnbTGIED;
  tstMTU_TIER.stMTU.stBit.b1TGIED = tpstCfg->u1EnbTCIEV;
  /* Memo:MTU0はTCIEUなし */
  /* Memo:MTU0はTTGE2なし */
  tstMTU_TIER.stMTU.stBit.b1TGIED = tpstCfg->u1EnbTTGE;
  stRegMTU.stMTU0_TMDR.u1Val = tstMTU_TIER.u1Val;

  tstMTU_TIER2.u1Val = (U1)0x00;
  tstMTU_TIER2.stBit.b1TGIEE = tpstCfg->u1EnbTGIEE;
  tstMTU_TIER2.stBit.b1TGIEF = tpstCfg->u1EnbTGIEF;
  stRegMTU.stMTU0_TIER2.u1Val = tstMTU_TIER2.u1Val;

  /* タイマアウトプットマスタ許可レジスタ(TOER)設定用 */
  /* Memo:MTU0はTOERなし */
}


/* ============================================================ */
/* 関数名 : FnVD_HwPph_Mtu_cfgMtu1                              */
/*          MTU1機能設定                                        */
/* 引数   : tpstCfg  コンフィグデータ                           */
/* 戻り値 : なし                                                */
/* 概要   : MTU1の機能設定を行う                                */
/* 制約   : 割り込み禁止中に実行すること                        */
/*          スタートアップにて1回のみ実行すること               */
/* ============================================================ */
/* ToDo:未実装 */


/* ============================================================ */
/* 関数名 : FnVD_HwPph_Mtu_cfgMtu2                              */
/*          MTU2機能設定                                        */
/* 引数   : tpstCfg  コンフィグデータ                           */
/* 戻り値 : なし                                                */
/* 概要   : MTU2の機能設定を行う                                */
/* 制約   : 割り込み禁止中に実行すること                        */
/*          スタートアップにて1回のみ実行すること               */
/* ============================================================ */
/* ToDo:未実装 */


/* ============================================================ */
/* 関数名 : FnVD_HwPph_Mtu_cfgMtu3                              */
/*          MTU3機能設定                                        */
/* 引数   : tpstCfg  コンフィグデータ                           */
/* 戻り値 : なし                                                */
/* 概要   : MTU3の機能設定を行う                                */
/* 制約   : 割り込み禁止中に実行すること                        */
/*          スタートアップにて1回のみ実行すること               */
/* ============================================================ */
VD FnVD_HwPph_Mtu_cfgMtu3(const ST_HwPph_Mtu_CfgMtu3 * tpstCfg)
{
  ST_MTU_TCR   tstMTU_TCR;
  ST_MTU_TMDR  tstMTU_TMDR;
  ST_MTU_TIORH tstMTU_TIORH;
  ST_MTU_TIORL tstMTU_TIORL;
  ST_MTU_TIER  tstMTU_TIER;
  ST_MTU_TSTR  tstMTU_TSTR;
  ST_MTU_TOER  tstMTU_TOER;

  /* タイマー停止 */
  tstMTU_TSTR.u1Val = stRegMTU.stMTU_TSTR.u1Val;
  tstMTU_TSTR.stMTU.stBit.b1CST3 = (U1)C_OFF;
  stRegMTU.stMTU_TSTR.u1Val = tstMTU_TSTR.u1Val;

  /* タイマコントロールレジスタ(TCR)設定用 */
  tstMTU_TCR.u1Val = (U1)0x00;
  tstMTU_TCR.stBit.b3TPSC = (U1)tpstCfg->enSelPriscaler;
  tstMTU_TCR.stBit.b2CKEG = (U1)tpstCfg->enSelClkEdge;
  tstMTU_TCR.stBit.b3CCLR = (U1)tpstCfg->enCntrClr;
  stRegMTU.stMTU3_TCR.u1Val = tstMTU_TCR.u1Val;

  /* タイマモードレジスタ(TMDR)設定用 */
  tstMTU_TMDR.u1Val = (U1)0x00;
  tstMTU_TMDR.stBit.b4MD  = (U1)tpstCfg->enSelMd;
  tstMTU_TMDR.stBit.b1BFA = tpstCfg->u1BufA;
  tstMTU_TMDR.stBit.b1BFB = tpstCfg->u1BufB;
  /* Memo:MTU3はBFEなし */
  stRegMTU.stMTU3_TMDR.u1Val = tstMTU_TMDR.u1Val;

  /* タイマI/Oコントロールレジスタ(TIOR)設定用 */
  tstMTU_TIORH.u1Val = (U1)0x00;
  tstMTU_TIORH.stBit.b4IOA = (U1)tpstCfg->enIoCtrlA;
  tstMTU_TIORH.stBit.b4IOB = (U1)tpstCfg->enIoCtrlB;
  stRegMTU.stMTU3_TIORH.u1Val = tstMTU_TIORH.u1Val;

  tstMTU_TIORL.u1Val = (U1)0x00;
  tstMTU_TIORL.stBit.b4IOC = (U1)tpstCfg->enIoCtrlC;
  tstMTU_TIORL.stBit.b4IOD = (U1)tpstCfg->enIoCtrlD;
  stRegMTU.stMTU3_TIORL.u1Val = tstMTU_TIORL.u1Val;

  /* タイマカウンタ初期化 */
  stRegMTU.stMTU3_TCNT.u2Val = (U2)0x0000;

  /* タイマジェネラルレジスタ初期化 */
  stRegMTU.stMTU3_TGRA.u2Val = CU2_HwPph_Mtu_TGR_Init;
  stRegMTU.stMTU3_TGRB.u2Val = CU2_HwPph_Mtu_TGR_Init;
  stRegMTU.stMTU3_TGRC.u2Val = CU2_HwPph_Mtu_TGR_Init;
  stRegMTU.stMTU3_TGRD.u2Val = CU2_HwPph_Mtu_TGR_Init;
  /* Memo:MTU3はTGREなし */
  /* Memo:MTU3はTGRFなし */

  /* タイマ割り込み許可レジスタ(TIER)設定用 */
  tstMTU_TIER.u1Val = (U1)0x00;
  tstMTU_TIER.stMTU.stBit.b1TGIEA = tpstCfg->u1EnbTGIEA;
  tstMTU_TIER.stMTU.stBit.b1TGIEB = tpstCfg->u1EnbTGIEB;
  tstMTU_TIER.stMTU.stBit.b1TGIEC = tpstCfg->u1EnbTGIEC;
  tstMTU_TIER.stMTU.stBit.b1TGIED = tpstCfg->u1EnbTGIED;
  tstMTU_TIER.stMTU.stBit.b1TGIED = tpstCfg->u1EnbTCIEV;
  /* Memo:MTU3はTCIEUなし */
  /* Memo:MTU3はTTGE2なし */
  tstMTU_TIER.stMTU.stBit.b1TGIED = tpstCfg->u1EnbTTGE;
  stRegMTU.stMTU3_TMDR.u1Val = tstMTU_TIER.u1Val;

  /* Memo:MTU3はTIER2なし */

  /* タイマアウトプットマスタ許可レジスタ(TOER)設定用 */
  tstMTU_TOER.u1Val = stRegMTU.stMTU_TOER.u1Val;
  tstMTU_TOER.stBit.b1OE3B = tpstCfg->u1EnbMTIOC3B;
  /* Memo:MTU3はOE4Aなし */
  /* Memo:MTU3はOE4Bなし */
  tstMTU_TOER.stBit.b1OE3D = tpstCfg->u1EnbMTIOC3D;
  /* Memo:MTU3はOE4Cなし */
  /* Memo:MTU3はOE4Dなし */
  tstMTU_TOER.stBit.b2Fix0 = CU1_HwPph_Mtu_TOER_Fix0;
  stRegMTU.stMTU_TOER.u1Val = tstMTU_TOER.u1Val;
}


/* ============================================================ */
/* 関数名 : FnVD_HwPph_Mtu_cfgMtu4                              */
/*          MTU4機能設定                                        */
/* 引数   : tpstCfg  コンフィグデータ                           */
/* 戻り値 : なし                                                */
/* 概要   : MTU4の機能設定を行う                                */
/* 制約   : 割り込み禁止中に実行すること                        */
/*          スタートアップにて1回のみ実行すること               */
/* ============================================================ */
VD FnVD_HwPph_Mtu_cfgMtu4(const ST_HwPph_Mtu_CfgMtu4 * tpstCfg)
{
  ST_MTU_TCR   tstMTU_TCR;
  ST_MTU_TMDR  tstMTU_TMDR;
  ST_MTU_TIORH tstMTU_TIORH;
  ST_MTU_TIORL tstMTU_TIORL;
  ST_MTU_TIER  tstMTU_TIER;
  ST_MTU_TSTR  tstMTU_TSTR;
  ST_MTU_TOER  tstMTU_TOER;

  /* タイマー停止 */
  tstMTU_TSTR.u1Val = stRegMTU.stMTU_TSTR.u1Val;
  tstMTU_TSTR.stMTU.stBit.b1CST4 = (U1)C_OFF;
  stRegMTU.stMTU_TSTR.u1Val = tstMTU_TSTR.u1Val;

  /* タイマコントロールレジスタ(TCR)設定用 */
  tstMTU_TCR.u1Val = (U1)0x00;
  tstMTU_TCR.stBit.b3TPSC = (U1)tpstCfg->enSelPriscaler;
  tstMTU_TCR.stBit.b2CKEG = (U1)tpstCfg->enSelClkEdge;
  tstMTU_TCR.stBit.b3CCLR = (U1)tpstCfg->enCntrClr;
  stRegMTU.stMTU3_TCR.u1Val = tstMTU_TCR.u1Val;

  /* タイマモードレジスタ(TMDR)設定用 */
  tstMTU_TMDR.u1Val = (U1)0x00;
  tstMTU_TMDR.stBit.b4MD  = (U1)tpstCfg->enSelMd;
  tstMTU_TMDR.stBit.b1BFA = tpstCfg->u1BufA;
  tstMTU_TMDR.stBit.b1BFB = tpstCfg->u1BufB;
  /* Memo:MTU4はBFEなし */
  stRegMTU.stMTU3_TMDR.u1Val = tstMTU_TMDR.u1Val;

  /* タイマI/Oコントロールレジスタ(TIOR)設定用 */
  tstMTU_TIORH.u1Val = (U1)0x00;
  tstMTU_TIORH.stBit.b4IOA = (U1)tpstCfg->enIoCtrlA;
  tstMTU_TIORH.stBit.b4IOB = (U1)tpstCfg->enIoCtrlB;
  stRegMTU.stMTU3_TIORH.u1Val = tstMTU_TIORH.u1Val;

  tstMTU_TIORL.u1Val = (U1)0x00;
  tstMTU_TIORL.stBit.b4IOC = (U1)tpstCfg->enIoCtrlC;
  tstMTU_TIORL.stBit.b4IOD = (U1)tpstCfg->enIoCtrlD;
  stRegMTU.stMTU3_TIORL.u1Val = tstMTU_TIORL.u1Val;

  /* タイマカウンタ初期化 */
  stRegMTU.stMTU4_TCNT.u2Val = (U2)0x0000;

  /* タイマジェネラルレジスタ初期化 */
  stRegMTU.stMTU4_TGRA.u2Val = CU2_HwPph_Mtu_TGR_Init;
  stRegMTU.stMTU4_TGRB.u2Val = CU2_HwPph_Mtu_TGR_Init;
  stRegMTU.stMTU4_TGRC.u2Val = CU2_HwPph_Mtu_TGR_Init;
  stRegMTU.stMTU4_TGRD.u2Val = CU2_HwPph_Mtu_TGR_Init;
  /* Memo:MTU3はTGREなし */
  /* Memo:MTU3はTGRFなし */

  /* タイマ割り込み許可レジスタ(TIER)設定用 */
  tstMTU_TIER.u1Val = (U1)0x00;
  tstMTU_TIER.stMTU.stBit.b1TGIEA = tpstCfg->u1EnbTGIEA;
  tstMTU_TIER.stMTU.stBit.b1TGIEB = tpstCfg->u1EnbTGIEB;
  tstMTU_TIER.stMTU.stBit.b1TGIEC = tpstCfg->u1EnbTGIEC;
  tstMTU_TIER.stMTU.stBit.b1TGIED = tpstCfg->u1EnbTGIED;
  tstMTU_TIER.stMTU.stBit.b1TGIED = tpstCfg->u1EnbTCIEV;
  /* Memo:MTU4はTCIEUなし */
  tstMTU_TIER.stMTU.stBit.b1TTGE2 = tpstCfg->u1EnbTTGE2;
  tstMTU_TIER.stMTU.stBit.b1TGIED = tpstCfg->u1EnbTTGE;
  stRegMTU.stMTU3_TMDR.u1Val = tstMTU_TIER.u1Val;

  /* Memo:MTU4はTIER2なし */

  /* タイマアウトプットマスタ許可レジスタ(TOER)設定用 */
  tstMTU_TOER.u1Val = stRegMTU.stMTU_TOER.u1Val;
  /* Memo:MTU4はOE3Bなし */
  tstMTU_TOER.stBit.b1OE4A = tpstCfg->u1EnbMTIOC4A;
  tstMTU_TOER.stBit.b1OE4B = tpstCfg->u1EnbMTIOC4B;
  /* Memo:MTU4はOE3Dなし */
  tstMTU_TOER.stBit.b1OE4C = tpstCfg->u1EnbMTIOC4C;
  tstMTU_TOER.stBit.b1OE4D = tpstCfg->u1EnbMTIOC4D;
  tstMTU_TOER.stBit.b2Fix0 = CU1_HwPph_Mtu_TOER_Fix0;
  stRegMTU.stMTU_TOER.u1Val = tstMTU_TOER.u1Val;
}


/* ============================================================ */
/* 関数名 : FnVD_HwPph_Mtu_cfgMtu5                              */
/*          MTU5機能設定                                        */
/* 引数   : tpstCfg  コンフィグデータ                           */
/* 戻り値 : なし                                                */
/* 概要   : MTU5の機能設定を行う                                */
/* 制約   : 割り込み禁止中に実行すること                        */
/*          スタートアップにて1回のみ実行すること               */
/* ============================================================ */
/* ToDo:未実装 */


/* ============================================================ */
/* 関数名 : FnU2_HwPph_Mtu_getTimerCounter                      */
/*          タイマカウンタ取得                                  */
/* 引数   : tenId  タイマカウンタ識別                           */
/* 戻り値 : タイマカウンタ値                                    */
/*          タイマカウンタ識別が規定外の場合は0を返す           */
/* 概要   : タイマカウンタ値を提供する                          */
/* 制約   : なし                                                */
/* ============================================================ */
U2 FnU2_HwPph_Mtu_getTimerCounter(EN_HwPph_Mtu_IdTCNT tenId)
{
  U2 tu2Ret;

  tu2Ret = (((U1)tenId < CU1_HwPph_Mtu_SizeTblRegTCNT) ? *(CPU2A_HwPph_Mtu_TblRegTCNT[tenId]) : (U2)0);

  return (tu2Ret);
}


/* ============================================================ */
/* 関数名 : FnVD_HwPph_Mtu_setTimerCounter                      */
/*          タイマカウンタ設定                                  */
/* 引数   : tenId  タイマカウンタ識別                           */
/*          tu2Val 設定値                                       */
/* 戻り値 : なし                                                */
/* 概要   : タイマカウンタの設定を行う                          */
/* 制約   : タイマー停止中に実行すること                        */
/*          タイマカウンタ識別が規定外の場合は何もしない        */
/* ============================================================ */
VD FnVD_HwPph_Mtu_setTimerCounter(EN_HwPph_Mtu_IdTCNT tenId, U2 tu2Val)
{
  if ((U1)tenId < CU1_HwPph_Mtu_SizeTblRegTCNT) {
    *(CPU2A_HwPph_Mtu_TblRegTCNT[tenId]) = tu2Val;
  }
}


/* ============================================================ */
/* 関数名 : FnVD_HwPph_Mtu_setTimerGeneralRegister              */
/*          タイマジェネラルレジスタ設定                        */
/* 引数   : tenId  タイマジェネラルレジスタ識別                 */
/*          tu2Val 設定値                                       */
/* 戻り値 : なし                                                */
/* 概要   : タイマカウンタの設定を行う                          */
/* 制約   : タイマー停止中に実行すること                        */
/*          タイマカウンタ識別が規定外の場合は何もしない        */
/* ============================================================ */
VD FnVD_HwPph_Mtu_setTimerGeneralRegister(EN_HwPph_Mtu_IdTGR tenId, U2 tu2Val)
{
  if ((U1)tenId < CU1_HwPph_Mtu_SizeTblRegTGR) {
    *(CPU2A_HwPph_Mtu_TblRegTGR[tenId]) = tu2Val;
  }
}

