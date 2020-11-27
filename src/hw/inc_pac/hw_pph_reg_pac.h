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
extern volatile ST_ICU    __evenaccess stRegICU;             /* ICUモジュール(GRPm, GENm, GCRm, SEL除く) */
extern volatile ST_PORTm  __evenaccess stRegPORTm;           /* PORTmモジュール */
extern volatile ST_MPC    __evenaccess stRegMPC;             /* MPCモジュール(PmnPFSレジスタ除く) */
extern volatile ST_PORT   __evenaccess stRegPORT;            /* PORTモジュール */
extern volatile ST_PmnPFS __evenaccess sta2RegPmnPFS[32][8]; /* MPCモジュール(PmnPFSレジスタ) */


/* ============================================================ */
/* const変数宣言(extern)                                        */
/* ============================================================ */


/* ============================================================ */
/* 関数形式マクロ定義                                           */
/* ============================================================ */


#endif
