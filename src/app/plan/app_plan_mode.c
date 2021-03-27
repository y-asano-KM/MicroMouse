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
U1 u1_mode_transition_permit;        /* 動作モード遷移判定許可フラグ */
U1 u1_mode;                          /* 動作モード */

/* ============================================================ */
/* 変数定義(static)                                             */
/* ============================================================ */
U1 u1_TactSwtRightShortPush_last;
U1 u1_TactSwtLeftShortPush_last;


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
/*          動作モードの初期化                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 動作モード遷移判定許可フラグ をOFFにする            */
/*          動作モードを通常モードにする                        */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_AppPln_Mode_init(VD)
{
  u1_mode_transition_permit = (U1)C_OFF;
  u1_mode = (U1)CEN_AppPln_Mode_Normal;
  u1_TactSwtRightShortPush_last = (U1)C_OFF;
  u1_TactSwtLeftShortPush_last = (U1)C_OFF;

}

/* ============================================================ */
/* 関数名 : FnVD_AppPln_Mode_transition_permit_judge            */
/*          動作モード遷移判定許可判定                          */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 動作モード遷移判定許可判定                          */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_AppPln_Mode_transition_permit_judge(VD)
{
  U1 tu1_TactSwtCenterShortPush;

 /* タクトスイッチC短押し状態チェック */
  tu1_TactSwtCenterShortPush = FnU1_PfSwt_Ctrl_getTactSwtCenterShortPush();
 
  if (tu1_TactSwtCenterShortPush == (U1)C_ON) {
    u1_mode_transition_permit = (U1)C_ON;
  }
  else {
    u1_mode_transition_permit = (U1)C_OFF;
  }
}

/* ============================================================ */
/* 関数名 : FnVD_AppPln_Mode_transition_judge                   */
/*          動作モード遷移判定                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 動作モード遷移判定                                  */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_AppPln_Mode_transition_judge(VD)
{
  U1 tu1_TactSwtRightShortPush;
  U1 tu1_TactSwtLeftShortPush;

 /* タクトスイッチR短押し状態チェック */
  tu1_TactSwtRightShortPush = FnU1_PfSwt_Ctrl_getTactSwtRightShortPush();
 /* タクトスイッチL短押し状態チェック */
  tu1_TactSwtLeftShortPush = FnU1_PfSwt_Ctrl_getTactSwtLeftShortPush();

  if ((u1_mode_transition_permit == (U1)C_ON)        /* 動作モード遷移判定許可フラグ：許可 */
       && ((u1_TactSwtRightShortPush_last == (U1)C_OFF) /* タクトスイッチR短押し状態(前回値)：オフ */
           && (tu1_TactSwtRightShortPush == (U1)C_ON))){ /* タクトスイッチR短押し状態(今回値)：オン */

    /* 動作モードを1段階繰り上げる */
    if ((u1_mode + (U1)1) >= (U1)CEN_AppPln_Mode_Num) {
      u1_mode = (U1)0;
    }
    else {
      u1_mode += (U1)1;
    }

  }
  else if ((u1_mode_transition_permit == (U1)C_ON)       /* 動作モード遷移判定許可フラグ：許可 */
            && ((u1_TactSwtLeftShortPush_last == (U1)C_OFF) /* タクトスイッチL短押し状態(前回値)：オフ */
                && (tu1_TactSwtLeftShortPush == (U1)C_ON))){ /* タクトスイッチL短押し状態(今回値)：オン */

    /* 動作モードを1段階繰り下げる */
    if (u1_mode <= (U1)0) {
      u1_mode = (U1)CEN_AppPln_Mode_Num - (U1)1;
    }
    else {
      u1_mode -= (U1)1;
    }

  }
  else {
    /* なにもしない */
  }

  /* タクトスイッチ短押し状態前回値を更新する */
  u1_TactSwtRightShortPush_last = tu1_TactSwtRightShortPush;
  u1_TactSwtLeftShortPush_last = tu1_TactSwtLeftShortPush;

}

/* ============================================================ */
/* 関数名 : FnEN_AppPln_Mode_get                                */
/*          動作モードの提供                                    */
/* 引数   : なし                                                */
/* 戻り値 : 動作モード                                          */
/* 概要   : 動作モードの提供                                    */
/* 制約   : なし                                                */
/* ============================================================ */
EN_AppPln_Mode FnEN_AppPln_Mode_get(VD)
{
  return((EN_AppPln_Mode)u1_mode);
  /* return(CEN_AppPln_Mode_Normal); */
}


