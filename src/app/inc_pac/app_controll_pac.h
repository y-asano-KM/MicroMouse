#if !defined(INCLUDED_app_controll_pac_h)
#define INCLUDED_app_controll_pac_h
/* ============================================================ */
/* ファイル名 : app_controll_pac.h                               */
/* 機能       :                                                 */
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
#include "app_map_pac.h"

/* 本体 */


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */
/* PLAN 動作指示 */
#define VHECLE_FORWORD        0                   /* 前進(north)  */
#define VHECLE_TURNRIGHT      1                   /* 右折(west)   */
#define VHECLE_TURNBACK       2                   /* 転回(south)  */
#define VHECLE_TURNLEFT       3                   /* 左折(east)   */
#define VHECLE_STOP           4                   /* 停止() */

/* モーター制御 */
#define    MTR_STOP           0                   /* モータ停止 MTR OFFで表現するためRUNと同値 */
#define    MTR_RUN            0                   /* モータ前進 */
#define    MTR_BACK           1                   /* モータ後進 */

/* MTU ON/OFF */
#define MTU_ON                1                   /* MTU ON  */
#define MTU_OFF               0                   /* MTU OFF */

/* モーター励磁 */
#define MTR_ON                1                   /* モーター励磁 ON */
#define MTR_OFF               0                   /* モーター励磁 OFF */

/* モーター速度 */
#define MIN_SPEED             100                 /* 最低速度(100mm/S) */
#define NORMAL_SPEED          500                 /* 通常速度(500mm/S) */
#define TURN_SPEED            200                 /* 最低速度(200mm/S) */

/* 加速値 */
#define ACCEL_VALUE           2                   /* 加速値 */

/* 迷路走行のパラメータ */
#define ONE_BLOCK             2                   /* １区画 */
#define HALF_BLOCK            1                   /* 半区画 */

/* 迷路のパラメータ */
#define BLOCK_LENGTH          180.0               /* １区画=180mm */

/* 定数定義 */
#define    PI            3.14159265358979            /* 円周率π */
/* モーターMTU発振数 */
#define MTU_MTR_CLOCK        6000000                    /* モーター用MTUの発振数 */



/* Pi:Coの物理的なパラメータ */
#define TIRE_DIAMETER         48.0                /* タイヤの直径(mm)＝48.0mm　(要調節) */
#define TREAD_WIDTH           64.0                /* トレッド幅(mm)＝64.0mm　(要調節) */

#define TIRE_CIRCUIT          (PI * TIRE_DIAMETER)                    /* タイヤの円周(mm)≒150.80mm */
#define TREAD_CIRCUIT         (TREAD_WIDTH * PI)                      /* 360°旋回時にタイヤが動く距離(mm)≒201.06mm */
#define STEP_DEGREE           (1.8 / 2.0)                             /* ステッピングモータ(1-2相励磁)のステップ角(°/step) */
#define STEP_LENGTH           (TIRE_CIRCUIT * STEP_DEGREE / 360.0)    /* １ステップで進む距離(mm)≒0.377mm */

/* PID制御 */
#define PID_KP                0.3                 /* 比例項パラメータ(要調整) */
#define PID_KI                0.3                 /* 積分項パラメータ(要調整) */
#define PID_KD                0.003               /* 微分項パラメータ(要調整) */

#define CTRL_WALL_THRESHOLD_R	60			/* 中央に置いた時の右センサリファレンス */
#define CTRL_WALL_THRESHOLD_L	60			/* 中央に置いた時の左センサリファレンス */


/* ============================================================ */
/* 型定義                                                       */
/* ============================================================ */
typedef enum {
  false = 0,
  true  = 1,
  ready = 2
} t_bool;


/* ============================================================ */
/* 関数プロトタイプ宣言(extern)                                 */
/* ============================================================ */
extern VD vd_g_InitializeController(VD);             /* 初期化関数 */
extern VD vd_ControllerMainTask(VD);                 /* 定期メインタスク */
extern VD vd_g_IntDmtrR(VD);                         /* MTU3割り込み    */
extern VD vd_g_IntDmtrL(VD);                         /* MTU4割り込み */
extern VD vd_s_IntDrvControll(VD);                   /* 1ms割り込みタスク */
/* 仮 */
extern U1 u1_jdgStepChange(VD);
extern VD vd_set_NextActFW(U1 u1_a_next_block);
extern VD vd_set_NextActTurnRight(VD);
extern VD vd_set_NextActTurnLeft(VD);
extern VD vd_set_NextActTurnBack(VD);
extern VD vd_set_NextActStop(VD);

t_bool* Fn_CONTROL_outputStatus(t_local_dir*);


/* ============================================================ */
/* 変数宣言(extern)                                             */
/* ============================================================ */


/* ============================================================ */
/* const変数宣言(extern)                                        */
/* ============================================================ */


/* ============================================================ */
/* 関数形式マクロ定義                                           */
/* ============================================================ */
/* ============================================================ */
/* 関数名 : McU1_XxYyy_getSignal                                */
/*          関数和名をここへ記述                                */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 関数箱型コメントの形式を示す                        */
/* 制約   : なし                                                */
/* ============================================================ */


#endif
