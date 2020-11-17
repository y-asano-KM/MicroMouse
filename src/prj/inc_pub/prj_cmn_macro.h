#if !defined(INCLUDED_prj_cmn_macro_h)
#define INCLUDED_prj_cmn_macro_h
/* ================================================== */
/* ファイル名 : prj_cmn_macro.h                       */
/* 機能       : 汎用マクロ義                          */
/* ================================================== */

/* ================================================== */
/* インクルード                                       */
/* ================================================== */
#include "prj_cmn_option.h"

/* ================================================== */
/* マクロ定数定義                                     */
/* ================================================== */
/* ---------------- */
/* 型の最大値の定義 */
/* ---------------- */
#define CU1_Max    ((U1)0xFFU)                      /* 符号なし1バイト型の最大値 */
#define CU2_Max    ((U2)0xFFFFU)                    /* 符号なし2バイト型の最大値 */
#define CU4_Max    ((U4)0xFFFFFFFFU)                /* 符号なし4バイト型の最大値 */
#define CU8_Max    ((U8)0xFFFFFFFFFFFFFFFFU)        /* 符号なし8バイト型の最大値 */
#define CS1_Max    ((S1)0x7F)                       /* 符号付き1バイト型の最大値 */
#define CS2_Max    ((S2)0x7FFF)                     /* 符号付き2バイト型の最大値 */
#define CS4_Max    ((S4)0x7FFFFFFF)                 /* 符号付き4バイト型の最大値 */
#define CS8_Max    ((S8)0x7FFFFFFFFFFFFFFF)         /* 符号付き8バイト型の最大値 */
#define CFL_Max    ((FL)3.402823466E+38F)           /* 単精度浮動小数型の最大値  */
#define CDB_Max    ((DB)1.7976931348623158E+308)    /* 倍精度浮動小数型の最大値  */

/* ---------------- */
/* 型の最小値の定義 */
/* ---------------- */
#define CU1_Min    ((U1)0x00U)                      /* 符号なし1バイト型の最小値 */
#define CU2_Min    ((U2)0x0000U)                    /* 符号なし2バイト型の最小値 */
#define CU4_Min    ((U4)0x00000000U)                /* 符号なし4バイト型の最小値 */
#define CU8_Min    ((U8)0x0000000000000000U)        /* 符号なし8バイト型の最小値 */
#define CS1_Min    ((S1)0x80)                       /* 符号付き1バイト型の最小値 */
#define CS2_Min    ((S2)0x8000)                     /* 符号付き2バイト型の最小値 */
#define CS4_Min    ((S4)0x80000000)                 /* 符号付き4バイト型の最小値 */
#define CS8_Min    ((S8)0x8000000000000000)         /* 符号付き8バイト型の最小値 */
#define CFL_Min    ((FL)(-CFL_Max))                 /* 単精度浮動小数型の最小値  */
#define CDB_Min    ((DB)(-CDB_Max))                 /* 倍精度浮動小数型の最小値  */

/* --------------- */
/* 実数型の0近傍値 */
/* --------------- */
#define CFL_Sml    ((FL)1.175494351E-38F)           /* 単精度浮動小数型の最小0近傍値  */
#define CDB_Sml    ((DB)2.2250738585072014E-308)    /* 倍精度浮動小数型の最小0近傍値  */

/* ---------------------- */
/* 演算機イプシロンの定義 */
/* ---------------------- */
#define CFL_Eps    ((FL)1.0E-6F)                    /* 単精度浮動小数の演算機イプシロン */
#define CDB_Eps    ((DB)1.0E-10)                    /* 倍精度浮動小数の演算機イプシロン */

/* -------------- */
/* 数学定数の定義 */
/* -------------- */
#define CDB_Pi         ((DB)3.1415926535897932)    /* 円周率 */
#define CFL_Pi         ((FL)CDB_Pi)                /* 円周率 */
#define CDB_Exp        ((DB)2.7182818284590452)    /* 自然対数の底 */
#define CFL_Exp        ((FL)CDB_Exp)               /* 自然対数の底 */
#define CSI_SgnM       (-1)                        /* 符号- */
#define CSI_SgnN       (0)                         /* 符号なし(0) */
#define CSI_SgnP       (1)                         /* 符号+ */

/* -------------- */
/* 物理定数の定義 */
/* -------------- */
#define CDB_G          ((DB)9.80665)               /* [m/s^2]標準重力加速度 */
#define CFL_G          ((FL)CDB_G)                 /* [m/s^2]標準重力加速度 */
#define CDB_RaySpd     ((DB)3.0E+8)                /* [m/s]光速 */
#define CFL_RaySpd     ((FL)CDB_RaySpd)            /* [m/s]光速 */

/* -------------------- */
/* フラグ型設定値の定義 */
/* -------------------- */
#define C_OFF          (0)                         /* フラグ OFF */
#define C_ON           (1)                         /* フラグ ON  */

/* ---------- */
/* NULL値定義 */
/* ---------- */
#define CAC_NULL       ((AC)0)                     /* 文字型NULL値 */
#define CPVD_NULL      ((VD *)0)                   /* ポインタ型NULL値 */

/* ================================================== */
/* 関数形式マクロ定義                                 */
/* ================================================== */
/* ========================================================= */
/* マクロ名 : McXX_selMin/Max                                */
/* 概要     : 最小値/最大値選択                              */
/* 周期     : なし                                           */
/* 戻り値   : 最小値/最大値                                  */
/* 引数     : axxA  入力A                                    */
/*            axxB  入力B                                    */
/* 制約     : 引数の型を合わせること。                       */
/* 詳細     : 入力a,bを比較し、小さい方/大きい方の値を返す。 */
/* ========================================================= */
#define McXX_selMin(axxA, axxB)          (((axxA) > (axxB)) ? (axxB) : (axxA))
#define McXX_selMax(axxA, axxB)          (((axxA) > (axxB)) ? (axxA) : (axxB))


/* ========================================================= */
/* マクロ名 : McXX_grdMin/Max/Med                            */
/* 概要     : 最小値/最大値ガード                            */
/* 周期     : なし                                           */
/* 戻り値   : 最小値/最大値ガード後の値                      */
/* 引数     : axxVal  入力値                                 */
/*            axxTh   閾値                                   */
/*            axxThL  下限閾値                               */
/*            axxThH  上限閾値                               */
/* 制約     : 引数の型を合わせること。                       */
/* 詳細     : 閾値内の場合は、入力値を返す。                 */
/*            閾値を超える場合、閾値を返す。                 */
/* ========================================================= */
#define McXX_grdMin(axxVal, axxTh)              McXX_selMax((axxVal), (axxTh))
#define McXX_grdMax(axxVal, axxTh)              McXX_selMin((axxVal), (axxTh))
#define McXX_grdMed(axxVal, axxThL, axxThH)     McXX_grdMax(McXX_grdMin((axxVal), (axxThL)), (axxThH))


/* ========================================================= */
/* マクロ名 : McXX_incGrd/#$Max (#={U,S}, $={1,2,4})         */
/* 概要     : インクリメントガード                           */
/* 周期     : なし                                           */
/* 戻り値   : なし                                           */
/* 引数     : axxCntr  カウンタ変数                          */
/*            axxTh    閾値                                  */
/* 制約     : 引数の型を合わせること。                       */
/* 詳細     : 閾値内の場合、インクリメントする。             */
/*            閾値を超える場合、インクリメントしない。       */
/* ========================================================= */
#define McXX_incGrd(axxCntr, axxTh) \
do { \
    if ((axxCntr) < (axxTh)) { \
        (axxCntr)++; \
    } \
} while (0)
#define McXX_incU1Max(axxCntr)    McXX_incGrd((axxCntr), CU1_Max)
#define McXX_incU2Max(axxCntr)    McXX_incGrd((axxCntr), CU2_Max)
#define McXX_incU4Max(axxCntr)    McXX_incGrd((axxCntr), CU4_Max)
#define McXX_incU8Max(axxCntr)    McXX_incGrd((axxCntr), CU8_Max)
#define McXX_incS1Max(axxCntr)    McXX_incGrd((axxCntr), CS1_Max)
#define McXX_incS2Max(axxCntr)    McXX_incGrd((axxCntr), CS2_Max)
#define McXX_incS4Max(axxCntr)    McXX_incGrd((axxCntr), CS4_Max)
#define McXX_incS8Max(axxCntr)    McXX_incGrd((axxCntr), CS8_Max)


/* ========================================================= */
/* マクロ名 : McXX_decGrd                                    */
/* 概要     : デクリメントガード                             */
/* 周期     : なし                                           */
/* 戻り値   : なし                                           */
/* 引数     : axxCntr  カウンタ変数                          */
/*            axxTh    閾値                                  */
/* 制約     : なし                                           */
/* 詳細     : 閾値より大きい場合はデクリメントする。         */
/*            閾値以下の場合はデクリメントしない。           */
/* ========================================================= */
#define McXX_decGrd(axxCntr, axxTh) \
do { \
    if ((axxCntr) > (axxTh)) { \
        (axxCntr)--; \
    } \
} while (0)
#define McXX_decU1Min(axxCntr)    McXX_decGrd((axxCntr), CU1_Min)
#define McXX_decU2Min(axxCntr)    McXX_decGrd((axxCntr), CU2_Min)
#define McXX_decU4Min(axxCntr)    McXX_decGrd((axxCntr), CU4_Min)
#define McXX_decU8Min(axxCntr)    McXX_decGrd((axxCntr), CU8_Min)
#define McXX_decS1Min(axxCntr)    McXX_decGrd((axxCntr), CS1_Min)
#define McXX_decS2Min(axxCntr)    McXX_decGrd((axxCntr), CS2_Min)
#define McXX_decS4Min(axxCntr)    McXX_decGrd((axxCntr), CS4_Min)
#define McXX_decS8Min(axxCntr)    McXX_decGrd((axxCntr), CS8_Min)


/* ========================================================= */
/* マクロ名 : McSI_getSgn                                    */
/* 概要     : 符号取得                                       */
/* 周期     : なし                                           */
/* 戻り値   : 符号(-1:負, 0:符号なし, 1:正)                  */
/* 引数     : axxVal  入力値                                 */
/* 制約     : なし                                           */
/* 詳細     : 0未満の場合-1(負)を返す。                      */
/*            0の場合は0(符号なし)を返す。                   */
/*            0より大きい場合1(正)を返す。                   */
/* ========================================================= */
#define McSI_getSgn(axxVal)       ((const SI)(((axxVal) < 0) ? CSI_SgnM : (((axxVal) > 0) ? CSI_SgnP : CSI_SgnN)))


/* ========================================================= */
/* マクロ名 : McXX_calAbs                                    */
/* 概要     : 実数値の絶対値取得                             */
/* 周期     : なし                                           */
/* 戻り値   : 実数値                                         */
/* 引数     : axxVal  入力値                                 */
/* 制約     : 特異値問題は使用側で考慮すること。             */
/* 詳細     : 実数の絶対値を返す。                           */
/* ========================================================= */
#define McXX_calAbs(axxVal)        (((axxVal) < 0) ? -(axxVal) : (axxVal))

#endif
