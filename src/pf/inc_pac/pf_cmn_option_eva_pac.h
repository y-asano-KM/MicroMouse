#if !defined(INCLUDED_pf_cmn_option_eva_pac_h)
#define INCLUDED_pf_cmn_option_eva_pac_h
/* ================================================== */
/* ファイル名 : pf_cmn_option_eva_pac.h               */
/* 機能       : PFオプション定義(評価用)              */
/* ================================================== */

/* ================================================== */
/* インクルード                                       */
/* ================================================== */
#include "prj_cmn_option.h"


/* ================================================== */
/* 評価用オプション定義                               */
/* ================================================== */
/* ------------- */
/* 評価用LED調停 */
/* ------------- */
/* 評価用機能 */
#define OP_PfCmn_EvaLedMediation

/* LEDによる壁検知確認機能 */
#define OP_PfCmn_EvaLedMediation_RaySens

/* LEDによるSW入力確認機能 (0:短押し/長押し, 1:瞬時値) */
#define OP_PfCmn_EvaLedMediation_Sw         (1)

/* LEDによるモータパルス数入力確認機能 */
/* #define OP_PfCmn_EvaLedMediation_Mtr */

/* ---------------- */
/* 評価用モータ調停 */
/* ---------------- */
/* 評価用機能 */
/* #define OP_PfCmn_EvaMtrCtrl */


/* ================================================== */
/* オプションチェック                                 */
/* ================================================== */
#if !defined(OP_PfCmn_EvaLedMediation)
  #if defined(OP_PfCmn_EvaLedMediation_RaySens)
    #error  /* 規定外の組み合わせ */
  #endif
  #if defined(OP_PfCmn_EvaLedMediation_Sw)
    #error  /* 規定外の組み合わせ */
  #endif
  #if defined(OP_PfCmn_EvaLedMediation_Mtr)
    #error  /* 規定外の組み合わせ */
  #endif
#endif


#endif
