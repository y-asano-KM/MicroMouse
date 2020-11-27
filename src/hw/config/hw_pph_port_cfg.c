/* ============================================================ */
/* ファイル名 : hw_pph_port_cfg.c                               */
/* 機能       : ポート処理用ユーザ設定                          */
/* ============================================================ */
#define SECTION_HW

/* ============================================================ */
/* インクルード                                                 */
/* ============================================================ */
/* プロジェクト共通 */
#include "prj_cmn_section.h"
#include "prj_cmn_option.h"
#include "prj_cmn_type.h"
#include "prj_cmn_macro.h"

/* カテゴリ共通 */
#include "hw_cmn_option.h"
#include "hw_cmn_option_pac.h"

/* 個別 */
#include "prj_sche_main.h"

/* 本体 */
#include "hw_pph_port_pac.h"
#include "hw_pph_port_cfg_pac.h"


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


/* ============================================================ */
/* 変数定義(static)                                             */
/* ============================================================ */


/* ============================================================ */
/* const変数定義(extern)                                        */
/* ============================================================ */
const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgP05 = {
  CEN_HwPph_Port_Id_P05,
/* SLED_R:センサLED右側ポート設定(汎用出力ポート) */
/* b1PDR, b1PODR, b1Dmy0, b1PMR, b1ODR0, b1ODR1, b1PCR, b1DSCR  */
  {(U1)1, (U1)0,  (U1)0,  (U1)0, (U1)0,  (U1)0,  (U1)0, (U1)0},
/* b5PSEL, b1Dmy0, b1ISEL, b1ASEL */
  {(U1)0,  (U1)0,  (U1)0,  (U1)0}
};

const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgP15 = {
  CEN_HwPph_Port_Id_P15,
/* motor_EN:モータON/OFF切り替え(汎用出力ポート) */
/* b1PDR, b1PODR, b1Dmy0, b1PMR, b1ODR0, b1ODR1, b1PCR, b1DSCR  */
  {(U1)1, (U1)0,  (U1)0,  (U1)0, (U1)0,  (U1)0,  (U1)0, (U1)0},
/* b5PSEL, b1Dmy0, b1ISEL, b1ASEL */
  {(U1)0,  (U1)0,  (U1)0,  (U1)0}
};

const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgP17 = {
  CEN_HwPph_Port_Id_P17,
/* motor_R_PWM:右モータPWM(周辺機能出力ポートMTIOC3A) */
/* b1PDR, b1PODR, b1Dmy0, b1PMR, b1ODR0, b1ODR1, b1PCR, b1DSCR  */
  {(U1)1, (U1)0,  (U1)0,  (U1)1, (U1)0,  (U1)0,  (U1)0, (U1)0},
/* b5PSEL, b1Dmy0, b1ISEL, b1ASEL */
  {(U1)1,  (U1)0,  (U1)0,  (U1)0}
};

const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgP26 = {
  CEN_HwPph_Port_Id_P26,
/* TXD1:シリアル通信(送信)(周辺機能出力ポートTXD1) */
/* b1PDR, b1PODR, b1Dmy0, b1PMR, b1ODR0, b1ODR1, b1PCR, b1DSCR  */
  {(U1)1, (U1)1,  (U1)0,  (U1)1, (U1)0,  (U1)0,  (U1)0, (U1)0},
/* b5PSEL, b1Dmy0, b1ISEL, b1ASEL */
  {(U1)10, (U1)0,  (U1)0,  (U1)0}
};

const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgP27 = {
  CEN_HwPph_Port_Id_P27,
/* SLED_FL:センサLED左前(汎用出力ポート) */
/* b1PDR, b1PODR, b1Dmy0, b1PMR, b1ODR0, b1ODR1, b1PCR, b1DSCR  */
  {(U1)1, (U1)0,  (U1)0,  (U1)0, (U1)0,  (U1)0,  (U1)0, (U1)0},
/* b5PSEL, b1Dmy0, b1ISEL, b1ASEL */
  {(U1)0,  (U1)0,  (U1)0,  (U1)0}
};

const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgP30 = {
  CEN_HwPph_Port_Id_P30,
/* RXD1:シリアル通信(受信)(周辺機能入力ポートRXD1) */
/* b1PDR, b1PODR, b1Dmy0, b1PMR, b1ODR0, b1ODR1, b1PCR, b1DSCR  */
  {(U1)0, (U1)0,  (U1)0,  (U1)1, (U1)0,  (U1)0,  (U1)0, (U1)0},
/* b5PSEL, b1Dmy0, b1ISEL, b1ASEL */
  {(U1)10, (U1)0,  (U1)0,  (U1)0}
};

const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgP31 = {
  CEN_HwPph_Port_Id_P31,
/* SW_L:タクトスイッチL(汎用入力ポート) */
/* b1PDR, b1PODR, b1Dmy0, b1PMR, b1ODR0, b1ODR1, b1PCR, b1DSCR  */
  {(U1)0, (U1)0,  (U1)0,  (U1)0, (U1)0,  (U1)0,  (U1)0, (U1)0},
/* b5PSEL, b1Dmy0, b1ISEL, b1ASEL */
  {(U1)0,  (U1)0,  (U1)0,  (U1)0}
};

const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgP42 = {
  CEN_HwPph_Port_Id_P42,
/* AN4:左センサ(アナログ入力) */
/* b1PDR, b1PODR, b1Dmy0, b1PMR, b1ODR0, b1ODR1, b1PCR, b1DSCR  */
  {(U1)0, (U1)0,  (U1)0,  (U1)1, (U1)0,  (U1)0,  (U1)0, (U1)0},
/* b5PSEL, b1Dmy0, b1ISEL, b1ASEL */
  {(U1)0,  (U1)0,  (U1)0,  (U1)1}
};

const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgP44 = {
  CEN_HwPph_Port_Id_P44,
/* AN2:左前センサ(アナログ入力) */
/* b1PDR, b1PODR, b1Dmy0, b1PMR, b1ODR0, b1ODR1, b1PCR, b1DSCR  */
  {(U1)0, (U1)0,  (U1)0,  (U1)1, (U1)0,  (U1)0,  (U1)0, (U1)0},
/* b5PSEL, b1Dmy0, b1ISEL, b1ASEL */
  {(U1)0,  (U1)0,  (U1)0,  (U1)1}
};

const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgP46 = {
  CEN_HwPph_Port_Id_P46,
/* AN3:右センサ(アナログ入力) */
/* b1PDR, b1PODR, b1Dmy0, b1PMR, b1ODR0, b1ODR1, b1PCR, b1DSCR  */
  {(U1)0, (U1)0,  (U1)0,  (U1)1, (U1)0,  (U1)0,  (U1)0, (U1)0},
/* b5PSEL, b1Dmy0, b1ISEL, b1ASEL */
  {(U1)0,  (U1)0,  (U1)0,  (U1)1}
};


const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgP54 = {
  CEN_HwPph_Port_Id_P54,
/* SLED_L:センサLED左(汎用出力ポート) */
/* b1PDR, b1PODR, b1Dmy0, b1PMR, b1ODR0, b1ODR1, b1PCR, b1DSCR  */
  {(U1)1, (U1)0,  (U1)0,  (U1)0, (U1)0,  (U1)0,  (U1)0, (U1)0},
/* b5PSEL, b1Dmy0, b1ISEL, b1ASEL */
  {(U1)0,  (U1)0,  (U1)0,  (U1)0}
};

const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgPA0 = {
  CEN_HwPph_Port_Id_PA0,
/* LED3:確認用LED3(汎用出力ポート) */
/* b1PDR, b1PODR, b1Dmy0, b1PMR, b1ODR0, b1ODR1, b1PCR, b1DSCR  */
  {(U1)1, (U1)0,  (U1)0,  (U1)0, (U1)0,  (U1)0,  (U1)0, (U1)0},
/* b5PSEL, b1Dmy0, b1ISEL, b1ASEL */
  {(U1)0,  (U1)0,  (U1)0,  (U1)0}
};

const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgPA3 = {
  CEN_HwPph_Port_Id_PA3,
/* BLED1:バッテリ監視用LED1(汎用出力ポート) */
/* b1PDR, b1PODR, b1Dmy0, b1PMR, b1ODR0, b1ODR1, b1PCR, b1DSCR  */
  {(U1)1, (U1)0,  (U1)0,  (U1)0, (U1)0,  (U1)0,  (U1)0, (U1)0},
/* b5PSEL, b1Dmy0, b1ISEL, b1ASEL */
  {(U1)0,  (U1)0,  (U1)0,  (U1)0}
};

const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgPA4 = {
  CEN_HwPph_Port_Id_PA4,
/* LED2:確認用LED2(汎用出力ポート) */
/* b1PDR, b1PODR, b1Dmy0, b1PMR, b1ODR0, b1ODR1, b1PCR, b1DSCR  */
  {(U1)1, (U1)0,  (U1)0,  (U1)0, (U1)0,  (U1)0,  (U1)0, (U1)0},
/* b5PSEL, b1Dmy0, b1ISEL, b1ASEL */
  {(U1)0,  (U1)0,  (U1)0,  (U1)0}
};

const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgPA6 = {
  CEN_HwPph_Port_Id_PA6,
/* LED1:確認用LED1(汎用出力ポート) */
/* b1PDR, b1PODR, b1Dmy0, b1PMR, b1ODR0, b1ODR1, b1PCR, b1DSCR  */
  {(U1)1, (U1)0,  (U1)0,  (U1)0, (U1)0,  (U1)0,  (U1)0, (U1)0},
/* b5PSEL, b1Dmy0, b1ISEL, b1ASEL */
  {(U1)0,  (U1)0,  (U1)0,  (U1)0}
};

const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgPB0 = {
  CEN_HwPph_Port_Id_PB0,
/* LED0:確認用LED0(汎用出力ポート) */
/* b1PDR, b1PODR, b1Dmy0, b1PMR, b1ODR0, b1ODR1, b1PCR, b1DSCR  */
  {(U1)1, (U1)0,  (U1)0,  (U1)0, (U1)0,  (U1)0,  (U1)0, (U1)0},
/* b5PSEL, b1Dmy0, b1ISEL, b1ASEL */
  {(U1)0,  (U1)0,  (U1)0,  (U1)0}
};

const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgPB1 = {
  CEN_HwPph_Port_Id_PB1,
/* BLED0:バッテリ監視用LED0(汎用出力ポート) */
/* b1PDR, b1PODR, b1Dmy0, b1PMR, b1ODR0, b1ODR1, b1PCR, b1DSCR  */
  {(U1)1, (U1)0,  (U1)0,  (U1)0, (U1)0,  (U1)0,  (U1)0, (U1)0},
/* b5PSEL, b1Dmy0, b1ISEL, b1ASEL */
  {(U1)0,  (U1)0,  (U1)0,  (U1)0}
};

const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgPB3 = {
  CEN_HwPph_Port_Id_PB3,
/* Buzzer:ブザー(周辺機能出力ポートMTIOC0A) */
/* b1PDR, b1PODR, b1Dmy0, b1PMR, b1ODR0, b1ODR1, b1PCR, b1DSCR  */
  {(U1)1, (U1)1,  (U1)0,  (U1)1, (U1)0,  (U1)0,  (U1)0, (U1)0},
/* b5PSEL, b1Dmy0, b1ISEL, b1ASEL */
  {(U1)1,  (U1)0,  (U1)0,  (U1)0}
};

const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgPB5 = {
  CEN_HwPph_Port_Id_PB5,
/* SLED_FR:センサLED右前(汎用出力ポート) */
/* b1PDR, b1PODR, b1Dmy0, b1PMR, b1ODR0, b1ODR1, b1PCR, b1DSCR  */
  {(U1)1, (U1)0,  (U1)0,  (U1)0, (U1)0,  (U1)0,  (U1)0, (U1)0},
/* b5PSEL, b1Dmy0, b1ISEL, b1ASEL */
  {(U1)0,  (U1)0,  (U1)0,  (U1)0}
};

const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgPC2 = {
  CEN_HwPph_Port_Id_PC2,
/* SW_R:タクトスイッチR(汎用入力ポート) */
/* b1PDR, b1PODR, b1Dmy0, b1PMR, b1ODR0, b1ODR1, b1PCR, b1DSCR  */
  {(U1)0, (U1)0,  (U1)0,  (U1)0, (U1)0,  (U1)0,  (U1)0, (U1)0},
/* b5PSEL, b1Dmy0, b1ISEL, b1ASEL */
  {(U1)0,  (U1)0,  (U1)0,  (U1)0}
};

const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgPC3 = {
  CEN_HwPph_Port_Id_PC3,
/* SW_R:タクトスイッチC(汎用入力ポート) */
/* b1PDR, b1PODR, b1Dmy0, b1PMR, b1ODR0, b1ODR1, b1PCR, b1DSCR  */
  {(U1)0, (U1)0,  (U1)0,  (U1)0, (U1)0,  (U1)0,  (U1)0, (U1)0},
/* b5PSEL, b1Dmy0, b1ISEL, b1ASEL */
  {(U1)0,  (U1)0,  (U1)0,  (U1)0}
};

const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgPC5 = {
  CEN_HwPph_Port_Id_PC5,
/* CW/CCW_R:右モータCS/CCW(汎用出力ポート) */
/* b1PDR, b1PODR, b1Dmy0, b1PMR, b1ODR0, b1ODR1, b1PCR, b1DSCR  */
  {(U1)1, (U1)0,  (U1)0,  (U1)0, (U1)0,  (U1)0,  (U1)0, (U1)0},
/* b5PSEL, b1Dmy0, b1ISEL, b1ASEL */
  {(U1)0,  (U1)0,  (U1)0,  (U1)0}
};

const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgPC6 = {
  CEN_HwPph_Port_Id_PC6,
/* CW/CCW_L:左モータCS/CCW(汎用出力ポート) */
/* b1PDR, b1PODR, b1Dmy0, b1PMR, b1ODR0, b1ODR1, b1PCR, b1DSCR  */
  {(U1)1, (U1)0,  (U1)0,  (U1)0, (U1)0,  (U1)0,  (U1)0, (U1)0},
/* b5PSEL, b1Dmy0, b1ISEL, b1ASEL */
  {(U1)0,  (U1)0,  (U1)0,  (U1)0}
};

const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgPE0 = {
  CEN_HwPph_Port_Id_PE0,
/* AN0:電圧監視(アナログ入力) */
/* b1PDR, b1PODR, b1Dmy0, b1PMR, b1ODR0, b1ODR1, b1PCR, b1DSCR  */
  {(U1)0, (U1)0,  (U1)0,  (U1)1, (U1)0,  (U1)0,  (U1)0, (U1)0},
/* b5PSEL, b1Dmy0, b1ISEL, b1ASEL */
  {(U1)0,  (U1)0,  (U1)0,  (U1)1}
};

const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgPE1 = {
  CEN_HwPph_Port_Id_PE1,
/* AN1:右前センサ(アナログ入力) */
/* b1PDR, b1PODR, b1Dmy0, b1PMR, b1ODR0, b1ODR1, b1PCR, b1DSCR  */
  {(U1)0, (U1)0,  (U1)0,  (U1)1, (U1)0,  (U1)0,  (U1)0, (U1)0},
/* b5PSEL, b1Dmy0, b1ISEL, b1ASEL */
  {(U1)0,  (U1)0,  (U1)0,  (U1)1}
};

const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgPE2 = {
  CEN_HwPph_Port_Id_PE2,
/* AN1:左モータPWM(周辺機能出力ポートMTIOC4A) */
/* b1PDR, b1PODR, b1Dmy0, b1PMR, b1ODR0, b1ODR1, b1PCR, b1DSCR  */
  {(U1)1, (U1)0,  (U1)0,  (U1)1, (U1)0,  (U1)0,  (U1)0, (U1)0},
/* b5PSEL, b1Dmy0, b1ISEL, b1ASEL */
  {(U1)1,  (U1)0,  (U1)0,  (U1)0}
};


/* ============================================================ */
/* const変数定義(static)                                        */
/* ============================================================ */


/* ============================================================ */
/* 関数形式マクロ定義                                           */
/* ============================================================ */


/* ============================================================ */
/* 関数定義                                                     */
/* ============================================================ */
