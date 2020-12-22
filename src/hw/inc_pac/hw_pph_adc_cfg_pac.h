#if !defined(INCLUDED_hw_pph_adc_cfg_pac_h)
#define INCLUDED_hw_pph_adc_cfg_pac_h
/* ============================================================ */
/* ファイル名 : hw_pph_adc_cfg_pac.h                            */
/* 機能       : A/D変換処理用ユーザ設定                         */
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
#include "hw_pph_adc_pac.h"


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */
/* A/D変換クロック設定 */
#define CEN_HwPph_Adc_CfgSelClk         CEN_HwPph_Adc_SelClk_Div1

/* スキャン終了割り込み許可 */
#define CU1_HwPph_Adc_CfgIntEnb         ((U1)C_OFF)

/* 自動クリアイネーブル設定 */
#define CU1_HwPph_Adc_CfgReadClrEnb     ((U1)C_ON)

/* A/Dデータレジスタフォーマット設定 */
#define CEN_HwPph_Adc_CfgFormat         CEN_HwPph_Adc_Format_Right

/* サンプリング時間1設定 */
#define CU1_HwPph_Adc_CfgSamplingTime   ((U1)20)

/* A/D変換待ち時間 */
/* PCLK = ADCLK * 2^(3 - ADCSR.CKS) */
#define CU2_HwPph_Adc_PphClk            ((U2)((U2)1 << (U2)((U2)CEN_HwPph_Adc_SelClk_Div1 - (U2)CEN_HwPph_Adc_CfgSelClk)))

/* スキャン開始処理時間(Td = 2PCLK＋3ADCLK) */
#define CU2_HwPph_Adc_CfgScanStartTime  ((U2)((U2)2 * CU2_HwPph_Adc_PphClk + (U2)3))

/* 1回あたりのA/D変換処理時間(Tconv = (30 + ADSSTRxx.SSTy)ADCLK) */
#define CU2_HwPph_Adc_ConvertTime       ((U2)((U2)30 + (U2)CU1_HwPph_Adc_CfgSamplingTime))

/* スキャン終了処理時間(Ted = 1PCLK＋2ADCLK) */
#define CU2_HwPph_Adc_CfgScanEndTime  ((U2)(CU2_HwPph_Adc_PphClk + (U2)2))


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
extern const EN_HwPph_Adc_SelClk CEN_HwPph_Adc_CfgSelClk_;
extern const U1 CU1_HwPph_Adc_CfgIntEnb_;
extern const U1 CU1_HwPph_Adc_CfgReadClrEnb_;
extern const EN_HwPph_Adc_Format CEN_HwPph_Adc_CfgFormat_;
extern const U1 CU1_HwPph_Adc_CfgSamplingTime_;


/* ============================================================ */
/* 関数形式マクロ定義                                           */
/* ============================================================ */
/* ============================================================ */
/* 関数名 : McU2_HwPph_Adc_calTotalConvertTime                  */
/*          総A/D変換時間演算                                   */
/* 引数   : tu2Num  [回]A/D変換回数                             */
/* 戻り値 : [クロック(ADCLK)]総A/D変換時間(クロック数)          */
/* 概要   : 総A/D変換時間を返す                                 */
/* 制約   : なし                                                */
/* ============================================================ */
#define McU2_HwPph_Adc_calTotalConvertTime(tu2Num)    ((U2)(  CU2_HwPph_Adc_CfgScanStartTime \
                                                            + CU2_HwPph_Adc_ConvertTime * (U2)(tu2Num) \
                                                            + CU2_HwPph_Adc_CfgScanEndTime))


/* ============================================================ */
/* 関数名 : McFL_HwPph_Adc_calTotalConvertTime                  */
/*          総A/D変換時間演算                                   */
/* 引数   : tu2Num        [回]A/D変換回数                       */
/*          flPphClkFreq  [MHz]PCLK周波数                       */
/* 戻り値 : [us]総A/D変換時間                                   */
/* 概要   : 総A/D変換時間を返す                                 */
/* 制約   : なし                                                */
/* ============================================================ */
#define McFL_HwPph_Adc_calTotalConvertTime(tu2Num, flPphClkFreq)    ((FL)((FL)McU2_HwPph_Adc_calTotalConvertTime(tu2Num) / (flPphClkFreq)))


#endif
