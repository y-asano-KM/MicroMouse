/* ============================================================ */
/* ファイル名 : pf_switch_ctrl.c                                */
/* 機能       : スイッチ入力制御                                */
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
#include "pf_switch_if_pac.h"

/* 本体 */
#include "pf_switch_ctrl_pac.h"


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */
/* [ms]各種スイッチ短押し判定時間 */
#define CU2_PfSwt_Ctrl_TactSwtRightShortPushTime     ((U2)((U2)100 / (U2)CU1_PrjCmn_MainPeriod))
#define CU2_PfSwt_Ctrl_TactSwtCenterShortPushTime    ((U2)((U2)100 / (U2)CU1_PrjCmn_MainPeriod))
#define CU2_PfSwt_Ctrl_TactSwtLeftShortPushTime      ((U2)((U2)100 / (U2)CU1_PrjCmn_MainPeriod))

/* [ms]各種スイッチ長押し判定時間 */
#define CU2_PfSwt_Ctrl_TactSwtRightLongPushTime      ((U2)((U2)3000 / (U2)CU1_PrjCmn_MainPeriod))
#define CU2_PfSwt_Ctrl_TactSwtCenterLongPushTime     ((U2)((U2)3000 / (U2)CU1_PrjCmn_MainPeriod))
#define CU2_PfSwt_Ctrl_TactSwtLeftLongPushTime       ((U2)((U2)3000 / (U2)CU1_PrjCmn_MainPeriod))


/* ============================================================ */
/* 型定義                                                       */
/* ============================================================ */


/* ============================================================ */
/* 関数プロトタイプ宣言(static)                                 */
/* ============================================================ */
static VD FnVD_PfSwt_Ctrl_filterReadTwice(U1 * tpu1Filter, U1 * tpu1Prev, U1 tu1Cur);
static VD FnVD_PfSwt_Ctrl_filter(VD);
static VD FnVD_PfSwt_Ctrl_jdgMomentarySts(
  U1 * tpu1PushShortFlag,
  U1 * tpu1PushLongFlag,
  U2 * tpu2Timer,
  U2 tu2PushShortTime,
  U2 tu2PushLongTime,
  U1 tu1Signal
);
static VD FnVD_PfSwt_Ctrl_jdgMomentaryStsTactSwtProc(VD);


/* ============================================================ */
/* 変数定義(extern)                                             */
/* ============================================================ */


/* ============================================================ */
/* 変数定義(static)                                             */
/* ============================================================ */
/* ------------------------------ */
/* タクトスイッチ信号(生値)前回値 */
/* ------------------------------ */
static F1 f1PfSwt_Ctrl_SignalRawPrev;

/* 右側タクトスイッチ(生値) */
#define fPfSwt_Ctrl_TactSwtRightRawPrev     f1PfSwt_Ctrl_SignalRawPrev.Flag.fBit0

/* 中央タクトスイッチ(生値) */
#define fPfSwt_Ctrl_TactSwtCenterRawPrev    f1PfSwt_Ctrl_SignalRawPrev.Flag.fBit1

/* 左側タクトスイッチ(生値) */
#define fPfSwt_Ctrl_TactSwtLeftRawPrev      f1PfSwt_Ctrl_SignalRawPrev.Flag.fBit2

/* ------------------ */
/* タクトスイッチ信号 */
/* ------------------ */
static F1 f1PfSwt_Ctrl_Signal;

/* 右側タクトスイッチ(モーメンタリースイッチ) */
#define fPfSwt_Ctrl_TactSwtRightMomentary   f1PfSwt_Ctrl_Signal.Flag.fBit0

/* 中央タクトスイッチ(モーメンタリースイッチ) */
#define fPfSwt_Ctrl_TactSwtCenterMomentary  f1PfSwt_Ctrl_Signal.Flag.fBit1

/* 左側タクトスイッチ(モーメンタリースイッチ) */
#define fPfSwt_Ctrl_TactSwtLeftMomentary    f1PfSwt_Ctrl_Signal.Flag.fBit2

/* -------------------------- */
/* タクトスイッチ信号(短押し) */
/* -------------------------- */
static F1 f1PfSwt_Ctrl_SignalShort;

/* タクトスイッチ(短押し) */
#define fPfSwt_Ctrl_TactSwtRightShort       f1PfSwt_Ctrl_SignalShort.Flag.fBit0

/* タクトスイッチ(短押し) */
#define fPfSwt_Ctrl_TactSwtCenterShort      f1PfSwt_Ctrl_SignalShort.Flag.fBit1

/* タクトスイッチ(短押し) */
#define fPfSwt_Ctrl_TactSwtLeftShort        f1PfSwt_Ctrl_SignalShort.Flag.fBit2

/* -------------------------- */
/* タクトスイッチ信号(長押し) */
/* -------------------------- */
static F1 f1PfSwt_Ctrl_SignalLong;

/* タクトスイッチ(短押し) */
#define fPfSwt_Ctrl_TactSwtRightLong        f1PfSwt_Ctrl_SignalLong.Flag.fBit0

/* タクトスイッチ(短押し) */
#define fPfSwt_Ctrl_TactSwtCenterLong       f1PfSwt_Ctrl_SignalLong.Flag.fBit1

/* タクトスイッチ(短押し) */
#define fPfSwt_Ctrl_TactSwtLeftLong         f1PfSwt_Ctrl_SignalLong.Flag.fBit2


/* ---------------------- */
/* タクトスイッチ押下時間 */
/* ---------------------- */
static U2 u2PfSwt_Ctrl_TactSwtRightPushTimer;
static U2 u2PfSwt_Ctrl_TactSwtCenterPushTimer;
static U2 u2PfSwt_Ctrl_TactSwtLeftPushTimer;


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
/* 関数名 : FnVD_PfSwt_Ctrl_init                                */
/*          スイッチ入力制御処理初期化                          */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : スイッチ入力制御処理の初期化を行う                  */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_PfSwt_Ctrl_init(VD)
{
  /* Memo:fPfSwt_Ctrl_TactSwtRightRawPrevの初期化を兼ねる */
  /* Memo:fPfSwt_Ctrl_TactSwtCenterRawPrevの初期化を兼ねる */
  /* Memo:fPfSwt_Ctrl_TactSwtLeftRawPrevの初期化を兼ねる */
  f1PfSwt_Ctrl_SignalRawPrev.u1Val = (U1)0x00;

  /* Memo:fPfSwt_Ctrl_TactSwtRightMomentaryの初期化を兼ねる */
  /* Memo:fPfSwt_Ctrl_TactSwtCenterMomentaryの初期化を兼ねる */
  /* Memo:fPfSwt_Ctrl_TactSwtLeftMomentaryの初期化を兼ねる */
  f1PfSwt_Ctrl_Signal.u1Val        = (U1)0x00;

  /* Memo:fPfSwt_Ctrl_TactSwtRightShortの初期化を兼ねる */
  /* Memo:fPfSwt_Ctrl_TactSwtCenterShortの初期化を兼ねる */
  /* Memo:fPfSwt_Ctrl_TactSwtLeftShortの初期化を兼ねる */
  f1PfSwt_Ctrl_SignalShort.u1Val   = (U1)0x00;

  /* Memo:fPfSwt_Ctrl_TactSwtRightLongの初期化を兼ねる */
  /* Memo:fPfSwt_CtrlTactSwtCenterLongの初期化を兼ねる */
  /* Memo:fPfSwt_Ctrl_TactSwtLeftLongの初期化を兼ねる */
  f1PfSwt_Ctrl_SignalLong.u1Val    = (U1)0x00;

  u2PfSwt_Ctrl_TactSwtRightPushTimer  = (U2)0;
  u2PfSwt_Ctrl_TactSwtCenterPushTimer = (U2)0;
  u2PfSwt_Ctrl_TactSwtLeftPushTimer   = (U2)0;
}


/* ============================================================ */
/* 関数名 : FnVD_PfSwt_Ctrl_filterReadTwice                     */
/*          2度読み処理                                         */
/* 引数   : tpu1Filter  信号(フィルター後)                      */
/*          tpu1Prev    信号(前回値)                            */
/*          tu1Cur      信号(今回値)                            */
/* 戻り値 : なし                                                */
/* 概要   : 2度読みフィルターをかける                           */
/* 制約   : なし                                                */
/* ============================================================ */
static VD FnVD_PfSwt_Ctrl_filterReadTwice(U1 * tpu1Filter, U1 * tpu1Prev, U1 tu1Cur)
{
  U1 tu1Edge;

  /* エッジ取得(立ち上がり/立ち下がりの両エッジ) */
  tu1Edge = tu1Cur ^ (*tpu1Prev);

  /* 2度読みフィルター処理 */
  /* 生値が2周期同じレベルの場合はフィルター値更新 */
  /* 生値が2周期で異なるレベルの場合はフィルター値前回値を保持 */
  *tpu1Filter = (U1)((U1)((*tpu1Filter) & tu1Edge) | (U1)(tu1Cur & (U1)~tu1Edge));

  /* 前回値更新 */
  *tpu1Prev = tu1Cur;
}


/* ============================================================ */
/* 関数名 : FnVD_PfSwt_Ctrl_proc                                */
/*          スイッチ信号フィルター処理                          */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : スイッチ信号にフィルターをかける                    */
/* 制約   : なし                                                */
/* ============================================================ */
static VD FnVD_PfSwt_Ctrl_filter(VD)
{
  F1 tf1SignalRawCur;

  tf1SignalRawCur.u1Val = (U1)0x00;
  tf1SignalRawCur.Flag.fBit0 = FnU1_PfSwt_If_getTactSwtRightRaw();
  tf1SignalRawCur.Flag.fBit1 = FnU1_PfSwt_If_getTactSwtCenterRaw();
  tf1SignalRawCur.Flag.fBit2 = FnU1_PfSwt_If_getTactSwtLeftRaw();

  FnVD_PfSwt_Ctrl_filterReadTwice(&f1PfSwt_Ctrl_Signal.u1Val, &f1PfSwt_Ctrl_SignalRawPrev.u1Val, tf1SignalRawCur.u1Val);
}


/* ============================================================ */
/* 関数名 : FnVD_PfSwt_Ctrl_jdgMomentarySts                     */
/*          モーメンタリースイッチ状態判定                      */
/* 引数   : tpu1PushShortFlag  短押しフラグ                     */
/*          tpu1PushLongFlag   長押しフラグ                     */
/*          tpu2Timer          [ms]押下タイマ                   */
/*          tu2PushShortTime   [ms]短押し判定時間               */
/*          tu2PushLongTime    [ms]長押しフラグ                 */
/*          tu1Signal          スイッチ入力信号                 */
/* 戻り値 : なし                                                */
/* 概要   : 短押し/長押しを判定する                             */
/* 制約   : なし                                                */
/* ============================================================ */
static VD FnVD_PfSwt_Ctrl_jdgMomentarySts(
  U1 * tpu1PushShortFlag,
  U1 * tpu1PushLongFlag,
  U2 * tpu2Timer,
  U2 tu2PushShortTime,
  U2 tu2PushLongTime,
  U1 tu1Signal
)
{
  U2 tu2PushTim;
  U1 tu1PushShortFlag;
  U1 tu1PushLongFlag;

  /* 前回値取得 */
  tu1PushShortFlag = (*tpu1PushShortFlag);
  tu1PushLongFlag  = (*tpu1PushLongFlag);
  tu2PushTim = (*tpu2Timer);

  /* 押下時間計測 */
  if (tu1Signal == (U1)C_OFF) {
    tu2PushTim = (U2)0;
  }
  else {
    McXX_incU2Max(tu2PushTim);
  }

  /* モーメンタリースイッチ状態判定 */
  if ((*tpu2Timer) >= tu2PushLongTime) {
    /* 長押し時の処理 */
    if (tu1Signal == (U1)C_OFF) {
      tu1PushLongFlag = ((tu1PushLongFlag == (U1)C_OFF) ? (U1)C_ON : (U1)C_OFF);
    }
    else {
      /* 前回値保持 */
    }
  }
  else if ((*tpu2Timer) >= tu2PushShortTime) {
    /* 長押し時の処理 */
    if (tu1Signal == (U1)C_OFF) {
      tu1PushShortFlag = ((tu1PushShortFlag == (U1)C_OFF) ? (U1)C_ON : (U1)C_OFF);
    }
    else {
      /* 前回値保持 */
    }
  }
  else {
    /* 前回値保持 */
  }

  /* 状態更新 */
  *tpu1PushShortFlag = tu1PushShortFlag;
  *tpu1PushLongFlag  = tu1PushLongFlag;
  *tpu2Timer = tu2PushTim;
}


/* ============================================================ */
/* 関数名 : FnVD_PfSwt_Ctrl_jdgMomentaryStsTactSwtProc          */
/*          モーメンタリースイッチ状態判定(タクトスイッチ用)    */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 短押し/長押しを判定する                             */
/* 制約   : なし                                                */
/* ============================================================ */
static VD FnVD_PfSwt_Ctrl_jdgMomentaryStsTactSwtProc(VD)
{
  U1 tu1PushShortFlag;
  U1 tu1PushLongFlag;

  /* 押下状態判定(右側スイッチ) */
  tu1PushShortFlag = fPfSwt_Ctrl_TactSwtRightShort;
  tu1PushLongFlag  = fPfSwt_Ctrl_TactSwtRightLong;
  FnVD_PfSwt_Ctrl_jdgMomentarySts(
    &tu1PushShortFlag,
    &tu1PushLongFlag,
    &u2PfSwt_Ctrl_TactSwtRightPushTimer,
    CU2_PfSwt_Ctrl_TactSwtRightShortPushTime,
    CU2_PfSwt_Ctrl_TactSwtRightLongPushTime,
    fPfSwt_Ctrl_TactSwtRightMomentary
  );
  fPfSwt_Ctrl_TactSwtRightShort = tu1PushShortFlag;
  fPfSwt_Ctrl_TactSwtRightLong  = tu1PushLongFlag;

  /* 押下状態判定(中央スイッチ) */
  tu1PushShortFlag = fPfSwt_Ctrl_TactSwtCenterShort;
  tu1PushLongFlag  = fPfSwt_Ctrl_TactSwtCenterLong;
  FnVD_PfSwt_Ctrl_jdgMomentarySts(
    &tu1PushShortFlag,
    &tu1PushLongFlag,
    &u2PfSwt_Ctrl_TactSwtCenterPushTimer,
    CU2_PfSwt_Ctrl_TactSwtCenterShortPushTime,
    CU2_PfSwt_Ctrl_TactSwtCenterLongPushTime,
    fPfSwt_Ctrl_TactSwtCenterMomentary
  );
  fPfSwt_Ctrl_TactSwtCenterShort = tu1PushShortFlag;
  fPfSwt_Ctrl_TactSwtCenterLong  = tu1PushLongFlag;

  /* 押下状態判定(左側スイッチ) */
  tu1PushShortFlag = fPfSwt_Ctrl_TactSwtLeftShort;
  tu1PushLongFlag  = fPfSwt_Ctrl_TactSwtLeftLong;
  FnVD_PfSwt_Ctrl_jdgMomentarySts(
    &tu1PushShortFlag,
    &tu1PushLongFlag,
    &u2PfSwt_Ctrl_TactSwtLeftPushTimer,
    CU2_PfSwt_Ctrl_TactSwtLeftShortPushTime,
    CU2_PfSwt_Ctrl_TactSwtLeftLongPushTime,
    fPfSwt_Ctrl_TactSwtLeftMomentary
  );
  fPfSwt_Ctrl_TactSwtLeftShort = tu1PushShortFlag;
  fPfSwt_Ctrl_TactSwtLeftLong  = tu1PushLongFlag;
}


/* ============================================================ */
/* 関数名 : FnVD_PfSwt_Ctrl_proc                                */
/*          スイッチ入力制御処理                                */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : スイッチ入力制御処理                                */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_PfSwt_Ctrl_proc(VD)
{
  /* スイッチ信号フィルター処理 */
  FnVD_PfSwt_Ctrl_filter();

  /* モーメンタリースイッチ状態判定(タクトスイッチ用) */
  FnVD_PfSwt_Ctrl_jdgMomentaryStsTactSwtProc();
}


/* ============================================================ */
/* 関数名 : FnU1_PfSwt_Ctrl_getTactSwtRightMomentary            */
/*          右側タクトスイッチ信号取得(瞬時値)                  */
/* 引数   : なし                                                */
/* 戻り値 : 右側タクトスイッチ信号(瞬時値) (0:OFF, 1:ON)        */
/* 概要   : 右側タクトスイッチ信号(瞬時値)を提供する            */
/* 制約   : なし                                                */
/* ============================================================ */
U1 FnU1_PfSwt_Ctrl_getTactSwtRightMomentary(VD)
{
  return (fPfSwt_Ctrl_TactSwtRightMomentary);
}


/* ============================================================ */
/* 関数名 : FnU1_PfSwt_Ctrl_getTactSwtCenterMomentary           */
/*          中央タクトスイッチ信号取得(瞬時値)                  */
/* 引数   : なし                                                */
/* 戻り値 : 中央タクトスイッチ信号(瞬時値) (0:OFF, 1:ON)        */
/* 概要   : 中央タクトスイッチ信号(瞬時値)を提供する            */
/* 制約   : なし                                                */
/* ============================================================ */
U1 FnU1_PfSwt_Ctrl_getTactSwtCenterMomentary(VD)
{
  return (fPfSwt_Ctrl_TactSwtCenterMomentary);
}


/* ============================================================ */
/* 関数名 : FnU1_PfSwt_Ctrl_getTactSwtLeftMomentary             */
/*          左側タクトスイッチ信号取得(瞬時値)                  */
/* 引数   : なし                                                */
/* 戻り値 : 左側タクトスイッチ信号(瞬時値) (0:OFF, 1:ON)        */
/* 概要   : 左側タクトスイッチ信号(瞬時値)を提供する            */
/* 制約   : なし                                                */
/* ============================================================ */
U1 FnU1_PfSwt_Ctrl_getTactSwtLeftMomentary(VD)
{
  return (fPfSwt_Ctrl_TactSwtLeftMomentary);
}


/* ============================================================ */
/* 関数名 : FnU1_PfSwt_Ctrl_getTactSwtRightShortPush            */
/*          右側タクトスイッチ信号取得(短押し)                  */
/* 引数   : なし                                                */
/* 戻り値 : 右側タクトスイッチ信号(短押し) (0:OFF, 1:ON)        */
/* 概要   : 右側タクトスイッチ信号(短押し)を提供する            */
/* 制約   : なし                                                */
/* ============================================================ */
U1 FnU1_PfSwt_Ctrl_getTactSwtRightShortPush(VD)
{
  return (fPfSwt_Ctrl_TactSwtRightShort);
}


/* ============================================================ */
/* 関数名 : FnU1_PfSwt_Ctrl_getTactSwtCenterShortPush           */
/*          中央タクトスイッチ信号取得(短押し)                  */
/* 引数   : なし                                                */
/* 戻り値 : 中央タクトスイッチ信号(短押し) (0:OFF, 1:ON)        */
/* 概要   : 中央タクトスイッチ信号(短押し)を提供する            */
/* 制約   : なし                                                */
/* ============================================================ */
U1 FnU1_PfSwt_Ctrl_getTactSwtCenterShortPush(VD)
{
  return (fPfSwt_Ctrl_TactSwtCenterShort);
}


/* ============================================================ */
/* 関数名 : FnU1_PfSwt_Ctrl_getTactSwtLeftShortPush             */
/*          左側タクトスイッチ信号取得(短押し)                  */
/* 引数   : なし                                                */
/* 戻り値 : 左側タクトスイッチ信号(短押し) (0:OFF, 1:ON)        */
/* 概要   : 左側タクトスイッチ信号(短押し)を提供する            */
/* 制約   : なし                                                */
/* ============================================================ */
U1 FnU1_PfSwt_Ctrl_getTactSwtLeftShortPush(VD)
{
  return (fPfSwt_Ctrl_TactSwtLeftShort);
}


/* ============================================================ */
/* 関数名 : FnU1_PfSwt_Ctrl_getTactSwtRightLongPush             */
/*          右側タクトスイッチ信号取得(長押し)                  */
/* 引数   : なし                                                */
/* 戻り値 : 右側タクトスイッチ信号(長押し) (0:OFF, 1:ON)        */
/* 概要   : 右側タクトスイッチ信号(長押し)を提供する            */
/* 制約   : なし                                                */
/* ============================================================ */
U1 FnU1_PfSwt_Ctrl_getTactSwtRightLongPush(VD)
{
  return (fPfSwt_Ctrl_TactSwtRightLong);
}


/* ============================================================ */
/* 関数名 : FnU1_PfSwt_Ctrl_getTactSwtCenterLongPush            */
/*          中央タクトスイッチ信号取得(長押し)                  */
/* 引数   : なし                                                */
/* 戻り値 : 中央タクトスイッチ信号(長押し) (0:OFF, 1:ON)        */
/* 概要   : 中央タクトスイッチ信号(長押し)を提供する            */
/* 制約   : なし                                                */
/* ============================================================ */
U1 FnU1_PfSwt_Ctrl_getTactSwtCenterLongPush(VD)
{
  return (fPfSwt_Ctrl_TactSwtCenterLong);
}


/* ============================================================ */
/* 関数名 : FnU1_PfSwt_Ctrl_getTactSwtLeftLongPush              */
/*          左側タクトスイッチ信号取得(長押し)                  */
/* 引数   : なし                                                */
/* 戻り値 : 左側タクトスイッチ信号(長押し) (0:OFF, 1:ON)        */
/* 概要   : 左側タクトスイッチ信号(長押し)を提供する            */
/* 制約   : なし                                                */
/* ============================================================ */
U1 FnU1_PfSwt_Ctrl_getTactSwtLeftLongPush(VD)
{
  return (fPfSwt_Ctrl_TactSwtLeftLong);
}

