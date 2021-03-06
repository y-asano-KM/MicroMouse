/* ============================================================ */
/* ファイル名 : hw_core_exception.c                             */
/* 機能       : 例外ハンドラ                                    */
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
#include "hw_srv_exception_pac.h"

/* 本体 */
#include "hw_core_exception_pac.h"


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


/* ============================================================ */
/* const変数定義(static)                                        */
/* ============================================================ */


/* ============================================================ */
/* 関数形式マクロ定義                                           */
/* ============================================================ */


/* ============================================================ */
/* 関数定義                                                     */
/* ============================================================ */
#pragma section
#pragma section IntPRG
/* --------------------------------------------------------- */
/* ここ以降は例外ハンドラを定義する                          */
/* 将来的にはアセンブリで記述する                            */
/* 関数定義の直前で以下のプリプロセッサを記述することにより  */
/* スタックへのレジスタ退避/復帰, 割り込み復帰処理を生成する */
/* #pragma interrupt 関数名                                  */
/* --------------------------------------------------------- */
/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleReserved                */
/*          例外ベクタ予約領域ハンドラ                          */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleReserved)
VD FnVD_HwCore_Exception_handleReserved(VD)
{
  FnVD_HwSrv_Exception_handleReserved();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleSuperVisor              */
/*          権限特権例外ハンドラ                                */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleSuperVisor)
VD FnVD_HwCore_Exception_handleSuperVisor(VD)
{
  FnVD_HwSrv_Exception_handleSuperVisor();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleAccess                  */
/*          アクセス例外ハンドラ                                */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleAccess)
VD FnVD_HwCore_Exception_handleAccess(VD)
{
  FnVD_HwSrv_Exception_handleAccess();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleUndefined               */
/*          未定義命令例外ハンドラ                              */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleUndefined)
VD FnVD_HwCore_Exception_handleUndefined(VD)
{
  FnVD_HwSrv_Exception_handleUndefined();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleFloatingPoint           */
/*          浮動小数点例外ハンドラ                              */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleFloatingPoint)
VD FnVD_HwCore_Exception_handleFloatingPoint(VD)
{
  FnVD_HwSrv_Exception_handleFloatingPoint();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleNonMaskableInterrupt    */
/*          ノンマスカブル割り込みハンドラ                      */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleNonMaskableInterrupt)
VD FnVD_HwCore_Exception_handleNonMaskableInterrupt(VD)
{
  FnVD_HwSrv_Exception_handleNonMaskableInterrupt();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleBrk                     */
/*          BRK命令例外ハンドラ                                 */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleBrk)
VD FnVD_HwCore_Exception_handleBrk(VD)
{
  FnVD_HwSrv_Exception_handleBrk();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTrap                    */
/*          無条件トラップ専用ハンドラ                          */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTrap)
VD FnVD_HwCore_Exception_handleTrap(VD)
{
  FnVD_HwSrv_Exception_handleTrap();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleBSC_BUSERR              */
/*          BSC.BUSERRハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleBSC_BUSERR)
VD FnVD_HwCore_Exception_handleBSC_BUSERR(VD)
{
  FnVD_HwSrv_Exception_handleBSC_BUSERR();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleFCU_FIFERR              */
/*          FCU.FIFERRハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleFCU_FIFERR)
VD FnVD_HwCore_Exception_handleFCU_FIFERR(VD)
{
  FnVD_HwSrv_Exception_handleFCU_FIFERR();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleFCU_FRDYI               */
/*          FCU.FRDYIハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleFCU_FRDYI)
VD FnVD_HwCore_Exception_handleFCU_FRDYI(VD)
{
  FnVD_HwSrv_Exception_handleFCU_FRDYI();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleICU_SWINT               */
/*          ICU.SWINTハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleICU_SWINT)
VD FnVD_HwCore_Exception_handleICU_SWINT(VD)
{
  FnVD_HwSrv_Exception_handleICU_SWINT();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleCMT0_CMI0               */
/*          CMT0.CMI0ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleCMT0_CMI0)
VD FnVD_HwCore_Exception_handleCMT0_CMI0(VD)
{
  FnVD_HwSrv_Exception_handleCMT0_CMI0();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleCMT1_CMI1               */
/*          CMT1.CMI1ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleCMT1_CMI1)
VD FnVD_HwCore_Exception_handleCMT1_CMI1(VD)
{
  FnVD_HwSrv_Exception_handleCMT1_CMI1();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleCMT2_CMI2               */
/*          CMT2.CMI2ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleCMT2_CMI2)
VD FnVD_HwCore_Exception_handleCMT2_CMI2(VD)
{
  FnVD_HwSrv_Exception_handleCMT2_CMI2();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleCMT3_CMI3               */
/*          CMT3.CMI3ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleCMT3_CMI3)
VD FnVD_HwCore_Exception_handleCMT3_CMI3(VD)
{
  FnVD_HwSrv_Exception_handleCMT3_CMI3();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleETHER_EINT              */
/*          ETHER.EINTハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleETHER_EINT)
VD FnVD_HwCore_Exception_handleETHER_EINT(VD)
{
  FnVD_HwSrv_Exception_handleETHER_EINT();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleUSB0_D0FIFO0            */
/*          USB0.D0FIFO0ハンドラ                                */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleUSB0_D0FIFO0)
VD FnVD_HwCore_Exception_handleUSB0_D0FIFO0(VD)
{
  FnVD_HwSrv_Exception_handleUSB0_D0FIFO0();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleUSB0_D1FIFO0            */
/*          USB0.D1FIFO0ハンドラ                                */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleUSB0_D1FIFO0)
VD FnVD_HwCore_Exception_handleUSB0_D1FIFO0(VD)
{
  FnVD_HwSrv_Exception_handleUSB0_D1FIFO0();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleUSB0_USBI0              */
/*          USB0.USBI0ハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleUSB0_USBI0)
VD FnVD_HwCore_Exception_handleUSB0_USBI0(VD)
{
  FnVD_HwSrv_Exception_handleUSB0_USBI0();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleUSB1_D0FIFO1            */
/*          USB1.D0FIFO1ハンドラ                                */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleUSB1_D0FIFO1)
VD FnVD_HwCore_Exception_handleUSB1_D0FIFO1(VD)
{
  FnVD_HwSrv_Exception_handleUSB1_D0FIFO1();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleUSB1_D1FIFO1            */
/*          USB1.D1FIFO1ハンドラ                                */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleUSB1_D1FIFO1)
VD FnVD_HwCore_Exception_handleUSB1_D1FIFO1(VD)
{
  FnVD_HwSrv_Exception_handleUSB1_D1FIFO1();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleUSB1_USBI1              */
/*          USB1.USBI1ハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleUSB1_USBI1)
VD FnVD_HwCore_Exception_handleUSB1_USBI1(VD)
{
  FnVD_HwSrv_Exception_handleUSB1_USBI1();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleRSPI0_SPRI0             */
/*          RSPI0.SPRI0ハンドラ                                 */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleRSPI0_SPRI0)
VD FnVD_HwCore_Exception_handleRSPI0_SPRI0(VD)
{
  FnVD_HwSrv_Exception_handleRSPI0_SPRI0();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleRSPI0_SPTI0             */
/*          RSPI0.SPTI0ハンドラ                                 */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleRSPI0_SPTI0)
VD FnVD_HwCore_Exception_handleRSPI0_SPTI0(VD)
{
  FnVD_HwSrv_Exception_handleRSPI0_SPTI0();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleRSPI0_SPII0             */
/*          RSPI0.SPII0ハンドラ                                 */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleRSPI0_SPII0)
VD FnVD_HwCore_Exception_handleRSPI0_SPII0(VD)
{
  FnVD_HwSrv_Exception_handleRSPI0_SPII0();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleRSPI1_SPRI1             */
/*          RSPI1.SPRI1ハンドラ                                 */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleRSPI1_SPRI1)
VD FnVD_HwCore_Exception_handleRSPI1_SPRI1(VD)
{
  FnVD_HwSrv_Exception_handleRSPI1_SPRI1();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleRSPI1_SPTI1             */
/*          RSPI1.SPTI1ハンドラ                                 */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleRSPI1_SPTI1)
VD FnVD_HwCore_Exception_handleRSPI1_SPTI1(VD)
{
  FnVD_HwSrv_Exception_handleRSPI1_SPTI1();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleRSPI1_SPII1             */
/*          RSPI1.SPII1ハンドラ                                 */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleRSPI1_SPII1)
VD FnVD_HwCore_Exception_handleRSPI1_SPII1(VD)
{
  FnVD_HwSrv_Exception_handleRSPI1_SPII1();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleRSPI2_SPRI2             */
/*          RSPI2.SPRI2ハンドラ                                 */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleRSPI2_SPRI2)
VD FnVD_HwCore_Exception_handleRSPI2_SPRI2(VD)
{
  FnVD_HwSrv_Exception_handleRSPI2_SPRI2();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleRSPI2_SPTI2             */
/*          RSPI2.SPTI2ハンドラ                                 */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleRSPI2_SPTI2)
VD FnVD_HwCore_Exception_handleRSPI2_SPTI2(VD)
{
  FnVD_HwSrv_Exception_handleRSPI2_SPTI2();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleRSPI2_SPII2             */
/*          RSPI2.SPII2ハンドラ                                 */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleRSPI2_SPII2)
VD FnVD_HwCore_Exception_handleRSPI2_SPII2(VD)
{
  FnVD_HwSrv_Exception_handleRSPI2_SPII2();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleCAN0_RXF0               */
/*          CAN0.RXF0ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleCAN0_RXF0)
VD FnVD_HwCore_Exception_handleCAN0_RXF0(VD)
{
  FnVD_HwSrv_Exception_handleCAN0_RXF0();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleCAN0_TXF0               */
/*          CAN0.TXF0ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleCAN0_TXF0)
VD FnVD_HwCore_Exception_handleCAN0_TXF0(VD)
{
  FnVD_HwSrv_Exception_handleCAN0_TXF0();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleCAN0_RXM0               */
/*          CAN0.RXM0ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleCAN0_RXM0)
VD FnVD_HwCore_Exception_handleCAN0_RXM0(VD)
{
  FnVD_HwSrv_Exception_handleCAN0_RXM0();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleCAN0_TXM0               */
/*          CAN0.TXM0ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleCAN0_TXM0)
VD FnVD_HwCore_Exception_handleCAN0_TXM0(VD)
{
  FnVD_HwSrv_Exception_handleCAN0_TXM0();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleCAN1_RXF1               */
/*          CAN1.RXF1ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleCAN1_RXF1)
VD FnVD_HwCore_Exception_handleCAN1_RXF1(VD)
{
  FnVD_HwSrv_Exception_handleCAN1_RXF1();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleCAN1_TXF1               */
/*          CAN1.TXF1ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleCAN1_TXF1)
VD FnVD_HwCore_Exception_handleCAN1_TXF1(VD)
{
  FnVD_HwSrv_Exception_handleCAN1_TXF1();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleCAN1_RXM1               */
/*          CAN1.RXM1ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleCAN1_RXM1)
VD FnVD_HwCore_Exception_handleCAN1_RXM1(VD)
{
  FnVD_HwSrv_Exception_handleCAN1_RXM1();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleCAN1_TXM1               */
/*          CAN1.TXM1ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleCAN1_TXM1)
VD FnVD_HwCore_Exception_handleCAN1_TXM1(VD)
{
  FnVD_HwSrv_Exception_handleCAN1_TXM1();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleCAN2_RXF2               */
/*          CAN2.RXF2ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleCAN2_RXF2)
VD FnVD_HwCore_Exception_handleCAN2_RXF2(VD)
{
  FnVD_HwSrv_Exception_handleCAN2_RXF2();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleCAN2_TXF2               */
/*          CAN2.TXF2ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleCAN2_TXF2)
VD FnVD_HwCore_Exception_handleCAN2_TXF2(VD)
{
  FnVD_HwSrv_Exception_handleCAN2_TXF2();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleCAN2_RXM2               */
/*          CAN2.RXM2ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleCAN2_RXM2)
VD FnVD_HwCore_Exception_handleCAN2_RXM2(VD)
{
  FnVD_HwSrv_Exception_handleCAN2_RXM2();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleCAN2_TXM2               */
/*          CAN2.TXM2ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleCAN2_TXM2)
VD FnVD_HwCore_Exception_handleCAN2_TXM2(VD)
{
  FnVD_HwSrv_Exception_handleCAN2_TXM2();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleRTC_CUP                 */
/*          RTC.CUPハンドラ                                     */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleRTC_CUP)
VD FnVD_HwCore_Exception_handleRTC_CUP(VD)
{
  FnVD_HwSrv_Exception_handleRTC_CUP();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleICU_IRQ0                */
/*          ICU.IRQ0ハンドラ                                    */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleICU_IRQ0)
VD FnVD_HwCore_Exception_handleICU_IRQ0(VD)
{
  FnVD_HwSrv_Exception_handleICU_IRQ0();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleICU_IRQ1                */
/*          ICU.IRQ1ハンドラ                                    */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleICU_IRQ1)
VD FnVD_HwCore_Exception_handleICU_IRQ1(VD)
{
  FnVD_HwSrv_Exception_handleICU_IRQ1();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleICU_IRQ2                */
/*          ICU.IRQ2ハンドラ                                    */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleICU_IRQ2)
VD FnVD_HwCore_Exception_handleICU_IRQ2(VD)
{
  FnVD_HwSrv_Exception_handleICU_IRQ2();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleICU_IRQ3                */
/*          ICU.IRQ3ハンドラ                                    */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleICU_IRQ3)
VD FnVD_HwCore_Exception_handleICU_IRQ3(VD)
{
  FnVD_HwSrv_Exception_handleICU_IRQ3();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleICU_IRQ4                */
/*          ICU.IRQ4ハンドラ                                    */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleICU_IRQ4)
VD FnVD_HwCore_Exception_handleICU_IRQ4(VD)
{
  FnVD_HwSrv_Exception_handleICU_IRQ4();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleICU_IRQ5                */
/*          ICU.IRQ5ハンドラ                                    */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleICU_IRQ5)
VD FnVD_HwCore_Exception_handleICU_IRQ5(VD)
{
  FnVD_HwSrv_Exception_handleICU_IRQ5();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleICU_IRQ6                */
/*          ICU.IRQ6ハンドラ                                    */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleICU_IRQ6)
VD FnVD_HwCore_Exception_handleICU_IRQ6(VD)
{
  FnVD_HwSrv_Exception_handleICU_IRQ6();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleICU_IRQ7                */
/*          ICU.IRQ7ハンドラ                                    */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleICU_IRQ7)
VD FnVD_HwCore_Exception_handleICU_IRQ7(VD)
{
  FnVD_HwSrv_Exception_handleICU_IRQ7();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleICU_IRQ8                */
/*          ICU.IRQ8ハンドラ                                    */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleICU_IRQ8)
VD FnVD_HwCore_Exception_handleICU_IRQ8(VD)
{
  FnVD_HwSrv_Exception_handleICU_IRQ8();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleICU_IRQ9                */
/*          ICU.IRQ9ハンドラ                                    */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleICU_IRQ9)
VD FnVD_HwCore_Exception_handleICU_IRQ9(VD)
{
  FnVD_HwSrv_Exception_handleICU_IRQ9();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleICU_IRQ10               */
/*          ICU.IRQ10ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleICU_IRQ10)
VD FnVD_HwCore_Exception_handleICU_IRQ10(VD)
{
  FnVD_HwSrv_Exception_handleICU_IRQ10();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleICU_IRQ11               */
/*          ICU.IRQ11ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleICU_IRQ11)
VD FnVD_HwCore_Exception_handleICU_IRQ11(VD)
{
  FnVD_HwSrv_Exception_handleICU_IRQ11();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleICU_IRQ12               */
/*          ICU.IRQ12ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleICU_IRQ12)
VD FnVD_HwCore_Exception_handleICU_IRQ12(VD)
{
  FnVD_HwSrv_Exception_handleICU_IRQ12();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleICU_IRQ13               */
/*          ICU.IRQ13ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleICU_IRQ13)
VD FnVD_HwCore_Exception_handleICU_IRQ13(VD)
{
  FnVD_HwSrv_Exception_handleICU_IRQ13();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleICU_IRQ14               */
/*          ICU.IRQ14ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleICU_IRQ14)
VD FnVD_HwCore_Exception_handleICU_IRQ14(VD)
{
  FnVD_HwSrv_Exception_handleICU_IRQ14();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleICU_IRQ15               */
/*          ICU.IRQ15ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleICU_IRQ15)
VD FnVD_HwCore_Exception_handleICU_IRQ15(VD)
{
  FnVD_HwSrv_Exception_handleICU_IRQ15();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleUSB_USBR0               */
/*          USB.USBR0ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleUSB_USBR0)
VD FnVD_HwCore_Exception_handleUSB_USBR0(VD)
{
 FnVD_HwSrv_Exception_handleUSB_USBR0();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleUSB_USBR1               */
/*          USB.USBR1ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleUSB_USBR1)
VD FnVD_HwCore_Exception_handleUSB_USBR1(VD)
{
 FnVD_HwSrv_Exception_handleUSB_USBR1();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleRTC_ALM                 */
/*          RTC.ALMハンドラ                                     */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleRTC_ALM)
VD FnVD_HwCore_Exception_handleRTC_ALM(VD)
{
  FnVD_HwSrv_Exception_handleRTC_ALM();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleRTC_PRD                 */
/*          RTC.PRDハンドラ                                     */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleRTC_PRD)
VD FnVD_HwCore_Exception_handleRTC_PRD(VD)
{
  FnVD_HwSrv_Exception_handleRTC_PRD();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleAD_ADI0                 */
/*          AD.ADI0ハンドラ                                     */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleAD_ADI0)
VD FnVD_HwCore_Exception_handleAD_ADI0(VD)
{
  FnVD_HwSrv_Exception_handleAD_ADI0();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleS12AD_S12ADI0           */
/*          S12AD.S12ADI0ハンドラ                               */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleS12AD_S12ADI0)
VD FnVD_HwCore_Exception_handleS12AD_S12ADI0(VD)
{
  FnVD_HwSrv_Exception_handleS12AD_S12ADI0();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleICU_GROUP0              */
/*          ICU.GROUP0ハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleICU_GROUP0)
VD FnVD_HwCore_Exception_handleICU_GROUP0(VD)
{
  FnVD_HwSrv_Exception_handleICU_GROUP0();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleICU_GROUP1              */
/*          ICU.GROUP1ハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleICU_GROUP1)
VD FnVD_HwCore_Exception_handleICU_GROUP1(VD)
{
  FnVD_HwSrv_Exception_handleICU_GROUP1();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleICU_GROUP2              */
/*          ICU.GROUP2ハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleICU_GROUP2)
VD FnVD_HwCore_Exception_handleICU_GROUP2(VD)
{
  FnVD_HwSrv_Exception_handleICU_GROUP2();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleICU_GROUP3              */
/*          ICU.GROUP3ハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleICU_GROUP3)
VD FnVD_HwCore_Exception_handleICU_GROUP3(VD)
{
  FnVD_HwSrv_Exception_handleICU_GROUP3();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleICU_GROUP4              */
/*          ICU.GROUP4ハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleICU_GROUP4)
VD FnVD_HwCore_Exception_handleICU_GROUP4(VD)
{
  FnVD_HwSrv_Exception_handleICU_GROUP4();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleICU_GROUP5              */
/*          ICU.GROUP5ハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleICU_GROUP5)
VD FnVD_HwCore_Exception_handleICU_GROUP5(VD)
{
  FnVD_HwSrv_Exception_handleICU_GROUP5();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleICU_GROUP6              */
/*          ICU.GROUP6ハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleICU_GROUP6)
VD FnVD_HwCore_Exception_handleICU_GROUP6(VD)
{
  FnVD_HwSrv_Exception_handleICU_GROUP6();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleICU_GROUP12             */
/*          ICU.GROUP12ハンドラ                                 */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleICU_GROUP12)
VD FnVD_HwCore_Exception_handleICU_GROUP12(VD)
{
  FnVD_HwSrv_Exception_handleICU_GROUP12();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleSCI12_SCIX0             */
/*          SCI12.SCIX0ハンドラ                                 */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleSCI12_SCIX0)
VD FnVD_HwCore_Exception_handleSCI12_SCIX0(VD)
{
  FnVD_HwSrv_Exception_handleSCI12_SCIX0();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleSCI12_SCIX1             */
/*          SCI12.SCIX1ハンドラ                                 */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleSCI12_SCIX1)
VD FnVD_HwCore_Exception_handleSCI12_SCIX1(VD)
{
  FnVD_HwSrv_Exception_handleSCI12_SCIX1();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleSCI12_SCIX2             */
/*          SCI12.SCIX2ハンドラ                                 */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleSCI12_SCIX2)
VD FnVD_HwCore_Exception_handleSCI12_SCIX2(VD)
{
  FnVD_HwSrv_Exception_handleSCI12_SCIX2();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleSCI12_SCIX3             */
/*          SCI12.SCIX3ハンドラ                                 */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleSCI12_SCIX3)
VD FnVD_HwCore_Exception_handleSCI12_SCIX3(VD)
{
  FnVD_HwSrv_Exception_handleSCI12_SCIX3();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTPU0_TGI0A              */
/*          TPU0.TGI0Aハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTPU0_TGI0A)
VD FnVD_HwCore_Exception_handleTPU0_TGI0A(VD)
{
  FnVD_HwSrv_Exception_handleTPU0_TGI0A();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTPU0_TGI0B              */
/*          TPU0.TGI0Bハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTPU0_TGI0B)
VD FnVD_HwCore_Exception_handleTPU0_TGI0B(VD)
{
  FnVD_HwSrv_Exception_handleTPU0_TGI0B();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTPU0_TGI0C              */
/*          TPU0.TGI0Cハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTPU0_TGI0C)
VD FnVD_HwCore_Exception_handleTPU0_TGI0C(VD)
{
  FnVD_HwSrv_Exception_handleTPU0_TGI0C();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTPU0_TGI0D              */
/*          TPU0.TGI0Dハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTPU0_TGI0D)
VD FnVD_HwCore_Exception_handleTPU0_TGI0D(VD)
{
  FnVD_HwSrv_Exception_handleTPU0_TGI0D();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTPU1_TGI1A              */
/*          TPU1.TGI1Aハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTPU1_TGI1A)
VD FnVD_HwCore_Exception_handleTPU1_TGI1A(VD)
{
  FnVD_HwSrv_Exception_handleTPU1_TGI1A();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTPU1_TGI1B              */
/*          TPU1.TGI1Bハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTPU1_TGI1B)
VD FnVD_HwCore_Exception_handleTPU1_TGI1B(VD)
{
  FnVD_HwSrv_Exception_handleTPU1_TGI1B();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTPU2_TGI2A              */
/*          TPU2.TGI2Aハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTPU2_TGI2A)
VD FnVD_HwCore_Exception_handleTPU2_TGI2A(VD)
{
  FnVD_HwSrv_Exception_handleTPU2_TGI2A();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTPU2_TGI2B              */
/*          TPU2.TGI2Bハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTPU2_TGI2B)
VD FnVD_HwCore_Exception_handleTPU2_TGI2B(VD)
{
  FnVD_HwSrv_Exception_handleTPU2_TGI2B();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTPU3_TGI3A              */
/*          TPU3.TGI3Aハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTPU3_TGI3A)
VD FnVD_HwCore_Exception_handleTPU3_TGI3A(VD)
{
  FnVD_HwSrv_Exception_handleTPU3_TGI3A();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTPU3_TGI3B              */
/*          TPU3.TGI3Bハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTPU3_TGI3B)
VD FnVD_HwCore_Exception_handleTPU3_TGI3B(VD)
{
  FnVD_HwSrv_Exception_handleTPU3_TGI3B();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTPU3_TGI3C              */
/*          TPU3.TGI3Cハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTPU3_TGI3C)
VD FnVD_HwCore_Exception_handleTPU3_TGI3C(VD)
{
  FnVD_HwSrv_Exception_handleTPU3_TGI3C();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTPU3_TGI3D              */
/*          TPU3.TGI3Dハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTPU3_TGI3D)
VD FnVD_HwCore_Exception_handleTPU3_TGI3D(VD)
{
  FnVD_HwSrv_Exception_handleTPU3_TGI3D();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTPU4_TGI4A              */
/*          TPU4.TGI4Aハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTPU4_TGI4A)
VD FnVD_HwCore_Exception_handleTPU4_TGI4A(VD)
{
  FnVD_HwSrv_Exception_handleTPU4_TGI4A();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTPU4_TGI4B              */
/*          TPU4.TGI4Bハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTPU4_TGI4B)
VD FnVD_HwCore_Exception_handleTPU4_TGI4B(VD)
{
  FnVD_HwSrv_Exception_handleTPU4_TGI4B();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTPU5_TGI5A              */
/*          TPU5.TGI5Aハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTPU5_TGI5A)
VD FnVD_HwCore_Exception_handleTPU5_TGI5A(VD)
{
  FnVD_HwSrv_Exception_handleTPU5_TGI5A();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTPU5_TGI5B              */
/*          TPU5.TGI5Bハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTPU5_TGI5B)
VD FnVD_HwCore_Exception_handleTPU5_TGI5B(VD)
{
  FnVD_HwSrv_Exception_handleTPU5_TGI5B();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTPU6_TGI6A_MTU0_TGIA0   */
/*          TPU6.TGI6A/MTU0.TGIA0ハンドラ                       */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/*          SELレジスタ(CN0)により排他選択される                */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTPU6_TGI6A_MTU0_TGIA0)
VD FnVD_HwCore_Exception_handleTPU6_TGI6A_MTU0_TGIA0(VD)
{
  FnVD_HwSrv_Exception_handleTPU6_TGI6A_MTU0_TGIA0();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTPU6_TGI6B_MTU0_TGIB0   */
/*          TPU6.TGI6B/MTU0.TGIB0ハンドラ                       */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/*          SELレジスタ(CN0)により排他選択される                */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTPU6_TGI6B_MTU0_TGIB0)
VD FnVD_HwCore_Exception_handleTPU6_TGI6B_MTU0_TGIB0(VD)
{
  FnVD_HwSrv_Exception_handleTPU6_TGI6B_MTU0_TGIB0();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTPU6_TGI6C_MTU0_TGIC0   */
/*          TPU6.TGI6C/MTU0.TGIC0ハンドラ                       */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/*          SELレジスタ(CN0)により排他選択される                */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTPU6_TGI6C_MTU0_TGIC0)
VD FnVD_HwCore_Exception_handleTPU6_TGI6C_MTU0_TGIC0(VD)
{
  FnVD_HwSrv_Exception_handleTPU6_TGI6C_MTU0_TGIC0();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTPU6_TGI6D_MTU0_TGID0   */
/*          TPU6.TGI6D/MTU0.TGID0ハンドラ                       */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/*          SELレジスタ(CN0)により排他選択される                */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTPU6_TGI6D_MTU0_TGID0)
VD FnVD_HwCore_Exception_handleTPU6_TGI6D_MTU0_TGID0(VD)
{
  FnVD_HwSrv_Exception_handleTPU6_TGI6D_MTU0_TGID0();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleMTU0_TGIE0              */
/*          MTU0.TGIE0ハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleMTU0_TGIE0)
VD FnVD_HwCore_Exception_handleMTU0_TGIE0(VD)
{
  FnVD_HwSrv_Exception_handleMTU0_TGIE0();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleMTU0_TGIF0              */
/*          MTU0.TGIF0ハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleMTU0_TGIF0)
VD FnVD_HwCore_Exception_handleMTU0_TGIF0(VD)
{
  FnVD_HwSrv_Exception_handleMTU0_TGIF0();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTPU7_TGI7A_MTU1_TGIA1   */
/*          TPU7.TGI7A/MTU1.TGIA1ハンドラ                       */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/*          SELレジスタ(CN1)により排他選択される                */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTPU7_TGI7A_MTU1_TGIA1)
VD FnVD_HwCore_Exception_handleTPU7_TGI7A_MTU1_TGIA1(VD)
{
  FnVD_HwSrv_Exception_handleTPU7_TGI7A_MTU1_TGIA1();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTPU7_TGI7B_MTU1_TGIB1   */
/*          TPU7.TGI7B/MTU1.TGIB1ハンドラ                       */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/*          SELレジスタ(CN1)により排他選択される                */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTPU7_TGI7B_MTU1_TGIB1)
VD FnVD_HwCore_Exception_handleTPU7_TGI7B_MTU1_TGIB1(VD)
{
  FnVD_HwSrv_Exception_handleTPU7_TGI7B_MTU1_TGIB1();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTPU8_TGI8A_MTU2_TGIA2   */
/*          TPU8.TGI8A/MTU2.TGIA2ハンドラ                       */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/*          SELレジスタ(CN2)により排他選択される                */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTPU8_TGI8A_MTU2_TGIA2)
VD FnVD_HwCore_Exception_handleTPU8_TGI8A_MTU2_TGIA2(VD)
{
  FnVD_HwSrv_Exception_handleTPU8_TGI8A_MTU2_TGIA2();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTPU8_TGI8B_MTU2_TGIB2   */
/*          TPU8.TGI8B/MTU2.TGIB2ハンドラ                       */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/*          SELレジスタ(CN2)により排他選択される                */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTPU8_TGI8B_MTU2_TGIB2)
VD FnVD_HwCore_Exception_handleTPU8_TGI8B_MTU2_TGIB2(VD)
{
  FnVD_HwSrv_Exception_handleTPU8_TGI8B_MTU2_TGIB2();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTPU9_TGI9A_MTU3_TGIA3   */
/*          TPU9.TGI9A/MTU3.TGIA3ハンドラ                       */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/*          SELレジスタ(CN3)により排他選択される                */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTPU9_TGI9A_MTU3_TGIA3)
VD FnVD_HwCore_Exception_handleTPU9_TGI9A_MTU3_TGIA3(VD)
{
  FnVD_HwSrv_Exception_handleTPU9_TGI9A_MTU3_TGIA3();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTPU9_TGI9B_MTU3_TGIB3   */
/*          TPU9.TGI9B/MTU3.TGIB3ハンドラ                       */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/*          SELレジスタ(CN3)により排他選択される                */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTPU9_TGI9B_MTU3_TGIB3)
VD FnVD_HwCore_Exception_handleTPU9_TGI9B_MTU3_TGIB3(VD)
{
  FnVD_HwSrv_Exception_handleTPU9_TGI9B_MTU3_TGIB3();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTPU9_TGI9C_MTU3_TGIC3   */
/*          TPU9.TGI9C/MTU3.TGIC3ハンドラ                       */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/*          SELレジスタ(CN3)により排他選択される                */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTPU9_TGI9C_MTU3_TGIC3)
VD FnVD_HwCore_Exception_handleTPU9_TGI9C_MTU3_TGIC3(VD)
{
  FnVD_HwSrv_Exception_handleTPU9_TGI9C_MTU3_TGIC3();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTPU9_TGI9D_MTU3_TGID3   */
/*          TPU9.TGI9D/MTU3.TGID3ハンドラ                       */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/*          SELレジスタ(CN3)により排他選択される                */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTPU9_TGI9D_MTU3_TGID3)
VD FnVD_HwCore_Exception_handleTPU9_TGI9D_MTU3_TGID3(VD)
{
  FnVD_HwSrv_Exception_handleTPU9_TGI9D_MTU3_TGID3();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTPU10_TGI10A_MTU4_TGIA4 */
/*          TPU10.TGI10A/MTU4.TGIA4ハンドラ                     */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/*          SELレジスタ(CN4)により排他選択される                */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTPU10_TGI10A_MTU4_TGIA4)
VD FnVD_HwCore_Exception_handleTPU10_TGI10A_MTU4_TGIA4(VD)
{
  FnVD_HwSrv_Exception_handleTPU10_TGI10A_MTU4_TGIA4();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTPU10_TGI10B_MTU4_TGIB4 */
/*          TPU10.TGI10B/MTU4.TGIB4ハンドラ                     */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/*          SELレジスタ(CN4)により排他選択される                */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTPU10_TGI10B_MTU4_TGIB4)
VD FnVD_HwCore_Exception_handleTPU10_TGI10B_MTU4_TGIB4(VD)
{
  FnVD_HwSrv_Exception_handleTPU10_TGI10B_MTU4_TGIB4();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleMTU4_TGIC4              */
/*          MTU4.TGIC4ハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleMTU4_TGIC4)
VD FnVD_HwCore_Exception_handleMTU4_TGIC4(VD)
{
  FnVD_HwSrv_Exception_handleMTU4_TGIC4();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleMTU4_TGID4              */
/*          MTU4.TGID4ハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleMTU4_TGID4)
VD FnVD_HwCore_Exception_handleMTU4_TGID4(VD)
{
  FnVD_HwSrv_Exception_handleMTU4_TGID4();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleMTU4_TCIV4              */
/*          MTU4.TCIV4ハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleMTU4_TCIV4)
VD FnVD_HwCore_Exception_handleMTU4_TCIV4(VD)
{
  FnVD_HwSrv_Exception_handleMTU4_TCIV4();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTPU11_TGI11A            */
/*          TPU11.TGI11Aハンドラ                                */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTPU11_TGI11A)
VD FnVD_HwCore_Exception_handleTPU11_TGI11A(VD)
{
  FnVD_HwSrv_Exception_handleTPU11_TGI11A();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTPU11_TGI11B            */
/*          TPU11.TGI11Bハンドラ                                */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTPU11_TGI11B)
VD FnVD_HwCore_Exception_handleTPU11_TGI11B(VD)
{
  FnVD_HwSrv_Exception_handleTPU11_TGI11B();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleMTU5_TGIU5              */
/*          MTU5.TGIU5ハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleMTU5_TGIU5)
VD FnVD_HwCore_Exception_handleMTU5_TGIU5(VD)
{
  FnVD_HwSrv_Exception_handleMTU5_TGIU5();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleMTU5_TGIV5              */
/*          MTU5.TGIV5ハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleMTU5_TGIV5)
VD FnVD_HwCore_Exception_handleMTU5_TGIV5(VD)
{
  FnVD_HwSrv_Exception_handleMTU5_TGIV5();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleMTU5_TGIW5              */
/*          MTU5.TGIW5ハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleMTU5_TGIW5)
VD FnVD_HwCore_Exception_handleMTU5_TGIW5(VD)
{
  FnVD_HwSrv_Exception_handleMTU5_TGIW5();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handlePOE_OEI1                */
/*          POE.OEI1ハンドラ                                    */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handlePOE_OEI1)
VD FnVD_HwCore_Exception_handlePOE_OEI1(VD)
{
  FnVD_HwSrv_Exception_handlePOE_OEI1();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handlePOE_OEI2                */
/*          POE.OEI2ハンドラ                                    */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handlePOE_OEI2)
VD FnVD_HwCore_Exception_handlePOE_OEI2(VD)
{
  FnVD_HwSrv_Exception_handlePOE_OEI2();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTMR0_CMIA0              */
/*          TMR0.CMIA0ハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTMR0_CMIA0)
VD FnVD_HwCore_Exception_handleTMR0_CMIA0(VD)
{
  FnVD_HwSrv_Exception_handleTMR0_CMIA0();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTMR0_CMIB0              */
/*          TMR0.CMIB0ハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTMR0_CMIB0)
VD FnVD_HwCore_Exception_handleTMR0_CMIB0(VD)
{
  FnVD_HwSrv_Exception_handleTMR0_CMIB0();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTMR0_OVI0               */
/*          TMR0.OVI0ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTMR0_OVI0)
VD FnVD_HwCore_Exception_handleTMR0_OVI0(VD)
{
  FnVD_HwSrv_Exception_handleTMR0_OVI0();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTMR1_CMIA1              */
/*          TMR1.CMIA1ハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTMR1_CMIA1)
VD FnVD_HwCore_Exception_handleTMR1_CMIA1(VD)
{
  FnVD_HwSrv_Exception_handleTMR1_CMIA1();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTMR1_CMIB1              */
/*          TMR1.CMIB1ハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTMR1_CMIB1)
VD FnVD_HwCore_Exception_handleTMR1_CMIB1(VD)
{
  FnVD_HwSrv_Exception_handleTMR1_CMIB1();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTMR1_OVI1               */
/*          TMR1.OVI1ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTMR1_OVI1)
VD FnVD_HwCore_Exception_handleTMR1_OVI1(VD)
{
  FnVD_HwSrv_Exception_handleTMR1_OVI1();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTMR2_CMIA2              */
/*          TMR2.CMIA2ハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTMR2_CMIA2)
VD FnVD_HwCore_Exception_handleTMR2_CMIA2(VD)
{
  FnVD_HwSrv_Exception_handleTMR2_CMIA2();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTMR2_CMIB2              */
/*          TMR2.CMIB2ハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTMR2_CMIB2)
VD FnVD_HwCore_Exception_handleTMR2_CMIB2(VD)
{
  FnVD_HwSrv_Exception_handleTMR2_CMIB2();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTMR2_OVI2               */
/*          TMR2.OVI2ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTMR2_OVI2)
VD FnVD_HwCore_Exception_handleTMR2_OVI2(VD)
{
  FnVD_HwSrv_Exception_handleTMR2_OVI2();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTMR3_CMIA3              */
/*          TMR3.CMIA3ハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTMR3_CMIA3)
VD FnVD_HwCore_Exception_handleTMR3_CMIA3(VD)
{
  FnVD_HwSrv_Exception_handleTMR3_CMIA3();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTMR3_CMIB3              */
/*          TMR3.CMIB3ハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTMR3_CMIB3)
VD FnVD_HwCore_Exception_handleTMR3_CMIB3(VD)
{
  FnVD_HwSrv_Exception_handleTMR3_CMIB3();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleTMR3_OVI3               */
/*          TMR3.OVI3ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleTMR3_OVI3)
VD FnVD_HwCore_Exception_handleTMR3_OVI3(VD)
{
  FnVD_HwSrv_Exception_handleTMR3_OVI3();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleRIIC0_EEI0              */
/*          RIIC0.EEI0ハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleRIIC0_EEI0)
VD FnVD_HwCore_Exception_handleRIIC0_EEI0(VD)
{
  FnVD_HwSrv_Exception_handleRIIC0_EEI0();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleRIIC0_RXI0              */
/*          RIIC0.RXI0ハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleRIIC0_RXI0)
VD FnVD_HwCore_Exception_handleRIIC0_RXI0(VD)
{
  FnVD_HwSrv_Exception_handleRIIC0_RXI0();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleRIIC0_TXI0              */
/*          RIIC0.TXI0ハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleRIIC0_TXI0)
VD FnVD_HwCore_Exception_handleRIIC0_TXI0(VD)
{
  FnVD_HwSrv_Exception_handleRIIC0_TXI0();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleRIIC0_TEI0              */
/*          RIIC0.TEI0ハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleRIIC0_TEI0)
VD FnVD_HwCore_Exception_handleRIIC0_TEI0(VD)
{
  FnVD_HwSrv_Exception_handleRIIC0_TEI0();
}



/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleRIIC1_EEI1              */
/*          RIIC1.EEI1ハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleRIIC1_EEI1)
VD FnVD_HwCore_Exception_handleRIIC1_EEI1(VD)
{
  FnVD_HwSrv_Exception_handleRIIC1_EEI1();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleRIIC1_RXI1              */
/*          RIIC1.RXI1ハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleRIIC1_RXI1)
VD FnVD_HwCore_Exception_handleRIIC1_RXI1(VD)
{
  FnVD_HwSrv_Exception_handleRIIC1_RXI1();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleRIIC1_TXI1              */
/*          RIIC1.TXI1ハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleRIIC1_TXI1)
VD FnVD_HwCore_Exception_handleRIIC1_TXI1(VD)
{
  FnVD_HwSrv_Exception_handleRIIC1_TXI1();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleRIIC1_TEI1              */
/*          RIIC1.TEI1ハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleRIIC1_TEI1)
VD FnVD_HwCore_Exception_handleRIIC1_TEI1(VD)
{
  FnVD_HwSrv_Exception_handleRIIC1_TEI1();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleRIIC2_EEI2              */
/*          RIIC2.EEI2ハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleRIIC2_EEI2)
VD FnVD_HwCore_Exception_handleRIIC2_EEI2(VD)
{
  FnVD_HwSrv_Exception_handleRIIC2_EEI2();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleRIIC2_RXI2              */
/*          RIIC2.RXI2ハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleRIIC2_RXI2)
VD FnVD_HwCore_Exception_handleRIIC2_RXI2(VD)
{
  FnVD_HwSrv_Exception_handleRIIC2_RXI2();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleRIIC2_TXI2              */
/*          RIIC2.TXI2ハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleRIIC2_TXI2)
VD FnVD_HwCore_Exception_handleRIIC2_TXI2(VD)
{
  FnVD_HwSrv_Exception_handleRIIC2_TXI2();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleRIIC2_TEI2              */
/*          RIIC2.TEI2ハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleRIIC2_TEI2)
VD FnVD_HwCore_Exception_handleRIIC2_TEI2(VD)
{
  FnVD_HwSrv_Exception_handleRIIC2_TEI2();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleRIIC3_EEI3              */
/*          RIIC3.EEI3ハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleRIIC3_EEI3)
VD FnVD_HwCore_Exception_handleRIIC3_EEI3(VD)
{
  FnVD_HwSrv_Exception_handleRIIC3_EEI3();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleRIIC3_RXI3              */
/*          RIIC3.RXI3ハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleRIIC3_RXI3)
VD FnVD_HwCore_Exception_handleRIIC3_RXI3(VD)
{
  FnVD_HwSrv_Exception_handleRIIC3_RXI3();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleRIIC3_TXI3              */
/*          RIIC3.TXI3ハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleRIIC3_TXI3)
VD FnVD_HwCore_Exception_handleRIIC3_TXI3(VD)
{
  FnVD_HwSrv_Exception_handleRIIC3_TXI3();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleRIIC3_TEI3              */
/*          RIIC3.TEI3ハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleRIIC3_TEI3)
VD FnVD_HwCore_Exception_handleRIIC3_TEI3(VD)
{
  FnVD_HwSrv_Exception_handleRIIC3_TEI3();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleDMAC_DMAC0I             */
/*          DMAC.DMAC0Iハンドラ                                 */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleDMAC_DMAC0I)
VD FnVD_HwCore_Exception_handleDMAC_DMAC0I(VD)
{
  FnVD_HwSrv_Exception_handleDMAC_DMAC0I();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleDMAC_DMAC1I             */
/*          DMAC.DMAC1Iハンドラ                                 */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleDMAC_DMAC1I)
VD FnVD_HwCore_Exception_handleDMAC_DMAC1I(VD)
{
  FnVD_HwSrv_Exception_handleDMAC_DMAC1I();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleDMAC_DMAC2I             */
/*          DMAC.DMAC2Iハンドラ                                 */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleDMAC_DMAC2I)
VD FnVD_HwCore_Exception_handleDMAC_DMAC2I(VD)
{
  FnVD_HwSrv_Exception_handleDMAC_DMAC2I();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleDMAC_DMAC3I             */
/*          DMAC.DMAC3Iハンドラ                                 */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleDMAC_DMAC3I)
VD FnVD_HwCore_Exception_handleDMAC_DMAC3I(VD)
{
  FnVD_HwSrv_Exception_handleDMAC_DMAC3I();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleEXDMAC_EXDMAC0I         */
/*          EXDMAC.EXDMAC0Iハンドラ                             */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleEXDMAC_EXDMAC0I)
VD FnVD_HwCore_Exception_handleEXDMAC_EXDMAC0I(VD)
{
  FnVD_HwSrv_Exception_handleEXDMAC_EXDMAC0I();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleEXDMAC_EXDMAC1I         */
/*          EXDMAC.EXDMAC1Iハンドラ                             */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleEXDMAC_EXDMAC1I)
VD FnVD_HwCore_Exception_handleEXDMAC_EXDMAC1I(VD)
{
  FnVD_HwSrv_Exception_handleEXDMAC_EXDMAC1I();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleDEU_DEU0                */
/*          DEU.DEU0ハンドラ                                    */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleDEU_DEU0)
VD FnVD_HwCore_Exception_handleDEU_DEU0(VD)
{
  FnVD_HwSrv_Exception_handleDEU_DEU0();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleDEU_DEU1                */
/*          DEU.DEU1ハンドラ                                    */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleDEU_DEU1)
VD FnVD_HwCore_Exception_handleDEU_DEU1(VD)
{
  FnVD_HwSrv_Exception_handleDEU_DEU1();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handlePDC_PCDFI               */
/*          PDC.PCDFIハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handlePDC_PCDFI)
VD FnVD_HwCore_Exception_handlePDC_PCDFI(VD)
{
  FnVD_HwSrv_Exception_handlePDC_PCDFI();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handlePDC_PCFEI               */
/*          PDC.PCFEIハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handlePDC_PCFEI)
VD FnVD_HwCore_Exception_handlePDC_PCFEI(VD)
{
  FnVD_HwSrv_Exception_handlePDC_PCFEI();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handlePDC_PCERI               */
/*          PDC.PCERIハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handlePDC_PCERI)
VD FnVD_HwCore_Exception_handlePDC_PCERI(VD)
{
  FnVD_HwSrv_Exception_handlePDC_PCERI();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleSCI0_RXI0               */
/*          SCI0.RXI0ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleSCI0_RXI0)
VD FnVD_HwCore_Exception_handleSCI0_RXI0(VD)
{
  FnVD_HwSrv_Exception_handleSCI0_RXI0();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleSCI0_TXI0               */
/*          SCI0.TXI0ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleSCI0_TXI0)
VD FnVD_HwCore_Exception_handleSCI0_TXI0(VD)
{
  FnVD_HwSrv_Exception_handleSCI0_TXI0();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleSCI0_TEI0               */
/*          SCI0.TEI0ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleSCI0_TEI0)
VD FnVD_HwCore_Exception_handleSCI0_TEI0(VD)
{
  FnVD_HwSrv_Exception_handleSCI0_TEI0();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleSCI1_RXI1               */
/*          SCI1.RXI1ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleSCI1_RXI1)
VD FnVD_HwCore_Exception_handleSCI1_RXI1(VD)
{
  FnVD_HwSrv_Exception_handleSCI1_RXI1();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleSCI1_TXI1               */
/*          SCI1.TXI1ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleSCI1_TXI1)
VD FnVD_HwCore_Exception_handleSCI1_TXI1(VD)
{
  FnVD_HwSrv_Exception_handleSCI1_TXI1();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleSCI1_TEI1               */
/*          SCI1.TEI1ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleSCI1_TEI1)
VD FnVD_HwCore_Exception_handleSCI1_TEI1(VD)
{
  FnVD_HwSrv_Exception_handleSCI1_TEI1();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleSCI2_RXI2               */
/*          SCI2.RXI2ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleSCI2_RXI2)
VD FnVD_HwCore_Exception_handleSCI2_RXI2(VD)
{
  FnVD_HwSrv_Exception_handleSCI2_RXI2();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleSCI2_TXI2               */
/*          SCI2.TXI2ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleSCI2_TXI2)
VD FnVD_HwCore_Exception_handleSCI2_TXI2(VD)
{
  FnVD_HwSrv_Exception_handleSCI2_TXI2();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleSCI2_TEI2               */
/*          SCI2.TEI2ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleSCI2_TEI2)
VD FnVD_HwCore_Exception_handleSCI2_TEI2(VD)
{
  FnVD_HwSrv_Exception_handleSCI2_TEI2();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleSCI3_RXI3               */
/*          SCI3.RXI3ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleSCI3_RXI3)
VD FnVD_HwCore_Exception_handleSCI3_RXI3(VD)
{
  FnVD_HwSrv_Exception_handleSCI3_RXI3();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleSCI3_TXI3               */
/*          SCI3.TXI3ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleSCI3_TXI3)
VD FnVD_HwCore_Exception_handleSCI3_TXI3(VD)
{
  FnVD_HwSrv_Exception_handleSCI3_TXI3();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleSCI3_TEI3               */
/*          SCI3.TEI3ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleSCI3_TEI3)
VD FnVD_HwCore_Exception_handleSCI3_TEI3(VD)
{
  FnVD_HwSrv_Exception_handleSCI3_TEI3();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleSCI4_RXI4               */
/*          SCI4.RXI4ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleSCI4_RXI4)
VD FnVD_HwCore_Exception_handleSCI4_RXI4(VD)
{
  FnVD_HwSrv_Exception_handleSCI4_RXI4();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleSCI4_TXI4               */
/*          SCI4.TXI4ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleSCI4_TXI4)
VD FnVD_HwCore_Exception_handleSCI4_TXI4(VD)
{
  FnVD_HwSrv_Exception_handleSCI4_TXI4();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleSCI4_TEI4               */
/*          SCI4.TEI4ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleSCI4_TEI4)
VD FnVD_HwCore_Exception_handleSCI4_TEI4(VD)
{
  FnVD_HwSrv_Exception_handleSCI4_TEI4();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleSCI5_RXI5               */
/*          SCI5.RXI5ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleSCI5_RXI5)
VD FnVD_HwCore_Exception_handleSCI5_RXI5(VD)
{
  FnVD_HwSrv_Exception_handleSCI5_RXI5();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleSCI5_TXI5               */
/*          SCI5.TXI5ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleSCI5_TXI5)
VD FnVD_HwCore_Exception_handleSCI5_TXI5(VD)
{
  FnVD_HwSrv_Exception_handleSCI5_TXI5();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleSCI5_TEI5               */
/*          SCI5.TEI5ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleSCI5_TEI5)
VD FnVD_HwCore_Exception_handleSCI5_TEI5(VD)
{
  FnVD_HwSrv_Exception_handleSCI5_TEI5();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleSCI6_RXI6               */
/*          SCI6.RXI6ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleSCI6_RXI6)
VD FnVD_HwCore_Exception_handleSCI6_RXI6(VD)
{
  FnVD_HwSrv_Exception_handleSCI6_RXI6();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleSCI6_TXI6               */
/*          SCI6.TXI6ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleSCI6_TXI6)
VD FnVD_HwCore_Exception_handleSCI6_TXI6(VD)
{
  FnVD_HwSrv_Exception_handleSCI6_TXI6();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleSCI6_TEI6               */
/*          SCI6.TEI6ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleSCI6_TEI6)
VD FnVD_HwCore_Exception_handleSCI6_TEI6(VD)
{
  FnVD_HwSrv_Exception_handleSCI6_TEI6();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleSCI7_RXI7               */
/*          SCI7.RXI7ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleSCI7_RXI7)
VD FnVD_HwCore_Exception_handleSCI7_RXI7(VD)
{
  FnVD_HwSrv_Exception_handleSCI7_RXI7();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleSCI7_TXI7               */
/*          SCI7.TXI7ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleSCI7_TXI7)
VD FnVD_HwCore_Exception_handleSCI7_TXI7(VD)
{
  FnVD_HwSrv_Exception_handleSCI7_TXI7();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleSCI7_TEI7               */
/*          SCI7.TEI7ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleSCI7_TEI7)
VD FnVD_HwCore_Exception_handleSCI7_TEI7(VD)
{
  FnVD_HwSrv_Exception_handleSCI7_TEI7();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleSCI8_RXI8               */
/*          SCI8.RXI8ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleSCI8_RXI8)
VD FnVD_HwCore_Exception_handleSCI8_RXI8(VD)
{
  FnVD_HwSrv_Exception_handleSCI8_RXI8();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleSCI8_TXI8               */
/*          SCI8.TXI8ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleSCI8_TXI8)
VD FnVD_HwCore_Exception_handleSCI8_TXI8(VD)
{
  FnVD_HwSrv_Exception_handleSCI8_TXI8();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleSCI8_TEI8               */
/*          SCI8.TEI8ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleSCI8_TEI8)
VD FnVD_HwCore_Exception_handleSCI8_TEI8(VD)
{
  FnVD_HwSrv_Exception_handleSCI8_TEI8();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleSCI9_RXI9               */
/*          SCI9.RXI9ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleSCI9_RXI9)
VD FnVD_HwCore_Exception_handleSCI9_RXI9(VD)
{
  FnVD_HwSrv_Exception_handleSCI9_RXI9();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleSCI9_TXI9               */
/*          SCI9.TXI9ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleSCI9_TXI9)
VD FnVD_HwCore_Exception_handleSCI9_TXI9(VD)
{
  FnVD_HwSrv_Exception_handleSCI9_TXI9();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleSCI9_TEI9               */
/*          SCI9.TEI9ハンドラ                                   */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleSCI9_TEI9)
VD FnVD_HwCore_Exception_handleSCI9_TEI9(VD)
{
  FnVD_HwSrv_Exception_handleSCI9_TEI9();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleSCI10_RXI10             */
/*          SCI10.RXI10ハンドラ                                 */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleSCI10_RXI10)
VD FnVD_HwCore_Exception_handleSCI10_RXI10(VD)
{
  FnVD_HwSrv_Exception_handleSCI10_RXI10();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleSCI10_TXI10             */
/*          SCI10.TXI10ハンドラ                                 */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleSCI10_TXI10)
VD FnVD_HwCore_Exception_handleSCI10_TXI10(VD)
{
  FnVD_HwSrv_Exception_handleSCI10_TXI10();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleSCI10_TEI10             */
/*          SCI10.TEI10ハンドラ                                 */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleSCI10_TEI10)
VD FnVD_HwCore_Exception_handleSCI10_TEI10(VD)
{
  FnVD_HwSrv_Exception_handleSCI10_TEI10();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleSCI11_RXI11             */
/*          SCI11.RXI11ハンドラ                                 */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleSCI11_RXI11)
VD FnVD_HwCore_Exception_handleSCI11_RXI11(VD)
{
  FnVD_HwSrv_Exception_handleSCI11_RXI11();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleSCI11_TXI11             */
/*          SCI11.TXI11ハンドラ                                 */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleSCI11_TXI11)
VD FnVD_HwCore_Exception_handleSCI11_TXI11(VD)
{
  FnVD_HwSrv_Exception_handleSCI11_TXI11();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleSCI11_TEI11             */
/*          SCI11.TEI11ハンドラ                                 */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleSCI11_TEI11)
VD FnVD_HwCore_Exception_handleSCI11_TEI11(VD)
{
  FnVD_HwSrv_Exception_handleSCI11_TEI11();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleSCI12_RXI12             */
/*          SCI12.RXI12ハンドラ                                 */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleSCI12_RXI12)
VD FnVD_HwCore_Exception_handleSCI12_RXI12(VD)
{
  FnVD_HwSrv_Exception_handleSCI12_RXI12();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleSCI12_TXI12             */
/*          SCI12.TXI12ハンドラ                                 */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleSCI12_TXI12)
VD FnVD_HwCore_Exception_handleSCI12_TXI12(VD)
{
  FnVD_HwSrv_Exception_handleSCI12_TXI12();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleSCI12_TEI12             */
/*          SCI12.TEI12ハンドラ                                 */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleSCI12_TEI12)
VD FnVD_HwCore_Exception_handleSCI12_TEI12(VD)
{
  FnVD_HwSrv_Exception_handleSCI12_TEI12();
}


/* ============================================================ */
/* 関数名 : FnVD_HwCore_Exception_handleIEB_IEBINT              */
/*          IEB.IEBINTハンドラ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 例外ハンドラ                                        */
/* 制約   : 例外ベクタ以外で使用しないこと                      */
/* ============================================================ */
#pragma interrupt (FnVD_HwCore_Exception_handleIEB_IEBINT)
VD FnVD_HwCore_Exception_handleIEB_IEBINT(VD)
{
  FnVD_HwSrv_Exception_handleIEB_IEBINT();
}


/* セクションをユーザー定義に戻す */
#include "prj_cmn_section.h"

