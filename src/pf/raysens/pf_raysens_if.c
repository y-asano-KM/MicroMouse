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
#define CU4_PfRaySens_If_FcRate       ((U4)80)     /* [%]重み */
#define CU4_PfRaySens_If_FcMaxRate    ((U4)100)    /* [%]重み最大値 */


/* ============================================================ */
/* 型定義                                                       */
/* ============================================================ */
/* センサデータ */
typedef struct {
  U2 u2PreVal;        /* センサ前回値 */
  U2 u2CurVal;        /* センサ値 */
  U2 u2FilterVal;     /* FCセンサ値 */
  U1 u1SensDatVld;    /* センサデータ有効無効 無効:OFF(0) 有効:ON(1) */
} ST_PfRaySens_If_SensDat;

/* センサ情報 */
typedef struct {
  ST_PfRaySens_If_SensDat stSensFR;        /* 前右センサ */
  ST_PfRaySens_If_SensDat stSensFL;        /* 前左センサ */
  ST_PfRaySens_If_SensDat stSensR;         /* 右センサ */
  ST_PfRaySens_If_SensDat stSensL;         /* 左センサ */
} ST_PfRaySens_If_SensInfo;


/* ============================================================ */
/* 関数プロトタイプ宣言(static)                                 */
/* ============================================================ */
static U2 FnU2_PfRaySens_If_RcFilter(U2 tu2PreVal, U2 tu2CurVal);


/* ============================================================ */
/* 変数定義(extern)                                             */
/* ============================================================ */


/* ============================================================ */
/* 変数定義(static)                                             */
/* ============================================================ */
static ST_PfRaySens_If_SensInfo stPfRaySens_If_Info;    /* センサ情報 */


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
  stPfRaySens_If_Info.stSensR.u2CurVal = (U2)0;
  stPfRaySens_If_Info.stSensFL.u2CurVal = (U2)0;
  stPfRaySens_If_Info.stSensFR.u2CurVal = (U2)0;
  stPfRaySens_If_Info.stSensL.u2CurVal = (U2)0;

  /* センサ前回値 */
  stPfRaySens_If_Info.stSensR.u2PreVal = (U2)0;
  stPfRaySens_If_Info.stSensFL.u2PreVal = (U2)0;
  stPfRaySens_If_Info.stSensFR.u2PreVal = (U2)0;
  stPfRaySens_If_Info.stSensL.u2PreVal = (U2)0;

  /* FCセンサ値  */
  stPfRaySens_If_Info.stSensR.u2FilterVal = (U2)0;
  stPfRaySens_If_Info.stSensFL.u2FilterVal = (U2)0;
  stPfRaySens_If_Info.stSensFR.u2FilterVal = (U2)0;
  stPfRaySens_If_Info.stSensL.u2FilterVal = (U2)0;

  /* センサデータ有効無効 */
  stPfRaySens_If_Info.stSensR.u1SensDatVld = (U1)C_OFF;
  stPfRaySens_If_Info.stSensFL.u1SensDatVld = (U1)C_OFF;
  stPfRaySens_If_Info.stSensFR.u1SensDatVld = (U1)C_OFF;
  stPfRaySens_If_Info.stSensL.u1SensDatVld = (U1)C_OFF;

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
  stPfRaySens_If_Info.stSensR.u2PreVal = stPfRaySens_If_Info.stSensR.u2CurVal;    /* 過去の値を保存 */
  stPfRaySens_If_Info.stSensR.u2CurVal = tu2_sen_val;                            /* 現在の値を保存 */
  /* RCフィルタを通す */
  stPfRaySens_If_Info.stSensR.u2FilterVal = FnU2_PfRaySens_If_RcFilter(stPfRaySens_If_Info.stSensR.u2PreVal, stPfRaySens_If_Info.stSensR.u2CurVal);

  /* センサ前方左側 */
  FnVD_HwDrv_RaySens_renewVal(CEN_HwDrv_RaySens_Id_FL);
  tu2_sen_val = FnU2_HwDrv_RaySens_getVal(CEN_HwDrv_RaySens_Id_FL);
  stPfRaySens_If_Info.stSensFL.u2PreVal = stPfRaySens_If_Info.stSensFL.u2CurVal;  /* 過去の値を保存 */
  stPfRaySens_If_Info.stSensFL.u2CurVal = tu2_sen_val;                           /* 現在の値を保存 */  
  /* RCフィルタを通す */
  stPfRaySens_If_Info.stSensFL.u2FilterVal = FnU2_PfRaySens_If_RcFilter(stPfRaySens_If_Info.stSensFL.u2PreVal, stPfRaySens_If_Info.stSensFL.u2CurVal);

  /* センサ前方右側 */
  FnVD_HwDrv_RaySens_renewVal(CEN_HwDrv_RaySens_Id_FR);
  tu2_sen_val = FnU2_HwDrv_RaySens_getVal(CEN_HwDrv_RaySens_Id_FR);
  stPfRaySens_If_Info.stSensFR.u2PreVal = stPfRaySens_If_Info.stSensFR.u2CurVal;  /* 過去の値を保存 */
  stPfRaySens_If_Info.stSensFR.u2CurVal = tu2_sen_val;                           /* 現在の値を保存 */ 
  /* RCフィルタを通す */
  stPfRaySens_If_Info.stSensFR.u2FilterVal = FnU2_PfRaySens_If_RcFilter(stPfRaySens_If_Info.stSensFR.u2PreVal, stPfRaySens_If_Info.stSensFR.u2CurVal);

  /* センサ左側 */
  FnVD_HwDrv_RaySens_renewVal(CEN_HwDrv_RaySens_Id_L);
  tu2_sen_val  = FnU2_HwDrv_RaySens_getVal(CEN_HwDrv_RaySens_Id_L);
  stPfRaySens_If_Info.stSensL.u2PreVal = stPfRaySens_If_Info.stSensL.u2CurVal;    /* 過去の値を保存 */
  stPfRaySens_If_Info.stSensL.u2CurVal = tu2_sen_val;                            /* 現在の値を保存 */
  /* RCフィルタを通す */
  stPfRaySens_If_Info.stSensL.u2FilterVal = FnU2_PfRaySens_If_RcFilter(stPfRaySens_If_Info.stSensL.u2PreVal, stPfRaySens_If_Info.stSensL.u2CurVal);

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
  return (stPfRaySens_If_Info.stSensR.u2FilterVal);
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
  return (stPfRaySens_If_Info.stSensFR.u2FilterVal);
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
  return (stPfRaySens_If_Info.stSensFL.u2FilterVal);
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
  return (stPfRaySens_If_Info.stSensL.u2FilterVal);
}


/* ============================================================ */
/* 関数名 : FnU2_PfRaySens_If_RcFilter                          */
/*          RCフィルタ関数                                      */
/* 引数1  : tu2PreVal 前回の出力値                              */
/*          tu2CurVal 今回の出力値                              */
/* 戻り値 : フィルタ後出力値                                    */
/* 概要   : RCフィルタをかける                                  */
/* 制約   : なし                                                */
/* ============================================================ */
static U2 FnU2_PfRaySens_If_RcFilter(U2 tu2PreVal, U2 tu2CurVal)
{
  /* 出力値 = (a[%] * 前回の出力値 + (100-a)[%] * 今回の出力値) / 100 */
  return ((U2)(((CU4_PfRaySens_If_FcRate * (U4)tu2PreVal) + (CU4_PfRaySens_If_FcMaxRate - CU4_PfRaySens_If_FcRate) * (U4)tu2CurVal) / CU4_PfRaySens_If_FcMaxRate));
}

