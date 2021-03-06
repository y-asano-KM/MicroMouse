/* ============================================================ */
/* ファイル名 : pf_sche_if.c                                    */
/* 機能       : スケジュールI/F処理                             */
/* ============================================================ */
#define SECTION_PF

/* ============================================================ */
/* インクルード                                                 */
/* ============================================================ */
/* プロジェクト共通 */
#include "prj_cmn_section.h"
#include "prj_cmn_option.h"
#include "prj_cmn_type.h"
#include "prj_cmn_macro.h"

/* カテゴリ共通 */
#include "pf_cmn_option.h"
#include "pf_cmn_option_pac.h"

/* 個別 */
#include "hw_srv_schedule.h"

/* 本体 */
#include "pf_sche_if_pac.h"


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
static U4 u4PfSche_If_MainCnt;          /* [回]メイン周期実行回数(LSB:1回) */
static U4 u4PfSche_If_Int1msCnt;        /* [回]1ms周期割り込み実行回数(LSB:1回) */


/* ============================================================ */
/* const変数定義(extern)                                        */
/* ============================================================ */


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
/* 関数名 : FnVD_PfSche_If_initPf                               */
/*          スケジュールI/F処理初期化(PF用)                     */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : スケジュールI/F処理の初期化を行う                   */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_PfSche_If_initPf(VD)
{
  u4PfSche_If_MainCnt   = (U4)0;
  u4PfSche_If_Int1msCnt = (U4)0;
}


/* ============================================================ */
/* 関数名 : FnVD_PfSche_If_renewMainCnt                         */
/*          メイン周期実行回数更新                              */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : メイン周期実行回数を更新する                        */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_PfSche_If_renewMainCnt(VD)
{
  u4PfSche_If_MainCnt = FnU4_HwSrv_Sche_getMainCnt();
}


/* ============================================================ */
/* 関数名 : FnVD_PfSche_If_renewInt1msCnt                       */
/*          1ms周期割り込み実行回数更新                         */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 1ms周期割り込み実行回数を更新する                   */
/* 制約   : なし                                                */
/* ============================================================ */
VD FnVD_PfSche_If_renewInt1msCnt(VD)
{
  u4PfSche_If_Int1msCnt = FnU4_HwSrv_Sche_getInt1msCnt();
}


/* ============================================================ */
/* 関数名 : FnU4_PfSche_If_getMainCnt                           */
/*          メイン周期実行回数取得                              */
/* 引数   : なし                                                */
/* 戻り値 : [回]メイン周期実行回数(LSB:1回)                     */
/* 概要   : メイン周期実行回数を提供する                        */
/* 制約   : なし                                                */
/* ============================================================ */
U4 FnU4_PfSche_If_getMainCnt(VD)
{
  return (u4PfSche_If_MainCnt);
}


/* ============================================================ */
/* 関数名 : FnU4_PfSche_If_getInt1msCnt                         */
/*          1ms周期割り込み実行回数取得                         */
/* 引数   : なし                                                */
/* 戻り値 : [回]1ms周期割り込み実行回数(LSB:1回)                */
/* 概要   : 1ms周期割り込み実行回数を提供する                   */
/* 制約   : なし                                                */
/* ============================================================ */
U4 FnU4_PfSche_If_getInt1msCnt(VD)
{
  return (u4PfSche_If_Int1msCnt);
}


