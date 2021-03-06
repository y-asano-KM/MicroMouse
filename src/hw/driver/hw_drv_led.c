/* ============================================================ */
/* ファイル名 : hw_drv_led.c                                    */
/* 機能       : LED制御処理                                     */
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
#include "hw_srv_interrupt.h"
#include "hw_pph_port_pac.h"
#include "hw_pph_port_cfg_pac.h"

/* 本体 */
#include "hw_drv_led.h"
#include "hw_drv_led_pac.h"


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */
/* コンフィグレーション */
#define CST_HwDrv_Led_Port_CfgLed0 CST_HwPph_Port_CfgPB0
#define CST_HwDrv_Led_Port_CfgLed1 CST_HwPph_Port_CfgPA6
#define CST_HwDrv_Led_Port_CfgLed2 CST_HwPph_Port_CfgPA4
#define CST_HwDrv_Led_Port_CfgLed3 CST_HwPph_Port_CfgPA0

/* ポート識番号 */
#define CEN_HwDrv_Led_Port_IdLed0  CEN_HwPph_Port_Id_PB0
#define CEN_HwDrv_Led_Port_IdLed1  CEN_HwPph_Port_Id_PA6
#define CEN_HwDrv_Led_Port_IdLed2  CEN_HwPph_Port_Id_PA4
#define CEN_HwDrv_Led_Port_IdLed3  CEN_HwPph_Port_Id_PA0


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
/* 関数名 : FnVD_HwDrv_Led_init                                 */
/*          LED初期化                                           */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 初期化する                                          */
/* 制約   : 割り込み禁止中に実行すること                        */
/* ============================================================ */
VD FnVD_HwDrv_Led_init(VD)
{
  /* LED0:確認用LED0 */
  FnVD_HwPph_Port_cfg(&CST_HwDrv_Led_Port_CfgLed0);

  /* LED1:確認用LED1 */
  FnVD_HwPph_Port_cfg(&CST_HwDrv_Led_Port_CfgLed1);

  /* LED2:確認用LED2 */
  FnVD_HwPph_Port_cfg(&CST_HwDrv_Led_Port_CfgLed2);

  /* LED3:確認用LED3*/
  FnVD_HwPph_Port_cfg(&CST_HwDrv_Led_Port_CfgLed3);
}


/* ============================================================ */
/* 関数名 : FnVD_HwDrv_Led_setReqLed                            */
/*          LED消灯/点灯要求設定                                */
/* 引数   : tu1ReqLedi  (0:消灯, 1:点灯, i=0-3)                 */
/* 戻り値 : なし                                                */
/* 概要   : LEDを点灯/消灯させる                                */
/* 制約   : 割り込み禁止が解除される                            */
/* ============================================================ */
VD FnVD_HwDrv_Led_setReqLed(U1 tu1ReqLed0, U1 tu1ReqLed1, U1 tu1ReqLed2, U1 tu1ReqLed3)
{
  DI();
  FnVD_HwPph_Port_setOutLv(CEN_HwDrv_Led_Port_IdLed0, tu1ReqLed0);
  FnVD_HwPph_Port_setOutLv(CEN_HwDrv_Led_Port_IdLed1, tu1ReqLed1);
  FnVD_HwPph_Port_setOutLv(CEN_HwDrv_Led_Port_IdLed2, tu1ReqLed2);
  FnVD_HwPph_Port_setOutLv(CEN_HwDrv_Led_Port_IdLed3, tu1ReqLed3);
  EI();
}


/* ============================================================ */
/* 関数名 : FnVD_HwDrv_Led_setReqLed0                           */
/*          LED0消灯/点灯要求設定                               */
/* 引数   : tu1Req  (0:消灯, 1:点灯)                            */
/* 戻り値 : なし                                                */
/* 概要   : LEDを点灯/消灯させる                                */
/* 制約   : 割り込み禁止が解除される                            */
/* ============================================================ */
VD FnVD_HwDrv_Led_setReqLed0(U1 tu1Req)
{
  DI();
  FnVD_HwPph_Port_setOutLv(CEN_HwDrv_Led_Port_IdLed0, tu1Req);
  EI();
}


/* ============================================================ */
/* 関数名 : FnVD_HwDrv_Led_setReqLed1                           */
/*          LED1消灯/点灯要求設定                               */
/* 引数   : tu1Req  (0:消灯, 1:点灯)                            */
/* 戻り値 : なし                                                */
/* 概要   : LEDを点灯/消灯させる                                */
/* 制約   : 割り込み禁止が解除される                            */
/* ============================================================ */
VD FnVD_HwDrv_Led_setReqLed1(U1 tu1Req)
{
  DI();
  FnVD_HwPph_Port_setOutLv(CEN_HwDrv_Led_Port_IdLed1, tu1Req);
  EI();
}


/* ============================================================ */
/* 関数名 : FnVD_HwDrv_Led_setReqLed2                           */
/*          LED2消灯/点灯要求設定                               */
/* 引数   : tu1Req  (0:消灯, 1:点灯)                            */
/* 戻り値 : なし                                                */
/* 概要   : LEDを点灯/消灯させる                                */
/* 制約   : 割り込み禁止が解除される                            */
/* ============================================================ */
VD FnVD_HwDrv_Led_setReqLed2(U1 tu1Req)
{
  DI();
  FnVD_HwPph_Port_setOutLv(CEN_HwDrv_Led_Port_IdLed2, tu1Req);
  EI();
}


/* ============================================================ */
/* 関数名 : FnVD_HwDrv_Led_setReqLed3                           */
/*          LED3消灯/点灯要求設定                               */
/* 引数   : tu1Req  (0:消灯, 1:点灯)                            */
/* 戻り値 : なし                                                */
/* 概要   : LEDを点灯/消灯させる                                */
/* 制約   : 割り込み禁止が解除される                            */
/* ============================================================ */
VD FnVD_HwDrv_Led_setReqLed3(U1 tu1Req)
{
  DI();
  FnVD_HwPph_Port_setOutLv(CEN_HwDrv_Led_Port_IdLed3, tu1Req);
  EI();
}

