/* ============================================================ */
/* ファイル名 : pf_mtr_ctrl_eva.c                               */
/* 機能       : モータ制御(評価用)                              */
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
#if defined(OP_PfCmn_EvaMtrCtrl)
  #include "pf_switch_ctrl_pac.h"
#endif

/* 本体 */
#include "pf_mtr_ctrl_eva_pac.h"


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
#if defined(OP_PfCmn_EvaMtrCtrl)
/* ============================================================ */
/* 関数名 : FnVD_PfMtr_CtrlEva_mediate                          */
/*          モータ駆動要求調停処理(評価用)                      */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : モータ出力要求を評価用に生成する                    */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_PfMtr_CtrlEva_mediate(U1 * tpu1Enb, U1 * tpu1DirR, U1 * tpu1DirL, U2 * tpu2PeriodR, U2 * tpu2PeriodL, U2 * tpu2OnTimeR, U2 * tpu2OnTimeL)
{
  /* 中央タクトスイッチ瞬時値(2度読み)ONで始動, OFFで停止 */
  *tpu1Enb = FnU1_PfSwt_Ctrl_getTactSwtCenterMomentary();

  /* 左右タクトスイッチ短押しONで逆転、OFFで正転 */
  *tpu1DirR = FnU1_PfSwt_Ctrl_getTactSwtRightShortPush();
  *tpu1DirL = FnU1_PfSwt_Ctrl_getTactSwtLeftShortPush();

  /* 駆動周期設定 */
  *tpu2PeriodR = (U2)16000;      /* 右モータ：16ms周期(タイマ3MHz) */
  *tpu2PeriodL = (U2)16000;      /* 左モータ：16ms周期(タイマ3MHz) */
  *tpu2OnTimeR = (U2)15980;      /* 右モータ：パルス幅：60us */
  *tpu2OnTimeL = (U2)15980;      /* 右モータ：パルス幅：60us */
}
#endif
