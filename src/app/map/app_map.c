/* ============================================================ */
/* ファイル名 : app_map.c                                       */
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
#include "app_controll.h"
#include "app_controll_pac.h"
#include "app_recgwall.h"
#include "app_recgwall_pac.h"
#include "app_plan_pac.h"

/* 本体 */
#include "app_map.h"
#include "app_map_pac.h"


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
/* 自車位置情報 */
ST_AppMap_CarStt  stAppMap_MyPos;

/* 壁の情報を格納する構造体配列 */
ST_AppMap_WallSts staAppMap_WallSts[CU1_AppMap_MazeSizeX][CU1_AppMap_MazeSizeY];


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
/* 関数名 : FnVD_AppMap_init                                    */
/*          壁情報と自車位置情報初期化                          */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 壁情報と自車位置情報初期化                          */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_AppMap_init(VD)
{
  S4 ts4X;
  S4 ts4Y;

  /* 迷路全体を壁があるかないか判らない設定にする */
  for (ts4X = (S4)0; ts4X < (S4)CU1_AppMap_MazeSizeX; ts4X++) {
    for (ts4Y = (S4)0; ts4Y < (S4)CU1_AppMap_MazeSizeY; ts4Y++) {
      staAppMap_WallSts[ts4X][ts4Y].b2North = CU1_AppMap_WallStsUnkown;
      staAppMap_WallSts[ts4X][ts4Y].b2East  = CU1_AppMap_WallStsUnkown;
      staAppMap_WallSts[ts4X][ts4Y].b2South = CU1_AppMap_WallStsUnkown;
      staAppMap_WallSts[ts4X][ts4Y].b2West  = CU1_AppMap_WallStsUnkown;
    }
  }

  /* 迷路の四方を壁ありの設定にする */
  for (ts4X = (S4)0; ts4X < (S4)CU1_AppMap_MazeSizeX; ts4X++)
  {
    staAppMap_WallSts[ts4X][0].b2South = CU1_AppMap_WallStsExist;            /* 南 */
    staAppMap_WallSts[ts4X][(S4)CU1_AppMap_MazeSizeY - (S4)1].b2North = CU1_AppMap_WallStsExist; /* 北 */
  }

  for (ts4Y = (S4)0; ts4Y < (S4)CU1_AppMap_MazeSizeY; ts4Y++) {
    staAppMap_WallSts[0][ts4Y].b2West = CU1_AppMap_WallStsExist;             /* 西 */
    staAppMap_WallSts[(S4)CU1_AppMap_MazeSizeX - (S4)1][ts4Y].b2East = CU1_AppMap_WallStsExist;  /* 東 */
  }
 
  /* スタート地点の西側を壁ありの設定にする */
  staAppMap_WallSts[0][0].b2East  = CU1_AppMap_WallStsExist;
  staAppMap_WallSts[1][0].b2West  = CU1_AppMap_WallStsExist;
  staAppMap_WallSts[0][0].b2North = CU1_AppMap_WallStsNothing;

  /* 自車位置座標を(0,0)に初期化 */
  stAppMap_MyPos.s2X = (S2)0;
  stAppMap_MyPos.s2Y = (S2)0;

  /* 自車方角を北に初期化 */
  stAppMap_MyPos.enDir = CEN_PrjCmn_Dir4North;
}


/* ============================================================ */
/* 関数名 : Fn_MAP_pos_init                                     */
/*          自車位置情報と自車方角初期化                        */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 自車位置情報と自車方角初期化                        */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_AppMap_initPos(VD)
{
  /* 自車位置座標を(0,0)に初期化 */
  stAppMap_MyPos.s2X = (S2)0;
  stAppMap_MyPos.s2Y = (S2)0;

  /* 自車方角を北に初期化 */
  stAppMap_MyPos.enDir = CEN_PrjCmn_Dir4North;
}

/* ============================================================ */
/* 関数名 : FnVD_AppMap_getWallSts                              */
/*          壁情報出力                                          */
/* 引数   : tsta2WallSts  壁情報                                */
/* 戻り値 : なし                                                */
/* 概要   : 壁情報出力                                          */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_AppMap_getWallSts(ST_AppMap_WallSts tsta2WallSts[CU1_AppMap_MazeSizeX][CU1_AppMap_MazeSizeY])
{
  S4 ts4X;
  S4 ts4Y;

  for (ts4X = (S4)0; ts4X < (S4)CU1_AppMap_MazeSizeX; ts4X++) {
    for (ts4Y = (S4)0; ts4Y < (S4)CU1_AppMap_MazeSizeY; ts4Y++) {
      tsta2WallSts[ts4X][ts4Y].b2North = staAppMap_WallSts[ts4X][ts4Y].b2North;
      tsta2WallSts[ts4X][ts4Y].b2East  = staAppMap_WallSts[ts4X][ts4Y].b2East;
      tsta2WallSts[ts4X][ts4Y].b2South = staAppMap_WallSts[ts4X][ts4Y].b2South;
      tsta2WallSts[ts4X][ts4Y].b2West  = staAppMap_WallSts[ts4X][ts4Y].b2West;
    }
  }
}


/* ============================================================ */
/* 関数名 : FnVD_AppMap_updateWall                              */
/*          壁情報更新                                          */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 壁情報更新                                          */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_AppMap_updateWall(VD)
{
  S4 ts4X;
  S4 ts4Y;
  U1 tu1StsNorth;
  U1 tu1StsSouth;
  U1 tu1StsEast;
  U1 tu1StsWest;
  EN_AppCtrl_Dir *    tpstDir;    /* 移動内容を設定する変数 */
  EN_AppCtrl_RunSts * tpenRunSts; /* 移動状況を設定する変数 */

  /* 動作状況 0:走行中、1:走行完了 */
  tpenRunSts = FnEN_AppCtrl_getRunStt(tpstDir);

  /* 動作状況 1:走行完了 */
  if (*tpenRunSts == 1){
    /* 北を向いている時 */
    if (stAppMap_MyPos.enDir == CEN_PrjCmn_Dir4North) {
       if (stAppRcg_WallInfoForMap.stWallF.u1WallExistance == (U1)C_ON) {
         tu1StsNorth = CU1_AppMap_WallStsExist;
       }else{
         tu1StsNorth = CU1_AppMap_WallStsNothing;
       }

       if (stAppRcg_WallInfoForMap.stWallR.u1WallExistance == (U1)C_ON) {
         tu1StsEast = CU1_AppMap_WallStsExist;
       }else{
         tu1StsEast = CU1_AppMap_WallStsNothing;
       }

       if (stAppRcg_WallInfoForMap.stWallL.u1WallExistance == (U1)C_ON) {
         tu1StsWest = CU1_AppMap_WallStsExist;
       }else{
         tu1StsWest = CU1_AppMap_WallStsNothing;
       }

       tu1StsSouth = CU1_AppMap_WallStsNothing; /* 後ろは必ず壁がない */
    }

    /* 東を向いている時 */
    if (stAppMap_MyPos.enDir == CEN_PrjCmn_Dir4East) {
       if (stAppRcg_WallInfoForMap.stWallF.u1WallExistance == (U1)C_ON) {
         tu1StsEast = CU1_AppMap_WallStsExist;
       }else{
         tu1StsEast = CU1_AppMap_WallStsNothing;
       }

       if (stAppRcg_WallInfoForMap.stWallR.u1WallExistance == (U1)C_ON) {
         tu1StsSouth = CU1_AppMap_WallStsExist;
       }else{
         tu1StsSouth = CU1_AppMap_WallStsNothing;
       }

       if (stAppRcg_WallInfoForMap.stWallL.u1WallExistance == (U1)C_ON) {
         tu1StsNorth = CU1_AppMap_WallStsExist;
       }else{
         tu1StsNorth = CU1_AppMap_WallStsNothing;
       }

       tu1StsWest = CU1_AppMap_WallStsNothing; /* 後ろは必ず壁がない */
    }

    /* 南を向いている時 */
    if (stAppMap_MyPos.enDir == CEN_PrjCmn_Dir4South) {
       if (stAppRcg_WallInfoForMap.stWallF.u1WallExistance == (U1)C_ON) {
         tu1StsSouth = CU1_AppMap_WallStsExist;
       }else{
         tu1StsSouth = CU1_AppMap_WallStsNothing;
       }

       if (stAppRcg_WallInfoForMap.stWallR.u1WallExistance == (U1)C_ON) {
         tu1StsWest = CU1_AppMap_WallStsExist;
       }else{
         tu1StsWest = CU1_AppMap_WallStsNothing;
       }

       if (stAppRcg_WallInfoForMap.stWallL.u1WallExistance == (U1)C_ON) {
         tu1StsEast = CU1_AppMap_WallStsExist;
       }else{
         tu1StsEast = CU1_AppMap_WallStsNothing;
       }

       tu1StsNorth = CU1_AppMap_WallStsNothing; /* 後ろは必ず壁がない */
    }

    /* 西を向いている時 */
    if (stAppMap_MyPos.enDir == CEN_PrjCmn_Dir4West) {
       if (stAppRcg_WallInfoForMap.stWallF.u1WallExistance == (U1)C_ON) {
         tu1StsWest = CU1_AppMap_WallStsExist;
       }else{
         tu1StsWest = CU1_AppMap_WallStsNothing;
       }

       if (stAppRcg_WallInfoForMap.stWallR.u1WallExistance == (U1)C_ON) {
         tu1StsNorth = CU1_AppMap_WallStsExist;
       }else{
         tu1StsNorth = CU1_AppMap_WallStsNothing;
       }

       if (stAppRcg_WallInfoForMap.stWallL.u1WallExistance == (U1)C_ON) {
         tu1StsSouth = CU1_AppMap_WallStsExist;
       }else{
         tu1StsSouth = CU1_AppMap_WallStsNothing;
       }

       tu1StsEast = CU1_AppMap_WallStsNothing; /* 後ろは必ず壁がない */
    }

    /* 自車位置の壁情報を更新 */
    ts4X = stAppMap_MyPos.s2X;
    ts4Y = stAppMap_MyPos.s2Y;

    staAppMap_WallSts[ts4X][ts4Y].b2North = tu1StsNorth;
    staAppMap_WallSts[ts4X][ts4Y].b2South = tu1StsSouth;
    staAppMap_WallSts[ts4X][ts4Y].b2East  = tu1StsEast;
    staAppMap_WallSts[ts4X][ts4Y].b2West  = tu1StsWest;

    /* 反対側から見た壁情報を更新 */
    if (ts4Y < (S4)CU1_AppMap_MazeSizeY - (S4)1) {
      staAppMap_WallSts[ts4X][ts4Y + (S4)1].b2South = tu1StsNorth;
    }

    if (ts4X < (S4)CU1_AppMap_MazeSizeX-1) {
      staAppMap_WallSts[ts4X + (S4)1][ts4Y].b2West = tu1StsEast;
    }

    if (ts4Y > (S4)0) {
      staAppMap_WallSts[ts4X][ts4Y - (S4)1].b2North = tu1StsSouth;
    }

    if (ts4X > (S4)0) {
      staAppMap_WallSts[ts4X - (S4)1][ts4Y].b2East = tu1StsWest;
    }
  }
}


/* ============================================================ */
/* 関数名 : FnVD_AppMap_getPosition                             */
/*          自車位置情報出力                                    */
/* 引数   : pst_mypos                                           */
/* 戻り値 : なし                                                */
/* 概要   : 自車位置情報出力                                    */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_AppMap_getPosition(ST_AppMap_CarStt * tpstMyPos)
{
  tpstMyPos->s2X   = stAppMap_MyPos.s2X;
  tpstMyPos->s2Y   = stAppMap_MyPos.s2Y;
  tpstMyPos->enDir = stAppMap_MyPos.enDir;
}


/* ============================================================ */
/* 関数名 : FnVD_AppMap_updatePosition                          */
/*          自車位置情報更新                                    */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 自車位置情報更新                                    */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_AppMap_updatePosition(VD)
{
  EN_PrjCmn_Dir4      tenNextDir;  /* 次に向かう方向を記録する変数 */
  EN_AppCtrl_Dir *    tpstDir;     /* 移動内容を設定する変数 */
  EN_AppCtrl_RunSts * tpenRunSts;  /* 移動状況を設定する変数 */

 /* 動作状況 0:走行中、1:走行完了 */
  tpenRunSts = FnEN_AppCtrl_getRunStt(tpstDir);

  if (*tpenRunSts == CEN_AppCtrl_RunStsFinish) {
    /* 次に行く方向を戻り値とする関数 */
    tenNextDir = (EN_PrjCmn_Dir4)FnU1_AppPln_getDir();

    /* 方向を更新 */
    stAppMap_MyPos.enDir = tenNextDir;

    /* 座標を更新 */
    if (stAppMap_MyPos.enDir == CEN_PrjCmn_Dir4North) {
      if (stAppMap_MyPos.s2Y < ((S4)CU1_AppMap_MazeSizeY - (S4)1)) {
	      stAppMap_MyPos.s2Y++;
      }
    }
  
    if (stAppMap_MyPos.enDir == CEN_PrjCmn_Dir4East) {
      if (stAppMap_MyPos.s2X < ((S4)CU1_AppMap_MazeSizeX - (S4)1)) {
 	      stAppMap_MyPos.s2X++;
      }
    }

    if (stAppMap_MyPos.enDir == CEN_PrjCmn_Dir4South) {
      if (stAppMap_MyPos.s2Y > (S2)0) {
  	    stAppMap_MyPos.s2Y--;
      }
    }

    if (stAppMap_MyPos.enDir == CEN_PrjCmn_Dir4West) {
      if (stAppMap_MyPos.s2X > (S2)0) {
  	    stAppMap_MyPos.s2X--;
      }
    }
  }
}

