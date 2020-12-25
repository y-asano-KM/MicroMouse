#if !defined(INCLUDED_prj_cmn_option_h)
#define INCLUDED_prj_cmn_option_h
/* ================================================== */
/* ファイル名 : prj_cmn_option.h                      */
/* 機能       : 共通オプション定義                    */
/* ================================================== */

/* ================================================== */
/* オプション定義                                     */
/* ================================================== */
/* Long型8バイト環境 */
/* #define OP_PrjCmn_LongSize8 */

/* [排他]エンディアン選択 */
#define OP_PrjCmn_LittleEndian
/* #define OP_PrjCmn_BigEndian */

/* [ms]メインスケジュール周期 */
#define CU1_PrjCmn_MainPeriod      ((U1)5)

/* [ms]1ms割り込み周期 */
#define CU1_PrjCmn_Int1msPeriod    ((U1)1)


/* ================================================== */
/* オプションチェック                                 */
/* ================================================== */
#include "prj_cmn_chk_option.h"

#endif
