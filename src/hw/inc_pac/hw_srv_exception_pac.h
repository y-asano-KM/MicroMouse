#if !defined(INCLUDED_hw_srv_exception_pac_h)
#define INCLUDED_hw_srv_exception_pac_h
/* ============================================================ */
/* ファイル名 : hw_srv_exception_pac.h                          */
/* 機能       : 例外ハンドラ                                    */
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


/* ============================================================ */
/* 関数プロトタイプ宣言(extern)                                 */
/* ============================================================ */
/* 予約領域用 */
extern VD FnVD_HwSrv_Exception_handleReserved(VD);

/* 固定ベクタ用 */
extern VD FnVD_HwSrv_Exception_handleSuperVisor(VD);
extern VD FnVD_HwSrv_Exception_handleAccess(VD);
extern VD FnVD_HwSrv_Exception_handleUndefined(VD);
extern VD FnVD_HwSrv_Exception_handleFloatingPoint(VD);
extern VD FnVD_HwSrv_Exception_handleNonMaskableInterrupt(VD);

/* 可変ベクタ用 */
extern VD FnVD_HwSrv_Exception_handleBrk(VD);
extern VD FnVD_HwSrv_Exception_handleTrap(VD);
extern VD FnVD_HwSrv_Exception_handleBSC_BUSERR(VD);
extern VD FnVD_HwSrv_Exception_handleFCU_FIFERR(VD);
extern VD FnVD_HwSrv_Exception_handleFCU_FRDYI(VD);
extern VD FnVD_HwSrv_Exception_handleICU_SWINT(VD);
extern VD FnVD_HwSrv_Exception_handleCMT0_CMI0(VD);
extern VD FnVD_HwSrv_Exception_handleCMT1_CMI1(VD);
extern VD FnVD_HwSrv_Exception_handleCMT2_CMI2(VD);
extern VD FnVD_HwSrv_Exception_handleCMT3_CMI3(VD);
extern VD FnVD_HwSrv_Exception_handleETHER_EINT(VD);
extern VD FnVD_HwSrv_Exception_handleUSB0_D0FIFO0(VD);
extern VD FnVD_HwSrv_Exception_handleUSB0_D1FIFO0(VD);
extern VD FnVD_HwSrv_Exception_handleUSB0_USBI0(VD);
extern VD FnVD_HwSrv_Exception_handleUSB1_D0FIFO1(VD);
extern VD FnVD_HwSrv_Exception_handleUSB1_D1FIFO1(VD);
extern VD FnVD_HwSrv_Exception_handleUSB1_USBI1(VD);
extern VD FnVD_HwSrv_Exception_handleRSPI0_SPRI0(VD);
extern VD FnVD_HwSrv_Exception_handleRSPI0_SPTI0(VD);
extern VD FnVD_HwSrv_Exception_handleRSPI0_SPII0(VD);
extern VD FnVD_HwSrv_Exception_handleRSPI1_SPRI1(VD);
extern VD FnVD_HwSrv_Exception_handleRSPI1_SPTI1(VD);
extern VD FnVD_HwSrv_Exception_handleRSPI1_SPII1(VD);
extern VD FnVD_HwSrv_Exception_handleRSPI2_SPRI2(VD);
extern VD FnVD_HwSrv_Exception_handleRSPI2_SPTI2(VD);
extern VD FnVD_HwSrv_Exception_handleRSPI2_SPII2(VD);
extern VD FnVD_HwSrv_Exception_handleCAN0_RXF0(VD);
extern VD FnVD_HwSrv_Exception_handleCAN0_TXF0(VD);
extern VD FnVD_HwSrv_Exception_handleCAN0_RXM0(VD);
extern VD FnVD_HwSrv_Exception_handleCAN0_TXM0(VD);
extern VD FnVD_HwSrv_Exception_handleCAN1_RXF1(VD);
extern VD FnVD_HwSrv_Exception_handleCAN1_TXF1(VD);
extern VD FnVD_HwSrv_Exception_handleCAN1_RXM1(VD);
extern VD FnVD_HwSrv_Exception_handleCAN1_TXM1(VD);
extern VD FnVD_HwSrv_Exception_handleCAN2_RXF2(VD);
extern VD FnVD_HwSrv_Exception_handleCAN2_TXF2(VD);
extern VD FnVD_HwSrv_Exception_handleCAN2_RXM2(VD);
extern VD FnVD_HwSrv_Exception_handleCAN2_TXM2(VD);
extern VD FnVD_HwSrv_Exception_handleRTC_CUP(VD);
extern VD FnVD_HwSrv_Exception_handleICU_IRQ0(VD);
extern VD FnVD_HwSrv_Exception_handleICU_IRQ1(VD);
extern VD FnVD_HwSrv_Exception_handleICU_IRQ2(VD);
extern VD FnVD_HwSrv_Exception_handleICU_IRQ3(VD);
extern VD FnVD_HwSrv_Exception_handleICU_IRQ4(VD);
extern VD FnVD_HwSrv_Exception_handleICU_IRQ5(VD);
extern VD FnVD_HwSrv_Exception_handleICU_IRQ6(VD);
extern VD FnVD_HwSrv_Exception_handleICU_IRQ7(VD);
extern VD FnVD_HwSrv_Exception_handleICU_IRQ8(VD);
extern VD FnVD_HwSrv_Exception_handleICU_IRQ9(VD);
extern VD FnVD_HwSrv_Exception_handleICU_IRQ10(VD);
extern VD FnVD_HwSrv_Exception_handleICU_IRQ11(VD);
extern VD FnVD_HwSrv_Exception_handleICU_IRQ12(VD);
extern VD FnVD_HwSrv_Exception_handleICU_IRQ13(VD);
extern VD FnVD_HwSrv_Exception_handleICU_IRQ14(VD);
extern VD FnVD_HwSrv_Exception_handleICU_IRQ15(VD);
extern VD FnVD_HwSrv_Exception_handleUSB_USBR0(VD);
extern VD FnVD_HwSrv_Exception_handleUSB_USBR1(VD);
extern VD FnVD_HwSrv_Exception_handleRTC_ALM(VD);
extern VD FnVD_HwSrv_Exception_handleRTC_PRD(VD);
extern VD FnVD_HwSrv_Exception_handleAD_ADI0(VD);
extern VD FnVD_HwSrv_Exception_handleS12AD_S12ADI0(VD);
extern VD FnVD_HwSrv_Exception_handleICU_GROUP0(VD);
extern VD FnVD_HwSrv_Exception_handleICU_GROUP1(VD);
extern VD FnVD_HwSrv_Exception_handleICU_GROUP2(VD);
extern VD FnVD_HwSrv_Exception_handleICU_GROUP3(VD);
extern VD FnVD_HwSrv_Exception_handleICU_GROUP4(VD);
extern VD FnVD_HwSrv_Exception_handleICU_GROUP5(VD);
extern VD FnVD_HwSrv_Exception_handleICU_GROUP6(VD);
extern VD FnVD_HwSrv_Exception_handleICU_GROUP12(VD);
extern VD FnVD_HwSrv_Exception_handleSCI12_SCIX0(VD);
extern VD FnVD_HwSrv_Exception_handleSCI12_SCIX1(VD);
extern VD FnVD_HwSrv_Exception_handleSCI12_SCIX2(VD);
extern VD FnVD_HwSrv_Exception_handleSCI12_SCIX3(VD);
extern VD FnVD_HwSrv_Exception_handleTPU0_TGI0A(VD);
extern VD FnVD_HwSrv_Exception_handleTPU0_TGI0B(VD);
extern VD FnVD_HwSrv_Exception_handleTPU0_TGI0C(VD);
extern VD FnVD_HwSrv_Exception_handleTPU0_TGI0D(VD);
extern VD FnVD_HwSrv_Exception_handleTPU1_TGI1A(VD);
extern VD FnVD_HwSrv_Exception_handleTPU1_TGI1B(VD);
extern VD FnVD_HwSrv_Exception_handleTPU2_TGI2A(VD);
extern VD FnVD_HwSrv_Exception_handleTPU2_TGI2B(VD);
extern VD FnVD_HwSrv_Exception_handleTPU3_TGI3A(VD);
extern VD FnVD_HwSrv_Exception_handleTPU3_TGI3B(VD);
extern VD FnVD_HwSrv_Exception_handleTPU3_TGI3C(VD);
extern VD FnVD_HwSrv_Exception_handleTPU3_TGI3D(VD);
extern VD FnVD_HwSrv_Exception_handleTPU4_TGI4A(VD);
extern VD FnVD_HwSrv_Exception_handleTPU4_TGI4B(VD);
extern VD FnVD_HwSrv_Exception_handleTPU5_TGI5A(VD);
extern VD FnVD_HwSrv_Exception_handleTPU5_TGI5B(VD);
extern VD FnVD_HwSrv_Exception_handleTPU6_TGI6A_MTU0_TGIA0(VD);
extern VD FnVD_HwSrv_Exception_handleTPU6_TGI6B_MTU0_TGIB0(VD);
extern VD FnVD_HwSrv_Exception_handleTPU6_TGI6C_MTU0_TGIC0(VD);
extern VD FnVD_HwSrv_Exception_handleTPU6_TGI6D_MTU0_TGID0(VD);
extern VD FnVD_HwSrv_Exception_handleMTU0_TGIE0(VD);
extern VD FnVD_HwSrv_Exception_handleMTU0_TGIF0(VD);
extern VD FnVD_HwSrv_Exception_handleTPU7_TGI7A_MTU1_TGIA1(VD);
extern VD FnVD_HwSrv_Exception_handleTPU7_TGI7B_MTU1_TGIB1(VD);
extern VD FnVD_HwSrv_Exception_handleTPU8_TGI8A_MTU2_TGIA2(VD);
extern VD FnVD_HwSrv_Exception_handleTPU8_TGI8B_MTU2_TGIB2(VD);
extern VD FnVD_HwSrv_Exception_handleTPU9_TGI9A_MTU3_TGIA3(VD);
extern VD FnVD_HwSrv_Exception_handleTPU9_TGI9B_MTU3_TGIB3(VD);
extern VD FnVD_HwSrv_Exception_handleTPU9_TGI9C_MTU3_TGIC3(VD);
extern VD FnVD_HwSrv_Exception_handleTPU9_TGI9D_MTU3_TGID3(VD);
extern VD FnVD_HwSrv_Exception_handleTPU10_TGI10A_MTU4_TGIA4(VD);
extern VD FnVD_HwSrv_Exception_handleTPU10_TGI10B_MTU4_TGIB4(VD);
extern VD FnVD_HwSrv_Exception_handleMTU4_TGIC4(VD);
extern VD FnVD_HwSrv_Exception_handleMTU4_TGID4(VD);
extern VD FnVD_HwSrv_Exception_handleMTU4_TCIV4(VD);
extern VD FnVD_HwSrv_Exception_handleTPU11_TGI11A(VD);
extern VD FnVD_HwSrv_Exception_handleTPU11_TGI11B(VD);
extern VD FnVD_HwSrv_Exception_handleMTU5_TGIU5(VD);
extern VD FnVD_HwSrv_Exception_handleMTU5_TGIV5(VD);
extern VD FnVD_HwSrv_Exception_handleMTU5_TGIW5(VD);
extern VD FnVD_HwSrv_Exception_handlePOE_OEI1(VD);
extern VD FnVD_HwSrv_Exception_handlePOE_OEI2(VD);
extern VD FnVD_HwSrv_Exception_handleTMR0_CMIA0(VD);
extern VD FnVD_HwSrv_Exception_handleTMR0_CMIB0(VD);
extern VD FnVD_HwSrv_Exception_handleTMR0_OVI0(VD);
extern VD FnVD_HwSrv_Exception_handleTMR1_CMIA1(VD);
extern VD FnVD_HwSrv_Exception_handleTMR1_CMIB1(VD);
extern VD FnVD_HwSrv_Exception_handleTMR1_OVI1(VD);
extern VD FnVD_HwSrv_Exception_handleTMR2_CMIA2(VD);
extern VD FnVD_HwSrv_Exception_handleTMR2_CMIB2(VD);
extern VD FnVD_HwSrv_Exception_handleTMR2_OVI2(VD);
extern VD FnVD_HwSrv_Exception_handleTMR3_CMIA3(VD);
extern VD FnVD_HwSrv_Exception_handleTMR3_CMIB3(VD);
extern VD FnVD_HwSrv_Exception_handleTMR3_OVI3(VD);
extern VD FnVD_HwSrv_Exception_handleRIIC0_EEI0(VD);
extern VD FnVD_HwSrv_Exception_handleRIIC0_RXI0(VD);
extern VD FnVD_HwSrv_Exception_handleRIIC0_TXI0(VD);
extern VD FnVD_HwSrv_Exception_handleRIIC0_TEI0(VD);
extern VD FnVD_HwSrv_Exception_handleRIIC1_EEI1(VD);
extern VD FnVD_HwSrv_Exception_handleRIIC1_RXI1(VD);
extern VD FnVD_HwSrv_Exception_handleRIIC1_TXI1(VD);
extern VD FnVD_HwSrv_Exception_handleRIIC1_TEI1(VD);
extern VD FnVD_HwSrv_Exception_handleRIIC2_EEI2(VD);
extern VD FnVD_HwSrv_Exception_handleRIIC2_RXI2(VD);
extern VD FnVD_HwSrv_Exception_handleRIIC2_TXI2(VD);
extern VD FnVD_HwSrv_Exception_handleRIIC2_TEI2(VD);
extern VD FnVD_HwSrv_Exception_handleRIIC3_EEI3(VD);
extern VD FnVD_HwSrv_Exception_handleRIIC3_RXI3(VD);
extern VD FnVD_HwSrv_Exception_handleRIIC3_TXI3(VD);
extern VD FnVD_HwSrv_Exception_handleRIIC3_TEI3(VD);
extern VD FnVD_HwSrv_Exception_handleDMAC_DMAC0I(VD);
extern VD FnVD_HwSrv_Exception_handleDMAC_DMAC1I(VD);
extern VD FnVD_HwSrv_Exception_handleDMAC_DMAC2I(VD);
extern VD FnVD_HwSrv_Exception_handleDMAC_DMAC3I(VD);
extern VD FnVD_HwSrv_Exception_handleEXDMAC_EXDMAC0I(VD);
extern VD FnVD_HwSrv_Exception_handleEXDMAC_EXDMAC1I(VD);
extern VD FnVD_HwSrv_Exception_handleDEU_DEU0(VD);
extern VD FnVD_HwSrv_Exception_handleDEU_DEU1(VD);
extern VD FnVD_HwSrv_Exception_handlePDC_PCDFI(VD);
extern VD FnVD_HwSrv_Exception_handlePDC_PCFEI(VD);
extern VD FnVD_HwSrv_Exception_handlePDC_PCERI(VD);
extern VD FnVD_HwSrv_Exception_handleSCI0_RXI0(VD);
extern VD FnVD_HwSrv_Exception_handleSCI0_TXI0(VD);
extern VD FnVD_HwSrv_Exception_handleSCI0_TEI0(VD);
extern VD FnVD_HwSrv_Exception_handleSCI1_RXI1(VD);
extern VD FnVD_HwSrv_Exception_handleSCI1_TXI1(VD);
extern VD FnVD_HwSrv_Exception_handleSCI1_TEI1(VD);
extern VD FnVD_HwSrv_Exception_handleSCI2_RXI2(VD);
extern VD FnVD_HwSrv_Exception_handleSCI2_TXI2(VD);
extern VD FnVD_HwSrv_Exception_handleSCI2_TEI2(VD);
extern VD FnVD_HwSrv_Exception_handleSCI3_RXI3(VD);
extern VD FnVD_HwSrv_Exception_handleSCI3_TXI3(VD);
extern VD FnVD_HwSrv_Exception_handleSCI3_TEI3(VD);
extern VD FnVD_HwSrv_Exception_handleSCI4_RXI4(VD);
extern VD FnVD_HwSrv_Exception_handleSCI4_TXI4(VD);
extern VD FnVD_HwSrv_Exception_handleSCI4_TEI4(VD);
extern VD FnVD_HwSrv_Exception_handleSCI5_RXI5(VD);
extern VD FnVD_HwSrv_Exception_handleSCI5_TXI5(VD);
extern VD FnVD_HwSrv_Exception_handleSCI5_TEI5(VD);
extern VD FnVD_HwSrv_Exception_handleSCI6_RXI6(VD);
extern VD FnVD_HwSrv_Exception_handleSCI6_TXI6(VD);
extern VD FnVD_HwSrv_Exception_handleSCI6_TEI6(VD);
extern VD FnVD_HwSrv_Exception_handleSCI7_RXI7(VD);
extern VD FnVD_HwSrv_Exception_handleSCI7_TXI7(VD);
extern VD FnVD_HwSrv_Exception_handleSCI7_TEI7(VD);
extern VD FnVD_HwSrv_Exception_handleSCI8_RXI8(VD);
extern VD FnVD_HwSrv_Exception_handleSCI8_TXI8(VD);
extern VD FnVD_HwSrv_Exception_handleSCI8_TEI8(VD);
extern VD FnVD_HwSrv_Exception_handleSCI9_RXI9(VD);
extern VD FnVD_HwSrv_Exception_handleSCI9_TXI9(VD);
extern VD FnVD_HwSrv_Exception_handleSCI9_TEI9(VD);
extern VD FnVD_HwSrv_Exception_handleSCI10_RXI10(VD);
extern VD FnVD_HwSrv_Exception_handleSCI10_TXI10(VD);
extern VD FnVD_HwSrv_Exception_handleSCI10_TEI10(VD);
extern VD FnVD_HwSrv_Exception_handleSCI11_RXI11(VD);
extern VD FnVD_HwSrv_Exception_handleSCI11_TXI11(VD);
extern VD FnVD_HwSrv_Exception_handleSCI11_TEI11(VD);
extern VD FnVD_HwSrv_Exception_handleSCI12_RXI12(VD);
extern VD FnVD_HwSrv_Exception_handleSCI12_TXI12(VD);
extern VD FnVD_HwSrv_Exception_handleSCI12_TEI12(VD);
extern VD FnVD_HwSrv_Exception_handleIEB_IEBINT(VD);


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
