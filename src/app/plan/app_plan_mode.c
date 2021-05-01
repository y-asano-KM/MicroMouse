/* ============================================================ */
/* ファイル名 : app_plan_mode.c                                 */
/* 機能       :                                                 */
/* ============================================================ */
#define SECTION_APP

/* ============================================================ */
/* インクルード                                                 */
/* ============================================================ */
/* プロジェクト共通 */
#include "prj_cmn_section.h"
#include "prj_cmn_option.h"
#include "prj_cmn_type.h"
#include "prj_cmn_macro.h"

/* カテゴリ共通 */
#include "app_cmn_option.h"
#include "app_cmn_option_pac.h"

/* 個別 */
#include "app_map_pac.h"

/* 本体 */
#include "app_plan_mode.h"
#include "app_plan_mode_pac.h"


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */


/* ============================================================ */
/* 型定義                                                       */
/* ============================================================ */


/* ============================================================ */
/* 関数プロトタイプ宣言(static)                                 */
/* ============================================================ */


/* ============================================================ */
/* 変数定義(extern)                                             */
/* ============================================================ */
EN_AppPln_Mode_Sts enAppPln_Mode_Sts;     /* 走行モード */


/* ============================================================ */
/* 変数定義(static)                                             */
/* ============================================================ */
U1 u1AppPln_Mode_TactSwtRightShortPushPrev;   /* タクトスイッチRight短押し前回値 */
U1 u1AppPln_Mode_TactSwtLeftShortPushPrev;    /* タクトスイッチLeft短押し前回値 */
U1 u1AppPln_Mode_TactSwtCenterShortPushPrev;  /* タクトスイッチCenter短押し前回値 */


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
/* 関数名 : FnVD_AppPln_Mode_init                               */
/*          走行モードの初期化                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 走行モード遷移判定許可フラグ をOFFにする            */
/*          走行モードを通常モードにする                        */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_AppPln_Mode_init(VD)
{
  enAppPln_Mode_Sts                        = CEN_AppPln_Mode_StsReady;    /* 走行モード：準備モード */
  u1AppPln_Mode_TactSwtRightShortPushPrev  = (U1)C_OFF;                   /* タクトスイッチRight短押し前回値：オフ */
  u1AppPln_Mode_TactSwtLeftShortPushPrev   = (U1)C_OFF;                   /* タクトスイッチLeft短押し前回値：オフ */
  u1AppPln_Mode_TactSwtCenterShortPushPrev = (U1)C_OFF;                   /* タクトスイッチCenter短押し前回値：オフ */
}


/* ============================================================ */
/* 関数名 : FnVD_AppPln_Mode_jdgTransition                      */
/*          走行モード遷移判定                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 走行モード遷移判定                                  */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_AppPln_Mode_jdgTransition(VD)
{
  U1 tu1TactSwtRightShortPush;
  U1 tu1TactSwtLeftShortPush;
  U1 tu1TactSwtCenterShortPush;

  /* タクトスイッチR短押し状態チェック */
  tu1TactSwtRightShortPush  = FnU1_PfSwt_Ctrl_getTactSwtRightShortPush();

  /* タクトスイッチL短押し状態チェック */
  tu1TactSwtLeftShortPush   = FnU1_PfSwt_Ctrl_getTactSwtLeftShortPush();

  /* タクトスイッチC短押し状態チェック */
  tu1TactSwtCenterShortPush = FnU1_PfSwt_Ctrl_getTactSwtCenterShortPush();


  if (   (enAppPln_Mode_Sts == CEN_AppPln_Mode_StsSearch)
      && (tu1TactSwtCenterShortPush != u1AppPln_Mode_TactSwtCenterShortPushPrev)) {

    /* 走行モード：準備モード */
    enAppPln_Mode_Sts = CEN_AppPln_Mode_StsReady;
  }
  else if (   (enAppPln_Mode_Sts == CEN_AppPln_Mode_StsReady)
           && (tu1TactSwtCenterShortPush != u1AppPln_Mode_TactSwtCenterShortPushPrev)) {

    /* 走行モード：探索モード */
    enAppPln_Mode_Sts = CEN_AppPln_Mode_StsSearch;
  }
  else if (   (   (enAppPln_Mode_Sts == CEN_AppPln_Mode_StsSearch)
               && (   (u1AppPln_Mode_TactSwtLeftShortPushPrev == (U1)C_OFF)
                   || (tu1TactSwtLeftShortPush == (U1)C_ON)))
           || (   (enAppPln_Mode_Sts == CEN_AppPln_Mode_StsTimeAttack)
               && (tu1TactSwtCenterShortPush != u1AppPln_Mode_TactSwtCenterShortPushPrev))) {

    /* 走行モード：待機モード */
#if (0)
    enAppPln_Mode_Sts = CEN_AppPln_Mode_StsStay;
#endif
  }
  else if (   (enAppPln_Mode_Sts == CEN_AppPln_Mode_StsStay)
           && (tu1TactSwtCenterShortPush != u1AppPln_Mode_TactSwtCenterShortPushPrev)) {

    /* 走行モード：計測モード */
    enAppPln_Mode_Sts = CEN_AppPln_Mode_StsTimeAttack;
  }
  else if (   (enAppPln_Mode_Sts == CEN_AppPln_Mode_StsTimeAttack)
           && (tu1TactSwtCenterShortPush != u1AppPln_Mode_TactSwtCenterShortPushPrev)) {

    /* 走行モード：完了モード */
#if (0)
    enAppPln_Mode_Sts = CEN_AppPln_Mode_StsFinish;
#endif
  }
  else {
    /* なにもしない */
  }

  /* タクトスイッチ短押し状態前回値を更新する */
  u1AppPln_Mode_TactSwtRightShortPushPrev  = tu1TactSwtRightShortPush;
  u1AppPln_Mode_TactSwtLeftShortPushPrev   = tu1TactSwtLeftShortPush;
  u1AppPln_Mode_TactSwtCenterShortPushPrev = tu1TactSwtCenterShortPush;
}


/* ============================================================ */
/* 関数名 : FnEN_AppPln_Mode_get                                */
/*          走行モードの提供                                    */
/* 引数   : なし                                                */
/* 戻り値 : 走行モード                                          */
/* 概要   : 走行モードの提供                                    */
/* 制約   : なし                                                */
/* ============================================================ */
EN_AppPln_Mode_Sts FnEN_AppPln_Mode_get(VD)
{
  return (enAppPln_Mode_Sts);
}

