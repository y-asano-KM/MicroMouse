#if !defined(INCLUDED_hw_drv_wheel_pac_h)
#define INCLUDED_hw_drv_wheel_pac_h
/* ============================================================ */
/* ファイル名 : hw_drv_wheel_pac.h                              */
/* 機能       :                                                 */
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
#include "hw_pph_reg_pac.h"

/* 本体 */


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */
/* モーターMTUポート */
//#define MTU_MTR_R            stRegMTU.stMTU_TSTR.stMTU.b1CST3    /* 右モーター用MTU */
//#define MTU_MTR_L            stRegMTU.stMTU_TSTR.stMTU.b1CST4    /* 左モーター用MTU */
/* 右モーターMTUレジスタ */
#define MTU_MTR_CYCLE_R      stRegMTU.stMTU3_TGRC.u2Val            /* 右モーター周期を設定 */
/* 左モーターMTUレジスタ */
#define MTU_MTR_CYCLE_L      stRegMTU.stMTU4_TGRC.u2Val            /* 左モーター周期を設定 */
/* モーター励磁 */
//#define MTR_POWER            PORT1.PDR.BIT.B5     /* モーター励磁 */
/* モーターCWCCW端子 */
//#define MTR_CWCCW_R          PORTC.PDR.BIT.B5     /* 右モーターCWCCW端子 */
//#define MTR_CWCCW_L          PORTC.PDR.BIT.B6     /* 左モーターCWCCW端子 */
/* モーター用定数 */
#define MTR_FORWARD          1                    /* モーター前進(CWCCW端子) */
#define MTR_BACKWARD         0                    /* モーター後進(CWCCW端子) */

/* 割込みフラグ */
#define CMT0_INT_F           IR(CMT0,CMI0)        /* タイマー0割込みフラグ */
//#define MTU_R_INT_F          IR(MTU3,TGIB3)       /* 右モータMTU割込みフラグ */
//#define MTU_L_INT_F          IR(MTU4,TGIB4)       /* 左モータMTU割込みフラグ */

/* ============================================================ */
/* 型定義                                                       */
/* ============================================================ */


/* ============================================================ */
/* 関数プロトタイプ宣言(extern)                                 */
/* ============================================================ */
void vd_g_IntWheelDrvTask(void);
void vd_g_IntWheelMtrR(void);
void vd_g_IntWheelMtrL(void);
void vd_g_WheelDrvMtrTask(void);
void vd_g_Intcmt0(void);

/* ============================================================ */
/* 変数宣言(extern)                                             */
/* ============================================================ */


/* ============================================================ */
/* const変数宣言(extern)                                        */
/* ============================================================ */


/* ============================================================ */
/* 関数形式マクロ定義                                           */
/* ============================================================ */

#endif
