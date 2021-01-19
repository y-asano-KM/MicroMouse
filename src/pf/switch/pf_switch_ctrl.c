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
/* [ms]各種スイッチON判定時間(短押し) */
#define CU2_PfSwt_Ctrl_TactSwtRightShortOnTime     ((U2)((U2)100 / (U2)CU1_PrjCmn_MainPeriod))
#define CU2_PfSwt_Ctrl_TactSwtCenterShortOnTime    ((U2)((U2)100 / (U2)CU1_PrjCmn_MainPeriod))
#define CU2_PfSwt_Ctrl_TactSwtLeftShortOnTime      ((U2)((U2)100 / (U2)CU1_PrjCmn_MainPeriod))

/* [ms]各種スイッチON判定時間(長押し) */
#define CU2_PfSwt_Ctrl_TactSwtRightLongOnTime      ((U2)((U2)3000 / (U2)CU1_PrjCmn_MainPeriod))
#define CU2_PfSwt_Ctrl_TactSwtCenterLongOnTime     ((U2)((U2)3000 / (U2)CU1_PrjCmn_MainPeriod))
#define CU2_PfSwt_Ctrl_TactSwtLeftLongOnTime       ((U2)((U2)3000 / (U2)CU1_PrjCmn_MainPeriod))

/* [ms]各種スイッチOFF判定時間 */
#define CU2_PfSwt_Ctrl_TactSwtRightOffTime         ((U2)((U2)20 / (U2)CU1_PrjCmn_MainPeriod))
#define CU2_PfSwt_Ctrl_TactSwtCenterOffTime        ((U2)((U2)20 / (U2)CU1_PrjCmn_MainPeriod))
#define CU2_PfSwt_Ctrl_TactSwtLeftOffTime          ((U2)((U2)20 / (U2)CU1_PrjCmn_MainPeriod))


/* ============================================================ */
/* 型定義                                                       */
/* ============================================================ */


/* ============================================================ */
/* 関数プロトタイプ宣言(static)                                 */
/* ============================================================ */
static VD FnVD_PfSwt_Ctrl_filterReadTwice(U1 * tpu1Filter, U1 * tpu1Prev, U1 tu1Cur);
static VD FnVD_PfSwt_Ctrl_filter(VD);
static VD FnVD_PfSwt_Ctrl_jdgMomentarySts(
  U1 * tpu1ShortOnFlag,
  U1 * tpu1LongOnFlag,
  U2 * tpu2OnTimer,
  U2 * tpu2OffTimer,
  U2 tu2ShortOnTime,
  U2 tu2LongOnTime,
  U2 tu2OffTime,
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


/* ---------------------------- */
/* タクトスイッチON/OFF継続時間 */
/* ---------------------------- */
static U2 u2PfSwt_Ctrl_TactSwtRightOnTimer;
static U2 u2PfSwt_Ctrl_TactSwtRightOffTimer;
static U2 u2PfSwt_Ctrl_TactSwtCenterOnTimer;
static U2 u2PfSwt_Ctrl_TactSwtCenterOffTimer;
static U2 u2PfSwt_Ctrl_TactSwtLeftOnTimer;
static U2 u2PfSwt_Ctrl_TactSwtLeftOffTimer;


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

  u2PfSwt_Ctrl_TactSwtRightOnTimer   = (U2)0;
  u2PfSwt_Ctrl_TactSwtRightOffTimer  = (U2)0;
  u2PfSwt_Ctrl_TactSwtCenterOnTimer  = (U2)0;
  u2PfSwt_Ctrl_TactSwtCenterOffTimer = (U2)0;
  u2PfSwt_Ctrl_TactSwtLeftOnTimer    = (U2)0;
  u2PfSwt_Ctrl_TactSwtLeftOffTimer   = (U2)0;
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
/* 引数   : tpu1ShortOnFlag  短押しフラグ                       */
/*          tpu1LongOnFlag   長押しフラグ                       */
/*          tpu2OnTimer      [ms]ON継続時間                     */
/*          tpu2OffTimer     [ms]OFF継続時間                    */
/*          tu2ShortOnTime   [ms]短押し判定時間                 */
/*          tu2LongOnTime    [ms]長押し判定時間                 */
/*          tu2OffTime       [ms]OFF判定時間                    */
/*                           (LSB:CU1_PrjCmn_MainPeriod)        */
/*          tu1Signal          スイッチ入力信号                 */
/* 戻り値 : なし                                                */
/* 概要   : 短押し/長押しを判定する                             */
/* 制約   : なし                                                */
/* ============================================================ */
static VD FnVD_PfSwt_Ctrl_jdgMomentarySts(
  U1 * tpu1ShortOnFlag,
  U1 * tpu1LongOnFlag,
  U2 * tpu2OnTimer,
  U2 * tpu2OffTimer,
  U2 tu2ShortOnTime,
  U2 tu2LongOnTime,
  U2 tu2OffTime,
  U1 tu1Signal
)
{
  U2 tu2OnTimer;
  U2 tu2OffTimer;
  U1 tu1ShortOnFlag;
  U1 tu1LongOnFlag;

  /* 前回値取得 */
  tu1ShortOnFlag = (*tpu1ShortOnFlag);
  tu1LongOnFlag  = (*tpu1LongOnFlag);
  tu2OnTimer  = (*tpu2OnTimer);
  tu2OffTimer = (*tpu2OffTimer);

  /* ON/OFF時間計測 */
  if (tu1Signal == (U1)C_OFF) {
    /* OFF継続時間をカウント */
    McXX_incU2Max(tu2OffTimer);

    /* 2度読み信号値がOFFが一定時間経過でON継続時間クリア */
    /* チャタリング対策で一定時間OFFが継続するまでON継続時間を保持する */
    if (tu2OffTimer >= tu2OffTime) {
      tu2OnTimer = (U2)0;
    }
  }
  else {
    /* ON継続時間をカウント */
    McXX_incU2Max(tu2OnTimer);

    /* 2度読み信号値がONで即OFF継続時間をクリア */
    tu2OffTimer = (U2)0;
  }

  /* モーメンタリースイッチ状態判定 */
  if ((*tpu2OnTimer) >= tu2LongOnTime) {
    /* 長押し時の処理 */
    /* ONが長時間継続後、OFFが一定時間継続でモード切替 */
    if (tu2OffTimer >= tu2OffTime) {
      tu1LongOnFlag = ((tu1LongOnFlag == (U1)C_OFF) ? (U1)C_ON : (U1)C_OFF);
    }
    else {
      /* 前回値保持 */
    }
  }
  else if ((*tpu2OnTimer) >= tu2ShortOnTime) {
    /* 短押し時の処理 */
    /* ONが短時間継続後、OFFが一定時間継続でモード切替 */
    if (tu2OffTimer >= tu2OffTime) {
      tu1ShortOnFlag = ((tu1ShortOnFlag == (U1)C_OFF) ? (U1)C_ON : (U1)C_OFF);
    }
    else {
      /* 前回値保持 */
    }
  }
  else {
    /* 前回値保持 */
  }

  /* 状態更新 */
  *tpu1ShortOnFlag = tu1ShortOnFlag;
  *tpu1LongOnFlag  = tu1LongOnFlag;
  *tpu2OnTimer  = tu2OnTimer;
  *tpu2OffTimer = tu2OffTimer;
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
    &u2PfSwt_Ctrl_TactSwtRightOnTimer,
    &u2PfSwt_Ctrl_TactSwtRightOffTimer,
    CU2_PfSwt_Ctrl_TactSwtRightShortOnTime,
    CU2_PfSwt_Ctrl_TactSwtRightLongOnTime,
    CU2_PfSwt_Ctrl_TactSwtRightOffTime,
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
    &u2PfSwt_Ctrl_TactSwtCenterOnTimer,
    &u2PfSwt_Ctrl_TactSwtCenterOffTimer,
    CU2_PfSwt_Ctrl_TactSwtCenterShortOnTime,
    CU2_PfSwt_Ctrl_TactSwtCenterLongOnTime,
    CU2_PfSwt_Ctrl_TactSwtCenterOffTime,
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
    &u2PfSwt_Ctrl_TactSwtLeftOnTimer,
    &u2PfSwt_Ctrl_TactSwtLeftOffTimer,
    CU2_PfSwt_Ctrl_TactSwtLeftShortOnTime,
    CU2_PfSwt_Ctrl_TactSwtLeftLongOnTime,
    CU2_PfSwt_Ctrl_TactSwtLeftOffTime,
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

