#if !defined(INCLUDED_app_controll_h)
#define INCLUDED_app_controll_h
/* ============================================================ */
/* ファイル名 : app_controll.h                                  */
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
#include "app_cmn_option.h"

/* 個別 */


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */


/* ============================================================ */
/* 型定義                                                       */
/* ============================================================ */


/* ============================================================ */
/* 関数プロトタイプ宣言(extern)                                 */
/* ============================================================ */
extern VD FnVD_AppCtrl_init(VD);                       /* 初期化関数 */
extern VD FnVD_AppCtrl_mngTsk(VD);                     /* 定期メインタスク */
extern VD FnVD_AppCtrl_mngTskForInt(VD);               /* 1ms割り込みタスク */
extern U1 FnU1_AppCtrl_getMtrPowerMode(VD);            /* モータ励磁 */
extern U1 FnU1_AppCtrl_getMtrModeR(VD);                /* 右モーター モード */
extern U1 FnU1_AppCtrl_getMtrModeL(VD);                /* 左モーター モード */
extern U2 FnU2_AppCtrl_getMtrSpeedR(VD);
extern U2 FnU2_AppCtrl_getMtrSpeedL(VD);
extern U2 FnU2_AppCtrl_getCycleTimeR(VD);              /* 右モータ周期とパルス幅(1ms割り込み) */
extern U2 FnU2_AppCtrl_getCycleTimeL(VD);              /* 左モータ周期とパルス幅(1ms割り込み) */
extern U1 FnU1_AppCtrl_getResetPulseCntReq(VD);


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

