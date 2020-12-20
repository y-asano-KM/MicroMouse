/* ============================================================ */
/* ファイル名 : hw_srv_schedule.c                               */
/* 機能       : スケジューラを提供する                          */
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
#include "hw_srv_time.h"
#include "hw_srv_time_pac.h"
#include "hw_pph_clk_pac.h"
#include "hw_pph_cmt_pac.h"
#include "hw_pph_cmt_cfg_pac.h"
#include "hw_pph_intctrl_pac.h"
#include "hw_pph_intctrl_cfg_pac.h"

/* 本体 */
#include "hw_srv_schedule.h"
#include "hw_srv_schedule_pac.h"
#include "hw_srv_schedule_cfg_pac.h"


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */
#define CEN_HwSrv_Sche_Cmt_Unit_Int1ms            CEN_HwPph_Cmt_Unit_1
#define CST_HwSrv_Sche_Cmt_CfgUnit_Int1ms         CST_HwPph_Cmt_CfgUnit[CEN_HwSrv_Sche_Cmt_Unit_Int1ms]
#define CEN_HwSrv_Sche_IntCtrl_VecId_Int1ms       CEN_HwPph_IntCtrl_VecId_CMT1_CMI1
#define CEN_HwSrv_Sche_IntCtrl_Priority_Int1ms    CEN_HwPph_IntCtrl_CfgPriority_CMT1_CMI1
#define CU1_HwSrv_Sche_IntCtrl_EnbInt_Int1ms      ((U1)C_ON)
#define CU2_HwSrc_Sche_waitTimMainProc            ((U2)((FL)((FL)CU2_HwSrv_Sche_CfgMainProcPeriod / CFL_HwSrv_Time_ClkLsb)))

/* ============================================================ */
/* 型定義                                                       */
/* ============================================================ */


/* ============================================================ */
/* 関数プロトタイプ宣言(static)                                 */
/* ============================================================ */
static VD FnVD_HwSrv_Sche_initInt1msProc(VD);
static VD FnVD_HwSrv_Sche_initMainProc(VD);
static VD FnVD_HwSrv_Sche_waitMainProc(VD);


/* ============================================================ */
/* 変数定義(extern)                                             */
/* ============================================================ */


/* ============================================================ */
/* 変数定義(static)                                             */
/* ============================================================ */
/* メインスケジュール用定義 */
static U4 u4HwSrv_Sche_MainCnt;          /* [回]メインスケジュール実行回数 */
static U2 u2HwSrv_Sche_MainStaTim;       /* [クロック]メインスケジュール開始時刻 */
static U2 u2HwSrv_Sche_MainProcTim;      /* [us]メインスケジュール処理時間(LSB:CFL_HwSrv_Time_ClkLsb) */

/* 1ms定期割り込みスケジュール用定義 */
static U4 u4HwSrv_Sche_Int1msCnt;        /* [回]1ms定期割り込みケジュール実行回数 */
static U2 u2HwSrv_Sche_Int1msProcTim;    /* [us]1ms定期割り込みスケジュール処理時間(LSB:CFL_HwSrv_Time_ClkLsb) */


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
/* 関数名 : FnVD_HwSrv_Sche_initInt1msProc                      */
/*          1ms定期割り込みスケジュール初期化                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 1ms定期割り込みスケジュール初期化                   */
/* 制約   :                                                     */
/* ============================================================ */
static VD FnVD_HwSrv_Sche_initInt1msProc(VD)
{
  /* 1ms定期割り込みスケジュール実行回数クリア */
  u4HwSrv_Sche_Int1msCnt = (U4)0;

  /* 1ms定期割り込みスケジュール処理負荷クリア */
  u2HwSrv_Sche_Int1msProcTim = (U2)0;

  /* CMT機能設定 */
  FnVD_HwPph_Cmt_cfg(CEN_HwSrv_Sche_Cmt_Unit_Int1ms, &CST_HwSrv_Sche_Cmt_CfgUnit_Int1ms);

  /* 割り込み設定 */
  FnVD_HwPph_IntCtrl_setPriority(CEN_HwSrv_Sche_IntCtrl_VecId_Int1ms, CEN_HwSrv_Sche_IntCtrl_Priority_Int1ms);
  FnVD_HwPph_IntCtrl_setEnbInt(CEN_HwSrv_Sche_IntCtrl_VecId_Int1ms, CU1_HwSrv_Sche_IntCtrl_EnbInt_Int1ms);
  FnVD_HwPph_IntCtrl_clrIntReq(CEN_HwSrv_Sche_IntCtrl_VecId_Int1ms);

  /* CMTカウント動作開始 */
  FnVD_HwPph_Cmt_staCnt(CEN_HwSrv_Sche_Cmt_Unit_Int1ms);
}


/* ============================================================ */
/* 関数名 : FnVD_HwSrv_Sche_initMainProc                        */
/*          メインスケジュール初期化                            */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : メインスケジュール初期化                            */
/* 制約   :                                                     */
/* ============================================================ */
static VD FnVD_HwSrv_Sche_initMainProc(VD)
{
  /* メインスケジュール実行回数クリア */
  u4HwSrv_Sche_Int1msCnt = (U4)0;

  /* メインスケジュール開始時刻初期化 */
  u2HwSrv_Sche_MainStaTim = CU2_HwSrv_Time_ClkMax - CU2_HwSrc_Sche_waitTimMainProc;

  /* メインスケジュール処理負荷クリア */
  u2HwSrv_Sche_MainProcTim = (U2)0;
}


/* ============================================================ */
/* 関数名 : FnVD_HwSrv_Sche_waitMainProc                        */
/*          メインスケジュール待ち処理                          */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 定期処理にするための待ち処理を行う                  */
/* 制約   :                                                     */
/* ============================================================ */
static VD FnVD_HwSrv_Sche_waitMainProc(VD)
{
   U2 tu2TimPre;
   U2 tu2TimCur;
   U2 tu2TimElapsed;

   /* メイン開始時刻取得(前回値) */
   tu2TimPre = u2HwSrv_Sche_MainStaTim;

   /* 待ち処理 */
   if (CU1_HwSrv_Sche_CfgEnbWainMainProc == (U1)C_OFF) {
     tu2TimCur = McU2_HwSrv_Time_getClk();
   }
   else {
     do {
       tu2TimCur = McU2_HwSrv_Time_getClk();
       tu2TimElapsed = McU2_HwSrv_Time_calElapsedTime(tu2TimCur, tu2TimPre);
     } while (tu2TimElapsed < CU2_HwSrc_Sche_waitTimMainProc);
   }

   /* メイン開始時刻更新 */
   u2HwSrv_Sche_MainStaTim = tu2TimCur;
}


/* ============================================================ */
/* 関数名 : FnU4_HwSrv_Sche_getMainCnt                          */
/*          メインスケジュール実行回数取得                      */
/* 引数   : なし                                                */
/* 戻り値 : [回]メインスケジュール実行回数                      */
/* 概要   : メインスケジュール実行回数を提供する                */
/* 制約   :                                                     */
/* ============================================================ */
U4 FnU4_HwSrv_Sche_getMainCnt(VD)
{
  return (u4HwSrv_Sche_MainCnt);
}


/* ============================================================ */
/* 関数名 : FnU4_HwSrv_Sche_getInt1msCnt                        */
/*          1ms定期割り込みスケジュール実行回数取得             */
/* 引数   : なし                                                */
/* 戻り値 : [回]1ms定期割り込みスケジュール実行回数             */
/* 概要   : 1ms定期割り込みスケジュール実行回数を提供する       */
/* 制約   :                                                     */
/* ============================================================ */
U4 FnU4_HwSrv_Sche_getInt1msCnt(VD)
{
  return (u4HwSrv_Sche_Int1msCnt);
}


/* ============================================================ */
/* 関数名 : FnU2_HwSrv_Sche_getMainProcTim                      */
/*          メインスケジュール処理時間取得                      */
/* 引数   : なし                                                */
/* 戻り値 : [us]メインスケジュール処理時間                      */
/*              (LSB:CFL_HwSrv_Time_ClkLsb)                     */
/* 概要   : メインスケジュール処理時間を提供する                */
/* 制約   :                                                     */
/* ============================================================ */
U2 FnU2_HwSrv_Sche_getMainProcTim(VD)
{
  return (u2HwSrv_Sche_MainProcTim);
}


/* ============================================================ */
/* 関数名 : FnU2_HwSrv_Sche_getInt1msProcTim                    */
/*          1ms定期割り込みスケジュール処理時間取得             */
/* 引数   : なし                                                */
/* 戻り値 : [us]1ms定期割り込みスケジュール処理時間             */
/*              (LSB:CFL_HwSrv_Time_ClkLsb)                     */
/* 概要   : 1ms定期割り込みスケジュール処理時間を提供する       */
/* 制約   :                                                     */
/* ============================================================ */
U2 FnU2_HwSrv_Sche_getInt1msProcTim(VD)
{
  return (u2HwSrv_Sche_Int1msProcTim);
}


/* ============================================================ */
/* 関数名 : FnVD_HwSrv_Sche_wrapInitProc                        */
/*          初期化スケジュール                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : ユーザ初期化スケジュールを呼び出す                  */
/* 制約   : 割り込み禁止区間で呼び出すこと                      */
/*          割り込みを許可としないこと                          */
/* ============================================================ */
VD FnVD_HwSrv_Sche_wrapInitProc(VD)
{
  /* クロック設定 */
  FnVD_HwPph_Clk_cfg();

  /* CMT0,1モジュール停止遷移/解除 */
  FnVD_HwPph_Cmt_resetModuleStp(CEN_HwPph_Cmt_Unit_0);  /* 時刻提供用 */
  FnVD_HwPph_Cmt_resetModuleStp(CEN_HwPph_Cmt_Unit_1);  /* 1ms定期割り込みスケジュール */
  FnVD_HwPph_Cmt_stpModuleStp(CEN_HwPph_Cmt_Unit_2);    /* Memo:未使用 */
  FnVD_HwPph_Cmt_stpModuleStp(CEN_HwPph_Cmt_Unit_3);    /* Memo:未使用 */

  /* 時刻取得用タイマ初期化 */
  FnVD_HwSrv_Time_init();

  /* 1ms定期割り込みスケジューラ初期化 */
  FnVD_HwSrv_Sche_initInt1msProc();

  /* PF/APL初期化処理 */
  if (CPFnVD_HwSrv_Sche_CfgInitProc != CPVD_NULL) {
    CPFnVD_HwSrv_Sche_CfgInitProc();
  }

  /* メインスケジューラ初期化 */
  FnVD_HwSrv_Sche_initMainProc();

}


/* ============================================================ */
/* 関数名 : FnVD_HwSrv_Sche_wrapMainProc                        */
/*          メインスケジュール                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : ユーザメインスケジュールを呼び出す                  */
/* 制約   : 無限ループ(戻らない)                                */
/* ============================================================ */
VD FnVD_HwSrv_Sche_wrapMainProc(VD)
{
   U2 tu2TimEnd;

  /* 無限ループ */
  for ( ; ; ) {
    /* 待ち処理 */
    FnVD_HwSrv_Sche_waitMainProc();

    /* メインスケジュール実行回数カウント */
    u4HwSrv_Sche_MainCnt++;  /* ガード不要(オーバフロー/ラップアラウンド許容) */

    /* ユーザー定義のメインスケジュールコール */
    if (CPFnVD_HwSrv_Sche_CfgMainProc != CPVD_NULL) {
      CPFnVD_HwSrv_Sche_CfgMainProc();
    }

    /* メイン処理負荷取得 */
    tu2TimEnd = McU2_HwSrv_Time_getClk();
    u2HwSrv_Sche_MainProcTim = McU2_HwSrv_Time_calElapsedTime(tu2TimEnd, u2HwSrv_Sche_MainStaTim);
  }
}


/* ============================================================ */
/* 関数名 : FnVD_HwSrv_Sche_wrapInt1msProc                      */
/*          1ms定期割り込みスケジュール                         */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 1ms定期割り込みスケジュールを呼び出す               */
/* 制約   :                                                     */
/* ============================================================ */
VD FnVD_HwSrv_Sche_wrapInt1msProc(VD)
{
   U2 tu2TimSta;
   U2 tu2TimEnd;

  /* 1ms定期割り込み開始時刻更新 */
  tu2TimSta = McU2_HwSrv_Time_getClk();

  /* 1ms定期割り込みスケジュール実行回数カウント */
  u4HwSrv_Sche_Int1msCnt++;  /* ガード不要(オーバフロー/ラップアラウンド許容) */

  /* ユーザー定義の1ms定期割り込みスケジュールコール */
  if (CPFnVD_HwSrv_Sche_Cfg1msProc != CPVD_NULL) {
      CPFnVD_HwSrv_Sche_Cfg1msProc();
  }

  /* 1ms定期割り込み処理負荷取得 */
  tu2TimEnd = McU2_HwSrv_Time_getClk();
  u2HwSrv_Sche_Int1msProcTim = McU2_HwSrv_Time_calElapsedTime(tu2TimSta, tu2TimEnd);
}


