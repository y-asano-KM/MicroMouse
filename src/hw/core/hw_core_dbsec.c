/* ============================================================ */
/* ファイル名 : hw_core_dbsec.c                                 */
/* 機能       : セクション情報                                  */
/* ============================================================ */
/* ToDo:ライブラリ関数_INITSCTの代替処理を実装する */
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

/* 本体 */
#include "hw_core_dbsec_pac.h"


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
#pragma unpack
#pragma section C C$DSEC
/* 初期化子付き静的変数のデータ領域 */
/* Memo:スタートアップで初期化子付き静的変数を初期化するために使用するテーブル */
/* Memo:最適化防止のためわざとグローバル宣言とする(static volatileとはしない) */
const ST_DTBL CSTA_HwCode_DbSec_RomRamValTbl[CU1_HwCode_DbSec_SizeRomRamValTbl] = {
/* pu1RomValSta,           pu1RomValEnd,           pu1RamValSta            */
  {(U1 *)__sectop("D"),          (U1 *)__secend("D"),          (U1 *)__sectop("R")         },
  {(U1 *)__sectop("D_2"),        (U1 *)__secend("D_2"),        (U1 *)__sectop("R_2")       },
  {(U1 *)__sectop("D_1"),        (U1 *)__secend("D_1"),        (U1 *)__sectop("R_1")       },
  {(U1 *)__sectop("ROMVAL_PRJ"), (U1 *)__secend("ROMVAL_PRJ"), (U1 *)__sectop("RAMVAL_PRJ")},
  {(U1 *)__sectop("ROMVAL_HW"),  (U1 *)__secend("ROMVAL_HW"),  (U1 *)__sectop("RAMVAL_HW") },
  {(U1 *)__sectop("ROMVAL_PF"),  (U1 *)__secend("ROMVAL_PF"),  (U1 *)__sectop("RAMVAL_PF") },
  {(U1 *)__sectop("ROMVAL_APP"), (U1 *)__secend("ROMVAL_APP"), (U1 *)__sectop("RAMVAL_APP")}
};

#pragma section C C$BSEC
/* 静的変数のデータ領域 */
/* Memo:スタートアップで静的変数を0クリアするために使用するテーブル */
/* Memo:最適化防止のためわざとグローバル宣言とする(static volatileとはしない) */
const ST_BTBL CSTA_HwCode_DbSec_RamTbl[CU1_HwCode_DbSec_SizeRamTbl] = {
/* pu1RamSta,           pu1RamEnd,           */
  {(U1 *)__sectop("B"),       (U1 *)__secend("B")      },
  {(U1 *)__sectop("B_2"),     (U1 *)__secend("B_2")    },
  {(U1 *)__sectop("B_1"),     (U1 *)__secend("B_1")    },
  {(U1 *)__sectop("RAM_PRJ"), (U1 *)__secend("RAM_PRJ")},
  {(U1 *)__sectop("RAM_HW"),  (U1 *)__secend("RAM_HW") },
  {(U1 *)__sectop("RAM_PF"),  (U1 *)__secend("RAM_PF") },
  {(U1 *)__sectop("RAM_APP"), (U1 *)__secend("RAM_APP")}
};
/* デフォルトセクションとする */
#pragma section
#pragma packoption

/* セクションをユーザー定義に戻す */
#include "prj_cmn_section.h"

/* Memo:未使用のセクションが存在する場合にリンカが警告を出力するためその対策としてCTBLをダミーで定義している(W0561100) */
/* Memo:最適化防止のためわざとグローバル宣言とする(static volatileとはしない) */
const U1 * const CPU1A_HwCode_DbSec_SuppressLinkerWarningTbl[CU1_HwCode_DbSec_SizeSuppressLinkerWarningTbl] = {
  (U1 *)__sectop("SU"),
  (U1 *)__sectop("RAM_BEGIN"),
  (U1 *)__sectop("RAM_END"),
  (U1 *)__sectop("ROM_BEGIN"),
  (U1 *)__sectop("C_1"),
  (U1 *)__sectop("C_2"),
  (U1 *)__sectop("C"),
  (U1 *)__sectop("C$DSEC"),
  (U1 *)__sectop("C$BSEC"),
  (U1 *)__sectop("C$INIT"),
  (U1 *)__sectop("C$VTBL"),
  (U1 *)__sectop("W_1"),
  (U1 *)__sectop("W_2"),
  (U1 *)__sectop("W"),
  (U1 *)__sectop("L"),
  (U1 *)__sectop("C$VECT"),
  (U1 *)__sectop("PROG_END")
};


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
/* 関数名 : FnVD_HwCore_DbSec_initRamVal                        */
/*          RAM初期化                                           */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 初期値なしは0, 初期値ありは初期値を設定する         */
/* 制約   : 割り込み禁止区間であること                          */
/* ============================================================ */
VD FnVD_HwCore_DbSec_initRamVal(VD)
{
  /* ToDo:_INITSCTの代替処理を実装すること */
  _INITSCT();
}

