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
#include "app_recgwall.h"
#include "app_recgwall_pac.h"


/* 本体 */
#include "app_map_pac.h"
#include "app_plan_pac.h"
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
t_position mypos;                    /* 自車位置情報?*/
t_wall wall[MAZESIZE_X][MAZESIZE_Y]; /* 壁の情報を格納する構造体配列?*/

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
/* 関数名 : CONV_SEN2WALL                                       */
/*          センサ情報から壁情報へ変換                          */
/* 引数   : w                                                   */
/* 戻り値 : なし                                                */
/* 概要   : センサ情報から壁情報へ変換                          */
/* 制約   : なし                                                */
/* ============================================================ */
#define CONV_SEN2WALL(w) ((w) ? WALL : NOWALL)


/* ============================================================ */
/* 関数名 : Fn_MAP_init                                         */
/*          壁情報と自車位置情報初期化                          */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 壁情報と自車位置情報初期化                          */
/* 制約   : なし                                                */
/* ============================================================ */
void Fn_MAP_init(void)
{
  int i,j;

  /* 迷路全体を壁があるかないか判らない設定にする */
  i = 0;
  for ( j = 0; j < MAZESIZE_Y; j++ ) {
    wall[i][j].north = wall[i][j].east = wall[i][j].south = wall[i][j].west = UNKNOWN;
  }
  i = 1;
  for ( j = 0; j < MAZESIZE_Y; j++ ) {
    wall[i][j].north = wall[i][j].east = wall[i][j].south = wall[i][j].west = UNKNOWN;
  }
  i = 2;
  for ( j = 0; j < MAZESIZE_Y; j++ ) {
    wall[i][j].north = wall[i][j].east = wall[i][j].south = wall[i][j].west = UNKNOWN;
  }
  i = 3;
  for ( j = 0; j < MAZESIZE_Y; j++ ) {
    wall[i][j].north = wall[i][j].east = wall[i][j].south = wall[i][j].west = UNKNOWN;
  }
  i = 4;
  for ( j = 0; j < MAZESIZE_Y; j++ ) {
    wall[i][j].north = wall[i][j].east = wall[i][j].south = wall[i][j].west = UNKNOWN;
  }
  i = 5;
  for ( j = 0; j < MAZESIZE_Y; j++ ) {
    wall[i][j].north = wall[i][j].east = wall[i][j].south = wall[i][j].west = UNKNOWN;
  }
  i = 6;
  for ( j = 0; j < MAZESIZE_Y; j++ ) {
    wall[i][j].north = wall[i][j].east = wall[i][j].south = wall[i][j].west = UNKNOWN;
  }
  i = 7;
  for ( j = 0; j < MAZESIZE_Y; j++ ) {
    wall[i][j].north = wall[i][j].east = wall[i][j].south = wall[i][j].west = UNKNOWN;
  }
  i = 8;
  for ( j = 0; j < MAZESIZE_Y; j++ ) {
    wall[i][j].north = wall[i][j].east = wall[i][j].south = wall[i][j].west = UNKNOWN;
  }
  i = 9;
  for ( j = 0; j < MAZESIZE_Y; j++ ) {
    wall[i][j].north = wall[i][j].east = wall[i][j].south = wall[i][j].west = UNKNOWN;
  }
  i = 10;
  for ( j = 0; j < MAZESIZE_Y; j++ ) {
    wall[i][j].north = wall[i][j].east = wall[i][j].south = wall[i][j].west = UNKNOWN;
  }
  i = 11;
  for ( j = 0; j < MAZESIZE_Y; j++ ) {
    wall[i][j].north = wall[i][j].east = wall[i][j].south = wall[i][j].west = UNKNOWN;
  }
  i = 12;
  for ( j = 0; j < MAZESIZE_Y; j++ ) {
    wall[i][j].north = wall[i][j].east = wall[i][j].south = wall[i][j].west = UNKNOWN;
  }
  i = 13;
  for ( j = 0; j < MAZESIZE_Y; j++ ) {
    wall[i][j].north = wall[i][j].east = wall[i][j].south = wall[i][j].west = UNKNOWN;
  }
  i = 14;
  for ( j = 0; j < MAZESIZE_Y; j++ ) {
    wall[i][j].north = wall[i][j].east = wall[i][j].south = wall[i][j].west = UNKNOWN;
  }
  i = 15;
  for ( j = 0; j < MAZESIZE_Y; j++ ) {
    wall[i][j].north = wall[i][j].east = wall[i][j].south = wall[i][j].west = UNKNOWN;
  }


  /* 迷路の四方を壁ありの設定にする */
  for ( i = 0; i < MAZESIZE_X; i++ )
  {
    wall[i][0].south = WALL;            /* 南 */
    wall[i][MAZESIZE_Y-1].north = WALL; /* 北 */
  }

  for ( j = 0; j < MAZESIZE_Y; j++ ) {
    wall[0][j].west = WALL;             /* 西 */
    wall[MAZESIZE_X-1][j].east = WALL;  /* 東 */
  }
   
  /* スタート地点の右側を壁ありの設定にする */
  wall[0][0].east = wall[1][0].west = WALL;
  
  /* 自車位置座標を(0,0)に初期化 */
  mypos.x = mypos.y = 0;

  /* 自車方角を北に初期化 */
  mypos.dir = north;  

}


/* ============================================================ */
/* 関数名 : Fn_MAP_outputWall                                   */
/*          壁情報出力                                          */
/* 引数   : sta_wall[][MAZESIZE_Y]                              */
/* 戻り値 : なし                                                */
/* 概要   : 壁情報出力                                          */
/* 制約   : なし                                                */
/* ============================================================ */
void Fn_MAP_outputWall(t_wall sta_wall[][MAZESIZE_Y])
{
  int i,j;

  i = 0;
  for(j = 0; j < MAZESIZE_Y; j++)
  {
    sta_wall[i][j].north = wall[i][j].north;
    sta_wall[i][j].east = wall[i][j].east;
    sta_wall[i][j].south = wall[i][j].south;
    sta_wall[i][j].west = wall[i][j].west;
  }
  i = 1;
  for(j = 0; j < MAZESIZE_Y; j++)
  {
    sta_wall[i][j].north = wall[i][j].north;
    sta_wall[i][j].east = wall[i][j].east;
    sta_wall[i][j].south = wall[i][j].south;
    sta_wall[i][j].west = wall[i][j].west;
  }
  i = 2;
  for(j = 0; j < MAZESIZE_Y; j++)
  {
    sta_wall[i][j].north = wall[i][j].north;
    sta_wall[i][j].east = wall[i][j].east;
    sta_wall[i][j].south = wall[i][j].south;
    sta_wall[i][j].west = wall[i][j].west;
  }
  i = 3;
  for(j = 0; j < MAZESIZE_Y; j++)
  {
    sta_wall[i][j].north = wall[i][j].north;
    sta_wall[i][j].east = wall[i][j].east;
    sta_wall[i][j].south = wall[i][j].south;
    sta_wall[i][j].west = wall[i][j].west;
  }
  i = 4;
  for(j = 0; j < MAZESIZE_Y; j++)
  {
    sta_wall[i][j].north = wall[i][j].north;
    sta_wall[i][j].east = wall[i][j].east;
    sta_wall[i][j].south = wall[i][j].south;
    sta_wall[i][j].west = wall[i][j].west;
  }
  i = 5;
  for(j = 0; j < MAZESIZE_Y; j++)
  {
    sta_wall[i][j].north = wall[i][j].north;
    sta_wall[i][j].east = wall[i][j].east;
    sta_wall[i][j].south = wall[i][j].south;
    sta_wall[i][j].west = wall[i][j].west;
  }
  i = 6;
  for(j = 0; j < MAZESIZE_Y; j++)
  {
    sta_wall[i][j].north = wall[i][j].north;
    sta_wall[i][j].east = wall[i][j].east;
    sta_wall[i][j].south = wall[i][j].south;
    sta_wall[i][j].west = wall[i][j].west;
  }
  i = 7;
  for(j = 0; j < MAZESIZE_Y; j++)
  {
    sta_wall[i][j].north = wall[i][j].north;
    sta_wall[i][j].east = wall[i][j].east;
    sta_wall[i][j].south = wall[i][j].south;
    sta_wall[i][j].west = wall[i][j].west;
  }
  i = 8;
  for(j = 0; j < MAZESIZE_Y; j++)
  {
    sta_wall[i][j].north = wall[i][j].north;
    sta_wall[i][j].east = wall[i][j].east;
    sta_wall[i][j].south = wall[i][j].south;
    sta_wall[i][j].west = wall[i][j].west;
  }
  i = 9;
  for(j = 0; j < MAZESIZE_Y; j++)
  {
    sta_wall[i][j].north = wall[i][j].north;
    sta_wall[i][j].east = wall[i][j].east;
    sta_wall[i][j].south = wall[i][j].south;
    sta_wall[i][j].west = wall[i][j].west;
  }
  i = 10;
  for(j = 0; j < MAZESIZE_Y; j++)
  {
    sta_wall[i][j].north = wall[i][j].north;
    sta_wall[i][j].east = wall[i][j].east;
    sta_wall[i][j].south = wall[i][j].south;
    sta_wall[i][j].west = wall[i][j].west;
  }
  i = 11;
  for(j = 0; j < MAZESIZE_Y; j++)
  {
    sta_wall[i][j].north = wall[i][j].north;
    sta_wall[i][j].east = wall[i][j].east;
    sta_wall[i][j].south = wall[i][j].south;
    sta_wall[i][j].west = wall[i][j].west;
  }
  i = 12;
  for(j = 0; j < MAZESIZE_Y; j++)
  {
    sta_wall[i][j].north = wall[i][j].north;
    sta_wall[i][j].east = wall[i][j].east;
    sta_wall[i][j].south = wall[i][j].south;
    sta_wall[i][j].west = wall[i][j].west;
  }
  i = 13;
  for(j = 0; j < MAZESIZE_Y; j++)
  {
    sta_wall[i][j].north = wall[i][j].north;
    sta_wall[i][j].east = wall[i][j].east;
    sta_wall[i][j].south = wall[i][j].south;
    sta_wall[i][j].west = wall[i][j].west;
  }
  i = 14;
  for(j = 0; j < MAZESIZE_Y; j++)
  {
    sta_wall[i][j].north = wall[i][j].north;
    sta_wall[i][j].east = wall[i][j].east;
    sta_wall[i][j].south = wall[i][j].south;
    sta_wall[i][j].west = wall[i][j].west;
  }
  i = 15;
  for(j = 0; j < MAZESIZE_Y; j++)
  {
    sta_wall[i][j].north = wall[i][j].north;
    sta_wall[i][j].east = wall[i][j].east;
    sta_wall[i][j].south = wall[i][j].south;
    sta_wall[i][j].west = wall[i][j].west;
  }

}


/* ============================================================ */
/* 関数名 : Fn_MAP_updateWall                                   */
/*          壁情報更新                                          */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 壁情報更新                                          */
/* 制約   : なし                                                */
/* ============================================================ */
void Fn_MAP_updateWall(void)
{
  int x,y;
  unsigned char n_write,s_write,e_write,w_write;

  if (mypos.dir == north) {                        /* 北を向いている時 */
     if (st_RecgWall_info.wall_f.bl_wall_with ==1) {
	     n_write = 1;
     }else{
	     n_write = 0;
     }

     if (st_RecgWall_info.wall_r.bl_wall_with ==1) {
	     e_write = 1;
     }else{
	     e_write = 0;
     }

     if (st_RecgWall_info.wall_l.bl_wall_with ==1) {
	     w_write = 1;
     }else{
	     w_write = 0;
     }

     s_write = NOWALL;                             /* 後ろは必ず壁がない */
  }
  
  if (mypos.dir == east) {                        /* 東を向いている時 */
     if (st_RecgWall_info.wall_f.bl_wall_with ==1) {
	     e_write = 1;
     }else{
	     e_write = 0;
     }

     if (st_RecgWall_info.wall_r.bl_wall_with ==1) {
	     s_write = 1;
     }else{
	     s_write = 0;
     }

     if (st_RecgWall_info.wall_l.bl_wall_with ==1) {
	     n_write = 1;
     }else{
	     n_write = 0;
     }

     w_write = NOWALL;                             /* 後ろは必ず壁がない */
  }
  
  if (mypos.dir == south) {                        /* 南を向いている時 */
     if (st_RecgWall_info.wall_f.bl_wall_with ==1) {
	     s_write = 1;
     }else{
	     s_write = 0;
     }

     if (st_RecgWall_info.wall_r.bl_wall_with ==1) {
	     w_write = 1;
     }else{
	     w_write = 0;
     }

     if (st_RecgWall_info.wall_l.bl_wall_with ==1) {
	     e_write = 1;
     }else{
	     e_write = 0;
     }

     n_write = NOWALL;                             /* 後ろは必ず壁がない */
  }

  if (mypos.dir == west) {                        /* 西を向いている時 */
     if (st_RecgWall_info.wall_f.bl_wall_with ==1) {
	     w_write = 1;
     }else{
	     w_write = 0;
     }

     if (st_RecgWall_info.wall_r.bl_wall_with ==1) {
	     n_write = 1;
     }else{
	     n_write = 0;
     }

     if (st_RecgWall_info.wall_l.bl_wall_with ==1) {
	     s_write = 1;
     }else{
	     s_write = 0;
     }

     e_write = NOWALL;                             /* 後ろは必ず壁がない */
  }

  

  /* 自車位置の壁情報を更新 */
  x = mypos.x;
  y = mypos.y;

  wall[x][y].north = n_write;
  wall[x][y].south = s_write;
  wall[x][y].east  = e_write;
  wall[x][y].west  = w_write;

  /* 反対側から見た壁情報を更新 */
  if(y < MAZESIZE_Y-1)
  {
    wall[x][y+1].south = n_write;
  }

  if(x < MAZESIZE_X-1)
  {
    wall[x+1][y].west = e_write;
  }

  if(y > 0)
  {
    wall[x][y-1].north = s_write;
  }

  if(x > 0)
  {
    wall[x-1][y].east = w_write;
  }

}



/* ============================================================ */
/* 関数名 : Fn_MAP_outputPosition                               */
/*          自車位置情報出力                                    */
/* 引数   : pst_mypos                                           */
/* 戻り値 : なし                                                */
/* 概要   : 自車位置情報出力                                    */
/* 制約   : なし                                                */
/* ============================================================ */
void Fn_MAP_outputPosition(t_position *pst_mypos)
{
  pst_mypos->x = mypos.x;
  pst_mypos->y = mypos.y;
  pst_mypos->dir = mypos.dir;

}


/* ============================================================ */
/* 関数名 : Fn_MAP_updatePosition                               */
/*          自車位置情報更新                                    */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 自車位置情報更新                                    */
/* 制約   : なし                                                */
/* ============================================================ */
void Fn_MAP_updatePosition(void)
{
  /* 次に向かう方向を記録する変数 */
  t_direction glob_nextdir;

  /* 次に行く方向を戻り値とする関数 */
  glob_nextdir = (t_direction)FnU1_Plan_indicatedir(mypos.x,mypos.y,mypos.dir);

  /* 方向を更新 */
  mypos.dir = glob_nextdir;

  if (mypos.dir == north) {
	  mypos.y++;
  }
  
  if (mypos.dir == east) {
	  mypos.x++;
  }

  if (mypos.dir == south) {
	  mypos.y--;
  }

  if (mypos.dir == west) {
	  mypos.x--;
  }
}

