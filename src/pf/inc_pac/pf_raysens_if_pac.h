#if !defined(INCLUDED_pf_raysens_if_pac_h)
#define INCLUDED_pf_raysens_if_pac_h
/* ============================================================ */
/* ファイル名 : pf_raysens_if_pac.h                             */
/* 機能       : 光学センサI/F処理                               */
/* ============================================================ */

/* ============================================================ */
/* インクルード                                                 */
/* ============================================================ */
/* プロジェクト共通 */
#include "prj_cmn_option.h"
#include "prj_cmn_type.h"
#include "prj_cmn_macro.h"

/* カテゴリ共通 */
#include "pf_cmn_option.h"
#include "pf_cmn_option_pac.h"

/* 個別 */

/* 本体 */


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */
#define  CU1_SenNum  4  /* センサ数 */
#define  CU1_Fc_A  0.8  /* RCフィルタ 設定係数 */


/* ============================================================ */
/* 型定義                                                       */
/* ============================================================ */
/* センサデータ */
typedef struct {
  U2  u2_sen_pval;           /* センサ前回値 */
  U2  u2_sen_val;            /* センサ値 */
  U2  u2_sen_fcval;          /* FCセンサ値 */
  BL  bl_sen_data_valid;     /* センサデータ有効無効 無効:OFF(0) 有効:ON(1) */
} ST_SENDATA;

/* センサ情報 */
typedef struct {
  ST_SENDATA  sen_fr;        /* 前右センサ */
  ST_SENDATA  sen_fl;        /* 前左センサ */
  ST_SENDATA  sen_r;         /* 右センサ */
  ST_SENDATA  sen_l;         /* 左センサ */
} ST_SENINFO;


/* ============================================================ */
/* 関数プロトタイプ宣言(extern)                                 */
/* ============================================================ */
extern VD FnVD_PfRaySens_If_initHw(VD);
extern VD FnVD_PfRaySens_If_initPf(VD);
extern VD FnVD_PfRaySens_If_renewVal(VD);


/* ============================================================ */
/* 変数宣言(extern)                                             */
/* ============================================================ */


/* ============================================================ */
/* const変数宣言(extern)                                        */
/* ============================================================ */


/* ============================================================ */
/* 関数形式マクロ定義                                           */
/* ============================================================ */


#endif
