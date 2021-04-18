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
U1 u1_mode;                          /* 走行モード */

/* ============================================================ */
/* 変数定義(static)                                             */
/* ============================================================ */
U1 u1_TactSwtRightShortPush_last;   /* タクトスイッチRight短押し前回値 */
U1 u1_TactSwtLeftShortPush_last;    /* タクトスイッチLeft短押し前回値 */
U1 u1_TactSwtCenterShortPush_last;  /* タクトスイッチCenter短押し前回値 */


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
/* 関数名 : McU1_XxYyy_getSignal                                */
/*          関数和名をここへ記述                                */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 関数箱型コメントの形式を示す                        */
/* 制約   : なし                                                */
/* ============================================================ */


/* ============================================================ */
/* 関数定義                                                     */
/* ============================================================ */
/* ============================================================ */
/* 関数名 : FnEN_AppPln_Mode_init                               */
/*          走行モードの初期化                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 走行モード遷移判定許可フラグ をOFFにする            */
/*          走行モードを通常モードにする                        */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_AppPln_Mode_init(VD)
{
  u1_mode = (U1)CEN_AppPln_Mode_Ready;         /* 走行モード：準備モード */
  u1_TactSwtRightShortPush_last = (U1)C_OFF;   /* タクトスイッチRight短押し前回値：オフ */
  u1_TactSwtLeftShortPush_last = (U1)C_OFF;    /* タクトスイッチLeft短押し前回値：オフ */
  u1_TactSwtCenterShortPush_last = (U1)C_OFF;  /* タクトスイッチCenter短押し前回値：オフ */

}

/* ============================================================ */
/* 関数名 : FnVD_AppPln_Mode_transition_judge                   */
/*          走行モード遷移判定                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 走行モード遷移判定                                  */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_AppPln_Mode_transition_judge(VD)
{
  U1 tu1_TactSwtRightShortPush;
  U1 tu1_TactSwtLeftShortPush;
  U1 tu1_TactSwtCenterShortPush;

 /* タクトスイッチR短押し状態チェック */
  tu1_TactSwtRightShortPush = FnU1_PfSwt_Ctrl_getTactSwtRightShortPush();
 /* タクトスイッチL短押し状態チェック */
  tu1_TactSwtLeftShortPush = FnU1_PfSwt_Ctrl_getTactSwtLeftShortPush();
 /* タクトスイッチC短押し状態チェック */
  tu1_TactSwtCenterShortPush = FnU1_PfSwt_Ctrl_getTactSwtCenterShortPush();


  if ((u1_mode == (U1)CEN_AppPln_Mode_Search)       /* 走行モード = 探索モード */
       && (tu1_TactSwtCenterShortPush != u1_TactSwtCenterShortPush_last)){ /* タクトスイッチC短押し状態 != タクトスイッチC短押し状態(前回値) */

    /* 走行モード：準備モード */
    u1_mode = (U1)CEN_AppPln_Mode_Ready;
  }
  else if ((u1_mode == (U1)CEN_AppPln_Mode_Ready)       /* 走行モード = 準備モード */
       && (tu1_TactSwtCenterShortPush != u1_TactSwtCenterShortPush_last)){ /* タクトスイッチC短押し状態 != タクトスイッチC短押し状態(前回値) */

    /* 走行モード：探索モード */
    u1_mode = (U1)CEN_AppPln_Mode_Search;
  }
  else if (((u1_mode == (U1)CEN_AppPln_Mode_Search)           /* 走行モード = 探索モード */
             && ((u1_TactSwtLeftShortPush_last == (U1)C_OFF)  /* ←仮  ゴールに達した */
                  || (tu1_TactSwtLeftShortPush == (U1)C_ON))) /* ←仮  探索時間タイムアップ */
        || ((u1_mode == (U1)CEN_AppPln_Mode_TimeAttack)                           /* 走行モード = 計測モード */
             && (tu1_TactSwtCenterShortPush != u1_TactSwtCenterShortPush_last))){ /* タクトスイッチC短押し状態 != タクトスイッチC短押し状態(前回値) */

    /* 走行モード：待機モード */
    /* u1_mode = (U1)CEN_AppPln_Mode_Stay; */
  }
  else if ((u1_mode == (U1)CEN_AppPln_Mode_Stay)                           /* 走行モード = 待機モード */
       && (tu1_TactSwtCenterShortPush != u1_TactSwtCenterShortPush_last)){ /* タクトスイッチC短押し状態 != タクトスイッチC短押し状態(前回値) */

    /* 走行モード：計測モード */
    u1_mode = (U1)CEN_AppPln_Mode_TimeAttack;
  }
  else if ((u1_mode == (U1)CEN_AppPln_Mode_TimeAttack)                     /* 走行モード = 計測モード */
       && (tu1_TactSwtCenterShortPush != u1_TactSwtCenterShortPush_last)){ /* ←仮  ゴールに達した */

    /* 走行モード：完了モード */
    /* u1_mode = (U1)CEN_AppPln_Mode_Finish; */
  }
  else {
    /* なにもしない */
  }

  /* タクトスイッチ短押し状態前回値を更新する */
  u1_TactSwtRightShortPush_last = tu1_TactSwtRightShortPush;
  u1_TactSwtLeftShortPush_last = tu1_TactSwtLeftShortPush;
  u1_TactSwtCenterShortPush_last = tu1_TactSwtCenterShortPush;

}

/* ============================================================ */
/* 関数名 : FnEN_AppPln_Mode_get                                */
/*          走行モードの提供                                    */
/* 引数   : なし                                                */
/* 戻り値 : 走行モード                                          */
/* 概要   : 走行モードの提供                                    */
/* 制約   : なし                                                */
/* ============================================================ */
EN_AppPln_Mode FnEN_AppPln_Mode_get(VD)
{
  return((EN_AppPln_Mode)u1_mode);
  /* return(CEN_AppPln_Mode_Search); */
}


