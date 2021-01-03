/* ============================================================ */
/* ファイル名 : hw_pph_mtu.c                                    */
/* 機能       : MTU処理                                         */
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
#include "hw_pph_reg_pac.h"

/* 本体 */
#include "hw_pph_mtu_pac.h"


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
volatile const U1 __evenaccess * CPU1_MTU3_TCR        = &stRegMTU.stMTU3_TCR.u1Val;
volatile const U1 __evenaccess * CPU1_MTU_TGCR        = &stRegMTU.stMTU_TGCR;
volatile const U1 __evenaccess * CPU1_MTU_TITCR       = &stRegMTU.stMTU_TITCR;
volatile const U1 __evenaccess * CPU1_MTU_TDER        = &stRegMTU.stMTU_TDER;
volatile const U1 __evenaccess * CPU1_MTU_TOLBR       = &stRegMTU.stMTU_TOLBR;
volatile const U1 __evenaccess * CPU1_MTU3_TBTM       = &stRegMTU.stMTU3_TBTM;
volatile const U2 __evenaccess * CPU2_MTU4_TADCR      = &stRegMTU.stMTU4_TADCR;
volatile const U2 __evenaccess * CPU2_MTU4_TADCORA    = &stRegMTU.stMTU4_TADCORA;
volatile const U1 __evenaccess * CPU1_MTU_TWCR        = &stRegMTU.stMTU_TWCR;
volatile const U1 __evenaccess * CPU1_MTU_TSTR        = &stRegMTU.stMTU_TSTR.u1Val;
volatile const U1 __evenaccess * CPU1_MTU_TRWER       = &stRegMTU.stMTU_TRWER;
volatile const U1 __evenaccess * CPU1_MTU0_NFCR       = &stRegMTU.stMTU0_NFCR;
volatile const U1 __evenaccess * CPU1_MTU0_TCR        = &stRegMTU.stMTU0_TCR.u1Val;
volatile const U2 __evenaccess * CPU2_MTU0_TGRE       = &stRegMTU.stMTU0_TGRE.u2Val;
volatile const U1 __evenaccess * CPU1_MTU0_TBTM       = &stRegMTU.stMTU0_TBTM;
volatile const U1 __evenaccess * CPU1_MTU1_TCR        = &stRegMTU.stMTU1_TCR.u1Val;
volatile const U1 __evenaccess * CPU1_MTU1_TIER       = &stRegMTU.stMTU1_TIER.u1Val;
volatile const U1 __evenaccess * CPU1_MTU1_TICCR      = &stRegMTU.stMTU1_TICCR;
volatile const U1 __evenaccess * CPU1_MTU2_TCR        = &stRegMTU.stMTU2_TCR.u1Val;
volatile const U1 __evenaccess * CPU1_MTU2_TIER       = &stRegMTU.stMTU2_TIER.u1Val;
volatile const U2 __evenaccess * CPU2_MTU5_TCNTU      = &stRegMTU.stMTU5_TCNTU.u2Val;
volatile const U1 __evenaccess * CPU1_MTU5_TIORU      = &stRegMTU.stMTU5_TIORU.u1Val;
volatile const U2 __evenaccess * CPU2_MTU5_TCNTV      = &stRegMTU.stMTU5_TCNTV.u2Val;
volatile const U1 __evenaccess * CPU1_MTU5_TIORV      = &stRegMTU.stMTU5_TIORV.u1Val;
volatile const U2 __evenaccess * CPU2_MTU5_TCNTW      = &stRegMTU.stMTU5_TCNTW.u2Val;
volatile const U1 __evenaccess * CPU1_MTU5_TIORW      = &stRegMTU.stMTU5_TIORW.u1Val;
volatile const U1 __evenaccess * CPU1_MTU5_TIER       = &stRegMTU.stMTU5_TIER.u1Val;
volatile const U1 __evenaccess * CPU1_MTU5_TSTR       = &stRegMTU.stMTU5_TSTR.u1Val;
volatile const U1 __evenaccess * CPU1_MTU5_TCNTCMPCLR = &stRegMTU.stMTU5_TCNTCMPCLR;
volatile const U1 __evenaccess * CPU1_MTU_DMY         = &stRegMTU.u1aDmy28[72];


/* ============================================================ */
/* const変数定義(static)                                        */
/* ============================================================ */


/* ============================================================ */
/* 関数形式マクロ定義                                           */
/* ============================================================ */


/* ============================================================ */
/* 関数定義                                                     */
/* ============================================================ */
/* 未実装 */
