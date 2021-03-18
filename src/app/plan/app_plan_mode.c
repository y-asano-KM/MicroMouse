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


/* ============================================================ */
/* 変数定義(static)                                             */
/* ============================================================ */
static U1 u1_mode_transition_permit;        /* 動作モード遷移判定許可フラグ */
static U1 u1_mode;                          /* 動作モード */


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
  U1 tu1_zero;
  U1 tu1_one;

  tu1_TactSwtRightShortPush = FnU1_PfSwt_Ctrl_getTactSwtRightShortPush();
  tu1_TactSwtLeftShortPush = FnU1_PfSwt_Ctrl_getTactSwtLeftShortPush();
  tu1_zero = 0;
  tu1_one = 1;

  if ((u1_mode_transition_permit == (U1)C_ON)        /* 動作モード遷移判定許可フラグチェック */
       && (tu1_TactSwtRightShortPush == (U1)C_ON)) { /* タクトスイッチR短押し状態チェック */

    /* 動作モードを1段階繰り上げる */
    if ((u1_mode + tu1_one) >= (U1)CEN_AppPln_Mode_Num) {
      u1_mode = tu1_zero;
    }
    else {
      u1_mode += tu1_one;
    }

    /* 動作モード遷移判定許可フラグ をOFFにする */
    u1_mode_transition_permit = (U1)C_OFF;
  }
  else if ((u1_mode_transition_permit == (U1)C_ON)       /* 動作モード遷移判定許可フラグチェック */
            && (tu1_TactSwtLeftShortPush == (U1)C_ON)) { /* タクトスイッチL短押し状態チェック */

    /* 動作モードを1段階繰り下げる */
    if (u1_mode <= tu1_zero) {
      u1_mode = (U1)CEN_AppPln_Mode_Num - tu1_one;
    }
    else {
      u1_mode -= tu1_one;
    }

    /* 動作モード遷移判定許可フラグ をOFFにする */
    u1_mode_transition_permit = (U1)C_OFF;
  }
  else {
    /* なにもしない */
  }

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
  /* return((EN_AppPln_Mode)u1_mode); */
  return(CEN_AppPln_Mode_Normal);
}


