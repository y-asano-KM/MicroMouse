#if !defined(INCLUDED_hw_pph_mtu_pac_h)
#define INCLUDED_hw_pph_mtu_pac_h
/* ============================================================ */
/* ファイル名 : hw_pph_mtu_pac.h                                */
/* 機能       : MTU処理                                         */
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
/* TCNTレジスタテーブル要素数 */
#define CU1_HwPph_Mtu_SizeTblRegTCNT    ((U1)8)

/* TGRレジスタテーブル要素数 */
#define CU1_HwPph_Mtu_SizeTblRegTGR     ((U1)21)

/* MTUカウント動作停止/開始ビット位置 */
#define CU1_HwPph_Mtu_StartBitPosMtu0    ((U1)0)
#define CU1_HwPph_Mtu_StartBitPosMtu1    ((U1)1)
#define CU1_HwPph_Mtu_StartBitPosMtu2    ((U1)2)
#define CU1_HwPph_Mtu_StartBitPosMtu3    ((U1)3)
#define CU1_HwPph_Mtu_StartBitPosMtu4    ((U1)4)
#define CU1_HwPph_Mtu_StartBitPosMtu5U   ((U1)5)
#define CU1_HwPph_Mtu_StartBitPosMtu5V   ((U1)6)
#define CU1_HwPph_Mtu_StartBitPosMtu5W   ((U1)7)


/* ============================================================ */
/* 型定義                                                       */
/* ============================================================ */
/* Memo:各ユニットで機能やレジスタが異なり共通化が困難なためユニットごとにIFを提供する */
/* ------------------------------------- */
/* タイマコントロールレジスタ(TCR)設定用 */
/* ------------------------------------- */
/* タイマプリスケーラ選択 (TCR.TPSC) */
/* MTU0 */
typedef enum {
  CEN_HwPph_Mtu_SelPriscalerMtu0_PClkDiv0001  = 0x0,  /* 000b:内部クロックPCLK/1でカウント */
  CEN_HwPph_Mtu_SelPriscalerMtu0_PClkDiv0004  = 0x1,  /* 001b:内部クロックPCLK/4でカウント */
  CEN_HwPph_Mtu_SelPriscalerMtu0_PClkDiv0016  = 0x2,  /* 010b:内部クロックPCLK/16でカウント */
  CEN_HwPph_Mtu_SelPriscalerMtu0_PClkDiv0064  = 0x3,  /* 011b:内部クロックPCLK/64でカウント */
  CEN_HwPph_Mtu_SelPriscalerMtu0_ExtClkMTCLKA = 0x4,  /* 100b:外部クロックMTCLKA端子入力でカウント */
  CEN_HwPph_Mtu_SelPriscalerMtu0_ExtClkMTCLKB = 0x5,  /* 101b:外部クロックMTCLKB端子入力でカウント */
  CEN_HwPph_Mtu_SelPriscalerMtu0_ExtClkMTCLKC = 0x6,  /* 110b:外部クロックMTCLKC端子入力でカウント */
  CEN_HwPph_Mtu_SelPriscalerMtu0_ExtClkMTCLKD = 0x7   /* 111b:外部クロックMTCLKD端子入力でカウント */
} EN_HwPph_Mtu_SelPriscalerMtu0;

/* MTU1 */
/* ToDo:未実装 */

/* MTU2 */
/* ToDo:未実装 */

/* MTU3 */
typedef enum {
  CEN_HwPph_Mtu_SelPriscalerMtu3_PClkDiv0001  = 0x0,  /* 000b:内部クロックPCLK/1でカウント */
  CEN_HwPph_Mtu_SelPriscalerMtu3_PClkDiv0004  = 0x1,  /* 001b:内部クロックPCLK/4でカウント */
  CEN_HwPph_Mtu_SelPriscalerMtu3_PClkDiv0016  = 0x2,  /* 010b:内部クロックPCLK/16でカウント */
  CEN_HwPph_Mtu_SelPriscalerMtu3_PClkDiv0064  = 0x3,  /* 011b:内部クロックPCLK/64でカウント */
  CEN_HwPph_Mtu_SelPriscalerMtu3_PClkDiv0256  = 0x4,  /* 100b:内部クロックPCLK/256でカウント */
  CEN_HwPph_Mtu_SelPriscalerMtu3_PClkDiv1024  = 0x5,  /* 101b:内部クロックPCLK/1024でカウント */
  CEN_HwPph_Mtu_SelPriscalerMtu3_ExtClkMTCLKA = 0x6,  /* 110b:外部クロックMTCLKA端子入力でカウント */
  CEN_HwPph_Mtu_SelPriscalerMtu3_ExtClkMTCLKB = 0x7   /* 111b:外部クロックMTCLKB端子入力でカウント */
} EN_HwPph_Mtu_SelPriscalerMtu3;

/* MTU4 */
typedef enum {
  CEN_HwPph_Mtu_SelPriscalerMtu4_PClkDiv0001  = 0x0,  /* 000b:内部クロックPCLK/1でカウント */
  CEN_HwPph_Mtu_SelPriscalerMtu4_PClkDiv0004  = 0x1,  /* 001b:内部クロックPCLK/4でカウント */
  CEN_HwPph_Mtu_SelPriscalerMtu4_PClkDiv0016  = 0x2,  /* 010b:内部クロックPCLK/16でカウント */
  CEN_HwPph_Mtu_SelPriscalerMtu4_PClkDiv0064  = 0x3,  /* 011b:内部クロックPCLK/64でカウント */
  CEN_HwPph_Mtu_SelPriscalerMtu4_PClkDiv0256  = 0x4,  /* 100b:内部クロックPCLK/256でカウント */
  CEN_HwPph_Mtu_SelPriscalerMtu4_PClkDiv1024  = 0x5,  /* 101b:内部クロックPCLK/1024でカウント */
  CEN_HwPph_Mtu_SelPriscalerMtu4_ExtClkMTCLKA = 0x6,  /* 110b:外部クロックMTCLKA端子入力でカウント */
  CEN_HwPph_Mtu_SelPriscalerMtu4_ExtClkMTCLKB = 0x7   /* 111b:外部クロックMTCLKB端子入力でカウント */
} EN_HwPph_Mtu_SelPriscalerMtu4;

/* MTU5 */
/* ToDo:未実装 */

/* クロックエッジ選択 (TCR.CKEG) */
typedef enum {
  CEN_HwPph_Mtu_SelClkEdge_Rising  = 0x0,  /* 00b:立ち上がりエッジ */
  CEN_HwPph_Mtu_SelClkEdge_Falling = 0x1,  /* 01b:立下りエッジ */
  CEN_HwPph_Mtu_SelClkEdge_Both    = 0x2   /* 1xb:両エッジ */
} EN_HwPph_Mtu_SelClkEdge;

/* カウンタクリア(TCR.CCLR) */
/* MTU0 */
typedef enum {
  CEN_HwPph_Mtu_CntrClrMtu0_Dib  = 0x0,  /* 000b:TCNTのクリア禁止 */
  CEN_HwPph_Mtu_CntrClrMtu0_TGRA = 0x1,  /* 001b:TGRAのコンペアマッチ/インプットキャプチャでTCNTクリア */
  CEN_HwPph_Mtu_CntrClrMtu0_TGRB = 0x2,  /* 010b:TGRBのコンペアマッチ/インプットキャプチャでTCNTクリア */
  CEN_HwPph_Mtu_CntrClrMtu0_Sync = 0x3,  /* 011b:同期クリア/同期動作をしている他のチャネルのカウンタクリアでTCNTをクリア */
                                         /* 100b:CNTのクリア禁止 */
  CEN_HwPph_Mtu_CntrClrMtu0_TGRC = 0x5,  /* 101b:TGRCのコンペアマッチ/インプットキャプチャでTCNTクリア */
  CEN_HwPph_Mtu_CntrClrMtu0_TGRD = 0x6   /* 110b:TGRDのコンペアマッチ/インプットキャプチャでTCNTクリア */
                                         /* 111b:同期クリア/同期動作をしている他のチャネルのカウンタクリアでTCNTをクリア */
} EN_HwPph_Mtu_CntrClrMtu0;

/* MTU1 */
/* ToDo:未実装 */

/* MTU2 */
/* ToDo:未実装 */

/* MTU3 */
typedef enum {
  CEN_HwPph_Mtu_CntrClrMtu3_Dib  = 0x0,  /* 000b:TCNTのクリア禁止 */
  CEN_HwPph_Mtu_CntrClrMtu3_TGRA = 0x1,  /* 001b:TGRAのコンペアマッチ/インプットキャプチャでTCNTクリア */
  CEN_HwPph_Mtu_CntrClrMtu3_TGRB = 0x2,  /* 010b:TGRBのコンペアマッチ/インプットキャプチャでTCNTクリア */
  CEN_HwPph_Mtu_CntrClrMtu3_Sync = 0x3,  /* 011b:同期クリア/同期動作をしている他のチャネルのカウンタクリアでTCNTをクリア */
                                         /* 100b:CNTのクリア禁止 */
  CEN_HwPph_Mtu_CntrClrMtu3_TGRC = 0x5,  /* 101b:TGRCのコンペアマッチ/インプットキャプチャでTCNTクリア */
  CEN_HwPph_Mtu_CntrClrMtu3_TGRD = 0x6   /* 110b:TGRDのコンペアマッチ/インプットキャプチャでTCNTクリア */
                                         /* 111b:同期クリア/同期動作をしている他のチャネルのカウンタクリアでTCNTをクリア */
} EN_HwPph_Mtu_CntrClrMtu3;

/* MTU4 */
typedef enum {
  CEN_HwPph_Mtu_CntrClrMtu4_Dib  = 0x0,  /* 000b:TCNTのクリア禁止 */
  CEN_HwPph_Mtu_CntrClrMtu4_TGRA = 0x1,  /* 001b:TGRAのコンペアマッチ/インプットキャプチャでTCNTクリア */
  CEN_HwPph_Mtu_CntrClrMtu4_TGRB = 0x2,  /* 010b:TGRBのコンペアマッチ/インプットキャプチャでTCNTクリア */
  CEN_HwPph_Mtu_CntrClrMtu4_Sync = 0x3,  /* 011b:同期クリア/同期動作をしている他のチャネルのカウンタクリアでTCNTをクリア */
                                         /* 100b:CNTのクリア禁止 */
  CEN_HwPph_Mtu_CntrClrMtu4_TGRC = 0x5,  /* 101b:TGRCのコンペアマッチ/インプットキャプチャでTCNTクリア */
  CEN_HwPph_Mtu_CntrClrMtu4_TGRD = 0x6   /* 110b:TGRDのコンペアマッチ/インプットキャプチャでTCNTクリア */
                                         /* 111b:同期クリア/同期動作をしている他のチャネルのカウンタクリアでTCNTをクリア */
} EN_HwPph_Mtu_CntrClrMtu4;

/* MTU5 */
/* Memo:MTU5は機能なし */

/* -------------------------------- */
/* タイマモードレジスタ(TMDR)設定用 */
/* -------------------------------- */
/* モード選択 (TMDR.MD) */
/* MTU0 */
typedef enum {
  CEN_HwPph_Mtu_SelMdMtu0_Nrml              = 0x0,  /* 0000b:ノーマルモード */
                                                    /* 0001b:設定禁止 */
  CEN_HwPph_Mtu_SelMdMtu0_Pwm1              = 0x2,  /* 0010b:PWM1モード */
  CEN_HwPph_Mtu_SelMdMtu0_Pwm2              = 0x3   /* 0011b:PWM2モード */
                                                    /* 0100b:位相計数モード1 */ /* Memo:MTU0機能なし */
                                                    /* 0101b:位相計数モード2 */ /* Memo:MTU0機能なし */
                                                    /* 0110b:位相計数モード3 */ /* Memo:MTU0機能なし */
                                                    /* 0111b:位相計数モード4 */ /* Memo:MTU0機能なし */
                                                    /* 1000b:リセット同期PWMモード */ /* Memo:MTU0機能なし */
                                                    /* 1001b:設定禁止 */
                                                    /* 1010b:設定禁止 */
                                                    /* 1011b:設定禁止 */
                                                    /* 1100b:設定禁止 */
                                                    /* 1101b:相補PWMモード1(山で転送) */ /* Memo:MTU0機能なし */
                                                    /* 1110b:相補PWMモード2(谷で転送) */ /* Memo:MTU0機能なし */
                                                    /* 1111b:相補PWMモード3(山/谷で転送) */ /* Memo:MTU0機能なし */
} EN_HwPph_Mtu_SelMdMtu0;

/* MTU1 */
/* ToDo:未実装 */

/* MTU2 */
/* ToDo:未実装 */

/* MTU3 */
typedef enum {
  CEN_HwPph_Mtu_SelMdMtu3_Nrml              = 0x0,  /* 0000b:ノーマルモード */
                                                    /* 0001b:設定禁止 */
  CEN_HwPph_Mtu_SelMdMtu3_Pwm1              = 0x2,  /* 0010b:PWM1モード */
                                                    /* 0011b:PWM2モード *//* Memo:MTU3機能なし */
                                                    /* 0100b:位相計数モード1 */ /* Memo:MTU3機能なし */
                                                    /* 0101b:位相計数モード2 */ /* Memo:MTU3機能なし */
                                                    /* 0110b:位相計数モード3 */ /* Memo:MTU3機能なし */
                                                    /* 0111b:位相計数モード4 */ /* Memo:MTU3機能なし */
  CEN_HwPph_Mtu_SelMdMtu3_ResetSyncPwm      = 0x8,  /* 1000b:リセット同期PWMモード */
                                                    /* 1001b:設定禁止 */
                                                    /* 1010b:設定禁止 */
                                                    /* 1011b:設定禁止 */
                                                    /* 1100b:設定禁止 */
  CEN_HwPph_Mtu_SelMdMtu3_ComplementaryPwm1 = 0xD,  /* 1101b:相補PWMモード1(山で転送) */
  CEN_HwPph_Mtu_SelMdMtu3_ComplementaryPwm2 = 0xE,  /* 1110b:相補PWMモード2(谷で転送) */
  CEN_HwPph_Mtu_SelMdMtu3_ComplementaryPwm3 = 0xF   /* 1111b:相補PWMモード3(山/谷で転送) */
} EN_HwPph_Mtu_SelMdMtu3;

/* MTU0 */
typedef enum {
  CEN_HwPph_Mtu_SelMdMtu4_Nrml              = 0x0,  /* 0000b:ノーマルモード */
                                                    /* 0001b:設定禁止 */
  CEN_HwPph_Mtu_SelMdMtu4_Pwm1              = 0x2,  /* 0010b:PWM1モード */
  CEN_HwPph_Mtu_SelMdMtu4_Pwm2              = 0x3   /* 0011b:PWM2モード */
                                                    /* 0100b:位相計数モード1 */ /* Memo:MTU4機能なし */
                                                    /* 0101b:位相計数モード2 */ /* Memo:MTU4機能なし */
                                                    /* 0110b:位相計数モード3 */ /* Memo:MTU4機能なし */
                                                    /* 0111b:位相計数モード4 */ /* Memo:MTU4機能なし */
                                                    /* 1000b:リセット同期PWMモード */ /* Note:MTU3で当モードを設定した場合MTU4は初期値(0000b)を設定 */
                                                    /* 1001b:設定禁止 */
                                                    /* 1010b:設定禁止 */
                                                    /* 1011b:設定禁止 */
                                                    /* 1100b:設定禁止 */
                                                    /* 1101b:相補PWMモード1(山で転送) */ /* Note:MTU3で当モードを設定した場合MTU4は初期値(0000b)を設定 */
                                                    /* 1110b:相補PWMモード2(谷で転送) */ /* Note:MTU3で当モードを設定した場合MTU4は初期値(0000b)を設定 */
                                                    /* 1111b:相補PWMモード3(山/谷で転送) */ /* Note:MTU3で当モードを設定した場合MTU4は初期値(0000b)を設定 */
} EN_HwPph_Mtu_SelMdMtu4;

/* MTU5 */
/* Memo:MTU5は機能なし */

/* ----------------------------------------- */
/* タイマI/Oコントロールレジスタ(TIOR)設定用 */
/* ----------------------------------------- */
/* I/OコントロールA (TIORH.IOA, TIOR.IOA) */
/* I/OコントロールB (TIORH.IOB, TIOR.IOB) */
/* I/OコントロールC (TIORL.IOC) */
/* I/OコントロールD (TIORL.IOD) */
/* MTU0 */
typedef enum {                                      /* MTIOC0#端子の機能(#=A,B,C,D) */
  CEN_HwPph_Mtu_IoCtrlMtu0_DibOut = 0x0,            /* 0000b:出力禁止 */
  CEN_HwPph_Mtu_IoCtrlMtu0_InitLoCmprLo     = 0x1,  /* 0001b:初期出力Low, コンペアマッチでLow */
  CEN_HwPph_Mtu_IoCtrlMtu0_InitLoCmprHi     = 0x2,  /* 0010b:初期出力Low, コンペアマッチでHigh */
  CEN_HwPph_Mtu_IoCtrlMtu0_InitLoCmprToggle = 0x3,  /* 0011b:初期出力Low, コンペアマッチでトグル */
                                                    /* 0100b:出力禁止 */
  CEN_HwPph_Mtu_IoCtrlMtu0_InitHiCmprLo     = 0x5,  /* 0101b:初期出力High, コンペアマッチでLow */
  CEN_HwPph_Mtu_IoCtrlMtu0_InitHiCmprHi     = 0x6,  /* 0110b:初期出力High, コンペアマッチでHigh */
  CEN_HwPph_Mtu_IoCtrlMtu0_InitHiCmprToggle = 0x7,  /* 0111b:初期出力High, コンペアマッチでトグル */
  CEN_HwPph_Mtu_IoCtrlMtu0_CaptureRising    = 0x8,  /* 1000b:立ち上がりエッジでインプットキャプチャ */
  CEN_HwPph_Mtu_IoCtrlMtu0_CaptureFalling   = 0x9,  /* 1001b:立ち下がりエッジでインプットキャプチャ */
  CEN_HwPph_Mtu_IoCtrlMtu0_CaptureBoth      = 0xA,  /* 101xb:両エッジでインプットキャプチャ */
  CEN_HwPph_Mtu_IoCtrlMtu0_CaptureMTU1      = 0xC,  /* 11xxb:MTU1.TCNTのカウントでインプットキャプチャ */
} EN_HwPph_Mtu_IoCtrlMtu0;

/* MTU1 */
/* ToDo:未実装 */

/* MTU2 */
/* ToDo:未実装 */

/* MTU3 */
typedef enum {                                      /* MTIOC3#端子の機能(#=A,B,C,D) */
  CEN_HwPph_Mtu_IoCtrlMtu3_DibOut = 0x0,            /* 0000b:出力禁止 */
  CEN_HwPph_Mtu_IoCtrlMtu3_InitLoCmprLo     = 0x1,  /* 0001b:初期出力Low, コンペアマッチでLow */
  CEN_HwPph_Mtu_IoCtrlMtu3_InitLoCmprHi     = 0x2,  /* 0010b:初期出力Low, コンペアマッチでHigh */
  CEN_HwPph_Mtu_IoCtrlMtu3_InitLoCmprToggle = 0x3,  /* 0011b:初期出力Low, コンペアマッチでトグル */
                                                    /* 0100b:出力禁止 */
  CEN_HwPph_Mtu_IoCtrlMtu3_InitHiCmprLo     = 0x5,  /* 0101b:初期出力High, コンペアマッチでLow */
  CEN_HwPph_Mtu_IoCtrlMtu3_InitHiCmprHi     = 0x6,  /* 0110b:初期出力High, コンペアマッチでHigh */
  CEN_HwPph_Mtu_IoCtrlMtu3_InitHiCmprToggle = 0x7,  /* 0111b:初期出力High, コンペアマッチでトグル */
  CEN_HwPph_Mtu_IoCtrlMtu3_CaptureRising    = 0x8,  /* 1x00b:立ち上がりエッジでインプットキャプチャ */
  CEN_HwPph_Mtu_IoCtrlMtu3_CaptureFalling   = 0x9,  /* 1x01b:立ち下がりエッジでインプットキャプチャ */
  CEN_HwPph_Mtu_IoCtrlMtu3_CaptureBoth      = 0xA,  /* 1x1xb:両エッジでインプットキャプチャ */
} EN_HwPph_Mtu_IoCtrlMtu3;

/* MTU4 */
typedef enum {                                      /* MTIOC4#端子の機能(#=A,B,C,D) */
  CEN_HwPph_Mtu_IoCtrlMtu4_DibOut = 0x0,            /* 0000b:出力禁止 */
  CEN_HwPph_Mtu_IoCtrlMtu4_InitLoCmprLo     = 0x1,  /* 0001b:初期出力Low, コンペアマッチでLow */
  CEN_HwPph_Mtu_IoCtrlMtu4_InitLoCmprHi     = 0x2,  /* 0010b:初期出力Low, コンペアマッチでHigh */
  CEN_HwPph_Mtu_IoCtrlMtu4_InitLoCmprToggle = 0x3,  /* 0011b:初期出力Low, コンペアマッチでトグル */
                                                    /* 0100b:出力禁止 */
  CEN_HwPph_Mtu_IoCtrlMtu4_InitHiCmprLo     = 0x5,  /* 0101b:初期出力High, コンペアマッチでLow */
  CEN_HwPph_Mtu_IoCtrlMtu4_InitHiCmprHi     = 0x6,  /* 0110b:初期出力High, コンペアマッチでHigh */
  CEN_HwPph_Mtu_IoCtrlMtu4_InitHiCmprToggle = 0x7,  /* 0111b:初期出力High, コンペアマッチでトグル */
  CEN_HwPph_Mtu_IoCtrlMtu4_CaptureRising    = 0x8,  /* 1x00b:立ち上がりエッジでインプットキャプチャ */
  CEN_HwPph_Mtu_IoCtrlMtu4_CaptureFalling   = 0x9,  /* 1x01b:立ち下がりエッジでインプットキャプチャ */
  CEN_HwPph_Mtu_IoCtrlMtu4_CaptureBoth      = 0xA,  /* 1x1xb:両エッジでインプットキャプチャ */
} EN_HwPph_Mtu_IoCtrlMtu4;

/* MTU5 */
/* ToDo:未実装 */

/* ------------------ */
/* タイマカウンタ識別 */ 
/* ------------------ */
typedef enum {
  CEN_HwPph_Mtu_IdTCNT_MTU0 = 0,   /* #0:MTU0.TCNT */
  CEN_HwPph_Mtu_IdTCNT_MTU1,       /* #1:MTU1.TCNT */
  CEN_HwPph_Mtu_IdTCNT_MTU2,       /* #2:MTU2.TCNT */
  CEN_HwPph_Mtu_IdTCNT_MTU3,       /* #3:MTU3.TCNT */
  CEN_HwPph_Mtu_IdTCNT_MTU4,       /* #4:MTU4.TCNT */
  CEN_HwPph_Mtu_IdTCNT_MTU5U,      /* #5:MTU5.TCNTU */
  CEN_HwPph_Mtu_IdTCNT_MTU5V,      /* #6:MTU5.TCNTV */
  CEN_HwPph_Mtu_IdTCNT_MTU5W       /* #7:MTU5.TCNTW */
} EN_HwPph_Mtu_IdTCNT;

/* ---------------------------- */
/* タイマジェネラルレジスタ識別 */ 
/* ---------------------------- */
typedef enum {
  CEN_HwPph_Mtu_IdTGR_MTU0A = 0,   /* #00:MTU0.TGRA */
  CEN_HwPph_Mtu_IdTGR_MTU0B,       /* #01:MTU0.TGRB */
  CEN_HwPph_Mtu_IdTGR_MTU0C,       /* #02:MTU0.TGRC */
  CEN_HwPph_Mtu_IdTGR_MTU0D,       /* #03:MTU0.TGRD */
  CEN_HwPph_Mtu_IdTGR_MTU0E,       /* #04:MTU0.TGRE */
  CEN_HwPph_Mtu_IdTGR_MTU0F,       /* #05:MTU0.TGRF */
  CEN_HwPph_Mtu_IdTGR_MTU1A,       /* #06:MTU1.TGRA */
  CEN_HwPph_Mtu_IdTGR_MTU1B,       /* #07:MTU1.TGRB */
  CEN_HwPph_Mtu_IdTGR_MTU2A,       /* #08:MTU2.TGRA */
  CEN_HwPph_Mtu_IdTGR_MTU2B,       /* #09:MTU2.TGRB */
  CEN_HwPph_Mtu_IdTGR_MTU3A,       /* #10:MTU3.TGRA */
  CEN_HwPph_Mtu_IdTGR_MTU3B,       /* #11:MTU3.TGRB */
  CEN_HwPph_Mtu_IdTGR_MTU3C,       /* #12:MTU3.TGRC */
  CEN_HwPph_Mtu_IdTGR_MTU3D,       /* #13:MTU3.TGRD */
  CEN_HwPph_Mtu_IdTGR_MTU4A,       /* #14:MTU4.TGRA */
  CEN_HwPph_Mtu_IdTGR_MTU4B,       /* #15:MTU4.TGRB */
  CEN_HwPph_Mtu_IdTGR_MTU4C,       /* #16:MTU4.TGRC */
  CEN_HwPph_Mtu_IdTGR_MTU4D,       /* #17:MTU4.TGRD */
  CEN_HwPph_Mtu_IdTGR_MTU5U,       /* #18:MTU5.TGRU */
  CEN_HwPph_Mtu_IdTGR_MTU5V,       /* #19:MTU5.TGRV */
  CEN_HwPph_Mtu_IdTGR_MTU5W,       /* #20:MTU5.TGRW */
} EN_HwPph_Mtu_IdTGR;

/* --------------- */
/* MTU機能設定情報 */ 
/* --------------- */
/* MTU0 */ /* ToDo:未実装機能あり */
typedef struct {
  /* タイマコントロールレジスタ(TCR)設定用 */
  EN_HwPph_Mtu_SelPriscalerMtu0 enSelPriscaler;  /* タイマプリスケーラ選択 (TCR.TPSC) */
  EN_HwPph_Mtu_SelClkEdge       enSelClkEdge;    /* クロックエッジ選択 (TCR.CKEG) */
  EN_HwPph_Mtu_CntrClrMtu0      enCntrClr;       /* カウンタクリア (TCR.CCLR) */

  /* タイマモードレジスタ(TMDR)設定用 */
  EN_HwPph_Mtu_SelMdMtu0        enSelMd;         /* モード選択 (TMDR.MD) */
  U1                            u1BufA;          /* バッファ動作A (TMDR.BFA) [0:通常, 1:バッファ] */
  U1                            u1BufB;          /* バッファ動作B (TMDR.BFB) [0:通常, 1:バッファ] */
  U1                            u1BufE;          /* バッファ動作E (TMDR.BFE) [0:通常, 1:バッファ] */

  /* タイマI/Oコントロールレジスタ(TIOR)設定用 */
  EN_HwPph_Mtu_IoCtrlMtu0       enIoCtrlA;       /* I/OコントロールA (TIORH.IOA) */
  EN_HwPph_Mtu_IoCtrlMtu0       enIoCtrlB;       /* I/OコントロールB (TIORH.IOB) */
  EN_HwPph_Mtu_IoCtrlMtu0       enIoCtrlC;       /* I/OコントロールC (TIORL.IOC) */
  EN_HwPph_Mtu_IoCtrlMtu0       enIoCtrlD;       /* I/OコントロールD (TIORL.IOD) */

  /* タイマ割り込み許可レジスタ(TIER)設定用 */
  U1                            u1EnbTGIEA;      /* TGR割り込み許可A (TIER.TGIEA) [0:禁止, 1:許可] */
  U1                            u1EnbTGIEB;      /* TGR割り込み許可B (TIER.TGIEB) [0:禁止, 1:許可] */
  U1                            u1EnbTGIEC;      /* TGR割り込み許可C (TIER.TGIEC) [0:禁止, 1:許可] */
  U1                            u1EnbTGIED;      /* TGR割り込み許可D (TIER.TGIED) [0:禁止, 1:許可] */
  U1                            u1EnbTCIEV;      /* オーバフロー割り込み許可 (TIER.TCIEV) [0:禁止, 1:許可] */
                                                 /* アンダフロー割り込み許可 (TIER.TCIEU) [0:禁止, 1:許可] */ /* Memo:MTU0機能なし */
                                                 /* A/D変換開始要求許可2 (TIER.TTGE2) [0:禁止, 1:許可] */ /* Memo:MTU0機能なし */
  U1                            u1EnbTTGE;       /* A/D変換開始要求許可 (TIER.TTGE) [0:禁止, 1:許可] */
  U1                            u1EnbTGIEE;      /* TGR割り込み許可E (TIER.TGIEE) [0:禁止, 1:許可] */
  U1                            u1EnbTGIEF;      /* TGR割り込み許可F (TIER.TGIEF) [0:禁止, 1:許可] */

  /* タイマアウトプットマスタ許可レジスタ(TOER)設定用 */
                                                 /* マスタ許可MTIOC3B (TIER.OE3B) [0:禁止, 1:許可] */ /* Memo:MTU0機能なし */
                                                 /* マスタ許可MTIOC4A (TIER.OE4A) [0:禁止, 1:許可] */ /* Memo:MTU0機能なし */
                                                 /* マスタ許可MTIOC4B (TIER.OE4B) [0:禁止, 1:許可] */ /* Memo:MTU0機能なし */
                                                 /* マスタ許可MTIOC3D (TIER.OE3D) [0:禁止, 1:許可] */ /* Memo:MTU0機能なし */
                                                 /* マスタ許可MTIOC4C (TIER.OE4C) [0:禁止, 1:許可] */ /* Memo:MTU0機能なし */
                                                 /* マスタ許可MTIOC4D (TIER.OE4D) [0:禁止, 1:許可] */ /* Memo:MTU0機能なし */
} ST_HwPph_Mtu_CfgMtu0;

/* MTU1 */
/* ToDo:未実装 */

/* MTU2 */
/* ToDo:未実装 */

/* MTU3 */ /* ToDo:未実装機能あり */
typedef struct {
  /* タイマコントロールレジスタ(TCR)設定用 */
  EN_HwPph_Mtu_SelPriscalerMtu3 enSelPriscaler;  /* タイマプリスケーラ選択 (TCR.TPSC) */
  EN_HwPph_Mtu_SelClkEdge       enSelClkEdge;    /* クロックエッジ選択 (TCR.CKEG) */
  EN_HwPph_Mtu_CntrClrMtu3      enCntrClr;       /* カウンタクリア (TCR.CCLR) */

  /* タイマモードレジスタ(TMDR)設定用 */
  EN_HwPph_Mtu_SelMdMtu3        enSelMd;         /* モード選択 (TMDR.MD) */
  U1                            u1BufA;          /* バッファ動作A (TMDR.BFA) [0:通常, 1:バッファ] */
  U1                            u1BufB;          /* バッファ動作B (TMDR.BFB) [0:通常, 1:バッファ] */
                                                 /* バッファ動作E (TMDR.BFE) [0:通常, 1:バッファ] */ /* Memo:MTU3機能なし */

  /* タイマI/Oコントロールレジスタ(TIOR)設定用 */
  EN_HwPph_Mtu_IoCtrlMtu3       enIoCtrlA;       /* I/OコントロールA (TIORH.IOA) */
  EN_HwPph_Mtu_IoCtrlMtu3       enIoCtrlB;       /* I/OコントロールB (TIORH.IOB) */
  EN_HwPph_Mtu_IoCtrlMtu3       enIoCtrlC;       /* I/OコントロールC (TIORL.IOC) */
  EN_HwPph_Mtu_IoCtrlMtu3       enIoCtrlD;       /* I/OコントロールD (TIORL.IOD) */

  /* タイマ割り込み許可レジスタ(TIER)設定用 */
  U1                            u1EnbTGIEA;      /* TGR割り込み許可A (TIER.TGIEA) [0:禁止, 1:許可] */
  U1                            u1EnbTGIEB;      /* TGR割り込み許可B (TIER.TGIEB) [0:禁止, 1:許可] */
  U1                            u1EnbTGIEC;      /* TGR割り込み許可C (TIER.TGIEC) [0:禁止, 1:許可] */
  U1                            u1EnbTGIED;      /* TGR割り込み許可D (TIER.TGIED) [0:禁止, 1:許可] */
  U1                            u1EnbTCIEV;      /* オーバフロー割り込み許可 (TIER.TCIEV) [0:禁止, 1:許可] */
                                                 /* アンダフロー割り込み許可 (TIER.TCIEU) [0:禁止, 1:許可] */ /* Memo:MTU3機能なし */
                                                 /* A/D変換開始要求許可2 (TIER.TTGE2) [0:禁止, 1:許可] */ /* Memo:MTU3機能なし */
  U1                            u1EnbTTGE;       /* A/D変換開始要求許可 (TIER.TTGE) [0:禁止, 1:許可] */
                                                 /* TGR割り込み許可E (TIER.TGIEE) [0:禁止, 1:許可] */ /* Memo:MTU3機能なし */
                                                 /* TGR割り込み許可F (TIER.TGIEF) [0:禁止, 1:許可] */ /* Memo:MTU3機能なし */

  /* タイマアウトプットマスタ許可レジスタ(TOER)設定用 */
  U1                            u1EnbMTIOC3B;    /* マスタ許可MTIOC3B (TIER.OE3B) [0:禁止, 1:許可] */
                                                 /* マスタ許可MTIOC4A (TIER.OE4A) [0:禁止, 1:許可] */ /* Memo:MTU3機能なし */
                                                 /* マスタ許可MTIOC4B (TIER.OE4B) [0:禁止, 1:許可] */ /* Memo:MTU3機能なし */
  U1                            u1EnbMTIOC3D;    /* マスタ許可MTIOC3D (TIER.OE3D) [0:禁止, 1:許可] */
                                                 /* マスタ許可MTIOC4C (TIER.OE4C) [0:禁止, 1:許可] */ /* Memo:MTU3機能なし */
                                                 /* マスタ許可MTIOC4D (TIER.OE4D) [0:禁止, 1:許可] */ /* Memo:MTU3機能なし */
} ST_HwPph_Mtu_CfgMtu3;

/* MTU4 */ /* ToDo:未実装機能あり */
typedef struct {
  /* タイマコントロールレジスタ(TCR)設定用 */
  EN_HwPph_Mtu_SelPriscalerMtu4 enSelPriscaler;  /* タイマプリスケーラ選択 (TCR.TPSC) */
  EN_HwPph_Mtu_SelClkEdge       enSelClkEdge;    /* クロックエッジ選択 (TCR.CKEG) */
  EN_HwPph_Mtu_CntrClrMtu4      enCntrClr;       /* カウンタクリア (TCR.CCLR) */

  /* タイマモードレジスタ(TMDR)設定用 */
  EN_HwPph_Mtu_SelMdMtu4        enSelMd;         /* モード選択 (TMDR.MD) */
  U1                            u1BufA;          /* バッファ動作A (TMDR.BFA) [0:通常, 1:バッファ] */
  U1                            u1BufB;          /* バッファ動作B (TMDR.BFB) [0:通常, 1:バッファ] */
                                                 /* バッファ動作E (TMDR.BFE) [0:通常, 1:バッファ] */ /* Memo:MTU4機能なし */

  /* タイマI/Oコントロールレジスタ(TIOR)設定用 */
  EN_HwPph_Mtu_IoCtrlMtu4       enIoCtrlA;       /* I/OコントロールA (TIORH.IOA) */
  EN_HwPph_Mtu_IoCtrlMtu4       enIoCtrlB;       /* I/OコントロールB (TIORH.IOB) */
  EN_HwPph_Mtu_IoCtrlMtu4       enIoCtrlC;       /* I/OコントロールC (TIORL.IOC) */
  EN_HwPph_Mtu_IoCtrlMtu4       enIoCtrlD;       /* I/OコントロールD (TIORL.IOD) */

  /* タイマ割り込み許可レジスタ(TIER)設定用 */
  U1                            u1EnbTGIEA;      /* TGR割り込み許可A (TIER.TGIEA) [0:禁止, 1:許可] */
  U1                            u1EnbTGIEB;      /* TGR割り込み許可B (TIER.TGIEB) [0:禁止, 1:許可] */
  U1                            u1EnbTGIEC;      /* TGR割り込み許可C (TIER.TGIEC) [0:禁止, 1:許可] */
  U1                            u1EnbTGIED;      /* TGR割り込み許可D (TIER.TGIED) [0:禁止, 1:許可] */
  U1                            u1EnbTCIEV;      /* オーバフロー割り込み許可 (TIER.TCIEV) [0:禁止, 1:許可] */
                                                 /* アンダフロー割り込み許可 (TIER.TCIEU) [0:禁止, 1:許可] */ /* Memo:MTU4機能なし */
  U1                            u1EnbTTGE2;      /* A/D変換開始要求許可2 (TIER.TTGE2) [0:禁止, 1:許可] */
  U1                            u1EnbTTGE;       /* A/D変換開始要求許可 (TIER.TTGE) [0:禁止, 1:許可] */
                                                 /* TGR割り込み許可E (TIER.TGIEE) [0:禁止, 1:許可] */ /* Memo:MTU4機能なし */
                                                 /* TGR割り込み許可F (TIER.TGIEF) [0:禁止, 1:許可] */ /* Memo:MTU4機能なし */

  /* タイマアウトプットマスタ許可レジスタ(TOER)設定用 */
                                                 /* マスタ許可MTIOC3B (TIER.OE3B) [0:禁止, 1:許可] */ /* Memo:MTU4機能なし */
  U1                            u1EnbMTIOC4A;    /* マスタ許可MTIOC4A (TIER.OE4A) [0:禁止, 1:許可] */
  U1                            u1EnbMTIOC4B;    /* マスタ許可MTIOC4B (TIER.OE4B) [0:禁止, 1:許可] */
                                                 /* マスタ許可MTIOC3D (TIER.OE3D) [0:禁止, 1:許可] */ /* Memo:MTU4機能なし */
  U1                            u1EnbMTIOC4C;    /* マスタ許可MTIOC4C (TIER.OE4C) [0:禁止, 1:許可] */
  U1                            u1EnbMTIOC4D;    /* マスタ許可MTIOC4D (TIER.OE4D) [0:禁止, 1:許可] */
} ST_HwPph_Mtu_CfgMtu4;

/* MTU5 */
/* ToDo:未実装 */


/* ============================================================ */
/* 関数プロトタイプ宣言(extern)                                 */
/* ============================================================ */
/* MTU1,2,5未実装 */
extern VD FnVD_HwPph_Mtu_resetModuleStp(VD);
extern VD FnVD_HwPph_Mtu_stpModuleStp(VD);
extern VD FnVD_HwPph_Mtu_ctrlStpAndGo(U1 tu1Enb, U1 tu1Req);
extern VD FnVD_HwPph_Mtu_cfgMtu0(const ST_HwPph_Mtu_CfgMtu0 * tpstCfg);
extern VD FnVD_HwPph_Mtu_cfgMtu3(const ST_HwPph_Mtu_CfgMtu3 * tpstCfg);
extern VD FnVD_HwPph_Mtu_cfgMtu4(const ST_HwPph_Mtu_CfgMtu4 * tpstCfg);
extern U2 FnU2_HwPph_Mtu_getTimerCounter(EN_HwPph_Mtu_IdTCNT tenId);
extern VD FnVD_HwPph_Mtu_setTimerCounter(EN_HwPph_Mtu_IdTCNT tenId, U2 tu2Val);
extern VD FnVD_HwPph_Mtu_setTimerGeneralRegister(EN_HwPph_Mtu_IdTGR tenId, U2 tu2Val);


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
