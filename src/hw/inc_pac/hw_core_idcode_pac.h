#if !defined(INCLUDED_hw_core_idcode_pac_h)
#define INCLUDED_hw_core_idcode_pac_h
/* ============================================================ */
/* ファイル名 : hw_core_idcode_pac.h                            */
/* 機能       : IDコード定義                                    */
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
#define CU1_HwCore_IdCode_SizeData    ((U1)15)


/* ============================================================ */
/* 型定義                                                       */
/* ============================================================ */
typedef struct {
  U1 u1CtrlCode;                             /* 制御コード */
  U1 u1aIdCode[CU1_HwCore_IdCode_SizeData];  /* IDコードn (n=1-15) */
} ST_HwCore_IdCode_Data;


/* ============================================================ */
/* 関数プロトタイプ宣言(extern)                                 */
/* ============================================================ */


/* ============================================================ */
/* 変数宣言(extern)                                             */
/* ============================================================ */


/* ============================================================ */
/* const変数宣言(extern)                                        */
/* ============================================================ */
extern const ST_HwCore_IdCode_Data CST_HwCore_IdCode_Data;


/* ============================================================ */
/* 関数形式マクロ定義                                           */
/* ============================================================ */


#endif