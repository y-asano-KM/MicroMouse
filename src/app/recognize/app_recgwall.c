/* ============================================================ */
/* ファイル名 : app_recgwall.c                                  */
/* 機能       : 壁認識                                          */
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

/* 本体 */
#include "app_recgwall.h"
#include "app_recgwall_pac.h"


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */
#define  CU2_AppRcg_WallSensDetectThF  ((U2)10)   /* 前センサ値閾値(壁との距離約18cmくらい) */
#define  CU2_AppRcg_WallSensDetectThR  ((U2)30)   /* 右センサ値閾値(壁との距離約5.5cmくらい) */
#define  CU2_AppRcg_WallSensDetectThL  ((U2)30)   /* 左センサ値閾値(壁との距離約5.5cmくらい) */


/* ============================================================ */
/* 型定義                                                       */
/* ============================================================ */


/* ============================================================ */
/* 関数プロトタイプ宣言(static)                                 */
/* ============================================================ */
static VD FnVD_AppRcg_readSens(VD);
static VD FnVD_AppRcg_detectForInt(VD);
static VD FnVD_AppRcg_detect(VD);


/* ============================================================ */
/* 変数定義(extern)                                             */
/* ============================================================ */
ST_AppRcg_WallInfo stAppRcg_WallInfoForMap;  /* 壁情報(Map) */
ST_AppRcg_WallInfo stAppRcg_WallInfoForCtrl; /* 壁情報(姿勢制御) */


/* ============================================================ */
/* 変数定義(static)                                             */
/* ============================================================ */
static U2 u2AppRcg_SensValR;
static U2 u2AppRcg_SensValFR;
static U2 u2AppRcg_SensValFL;
static U2 u2AppRcg_SensValL;


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
/* 関数名 : FnVD_AppRcg_detectWall                              */
/*          壁認識処理関数(5ms)                                 */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 壁認識処理をする                                    */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_AppRcg_detectWall(VD)
{
  /* センサ値読み込み */
  FnVD_AppRcg_readSens();

  /* 壁検知 */
  FnVD_AppRcg_detect();
}


/* ============================================================ */
/* 関数名 : FnVD_AppRcg_detectWallForInt                        */
/*          壁認識処理関数(1ms)                                 */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 壁認識処理をする                                    */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_AppRcg_detectWallForInt(VD)
{
  /* センサ値読み込み */
  FnVD_AppRcg_readSens();

  /* 壁検知 */
  FnVD_AppRcg_detectForInt();
}


/* ============================================================ */
/* 関数名 : FnVD_AppRcg_init                                    */
/*          認識処理初期化関数                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 初期化                                              */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_AppRcg_init(VD)
{
  /* 壁情報(Map) */
  /* 壁有無 */
  stAppRcg_WallInfoForMap.stWallF.u1WallExistance = (U1)C_OFF;
  stAppRcg_WallInfoForMap.stWallR.u1WallExistance = (U1)C_OFF;
  stAppRcg_WallInfoForMap.stWallL.u1WallExistance = (U1)C_OFF;

  /* 壁データ有効無効 */
  stAppRcg_WallInfoForMap.stWallF.u1WallVld = (U1)C_OFF;
  stAppRcg_WallInfoForMap.stWallR.u1WallVld = (U1)C_OFF;
  stAppRcg_WallInfoForMap.stWallL.u1WallVld = (U1)C_OFF;
  
  /* センサ値 */
  stAppRcg_WallInfoForMap.stWallF.u2SensVal = (U2)0;
  stAppRcg_WallInfoForMap.stWallR.u2SensVal = (U2)0;
  stAppRcg_WallInfoForMap.stWallL.u2SensVal = (U2)0;

  /* 壁情報(姿勢制御) */
  /* 壁有無 */
  stAppRcg_WallInfoForCtrl.stWallF.u1WallExistance = (U1)C_OFF;
  stAppRcg_WallInfoForCtrl.stWallR.u1WallExistance = (U1)C_OFF;
  stAppRcg_WallInfoForCtrl.stWallL.u1WallExistance = (U1)C_OFF;

  /* 壁データ有効無効 */
  stAppRcg_WallInfoForCtrl.stWallF.u1WallVld = (U1)C_OFF;
  stAppRcg_WallInfoForCtrl.stWallR.u1WallVld = (U1)C_OFF;
  stAppRcg_WallInfoForCtrl.stWallL.u1WallVld = (U1)C_OFF;
  
  /* センサ値 */
  stAppRcg_WallInfoForCtrl.stWallF.u2SensVal = (U2)0;
  stAppRcg_WallInfoForCtrl.stWallR.u2SensVal = (U2)0;
  stAppRcg_WallInfoForCtrl.stWallL.u2SensVal = (U2)0;
}


/* ============================================================ */
/* 関数名 : FnVD_AppRcg_readSens                                */
/*          センサ読み込み関数                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : FCセンサ値を読み込む                                */
/* 制約   : なし                                                */
/* ============================================================ */
static VD FnVD_AppRcg_readSens(VD)
{
  /* センサ右側 */
  u2AppRcg_SensValR = FnU2_PfRaySens_If_getValRight();

  /* センサ前方左側 */
  u2AppRcg_SensValFL = FnU2_PfRaySens_If_getValFrontLeft();

  /* センサ前方右側 */
  u2AppRcg_SensValFR = FnU2_PfRaySens_If_getValFrontRight();

  /* センサ左側 */
  u2AppRcg_SensValL = FnU2_PfRaySens_If_getValLeft();
}


/* ============================================================ */
/* 関数名 : FnVD_AppRcg_detectForInt                            */
/*          壁検知関数(1ms)                                     */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 壁の有無を判断する                                  */
/* 制約   : なし                                                */
/* ============================================================ */
static VD FnVD_AppRcg_detectForInt(VD)
{
  /* 右壁チェック */
  if (u2AppRcg_SensValR > CU2_AppRcg_WallSensDetectThR) {
    stAppRcg_WallInfoForCtrl.stWallR.u1WallExistance = (U1)C_ON;         /* 右壁あり */
  }
  else {
    stAppRcg_WallInfoForCtrl.stWallR.u1WallExistance = (U1)C_OFF;        /* 右壁なし */
  }
  /* センサ値を格納 */
  stAppRcg_WallInfoForCtrl.stWallR.u2SensVal = (U2)u2AppRcg_SensValR;
  stAppRcg_WallInfoForCtrl.stWallR.u1WallVld = (U1)C_ON;

  /* 前壁チェック */
  /* 判定不要 */

  /* 左壁チェック */
  if (u2AppRcg_SensValL > CU2_AppRcg_WallSensDetectThL) {
    stAppRcg_WallInfoForCtrl.stWallL.u1WallExistance = (U1)C_ON;         /* 左壁あり */
  }
  else {
    stAppRcg_WallInfoForCtrl.stWallL.u1WallExistance = (U1)C_OFF;        /* 左壁なし */
  }
  /* センサ値を格納 */
  stAppRcg_WallInfoForCtrl.stWallL.u2SensVal = (U2)u2AppRcg_SensValL;
  stAppRcg_WallInfoForCtrl.stWallL.u1WallVld = (U1)C_ON;
}


/* ============================================================ */
/* 関数名 : FnVD_AppRcg_detect                                  */
/*          壁検知関数(5ms)                                     */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 壁の有無を判断する                                  */
/* 制約   : なし                                                */
/* ============================================================ */
static VD FnVD_AppRcg_detect(VD)
{
  U2 tu2FiltAve;

  /* 右壁チェック */
  if (u2AppRcg_SensValR > CU2_AppRcg_WallSensDetectThR) {
    stAppRcg_WallInfoForMap.stWallR.u1WallExistance = (U1)C_ON;         /* 右壁あり */
  }
  else {
    stAppRcg_WallInfoForMap.stWallR.u1WallExistance = (U1)C_OFF;        /* 右壁なし */
  }
  /* センサ値を格納 */
  stAppRcg_WallInfoForMap.stWallR.u2SensVal = (U2)u2AppRcg_SensValR;
  stAppRcg_WallInfoForMap.stWallR.u1WallVld = (U1)C_ON;

  /* 前左FCセンサ値と前右FCセンサ値の平均 */
  tu2FiltAve = (U2)0;
  tu2FiltAve = u2AppRcg_SensValFL + u2AppRcg_SensValFR;
  tu2FiltAve = (tu2FiltAve + (U2)1) / (U2)2;    /* 切り上げ */
  
  /* 前壁チェック */
  if (tu2FiltAve > CU2_AppRcg_WallSensDetectThF) {
    stAppRcg_WallInfoForMap.stWallF.u1WallExistance = (U1)C_ON;        /* 前壁あり */
  }
  else {
    stAppRcg_WallInfoForMap.stWallF.u1WallExistance = (U1)C_OFF;       /* 前壁なし */
  }
  /* センサ値を格納 */
  stAppRcg_WallInfoForMap.stWallF.u2SensVal = (U2)tu2FiltAve;
  stAppRcg_WallInfoForMap.stWallF.u1WallVld = (U1)C_ON;

  /* 左壁チェック */
  if (u2AppRcg_SensValL > CU2_AppRcg_WallSensDetectThL) {
    stAppRcg_WallInfoForMap.stWallL.u1WallExistance = (U1)C_ON;         /* 左壁あり */
  }
  else {
    stAppRcg_WallInfoForMap.stWallL.u1WallExistance = (U1)C_OFF;        /* 左壁なし */
  }
  /* センサ値を格納 */
  stAppRcg_WallInfoForMap.stWallL.u2SensVal = (U2)u2AppRcg_SensValL;
  stAppRcg_WallInfoForMap.stWallL.u1WallVld = (U1)C_ON;
}

