#if !defined(INCLUDED_app_map_pac_h)
#define INCLUDED_app_map_pac_h
/* ============================================================ */
/* ファイル名 : app_map_pac.h                                   */
/* 機能       : マップ(app公開)                                 */
/* ============================================================ */

/* ============================================================ */
/* インクルード                                                 */
/* ============================================================ */
/* プロジェクト共通 */
#include "prj_cmn_option.h"
#include "prj_cmn_type.h"
#include "prj_cmn_macro.h"

/* カテゴリ共通 */
#include "app_cmn_option.h"
#include "app_cmn_option_pac.h"

/* 個別 */

/* 本体 */


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */
#define CU1_AppMap_MazeSizeX      ((U1)5)    /* 迷路の大きさ(CS4_AppMap_MazeSizeX x CS4_AppMap_MazeSizeY)迷路 */
#define CU1_AppMap_MazeSizeY      ((U1)5)    /* 迷路の大きさ(CS4_AppMap_MazeSizeX x CS4_AppMap_MazeSizeY)迷路 */

#define CU1_AppMap_WallStsNothing ((U1)0)    /* 壁がないばあいの値 */
#define CU1_AppMap_WallStsExist   ((U1)1)    /* 壁がある場合の値 */
#define CU1_AppMap_WallStsUnkown  ((U1)2)    /* 壁があるかないか判らない状態の場合の値 */


/* ============================================================ */
/* 型定義                                                       */
/* ============================================================ */
/* 自車位置情報 */
typedef struct {
  S2             s2X;     /* 自車位置のX座標(東西方向) */
  S2             s2Y;     /* 自車位置のY座標(南北方向) */
  EN_PrjCmn_Dir4 enDir;   /* 自車方角 */
} ST_AppMap_CarStt;


/* 壁情報を格納する構造体(ビットフィールド) */
typedef struct {
  U1 b2North :2; /* 北の壁情報 */
  U1 b2East  :2; /* 東の壁情報 */
  U1 b2South :2; /* 南の壁情報 */
  U1 b2West  :2; /* 西の壁情報 */
} ST_AppMap_WallSts;


/* ============================================================ */
/* 関数プロトタイプ宣言(extern)                                 */
/* ============================================================ */
extern VD FnVD_AppMap_initPos(VD);
extern VD FnVD_AppMap_getWallSts(ST_AppMap_WallSts tsta2WallSts[CU1_AppMap_MazeSizeX][CU1_AppMap_MazeSizeY]);
extern VD FnVD_AppMap_getPosition(ST_AppMap_CarStt * tpstMyPos);


/* ============================================================ */
/* 変数宣言(extern)                                             */
/* ============================================================ */
extern ST_AppMap_CarStt  stAppMap_MyPos; /* 自車位置情報 */
extern ST_AppMap_WallSts staAppMap_WallSts[CU1_AppMap_MazeSizeX][CU1_AppMap_MazeSizeY]; /* 壁の情報を格納する構造体配列 */


/* ============================================================ */
/* const変数宣言(extern)                                        */
/* ============================================================ */


/* ============================================================ */
/* 関数形式マクロ定義                                           */
/* ============================================================ */


#endif
