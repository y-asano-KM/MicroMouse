/* ============================================================ */
/* ファイル名 : app_plan.c                                      */
/* 機能       : 最短経路算出・進行方向決定                      */
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
#include "app_map_pac.h"
#include "app_plan_mode_pac.h"

/* 本体 */
#include "app_plan.h"
#include "app_plan_pac.h"


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */
#define CU1_AppPln_ArraySize      ((U1)3)       /* (CU1_AppMap_MazeSizeX * CU1_AppMap_MazeSizeY - 1) / 8 */
#define CU1_AppPln_StepNumGoal    ((U1)0)       /* ステップ数:目的地 */
#define CU1_AppPln_StepNumInit    ((U1)255)     /* ステップ数初期値 */
#define CU1_AppPln_DirInit        ((U1)255)     /* 進行方向初期値 */
#define CU1_AppPln_BitPosMax      ((U1)7)       /* ビット位置最大値 */
#define CU1_AppPln_RunSearch      ((U1)0)       /* 探索走行 */
#define CU1_AppPln_RunShortest    ((U1)1)       /* 最短経路走行 */
#define CU1_AppPln_DirMsk         ((U1)0x03)    /* 方向用マスク */
#if (1)
  #define CU1_AppPln_GoalPosX     ((U1)2)       /* 目的地X */
  #define CU1_AppPln_GoalPosY     ((U1)2)       /* 目的地Y */
#else
  #define CU1_AppPln_GoalPosX     ((U1)7)       /* 目的地X */
  #define CU1_AppPln_GoalPosY     ((U1)7)       /* 目的地Y */
#endif

#if (0)
  #define OP_AppPln_Dbg           /* デバッグ用3月26日走行会MAP */
#endif
#if (1)
  #define OP_AppPln_DbgUseMode    /* Mode切替え(通常モード(最短経路走行モード):0, 探索走行モード:1)有効化 */
#endif


/* ============================================================ */
/* 型定義                                                       */
/* ============================================================ */


/* ============================================================ */
/* 関数プロトタイプ宣言(static)                                 */
/* ============================================================ */
static VD FnVD_AppPln_initMap(VD);
static VD FnVD_AppPln_extractShortestRoute(VD);
static U1 FnU1_AppPln_searchDir(U1 tu1X, U1 tu1Y, EN_PrjCmn_Dir4 tenDir);


/* ============================================================ */
/* 変数定義(extern)                                             */
/* ============================================================ */


/* ============================================================ */
/* 変数定義(static)                                             */
/* ============================================================ */
static U1 u1a2AppPln_StepMumMap[CU1_AppMap_MazeSizeX][CU1_AppMap_MazeSizeY];
static U1 u1aAppPln_North[CU1_AppPln_ArraySize];
static U1 u1aAppPln_East[CU1_AppPln_ArraySize];
static U1 u1aAppPln_South[CU1_AppPln_ArraySize];
static U1 u1aAppPln_West[CU1_AppPln_ArraySize];
static U1 u1AppPln_ShortestRouteFlg;  /* 最短経路抽出済フラグ */
static U1 u1AppPln_BytePos;           /* 最短経路抽出バイト位置 */
static U1 u1AppPln_BitPos;            /* 最短経路抽出ビット位置 */
static U1 u1AppPln_ActReq;            /* 上位4ビット:連続直進可能マス数, 下位4ビット:進行方向 */
static U1 u1AppPln_RunPattern;        /* 探索走行=0, 最短経路走行=1 */
static U1 u1AppPln_Dir;


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
/* 関数名 : FnVD_AppPln_initMap                                 */
/*          歩数Mapの初期化                                     */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 歩数Mapを全体を0xff、ゴール座標は0で初期化する      */
/* 制約   : なし                                                */
/* ============================================================ */
static VD FnVD_AppPln_initMap(VD)
{
  U1 tu1I;
  U1 tu1J;

  for (tu1I = (U1)0; tu1I < CU1_AppMap_MazeSizeX; tu1I++) {
    for (tu1J = (U1)0; tu1J < CU1_AppMap_MazeSizeY; tu1J++) {
      u1a2AppPln_StepMumMap[tu1I][tu1J] = CU1_AppPln_StepNumInit;
    }
  }

  /* ゴール座標の歩数を0に設定 */
#if (1)
  u1a2AppPln_StepMumMap[CU1_AppPln_GoalPosX][CU1_AppPln_GoalPosY] = CU1_AppPln_StepNumGoal;
#else
  u1a2AppPln_StepMumMap[CU1_AppPln_GoalPosX][CU1_AppPln_GoalPosY]                 = CU1_AppPln_StepNumGoal;
  u1a2AppPln_StepMumMap[CU1_AppPln_GoalPosX][CU1_AppPln_GoalPosY + (U1)1]         = CU1_AppPln_StepNumGoal;
  u1a2AppPln_StepMumMap[CU1_AppPln_GoalPosX + (U1)1][CU1_AppPln_GoalPosY]         = CU1_AppPln_StepNumGoal;
  u1a2AppPln_StepMumMap[CU1_AppPln_GoalPosX + (U1)1][CU1_AppPln_GoalPosY + (U1)1] = CU1_AppPln_StepNumGoal;
#endif

#if defined(OP_AppPln_Dbg)
  for (tu1I = (U1)0; tu1I < CU1_AppPln_ArraySize; tu1I++) {
    u1aAppPln_North[tu1I] = (U1)0x00;
    u1aAppPln_East[tu1I]  = (U1)0x00;
    u1aAppPln_South[tu1I] = (U1)0x00;
    u1aAppPln_West[tu1I]  = (U1)0x00;
  }

  u1AppPln_BytePos = (U1)0;                   /* 最短経路抽出バイト位置 */
  u1AppPln_BitPos  = CU1_AppPln_BitPosMax;    /* 最短経路抽出ビット位置 */
#endif
}


/* ============================================================ */
/* 関数名 : FnVD_AppPln_makeMap                                 */
/*          歩数Mapを作成する                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 壁情報をもとに歩数Mapを作成する                     */
/* 制約   : ゴールに着いたまたは経路探索を終了した時点でコール  */
/* ============================================================ */
VD FnVD_AppPln_makeMap(VD)
{
  U1 tu1X;
  U1 tu1Y;
  U1 tu1ChangeFlg;    /* Map作成終了を見極めるためのフラグ */

  /* Mapを初期化する */
  FnVD_AppPln_initMap();

  /* 最短経路走行 */
  if (u1AppPln_RunPattern == CU1_AppPln_RunShortest) {

    do {
      tu1ChangeFlg = (U1)C_OFF;    /* 変更がなかった場合にはループを抜ける */

      /* 迷路の大きさ分ループ(x座標) */
      for (tu1X = (U1)0; tu1X < CU1_AppMap_MazeSizeX; tu1X++) {
        /* 迷路の大きさ分ループ(y座標) */
        for (tu1Y = (U1)0; tu1Y < CU1_AppMap_MazeSizeY; tu1Y++) {

          /* 初期値の場合は次へ */
          if (u1a2AppPln_StepMumMap[tu1X][tu1Y] == CU1_AppPln_StepNumInit) {
            continue;
          }

          /* 範囲チェック */
          if (tu1Y < (U1)(CU1_AppMap_MazeSizeY - (U1)1)) {

             /* 壁がなければ */
            if (staAppMap_WallSts[tu1X][tu1Y].b2North == CU1_AppMap_WallStsNothing) {
              if (u1a2AppPln_StepMumMap[tu1X][(U1)(tu1Y + (U1)1)] == CU1_AppPln_StepNumInit) {
                u1a2AppPln_StepMumMap[tu1X][(U1)(tu1Y + (U1)1)] = u1a2AppPln_StepMumMap[tu1X][tu1Y] + (U1)1;
                tu1ChangeFlg = (U1)C_ON;       /* 値が更新されたことを示す */
              }
            }
          }

          /* 範囲チェック */
          if (tu1X < (U1)(CU1_AppMap_MazeSizeX - (U1)1)) {

            /* 壁がなければ */
            if (staAppMap_WallSts[tu1X][tu1Y].b2East == CU1_AppMap_WallStsNothing) {
              if ( u1a2AppPln_StepMumMap[(U1)(tu1X + (U1)1)][tu1Y] == CU1_AppPln_StepNumInit) {
                u1a2AppPln_StepMumMap[(U1)(tu1X + (U1)1)][tu1Y] = u1a2AppPln_StepMumMap[tu1X][tu1Y] + (U1)1;
                tu1ChangeFlg = (U1)C_ON;       /* 値が更新されたことを示す */
              }
            }
          }

          /* 範囲チェック */
          if (tu1Y > (U1)0) {
            /* 壁がなければ */
            if (staAppMap_WallSts[tu1X][tu1Y].b2South == CU1_AppMap_WallStsNothing) {
              if (u1a2AppPln_StepMumMap[tu1X][(U1)(tu1Y - (U1)1)] == CU1_AppPln_StepNumInit) {
                u1a2AppPln_StepMumMap[tu1X][(U1)(tu1Y - (U1)1)] = u1a2AppPln_StepMumMap[tu1X][tu1Y] + (U1)1;
                tu1ChangeFlg = (U1)C_ON;       /* 値が更新されたことを示す */
              }
            }
          }

          /* 範囲チェック */
          if (tu1X > (U1)0) {
            /* 壁がなければ */
            if (staAppMap_WallSts[tu1X][tu1Y].b2West == CU1_AppMap_WallStsNothing) {
              if (u1a2AppPln_StepMumMap[(U1)(tu1X - (U1)1)][tu1Y] == CU1_AppPln_StepNumInit) {
                u1a2AppPln_StepMumMap[(U1)(tu1X - (U1)1)][tu1Y] = u1a2AppPln_StepMumMap[tu1X][tu1Y] + (U1)1;
                tu1ChangeFlg = (U1)C_ON;       /* 値が更新されたことを示す */
              }
            }
          }
        }
      }
    } while (tu1ChangeFlg == (U1)C_ON);    /* 全体を作り終わるまで待つ */
  }
}


/* ============================================================ */
/* 関数名 : FnVD_AppPln_extractShortestRoute                    */
/*          最短経路を抽出する                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 作成した歩数Mapをもとに最短経路を抽出する           */
/* 制約   : なし                                                */
/* ============================================================ */
static VD FnVD_AppPln_extractShortestRoute(VD)
{
  U1 tu1X;
  U1 tu1Y;
  U1 tu1Idx;
  U1 tu1BytePos;
  U1 tu1BitPos;
  U1 tu1StepNum;
  EN_PrjCmn_Dir4 tenDir;
  EN_PrjCmn_Dir4 tenDirPrev;
  U1 tu1DirFlg;

  tu1X       = (U1)0;                         /* スタート地点のx座標 */
  tu1Y       = (U1)0;                         /* スタート地点のy座標 */
  tu1BytePos = (U1)0;
  tu1BitPos  = (U1)0;
  tu1StepNum = u1a2AppPln_StepMumMap[tu1X][tu1Y];    /* スタート地点の歩数マップ値を初期値設定 */
  tenDir     = CEN_PrjCmn_Dir4North;

  u1AppPln_ShortestRouteFlg = (U1)C_OFF;
  u1AppPln_BytePos = (U1)0;                   /* 最短経路抽出バイト位置 */
  u1AppPln_BitPos  = CU1_AppPln_BitPosMax;    /* 最短経路抽出ビット位置 */

  for (tu1Idx = (U1)0; tu1Idx < CU1_AppPln_ArraySize; tu1Idx++) {
    /* すべて0で埋める */
    u1aAppPln_North[tu1Idx] = (U1)0x00;
    u1aAppPln_East[tu1Idx]  = (U1)0x00;
    u1aAppPln_South[tu1Idx] = (U1)0x00;
    u1aAppPln_West[tu1Idx]  = (U1)0x00;
  }

  do {
    tu1DirFlg  = (U1)C_OFF;
    tenDirPrev = tenDir;           /* 前回値保持 */

    /* 範囲チェック */
    if (tu1Y < (U1)(CU1_AppMap_MazeSizeY - (U1)1)) {

      /* 壁がなければ */
      if (staAppMap_WallSts[tu1X][tu1Y].b2North == CU1_AppMap_WallStsNothing) {

        /* 歩数マップ値が-1であれば */
        if (u1a2AppPln_StepMumMap[tu1X][(U1)(tu1Y + (U1)1)] == (U1)(tu1StepNum - (U1)1)) {
          tenDir = CEN_PrjCmn_Dir4North;                /* 進行方角を設定 */
          tu1DirFlg = (U1)C_ON;      /* 値が更新されたことを示す */
        }
      }
    }

    /* 範囲チェック */
    if (tu1X < (U1)(CU1_AppMap_MazeSizeX - (U1)1)) {

      /* 壁がなければ */
      if (staAppMap_WallSts[tu1X][tu1Y].b2East == CU1_AppMap_WallStsNothing) {

        /* 歩数マップ値が-1であれば */
        if (u1a2AppPln_StepMumMap[(U1)(tu1X + (U1)1)][tu1Y] == (U1)(tu1StepNum - (U1)1)) {

          /* 進行方角に複数の可能性がある場合 */
          if (tu1DirFlg == (U1)C_ON) {

            /* 前回の進行方角と一致する場合は前回方角を優先 */
            if (tenDir != tenDirPrev) {
              tenDir = CEN_PrjCmn_Dir4East;    /* 進行方角を設定 */
              tu1DirFlg = (U1)C_ON;            /* 値が更新されたことを示す */
            }
          }
          else {
            tenDir = CEN_PrjCmn_Dir4East;    /* 進行方角を設定 */
            tu1DirFlg = (U1)C_ON;            /* 値が更新されたことを示す */
          }
        }
      }
    }

    /* 範囲チェック */
    if (tu1Y > (U1)0) {

      /* 壁がなければ */
      if (staAppMap_WallSts[tu1X][tu1Y].b2South == CU1_AppMap_WallStsNothing) {

        /* 歩数マップ値が-1であれば */
        if (u1a2AppPln_StepMumMap[tu1X][(U1)(tu1Y - (U1)1)] == (U1)(tu1StepNum - (U1)1)) {

          /* 進行方角に複数の可能性がある場合 */
          if (tu1DirFlg == (U1)C_ON) {

            /* 前回の進行方角と一致する場合は前回方角を優先 */
            if (tenDir != tenDirPrev) {
              tenDir = CEN_PrjCmn_Dir4South;    /* 進行方角を設定 */
              tu1DirFlg = (U1)C_ON;             /* 値が更新されたことを示す */
            }
          }
          else {
            tenDir = CEN_PrjCmn_Dir4South;    /* 進行方角を設定 */
            tu1DirFlg = (U1)C_ON;             /* 値が更新されたことを示す */
          }
        }
      }
    }

    /* 範囲チェック */
    if (tu1X > (U1)0) {

      /* 壁がなければ */
      if (staAppMap_WallSts[tu1X][tu1Y].b2West == CU1_AppMap_WallStsNothing) {

        /* 歩数マップ値が-1であれば */
        if (u1a2AppPln_StepMumMap[(U1)(tu1X - (U1)1)][tu1Y] == (U1)(tu1StepNum - (U1)1)) {

          /* 進行方角に複数の可能性がある場合 */
          if (tu1DirFlg == (U1)C_ON) {

            /* 前回の進行方角と一致する場合は前回方角を優先 */
            if (tenDir != tenDirPrev) {
              tenDir = CEN_PrjCmn_Dir4West;    /* 進行方角を設定 */
              tu1DirFlg = (U1)C_ON;            /* 値が更新されたことを示す */
            }
          }
          else {
            tenDir = CEN_PrjCmn_Dir4West;    /* 進行方角を設定 */
            tu1DirFlg = (U1)C_ON;            /* 値が更新されたことを示す */
          }
        }
      }
    }

    /* 進行方角を保持 */
    if (tu1DirFlg == (U1)C_ON) {
      if (tenDir == CEN_PrjCmn_Dir4North) {
        u1aAppPln_North[tu1BytePos] |= (U1)((U1)1 << (U1)(CU1_AppPln_BitPosMax - tu1BitPos));
      }
      if (tenDir == CEN_PrjCmn_Dir4East) {
        u1aAppPln_East[tu1BytePos]  |= (U1)((U1)1 << (U1)(CU1_AppPln_BitPosMax - tu1BitPos));
      }
      if (tenDir == CEN_PrjCmn_Dir4South) {
        u1aAppPln_South[tu1BytePos] |= (U1)((U1)1 << (U1)(CU1_AppPln_BitPosMax - tu1BitPos));
      }
      if (tenDir == CEN_PrjCmn_Dir4West) {
        u1aAppPln_West[tu1BytePos]  |= (U1)((U1)1 << (U1)(CU1_AppPln_BitPosMax - tu1BitPos));
      }

      tu1BitPos++;
      if (tu1BitPos > CU1_AppPln_BitPosMax) {
        tu1BytePos++;
        tu1BitPos = 0;
      }
    }
  } while (tu1DirFlg == (U1)C_ON);         /* 全体を作り終わるまで待つ */

  u1AppPln_ShortestRouteFlg = (U1)C_ON;    /* 最短経路抽出済 */
}


/* ============================================================ */
/* 関数名 : FnU1_AppPln_reqDir                                  */
/*          経路を指示する                                      */
/* 引数   : tu1X    ：現在地情報X                               */
/*          tu1Y    ：現在地情報Y                               */
/*          tenDir  ：現在の進行方角                            */
/* 戻り値 : u1t_ret ：EN_PrjCmn_Dir4                            */
/* 概要   : 現在地情報から経路(進行方角)を算出する              */
/* 制約   : なし                                                */
/* ============================================================ */
U1 FnU1_AppPln_reqDir(U1 tu1X, U1 tu1Y, EN_PrjCmn_Dir4 tenDir)
{
  U1 tu1StepNum;
  U1 tu1Dir;
  U1 tu1Val;
#if defined(OP_AppPln_DbgUseMode)
  EN_AppPln_Mode_Sts tenMode;
#endif

  tu1StepNum = u1a2AppPln_StepMumMap[tu1X][tu1Y];    /* 対象地点の歩数マップ値を初期値設定 */
  tu1Dir = CU1_AppPln_DirInit;

#if defined(OP_AppPln_Dbg)
  tu1StepNum = CU1_AppPln_StepNumInit - (U1)1;
#endif

#if defined(OP_AppPln_DbgUseMode)
  tenMode = FnEN_AppPln_Mode_get();
#endif

#if defined(OP_AppPln_DbgUseMode)
  if (tenMode == CEN_AppPln_Mode_StsReady) {
    u1AppPln_Dir    = tenDir;               /* 停止中のため現在の進行方角をセット */
    u1AppPln_ActReq = CU1_AppPln_ActStop;   /* 進行方向(停止) */
  }
  else {
#endif
    if (tu1StepNum == CU1_AppPln_StepNumInit) {
       /* 最短経路が判定できなかったため、壁判定CU1_AppMap_WallStsUnkown箇所(歩数マップ値が初期値CU1_AppPln_StepNumInitの箇所)の捜索 */
#if (1)
       tu1Dir = FnU1_AppPln_searchDir(tu1X, tu1Y, tenDir);
#else
       tu1Dir = (U1)CEN_PrjCmn_Dir4South;
#endif
    }
    else if (tu1StepNum == CU1_AppPln_StepNumGoal) {
      /* ゴール地点に着いたら */

      /* 最短経路未抽出の場合 */
      if (u1AppPln_ShortestRouteFlg == (U1)C_OFF) {
        u1AppPln_RunPattern = CU1_AppPln_RunShortest;
        FnVD_AppPln_makeMap();            /* 歩数マップ作成 */
        FnVD_AppPln_extractShortestRoute();      /* 最短経路抽出 */
        tu1Dir = (U1)((U1)((U1)tenDir + (U1)2) & CU1_AppPln_DirMsk);   /* 進行方向 TURNBACK(転回) */
      }
    }
    else {
#if defined(OP_AppPln_Dbg)
      u1aAppPln_North[0] = (U1)0xF0;    /* デバッグ用3月26日走行会MAP */
      u1aAppPln_East[0]  = (U1)0x0F;    /* デバッグ用3月26日走行会MAP */
      u1aAppPln_South[1] = (U1)0xC0;    /* デバッグ用3月26日走行会MAP */
      u1aAppPln_West[1]  = (U1)0x30;    /* デバッグ用3月26日走行会MAP */
#endif

      tu1Val = u1aAppPln_North[u1AppPln_BytePos];
      tu1Val &= (U1)((U1)1 << u1AppPln_BitPos);
      if (tu1Val != (U1)0) {
        tu1Dir = (U1)CEN_PrjCmn_Dir4North;              /* 進行方角 北 */
      }
      if (tu1Dir == CU1_AppPln_DirInit) {
        tu1Val = u1aAppPln_East[u1AppPln_BytePos];
        tu1Val &= (U1)((U1)1 << u1AppPln_BitPos);
        if (tu1Val != (U1)0) {
          tu1Dir = (U1)CEN_PrjCmn_Dir4East;             /* 進行方角 東 */
        }
      }
      if (tu1Dir == CU1_AppPln_DirInit) {
        tu1Val = u1aAppPln_South[u1AppPln_BytePos];
        tu1Val &= (U1)((U1)1 << u1AppPln_BitPos);
        if (tu1Val != (U1)0) {
          tu1Dir = (U1)CEN_PrjCmn_Dir4South;            /* 進行方角 南 */
        }
      }
      if (tu1Dir == CU1_AppPln_DirInit) {
        tu1Val = u1aAppPln_West[u1AppPln_BytePos];
        tu1Val &= (U1)((U1)1 << u1AppPln_BitPos);
        if (tu1Val != (U1)0) {
          tu1Dir = (U1)CEN_PrjCmn_Dir4West;             /* 進行方角 西 */
        }
      }

      if (u1AppPln_BitPos == (U1)0) {
        u1AppPln_BytePos++;
        u1AppPln_BitPos = CU1_AppPln_BitPosMax;
      }
      else {
        u1AppPln_BitPos--;
      }
    }

    u1AppPln_ActReq = CU1_AppPln_ActStop;    /* 進行方向(停止) */
    if (tu1Dir == (U1)tenDir) {
      u1AppPln_ActReq = (U1)((U1)0x10 | CU1_AppPln_ActGoStraight);  /* 進行方向(前進)1マス */
    }
    if (tu1Dir == (U1)((U1)((U1)tenDir + (U1)1) & CU1_AppPln_DirMsk)) {
      u1AppPln_ActReq = CU1_AppPln_ActTurnRight;  /* 進行方向(右折) */
    }
    if (tu1Dir == (U1)((U1)((U1)tenDir + (U1)2) & CU1_AppPln_DirMsk)) {
      u1AppPln_ActReq = CU1_AppPln_ActTurnBack;  /* 進行方向(転回) */
    }
    if (tu1Dir == (U1)((U1)((U1)tenDir + (U1)3) & CU1_AppPln_DirMsk)) {
      u1AppPln_ActReq = CU1_AppPln_ActTurnLeft;  /* 進行方向(左折) */
    }

#if (1)
    u1AppPln_Dir = tu1Dir;        /* 算出した進行方角をセット */
#endif
#if (0)
	  u1AppPln_ActReq = CU1_AppPln_ActStop;    /* 進行方向(停止) */
#endif
#if defined(OP_AppPln_DbgUseMode)
  }
#endif

  return (u1AppPln_ActReq);
}


/* ============================================================ */
/* 関数名 : FnU1_AppPln_searchDir                               */
/*          最短経路が分からない場合の経路を指示する            */
/* 引数   : tu1X    ：現在地情報X                               */
/*          tu1Y    ：現在地情報Y                               */
/*          tenDir ：現在の進行方角                             */
/* 戻り値 : 進行方向                                            */
/* 概要   : 現在地情報から経路(進行方角)を算出する              */
/*          優先順:ゴール→未検索方角→直進→右左折→後退       */
/* 制約   : なし                                                */
/* ============================================================ */
static U1 FnU1_AppPln_searchDir(U1 tu1X, U1 tu1Y, EN_PrjCmn_Dir4 tenDir)
{
  EN_PrjCmn_Dir4 tenDirection;
  U1 tu1Dir;            /* 進行方向 */
  U1 tu1Priority;       /* 優先順（ゴール:8、未検索:4、直進:2、右左折:1） */
  U1 tu1PriorityTmp;    /* 優先順（ゴール:8、未検索:4、直進:2、右左折:1） */
#if defined(OP_AppPln_DbgUseMode)
  EN_AppPln_Mode_Sts tenMode;
#endif

  tenDirection   = tenDir;
  tu1Dir         = CU1_AppPln_DirInit;
  tu1Priority    = (U1)0;
  tu1PriorityTmp = (U1)0;

#if defined(OP_AppPln_DbgUseMode)
  tenMode = FnEN_AppPln_Mode_get();
  if (tenMode == CEN_AppPln_Mode_StsSearch) {
    u1AppPln_RunPattern = CU1_AppPln_RunSearch;    /* 探索走行 */
  }
  else if (   (0)
  #if (0)
           || (tenMode == CEN_AppPln_Mode_StsTimeAttack)
  #endif
                                                        ) {

    /* 計測モード */
  }
  else {
  #if (1)
    u1AppPln_RunPattern = CU1_AppPln_RunShortest;    /* 最短経路走行 */
  #else
    u1AppPln_RunPattern = CU1_AppPln_RunSearch;      /* 最短経路走行 */
  #endif
  }
#endif

  /* 範囲チェック */
  if (tu1Y < (U1)(CU1_AppMap_MazeSizeY - (U1)1)) {

    /* 壁がなければ */
    if (staAppMap_WallSts[tu1X][tu1Y].b2North == CU1_AppMap_WallStsNothing) {
      tu1Dir = (U1)CEN_PrjCmn_Dir4North;               /* 進行方角 北(仮設定) */
#if defined(OP_AppPln_DbgUseMode)
      /* 最短経路走行 */
	    if (u1AppPln_RunPattern == CU1_AppPln_RunShortest) {
        /* ゴールだったら */
        if (u1a2AppPln_StepMumMap[tu1X][(U1)(tu1Y + (U1)1)] == CU1_AppPln_StepNumGoal) {
          tu1Priority = (U1)8;           /* 進行方角決定 */
        }
	    }
      else {
#endif
        /* 北に1マス進んだ先を一度も探索していなかったら */
        if (staAppMap_WallSts[tu1X][(U1)(tu1Y + (U1)1)].b2North == CU1_AppMap_WallStsUnkown) {
          tu1Priority = (U1)4;
        }

        if (tenDirection == CEN_PrjCmn_Dir4North) {
          /* 進行方角(北)が直進方向 */
          tu1Priority += (U1)2;
        }
        else if (tenDirection != CEN_PrjCmn_Dir4South) {
          /* 進行方角(北)が右左折方向 */
          tu1Priority += (U1)1;
        }
        else {
          /* 何もしない */
        }
#if defined(OP_AppPln_DbgUseMode)
      }
#endif
    }
  }

  if (tu1Priority < (U1)8) {

    /* 範囲チェック */
    if (tu1X < (U1)(CU1_AppMap_MazeSizeX - (U1)1)) {

      /* 壁がなければ */
      if (staAppMap_WallSts[tu1X][tu1Y].b2East == CU1_AppMap_WallStsNothing) {
#if defined(OP_AppPln_DbgUseMode)
        /* 最短経路走行 */
        if (u1AppPln_RunPattern == CU1_AppPln_RunShortest) {
          /* ゴールだったら */
          if (u1a2AppPln_StepMumMap[(U1)(tu1X + (U1)1) ][tu1Y] == CU1_AppPln_StepNumGoal) {
            tu1PriorityTmp = (U1)8;  /* 進行方角決定 */
          }
        }
        else {
#endif
          /* 東に1マス進んだ先を一度も探索していなかったら */
          if (staAppMap_WallSts[(U1)(tu1X + (U1)1)][tu1Y].b2East == CU1_AppMap_WallStsUnkown) {
            tu1PriorityTmp = (U1)4;
          }

          if (tenDirection == CEN_PrjCmn_Dir4East) {
            /* 進行方角(東)が直進方向 */
            tu1PriorityTmp += (U1)2;
          }
          else if (tenDirection != CEN_PrjCmn_Dir4West)
          {
            /* 進行方角(東)が右左折方向 */
            tu1PriorityTmp += (U1)1;
          }
          else {
            /* 何もしない */
          }
#if defined(OP_AppPln_DbgUseMode)
        }
#endif

        if (tu1PriorityTmp > tu1Priority) {
          tu1Dir = (U1)CEN_PrjCmn_Dir4East;        /* 進行方角 東(更新) */
          tu1Priority = tu1PriorityTmp;
          tu1PriorityTmp = (U1)0;  /* クリア処理 */
        }
        tu1PriorityTmp = (U1)0;  /* クリア処理 */
      }
    }
  }

  if (tu1Priority < (U1)8) {

    /* 範囲チェック */
    if (tu1Y > (U1)0) {
      /* 壁がなければ */
      if (staAppMap_WallSts[tu1X][tu1Y].b2South == CU1_AppMap_WallStsNothing) {
#if defined(OP_AppPln_DbgUseMode)
        /* 最短経路走行 */
        if (u1AppPln_RunPattern == CU1_AppPln_RunShortest) {
          /* ゴールだったら */
          if (u1a2AppPln_StepMumMap[tu1X][(U1)(tu1Y - (U1)1)] == CU1_AppPln_StepNumGoal) {
            tu1PriorityTmp = (U1)8;  /* 進行方角決定 */
          }
        }
        else {
#endif
          /* 南に1マス進んだ先を一度も探索していなかったら */
          if (staAppMap_WallSts[tu1X][(U1)(tu1Y - (U1)1)].b2South == CU1_AppMap_WallStsUnkown) {
            tu1PriorityTmp = (U1)4;
          }

          if (tenDirection == CEN_PrjCmn_Dir4South) {
            /* 進行方角(南)が直進方向 */
            tu1PriorityTmp += (U1)2;
          }
          else if (tenDirection != CEN_PrjCmn_Dir4North) {
            /* 進行方角(南)が右左折方向 */
            tu1PriorityTmp += (U1)1;
          }
          else {
            /* 何もしない */
          }
#if defined(OP_AppPln_DbgUseMode)
        }
#endif

        if (tu1PriorityTmp > tu1Priority) {
          tu1Dir = (U1)CEN_PrjCmn_Dir4South;       /* 進行方角 南(更新) */
          tu1Priority = tu1PriorityTmp;
          tu1PriorityTmp = (U1)0;  /* クリア処理 */
        }
        tu1PriorityTmp = (U1)0;  /* クリア処理 */
      }
    }
  }

  if (tu1Priority < (U1)8) {

    /* 範囲チェック */
    if (tu1Y > (U1)0) {

      /* 壁がなければ */
      if (staAppMap_WallSts[tu1X][tu1Y].b2West == CU1_AppMap_WallStsNothing) {
#if defined(OP_AppPln_DbgUseMode)
        /* 最短経路走行 */
        if (u1AppPln_RunPattern == CU1_AppPln_RunShortest) {
          /* ゴールだったら */
          if (u1a2AppPln_StepMumMap[(U1)(tu1X - (U1)1)][tu1Y] == CU1_AppPln_StepNumGoal) {
            tu1PriorityTmp = (U1)8;  /* 進行方角決定 */
          }
        }
        else {
#endif
          /* 西に1マス進んだ先を一度も探索していなかったら */
          if (staAppMap_WallSts[(U1)(tu1X - (U1)1)][tu1Y].b2West == CU1_AppMap_WallStsUnkown) {
            tu1PriorityTmp = (U1)4;
          }

          if (tenDirection == CEN_PrjCmn_Dir4West) {
            /* 進行方角(西)が直進方向 */
            tu1PriorityTmp += (U1)2;
          }
          else if (tenDirection != CEN_PrjCmn_Dir4East) {
            /* 進行方角(西)が右左折方向 */
            tu1PriorityTmp += (U1)1;
          }
          else {
            /* 何もしない */
          }
#if defined(OP_AppPln_DbgUseMode)
        }
#endif

        if (tu1PriorityTmp > tu1Priority) {
          tu1Dir = (U1)CEN_PrjCmn_Dir4West;        /* 進行方角 西(更新) */
          tu1Priority = tu1PriorityTmp;
        }
      }
    }
  }

  return (tu1Dir);
}


/* ============================================================ */
/* 関数名 : FnU1_AppPln_getDir                                  */
/*          現在の進行方角を返す                                */
/* 引数   : なし                                                */
/* 戻り値 : 進行方向                                            */
/* 概要   : 進行方向を返す                                      */
/* 制約   : なし                                                */
/* ============================================================ */
U1 FnU1_AppPln_getDir(VD)
{
  return (u1AppPln_Dir);
}


/* ============================================================ */
/* 関数名 : FnU1_AppPln_getActReq                               */
/*          進行方向を返す                                      */
/* 引数   : なし                                                */
/* 戻り値 : u1AppPln_ActReq 上位4ビット:連続直進可能マス数      */
/*                          下位4ビット:進行方向                */
/* 概要   : 進行方向と直進時は連続直進可能マス数を返す          */
/* 制約   : なし                                                */
/* ============================================================ */
U1 FnU1_AppPln_getActReq(VD)
{
  return (u1AppPln_ActReq);
}

