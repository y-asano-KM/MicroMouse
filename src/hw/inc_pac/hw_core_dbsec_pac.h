#if !defined(INCLUDED_hw_core_dbsec_pac_h)
#define INCLUDED_hw_core_dbsec_pac_h
/* ============================================================ */
/* ファイル名 : hw_core_dbsec_pac.h                             */
/* 機能       : スタートアップルーチン                          */
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
#define CU1_HwCode_DbSec_SizeRomRamValTbl              ((U1)7)
#define CU1_HwCode_DbSec_SizeRamTbl                    ((U1)7)
#define CU1_HwCode_DbSec_SizeSuppressLinkerWarningTbl  ((U1)17)


/* ============================================================ */
/* 型定義                                                       */
/* ============================================================ */
typedef struct {
  U1 * pu1RomValSta;      /* Start address of the initialized data section in ROM */
  U1 * pu1RomValEnd;      /* End address of the initialized data section in ROM   */
  U1 * pu1RamValSta;      /* Start address of the initialized data section in RAM */
} ST_DTBL;

typedef struct {
  U1 * pu1RamSta;         /* Start address of non-initialized data section */
  U1 * pu1RamEnd;         /* End address of non-initialized data section */
} ST_BTBL;


/* ============================================================ */
/* 関数プロトタイプ宣言(extern)                                 */
/* ============================================================ */
extern VD FnVD_HwCore_DbSec_initRamVal(VD);


/* ============================================================ */
/* 変数宣言(extern)                                             */
/* ============================================================ */


/* ============================================================ */
/* const変数宣言(extern)                                        */
/* ============================================================ */
extern const ST_DTBL CSTA_HwCode_DbSec_RomRamValTbl[CU1_HwCode_DbSec_SizeRomRamValTbl];
extern const ST_BTBL CSTA_HwCode_DbSec_RamTbl[CU1_HwCode_DbSec_SizeRamTbl];
extern const U1 * const CPU1A_HwCode_DbSec_SuppressLinkerWarningTbl[CU1_HwCode_DbSec_SizeSuppressLinkerWarningTbl];


/* ============================================================ */
/* 関数形式マクロ定義                                           */
/* ============================================================ */


#endif
