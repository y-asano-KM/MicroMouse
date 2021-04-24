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
#include "app_plan_pac.h"


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */
/* #define ARRAYSIZE 32 */      /* (MAZESIZE_X×MAZESIZE_Y－1)÷8 */
#define ARRAYSIZE 3             /* (MAZESIZE_X×MAZESIZE_Y－1)÷8 */

#define flag U1
#define false 0
#define true 1

#define debug_plan 0            /* デバッグ用3月26日走行会MAP */
#define debug_planmode 1        /* Mode切替え(通常モード(最短経路走行モード):0, 探索走行モード:1)有効化 */

/* ============================================================ */
/* 型定義                                                       */
/* ============================================================ */

/* ============================================================ */
/* 関数プロトタイプ宣言(static)                                 */
/* ============================================================ */
static U1 FnU1_Plan_searchdir(U1 x, U1 y, t_direction dir);

/* ============================================================ */
/* 変数定義(extern)                                             */
/* ============================================================ */

/* ============================================================ */
/* 変数定義(static)                                             */
/* ============================================================ */
static U1 u1s_map[MAZESIZE_X][MAZESIZE_Y];
static U1 u1s_north[ARRAYSIZE];
static U1 u1s_east[ARRAYSIZE];
static U1 u1s_south[ARRAYSIZE];
static U1 u1s_west[ARRAYSIZE];
static U1 u1s_shortestroute_c;  /* 最短経路抽出済フラグ */
static U1 u1s_bytepos;          /* 最短経路抽出バイト位置 */
static U1 u1s_bitpos;           /* 最短経路抽出ビット位置 */
static U1 u1s_direction;        /* 上位４ビット：連続直進可能マス数 */
                                /* 下位４ビット：FORWORD(前進)=0,TURNRIGHT(右折)=1,TURNBACK(転回)=2,TURNLEFT(左折)=3,STOP(停止)=4 */
static U1 u1s_runpattern;       /* 探索走行=0,最短経路走行=1 */
static U1 u1s_retdir;

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
/* 関数名 : FnVD_Plan_initmap                                   */
/*          歩数Mapの初期化                                     */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 歩数Mapを全体を0xff、ゴール座標(x,y)は0で初期化する */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_Plan_initmap(VD)
{
    U1 u1t_i;
    U1 u1t_j;

    for( u1t_i = (U1)0; u1t_i < MAZESIZE_X; u1t_i++ )           /* 迷路の大きさ分ループ(x座標) */
    {
        for( u1t_j = (U1)0; u1t_j < MAZESIZE_Y; u1t_j++ )       /* 迷路の大きさ分ループ(y座標) */
        {
            u1s_map[u1t_i][u1t_j] = (U1)255;                    /* すべて255で埋める */
        }
    }

    //ゴール座標の歩数を0に設定
    u1s_map[2][2] = (U1)0;
    /*u1s_map[7][7] = (U1)0;*/
    /*u1s_map[7][8] = (U1)0;*/
    /*u1s_map[8][7] = (U1)0;*/
    /*u1s_map[8][8] = (U1)0;*/

#if debug_plan
    for( u1t_i = (U1)0; u1t_i < ARRAYSIZE; u1t_i++ )
    {
        u1s_north[u1t_i] = (U1)0x00;
        u1s_east[u1t_i] = (U1)0x00;
        u1s_south[u1t_i] = (U1)0x00;
        u1s_west[u1t_i] = (U1)0x00;
    }

    u1s_bytepos = (U1)0;                /* 最短経路抽出バイト位置 */
    u1s_bitpos = (U1)7;                 /* 最短経路抽出ビット位置 */
#endif

}

/* ============================================================ */
/* 関数名 : FnVD_Plan_makemap                                   */
/*          歩数Mapを作成する                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 壁情報をもとに歩数Mapを作成する                     */
/* 制約   : ゴールに着いたまたは経路探索を終了した時点でコール  */
/* ============================================================ */
VD FnVD_Plan_makemap(VD)
{
    U1 u1t_i;
    U1 u1t_j;
    flag bit_change_flag;       /* Map作成終了を見極めるためのフラグ */

    FnVD_Plan_initmap();        /* Mapを初期化する */

    if( u1s_runpattern == 1 )     /* 最短経路走行 */
    {

        do
        {
            bit_change_flag = (flag)false;                          /* 変更がなかった場合にはループを抜ける */
            for( u1t_i = 0; u1t_i < MAZESIZE_X; u1t_i++ )           /* 迷路の大きさ分ループ(x座標) */
            {
                for( u1t_j = 0; u1t_j < MAZESIZE_Y; u1t_j++ )       /* 迷路の大きさ分ループ(y座標) */
                {

                    if( u1s_map[u1t_i][u1t_j] == (U1)255 )          /* 255の場合は次へ */
                    {
                        continue;
                    }

                    if( u1t_j < (U1)( MAZESIZE_Y - (U1)1 ) )        /* 範囲チェック */
                    {
                        if( wall[u1t_i][u1t_j].north == NOWALL )    /* 壁がなければ */
                        {
                            if( u1s_map[u1t_i][ (U1)( u1t_j + (U1)1 ) ] == (U1)255 )        /* まだ値が入っていなければ */
                            {
                                u1s_map[u1t_i][ (U1)( u1t_j + (U1)1 ) ] = (U1)( u1s_map[u1t_i][u1t_j] + (U1)1 );    /* 値を代入 */
                                bit_change_flag = (flag)true;       /* 値が更新されたことを示す */
                            }
                        }
                    }

                    if( u1t_i < (U1)( MAZESIZE_X - (U1)1 ) )        /* 範囲チェック */
                    {
                        if( wall[u1t_i][u1t_j].east == NOWALL )     /* 壁がなければ */
                        {
                            if( u1s_map[ (U1)( u1t_i + (U1)1 ) ][u1t_j] == (U1)255 )        /* まだ値が入っていなければ */
                            {
                                u1s_map[ (U1)( u1t_i + (U1)1 ) ][u1t_j] = (U1)( u1s_map[u1t_i][u1t_j] + (U1)1 );    /* 値を代入 */
                                bit_change_flag = (flag)true;       /* 値が更新されたことを示す */
                            }
                        }
                    }

                    if( u1t_j > (U1)0 )                             /* 範囲チェック */
                    {
                        if( wall[u1t_i][u1t_j].south == NOWALL )    /* 壁がなければ */
                        {
                            if( u1s_map[u1t_i][ (U1)( u1t_j - (U1)1 ) ] == (U1)255 )        /* 値が入っていなければ */
                            {
                                u1s_map[u1t_i][ (U1)( u1t_j - (U1)1 ) ] = (U1)( u1s_map[u1t_i][u1t_j] + (U1)1 );    /* 値を代入 */
                                bit_change_flag = (flag)true;       /* 値が更新されたことを示す */
                            }
                        }
                    }

                    if( u1t_i > (U1)0 )                             /* 範囲チェック */
                    {
                        if( wall[u1t_i][u1t_j].west == NOWALL )     /* 壁がなければ */
	                {
                            if( u1s_map[ (U1)( u1t_i - (U1)1 ) ][u1t_j] == (U1)255 )        /* 値が入っていなければ */
                            {
                                u1s_map[ (U1)( u1t_i - (U1)1 ) ][u1t_j] = (U1)( u1s_map[u1t_i][u1t_j] + (U1)1 );    /* 値を代入 */
                                bit_change_flag = (flag)true;       /* 値が更新されたことを示す */
                            }
                        }
                    }
                }

            }

        }while( bit_change_flag == (flag)true );    /* 全体を作り終わるまで待つ */
    }

}

/* ============================================================ */
/* 関数名 : FnVD_Plan_shortestroute                             */
/*          最短経路を抽出する                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 作成した歩数Mapをもとに最短経路を抽出する           */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_Plan_shortestroute(VD)
{
    U1 u1t_i;
    U1 u1t_j;
    U1 u1t_k;
    U1 u1t_l;
    U1 u1t_m;
    U1 u1t_n;
    t_direction u1t_dir;        /* north=0,east=1,south=2,west=3 */

    U1 u1t_dir_before;
    flag bit_dir_flag;

    u1t_i = (U1)0;                      /* スタート地点のx座標 */
    u1t_j = (U1)0;                      /* スタート地点のy座標 */
    u1t_l = (U1)0;
    u1t_m = (U1)0;
    u1t_n = u1s_map[u1t_i][u1t_j];      /* スタート地点の歩数マップ値を初期値設定 */
    u1t_dir = north;

    u1s_shortestroute_c = (U1)0;
    u1s_bytepos = (U1)0;                /* 最短経路抽出バイト位置 */
    u1s_bitpos = (U1)7;                 /* 最短経路抽出ビット位置 */

    for( u1t_k = (U1)0; u1t_k < ARRAYSIZE; u1t_k++ )    /* すべて0で埋める */
    {
        u1s_north[u1t_k] = (U1)0;
        u1s_east[u1t_k] = (U1)0;
        u1s_south[u1t_k] = (U1)0;
        u1s_west[u1t_k] = (U1)0;
    }

    do
    {
        bit_dir_flag = (flag)false;
        u1t_dir_before = u1t_dir;           /* 前回値保持 */

        if( u1t_j < (U1)( MAZESIZE_Y - (U1)1 ) )    /* 範囲チェック */
        {
            if( wall[u1t_i][u1t_j].north == NOWALL )        /* 壁がなければ */
            {
                if( u1s_map[u1t_i][ (U1)( u1t_j + (U1)1 ) ] == (U1)( u1t_n - (U1)1 ) )  /* 歩数マップ値が-1であれば */
                {
                    u1t_dir = north;                /* 進行方角を設定 */
                    bit_dir_flag = (flag)true;      /* 値が更新されたことを示す */
                }
            }
        }

        if( u1t_i < (U1)( MAZESIZE_X - (U1)1 ) )    /* 範囲チェック */
        {
            if( wall[u1t_i][u1t_j].east == NOWALL )         /* 壁がなければ */
            {
                if( u1s_map[ (U1)( u1t_i + (U1)1 ) ][u1t_j] == (U1)( u1t_n - (U1)1 ) ) /* 歩数マップ値が-1であれば */
                {
                    if( bit_dir_flag == (flag)true )        /* 進行方角に複数の可能性がある場合 */
                    {
                        if( u1t_dir != u1t_dir_before )     /* 前回の進行方角と一致する場合は前回方角を優先 */
                        {
                            u1t_dir = east;         /* 進行方角を設定 */
                            bit_dir_flag = (flag)true;      /* 値が更新されたことを示す */
                        }
                    }
                    else
                    {
                        u1t_dir = east;             /* 進行方角を設定 */
                        bit_dir_flag = (flag)true;         /* 値が更新されたことを示す */
  
                    }
                }
            }
        }

        if( u1t_j > (U1)0 )                         /* 範囲チェック */
        {
            if( wall[u1t_i][u1t_j].south == NOWALL )        /* 壁がなければ */
            {
                if( u1s_map[u1t_i][ (U1)( u1t_j - (U1)1 ) ] == (U1)( u1t_n - (U1)1 ) )  /* 歩数マップ値が-1であれば */
                {
                    if( bit_dir_flag == (flag)true )        /* 進行方角に複数の可能性がある場合 */
                    {
                        if( u1t_dir != u1t_dir_before )     /* 前回の進行方角と一致する場合は前回方角を優先 */
                        {
                            u1t_dir = south;        /* 進行方角を設定 */
                            bit_dir_flag = (flag)true;      /* 値が更新されたことを示す */
                        }
                    }
                    else
                    {
                        u1t_dir = south;            /* 進行方角を設定 */
                        bit_dir_flag = (flag)true;          /* 値が更新されたことを示す */
  
                    }
                }
            }
        }

        if( u1t_i > (U1)0 )                         /* 範囲チェック */
        {
            if( wall[u1t_i][u1t_j].west == NOWALL )         /* 壁がなければ */
            {
                if( u1s_map[ (U1)( u1t_i - (U1)1 ) ][u1t_j] == (U1)( u1t_n - (U1)1 ) )  /* 歩数マップ値が-1であれば */
                {
                    if( bit_dir_flag == (flag)true )        /* 進行方角に複数の可能性がある場合 */
                    {
                        if( u1t_dir != u1t_dir_before )     /* 前回の進行方角と一致する場合は前回方角を優先 */
                        {
                            u1t_dir = west;         /* 進行方角を設定 */
                            bit_dir_flag = (flag)true;      /* 値が更新されたことを示す */
                        }
                    }
                    else
                    {
                        u1t_dir = west;             /* 進行方角を設定 */
                        bit_dir_flag = (flag)true;          /* 値が更新されたことを示す */
  
                    }
                }
            }
        }

        if( bit_dir_flag == (flag)true )        /* 進行方角を保持 */
        {
            if( u1t_dir == north )
            {
                u1s_north[u1t_l] |= ( (U1)1 << (U1)( (U1)7 - u1t_m ) );
            }
            if( u1t_dir == east )
            {
                u1s_east[u1t_l] |= ( (U1)1 << (U1)( (U1)7 - u1t_m ) );
            }
            if( u1t_dir == south )
            {
                u1s_south[u1t_l] |= ( (U1)1 << (U1)( (U1)7 - u1t_m ) );
            }
            if( u1t_dir == west )
            {
                u1s_west[u1t_l] |= ( (U1)1 << (U1)( (U1)7 - u1t_m ) );
            }

            u1t_m++;
            if( u1t_m > (U1)7 )
            {
                u1t_l++;
                u1t_m = 0;
            }
        }

    }while( bit_dir_flag == (flag)true );      /* 全体を作り終わるまで待つ */

    u1s_shortestroute_c = (U1)1;               /* 最短経路抽出済 */

}

/* ============================================================ */
/* 関数名 : FnU1_Plan_indicatedir                               */
/*          経路を指示する                                      */
/* 引数   : x,y ：現在地情報(x,y)                               */
/*          dir ：現在の進行方角                                */
/* 戻り値 : u1t_ret ：north=0,east=1,south=2,west=3             */
/* 概要   : 現在地情報(x,y)から経路(進行方角)を算出する         */
/* 制約   : なし                                                */
/* ============================================================ */
U1 FnU1_Plan_indicatedir(U1 x, U1 y, t_direction dir)
{
    U1 u1t_n;
    U1 u1t_ret;         /* north=0,east=1,south=2,west=3 */
    U1 u1t_temp;
    
    u1t_n = u1s_map[x][y];      /* 対象地点の歩数マップ値を初期値設定 */
    u1t_ret = (U1)255;

#if debug_plan
    u1t_n = (U1)254;
#endif

#if debug_planmode
    U1 u1t_mode;

    u1t_mode = FnEN_AppPln_Mode_get();
    if( u1t_mode == (U1)CEN_AppPln_Mode_Ready )     /* 準備モード */
    {
      u1s_retdir = dir;           /* 停止中のため現在の進行方角をセット */
      u1s_direction = (U1)0x04;   /* 進行方向　STOP(停止) */
    }
    else
    {
#endif

        if( u1t_n == (U1)255 )
        {
            /* 最短経路が判定できなかったため、壁判定UNKNOWN箇所(歩数マップ値が初期値(255)の箇所)の捜索 */
            u1t_ret = FnU1_Plan_searchdir( x, y, dir );
        }
        else if( u1t_n == (U1)0 )   /* ゴール地点に着いたら */
        {
            if( u1s_shortestroute_c == (U1)0 )  /* 最短経路未抽出の場合 */
            {
                u1s_runpattern =1;
                FnVD_Plan_makemap();            /* 歩数マップ作成 */
                FnVD_Plan_shortestroute();      /* 最短経路抽出 */
                u1t_ret = (U1)( (U1)( dir + (U1)2 ) & (U1)0x03 );   /* 進行方向　TURNBACK(転回) */
            }
        }
        else
        {

#if debug_plan
            u1s_north[0] = (U1)0xF0;    /* デバッグ用3月26日走行会MAP */
            u1s_east[0] = (U1)0x0F;     /* デバッグ用3月26日走行会MAP */
            u1s_south[1] = (U1)0xC0;    /* デバッグ用3月26日走行会MAP */
            u1s_west[1] = (U1)0x30;     /* デバッグ用3月26日走行会MAP */
#endif

            u1t_temp = u1s_north[u1s_bytepos];
            u1t_temp &= ( (U1)1 << u1s_bitpos );
            if( u1t_temp != (U1)0 )
            {
                u1t_ret = north;                /* 進行方角　北 */
            }
            if( u1t_ret == (U1)255 )
            {
                u1t_temp = u1s_east[u1s_bytepos];
                u1t_temp &= ( (U1)1 << u1s_bitpos );
                if( u1t_temp != (U1)0 )
                {
                    u1t_ret = east;             /* 進行方角　東 */
                }
            }
            if( u1t_ret == (U1)255 )
            {
                u1t_temp = u1s_south[u1s_bytepos];
                u1t_temp &= ( (U1)1 << u1s_bitpos );
                if( u1t_temp != (U1)0 )
                {
                    u1t_ret = south;            /* 進行方角　南 */
                }
            }
            if( u1t_ret == (U1)255 )
            {
                u1t_temp = u1s_west[u1s_bytepos];
                u1t_temp &= ( (U1)1 << u1s_bitpos );
                if( u1t_temp != (U1)0 )
                {
                    u1t_ret = west;             /* 進行方角　西 */
                }
            }

            if( u1s_bitpos == (U1)0 )
            {
                u1s_bytepos++;
                u1s_bitpos = (U1)7;
            }
            else
            {
                u1s_bitpos--;
            }
        }

        u1s_direction = (U1)0x04;      /* 進行方向　STOP(停止) */
        if( u1t_ret == dir )
        {
            u1s_direction = (U1)0x10;  /* 進行方向　FORWORD(前進)１マス */
        }
        if( u1t_ret == ( (U1)( dir + (U1)1 ) & (U1)0x03 ) )
        {
            u1s_direction = (U1)0x01;  /* 進行方向　TURNRIGHT(右折) */
        }
        if( u1t_ret == ( (U1)( dir + (U1)2 ) & (U1)0x03 ) )
        {
            u1s_direction = (U1)0x02;  /* 進行方向　TURNBACK(転回) */
        }
        if( u1t_ret == ( (U1)( dir + (U1)3 ) & (U1)0x03 ) )
        {
            u1s_direction = (U1)0x03;  /* 進行方向　TURNLEFT(左折) */
        }

        u1s_retdir = u1t_ret;   /* 算出した進行方角をセット */

#if debug_planmode
    }
#endif

    return(u1s_direction);

}

/* ============================================================ */
/* 関数名 : FnU1_Plan_searchdir                                 */
/*          最短経路が分からない場合の経路を指示する            */
/* 引数   : x,y ：現在地情報(x,y)                               */
/*          dir ：現在の進行方角(north=0,east=1,south=2,west=3) */
/* 戻り値 : u1t_ret_temp ：north=0,east=1,south=2,west=3        */
/* 概要   : 現在地情報(x,y)から経路(進行方角)を算出する         */
/*          優先順:ゴール→未検索方角→直進→右左折→後退       */
/* 制約   : なし                                                */
/* ============================================================ */
static U1 FnU1_Plan_searchdir(U1 x, U1 y, t_direction dir)
{
    t_direction u1t_dir;        /* north=0,east=1,south=2,west=3 */
    U1 u1t_ret_temp;            /* north=0,east=1,south=2,west=3,初期値=255 */
    U1 u1t_priority;            /* 優先順（ゴール:8、未検索:4、直進:2、右左折:1） */
    U1 u1t_priority_temp;       /* 優先順（ゴール:8、未検索:4、直進:2、右左折:1） */

    u1t_dir = dir;
    u1t_ret_temp = (U1)255;
    u1t_priority = (U1)0;
    u1t_priority_temp = (U1)0;

#if debug_planmode
    U1 u1t_mode;

    u1t_mode = FnEN_AppPln_Mode_get();
    if( u1t_mode == (U1)CEN_AppPln_Mode_Search )        /* 探索モード */
    {
        u1s_runpattern = (U1)0;     /* 探索走行 */
    }
    else if( u1t_mode == (U1)CEN_AppPln_Mode_TimeAttack )       /* 計測モード */
    {
        u1s_runpattern = (U1)1;     /* 最短経路走行 */
    }
#endif

    if( y < (U1)( MAZESIZE_Y - (U1)1 ) )        /* 範囲チェック */
    {
        if( wall[x][y].north == NOWALL )        /* 壁がなければ */
        {
            u1t_ret_temp = north;               /* 進行方角　北(仮設定) */
#if debug_planmode
	    if( u1s_runpattern == (U1)1 )       /* 最短経路走行 */
	    {
                if( u1s_map[x][ (U1)( y + (U1)1 ) ] == (U1)0 )      /* ゴールだったら */
                {
                    u1t_priority = (U1)8;           /* 進行方角決定 */
                }
	    }
            else
            {
#endif
                if( wall[x][ (U1)( y + (U1)1 ) ].north == UNKNOWN )     /* 北に１マス進んだ先を一度も探索していなかったら */
                {
                    u1t_priority = (U1)4;
                }

                if( u1t_dir == north )          /* 進行方角(北)が直進方向 */
                {
                    u1t_priority += (U1)2;
                }
                else if( u1t_dir != south )     /* 進行方角(北)が右左折方向 */
                {
                    u1t_priority += (U1)1;
                }
#if debug_planmode
            }
#endif
        }
    }

    if( u1t_priority < (U1)8 )
    {
        if( x < (U1)( MAZESIZE_X - (U1)1 ) )    /* 範囲チェック */
        {
            if( wall[x][y].east == NOWALL )     /* 壁がなければ */
            {
#if debug_planmode
                if( u1s_runpattern == (U1)1 )       /* 最短経路走行 */
	        {
                    if( u1s_map[ (U1)( x + (U1)1 ) ][y] == (U1)0 )          /* ゴールだったら */
                    {
                        u1t_priority_temp = (U1)8;  /* 進行方角決定 */
                    }
                }
                else
                {
#endif
                    if( wall[ (U1)( x + (U1)1 ) ][y].east == UNKNOWN ) /* 東に１マス進んだ先を一度も探索していなかったら */
                    {
                        u1t_priority_temp = (U1)4;
                    }

                    if( u1t_dir == east )       /* 進行方角(東)が直進方向 */
                    {
                        u1t_priority_temp += (U1)2;
                    }
                    else if( u1t_dir != west )  /* 進行方角(東)が右左折方向 */
                    {
                        u1t_priority_temp += (U1)1;
                    }
#if debug_planmode
                }
#endif

                if( u1t_priority_temp > u1t_priority )
                {
                    u1t_ret_temp = east;        /* 進行方角　東(更新) */
                    u1t_priority = u1t_priority_temp;
                    u1t_priority_temp = (U1)0;  /* クリア処理 */
                }
            }
        }
    }

    if( u1t_priority < (U1)8 )
    {
        if( y > (U1)0 )                         /* 範囲チェック */
        {
            if( wall[x][y].south == NOWALL )    /* 壁がなければ */
            {
#if debug_planmode
                if( u1s_runpattern == (U1)1 )       /* 最短経路走行 */
	        {
                    if( u1s_map[x][ (U1)( y - (U1)1 ) ] == (U1)0 )  /* ゴールだったら */
                    {
                        u1t_priority_temp = (U1)8;  /* 進行方角決定 */
                    }
                }
                else
                {
#endif
                    if( wall[x][ (U1)( y - (U1)1 ) ].south == UNKNOWN ) /* 南に１マス進んだ先を一度も探索していなかったら */
                    {
                        u1t_priority_temp = (U1)4;
                    }

                    if( u1t_dir == south )      /* 進行方角(南)が直進方向 */
                    {
                        u1t_priority_temp += (U1)2;
                    }
                    else if( u1t_dir != north ) /* 進行方角(南)が右左折方向 */
                    {
                        u1t_priority_temp += (U1)1;
                    }
#if debug_planmode
                }
#endif

                if( u1t_priority_temp > u1t_priority )
                {
                    u1t_ret_temp = south;       /* 進行方角　南(更新) */
                    u1t_priority = u1t_priority_temp;
                    u1t_priority_temp = (U1)0;  /* クリア処理 */
                }
            }
        }
    }

    if( u1t_priority < (U1)8 )
    {
        if( y > (U1)0 )                         /* 範囲チェック */
        {
            if( wall[x][y].west == NOWALL )    /* 壁がなければ */
            {
#if debug_planmode
                if( u1s_runpattern == (U1)1 )       /* 最短経路走行 */
	        {
                    if( u1s_map[ (U1)( x - (U1)1 ) ][y] == (U1)0 )  /* ゴールだったら */
                    {
                        u1t_priority_temp = (U1)8;  /* 進行方角決定 */
                    }
                }
                else
                {
#endif
                    if( wall[ (U1)( x - (U1)1 ) ][y].west == UNKNOWN )  /* 西に１マス進んだ先を一度も探索していなかったら */
                    {
                        u1t_priority_temp = (U1)4;
                    }

                    if( u1t_dir == west )       /* 進行方角(西)が直進方向 */
                    {
                        u1t_priority_temp += (U1)2;
                    }
                    else if( u1t_dir != east )  /* 進行方角(西)が右左折方向 */
                    {
                        u1t_priority_temp += (U1)1;
                    }
#if debug_planmode
                }
#endif

                if( u1t_priority_temp > u1t_priority )
                {
                    u1t_ret_temp = west;        /* 進行方角　西(更新) */
                    u1t_priority = u1t_priority_temp;
                }
            }
        }
    }

    return(u1t_ret_temp);

}

/* ============================================================ */
/* 関数名 : FnU1_Plan_retdir                                    */
/*          現在の進行方角を返す                                */
/* 引数   : なし                                                */
/* 戻り値 : u1t_ret ：north=0,east=1,south=2,west=3             */
/* 概要   : 進行方向を返す                                      */
/* 制約   : なし                                                */
/* ============================================================ */
U1 FnU1_Plan_retdir(VD)
{
    return(u1s_retdir);
}

/* ============================================================ */
/* 関数名 : FnU1_Plan_returndir                                 */
/*          進行方向を返す                                      */
/* 引数   : なし                                                */
/* 戻り値 : u1s_direction ：上位４ビット：連続直進可能マス数    */
/*            下位４ビット：FORWORD(前進)=0,TURNRIGHT(右折)=1,  */
/*              TURNBACK(転回)=2,TURNLEFT(左折)=3,STOP(停止)=4  */
/* 概要   : 進行方向と直進時は連続直進可能マス数を返す          */
/* 制約   : なし                                                */
/* ============================================================ */
U1 FnU1_Plan_returndir(VD)
{
    return(u1s_direction);
}
