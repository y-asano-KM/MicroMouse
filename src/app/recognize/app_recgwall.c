/* ============================================================ */
/* ファイル名 : app_recgwall.c                            　　　*/
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


/* ============================================================ */
/* 型定義                                                       */
/* ============================================================ */


/* ============================================================ */
/* 関数プロトタイプ宣言(static)                                 */
/* ============================================================ */
static VD FnVD_Recg_ReadSensor(VD);
static VD FnVD_Recg_RecognizeWall_1ms(VD);
static VD FnVD_Recg_RecognizeWall_5ms(VD);


/* ============================================================ */
/* 変数定義(extern)                                             */
/* ============================================================ */
ST_WALLINFO st_RecgWall_info;      /* 壁情報(Map) */
ST_WALLINFO st_RecgWall_info_attc; /* 壁情報(姿勢制御) */


/* ============================================================ */
/* 変数定義(static)                                             */
/* ============================================================ */
static U2 u2RecgSensVal_R;
static U2 u2RecgSensVal_FR;
static U2 u2RecgSensVal_FL;
static U2 u2RecgSensVal_L;


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
/* 関数名 : FnVD_Recg_WallRecognize                             */
/*          壁認識処理関数(5ms)                                 */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 壁認識処理をする                                    */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_Recg_WallRecognize(VD)
{
 
  /* センサ値読み込み */
  FnVD_Recg_ReadSensor();
 
  /* 壁検知 */
  FnVD_Recg_RecognizeWall_5ms();
  
}


/* ============================================================ */
/* 関数名 : FnVD_Recg_WallRecognize_1ms                         */
/*          壁認識処理関数(1ms)                                 */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 壁認識処理をする                                    */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_Recg_WallRecognize_1ms(VD)
{
 
  /* センサ値読み込み */
  FnVD_Recg_ReadSensor();
 
  /* 壁検知 */
  FnVD_Recg_RecognizeWall_1ms();
  
}


/* ============================================================ */
/* 関数名 : FnVD_Recg_RecognizeInit                             */
/*          認識処理初期化関数                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 初期化                                              */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_Recg_RecognizeInit(VD)
{

  /* 壁情報(Map) */
  /* 壁有無 */
  st_RecgWall_info.wall_f.bl_wall_with = (BL)C_OFF;
  st_RecgWall_info.wall_r.bl_wall_with = (BL)C_OFF;
  st_RecgWall_info.wall_l.bl_wall_with = (BL)C_OFF;

  /* 壁データ有効無効 */
  st_RecgWall_info.wall_f.bl_wall_data_valid = (BL)C_OFF;
  st_RecgWall_info.wall_r.bl_wall_data_valid = (BL)C_OFF;
  st_RecgWall_info.wall_l.bl_wall_data_valid = (BL)C_OFF;
  
  /* センサ値 */
  st_RecgWall_info.wall_f.u2_sens_val = (U2)0;
  st_RecgWall_info.wall_r.u2_sens_val = (U2)0;
  st_RecgWall_info.wall_l.u2_sens_val = (U2)0;

  /* 壁情報(姿勢制御) */
  /* 壁有無 */
  st_RecgWall_info_attc.wall_f.bl_wall_with = (BL)C_OFF;
  st_RecgWall_info_attc.wall_r.bl_wall_with = (BL)C_OFF;
  st_RecgWall_info_attc.wall_l.bl_wall_with = (BL)C_OFF;

  /* 壁データ有効無効 */
  st_RecgWall_info_attc.wall_f.bl_wall_data_valid = (BL)C_OFF;
  st_RecgWall_info_attc.wall_r.bl_wall_data_valid = (BL)C_OFF;
  st_RecgWall_info_attc.wall_l.bl_wall_data_valid = (BL)C_OFF;
  
  /* センサ値 */
  st_RecgWall_info_attc.wall_f.u2_sens_val = (U2)0;
  st_RecgWall_info_attc.wall_r.u2_sens_val = (U2)0;
  st_RecgWall_info_attc.wall_l.u2_sens_val = (U2)0;

}

/* ============================================================ */
/* 関数名 : FnVD_Recg_ReadSensor                                */
/*          センサ読み込み関数                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : FCセンサ値を読み込む                                */
/* 制約   : なし                                                */
/* ============================================================ */
static VD FnVD_Recg_ReadSensor(VD)
{
  /* センサ右側 */
  u2RecgSensVal_R = FnU2_PfRaySens_If_getValRight();

  /* センサ前方左側 */
  u2RecgSensVal_FL = FnU2_PfRaySens_If_getValFrontLeft();

  /* センサ前方右側 */
  u2RecgSensVal_FR = FnU2_PfRaySens_If_getValFrontRight();

  /* センサ左側 */
  u2RecgSensVal_L = FnU2_PfRaySens_If_getValLeft();

}

/* ============================================================ */
/* 関数名 : FnVD_Recg_RecognizeWall_1ms                         */
/*          壁検知関数(1ms)                                     */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 壁の有無を判断する                                  */
/* 制約   : なし                                                */
/* ============================================================ */
static VD FnVD_Recg_RecognizeWall_1ms(VD)
{

  /* 右壁チェック */
  if (u2RecgSensVal_R > CU1_WALL_R_SEN_TH) {
    st_RecgWall_info_attc.wall_r.bl_wall_with = (BL)C_ON;         /* 右壁あり */
  }
  else {
    st_RecgWall_info_attc.wall_r.bl_wall_with = (BL)C_OFF;        /* 右壁なし */
  }
  /* センサ値を格納 */
  st_RecgWall_info_attc.wall_r.u2_sens_val = (U2)u2RecgSensVal_R;
  st_RecgWall_info_attc.wall_r.bl_wall_data_valid = (BL)C_ON;

  /* 前壁チェック */
  /* 判定不要 */

  /* 左壁チェック */
  if (u2RecgSensVal_L > CU1_WALL_L_SEN_TH) {
    st_RecgWall_info_attc.wall_l.bl_wall_with = (BL)C_ON;         /* 左壁あり */
  }
  else {
    st_RecgWall_info_attc.wall_l.bl_wall_with = (BL)C_OFF;        /* 左壁なし */
  }
  /* センサ値を格納 */
  st_RecgWall_info_attc.wall_l.u2_sens_val = (U2)u2RecgSensVal_L;
  st_RecgWall_info_attc.wall_l.bl_wall_data_valid = (BL)C_ON;
  
}

/* ============================================================ */
/* 関数名 : FnVD_Recg_RecognizeWall_5ms                         */
/*          壁検知関数(5ms)                                     */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 壁の有無を判断する                                  */
/* 制約   : なし                                                */
/* ============================================================ */
static VD FnVD_Recg_RecognizeWall_5ms(VD)
{
  U2 tu2_f_ave;

  /* 右壁チェック */
  if (u2RecgSensVal_R > CU1_WALL_R_SEN_TH) {
    st_RecgWall_info.wall_r.bl_wall_with = (BL)C_ON;         /* 右壁あり */
  }
  else {
    st_RecgWall_info.wall_r.bl_wall_with = (BL)C_OFF;        /* 右壁なし */
  }
  /* センサ値を格納 */
  st_RecgWall_info.wall_r.u2_sens_val = (U2)u2RecgSensVal_R;
  st_RecgWall_info.wall_r.bl_wall_data_valid = (BL)C_ON;

  /* 前左FCセンサ値と前右FCセンサ値の平均 */
  tu2_f_ave = 0;
  tu2_f_ave = u2RecgSensVal_FL + u2RecgSensVal_FR;
  tu2_f_ave = (tu2_f_ave + (U2)1) / (U2)2;    /* 切り上げ */
  
  /* 前壁チェック */
  if (tu2_f_ave > CU1_WALL_F_SEN_TH) {
    st_RecgWall_info.wall_f.bl_wall_with = (BL)C_ON;        /* 前壁あり */
  }
  else {
    st_RecgWall_info.wall_f.bl_wall_with = (BL)C_OFF;       /* 前壁なし */
  }
  /* センサ値を格納 */
  st_RecgWall_info.wall_f.u2_sens_val = (U2)tu2_f_ave;
  st_RecgWall_info.wall_f.bl_wall_data_valid = (BL)C_ON;

  /* 左壁チェック */
  if (u2RecgSensVal_L > CU1_WALL_L_SEN_TH) {
    st_RecgWall_info.wall_l.bl_wall_with = (BL)C_ON;         /* 左壁あり */
  }
  else {
    st_RecgWall_info.wall_l.bl_wall_with = (BL)C_OFF;        /* 左壁なし */
  }
  /* センサ値を格納 */
  st_RecgWall_info.wall_l.u2_sens_val = (U2)u2RecgSensVal_L;
  st_RecgWall_info.wall_l.bl_wall_data_valid = (BL)C_ON;
  
}
