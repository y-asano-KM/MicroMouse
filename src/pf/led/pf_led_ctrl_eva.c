/* ============================================================ */
/* ファイル名 : pf_led_ctrl_eva.c                               */
/* 機能       : LED制御(評価用)                                 */
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
#if defined(OP_PfCmn_EvaLedMediation)
  #include "pf_sche_if_pac.h"
  #if defined(OP_PfCmn_EvaLedMediation_Sw)
    #include "pf_switch_ctrl_pac.h"
  #endif
  #if defined(OP_PfCmn_EvaLedMediation_RaySens)
    #include "pf_raysens_if.h"
  #endif
  #if defined(OP_PfCmn_EvaLedMediation_Mtr)
    #include "pf_mtr_if_pac.h"
  #endif
#endif

#include "app_plan_mode_pac.h"

/* 本体 */
#include "pf_led_ctrl_eva_pac.h"



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


#if defined(OP_PfCmn_EvaLedMediation)
/* ============================================================ */
/* 関数名 : FnVD_PfLed_CtrlEva_mediate                          */
/*          LED消灯/点灯要求調停処理(評価用)                    */
/* 引数   : tpu1Req0  LED0点灯要求(0:消灯, 1:点灯)              */
/*          tpu1Req1  LED1点灯要求(0:消灯, 1:点灯)              */
/*          tpu1Req2  LED2点灯要求(0:消灯, 1:点灯)              */
/*          tpu1Req3  LED3点灯要求(0:消灯, 1:点灯)              */
/* 戻り値 : なし                                                */
/* 概要   : 各種点灯条件/消灯条件の優先度より出力値を調停する   */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_PfLed_CtrlEva_mediate(U1 * tpu1Req0, U1 * tpu1Req1, U1 * tpu1Req2, U1 * tpu1Req3)
{
  U4 tu4MainCnt;
  U4 tu4Int1msCnt;
  #if defined(OP_PfCmn_EvaLedMediation_RaySens)
  U2 tu2RaySensR;
  U2 tu2RaySensFR;
  U2 tu2RaySensFL;
  U2 tu2RaySensL;
  #endif
  #if defined(OP_PfCmn_EvaLedMediation_Mtr)
  U2 tu2PlusCntR;
  U2 tu2PlusCntL;
  #endif
  #if defined(OP_PfCmn_EvaLedMediation_Sw)
    #if (OP_PfCmn_EvaLedMediation_Sw == 0)
  U1 tu1TactSwtRS;
  U1 tu1TactSwtCS;
  U1 tu1TactSwtLS;
  U1 tu1TactSwtRL;
  U1 tu1TactSwtCL;
  U1 tu1TactSwtLL;
    #else
  U1 tu1TactSwtRM;
  U1 tu1TactSwtCM;
  U1 tu1TactSwtLM;
    #endif
  #endif
  U1 tu1LedReq0;
  U1 tu1LedReq1;
  U1 tu1LedReq2;
  U1 tu1LedReq3;

  /* 前処理 */
  tu1LedReq0 = (*tpu1Req0);
  tu1LedReq1 = (*tpu1Req1);
  tu1LedReq2 = (*tpu1Req2);
  tu1LedReq3 = (*tpu1Req3);

  /* 確認用LED点灯処理 */
  /* メイン処理/1ms割り込み処理実行回数取得 */
  tu4MainCnt   = FnU4_PfSche_If_getMainCnt();
  tu4Int1msCnt = FnU4_PfSche_If_getInt1msCnt();

  /* 基本パターン */
  /* LED0,3:640ms周期(疑似2Hz), LED1,2:256ms周期(疑似4Hz) */
  tu1LedReq0 = (((U4)(tu4MainCnt & (U4)0x00000040) == (U4)0) ? (U1)C_ON : (U1)C_OFF);
  tu1LedReq1 = (((U4)(tu4Int1msCnt & (U4)0x00000080) == (U4)0) ? (U1)C_ON : (U1)C_OFF);
  tu1LedReq2 = tu1LedReq1;
  tu1LedReq3 = tu1LedReq0;

  #if defined(OP_PfCmn_EvaLedMediation_Sw)
    #if (OP_PfCmn_EvaLedMediation_Sw == 0)
  /* タクトスイッチ取得(短押し/長押し) */
  tu1TactSwtRS = FnU1_PfSwt_Ctrl_getTactSwtRightShortPush();
  tu1TactSwtCS = FnU1_PfSwt_Ctrl_getTactSwtCenterShortPush();
  tu1TactSwtLS = FnU1_PfSwt_Ctrl_getTactSwtLeftShortPush();
  tu1TactSwtRL = FnU1_PfSwt_Ctrl_getTactSwtRightLongPush();
  tu1TactSwtCL = FnU1_PfSwt_Ctrl_getTactSwtCenterLongPush();
  tu1TactSwtLL = FnU1_PfSwt_Ctrl_getTactSwtLeftLongPush();

  /* 短押しで消灯 */
  tu1LedReq0 = ((tu1TactSwtLS == (U1)C_OFF) ? tu1LedReq0 : (U1)C_OFF);
  tu1LedReq1 = ((tu1TactSwtCS == (U1)C_OFF) ? tu1LedReq1 : (U1)C_OFF);
  tu1LedReq2 = ((tu1TactSwtCS == (U1)C_OFF) ? tu1LedReq2 : (U1)C_OFF);
  tu1LedReq3 = ((tu1TactSwtRS == (U1)C_OFF) ? tu1LedReq3 : (U1)C_OFF);

  /* 長押しで点灯 */
  tu1LedReq0 = ((tu1TactSwtLL == (U1)C_OFF) ? tu1LedReq0 : (U1)C_ON);
  tu1LedReq1 = ((tu1TactSwtCL == (U1)C_OFF) ? tu1LedReq1 : (U1)C_ON);
  tu1LedReq2 = ((tu1TactSwtCL == (U1)C_OFF) ? tu1LedReq2 : (U1)C_ON);
  tu1LedReq3 = ((tu1TactSwtRL == (U1)C_OFF) ? tu1LedReq3 : (U1)C_ON);
    #else
  tu1TactSwtRM = FnU1_PfSwt_Ctrl_getTactSwtRightMomentary();
  tu1TactSwtCM = FnU1_PfSwt_Ctrl_getTactSwtCenterMomentary();
  tu1TactSwtLM = FnU1_PfSwt_Ctrl_getTactSwtLeftMomentary();
 
  /* SW ONで消灯 */
  tu1LedReq0 = ((tu1TactSwtLM == (U1)C_OFF) ? tu1LedReq0 : (U1)C_OFF);
  tu1LedReq1 = ((tu1TactSwtCM == (U1)C_OFF) ? tu1LedReq1 : (U1)C_OFF);
  tu1LedReq2 = ((tu1TactSwtCM == (U1)C_OFF) ? tu1LedReq2 : (U1)C_OFF);
  tu1LedReq3 = ((tu1TactSwtRM == (U1)C_OFF) ? tu1LedReq3 : (U1)C_OFF);
    #endif
  #endif
    
  #if defined(OP_PfCmn_EvaLedMediation_RaySens)
  /* センサ電圧値取得 */
  tu2RaySensR  = FnU2_PfRaySens_If_getValRight();
  tu2RaySensFR = FnU2_PfRaySens_If_getValFrontRight();
  tu2RaySensFL = FnU2_PfRaySens_If_getValFrontLeft();
  tu2RaySensL  = FnU2_PfRaySens_If_getValLeft();

  /* 壁検出で消灯 */
  tu1LedReq0 = ((tu2RaySensL  > (U2)30) ? (U1)C_OFF : tu1LedReq0);
  tu1LedReq1 = ((tu2RaySensFL > (U2)30) ? (U1)C_OFF : tu1LedReq1);
  tu1LedReq2 = ((tu2RaySensFR > (U2)30) ? (U1)C_OFF : tu1LedReq2);
  tu1LedReq3 = ((tu2RaySensR  > (U2)30) ? (U1)C_OFF : tu1LedReq3);

  /* 動作モード */
  /* tu1LedReq0 = ((u1_mode == (U1)CEN_AppPln_Mode_Normal) ? (U1)C_OFF : tu1LedReq0); */  /* 通常で消灯 */
  /* tu1LedReq1 = ((u1_mode == (U1)CEN_AppPln_Mode_Search) ? (U1)C_OFF : tu1LedReq1); */  /* 探索で消灯 */
  /* tu1LedReq3 = ((u1_mode_transition_permit == (U1)C_ON) ? (U1)C_OFF : tu1LedReq3); */  /* 動作モード遷移判定許可フラグOFFで消灯 */

  #endif

  #if defined(OP_PfCmn_EvaLedMediation_Mtr)
  /* モータパルス数取得 */
  tu2PlusCntR = FnU2_PfMtr_If_getRightMtrPulseCount();
  tu2PlusCntL = FnU2_PfMtr_If_getLeftMtrPulseCount();

  /* モータパルス数取得用割り込み発生で消灯 */
  tu1LedReq0 = ((tu2PlusCntL > (U2)200) ? (U1)C_OFF : tu1LedReq0);
  tu1LedReq3 = ((tu2PlusCntR > (U2)100) ? (U1)C_OFF : tu1LedReq3);
  #endif

  /* 調停結果反映 */
  *tpu1Req0 = tu1LedReq0;
  *tpu1Req1 = tu1LedReq1;
  *tpu1Req2 = tu1LedReq2;
  *tpu1Req3 = tu1LedReq3;
}
#endif

