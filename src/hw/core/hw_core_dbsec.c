/* ============================================================ */
/* ファイル名 : hw_core_dbsec.c                                 */
/* 機能       : セクション情報                                  */
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
/* スタートアップで初期化子付き静的変数を初期化するために使用するテーブル */
const ST_DTBL CST_DTBL[] = {
/* pu1RomValSta,           pu1RomValEnd,           pu1RamValSta            */
  {__sectop("D"),          __secend("D"),          __sectop("R")         },
  {__sectop("D_2"),        __secend("D_2"),        __sectop("R_2")       },
  {__sectop("D_1"),        __secend("D_1"),        __sectop("R_1")       },
  {__sectop("ROMVAL_PRJ"), __secend("ROMVAL_PRJ"), __sectop("RAMVAL_PRJ")},
  {__sectop("ROMVAL_HW"),  __secend("ROMVAL_HW"),  __sectop("RAMVAL_HW") },
  {__sectop("ROMVAL_PF"),  __secend("ROMVAL_PF"),  __sectop("RAMVAL_PF") },
  {__sectop("ROMVAL_APP"), __secend("ROMVAL_APP"), __sectop("RAMVAL_APP")}
};

#pragma section C C$BSEC
/* 静的変数のデータ領域 */
/* スタートアップで静的変数を0クリアするために使用するテーブル */
const ST_BTBL CST_BTBL[] = {
/* pu1RamSta,           pu1RamEnd,           */
  {__sectop("B"),       __secend("B")      },
  {__sectop("B_2"),     __secend("B_2")    },
  {__sectop("RAM_PRJ"), __secend("RAM_PRJ")},
  {__sectop("RAM_HW"),  __secend("RAM_HW") },
  {__sectop("RAM_PF"),  __secend("RAM_PF") },
  {__sectop("RAM_APP"), __secend("RAM_APP")}
};
/* デフォルトセクションとする */
#pragma section

/* CTBL prevents excessive output of L1100 messages when linking.         */
/* Even if CTBL is deleted, the operation of the program does not change. */
U1 * const CPU1_CTBL[] = {
  __sectop("C_1"),
  __sectop("C_2"),
  __sectop("C"),
  __sectop("CONST_PRJ"),
  __sectop("CONST_HW"),
  __sectop("CONST_PF"),
  __sectop("CONST_APP"),
  __sectop("W_1"),
  __sectop("W_2"),
  __sectop("W"),
  __sectop("L"),
  __sectop("SU"),
  __sectop("C$DSEC"),
  __sectop("C$BSEC"),
  __sectop("C$INIT"),
  __sectop("C$VTBL"),
  __sectop("C$VECT")
};
#pragma packoption

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
