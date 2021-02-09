/* ============================================================ */
/* ファイル名 : pf_raysens_if.c                                 */
/* 機能       : 光学センサI/F処理                               */
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
#include "hw_drv_raysens.h"

/* 本体 */
#include "pf_raysens_if.h"
#include "pf_raysens_if_pac.h"


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */


/* ============================================================ */
/* 型定義                                                       */
/* ============================================================ */


/* ============================================================ */
/* 関数プロトタイプ宣言(static)                                 */
/* ============================================================ */
static U2 FnU2_PfRaySens_If_RcFilter(U2 au2_pval, U2 au2_val);

/* ============================================================ */
/* 変数定義(extern)                                             */
/* ============================================================ */


/* ============================================================ */
/* 変数定義(static)                                             */
/* ============================================================ */
static ST_SENINFO st_PfRaySens_info;    /* センサ情報 */


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
/* 関数名 : FnVD_PfRaySens_If_initHw                            */
/*          光学センサI/F処理初期化(HW用)                       */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : ハードウェア層の初期化を行う                        */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_PfRaySens_If_initHw(VD)
{
  FnVD_HwDrv_RaySens_init();
}


/* ============================================================ */
/* 関数名 : FnVD_PfRaySens_If_initPf                            */
/*          光学センサI/F処理初期化(PF用)                       */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 光学センサI/F処理の初期化を行う                     */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_PfRaySens_If_initPf(VD)
{
  /* センサ値 */
  st_PfRaySens_info.sen_r.u2_sen_val = (U2)0;
  st_PfRaySens_info.sen_fl.u2_sen_val = (U2)0;
  st_PfRaySens_info.sen_fr.u2_sen_val = (U2)0;
  st_PfRaySens_info.sen_l.u2_sen_val = (U2)0;

  /* センサ前回値 */
  st_PfRaySens_info.sen_r.u2_sen_pval = (U2)0;
  st_PfRaySens_info.sen_fl.u2_sen_pval = (U2)0;
  st_PfRaySens_info.sen_fr.u2_sen_pval = (U2)0;
  st_PfRaySens_info.sen_l.u2_sen_pval = (U2)0;

  /* FCセンサ値  */
  st_PfRaySens_info.sen_r.u2_sen_fcval = (U2)0;
  st_PfRaySens_info.sen_fl.u2_sen_fcval = (U2)0;
  st_PfRaySens_info.sen_fr.u2_sen_fcval = (U2)0;
  st_PfRaySens_info.sen_l.u2_sen_fcval = (U2)0;

  /* センサデータ有効無効 */
  st_PfRaySens_info.sen_r.bl_sen_data_valid = (BL)C_OFF;
  st_PfRaySens_info.sen_fl.bl_sen_data_valid = (BL)C_OFF;
  st_PfRaySens_info.sen_fr.bl_sen_data_valid = (BL)C_OFF;
  st_PfRaySens_info.sen_l.bl_sen_data_valid = (BL)C_OFF;

}


/* ============================================================ */
/* 関数名 : FnVD_PfRaySens_If_renewVal                          */
/*          センサ値更新                                        */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : センサ値を更新する                                  */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_PfRaySens_If_renewVal(VD)
{
  U1 tu2_sen_val;

  /* センサ右側 */
  FnVD_HwDrv_RaySens_renewVal(CEN_HwDrv_RaySens_Id_R);
  tu2_sen_val = FnU2_HwDrv_RaySens_getVal(CEN_HwDrv_RaySens_Id_R);
  st_PfRaySens_info.sen_r.u2_sen_pval = st_PfRaySens_info.sen_r.u2_sen_val;    /* 過去の値を保存 */
  st_PfRaySens_info.sen_r.u2_sen_val = tu2_sen_val;                            /* 現在の値を保存 */
  /* RCフィルタを通す */
  st_PfRaySens_info.sen_r.u2_sen_fcval = FnU2_PfRaySens_If_RcFilter(st_PfRaySens_info.sen_r.u2_sen_pval, st_PfRaySens_info.sen_r.u2_sen_val);

  /* センサ前方左側 */
  FnVD_HwDrv_RaySens_renewVal(CEN_HwDrv_RaySens_Id_FL);
  tu2_sen_val = FnU2_HwDrv_RaySens_getVal(CEN_HwDrv_RaySens_Id_FL);
  st_PfRaySens_info.sen_fl.u2_sen_pval = st_PfRaySens_info.sen_fl.u2_sen_val;  /* 過去の値を保存 */
  st_PfRaySens_info.sen_fl.u2_sen_val = tu2_sen_val;                           /* 現在の値を保存 */  
  /* RCフィルタを通す */
  st_PfRaySens_info.sen_fl.u2_sen_fcval = FnU2_PfRaySens_If_RcFilter(st_PfRaySens_info.sen_fl.u2_sen_pval, st_PfRaySens_info.sen_fl.u2_sen_val);

  /* センサ前方右側 */
  FnVD_HwDrv_RaySens_renewVal(CEN_HwDrv_RaySens_Id_FR);
  tu2_sen_val = FnU2_HwDrv_RaySens_getVal(CEN_HwDrv_RaySens_Id_FR);
  st_PfRaySens_info.sen_fr.u2_sen_pval = st_PfRaySens_info.sen_fr.u2_sen_val;  /* 過去の値を保存 */
  st_PfRaySens_info.sen_fr.u2_sen_val = tu2_sen_val;                           /* 現在の値を保存 */ 
  /* RCフィルタを通す */
  st_PfRaySens_info.sen_fr.u2_sen_fcval = FnU2_PfRaySens_If_RcFilter(st_PfRaySens_info.sen_fr.u2_sen_pval, st_PfRaySens_info.sen_fr.u2_sen_val);

  /* センサ左側 */
  FnVD_HwDrv_RaySens_renewVal(CEN_HwDrv_RaySens_Id_L);
  tu2_sen_val  = FnU2_HwDrv_RaySens_getVal(CEN_HwDrv_RaySens_Id_L);
  st_PfRaySens_info.sen_l.u2_sen_pval = st_PfRaySens_info.sen_l.u2_sen_val;    /* 過去の値を保存 */
  st_PfRaySens_info.sen_l.u2_sen_val = tu2_sen_val;                            /* 現在の値を保存 */
  /* RCフィルタを通す */
  st_PfRaySens_info.sen_l.u2_sen_fcval = FnU2_PfRaySens_If_RcFilter(st_PfRaySens_info.sen_l.u2_sen_pval, st_PfRaySens_info.sen_l.u2_sen_val);

}


/* ============================================================ */
/* 関数名 : FnU2_PfRaySens_If_getValRight                       */
/*          FCセンサ値取得(右側)                                */
/* 引数   : なし                                                */
/* 戻り値 : センサ値                                            */
/* 概要   : フィルタカット後センサ値を提供する                  */
/* 制約   : なし                                                */
/* ============================================================ */
U2 FnU2_PfRaySens_If_getValRight(VD)
{
  return (st_PfRaySens_info.sen_r.u2_sen_fcval);
}


/* ============================================================ */
/* 関数名 : FnU2_PfRaySens_If_getValFrontRight                  */
/*          FCセンサ値取得(前方右側)                            */
/* 引数   : なし                                                */
/* 戻り値 : センサ値                                            */
/* 概要   : フィルタカット後センサ値を提供する                  */
/* 制約   : なし                                                */
/* ============================================================ */
U2 FnU2_PfRaySens_If_getValFrontRight(VD)
{
  return (st_PfRaySens_info.sen_fr.u2_sen_fcval);
}


/* ============================================================ */
/* 関数名 : FnU2_PfRaySens_If_getValFrontLeft                   */
/*          FCセンサ値取得(前方左側)                            */
/* 引数   : なし                                                */
/* 戻り値 : センサ値                                            */
/* 概要   : フィルタカット後センサ値を提供する                  */
/* 制約   : なし                                                */
/* ============================================================ */
U2 FnU2_PfRaySens_If_getValFrontLeft(VD)
{
  return (st_PfRaySens_info.sen_fl.u2_sen_fcval);
}


/* ============================================================ */
/* 関数名 : FnU2_PfRaySens_If_getValLeft                        */
/*          FCセンサ値取得(右側)                                */
/* 引数   : なし                                                */
/* 戻り値 : センサ値                                            */
/* 概要   : フィルタカット後センサ値を提供する                  */
/* 制約   : なし                                                */
/* ============================================================ */
U2 FnU2_PfRaySens_If_getValLeft(VD)
{
  return (st_PfRaySens_info.sen_l.u2_sen_fcval);
}


/* ============================================================ */
/* 関数名 : FnU2_PfRaySens_If_RcFilter                          */
/*          RCフィルタ関数                                      */
/* 引数1  : (U2)前回の出力値                                    */
/* 引数2  : (U2)今回の出力値                                    */
/* 戻り値 : (U2)フィルタ後出力値                                */
/* 概要   : RCフィルタをかける                                  */
/* 制約   : なし                                                */
/* ============================================================ */
static U2 FnU2_PfRaySens_If_RcFilter(U2 au2_pval, U2 au2_val)
{
  /* 出力値 = (a[%] * 前回の出力値 + (100-a)[%] * 今回の出力値) / 100 */
  return(((CU4_Fc_RATE * (U4)au2_pval) + ((CU4_Fc_MAX_RATE - CU4_Fc_RATE) * (U4)au2_val)) / CU4_Fc_MAX_RATE);
}
