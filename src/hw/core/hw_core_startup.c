/* ============================================================ */
/* ファイル名 : hw_core_startup.c                               */
/* 機能       : スタートアップルーチン                          */
/* ============================================================ */
/* ToDo:将来的にはアセンブリで記述し、ライブラリ提供の関数は使用しない設計とする */
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
#include <_h_c_lib.h>
#include "hw_core_junction_pac.h"

/* 本体 */
#include "hw_core_startup_pac.h"


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */
#define CU4_HwCore_Startup_PswInitVal    ((U4)0x00000000)     /* PSW初期値(I:割り込み禁止, U:ISP, PM:SVモード, IPL:最低優先) */
#define CU4_HwCore_Startup_FpswInitVal   ((U4)0x00000000)     /* FPSW bit base pattern */
#if defined(__FPU)
  #if defined(__ROZ)                   /* Initialize FPSW */
    #define CU4_HwCore_Startup_FpswRm    ((U4)0x00000001)     /* Let FPSW RMbits=01 (round to zero) */
  #else
    #define CU4_HwCore_Startup_FpswRm    ((U4)0x00000000)     /* Let FPSW RMbits=00 (round to nearest) */
  #endif
  #if defined(__DOFF)
    #define CU4_HwCore_Startup_FpswDn    ((U4)0x00000100)     /* Let FPSW DNbit=1 (denormal as zero) */
  #else
    #define CU4_HwCore_Startup_FpswDn    ((U4)0x00000000)     /* Let FPSW DNbit=0 (denormal as is) */
  #endif
  #define CU4_HwCore_Startup_SetFpswVal  ((U4)(  CU4_HwCore_Startup_FpswInitVal \
                                               | CU4_HwCore_Startup_FpswRm \
                                               | CU4_HwCore_Startup_FpswDn))
#endif


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
/* スタックサイズ指定                                           */
/* ============================================================ */
/* Memo:SVモードしか使わない設計のためSUの設定は不要だが念のため設定する */
/* Memo:アドレスとサイズはメモリマップの設計に依存する */
#pragma stacksize su=0x7F8
#pragma stacksize si=0x7F8


/* ============================================================ */
/* 関数定義                                                     */
/* ============================================================ */

#pragma section
#pragma section ResetPRG
#pragma entry FnVD_HwCore_Startup_handleResetException
/* ============================================================ */
/* 関数名 : FnVD_HwCore_Startup_handleResetException            */
/*          スタートアップ処理                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : スタートアップ処理とユーザープログラムへ移行        */
/* 制約   : 割り込み禁止区間であること                          */
/* ============================================================ */
VD FnVD_HwCore_Startup_handleResetException(VD)
{ 
  /* PSWレジスタ初期化(割り込み禁止のDI()を含む) */
  __set_psw(CU4_HwCore_Startup_PswInitVal);

  /* 例外ベクタベースアドレス設定 */
#if defined(__RXV2)
  __set_extb(__sectop("EXCEPTVECT"));
#endif
  __set_intb(__sectop("C$VECT"));

#if defined(__FPU)
  /* FPU設定 */
  __set_fpsw(CU4_HwCore_Startup_SetFpswVal);
#endif

  /* RAM初期化 */
  _INITSCT();

  /* ユーザプログラムへ移行 */
  FnVD_HwCore_Junction_shiftUserProgram();
}
/* セクションをユーザー定義に戻す */
#include "prj_cmn_section.h"

