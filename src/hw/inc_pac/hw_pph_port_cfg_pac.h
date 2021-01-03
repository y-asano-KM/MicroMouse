#if !defined(INCLUDED_hw_pph_port_cfg_pac_h)
#define INCLUDED_hw_pph_port_cfg_pac_h
/* ============================================================ */
/* ファイル名 : hw_pph_port_cfg_pac.h                           */
/* 機能       : ポート処理用ユーザ設定                          */
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
#include "hw_pph_port_pac.h"


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */


/* ============================================================ */
/* 型定義                                                       */
/* ============================================================ */


/* ============================================================ */
/* 関数プロトタイプ宣言(extern)                                 */
/* ============================================================ */


/* ============================================================ */
/* 変数宣言(extern)                                             */
/* ============================================================ */


/* ============================================================ */
/* const変数宣言(extern)                                        */
/* ============================================================ */
extern const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgP05;  /* SLED_R(センサLED右側)          */
extern const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgP15;  /* motor_EN(モータON/OFF切り替え) */
extern const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgP17;  /* motor_R_PWM(右モータPWM)       */
extern const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgP26;  /* TXD1(シリアル通信(送信))       */
extern const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgP27;  /* SLED_FL(センサLED左前)         */
extern const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgP30;  /* RXD1(シリアル通信(受信))       */
extern const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgP31;  /* SW_L(タクトスイッチL)          */
extern const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgP42;  /* AN4(左センサ)                  */
extern const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgP44;  /* AN2(左前センサ)                */
extern const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgP46;  /* AN3(右センサ)                  */
extern const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgP54;  /* SLED_L(センサLED左)            */
extern const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgPA0;  /* LED3(確認用LED3)               */
extern const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgPA3;  /* BLED1(バッテリ監視用LED1)      */
extern const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgPA4;  /* LED2(確認用LED2)               */
extern const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgPA6;  /* LED1(確認用LED1)               */
extern const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgPB0;  /* LED0(確認用LED0)               */
extern const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgPB1;  /* BLED0(バッテリ監視用LED0)      */
extern const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgPB3;  /* Buzzer(ブザー)                 */
extern const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgPB5;  /* SLED_FR(センサLED右前)         */
extern const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgPC2;  /* SW_R(タクトスイッチR)          */
extern const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgPC3;  /* SW_C(タクトスイッチC)          */
extern const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgPC5;  /* CW/CCW_R(右モータCS/CCW)       */
extern const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgPC6;  /* CW/CCW_L(左モータCS/CCW)       */
extern const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgPE0;  /* AN0(電圧監視)                  */
extern const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgPE1;  /* AN1(右前センサ)                */
extern const ST_HwPph_Port_Cfg CST_HwPph_Port_CfgPE2;  /* motor_L_PWM(左モータPWM)       */


/* ============================================================ */
/* 関数形式マクロ定義                                           */
/* ============================================================ */


#endif
