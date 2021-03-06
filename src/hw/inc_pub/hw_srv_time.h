#if !defined(INCLUDED_hw_srv_time_h)
#define INCLUDED_hw_srv_time_h
/* ============================================================ */
/* ファイル名 : hw_srv_time.h                                   */
/* 機能       : 時刻処理                                        */
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

/* 個別 */

/* 本体 */


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */
/* CMCNT0レジスタ */ /* 現在時刻取得用 */
#define CU2_HwSrv_Time_ClkReg    ((volatile U2 __evenaccess *)0x00088004)

/* [us]クロックLSB */ /* CFL_HwPph_Cmt_CfgUnit0CntClkFreq */
#define CFL_HwSrv_Time_ClkLsb    ((FL)((FL)1.0F / (FL)1.5F))

/* クロックマスク */
#define CU2_HwSrv_Time_ClkMsk    ((U2)0x7FFF)

/* クロック最大値 */
#define CU2_HwSrv_Time_ClkMax    ((U2)0x7FFF)


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


/* ============================================================ */
/* 関数形式マクロ定義                                           */
/* ============================================================ */
/* ============================================================ */
/* 関数名 : McU2_HwSrv_Time_getClk                              */
/*          現在時刻取得                                        */
/* 引数   : なし                                                */
/* 戻り値 : [クロック]現在時刻                                  */
/*          (LSB:CFL_HwSrv_Time_ClkLsb)                         */
/* 概要   : 現在時刻を返す                                      */
/* 制約   : なし                                                */
/* ============================================================ */
#define McU2_HwSrv_Time_getClk()  ((U2)((*CU2_HwSrv_Time_ClkReg) & CU2_HwSrv_Time_ClkMsk))


/* ============================================================ */
/* 関数名 : McU2_HwSrv_Time_calElapsedTime                      */
/*          経過時間演算                                        */
/* 引数   : tu2TimCur   [クロック数]現在時刻                    */
/*          tu2TimBase  [クロック数]基点時刻                    */
/* 戻り値 : [クロック数]経過時間                                */
/*          (LSB:CFL_HwSrv_Time_ClkLsb)                         */
/* 概要   : タイマーを初期化する                                */
/* 制約   :                                                     */
/* ============================================================ */
#define McU2_HwSrv_Time_calElapsedTime(tu2TimCur, tu2TimBase)  ((U2)((U2)((tu2TimCur) - (tu2TimBase)) & CU2_HwSrv_Time_ClkMsk))


#endif
