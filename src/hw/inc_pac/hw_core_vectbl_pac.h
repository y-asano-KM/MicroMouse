#if !defined(INCLUDED_hw_core_vectbl_pac_h)
#define INCLUDED_hw_core_vectbl_pac_h
/* ============================================================ */
/* ファイル名 : hw_core_vectbl_pach                             */
/* 機能       : ベクタテーブル定義                              */
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
#define CU2_HwCore_VecTbl_Size          ((U2)256)
#define CU1_HwCore_VecTbl_SizeIdCode    ((U1)4)
#define CU1_HwCore_VecTbl_SizeFixed     ((U1)12)

/* ============================================================ */
/* 型定義                                                       */
/* ============================================================ */


/* ============================================================ */
/* 関数プロトタイプ宣言(extern)                                 */
/* ============================================================ */


/* ============================================================ */
/* 変数宣言(extern)                                             */
/* ============================================================ */


/* ============================================================ */
/* const変数宣言(extern)                                        */
/* ============================================================ */
extern VD (* const CPFnVD_HwCore_VecTbl[CU2_HwCore_VecTbl_Size])(VD);
extern const U4 CU4_HwCode_VecTbl_MdeReg;
extern const U4 CU4_HwCore_VecTbl_IdCode[CU1_HwCore_VecTbl_SizeIdCode];
extern VD (* const CPFnVD_HwCore_VecTblFixed[CU1_HwCore_VecTbl_SizeFixed])(VD);

/* ============================================================ */
/* 関数形式マクロ定義                                           */
/* ============================================================ */


#endif
