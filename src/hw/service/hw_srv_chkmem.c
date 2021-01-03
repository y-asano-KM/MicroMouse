/* ============================================================ */
/* ファイル名 : hw_srv_chkmem.c                                 */
/* 機能       : メモリ監視                                      */
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
#include "hw_srv_termination.h"
#include "hw_srv_termination_cfg_pac.h"

/* 本体 */
#include "hw_srv_chkmem_cfg_pac.h"
#include "hw_srv_chkmem_pac.h"


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */
/* スタックオーバフローチェック用埋め込みデータ */
#define CU4_HwSrv_ChkMem_StackOverFlowChkCode       ((U4)0x5555AAAA)

/* 終了コード */
#define CU4_HwSrv_ChkMem_EndCodeIntStackOverFlow    CU4_HwSrv_Termination_CfgCodeIntStackOverFlow
#define CU4_HwSrv_ChkMem_EndCodeUsrStackOverFlow    CU4_HwSrv_Termination_CfgCodeUsrStackOverFlow


/* ============================================================ */
/* 型定義                                                       */
/* ============================================================ */


/* ============================================================ */
/* 関数プロトタイプ宣言(static)                                 */
/* ============================================================ */
static VD FnVD_HwSrv_ChkMem_initStackChk(VD);


/* ============================================================ */
/* 変数定義(extern)                                             */
/* ============================================================ */


/* ============================================================ */
/* 変数定義(static)                                             */
/* ============================================================ */
static F1 f1HwSrv_ChkMem_Sts;
#define fHwSrv_ChkMem_StsIntStackOverFlow  f1HwSrv_ChkMem_Sts.Flag.fBit0
#define fHwSrv_ChkMem_StsUsrStackOverFlow  f1HwSrv_ChkMem_Sts.Flag.fBit1


/* ============================================================ */
/* const変数定義(extern)                                        */
/* ============================================================ */


/* ============================================================ */
/* const変数定義(static)                                        */
/* ============================================================ */
static volatile U4 * const CPU4_HwSrv_ChkMem_StackIntBegin = (volatile U4 *)__sectop("SI_BEGIN");
static volatile U4 * const CPU4_HwSrv_ChkMem_StackIntEnd   = (volatile U4 *)__sectop("SI_END");
static volatile U4 * const CPU4_HwSrv_ChkMem_StackUsrBegin = (volatile U4 *)__sectop("SU_BEGIN");
static volatile U4 * const CPU4_HwSrv_ChkMem_StackUsrEnd   = (volatile U4 *)__sectop("SU_END");


/* ============================================================ */
/* 関数形式マクロ定義                                           */
/* ============================================================ */


/* ============================================================ */
/* 関数定義                                                     */
/* ============================================================ */


/* ============================================================ */
/* 関数名 : FnVD_HwSrv_ChkMem_initStackChk                      */
/*          スタックチェック初期化                              */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : スタックオーバフローチェック用にデータを埋め込む    */
/* 制約   :                                                     */
/* ============================================================ */
static VD FnVD_HwSrv_ChkMem_initStackChk(VD)
{
  /* SI用 */
  (*CPU4_HwSrv_ChkMem_StackIntBegin) = CU4_HwSrv_ChkMem_StackOverFlowChkCode;
  (*CPU4_HwSrv_ChkMem_StackIntEnd)   = CU4_HwSrv_ChkMem_StackOverFlowChkCode;

  /* SU用 */
  (*CPU4_HwSrv_ChkMem_StackUsrBegin) = CU4_HwSrv_ChkMem_StackOverFlowChkCode;
  (*CPU4_HwSrv_ChkMem_StackUsrEnd)   = CU4_HwSrv_ChkMem_StackOverFlowChkCode;

  /* ステータスフラグクリア */
  fHwSrv_ChkMem_StsIntStackOverFlow = (U1)C_OFF;
  fHwSrv_ChkMem_StsUsrStackOverFlow = (U1)C_OFF;
}


/* ============================================================ */
/* 関数名 : FnVD_HwSrv_ChkMem_init                              */
/*          メモリ監視初期化                                    */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : メモリ監視を初期化する                              */
/* 制約   :                                                     */
/* ============================================================ */
VD FnVD_HwSrv_ChkMem_init(VD)
{
  /* ステータスフラグクリア */
  f1HwSrv_ChkMem_Sts.u1Val = (U1)0x00;

  /* スタックチェック初期化 */
  FnVD_HwSrv_ChkMem_initStackChk();
}


/* ============================================================ */
/* 関数名 : FnVD_HwSrv_ChkMem_chkStackOverFlow                  */
/*          スタックオーバフローチェック                        */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : スタックのオーバーフローを確認する                  */
/* 制約   : 割り込み禁止が解除される                            */
/* ============================================================ */
static VD FnVD_HwSrv_ChkMem_chkStackOverFlow(VD)
{
  /* 割り込み禁止 */
  DI();

  /* SIオーバフロー確認(下限) */
  if ((*CPU4_HwSrv_ChkMem_StackIntBegin) != CU4_HwSrv_ChkMem_StackOverFlowChkCode) {
    fHwSrv_ChkMem_StsIntStackOverFlow = (U1)C_ON;
    if (CU1_HwSrv_ChkMem_CfgEnbIntStackCheckErr == (U1)C_ON) {
      FnVD_HwSrv_Termination_kill(CU4_HwSrv_ChkMem_EndCodeIntStackOverFlow);
    }
  };

  /* SIオーバフロー確認(上限) */
  if ((*CPU4_HwSrv_ChkMem_StackIntEnd) != CU4_HwSrv_ChkMem_StackOverFlowChkCode) {
    fHwSrv_ChkMem_StsIntStackOverFlow = (U1)C_ON;
    if (CU1_HwSrv_ChkMem_CfgEnbIntStackCheckErr == (U1)C_ON) {
      FnVD_HwSrv_Termination_kill(CU4_HwSrv_ChkMem_EndCodeIntStackOverFlow);
    }
  };

  /* SUオーバフロー確認(下限) */
  if ((*CPU4_HwSrv_ChkMem_StackUsrBegin) != CU4_HwSrv_ChkMem_StackOverFlowChkCode) {
    fHwSrv_ChkMem_StsUsrStackOverFlow = (U1)C_ON;
    if (CU1_HwSrv_ChkMem_CfgEnbUsrStackCheckErr == (U1)C_ON) {
      FnVD_HwSrv_Termination_kill(CU4_HwSrv_ChkMem_EndCodeIntStackOverFlow);
    }
  };

  /* SUオーバフロー確認(上限) */
  if ((*CPU4_HwSrv_ChkMem_StackUsrEnd) != CU4_HwSrv_ChkMem_StackOverFlowChkCode) {
    fHwSrv_ChkMem_StsUsrStackOverFlow = (U1)C_ON;
    if (CU1_HwSrv_ChkMem_CfgEnbUsrStackCheckErr == (U1)C_ON) {
      FnVD_HwSrv_Termination_kill(CU4_HwSrv_ChkMem_EndCodeIntStackOverFlow);
    }
  };

  /* 割り込み許可 */
  EI();
}


/* ============================================================ */
/* 関数名 : FnVD_HwSrv_ChkMem_proc                              */
/*          メモリ監視処理                                      */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : メモリ監視を行う                                    */
/* 制約   :                                                     */
/* ============================================================ */
VD FnVD_HwSrv_ChkMem_proc(VD)
{
  /* スタックオーバフローチェック */
  FnVD_HwSrv_ChkMem_chkStackOverFlow();

  /* ToDo:RAMのWrite/Readチェックを実装したい */

  /* ToDo:ROMのCRCチェックを実装したい */
}


/* ============================================================ */
/* 関数名 : FnU1_HwSrv_ChkMem_getIntStackOverFlowFlg            */
/*          SIスタックオーバフローフラグ取得                    */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : SIスタックオーバフロー確認結果を提供する            */
/* 制約   :                                                     */
/* ============================================================ */
U1 FnU1_HwSrv_ChkMem_getIntStackOverFlowFlg(VD)
{
  return (fHwSrv_ChkMem_StsIntStackOverFlow);
}


/* ============================================================ */
/* 関数名 : FnU1_HwSrv_ChkMem_getUsrStackOverFlowFlg            */
/*          SUスタックオーバフローフラグ取得                    */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : SUスタックオーバフロー確認結果を提供する            */
/* 制約   :                                                     */
/* ============================================================ */
U1 FnU1_HwSrv_ChkMem_getUsrStackOverFlowFlg(VD)
{
  return (fHwSrv_ChkMem_StsUsrStackOverFlow);
}

