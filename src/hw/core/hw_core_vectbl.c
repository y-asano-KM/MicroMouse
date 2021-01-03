/* ============================================================ */
/* ファイル名 : hw_core_vectbl.c                                */
/* 機能       : ベクタテーブル定義                              */
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
#include "hw_core_startup_pac.h"
#include "hw_core_exception_pac.h"

/* 本体 */
#include "hw_core_vectbl_pac.h"


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
#pragma section C C$VECT
VD (* const CPFnVD_HwCore_VecTbl[CU2_HwCore_VecTbl_Size])(VD) = {
  FnVD_HwCore_Exception_handleBrk,                        /* 000 : 無条件トラップ専用(BRK) */
  FnVD_HwCore_Exception_handleTrap,                       /* 001 : 無条件トラップ専用      */
  FnVD_HwCore_Exception_handleTrap,                       /* 002 : 無条件トラップ専用      */
  FnVD_HwCore_Exception_handleTrap,                       /* 003 : 無条件トラップ専用      */
  FnVD_HwCore_Exception_handleTrap,                       /* 004 : 無条件トラップ専用      */
  FnVD_HwCore_Exception_handleTrap,                       /* 005 : 無条件トラップ専用      */
  FnVD_HwCore_Exception_handleTrap,                       /* 006 : 無条件トラップ専用      */
  FnVD_HwCore_Exception_handleTrap,                       /* 007 : 無条件トラップ専用      */
  FnVD_HwCore_Exception_handleTrap,                       /* 008 : 無条件トラップ専用      */
  FnVD_HwCore_Exception_handleTrap,                       /* 009 : 無条件トラップ専用      */

  FnVD_HwCore_Exception_handleTrap,                       /* 010 : 無条件トラップ専用      */
  FnVD_HwCore_Exception_handleTrap,                       /* 011 : 無条件トラップ専用      */
  FnVD_HwCore_Exception_handleTrap,                       /* 012 : 無条件トラップ専用      */
  FnVD_HwCore_Exception_handleTrap,                       /* 013 : 無条件トラップ専用      */
  FnVD_HwCore_Exception_handleTrap,                       /* 014 : 無条件トラップ専用      */
  FnVD_HwCore_Exception_handleTrap,                       /* 015 : 無条件トラップ専用      */
  FnVD_HwCore_Exception_handleBSC_BUSERR,                 /* 016 : BSC.BUSERR              */
  FnVD_HwCore_Exception_handleReserved,                   /* 017 : 予約                    */
  FnVD_HwCore_Exception_handleReserved,                   /* 018 : 予約                    */
  FnVD_HwCore_Exception_handleReserved,                   /* 019 : 予約                    */

  FnVD_HwCore_Exception_handleReserved,                   /* 020 : 予約                    */
  FnVD_HwCore_Exception_handleFCU_FIFERR,                 /* 021 : FCU.FIFERR              */
  FnVD_HwCore_Exception_handleReserved,                   /* 022 : 予約                    */
  FnVD_HwCore_Exception_handleFCU_FRDYI,                  /* 023 : FCU.FRDIY               */
  FnVD_HwCore_Exception_handleReserved,                   /* 024 : 予約                    */
  FnVD_HwCore_Exception_handleReserved,                   /* 025 : 予約                    */
  FnVD_HwCore_Exception_handleReserved,                   /* 026 : 予約                    */
  FnVD_HwCore_Exception_handleICU_SWINT,                  /* 027 : ICU.SWINT               */
  FnVD_HwCore_Exception_handleCMT0_CMI0,                  /* 028 : CMT0.CMI0               */
  FnVD_HwCore_Exception_handleCMT1_CMI1,                  /* 029 : CMT1.CMI1               */

  FnVD_HwCore_Exception_handleCMT2_CMI2,                  /* 030 : CMT2.CMI2               */
  FnVD_HwCore_Exception_handleCMT3_CMI3,                  /* 031 : CMT3.CMI3               */
  FnVD_HwCore_Exception_handleETHER_EINT,                 /* 032 : Ether.EINT              */
  FnVD_HwCore_Exception_handleUSB0_D0FIFO0,               /* 033 : USB0.D0FIFO0            */
  FnVD_HwCore_Exception_handleUSB0_D1FIFO0,               /* 034 : USB0.D1FIFO0            */
  FnVD_HwCore_Exception_handleUSB0_USBI0,                 /* 035 : USB0.USBI0              */
  FnVD_HwCore_Exception_handleUSB1_D0FIFO1,               /* 036 : USB1.D0FIFO1            */
  FnVD_HwCore_Exception_handleUSB1_D1FIFO1,               /* 037 : USB1.D1FIFO1            */
  FnVD_HwCore_Exception_handleUSB1_USBI1,                 /* 038 : USB1.USBI1              */
  FnVD_HwCore_Exception_handleRSPI0_SPRI0,                /* 039 : RSPI0.SPRI0             */

  FnVD_HwCore_Exception_handleRSPI0_SPTI0,                /* 040 : RSPI0.SPTI0             */
  FnVD_HwCore_Exception_handleRSPI0_SPII0,                /* 041 : RSPI0.SPII0             */
  FnVD_HwCore_Exception_handleRSPI1_SPRI1,                /* 042 : RSPI1.SPRI1             */
  FnVD_HwCore_Exception_handleRSPI1_SPTI1,                /* 043 : RSPI1.SPTI1             */
  FnVD_HwCore_Exception_handleRSPI1_SPII1,                /* 044 : RSPI1.SPII1             */
  FnVD_HwCore_Exception_handleRSPI2_SPRI2,                /* 045 : RSPI2.SPRI2             */
  FnVD_HwCore_Exception_handleRSPI2_SPTI2,                /* 046 : RSPI2.SPTI2             */
  FnVD_HwCore_Exception_handleRSPI2_SPII2,                /* 047 : RSPI2.SPII2             */
  FnVD_HwCore_Exception_handleCAN0_RXF0,                  /* 048 : CAN0.RXF0               */
  FnVD_HwCore_Exception_handleCAN0_TXF0,                  /* 049 : CAN0.TXF0               */

  FnVD_HwCore_Exception_handleCAN0_RXM0,                  /* 050 : CAN0.RXM0               */
  FnVD_HwCore_Exception_handleCAN0_TXM0,                  /* 051 : CAN0.TXM0               */
  FnVD_HwCore_Exception_handleCAN1_RXF1,                  /* 052 : CAN1.RXF1               */
  FnVD_HwCore_Exception_handleCAN1_TXF1,                  /* 053 : CAN1.TXF1               */
  FnVD_HwCore_Exception_handleCAN1_RXM1,                  /* 054 : CAN1.RXM1               */
  FnVD_HwCore_Exception_handleCAN1_TXM1,                  /* 055 : CAN1.TXM1               */
  FnVD_HwCore_Exception_handleCAN2_RXF2,                  /* 056 : CAN2.RXF2               */
  FnVD_HwCore_Exception_handleCAN2_TXF2,                  /* 057 : CAN2.TXF2               */
  FnVD_HwCore_Exception_handleCAN2_RXM2,                  /* 058 : CAN2.RXM2               */
  FnVD_HwCore_Exception_handleCAN2_TXM2,                  /* 059 : CAN2.TXM2               */

  FnVD_HwCore_Exception_handleReserved,                   /* 060 : 予約                    */
  FnVD_HwCore_Exception_handleReserved,                   /* 061 : 予約                    */
  FnVD_HwCore_Exception_handleRTC_CUP,                    /* 062 : RTC.CUP                 */
  FnVD_HwCore_Exception_handleReserved,                   /* 063 : 予約                    */
  FnVD_HwCore_Exception_handleICU_IRQ0,                   /* 064 : ICU.IRQ0                */
  FnVD_HwCore_Exception_handleICU_IRQ1,                   /* 065 : ICU.IRQ1                */
  FnVD_HwCore_Exception_handleICU_IRQ2,                   /* 066 : ICU.IRQ2                */
  FnVD_HwCore_Exception_handleICU_IRQ3,                   /* 067 : ICU.IRQ3                */
  FnVD_HwCore_Exception_handleICU_IRQ4,                   /* 068 : ICU.IRQ4                */
  FnVD_HwCore_Exception_handleICU_IRQ5,                   /* 069 : ICU.IRQ5                */

  FnVD_HwCore_Exception_handleICU_IRQ6,                   /* 070 : ICU.IRQ6                */
  FnVD_HwCore_Exception_handleICU_IRQ7,                   /* 071 : ICU.IRQ7                */
  FnVD_HwCore_Exception_handleICU_IRQ8,                   /* 072 : ICU.IRQ8                */
  FnVD_HwCore_Exception_handleICU_IRQ9,                   /* 073 : ICU.IRQ9                */
  FnVD_HwCore_Exception_handleICU_IRQ10,                  /* 074 : ICU.IRQ10               */
  FnVD_HwCore_Exception_handleICU_IRQ11,                  /* 075 : ICU.IRQ11               */
  FnVD_HwCore_Exception_handleICU_IRQ12,                  /* 076 : ICU.IRQ12               */
  FnVD_HwCore_Exception_handleICU_IRQ13,                  /* 077 : ICU.IRQ13               */
  FnVD_HwCore_Exception_handleICU_IRQ14,                  /* 078 : ICU.IRQ14               */
  FnVD_HwCore_Exception_handleICU_IRQ15,                  /* 079 : ICU.IRQ15               */

  FnVD_HwCore_Exception_handleReserved,                   /* 080 : 予約                    */
  FnVD_HwCore_Exception_handleReserved,                   /* 081 : 予約                    */
  FnVD_HwCore_Exception_handleReserved,                   /* 082 : 予約                    */
  FnVD_HwCore_Exception_handleReserved,                   /* 083 : 予約                    */
  FnVD_HwCore_Exception_handleReserved,                   /* 084 : 予約                    */
  FnVD_HwCore_Exception_handleReserved,                   /* 085 : 予約                    */
  FnVD_HwCore_Exception_handleReserved,                   /* 086 : 予約                    */
  FnVD_HwCore_Exception_handleReserved,                   /* 087 : 予約                    */
  FnVD_HwCore_Exception_handleReserved,                   /* 088 : 予約                    */
  FnVD_HwCore_Exception_handleReserved,                   /* 089 : 予約                    */

  FnVD_HwCore_Exception_handleUSB_USBR0,                  /* 090 : USB.USBR0               */
  FnVD_HwCore_Exception_handleUSB_USBR1,                  /* 091 : USB.USBR1               */
  FnVD_HwCore_Exception_handleRTC_ALM,                    /* 092 : RTC.ALM                 */
  FnVD_HwCore_Exception_handleRTC_PRD,                    /* 093 : RTC.PRD                 */
  FnVD_HwCore_Exception_handleReserved,                   /* 094 : 予約                    */
  FnVD_HwCore_Exception_handleReserved,                   /* 095 : 予約                    */
  FnVD_HwCore_Exception_handleReserved,                   /* 096 : 予約                    */
  FnVD_HwCore_Exception_handleReserved,                   /* 097 : 予約                    */
  FnVD_HwCore_Exception_handleAD_ADI0,                    /* 098 : AD.ADI0                 */
  FnVD_HwCore_Exception_handleReserved,                   /* 099 : 予約                    */

  FnVD_HwCore_Exception_handleReserved,                   /* 100 : 予約                    */
  FnVD_HwCore_Exception_handleReserved,                   /* 101 : 予約                    */
  FnVD_HwCore_Exception_handleS12AD_S12ADI0,              /* 102 : S12AD.S12ADI0           */
  FnVD_HwCore_Exception_handleReserved,                   /* 103 : 予約                    */
  FnVD_HwCore_Exception_handleReserved,                   /* 104 : 予約                    */
  FnVD_HwCore_Exception_handleReserved,                   /* 105 : 予約                    */
  FnVD_HwCore_Exception_handleICU_GROUP0,                 /* 106 : ICU.GROUP0              */
  FnVD_HwCore_Exception_handleICU_GROUP1,                 /* 107 : ICU.GROUP1              */
  FnVD_HwCore_Exception_handleICU_GROUP2,                 /* 108 : ICU.GROUP2              */
  FnVD_HwCore_Exception_handleICU_GROUP3,                 /* 109 : ICU.GROUP3              */

  FnVD_HwCore_Exception_handleICU_GROUP4,                 /* 110 : ICU.GROUP4              */
  FnVD_HwCore_Exception_handleICU_GROUP5,                 /* 111 : ICU.GROUP5              */
  FnVD_HwCore_Exception_handleICU_GROUP6,                 /* 112 : ICU.GROUP6              */
  FnVD_HwCore_Exception_handleReserved,                   /* 113 : 予約                    */
  FnVD_HwCore_Exception_handleICU_GROUP12,                /* 114 : ICU.GROUP12             */
  FnVD_HwCore_Exception_handleReserved,                   /* 115 : 予約                    */
  FnVD_HwCore_Exception_handleReserved,                   /* 116 : 予約                    */
  FnVD_HwCore_Exception_handleReserved,                   /* 117 : 予約                    */
  FnVD_HwCore_Exception_handleReserved,                   /* 118 : 予約                    */
  FnVD_HwCore_Exception_handleReserved,                   /* 119 : 予約                    */

  FnVD_HwCore_Exception_handleReserved,                   /* 120 : 予約                    */
  FnVD_HwCore_Exception_handleReserved,                   /* 121 : 予約                    */
  FnVD_HwCore_Exception_handleSCI12_SCIX0,                /* 122 : SCI12.SCIX0             */
  FnVD_HwCore_Exception_handleSCI12_SCIX1,                /* 123 : SCI12.SCIX1             */
  FnVD_HwCore_Exception_handleSCI12_SCIX2,                /* 124 : SCI12.SCIX2             */
  FnVD_HwCore_Exception_handleSCI12_SCIX3,                /* 125 : SCI12.SCIX3             */
  FnVD_HwCore_Exception_handleTPU0_TGI0A,                 /* 126 : TPU0.TGI0A              */
  FnVD_HwCore_Exception_handleTPU0_TGI0B,                 /* 127 : TPU0.TGI0B              */
  FnVD_HwCore_Exception_handleTPU0_TGI0C,                 /* 128 : TPU0.TGI0C              */
  FnVD_HwCore_Exception_handleTPU0_TGI0D,                 /* 129 : TPU0.TGI0D              */

  FnVD_HwCore_Exception_handleTPU1_TGI1A,                 /* 130 : TPU1.TGI1A              */
  FnVD_HwCore_Exception_handleTPU1_TGI1B,                 /* 131 : TPU1.TGI1B              */
  FnVD_HwCore_Exception_handleTPU2_TGI2A,                 /* 132 : TPU2.TGI2A              */
  FnVD_HwCore_Exception_handleTPU2_TGI2B,                 /* 133 : TPU2.TGI2B              */
  FnVD_HwCore_Exception_handleTPU3_TGI3A,                 /* 134 : TPU3.TGI3A              */
  FnVD_HwCore_Exception_handleTPU3_TGI3B,                 /* 135 : TPU3.TGI3B              */
  FnVD_HwCore_Exception_handleTPU3_TGI3C,                 /* 136 : TPU3.TGI3C              */
  FnVD_HwCore_Exception_handleTPU3_TGI3D,                 /* 137 : TPU3.TGI3D              */
  FnVD_HwCore_Exception_handleTPU4_TGI4A,                 /* 138 : TPU4.TGI4A              */
  FnVD_HwCore_Exception_handleTPU4_TGI4B,                 /* 139 : TPU4.TGI4B              */

  FnVD_HwCore_Exception_handleTPU5_TGI5A,                 /* 140 : TPU5.TGI5A              */
  FnVD_HwCore_Exception_handleTPU5_TGI5B,                 /* 141 : TPU5.TGI5B              */
  FnVD_HwCore_Exception_handleTPU6_TGI6A_MTU0_TGIA0,      /* 142 : TPU6.TGI6A/MTU0.TGIA0   */
  FnVD_HwCore_Exception_handleTPU6_TGI6B_MTU0_TGIB0,      /* 143 : TPU6.TGI6B/MTU0.TGIB0   */
  FnVD_HwCore_Exception_handleTPU6_TGI6C_MTU0_TGIC0,      /* 144 : TPU6.TGI6C/MTU0.TGIC0   */
  FnVD_HwCore_Exception_handleTPU6_TGI6D_MTU0_TGID0,      /* 145 : TPU6.TGI6D/MTU0.TGID0   */
  FnVD_HwCore_Exception_handleMTU0_TGIE0,                 /* 146 : MTU0.TGIE0              */
  FnVD_HwCore_Exception_handleMTU0_TGIF0,                 /* 147 : MTU0.TGIF0              */
  FnVD_HwCore_Exception_handleTPU7_TGI7A_MTU1_TGIA1,      /* 148 : TPU7.TGI7A/MTU1.TGIA1   */
  FnVD_HwCore_Exception_handleTPU7_TGI7B_MTU1_TGIB1,      /* 149 : TPU7.TGI7B/MTU1.TGIB1   */

  FnVD_HwCore_Exception_handleTPU8_TGI8A_MTU2_TGIA2,      /* 150 : TPU8.TGI8A/MTU2.TGIA2   */
  FnVD_HwCore_Exception_handleTPU8_TGI8B_MTU2_TGIB2,      /* 151 : TPU8.TGI8B/MTU2.TGIB2   */
  FnVD_HwCore_Exception_handleTPU9_TGI9A_MTU3_TGIA3,      /* 152 : TPU9.TGI9A/MTU3.TGIA3   */
  FnVD_HwCore_Exception_handleTPU9_TGI9B_MTU3_TGIB3,      /* 153 : TPU9.TGI9B/MTU3.TGIB3   */
  FnVD_HwCore_Exception_handleTPU9_TGI9C_MTU3_TGIC3,      /* 154 : TPU9.TGI9C/MTU3.TGIC3   */
  FnVD_HwCore_Exception_handleTPU9_TGI9D_MTU3_TGID3,      /* 155 : TPU9.TGI9D/MTU3.TGID3   */
  FnVD_HwCore_Exception_handleTPU10_TGI10A_MTU4_TGIA4,    /* 156 : TPU10.TGI10A/MTU4.TGIA4 */
  FnVD_HwCore_Exception_handleTPU10_TGI10B_MTU4_TGIB4,    /* 157 : TPU10.TGI10B/MTU4.TGIB4 */
  FnVD_HwCore_Exception_handleMTU4_TGIC4,                 /* 158 : MTU4.TGIC4              */
  FnVD_HwCore_Exception_handleMTU4_TGID4,                 /* 159 : MTU4.TGID4              */

  FnVD_HwCore_Exception_handleMTU4_TCIV4,                 /* 160 : MTU4.TGIV4              */
  FnVD_HwCore_Exception_handleMTU5_TGIU5,                 /* 161 : MTU5.TGIU5              */
  FnVD_HwCore_Exception_handleMTU5_TGIV5,                 /* 162 : MTU5.TGIV5              */
  FnVD_HwCore_Exception_handleMTU5_TGIW5,                 /* 163 : MTU5.TGIW5              */
  FnVD_HwCore_Exception_handleTPU11_TGI11A,               /* 164 : TPU11.TGI11A            */
  FnVD_HwCore_Exception_handleTPU11_TGI11B,               /* 165 : TPU11.TGI11B            */
  FnVD_HwCore_Exception_handlePOE_OEI1,                   /* 166 : POE.OEI0                */
  FnVD_HwCore_Exception_handlePOE_OEI2,                   /* 167 : POE.OEI1                */
  FnVD_HwCore_Exception_handleReserved,                   /* 168 : 予約                    */
  FnVD_HwCore_Exception_handleReserved,                   /* 169 : 予約                    */

  FnVD_HwCore_Exception_handleTMR0_CMIA0,                 /* 170 : TMR0.CMIA0              */
  FnVD_HwCore_Exception_handleTMR0_CMIB0,                 /* 171 : TMR0.CMIB0              */
  FnVD_HwCore_Exception_handleTMR0_OVI0,                  /* 172 : TMR0.OVI0               */
  FnVD_HwCore_Exception_handleTMR1_CMIA1,                 /* 173 : TMR1.CMIA1              */
  FnVD_HwCore_Exception_handleTMR1_CMIB1,                 /* 174 : TMR1.CMIB1              */
  FnVD_HwCore_Exception_handleTMR1_OVI1,                  /* 175 : TMR1.OVI1               */
  FnVD_HwCore_Exception_handleTMR2_CMIA2,                 /* 176 : TMR2.CMIA2              */
  FnVD_HwCore_Exception_handleTMR2_CMIB2,                 /* 177 : TMR2.CMIB2              */
  FnVD_HwCore_Exception_handleTMR2_OVI2,                  /* 178 : TMR2.OVI2               */
  FnVD_HwCore_Exception_handleTMR3_CMIA3,                 /* 179 : TMR3.CMIA3              */

  FnVD_HwCore_Exception_handleTMR3_CMIB3,                 /* 180 : TMR3.CMIB3              */
  FnVD_HwCore_Exception_handleTMR3_OVI3,                  /* 181 : TMR3.OVI3               */
  FnVD_HwCore_Exception_handleRIIC0_EEI0,                 /* 182 : RIIC0.EEI0              */
  FnVD_HwCore_Exception_handleRIIC0_RXI0,                 /* 183 : RIIC0.RXI0              */
  FnVD_HwCore_Exception_handleRIIC0_TXI0,                 /* 184 : RIIC0.TXI0              */
  FnVD_HwCore_Exception_handleRIIC0_TEI0,                 /* 185 : RIIC0.TEI0              */
  FnVD_HwCore_Exception_handleRIIC1_EEI1,                 /* 186 : RIIC1.EEI1              */
  FnVD_HwCore_Exception_handleRIIC1_RXI1,                 /* 187 : RIIC1.RXI1              */
  FnVD_HwCore_Exception_handleRIIC1_TXI1,                 /* 188 : RIIC1.TXI1              */
  FnVD_HwCore_Exception_handleRIIC1_TEI1,                 /* 189 : RIIC1.TEI1              */

  FnVD_HwCore_Exception_handleRIIC2_EEI2,                 /* 190 : RIIC2.EEI2              */
  FnVD_HwCore_Exception_handleRIIC2_RXI2,                 /* 191 : RIIC2.RXI2              */
  FnVD_HwCore_Exception_handleRIIC2_TXI2,                 /* 192 : RIIC2.TXI2              */
  FnVD_HwCore_Exception_handleRIIC2_TEI2,                 /* 193 : RIIC2.TEI2              */
  FnVD_HwCore_Exception_handleRIIC3_EEI3,                 /* 194 : RIIC3.EEI3              */
  FnVD_HwCore_Exception_handleRIIC3_RXI3,                 /* 195 : RIIC3.RXI3              */
  FnVD_HwCore_Exception_handleRIIC3_TXI3,                 /* 196 : RIIC3.TXI3              */
  FnVD_HwCore_Exception_handleRIIC3_TEI3,                 /* 197 : RIIC3.TEI3              */
  FnVD_HwCore_Exception_handleDMAC_DMAC0I,                /* 198 : DMAC.DMAC0I             */
  FnVD_HwCore_Exception_handleDMAC_DMAC1I,                /* 199 : DMAC.DMAC1I             */

  FnVD_HwCore_Exception_handleDMAC_DMAC2I,                /* 200 : DMAC.DMAC2I             */
  FnVD_HwCore_Exception_handleDMAC_DMAC3I,                /* 201 : DMAC.DMAC3I             */
  FnVD_HwCore_Exception_handleEXDMAC_EXDMAC0I,            /* 202 : EXDMAC.EXDMAC0I         */
  FnVD_HwCore_Exception_handleEXDMAC_EXDMAC1I,            /* 203 : EXDMAC.EXDMAC1I         */
  FnVD_HwCore_Exception_handleReserved,                   /* 204 : 予約                    */
  FnVD_HwCore_Exception_handleReserved,                   /* 205 : 予約                    */
  FnVD_HwCore_Exception_handleDEU_DEU0,                   /* 206 : DEU.DEU0                */
  FnVD_HwCore_Exception_handleDEU_DEU1,                   /* 207 : DEU.DEU1                */
  FnVD_HwCore_Exception_handlePDC_PCDFI,                  /* 208 : PDC.PCDFI               */
  FnVD_HwCore_Exception_handlePDC_PCFEI,                  /* 209 : PDC.PCFEI               */

  FnVD_HwCore_Exception_handlePDC_PCERI,                  /* 210 : PDC.PCERI               */
  FnVD_HwCore_Exception_handleReserved,                   /* 211 : 予約                    */
  FnVD_HwCore_Exception_handleReserved,                   /* 212 : 予約                    */
  FnVD_HwCore_Exception_handleReserved,                   /* 213 : 予約                    */
  FnVD_HwCore_Exception_handleSCI0_RXI0,                  /* 214 : SCI0.RXI0               */
  FnVD_HwCore_Exception_handleSCI0_TXI0,                  /* 215 : SCI0.TXI0               */
  FnVD_HwCore_Exception_handleSCI0_TEI0,                  /* 216 : SCI0.TEI0               */
  FnVD_HwCore_Exception_handleSCI1_RXI1,                  /* 217 : SCI1.RXI1               */
  FnVD_HwCore_Exception_handleSCI1_TXI1,                  /* 218 : SCI1.TXI1               */
  FnVD_HwCore_Exception_handleSCI1_TEI1,                  /* 219 : SCI1.TEI1               */

  FnVD_HwCore_Exception_handleSCI2_RXI2,                  /* 220 : SCI2.RXI2               */
  FnVD_HwCore_Exception_handleSCI2_TXI2,                  /* 221 : SCI2.TXI2               */
  FnVD_HwCore_Exception_handleSCI2_TEI2,                  /* 222 : SCI2.TEI2               */
  FnVD_HwCore_Exception_handleSCI3_RXI3,                  /* 223 : SCI3.RXI3               */
  FnVD_HwCore_Exception_handleSCI3_TXI3,                  /* 224 : SCI3.TXI3               */
  FnVD_HwCore_Exception_handleSCI3_TEI3,                  /* 225 : SCI3.TEI3               */
  FnVD_HwCore_Exception_handleSCI4_RXI4,                  /* 226 : SCI4.RXI4               */
  FnVD_HwCore_Exception_handleSCI4_TXI4,                  /* 227 : SCI4.TXI4               */
  FnVD_HwCore_Exception_handleSCI4_TEI4,                  /* 228 : SCI4.TEI4               */
  FnVD_HwCore_Exception_handleSCI5_RXI5,                  /* 229 : SCI5.RXI5               */

  FnVD_HwCore_Exception_handleSCI5_TXI5,                  /* 230 : SCI5.TXI5               */
  FnVD_HwCore_Exception_handleSCI5_TEI5,                  /* 231 : SCI5.TEI5               */
  FnVD_HwCore_Exception_handleSCI6_RXI6,                  /* 232 : SCI6.RXI6               */
  FnVD_HwCore_Exception_handleSCI6_TXI6,                  /* 233 : SCI6.TXI6               */
  FnVD_HwCore_Exception_handleSCI6_TEI6,                  /* 234 : SCI6.TEI6               */
  FnVD_HwCore_Exception_handleSCI7_RXI7,                  /* 235 : SCI7.RXI7               */
  FnVD_HwCore_Exception_handleSCI7_TXI7,                  /* 236 : SCI7.TXI7               */
  FnVD_HwCore_Exception_handleSCI7_TEI7,                  /* 237 : SCI7.TEI7               */
  FnVD_HwCore_Exception_handleSCI8_RXI8,                  /* 238 : SCI8.RXI8               */
  FnVD_HwCore_Exception_handleSCI8_TXI8,                  /* 239 : SCI8.TXI8               */

  FnVD_HwCore_Exception_handleSCI8_TEI8,                  /* 240 : SCI8.TEI8               */
  FnVD_HwCore_Exception_handleSCI9_RXI9,                  /* 241 : SCI9.RXI9               */
  FnVD_HwCore_Exception_handleSCI9_TXI9,                  /* 242 : SCI9.TXI9               */
  FnVD_HwCore_Exception_handleSCI9_TEI9,                  /* 243 : SCI9.TEI9               */
  FnVD_HwCore_Exception_handleSCI10_RXI10,                /* 244 : SCI10.RXI10             */
  FnVD_HwCore_Exception_handleSCI10_TXI10,                /* 245 : SCI10.TXI10             */
  FnVD_HwCore_Exception_handleSCI10_TEI10,                /* 246 : SCI10.TEI10             */
  FnVD_HwCore_Exception_handleSCI11_RXI11,                /* 247 : SCI11.RXI11             */
  FnVD_HwCore_Exception_handleSCI11_TXI11,                /* 248 : SCI11.TXI11             */
  FnVD_HwCore_Exception_handleSCI11_TEI11,                /* 249 : SCI11.TEI11             */

  FnVD_HwCore_Exception_handleSCI12_RXI12,                /* 250 : SCI12.RXI12             */
  FnVD_HwCore_Exception_handleSCI12_TXI12,                /* 251 : SCI12.TXI12             */
  FnVD_HwCore_Exception_handleSCI12_TEI12,                /* 252 : SCI12.TEI12             */
  FnVD_HwCore_Exception_handleIEB_IEBINT,                 /* 253 : IEB.IEBINT              */
  FnVD_HwCore_Exception_handleReserved,                   /* 254 : 予約                    */
  FnVD_HwCore_Exception_handleReserved                    /* 255 : 予約                    */
};

/* 固定ベクタテーブル */
#pragma section C FIXEDVECT
VD (* const CPFnVD_HwCore_VecTblFixed[CU1_HwCore_VecTbl_SizeFixed])(VD) = {
  FnVD_HwCore_Exception_handleSuperVisor,           /* 0xFFFFFFD0 : 特権命令例外           */
  FnVD_HwCore_Exception_handleAccess,               /* 0xFFFFFFD4 : アクセス例外           */
  FnVD_HwCore_Exception_handleReserved,             /* 0xFFFFFFD8 : 予約領域               */
  FnVD_HwCore_Exception_handleUndefined,            /* 0xFFFFFFDC : 未定義命令例外         */
  FnVD_HwCore_Exception_handleReserved,             /* 0xFFFFFFE0 : 予約領域               */
  FnVD_HwCore_Exception_handleFloatingPoint,        /* 0xFFFFFFE4 : 浮動小数点例外         */
  FnVD_HwCore_Exception_handleReserved,             /* 0xFFFFFFE8 : 予約領域               */
  FnVD_HwCore_Exception_handleReserved,             /* 0xFFFFFFEC : 予約領域               */
  FnVD_HwCore_Exception_handleReserved,             /* 0xFFFFFFF0 : 予約領域               */
  FnVD_HwCore_Exception_handleReserved,             /* 0xFFFFFFF4 : 予約領域               */
  FnVD_HwCore_Exception_handleNonMaskableInterrupt, /* 0xFFFFFFF8 : ノンマスカブル割り込み */
  FnVD_HwCore_Startup_handleResetException          /* 0xFFFFFFFC : リセット例外           */
};
/* セクションをユーザー定義に戻す */
#include "prj_cmn_section.h"


/* ============================================================ */
/* const変数定義(static)                                        */
/* ============================================================ */


/* ============================================================ */
/* 関数形式マクロ定義                                           */
/* ============================================================ */


/* ============================================================ */
/* 関数定義                                                     */
/* ============================================================ */
