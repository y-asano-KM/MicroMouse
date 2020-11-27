#if !defined(INCLUDED_hw_pph_intctrl_pac_h)
#define INCLUDED_hw_pph_intctrl_pac_h
/* ============================================================ */
/* ファイル名 : hw_pph_intctrl_pac.h                            */
/* 機能       : 割り込み制御処理                                */
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
/* 割り込みベクタ番号 */
typedef enum {
  CEN_HwPph_IntCtrl_VecId_Brk                     = 0,
  CEN_HwPph_IntCtrl_VecId_Trap01                  = 1,
  CEN_HwPph_IntCtrl_VecId_Trap02                  = 2,
  CEN_HwPph_IntCtrl_VecId_Trap03                  = 3,
  CEN_HwPph_IntCtrl_VecId_Trap04                  = 4,
  CEN_HwPph_IntCtrl_VecId_Trap05                  = 5,
  CEN_HwPph_IntCtrl_VecId_Trap06                  = 6,
  CEN_HwPph_IntCtrl_VecId_Trap07                  = 7,
  CEN_HwPph_IntCtrl_VecId_Trap08                  = 8,
  CEN_HwPph_IntCtrl_VecId_Trap09                  = 9,
  CEN_HwPph_IntCtrl_VecId_Trap10                  = 10,
  CEN_HwPph_IntCtrl_VecId_Trap11                  = 11,
  CEN_HwPph_IntCtrl_VecId_Trap12                  = 12,
  CEN_HwPph_IntCtrl_VecId_Trap13                  = 13,
  CEN_HwPph_IntCtrl_VecId_Trap14                  = 14,
  CEN_HwPph_IntCtrl_VecId_Trap15                  = 15,
  CEN_HwPph_IntCtrl_VecId_BSC_BUSERR              = 16,
  /* #017:予約 */
  /* #018:予約 */
  /* #019:予約 */
  /* #020:予約 */
  CEN_HwPph_IntCtrl_VecId_FCU_FIFERR              = 21,
  /* #022:予約 */
  CEN_HwPph_IntCtrl_VecId_FCU_FRDYI               = 23,
  /* #024:予約 */
  /* #025:予約 */
  /* #026:予約 */
  CEN_HwPph_IntCtrl_VecId_ICU_SWINT               = 27,
  CEN_HwPph_IntCtrl_VecId_CMT0_CMI0               = 28,
  CEN_HwPph_IntCtrl_VecId_CMT1_CMI1               = 29,
  CEN_HwPph_IntCtrl_VecId_CMT2_CMI2               = 30,
  CEN_HwPph_IntCtrl_VecId_CMT3_CMI3               = 31,
  CEN_HwPph_IntCtrl_VecId_Ether_EINT              = 32,
  CEN_HwPph_IntCtrl_VecId_USB0_D0FIFO0            = 33,
  CEN_HwPph_IntCtrl_VecId_USB0_D1FIFO0            = 34,
  CEN_HwPph_IntCtrl_VecId_USB0_USBI0              = 35,
  CEN_HwPph_IntCtrl_VecId_USB1_D0FIFO1            = 36,
  CEN_HwPph_IntCtrl_VecId_USB1_D1FIFO1            = 37,
  CEN_HwPph_IntCtrl_VecId_USB1_USBI1              = 38,
  CEN_HwPph_IntCtrl_VecId_RSPI0_SPRI0             = 39,
  CEN_HwPph_IntCtrl_VecId_RSPI0_SPTI0             = 40,
  CEN_HwPph_IntCtrl_VecId_RSPI0_SPII0             = 41,
  CEN_HwPph_IntCtrl_VecId_RSPI1_SPRI1             = 42,
  CEN_HwPph_IntCtrl_VecId_RSPI1_SPTI1             = 43,
  CEN_HwPph_IntCtrl_VecId_RSPI1_SPII1             = 44,
  CEN_HwPph_IntCtrl_VecId_RSPI2_SPRI2             = 45,
  CEN_HwPph_IntCtrl_VecId_RSPI2_SPTI2             = 46,
  CEN_HwPph_IntCtrl_VecId_RSPI2_SPII2             = 47,
  CEN_HwPph_IntCtrl_VecId_CAN0_RXF0               = 48,
  CEN_HwPph_IntCtrl_VecId_CAN0_TXF0               = 49,
  CEN_HwPph_IntCtrl_VecId_CAN0_RXM0               = 50,
  CEN_HwPph_IntCtrl_VecId_CAN0_TXM0               = 51,
  CEN_HwPph_IntCtrl_VecId_CAN1_RXF1               = 52,
  CEN_HwPph_IntCtrl_VecId_CAN1_TXF1               = 53,
  CEN_HwPph_IntCtrl_VecId_CAN1_RXM1               = 54,
  CEN_HwPph_IntCtrl_VecId_CAN1_TXM1               = 55,
  CEN_HwPph_IntCtrl_VecId_CAN2_RXF2               = 56,
  CEN_HwPph_IntCtrl_VecId_CAN2_TXF2               = 57,
  CEN_HwPph_IntCtrl_VecId_CAN2_RXM2               = 58,
  CEN_HwPph_IntCtrl_VecId_CAN2_TXM2               = 59,
  /* #060:予約 */
  /* #061:予約 */
  CEN_HwPph_IntCtrl_VecId_RTC_CUP                 = 62,
  /* #063:予約 */
  CEN_HwPph_IntCtrl_VecId_ICU_IRQ0                = 64,
  CEN_HwPph_IntCtrl_VecId_ICU_IRQ1                = 65,
  CEN_HwPph_IntCtrl_VecId_ICU_IRQ2                = 66,
  CEN_HwPph_IntCtrl_VecId_ICU_IRQ3                = 67,
  CEN_HwPph_IntCtrl_VecId_ICU_IRQ4                = 68,
  CEN_HwPph_IntCtrl_VecId_ICU_IRQ5                = 69,
  CEN_HwPph_IntCtrl_VecId_ICU_IRQ6                = 70,
  CEN_HwPph_IntCtrl_VecId_ICU_IRQ7                = 71,
  CEN_HwPph_IntCtrl_VecId_ICU_IRQ8                = 72,
  CEN_HwPph_IntCtrl_VecId_ICU_IRQ9                = 73,
  CEN_HwPph_IntCtrl_VecId_ICU_IRQ10               = 74,
  CEN_HwPph_IntCtrl_VecId_ICU_IRQ11               = 75,
  CEN_HwPph_IntCtrl_VecId_ICU_IRQ12               = 76,
  CEN_HwPph_IntCtrl_VecId_ICU_IRQ13               = 77,
  CEN_HwPph_IntCtrl_VecId_ICU_IRQ14               = 78,
  CEN_HwPph_IntCtrl_VecId_ICU_IRQ15               = 79,
  /* #080:予約 */
  /* #081:予約 */
  /* #082:予約 */
  /* #083:予約 */
  /* #084:予約 */
  /* #085:予約 */
  /* #086:予約 */
  /* #087:予約 */
  /* #088:予約 */
  /* #089:予約 */
  CEN_HwPph_IntCtrl_VecId_USB_USBR0               = 90,
  CEN_HwPph_IntCtrl_VecId_USB_USBR1               = 91,
  CEN_HwPph_IntCtrl_VecId_RTC_ALM                 = 92,
  CEN_HwPph_IntCtrl_VecId_RTC_PRD                 = 93,
  /* #094:予約 */
  /* #095:予約 */
  /* #096:予約 */
  /* #097:予約 */
  CEN_HwPph_IntCtrl_VecId_AD_ADI0                 = 98,
  /* #099:予約 */
  /* #100:予約 */
  /* #101:予約 */
  CEN_HwPph_IntCtrl_VecId_S12AD_S12ADI0           = 102,
  /* #103:予約 */
  /* #104:予約 */
  /* #105:予約 */
  CEN_HwPph_IntCtrl_VecId_ICU_GROUP0              = 106,
  CEN_HwPph_IntCtrl_VecId_ICU_GROUP1              = 107,
  CEN_HwPph_IntCtrl_VecId_ICU_GROUP2              = 108,
  CEN_HwPph_IntCtrl_VecId_ICU_GROUP3              = 109,
  CEN_HwPph_IntCtrl_VecId_ICU_GROUP4              = 110,
  CEN_HwPph_IntCtrl_VecId_ICU_GROUP5              = 111,
  CEN_HwPph_IntCtrl_VecId_ICU_GROUP6              = 112,
  /* #113:予約 */
  CEN_HwPph_IntCtrl_VecId_ICU_GROUP12             = 114,
  /* #115:予約 */
  /* #116:予約 */
  /* #117:予約 */
  /* #118:予約 */
  /* #119:予約 */
  /* #120:予約 */
  /* #121:予約 */
  CEN_HwPph_IntCtrl_VecId_SCI12_SCIX0             = 122,
  CEN_HwPph_IntCtrl_VecId_SCI12_SCIX1             = 123,
  CEN_HwPph_IntCtrl_VecId_SCI12_SCIX2             = 124,
  CEN_HwPph_IntCtrl_VecId_SCI12_SCIX3             = 125,
  CEN_HwPph_IntCtrl_VecId_TPU0_TGI0A              = 126,
  CEN_HwPph_IntCtrl_VecId_TPU0_TGI0B              = 127,
  CEN_HwPph_IntCtrl_VecId_TPU0_TGI0C              = 128,
  CEN_HwPph_IntCtrl_VecId_TPU0_TGI0D              = 129,
  CEN_HwPph_IntCtrl_VecId_TPU1_TGI1A              = 130,
  CEN_HwPph_IntCtrl_VecId_TPU1_TGI1B              = 131,
  CEN_HwPph_IntCtrl_VecId_TPU2_TGI2A              = 132,
  CEN_HwPph_IntCtrl_VecId_TPU2_TGI2B              = 133,
  CEN_HwPph_IntCtrl_VecId_TPU3_TGI3A              = 134,
  CEN_HwPph_IntCtrl_VecId_TPU3_TGI3B              = 135,
  CEN_HwPph_IntCtrl_VecId_TPU3_TGI3C              = 136,
  CEN_HwPph_IntCtrl_VecId_TPU3_TGI3D              = 137,
  CEN_HwPph_IntCtrl_VecId_TPU4_TGI4A              = 138,
  CEN_HwPph_IntCtrl_VecId_TPU4_TGI4B              = 139,
  CEN_HwPph_IntCtrl_VecId_TPU5_TGI5A              = 140,
  CEN_HwPph_IntCtrl_VecId_TPU5_TGI5B              = 141,
  CEN_HwPph_IntCtrl_VecId_TPU6_TGI6A_MTU0_TGIA0   = 142,
  CEN_HwPph_IntCtrl_VecId_TPU6_TGI6B_MTU0_TGIB0   = 143,
  CEN_HwPph_IntCtrl_VecId_TPU6_TGI6C_MTU0_TGIC0   = 144,
  CEN_HwPph_IntCtrl_VecId_TPU6_TGI6D_MTU0_TGID0   = 145,
  CEN_HwPph_IntCtrl_VecId_MTU0_TGIE0              = 146,
  CEN_HwPph_IntCtrl_VecId_MTU0_TGIF0              = 147,
  CEN_HwPph_IntCtrl_VecId_TPU7_TGI7A_MTU1_TGIA1   = 148,
  CEN_HwPph_IntCtrl_VecId_TPU7_TGI7B_MTU1_TGIB1   = 149,
  CEN_HwPph_IntCtrl_VecId_TPU8_TGI8A_MTU2_TGIA2   = 150,
  CEN_HwPph_IntCtrl_VecId_TPU8_TGI8B_MTU2_TGIB2   = 151,
  CEN_HwPph_IntCtrl_VecId_TPU9_TGI9A_MTU3_TGIA3   = 151,
  CEN_HwPph_IntCtrl_VecId_TPU9_TGI9B_MTU3_TGIB3   = 153,
  CEN_HwPph_IntCtrl_VecId_TPU9_TGI9C_MTU3_TGIC3   = 154,
  CEN_HwPph_IntCtrl_VecId_TPU9_TGI9D_MTU3_TGID3   = 155,
  CEN_HwPph_IntCtrl_VecId_TPU10_TGI10A_MTU4_TGIA4 = 156,
  CEN_HwPph_IntCtrl_VecId_TPU10_TGI10B_MTU4_TGIB4 = 157,
  CEN_HwPph_IntCtrl_VecId_MTU4_TGIC4              = 158,
  CEN_HwPph_IntCtrl_VecId_MTU4_TGID4              = 159,
  CEN_HwPph_IntCtrl_VecId_MTU4_TGIV4              = 160,
  CEN_HwPph_IntCtrl_VecId_MTU5_TGIU5              = 161,
  CEN_HwPph_IntCtrl_VecId_MTU5_TGIV5              = 162,
  CEN_HwPph_IntCtrl_VecId_MTU5_TGIW5              = 163,
  CEN_HwPph_IntCtrl_VecId_TPU11_TGI11A            = 164,
  CEN_HwPph_IntCtrl_VecId_TPU11_TGI11B            = 165,
  CEN_HwPph_IntCtrl_VecId_POE_OEI1                = 166,
  CEN_HwPph_IntCtrl_VecId_POE_OEI2                = 167,
  /* #168:予約 */
  /* #169:予約 */
  CEN_HwPph_IntCtrl_VecId_TMR0_CMIA0              = 170,
  CEN_HwPph_IntCtrl_VecId_TMR0_CMIB0              = 171,
  CEN_HwPph_IntCtrl_VecId_TMR0_OVI0               = 172,
  CEN_HwPph_IntCtrl_VecId_TMR1_CMIA1              = 173,
  CEN_HwPph_IntCtrl_VecId_TMR1_CMIB1              = 174,
  CEN_HwPph_IntCtrl_VecId_TMR1_OVI1               = 175,
  CEN_HwPph_IntCtrl_VecId_TMR2_CMIA2              = 176,
  CEN_HwPph_IntCtrl_VecId_TMR2_CMIB2              = 177,
  CEN_HwPph_IntCtrl_VecId_TMR2_OVI2               = 178,
  CEN_HwPph_IntCtrl_VecId_TMR3_CMIA3              = 179,
  CEN_HwPph_IntCtrl_VecId_TMR3_CMIB3              = 180,
  CEN_HwPph_IntCtrl_VecId_TMR3_OVI3               = 181,
  CEN_HwPph_IntCtrl_VecId_RIIC0_EEI0              = 182,
  CEN_HwPph_IntCtrl_VecId_RIIC0_RXI0              = 183,
  CEN_HwPph_IntCtrl_VecId_RIIC0_TXI0              = 184,
  CEN_HwPph_IntCtrl_VecId_RIIC0_TEI0              = 185,
  CEN_HwPph_IntCtrl_VecId_RIIC1_EEI1              = 186,
  CEN_HwPph_IntCtrl_VecId_RIIC1_RXI1              = 187,
  CEN_HwPph_IntCtrl_VecId_RIIC1_TXI1              = 188,
  CEN_HwPph_IntCtrl_VecId_RIIC1_TEI1              = 189,
  CEN_HwPph_IntCtrl_VecId_RIIC2_EEI2              = 190,
  CEN_HwPph_IntCtrl_VecId_RIIC2_RXI2              = 191,
  CEN_HwPph_IntCtrl_VecId_RIIC2_TXI2              = 192,
  CEN_HwPph_IntCtrl_VecId_RIIC2_TEI2              = 193,
  CEN_HwPph_IntCtrl_VecId_RIIC3_EEI3              = 194,
  CEN_HwPph_IntCtrl_VecId_RIIC3_RXI3              = 195,
  CEN_HwPph_IntCtrl_VecId_RIIC3_TXI3              = 195,
  CEN_HwPph_IntCtrl_VecId_RIIC3_TEI3              = 197,
  CEN_HwPph_IntCtrl_VecId_DMAC_DMAC0I             = 198,
  CEN_HwPph_IntCtrl_VecId_DMAC_DMAC1I             = 199,
  CEN_HwPph_IntCtrl_VecId_DMAC_DMAC2I             = 200,
  CEN_HwPph_IntCtrl_VecId_DMAC_DMAC3I             = 201,
  CEN_HwPph_IntCtrl_VecId_EXDMAC_EXDMAC0I         = 202,
  CEN_HwPph_IntCtrl_VecId_EXDMAC_EXDMAC1I         = 203,
  /* #204:予約 */
  /* #205:予約 */
  CEN_HwPph_IntCtrl_VecId_DEU_DEU0                = 206,
  CEN_HwPph_IntCtrl_VecId_DEU_DEU1                = 207,
  CEN_HwPph_IntCtrl_VecId_PDC_PCDFI               = 208,
  CEN_HwPph_IntCtrl_VecId_PDC_PCFEI               = 209,
  CEN_HwPph_IntCtrl_VecId_PDC_PCERI               = 210,
  /* #211:予約 */
  /* #212:予約 */
  /* #213:予約 */
  CEN_HwPph_IntCtrl_VecId_SCI0_RXI0               = 214,
  CEN_HwPph_IntCtrl_VecId_SCI0_TXI0               = 215,
  CEN_HwPph_IntCtrl_VecId_SCI0_TEI0               = 216,
  CEN_HwPph_IntCtrl_VecId_SCI1_RXI1               = 217,
  CEN_HwPph_IntCtrl_VecId_SCI1_TXI1               = 218,
  CEN_HwPph_IntCtrl_VecId_SCI1_TEI1               = 219,
  CEN_HwPph_IntCtrl_VecId_SCI2_RXI2               = 220,
  CEN_HwPph_IntCtrl_VecId_SCI2_TXI2               = 221,
  CEN_HwPph_IntCtrl_VecId_SCI2_TEI2               = 222,
  CEN_HwPph_IntCtrl_VecId_SCI3_RXI3               = 223,
  CEN_HwPph_IntCtrl_VecId_SCI3_TXI3               = 224,
  CEN_HwPph_IntCtrl_VecId_SCI3_TEI3               = 225,
  CEN_HwPph_IntCtrl_VecId_SCI4_RXI4               = 226,
  CEN_HwPph_IntCtrl_VecId_SCI4_TXI4               = 227,
  CEN_HwPph_IntCtrl_VecId_SCI4_TEI4               = 228,
  CEN_HwPph_IntCtrl_VecId_SCI5_RXI5               = 229,
  CEN_HwPph_IntCtrl_VecId_SCI5_TXI5               = 230,
  CEN_HwPph_IntCtrl_VecId_SCI5_TEI5               = 231,
  CEN_HwPph_IntCtrl_VecId_SCI6_RXI6               = 232,
  CEN_HwPph_IntCtrl_VecId_SCI6_TXI6               = 233,
  CEN_HwPph_IntCtrl_VecId_SCI6_TEI6               = 234,
  CEN_HwPph_IntCtrl_VecId_SCI7_RXI7               = 235,
  CEN_HwPph_IntCtrl_VecId_SCI7_TXI7               = 236,
  CEN_HwPph_IntCtrl_VecId_SCI7_TEI7               = 237,
  CEN_HwPph_IntCtrl_VecId_SCI8_RXI8               = 238,
  CEN_HwPph_IntCtrl_VecId_SCI8_TXI8               = 239,
  CEN_HwPph_IntCtrl_VecId_SCI8_TEI8               = 240,
  CEN_HwPph_IntCtrl_VecId_SCI9_RXI9               = 241,
  CEN_HwPph_IntCtrl_VecId_SCI9_TXI9               = 242,
  CEN_HwPph_IntCtrl_VecId_SCI9_TEI9               = 243,
  CEN_HwPph_IntCtrl_VecId_SCI10_RXI10             = 244,
  CEN_HwPph_IntCtrl_VecId_SCI10_TXI10             = 245,
  CEN_HwPph_IntCtrl_VecId_SCI10_TEI10             = 246,
  CEN_HwPph_IntCtrl_VecId_SCI11_RXI11             = 247,
  CEN_HwPph_IntCtrl_VecId_SCI11_TXI11             = 248,
  CEN_HwPph_IntCtrl_VecId_SCI11_TEI11             = 249,
  CEN_HwPph_IntCtrl_VecId_SCI12_RXI12             = 250,
  CEN_HwPph_IntCtrl_VecId_SCI12_TXI12             = 251,
  CEN_HwPph_IntCtrl_VecId_SCI12_TEI12             = 252,
  CEN_HwPph_IntCtrl_VecId_IEB_IEBINT              = 253
  /* #254:予約 */
  /* #255:予約 */
} EN_HwPph_IntCtrl_VecId;

/* 割り込み優先度 */
typedef enum {
/* 0:割り込み禁止, 1:優先度低, ..., 15:優先度高 */
  CEN_HwPph_IntCtrl_Priority_DibInt = 0,
  CEN_HwPph_IntCtrl_Priority_01_Min,
  CEN_HwPph_IntCtrl_Priority_02,
  CEN_HwPph_IntCtrl_Priority_03,
  CEN_HwPph_IntCtrl_Priority_04,
  CEN_HwPph_IntCtrl_Priority_05,
  CEN_HwPph_IntCtrl_Priority_06,
  CEN_HwPph_IntCtrl_Priority_08,
  CEN_HwPph_IntCtrl_Priority_09,
  CEN_HwPph_IntCtrl_Priority_10,
  CEN_HwPph_IntCtrl_Priority_11,
  CEN_HwPph_IntCtrl_Priority_12,
  CEN_HwPph_IntCtrl_Priority_13,
  CEN_HwPph_IntCtrl_Priority_14,
  CEN_HwPph_IntCtrl_Priority_15_Max
} EN_HwPph_IntCtrl_Priority;


/* ============================================================ */
/* 関数プロトタイプ宣言(extern)                                 */
/* ============================================================ */
extern VD FnVD_HwPph_IntCtrl_initForStartup(VD);
extern VD FnVD_HwPph_IntCtrl_initToKill(VD);
extern VD FnVD_HwPph_IntCtrl_clrIntReq(VD);
extern VD FnVD_HwPph_IntCtrl_enbMsk(EN_HwPph_IntCtrl_VecId tenId, U1 tu1Msk);
extern VD FnVD_HwPph_IntCtrl_setPriority(EN_HwPph_IntCtrl_VecId tenId, EN_HwPph_IntCtrl_Priority tenP);


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
