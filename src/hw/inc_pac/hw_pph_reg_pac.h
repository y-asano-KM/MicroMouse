#if !defined(INCLUDED_hw_pph_reg_pac_h)
#define INCLUDED_hw_pph_reg_pac_h
/* ============================================================ */
/* ファイル名 : hw_pph_reg_pac.h                                */
/* 機能       : 周辺機能レジスタ定義                            */
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
/* 周辺I/Oレジスタはリトルエンディアンのため bit_order=rightとして下位ビットから順に記述する方式とする */
/* 周辺I/Oレジスタのアライメントはメンバーのデータサイズに応じるためunpackとする */
#pragma bit_order right
#pragma unpack
/* ----------------- */
/* SYSTEMモジュール0 */
/* ----------------- */
/* モジュールストップコントロールレジスタA */
typedef union {
  struct {
    U4 b1Fix0    :1;   /* RW:予約(1b固定) */
    U4 b1Fix1    :1;   /* RW:予約(1b固定) */
    U4 b1Fix2    :1;   /* RW:予約(1b固定) */
    U4 b1Fix3    :1;   /* RW:予約(1b固定) */
    U4 b1MSTPA4  :1;   /* RW:8ビットタイマ3、2(ユニット1)モジュールストップ設定ビット (TMR3,2) */
    U4 b1MSTPA5  :1;   /* RW:8ビットタイマ1、0(ユニット0)モジュールストップ設定ビット (TMR1,0) */
    U4 b1Fix6    :1;   /* RW:予約(1b固定) */
    U4 b1Fix7    :1;   /* RW:予約(1b固定) */
    U4 b1Fix8    :1;   /* RW:予約(1b固定) */
    U4 b1MSTPA9  :1;   /* RW:マルチファンクションタイマパルスユニット2モジュールストップ設定ビット (MTU0-5) */
    U4 b1MSTPA10 :1;   /* RW:プログラマブルパルスジェネレータ(ユニット1)モジュールストップ設定ビット (PPG1) */
    U4 b1MSTPA11 :1;   /* RW:プログラマブルパルスジェネレータ(ユニット0)モジュールストップ設定ビット (PPG0) */
    U4 b1MSTPA12 :1;   /* RW:16ビットタイマパルスユニット1(ユニット1)モジュールストップ設定ビット (TPU6-11) */
    U4 b1MSTPA13 :1;   /* RW:16ビットタイマパルスユニット0(ユニット0)モジュールストップ設定ビット (TPU0-5) */
    U4 b1MSTPA14 :1;   /* RW:コンペアマッチタイマ(ユニット1)モジュールストップ設定ビット (CMT2,3) */
    U4 b1MSTPA15 :1;   /* RW:コンペアマッチタイマ(ユニット0)モジュールストップ設定ビット (CMT0,1) */
    U4 b1Fix16   :1;   /* RW:予約(1b固定) */
    U4 b1MSTPA17 :1;   /* RW:12ビットA/Dコンバータモジュールストップ設定ビット (S12AD) */
    U4 b1Fix18   :1;   /* RW:予約(1b固定) */
    U4 b1MSTPA19 :1;   /* RW:D/Aコンバータモジュールストップ設定ビット (DA) */
    U4 b1Fix20   :1;   /* RW:予約(1b固定) */
    U4 b1Fix21   :1;   /* RW:予約(1b固定) */
    U4 b1Fix22   :1;   /* RW:予約(1b固定) */
    U4 b1MSTPA23 :1;   /* RW:10ビットA/Dコンバータモジュールストップ設定ビット (AD) */
    U4 b1MSTPA24 :1;   /* RW:モジュールストップA24設定ビット */
    U4 b1Fix25   :1;   /* RW:予約(1b固定) */
    U4 b1Fix26   :1;   /* RW:予約(1b固定) */
    U4 b1MSTPA27 :1;   /* RW:モジュールストップA27設定ビット */
    U4 b1MSTPA28 :1;   /* RW:DMAコントローラ/データトランスファコントローラモジュールストップ設定ビット (DMAC/DTC) */
    U4 b1MSTPA29 :1;   /* RW:EXDMAコントローラモジュールストップ設定ビット (EXDMAC) */
    U4 b1Fix30   :1;   /* RW:予約(1b固定) */
    U4 b1ACSE    :1;   /* RW:全モジュールクロックストップモード許可ビット */
  } stBit;
  U4 u4Val;
} ST_MSTPCRA;

/* モジュールストップコントロールレジスタB */
typedef union {
  struct {
    U4 b1MSTPB0  :1;   /* RW:CANモジュール0モジュールストップ設定ビット (CAN0) */
    U4 b1MSTPB1  :1;   /* RW:CANモジュール1モジュールストップ設定ビット (CAN1) */
    U4 b1MSTPB2  :1;   /* RW:CANモジュール2モジュールストップ設定ビット (CAN2) */
    U4 b1Fix3    :1;   /* RW:予約(1b固定) */
    U4 b1MSTPB4  :1;   /* RW:シリアルコミュニケーションインタフェースSCIdモジュールストップ設定ビット (SCI12) */
    U4 b1Fix5    :1;   /* RW:予約(1b固定) */
    U4 b1Fix6    :1;   /* RW:予約(1b固定) */
    U4 b1Fix7    :1;   /* RW:予約(1b固定) */
    U4 b1MSTPB8  :1;   /* RW:温度センサモジュールストップ設定ビット (温度センサ) */
    U4 b1Fix9    :1;   /* RW:予約(1b固定) */
    U4 b1Fix10   :1;   /* RW:予約(1b固定) */
    U4 b1Fix11   :1;   /* RW:予約(1b固定) */
    U4 b1Fix12   :1;   /* RW:予約(1b固定) */
    U4 b1Fix13   :1;   /* RW:予約(1b固定) */
    U4 b1Fix14   :1;   /* RW:予約(1b固定) */
    U4 b1MSTPB15 :1;   /* RW:イーサネットコントローラ用DMAコントローラモジュールストップ設定ビット (EDMAC) */
    U4 b1MSTPB16 :1;   /* RW:シリアルペリフェラルインタフェース1モジュールストップ設定ビット (RSPI1) */
    U4 b1MSTPB17 :1;   /* RW:シリアルペリフェラルインタフェース0モジュールストップ設定ビット (RSPI0) */
    U4 b1MSTPB18 :1;   /* RW:ユニバーサルシリアルバスインタフェース(ポート1)モジュールストップ設定ビット (USB1) */
    U4 b1MSTPB19 :1;   /* RW:ユニバーサルシリアルバスインタフェース(ポート0)モジュールストップ設定ビット (USB0) */
    U4 b1MSTPB20 :1;   /* RW:I2Cバスインタフェース1モジュールストップ設定ビット (RIIC1) */
    U4 b1MSTPB21 :1;   /* RW:I2Cバスインタフェース0モジュールストップ設定ビット (RIIC0) */
    U4 b1MSTPB22 :1;   /* RW:パラレルデータキャプチャユニットモジュールストップ設定ビット (PDC) */
    U4 b1MSTPB23 :1;   /* RW:CRC演算器モジュールストップ設定ビット (CRC) */
    U4 b1MSTPB24 :1;   /* RW:シリアルコミュニケーションインタフェース7モジュールストップ設定ビット (SCI7) */
    U4 b1MSTPB25 :1;   /* RW:シリアルコミュニケーションインタフェース6モジュールストップ設定ビット (SCI6) */
    U4 b1MSTPB26 :1;   /* RW:シリアルコミュニケーションインタフェース5モジュールストップ設定ビット (SCI5) */
    U4 b1MSTPB27 :1;   /* RW:シリアルコミュニケーションインタフェース4モジュールストップ設定ビット (SCI4) */
    U4 b1MSTPB28 :1;   /* RW:シリアルコミュニケーションインタフェース3モジュールストップ設定ビット (SCI3) */
    U4 b1MSTPB29 :1;   /* RW:シリアルコミュニケーションインタフェース2モジュールストップ設定ビット (SCI2) */
    U4 b1MSTPB30 :1;   /* RW:シリアルコミュニケーションインタフェース1モジュールストップ設定ビット (SCI1) */
    U4 b1MSTPB31 :1;   /* RW:シリアルコミュニケーションインタフェース0モジュールストップ設定ビット (SCI0) */
  } stBit;
  U4 u4Val;
} ST_MSTPCRB;

/* モジュールストップコントロールレジスタC */
typedef union {
  struct {
    U4 b1MSTPC0  :1;   /* RW:RAM0モジュールストップ設定ビット (RAM0) */
    U4 b1MSTPC1  :1;   /* RW:RAM1モジュールストップ設定ビット (RAM1) */
    U4 b1Dmy2    :1;   /* RW:予約 */
    U4 b1Dmy3    :1;   /* RW:予約 */
    U4 b1Dmy4    :1;   /* RW:予約 */
    U4 b1Dmy5    :1;   /* RW:予約 */
    U4 b1Dmy6    :1;   /* RW:予約 */
    U4 b1Dmy7    :1;   /* RW:予約 */
    U4 b1Dmy8    :1;   /* RW:予約 */
    U4 b1Dmy9    :1;   /* RW:予約 */
    U4 b1Dmy10   :1;   /* RW:予約 */
    U4 b1Dmy11   :1;   /* RW:予約 */
    U4 b1Dmy12   :1;   /* RW:予約 */
    U4 b1Dmy13   :1;   /* RW:予約 */
    U4 b1Dmy14   :1;   /* RW:予約 */
    U4 b1Dmy15   :1;   /* RW:予約 */
    U4 b1MSTPC16 :1;   /* RW:I2Cバスインタフェース3モジュールストップ設定ビット (RIIC3) */
    U4 b1MSTPC17 :1;   /* RW:I2Cバスインタフェース2モジュールストップ設定ビット (RIIC2) */
    U4 b1MSTPC18 :1;   /* RW:IEBUSモジュールストップ設定ビット (IEBUS) */
    U4 b1MSTPC19 :1;   /* RW:周波数測定機能モジュールストップ設定ビット (MCK) */
    U4 b1Fix20   :1;   /* RW:予約(1b固定) */
    U4 b1Fix21   :1;   /* RW:予約(1b固定) */
    U4 b1MSTPC22 :1;   /* RW:シリアルペリフェラルインタフェース2モジュールストップ設定ビット (RSPI2) */
    U4 b1Fix23   :1;   /* RW:予約(1b固定) */
    U4 b1MSTPC24 :1;   /* RW:シリアルコミュニケーションインタフェース11モジュールストップ設定ビット (SCI11) */
    U4 b1MSTPC25 :1;   /* RW:シリアルコミュニケーションインタフェース10モジュールストップ設定ビット (SCI10) */
    U4 b1MSTPC26 :1;   /* RW:シリアルコミュニケーションインタフェース9モジュールストップ設定ビット (SCI9) */
    U4 b1MSTPC27 :1;   /* RW:シリアルコミュニケーションインタフェース8モジュールストップ設定ビット (SCI8) */
    U4 b1Fix28   :1;   /* RW:予約(1b固定) */
    U4 b1Fix29   :1;   /* RW:予約(1b固定) */
    U4 b1Fix30   :1;   /* RW:予約(1b固定) */
    U4 b1Fix31   :1;   /* RW:予約(1b固定) */
  } stBit;
  U4 u4Val;
} ST_MSTPCRC;

/* モジュールストップコントロールレジスタD */
typedef union {
  struct {
    U4 b1Dmy0    :1;   /* RW:予約 */
    U4 b1Dmy1    :1;   /* RW:予約 */
    U4 b1Dmy2    :1;   /* RW:予約 */
    U4 b1Dmy3    :1;   /* RW:予約 */
    U4 b1Dmy4    :1;   /* RW:予約 */
    U4 b1Dmy5    :1;   /* RW:予約 */
    U4 b1Dmy6    :1;   /* RW:予約 */
    U4 b1Dmy7    :1;   /* RW:予約 */
    U4 b1Fix8    :1;   /* RW:予約(1b固定) */
    U4 b1Fix9    :1;   /* RW:予約(1b固定) */
    U4 b1Fix10   :1;   /* RW:予約(1b固定) */
    U4 b1Fix11   :1;   /* RW:予約(1b固定) */
    U4 b1Fix12   :1;   /* RW:予約(1b固定) */
    U4 b1Fix13   :1;   /* RW:予約(1b固定) */
    U4 b1Fix14   :1;   /* RW:予約(1b固定) */
    U4 b1Fix15   :1;   /* RW:予約(1b固定) */
    U4 b1Fix16   :1;   /* RW:予約(1b固定) */
    U4 b1Fix17   :1;   /* RW:予約(1b固定) */
    U4 b1Fix18   :1;   /* RW:予約(1b固定) */
    U4 b1Fix19   :1;   /* RW:予約(1b固定) */
    U4 b1Fix20   :1;   /* RW:予約(1b固定) */
    U4 b1Fix21   :1;   /* RW:予約(1b固定) */
    U4 b1Fix22   :1;   /* RW:予約(1b固定) */
    U4 b1Fix23   :1;   /* RW:予約(1b固定) */
    U4 b1Fix24   :1;   /* RW:予約(1b固定) */
    U4 b1Fix25   :1;   /* RW:予約(1b固定) */
    U4 b1Fix26   :1;   /* RW:予約(1b固定) */
    U4 b1Fix27   :1;   /* RW:予約(1b固定) */
    U4 b1Fix28   :1;   /* RW:予約(1b固定) */
    U4 b1Fix29   :1;   /* RW:予約(1b固定) */
    U4 b1Fix30   :1;   /* RW:予約(1b固定) */
    U4 b1MSTPD31 :1;   /* RW:データ暗号化ユニット(DEU)モジュールストップ設定ビット (DEU) */
  } stBit;
  U4 u4Val;
} ST_MSTPCRD;

/* システムクロックコントロールレジスタ */ /* 0008 0020 */
typedef union {
  struct {
    U4 b4Fix0   :4;  /* RW:予約(0001b固定) */
    U4 b4Fix1   :4;  /* RW:予約(0001b固定) */
    U4 b4PCKB   :4;  /* RW:周辺モジュールクロックB(PCLKB)選択ビット */
    U4 b4PCKA   :4;  /* RW:周辺モジュールクロックA(PCLKA)選択ビット */
    U4 b4BCK    :4;  /* RW:外部バスクロック(BCLK)選択ビット */
    U4 b2Dmy0   :2;  /* RW:予約 */
    U4 b1PSTOP0 :1;  /* RW:SDCLK端子出力制御ビット */
    U4 b1PSTOP1 :1;  /* RW:BCLK端子出力制御ビット */
    U4 b4ICK    :4;  /* RW:システムクロック(ICLK)選択ビット */
    U4 b4FCK    :4;  /* RW:FlashIFクロック(FCLK)選択ビット */
  } stBit;
  U4 u4Val;
} ST_SCKCR;

/* システムクロックコントロールレジスタ2 */ /* 0008 0024 */
typedef union {
  struct {
    U2 b4IEBCK :4;  /* RW:IEBUSクロック(IECLK)選択ビット */
    U2 b4UCK   :4;  /* RW:USBクロック(UCLK)選択ビット */
    U2 b8Dmy0  :8;  /* RW:予約 */
  } stBit;
  U2 u2Val;
} ST_SCKCR2;

/* システムクロックコントロールレジスタ3 */ /* 0008 0026 */
typedef union {
  struct {
    U2 b8Dmy0  :8;  /* RW:予約 */
    U2 b3CKSEL :3;  /* RW:クロックソース選択ビット */
    U2 b5Dmy1  :5;  /* RW:予約 */
  } stBit;
  U2 u2Val;
} ST_SCKCR3;

/* PLLコントロールレジスタ */ /* 0008 0028 */
typedef union {
  struct {
    U2 b2PLIDIV :2;  /* RW:PLL入力分周比選択ビット */
    U2 b6Dmy0   :6;  /* RW:予約 */
    U2 b6STC    :6;  /* RW:周波数逓倍率設定ビット */
    U2 b2Dmy1   :2;  /* RW:予約 */
  } stBit;
  U2 u2Val;
} ST_PLLCR;

/* PLLコントロールレジスタ2 */ /* 0008 002A */
typedef union {
  struct {
    U1 b1PLLEN :1;  /* RW:PLL停止制御ビット */
    U1 b7Dmy0  :7;  /* RW:予約 */
  } stBit;
  U1 u1Val;
} ST_PLLCR2;

/* 外部バスクロックコントロールレジスタ */ /* 0008 0030 */
typedef union {
  struct {
    U1 b1BCLKDIV :1;  /* RW:BCLK端子出力選択ビット */
    U1 b7Dmy0    :7;  /* RW:予約 */
  } stBit;
  U1 u1Val;
} ST_BCKCR;

/* PLL ウェイトコントロールレジスタ */ /* 0008 00A6 */
typedef union {
  struct {
    U1 b5PSTS :5;  /* RW:PLLウェイト時間設定ビット */
    U1 b3Dmy0 :3;
  } stBit;
  U1 u1Val;
} ST_PLLWTCR;

/* プロテクトレジスタ */ /* 0008 03FE */
typedef union {
  struct {
    U2 b1PRC0  :1;  /* RW:プロテクトビット0 */
    U2 b1PRC1  :1;  /* RW:プロテクトビット1 */
    U2 b1Dmy0  :1;  /* RW:予約 */
    U2 b1PRC3  :1;  /* RW:プロテクトビット3 */
    U2 b4Dmy1  :4;  /* RW:予約 */
    U2 b8PRKEY :8;  /* RW:PRCキーコードビット */
  } stBit;
  U2 u2Val;
} ST_PRCR;

/* SYSTEMモジュール0 */
typedef struct {
  U2          stMDMONR;       /* モードモニタレジスタ */ /* ToDo:未実装 */
  U2          stMDSR;         /* モードステータスレジスタ */ /* ToDo:未実装 */
  U2          stSYSCR0;       /* システムコントロールレジスタ0 */ /* ToDo:未実装 */
  U2          stSYSCR1;       /* システムコントロールレジスタ1 */ /* ToDo:未実装 */
  U1          u1aDmy00[2];    /* 予約 */
  U2          stSBYCR;        /* スタンバイコントロールレジスタ */ /* ToDo:未実装 */
  U2          u1aDmy01[2];    /* 予約 */
  ST_MSTPCRA  stMSTPCRA;      /* モジュールストップコントロールレジスタA */
  ST_MSTPCRB  stMSTPCRB;      /* モジュールストップコントロールレジスタB */
  ST_MSTPCRC  stMSTPCRC;      /* モジュールストップコントロールレジスタC */
  ST_MSTPCRD  stMSTPCRD;      /* モジュールストップコントロールレジスタD */
  ST_SCKCR    stSCKCR;        /* システムクロックコントロールレジスタ */
  ST_SCKCR2   stSCKCR2;       /* システムクロックコントロールレジスタ2 */
  ST_SCKCR3   stSCKCR3;       /* システムクロックコントロールレジスタ3 */
  ST_PLLCR    stPLLCR;        /* PLLコントロールレジスタ */
  ST_PLLCR2   stPLLCR2;       /* PLLコントロールレジスタ2 */
  U1          u1aDmy02[5];    /* 予約 */
  ST_BCKCR    stBCKCR;        /* 外部バスクロックコントロールレジスタ */
  U1          u1aDmy03[1];    /* 予約 */
  U1          stMOSCCR;       /* メインクロック発振器コントロールレジスタ */ /* ToDo:未実装 */
  U1          stSOSCCR;       /* サブクロック発振器コントロールレジスタ */ /* ToDo:未実装 */
  U1          stLOCOCR;       /* 低速オンチップオシレータコントロールレジスタ */ /* ToDo:未実装 */
  U1          stILOCOCR;      /* IWDT専用オンチップオシレータコントロールレジスタ */ /* ToDo:未実装 */
  U1          stHOCOCR;       /* 高速オンチップオシレータコントロールレジスタ */ /* ToDo:未実装 */
  U1          u1aDmy04[9];    /* 予約 */
  U1          stOSTDCR;       /* 発振停止検出コントロールレジスタ */ /* ToDo:未実装 */
  U1          stOSTDSR;       /* 発振停止検出ステータスレジスタ */ /* ToDo:未実装 */
  U1          u1aDmy05[94];   /* 予約 */
  U1          stOPCCR;        /* 動作電力コントロールレジスタ */ /* ToDo:未実装 */
  U1          stRSTCKCR;      /* スリープモード復帰クロックソース切り替えレジスタ */ /* ToDo:未実装 */
  U1          stMOSCWTCR;     /* メインクロック発振器ウェイトコントロールレジスタ */ /* ToDo:未実装 */
  U1          stSOSCWTCR;     /* サブクロック発振器ウェイトコントロールレジスタ */ /* ToDo:未実装 */
  U1          u1aDmy06[2];    /* 予約 */
  ST_PLLWTCR  stPLLWTCR;      /* PLLウェイトコントロールレジスタ */
  U1          u1aDmy07[25];   /* 予約 */
  U1          stRSTSR2;       /* リセットステータスレジスタ2 */ /* ToDo:未実装 */
  U1          u1aDmy08[1];    /* 予約 */
  U2          stSWRR;         /* ソフトウェアリセットレジスタ */ /* ToDo:未実装 */
  U1          u1aDmy09[28];   /* 予約 */
  U1          stLVD1CR1;      /* 電圧監視1回路制御レジスタ1 */ /* ToDo:未実装 */
  U1          stLVD1SR;       /* 電圧監視1回路ステータスレジスタ */ /* ToDo:未実装 */
  U1          stLVD2CR1;      /* 電圧監視2回路制御レジスタ1 */ /* ToDo:未実装 */
  U1          stLVD2SR;       /* 電圧監視2回路ステータスレジスタ */ /* ToDo:未実装 */
  U1          u1aDmy10[794];  /* 予約 */
  ST_PRCR     stPRCR;         /* プロテクトレジスタ */
} ST_SYSTEM0;

/* ---------------------------------------- */
/* ICUモジュール(GRPm, GENm, GCRm, SEL除く) */
/* ---------------------------------------- */
/* 割り込み要求レジスタn (n = 割り込みベクタ番号) */
typedef union {
  struct {
    U1 b1IR   :1;  /* RW:割り込みステータスフラグ */
    U1 b7Dmy0 :7;  /* RW:予約 */
  } stBit;
  U1 u1Val;
} ST_IRn;

/* 割り込み要求許可レジスタm (m = 0x02, ..., 0x1F) */
typedef union {
  struct {
    U1 b1IEN0 :1;  /* RW:割り込み要求許可ビット0 */
    U1 b1IEN1 :1;  /* RW:割り込み要求許可ビット1 */
    U1 b1IEN2 :1;  /* RW:割り込み要求許可ビット2 */
    U1 b1IEN3 :1;  /* RW:割り込み要求許可ビット3 */
    U1 b1IEN4 :1;  /* RW:割り込み要求許可ビット4 */
    U1 b1IEN5 :1;  /* RW:割り込み要求許可ビット5 */
    U1 b1IEN6 :1;  /* RW:割り込み要求許可ビット6 */
    U1 b1IEN7 :1;  /* RW:割り込み要求許可ビット7 */
  } stBit;
  U1 u1Val;
} ST_IERm;

/* 割り込み要因プライオリティレジスタn (n = 割り込みベクタ番号) */
typedef union {
  struct {
    U1 b4IPR  :4;  /* RW:割り込み優先レベル設定ビット */
    U1 b4Dmy0 :4;  /* RW:予約 */
  } stBit;
  U1 u1Val;
} ST_IPRn;

/* 高速割り込み設定レジスタ */
typedef union {
  struct {
    U2 b8FVCT  :8;  /* RW:高速割り込みベクタ設定ビット */
    U2 b7Dmy0  :7;  /* RW:予約 */
    U2 b1FIEN  :1;  /* RW:高速割り込み許可ビット */
  } stBit;
  U2 u2Val;
} ST_FIR;

/* ICUモジュール(GRPm, GENm, GCRm, SEL除く) */
typedef struct {
  ST_IRn  staIRn[256];     /* 割り込み要求レジスタn */
  U1      staDTCERn[256];  /* DTC起動許可レジスタn */ /* ToDo:未実装 */
  ST_IERm staIERm[32];     /* 割り込み要求許可レジスタm */
  U1      u1aDmy0[192];    /* 予約 */
  U1      stSWINTR;        /* ソフトウェア割り込み起動レジスタ */ /* ToDo:未実装 */
  U1      u1aDmy1[15];     /* 予約 */
  ST_FIR  stFIR;           /* 高速割り込み設定レジスタ */
  U1      u1aDmy2[14];     /* 予約 */
  ST_IPRn staIPRn[256];    /* 割り込み要因プライオリティレジスタn */
  struct {
    U1 stDMRSR;            /* DMAC起動要求選択レジスタm */ /* ToDo:未実装 */
    U1 u1aDmy0[3];
  } staDMRSRm[4];
  U1      u1aDmy3[240];    /* 予約 */
  U1      staIRQCRi[16];   /* IRQコントロールレジスタi */ /* ToDo:未実装 */
  U1      staIRQFLTE[2];   /* IRQ端子デジタルフィルタ許可レジスタ */ /* ToDo:未実装 */
  U1      u1aDmy4[2];      /* 予約 */
  U2      staIRQFLTC[2];   /* IRQ端子デジタルフィルタ設定レジスタ */ /* ToDo:未実装 */
  U1      u1aDmy5[104];    /* 予約 */
  U1      stNMISR;         /* ノンマスカブル割り込みステータスレジスタ */ /* ToDo:未実装 */
  U1      stNMIER;         /* ノンマスカブル割り込み許可レジスタ */ /* ToDo:未実装 */
  U1      stNMICLR;        /* ノンマスカブル割り込みステータスクリアレジスタ */ /* ToDo:未実装 */
  U1      stNMICR;         /* NMI端子割り込みコントロールレジスタ */ /* ToDo:未実装 */
  U1      u1aDmy6[12];     /* 予約 */
  U1      stNMIFLTE;       /* NMI端子デジタルフィルタ許可レジスタ */ /* ToDo:未実装 */
  U1      u1aDmy7[3];      /* 予約 */
  U2      stNMIFLTC;       /* NMI端子デジタルフィルタ設定レジスタ */ /* ToDo:未実装 */
} ST_ICU;

/* -------------------------- */
/* CMT/CMTmモジュール (m=0-3) */
/* -------------------------- */
/* コンペアマッチタイマスタートレジスタi (i = 0,1) */
typedef union {
  struct {
    U2 b1STR02 :1;   /* RW:カウントスタート0, 2ビット */
    U2 b1STR13 :1;   /* RW:カウントスタート1, 3ビット */
    U2 b14Dmy1 :14;  /* RW:予約 */
  } stBit;
  U2 u2Val;
} ST_CMSTRi;

/* コンペアマッチタイマコントロールレジスタ */
typedef union {
  struct {
    U2 b2CKS  :2;  /* RW:クロック選択ビット */
    U2 b4Dmy0 :4;  /* RW:予約 */
    U2 b1CMIE :1;  /* RW:コンペアマッチ割り込み許可ビット */
    U2 b1Fix0 :1;  /* 予約(R:不定値, W:1固定) */
    U2 b8Dmy1 :8;  /* RW:予約 */
  } stBit;
  U2 u2Val;
} ST_CMCR;

/* コンペアマッチタイマカウンタ */
typedef union {
  struct {
    U2 b16CNT :16;  /* RW:カウンタ値ビット */
  } stBit;
  U2 u2Val;
} ST_CMCNT;

/* コンペアマッチタイマコンスタントレジスタ */
typedef union {
  struct {
    U2 b16CMP :16;  /* RW:コンペア値設定ビット */
  } stBit;
  U2 u2Val;
} ST_CMCOR;

/* CMT/CMTmモジュール (m=0-3) */
typedef struct {
  ST_CMSTRi stCMSTR;   /* コンペアマッチタイマスタートレジスタ0, 1 (MainIdx:m/2) */
  struct {
    ST_CMCR  stCMCR;   /* コンペアマッチタイマコントロールレジスタ0-3 (MainIdx:m/2, SubIdx:m%2) */
    ST_CMCNT stCMCNT;  /* コンペアマッチタイマカウンタ0-3 (MainIdx:m/2, SubIdx:m%2) */
    ST_CMCOR stCMCOR;  /* コンペアマッチタイマコンスタントレジスタ0-3 (MainIdx:m/2, SubIdx:m%2) */
  } staCM[2];          /* (MainIdx:m/2) */
  U1 u1Dmy0[2];        /* 予約 */
} ST_CMTm;

/* --------------- */
/* S12ADモジュール */
/* --------------- */
/* A/D コントロールレジスタ */
typedef union {
  struct {
    U1 b1EXTRG :1;    /* RW:トリガ選択ビット */
    U1 b1TRGE  :1;    /* RW:トリガ開始許可ビット */
    U1 b2CKS   :2;    /* RW:A/D変換クロック選択ビット */
    U1 b1ADIE  :1;    /* RW:スキャン終了割り込み許可ビット */
    U1 b1Dmy0  :1;    /* RW:予約 */
    U1 b1ADCS  :1;    /* RW:スキャンモード選択ビット */
    U1 b1ADST  :1;    /* RW:A/D変換スタートビット */
  } stBit;
  U1 u1Val;
} ST_ADCSR;

/* A/D チャネル選択レジスタi (i = ch/16, ch = 0-20) */
typedef union {
  struct {
    U2 b1ANSi0  :1;    /* RW:A/D変換チャネル選択ビット({i, ch}={0,AN000}, {1,AN016}) */
    U2 b1ANSi1  :1;    /* RW:A/D変換チャネル選択ビット({i, ch}={0,AN001}, {1,AN017}) */
    U2 b1ANSi2  :1;    /* RW:A/D変換チャネル選択ビット({i, ch}={0,AN002}, {1,AN018}) */
    U2 b1ANSi3  :1;    /* RW:A/D変換チャネル選択ビット({i, ch}={0,AN003}, {1,AN019}) */
    U2 b1ANSi4  :1;    /* RW:A/D変換チャネル選択ビット({i, ch}={0,AN004}, {1,AN020}) */
    U2 b1ANSi5  :1;    /* RW:A/D変換チャネル選択ビット({i, ch}={0,AN005}, {1,予約}) */
    U2 b1ANSi6  :1;    /* RW:A/D変換チャネル選択ビット({i, ch}={0,AN006}, {1,予約}) */
    U2 b1ANSi7  :1;    /* RW:A/D変換チャネル選択ビット({i, ch}={0,AN007}, {1,予約}) */
    U2 b1ANSi8  :1;    /* RW:A/D変換チャネル選択ビット({i, ch}={0,AN008}, {1,予約}) */
    U2 b1ANSi9  :1;    /* RW:A/D変換チャネル選択ビット({i, ch}={0,AN009}, {1,予約}) */
    U2 b1ANSi10 :1;    /* RW:A/D変換チャネル選択ビット({i, ch}={0,AN010}, {1,予約}) */
    U2 b1ANSi11 :1;    /* RW:A/D変換チャネル選択ビット({i, ch}={0,AN011}, {1,予約}) */
    U2 b1ANSi12 :1;    /* RW:A/D変換チャネル選択ビット({i, ch}={0,AN012}, {1,予約}) */
    U2 b1ANSi13 :1;    /* RW:A/D変換チャネル選択ビット({i, ch}={0,AN013}, {1,予約}) */
    U2 b1ANSi14 :1;    /* RW:A/D変換チャネル選択ビット({i, ch}={0,AN014}, {1,予約}) */
    U2 b1ANSi15 :1;    /* RW:A/D変換チャネル選択ビット({i, ch}={0,AN015}, {1,予約}) */
  } stBit;
  U2 u2Val;
} ST_ADANSi;

/* A/D 変換値加算モード選択レジスタi (i = ch/16, ch = 0-20) */
typedef union {
  struct {
    U2 b1ADSi0  :1;    /* RW:AD変換値加算チャネル選択ビット({i, ch}={0,AN000}, {1,AN016}) */
    U2 b1ADSi1  :1;    /* RW:AD変換値加算チャネル選択ビット({i, ch}={0,AN001}, {1,AN017}) */
    U2 b1ADSi2  :1;    /* RW:AD変換値加算チャネル選択ビット({i, ch}={0,AN002}, {1,AN018}) */
    U2 b1ADSi3  :1;    /* RW:AD変換値加算チャネル選択ビット({i, ch}={0,AN003}, {1,AN019}) */
    U2 b1ADSi4  :1;    /* RW:AD変換値加算チャネル選択ビット({i, ch}={0,AN004}, {1,AN020}) */
    U2 b1ADSi5  :1;    /* RW:AD変換値加算チャネル選択ビット({i, ch}={0,AN005}, {1,予約}) */
    U2 b1ADSi6  :1;    /* RW:AD変換値加算チャネル選択ビット({i, ch}={0,AN006}, {1,予約}) */
    U2 b1ADSi7  :1;    /* RW:AD変換値加算チャネル選択ビット({i, ch}={0,AN007}, {1,予約}) */
    U2 b1ADSi8  :1;    /* RW:AD変換値加算チャネル選択ビット({i, ch}={0,AN008}, {1,予約}) */
    U2 b1ADSi9  :1;    /* RW:AD変換値加算チャネル選択ビット({i, ch}={0,AN009}, {1,予約}) */
    U2 b1ADSi10 :1;    /* RW:AD変換値加算チャネル選択ビット({i, ch}={0,AN010}, {1,予約}) */
    U2 b1ADSi11 :1;    /* RW:AD変換値加算チャネル選択ビット({i, ch}={0,AN011}, {1,予約}) */
    U2 b1ADSi12 :1;    /* RW:AD変換値加算チャネル選択ビット({i, ch}={0,AN012}, {1,予約}) */
    U2 b1ADSi13 :1;    /* RW:AD変換値加算チャネル選択ビット({i, ch}={0,AN013}, {1,予約}) */
    U2 b1ADSi14 :1;    /* RW:AD変換値加算チャネル選択ビット({i, ch}={0,AN014}, {1,予約}) */
    U2 b1ADSi15 :1;    /* RW:AD変換値加算チャネル選択ビット({i, ch}={0,AN015}, {1,予約}) */
  } stBit;
  U2 u2Val;
} ST_ADADSi;

/* A/D 変換値加算回数選択レジスタ */
typedef union {
  struct {
    U1 b2ADC   :2;    /* RW:加算回数選択ビット */
    U1 b6Dmy0  :6;    /* RW:予約 */
  } stBit;
  U1 u1Val;
} ST_ADADC;

/* A/D コントロール拡張レジスタ */
typedef union {
  struct {
    U2 b5Dmy0   :5;    /* RW:予約 */
    U2 b1ACE    :1;    /* RW:自動クリアイネーブルビット */
    U2 b9Dmy0   :9;    /* RW:予約 */
    U2 b1ADRFMT :1;    /* RW:A/Dデータレジスタフォーマット選択ビット */
  } stBit;
  U2 u2Val;
} ST_ADCER;

/* A/D 開始トリガ選択レジスタ */
typedef union {
  struct {
    U1 b4ADSTRS :4;    /* RW:A/D変換開始トリガ選択ビット */
    U1 b4Dmy0   :4;    /* RW:予約 */
  } stBit;
  U1 u1Val;
} ST_ADSTRGR;

/* A/D 変換拡張入力コントロールレジスタ */
typedef union {
  struct {
    U2 b1TSSAD :1;    /* RW:温度センサ出力A/D変換値加算モード選択ビット */
    U2 b1OCSAD :1;    /* RW:内部基準電圧A/D変換値加算モード選択ビット */
    U2 b6Dmy0  :6;    /* RW:予約 */
    U2 b1TSS   :1;    /* RW:温度センサ出力A/D変換選択ビット */
    U2 b1OCS   :1;    /* RW:内部基準電圧A/D変換選択ビット */
    U2 b6Dmy1  :6;    /* RW:予約 */
  } stBit;
  U2 u2Val;
} ST_ADEXICR;

/* A/D 温度センサデータレジスタ */
typedef union {
  struct {
    struct {
      U2 b12AD  :12;    /* RW:12ビットA/D変換値 */
      U2 b4Dmy0 :4;     /* RW:予約 */
    } stBit;
  } stRight;            /* 右詰め */
  struct {
    struct {
      U2 b4Dmy0 :4;     /* RW:予約 */
      U2 b12AD  :12;    /* RW:12ビットA/D変換値 */
    } stBit;
  } stLeft;             /* 左詰め */
  struct {
    struct {
      U2 b2Dmy0 :2;     /* RW:予約 */
      U2 b14AD  :14;    /* RW:14ビットA/D変換値加算結果 */
    } stBit;
  } stAdd;              /* 加算モード(左詰め) */
  U2 u2Val;
} ST_ADTSDR;

/* A/D 内部基準電圧データレジスタ */
typedef union {
  struct {
    struct {
      U2 b12AD  :12;    /* RW:12ビットA/D変換値 */
      U2 b4Dmy0 :4;     /* RW:予約 */
    } stBit;
  } stRight;            /* 右詰め */
  struct {
    struct {
      U2 b4Dmy0 :4;     /* RW:予約 */
      U2 b12AD  :12;    /* RW:12ビットA/D変換値 */
    } stBit;
  } stLeft;             /* 左詰め */
  struct {
    struct {
      U2 b2Dmy0 :2;     /* RW:予約 */
      U2 b14AD  :14;    /* RW:14ビットA/D変換値加算結果 */
    } stBit;
  } stAdd;              /* 加算モード(左詰め) */
  U2 u2Val;
} ST_ADOCDR;

/* A/D データレジスタy (y = 0-20) */
typedef union {
  struct {
    struct {
      U2 b12AD  :12;    /* RW:12ビットA/D変換値 */
      U2 b4Dmy0 :4;     /* RW:予約 */
    } stBit;
  } stRight;            /* 右詰め */
  struct {
    struct {
      U2 b4Dmy0 :4;     /* RW:予約 */
      U2 b12AD  :12;    /* RW:12ビットA/D変換値 */
    } stBit;
  } stLeft;             /* 左詰め */
  struct {
    struct {
      U2 b2Dmy0 :2;     /* RW:予約 */
      U2 b14AD  :14;    /* RW:14ビットA/D変換値加算結果 */
    } stBit;
  } stAdd;              /* 加算モード(左詰め) */
  U2 u2Val;
} ST_ADDRy;

/* A/D サンプリングステートレジスタ01 */
typedef union {
  struct {
    U2 b8SST1 :1;    /* RW:サンプリング時間1設定ビット */
    U2 b8Fix0 :6;    /* RW:固定(20 = 0001 0100b) */
  } stBit;
  U2 u2Val;
} ST_ADSSTR01;

/* A/D サンプリングステートレジスタ23 */
typedef union {
  struct {
    U2 b8Fix0 :6;    /* RW:固定(20 = 0001 0100b) */
    U2 b8SST2 :1;    /* RW:サンプリング時間1設定ビット */
  } stBit;
  U2 u2Val;
} ST_ADSSTR23;

/* S12ADモジュール */
typedef struct {
  ST_ADCSR    stADCSR;       /* A/Dコントロールレジスタ */
  U1          u1aDmy0[3];    /* 予約 */
  ST_ADANSi   staADANSi[2];  /* A/Dチャネル選択レジスタi */
  ST_ADADSi   staADADSi[2];  /* A/D変換値加算モード選択レジスタi */
  ST_ADADC    stADADC;       /* A/D変換値加算回数選択レジスタ */
  U1          u1aDmy1[1];    /* 予約 */
  ST_ADCER    stADCER;       /* A/Dコントロール拡張レジスタ */
  ST_ADSTRGR  stADSTRGR;     /* A/D開始トリガ選択レジスタ */
  U1          u1aDmy2[1];    /* 予約 */
  ST_ADEXICR  stADEXICR;     /* A/D変換拡張入力コントロールレジスタ */
  U1          u1aDmy3[6];    /* 予約 */
  ST_ADTSDR   stADTSDR;      /* A/D温度センサデータレジスタ */
  ST_ADOCDR   stADOCDR;      /* A/D内部基準電圧データレジスタ */
  U1          u1aDmy4[2];    /* 予約 */
  ST_ADDRy    staADDRy[21];  /* A/Dデータレジスタy */
  U1          u1aDmy5[22];   /* 予約 */
  ST_ADSSTR01 stADSSTR01;    /* A/Dサンプリングステートレジスタ01 */
  U1          u1aDmy6[14];   /* 予約 */
  ST_ADSSTR23 stADSSTR23;    /* A/Dサンプリングステートレジスタ23 */
  U1          u1aDmy7[14];   /* 予約 */
} ST_S12AD;

/* --------------------------------------------------------- */
/* PORTmモジュール(idx = 0:P0, ..., 10:PA, ... 16:PG, 18:PJ) */
/* --------------------------------------------------------- */
/* ポート方向レジスタ */
typedef union {
  struct {
    U1 b1B0 :1;    /* RW:Pm0方向制御ビット */
    U1 b1B1 :1;    /* RW:Pm1方向制御ビット */
    U1 b1B2 :1;    /* RW:Pm2方向制御ビット */
    U1 b1B3 :1;    /* RW:Pm3方向制御ビット */
    U1 b1B4 :1;    /* RW:Pm4方向制御ビット */
    U1 b1B5 :1;    /* RW:Pm5方向制御ビット */
    U1 b1B6 :1;    /* RW:Pm6方向制御ビット */
    U1 b1B7 :1;    /* RW:Pm7方向制御ビット */
  } stBit;
  U1 u1Val;
} ST_PDR;

/* ポート出力データレジスタ */
typedef union {
  struct {
    U1 b1B0 :1;    /* RW:Pm0出力データ格納ビット */
    U1 b1B1 :1;    /* RW:Pm1出力データ格納ビット */
    U1 b1B2 :1;    /* RW:Pm2出力データ格納ビット */
    U1 b1B3 :1;    /* RW:Pm3出力データ格納ビット */
    U1 b1B4 :1;    /* RW:Pm4出力データ格納ビット */
    U1 b1B5 :1;    /* RW:Pm5出力データ格納ビット */
    U1 b1B6 :1;    /* RW:Pm6出力データ格納ビット */
    U1 b1B7 :1;    /* RW:Pm7出力データ格納ビット */
 } stBit;
  U1 u1Val;
} ST_PODR;

/* ポート入力データレジスタ */
typedef union {
  struct {
    U1 b1B0 :1;    /* R:Pm0ビット */
    U1 b1B1 :1;    /* R:Pm1ビット */
    U1 b1B2 :1;    /* R:Pm2ビット */
    U1 b1B3 :1;    /* R:Pm3ビット */
    U1 b1B4 :1;    /* R:Pm4ビット */
    U1 b1B5 :1;    /* R:Pm5ビット */
    U1 b1B6 :1;    /* R:Pm6ビット */
    U1 b1B7 :1;    /* R:Pm7ビット */
 } stBit;
  U1 u1Val;
} ST_PIDR;

/* ポートモードレジスタ */
typedef union {
  struct {
    U1 b1B0 :1;    /* RW:Pm0端子モード制御ビット */
    U1 b1B1 :1;    /* RW:Pm1端子モード制御ビット */
    U1 b1B2 :1;    /* RW:Pm2端子モード制御ビット */
    U1 b1B3 :1;    /* RW:Pm3端子モード制御ビット */
    U1 b1B4 :1;    /* RW:Pm4端子モード制御ビット */
    U1 b1B5 :1;    /* RW:Pm5端子モード制御ビット */
    U1 b1B6 :1;    /* RW:Pm6端子モード制御ビット */
    U1 b1B7 :1;    /* RW:Pm7端子モード制御ビット */
 } stBit;
  U1 u1Val;
} ST_PMR;

/* オープンドレイン制御レジスタ i (i=0,1) */
typedef union {
  struct {
    U1 b1B0   :1;    /* RW:Pm0/4出力形態指定ビット */
    U1 b1Dmy1 :1;    /* RW:予約ビット */
    U1 b1B2   :1;    /* RW:Pm1/5出力形態指定ビット */
    U1 b1Dmy2 :1;    /* RW:予約ビット */
    U1 b1B4   :1;    /* RW:Pm2/6出力形態指定ビット */
    U1 b1Dmy3 :1;    /* RW:予約ビット */
    U1 b1B6   :1;    /* RW:Pm3/7出力形態指定ビット */
    U1 b1Dmy4 :1;    /* RW:予約ビット */
 } stBit;
  U1 u1Val;
} ST_ODRi;

/* プルアップ制御レジスタ */
typedef union {
  struct {
    U1 b1B0 :1;    /* RW:Pm0入力プルアップ抵抗制御ビット */
    U1 b1B1 :1;    /* RW:Pm1入力プルアップ抵抗制御ビット */
    U1 b1B2 :1;    /* RW:Pm2入力プルアップ抵抗制御ビット */
    U1 b1B3 :1;    /* RW:Pm3入力プルアップ抵抗制御ビット */
    U1 b1B4 :1;    /* RW:Pm4入力プルアップ抵抗制御ビット */
    U1 b1B5 :1;    /* RW:Pm5入力プルアップ抵抗制御ビット */
    U1 b1B6 :1;    /* RW:Pm6入力プルアップ抵抗制御ビット */
    U1 b1B7 :1;    /* RW:Pm7入力プルアップ抵抗制御ビット */
 } stBit;
  U1 u1Val;
} ST_PCR;

/* 駆動能力制御レジスタ */
typedef union {
  struct {
    U1 b1B0 :1;    /* RW:Pm0駆動能力制御ビット */
    U1 b1B1 :1;    /* RW:Pm1駆動能力制御ビット */
    U1 b1B2 :1;    /* RW:Pm2駆動能力制御ビット */
    U1 b1B3 :1;    /* RW:Pm3駆動能力制御ビット */
    U1 b1B4 :1;    /* RW:Pm4駆動能力制御ビット */
    U1 b1B5 :1;    /* RW:Pm5駆動能力制御ビット */
    U1 b1B6 :1;    /* RW:Pm6駆動能力制御ビット */
    U1 b1B7 :1;    /* RW:Pm7駆動能力制御ビット */
 } stBit;
  U1 u1Val;
} ST_DSCR;

/* PORTmモジュール(idx = 0:P0, ..., 10:PA, ... 16:PG, 18:PJ) */
/* m=17, 18, 20～31は予約 */
typedef struct {
  ST_PDR  staPDR[32];        /* ポート方向レジスタ */
  ST_PODR staPODR[32];       /* ポート出力データレジスタ */
  ST_PIDR staPIDR[32];       /* ポート入力データレジスタ */
  ST_PMR  staPMR[32];        /* ポートモードレジスタ */
  ST_ODRi sta2ODRi[32][2];   /* オープンドレイン制御レジスタi */
  ST_PCR  staPCR[32];        /* プルアップ制御レジスタ */
  ST_DSCR staDSCR[32];       /* 駆動能力制御レジスタ */
} ST_PORTm;

/* -------------- */
/* PORTモジュール */
/* -------------- */
/* ポート切り替えレジスタA */ /* Note:64ピンパッケージ限定 */
typedef union {
  struct {
    U1 b6Dmy0  :6;  /* RW:予約 */
    U1 b1PSEL6 :1;  /* RW:PB6/PC0切り替えビット */
    U1 b1PSEL7 :1;  /* RW:PB7/PC1切り替えビット */
  } stBit;
  U1 u1Val;
} ST_PSRA;

/* ポート切り替えレジスタB */ /* Note:48ピンパッケージ限定 */
typedef union {
  struct {
    U1 b1PSEL0 :1;  /* RW:PB0/PC0切り替えビット */
    U1 b1PSEL1 :1;  /* RW:PB1/PC1切り替えビット */
    U1 b1Dmy0  :1;  /* RW:予約 */
    U1 b1PSEL3 :1;  /* RW:PB3/PC2切り替えビット */
    U1 b1Dmy1  :1;  /* RW:予約 */
    U1 b1PSEL5 :1;  /* RW:PB5/PC3切り替えビット */
    U1 b2Dmy2  :2;  /* RW:予約 */
  } stBit;
  U1 u1Val;
} ST_PSRB;

/* PORTモジュール */
typedef struct {
  ST_PSRA stPSRA;  /* ポート切り替えレジスタA */ /* Note:64ピンパッケージ限定 */
  ST_PSRB stPSRB;  /* ポート切り替えレジスタB */ /* Note:48ピンパッケージ限定 */
} ST_PORT;

/* ------------- */
/* MPCモジュール */
/* ------------- */
/* 書き込みプロテクトレジスタ */
typedef union {
  struct {
    U1 b6Dmy0  :6;  /* RW:予約 */
    U1 b1PFSWE :1;  /* RW:PFSレジスタ書き込み許可ビット */
    U1 b1B0WI  :1;  /* RW:PFSWEビット書き込み禁止ビット */
  } stBit;
  U1 u1Val;
} ST_PWPR;

/* MPCモジュール(PmnPFSレジスタ除く) */
typedef struct {
  U1      stPFCSE;        /* CS出力許可レジスタ */ /* ToDo:未実装 */
  U1      u1aDmy0[1];     /* 予約 */
  U2      stPFCSSi;       /* CS出力端子選択レジスタi */ /* ToDo:未実装 */
  U2      stPFAOEi;       /* アドレス出力許可レジスタi */ /* ToDo:未実装 */
  U2      stPFBCRi;       /* 外部バス制御レジスタi */ /* ToDo:未実装 */
  U1      u1aDmy1[6];     /* 予約 */
  U1      stPFENET;       /* イーサネット制御レジスタ */ /* ToDo:未実装 */
  U1      u1aDmy2[5];     /* 予約 */
  U1      stPFUSB0;       /* USB0制御レジスタ */ /* ToDo:未実装 */
  U1      stPFUSB1;       /* USB1制御レジスタ */ /* ToDo:未実装 */
  U1      u1aDmy3[9];     /* 予約 */
  ST_PWPR stPWPR;         /* 書き込みプロテクトレジスタ */ /* ToDo:未実装 */
} ST_MPC;

/* MPCモジュール(Pmn 端子機能制御レジスタ) */
typedef union {
  struct {
    U1 b5PSEL  :5;  /* RW:端子機能選択ビット */
    U1 b1Dmy0  :1;  /* RW:予約 */
    U1 b1ISEL  :1;  /* RW:割り込み入力機能選択ビット */
    U1 b1ASEL  :1;  /* RW:アナログ入力機能選択ビット */
  } stBit;
  U1 u1Val;
} ST_PmnPFS;

/* ビットオーダー/アライメントをコンパイラオプションの設定に戻す */
#pragma bit_order
#pragma packoption


/* ============================================================ */
/* 関数プロトタイプ宣言(extern)                                 */
/* ============================================================ */


/* ============================================================ */
/* 変数宣言(extern)                                             */
/* ============================================================ */
extern volatile ST_SYSTEM0 __evenaccess stRegSys0;            /* SYSTEMモジュール(0) */
extern volatile ST_ICU     __evenaccess stRegICU;             /* ICUモジュール(GRPm, GENm, GCRm, SEL除く) */
extern volatile ST_CMTm    __evenaccess staRegCMTm[2];        /* CMT/CMTmモジュール (m=0-3  MainIdx=m/2, SubIdx=m%2) */
extern volatile ST_S12AD   __evenaccess stRegS12AD;           /* S12ADモジュール */
extern volatile ST_PORTm   __evenaccess stRegPORTm;           /* PORTmモジュール */
extern volatile ST_MPC     __evenaccess stRegMPC;             /* MPCモジュール(PmnPFSレジスタ除く) */
extern volatile ST_PORT    __evenaccess stRegPORT;            /* PORTモジュール */
extern volatile ST_PmnPFS  __evenaccess sta2RegPmnPFS[32][8]; /* MPCモジュール(PmnPFSレジスタ) */


/* ============================================================ */
/* const変数宣言(extern)                                        */
/* ============================================================ */


/* ============================================================ */
/* 関数形式マクロ定義                                           */
/* ============================================================ */


#endif
