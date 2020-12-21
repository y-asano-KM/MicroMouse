/* ============================================================ */
/* ファイル名 : hw_srv_time.c                                   */
/* 機能       : 時刻処理                                        */
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
#include "hw_pph_cmt_pac.h"
#include "hw_pph_cmt_cfg_pac.h"
#include "hw_pph_intctrl_pac.h"
#include "hw_pph_intctrl_cfg_pac.h"

/* 本体 */
#include "hw_srv_time.h"
#include "hw_srv_time_pac.h"


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */
#define CEN_HwSrv_Time_Cmt_Unit            CEN_HwPph_Cmt_Unit_0
#define CST_HwSrv_Time_Cmt_CfgUnit         CST_HwPph_Cmt_CfgUnit[CEN_HwSrv_Time_Cmt_Unit]
#define CEN_HwSrv_Time_IntCtrl_VecId       CEN_HwPph_IntCtrl_VecId_CMT0_CMI0
#define CEN_HwSrv_Time_IntCtrl_Priority    CEN_HwPph_IntCtrl_CfgPriority_CMT0_CMI0
#define CU1_HwSrv_Time_IntCtrl_EnbInt      ((U1)C_OFF)


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
/* ============================================================ */
/* 関数名 : FnVD_HwSrv_Time_init                                */
/*          時刻初期化                                          */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : タイマーを初期化する                                */
/* 制約   :                                                     */
/* ============================================================ */
VD FnVD_HwSrv_Time_init(VD)
{
  /* CMT機能設定 */
  FnVD_HwPph_Cmt_cfg(CEN_HwSrv_Time_Cmt_Unit, &CST_HwSrv_Time_Cmt_CfgUnit);

  /* 割り込み設定 */
  FnVD_HwPph_IntCtrl_setPriority(CEN_HwSrv_Time_IntCtrl_VecId, CEN_HwSrv_Time_IntCtrl_Priority);
  FnVD_HwPph_IntCtrl_setEnbInt(CEN_HwSrv_Time_IntCtrl_VecId, CU1_HwSrv_Time_IntCtrl_EnbInt);
  FnVD_HwPph_IntCtrl_clrIntReq(CEN_HwSrv_Time_IntCtrl_VecId);

  /* CMTカウント動作開始 */
  FnVD_HwPph_Cmt_staCnt(CEN_HwSrv_Time_Cmt_Unit);
}

