/* ============================================================ */
/* ファイル名 : pf_mtr_ctrl.c                                   */
/* 機能       : モータ制御                                      */
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
#include "app_controll.h"

/* 本体 */
#include "pf_mtr_ctrl_pac.h"
#if defined(OP_PfCmn_EvaMtrCtrl)
  #include "pf_mtr_ctrl_eva_pac.h"
#endif


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
/* モータ制御許可フラグ */
static U1 u1PfMtr_Ctrl_CtrlEnb;

/* -------- */
/* 右モータ */
/* -------- */
/* 回転方向 */
static U1 u1PfMtr_Ctrl_RightMtrRotDir;

/* [us]駆動周期 */
static U2 u2PfMtr_Ctrl_RightMtrPeriod;

/* [us]ON時間 */
static U2 u2PfMtr_Ctrl_RightMtrOnTime;


/* -------- */
/* 左モータ */
/* -------- */
/* 回転方向 */
static U1 u1PfMtr_Ctrl_LeftMtrRotDir;

/* [us]駆動周期 */
static U2 u2PfMtr_Ctrl_LeftMtrPeriod;

/* [us]ON時間 */
static U2 u2PfMtr_Ctrl_LeftMtrOnTime;


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
/* 関数名 : FnVD_PfMtr_Ctrl_init                                */
/*          モータ制御初期化                                    */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : モータ制御の初期化を行う                            */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_PfMtr_Ctrl_init(VD)
{
  /* モータ制御許可フラグ初期化 */
  u1PfMtr_Ctrl_CtrlEnb = (U1)C_OFF;

  /* -------- */
  /* 右モータ */
  /* -------- */
  /* 回転方向初期化 */
  u1PfMtr_Ctrl_RightMtrRotDir = (U1)C_OFF;

  /* 駆動周期初期化 */
  u2PfMtr_Ctrl_RightMtrPeriod = (U2)0;

  /* ON時間初期化 */
  u2PfMtr_Ctrl_RightMtrOnTime = (U2)0;

  /* -------- */
  /* 左モータ */
  /* -------- */
  /* 回転方向初期化 */
  u1PfMtr_Ctrl_LeftMtrRotDir = (U1)C_OFF;

  /* 駆動周期初期化 */
  u2PfMtr_Ctrl_LeftMtrPeriod = (U2)0;

  /* ON時間初期化 */
  u2PfMtr_Ctrl_LeftMtrOnTime = (U2)0;
}


/* ============================================================ */
/* 関数名 : FnVD_PfMtr_Ctrl_mediate                             */
/*          モータ駆動要求調停処理                              */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : モータ出力要求を評価用に生成する                    */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_PfMtr_Ctrl_mediate(VD)
{
  U2 tu2PeriodR;      /* 右モータ駆動周期 */
  U2 tu2OnTimeR;      /* 右モータON時間 */
  U2 tu2PeriodL;      /* 左モータ駆動周期 */
  U2 tu2OnTimeL;      /* 左モータON時間 */
  U1 tu1DirR;         /* 右モータ回転方向 */
  U1 tu1DirL;         /* 左モータ回転方向 */
  U1 tu1Enb;          /* モータ制御許可フラグ */

#if (1)
  /* ToDo:暫定処置 */
  tu1Enb     = u1_g_get_MtrPowerMode();  /* 駆動許可禁止 */
  tu1DirR    = u1_g_get_MtrModeR();  /* 右モータ：回転方向 */
  tu1DirL    = u1_g_get_MtrModeL();  /* 左モータ：回転方向 */
  tu2PeriodR = (U2)16000;  /* 右モータ：16ms周期(タイマ3MHz) 暫定 */
  tu2PeriodL = (U2)16000;  /* 左モータ：16ms周期(タイマ3MHz) 暫定 */
  tu2OnTimeR = (U2)15980;  /* 右モータ：パルス幅：60us 暫定 */
  tu2OnTimeL = (U2)15980;  /* 右モータ：パルス幅：60us 暫定 */
#endif
#if defined(OP_PfCmn_EvaMtrCtrl)
  /* モータ駆動要求調停処理(評価用) */
  FnVD_PfMtr_CtrlEva_mediate(&tu1Enb,
                             &tu1DirR,    &tu1DirL,
                             &tu2PeriodR, &tu2PeriodL,
                             &tu2OnTimeR, &tu2OnTimeL);
#endif

  /* 要求設定 */
  u1PfMtr_Ctrl_CtrlEnb        = tu1Enb;
  u1PfMtr_Ctrl_RightMtrRotDir = tu1DirR;
  u1PfMtr_Ctrl_LeftMtrRotDir  = tu1DirL;
  u2PfMtr_Ctrl_RightMtrPeriod = tu2PeriodR;
  u2PfMtr_Ctrl_LeftMtrPeriod  = tu2PeriodL;
  u2PfMtr_Ctrl_RightMtrOnTime = tu2OnTimeR;
  u2PfMtr_Ctrl_LeftMtrOnTime  = tu2OnTimeL;
}


/* ============================================================ */
/* 関数名 : FnU1_PfMtr_Ctrl_getCtrlEnb                          */
/*          モータ制御許可フラグ取得                            */
/* 引数   : なし                                                */
/* 戻り値 : モータ制御許可フラグ (0:禁止, 1:許可)               */
/* 概要   : モータ制御許可フラグを提供する                      */
/* 制約   : なし                                                */
/* ============================================================ */
U1 FnU1_PfMtr_Ctrl_getCtrlEnb(VD)
{
  return (u1PfMtr_Ctrl_CtrlEnb);
}


/* ============================================================ */
/* 関数名 : FnU1_PfMtr_Ctrl_getRightMtrRotDirReq                */
/*          右モータ回転方向要求取得                            */
/* 引数   : なし                                                */
/* 戻り値 : 右モータ回転方向 (0:正転, 1:逆転)                   */
/* 概要   : 右モータ回転方向要求を提供する                      */
/* 制約   : なし                                                */
/* ============================================================ */
U1 FnU1_PfMtr_Ctrl_getRightMtrRotDirReq(VD)
{
  return (u1PfMtr_Ctrl_RightMtrRotDir);
}


/* ============================================================ */
/* 関数名 : FnU2_PfMtr_Ctrl_getRightMtrPeriod                   */
/*          右モータ駆動周期要求取得                            */
/* 引数   : なし                                                */
/* 戻り値 : [us]右モータ駆動周期                                */
/* 概要   : 右モータ駆動周期を提供する                          */
/* 制約   : なし                                                */
/* ============================================================ */
U2 FnU2_PfMtr_Ctrl_getRightMtrPeriod(VD)
{
  return (u2PfMtr_Ctrl_RightMtrPeriod);
}


/* ============================================================ */
/* 関数名 : FnU2_PfMtr_Ctrl_getRightMtrPeriod                   */
/*          右モータON時間要求取得                              */
/* 引数   : なし                                                */
/* 戻り値 : [us]右モータON時間                                  */
/* 概要   : 右モータON時間を提供する                            */
/* 制約   : なし                                                */
/* ============================================================ */
U2 FnU2_PfMtr_Ctrl_getRightMtrOnTime(VD)
{
  return (u2PfMtr_Ctrl_RightMtrOnTime);
}


/* ============================================================ */
/* 関数名 : FnU1_PfMtr_Ctrl_getLeftMtrRotDirReq                 */
/*          左モータ回転方向要求取得                            */
/* 引数   : なし                                                */
/* 戻り値 : 左モータ回転方向 (0:正転, 1:逆転)                   */
/* 概要   : 左モータ回転方向要求を提供する                      */
/* 制約   : なし                                                */
/* ============================================================ */
U1 FnU1_PfMtr_Ctrl_getLeftMtrRotDirReq(VD)
{
  return (u1PfMtr_Ctrl_LeftMtrRotDir);
}


/* ============================================================ */
/* 関数名 : FnU2_PfMtr_Ctrl_getLeftMtrPeriod                    */
/*          左モータ駆動周期要求取得                            */
/* 引数   : なし                                                */
/* 戻り値 : [us]左モータ駆動周期                                */
/* 概要   : 左モータ駆動周期を提供する                          */
/* 制約   : なし                                                */
/* ============================================================ */
U2 FnU2_PfMtr_Ctrl_getLeftMtrPeriod(VD)
{
  return (u2PfMtr_Ctrl_LeftMtrPeriod);
}


/* ============================================================ */
/* 関数名 : FnU2_PfMtr_Ctrl_getLeftMtrOnTime                    */
/*          左モータON時間要求取得                              */
/* 引数   : なし                                                */
/* 戻り値 : [us]左モータON時間                                  */
/* 概要   : 左モータON時間を提供する                            */
/* 制約   : なし                                                */
/* ============================================================ */
U2 FnU2_PfMtr_Ctrl_getLeftMtrOnTime(VD)
{
  return (u2PfMtr_Ctrl_LeftMtrOnTime);
}

