#if !defined(INCLUDED_hw_pph_port_pac_h)
#define INCLUDED_hw_pph_port_pac_h
/* ============================================================ */
/* ファイル名 : hw_pph_port_pac.h                               */
/* 機能       : ポート処理                                      */
/* ============================================================ */

/* ============================================================ */
/* インクルード                                                 */
/* ============================================================ */
/* プロジェクト共通 */
#include "prj_cmn_option.h"
#include "prj_cmn_type.h"
#include "prj_cmn_macro.h"

/* カテゴリ共通 */
#include "hw_cmn_option.h"
#include "hw_cmn_option_pac.h"

/* 個別 */

/* 本体 */


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */


/* ============================================================ */
/* 型定義                                                       */
/* ============================================================ */
/* ポート識別ID */
typedef enum {
/* 未実装:0xGGPP (GG:グループ, PP:ピン番号) */
  CEN_HwPph_Port_Id_P00 = 0x0000,
  CEN_HwPph_Port_Id_P01 = 0x0001,
  CEN_HwPph_Port_Id_P10 = 0x0100,
  CEN_HwPph_Port_Id_P20 = 0x0200,
  CEN_HwPph_Port_Id_PA0 = 0x0A00,
  CEN_HwPph_Port_Id_PG0 = 0x1000,
  CEN_HwPph_Port_Id_PJ5 = 0x1105
} EN_HwPph_Port_Id;

/* ポートコンフィグレーション情報 */
typedef struct {
/* 未実装 */
  EN_HwPph_Port_Id enId;  /* ポート識別ID */
  /* レジスタ設定情報 */
  union {
    struct {
      U1 b1PMR   :1;      /* ポートモードレジスタ設定値 */
      U1 b1PDR   :1;      /* ポート方向レジスタ設定値   */
      U1 b6Dmy   :6;      /* 未実装 */
    } stReg;              /* 主メンバー */
    U1 u1Val;             /* 副メンバー */
  } stCfg;
} ST_HwPph_Port_Cfg;


/* ============================================================ */
/* 関数プロトタイプ宣言(extern)                                 */
/* ============================================================ */
extern VD FnVD_HwPph_Port_initForStartup(VD);
extern VD FnVD_HwPph_Port_initToKill(VD);
extern VD FnVD_HwPph_Port_cfg(const ST_HwPph_Port_Cfg * tpstCfg);
extern U1 FnU1_HwPph_Port_getInLv(EN_HwPph_Port_Id tenId);
extern VD FnVD_HwPph_Port_setOutLv(EN_HwPph_Port_Id tenId, U1 tu1OutLv);


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
