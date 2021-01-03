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
/* ToDo:暫定で必要最小限だけ定義 */
/* 0xGGPP (GG:グループ, PP:ピン番号) */ /* Note:PJのグループ番号は18  */
  CEN_HwPph_Port_Id_P05 = 0x0005U,
  CEN_HwPph_Port_Id_P15 = 0x0105U,
  CEN_HwPph_Port_Id_P17 = 0x0107U,
  CEN_HwPph_Port_Id_P26 = 0x0206U,
  CEN_HwPph_Port_Id_P27 = 0x0207U,
  CEN_HwPph_Port_Id_P30 = 0x0300U,
  CEN_HwPph_Port_Id_P31 = 0x0301U,
  CEN_HwPph_Port_Id_P42 = 0x0402U,
  CEN_HwPph_Port_Id_P44 = 0x0404U,
  CEN_HwPph_Port_Id_P46 = 0x0406U,
  CEN_HwPph_Port_Id_P54 = 0x0504U,
  CEN_HwPph_Port_Id_PA0 = 0x0A00U,
  CEN_HwPph_Port_Id_PA3 = 0x0A03U,
  CEN_HwPph_Port_Id_PA4 = 0x0A04U,
  CEN_HwPph_Port_Id_PA6 = 0x0A06U,
  CEN_HwPph_Port_Id_PB0 = 0x0B00U,
  CEN_HwPph_Port_Id_PB1 = 0x0B01U,
  CEN_HwPph_Port_Id_PB3 = 0x0B03U,
  CEN_HwPph_Port_Id_PB5 = 0x0B05U,
  CEN_HwPph_Port_Id_PC2 = 0x0C02U,
  CEN_HwPph_Port_Id_PC3 = 0x0C03U,
  CEN_HwPph_Port_Id_PC5 = 0x0C05U,
  CEN_HwPph_Port_Id_PC6 = 0x0C06U,
  CEN_HwPph_Port_Id_PE0 = 0x0E00U,
  CEN_HwPph_Port_Id_PE1 = 0x0E01U,
  CEN_HwPph_Port_Id_PE2 = 0x0E02U
} EN_HwPph_Port_Id;

/* ポートコンフィグレーション情報 */
typedef struct {
/* ToDo:未実装 */
  EN_HwPph_Port_Id enId;  /* ポート識別ID */
  /* レジスタ設定情報 */
  union {
    struct {
      U1 b1PDR   :1;      /* ポート方向レジスタ設定値 */
      U1 b1PODR  :1;      /* ポート出力データレジスタ設定値 */
      U1 b1Dmy0  :1;      /* 予約 */
      U1 b1PMR   :1;      /* ポートモードレジスタ設定値 */
      U1 b1ODR0  :1;      /* オープンドレイン制御レジスタ0設定値 */ /* ToDo:未検討 */
      U1 b1ODR1  :1;      /* オープンドレイン制御レジスタ1設定値 */ /* ToDo:未検討 */
      U1 b1PCR   :1;      /* プルアップ制御レジスタ設定値 */ /* ToDo:未検討 */
      U1 b1DSCR  :1;      /* 駆動能力制御レジスタ設定値 */ /* ToDo:未検討 */
    } stReg;              /* 主メンバー */
    U1 u1Val;             /* 副メンバー */
  } stPortCfg;
  union {
    struct {
      U1 b5PSEL  :5;      /* 周辺機能選択 */
      U1 b1Dmy0  :1;      /* 予約 */
      U1 b1ISEL  :1;      /* 割り込み入力機能選択 */ /* ToDo:未検討 */
      U1 b1ASEL  :1;      /* アナログ入力機能選択 */
    } stReg;              /* 主メンバー */
    U1 u1Val;             /* 副メンバー */
  } stMpcCfg;
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
