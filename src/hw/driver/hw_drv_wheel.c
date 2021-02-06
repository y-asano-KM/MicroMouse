/* ============================================================ */
/* ファイル名 : hw_drv_wheel.c                                  */
/* 機能       :                                                 */
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
#include "app_controll_pac.h"
#include "hw_drv_mtr.h"
#include "hw_pph_intctrl_pac.h"

/* 本体 */
#include "hw_drv_wheel.h"
#include "hw_drv_wheel_pac.h"


/* ============================================================ */
/* マクロ定数定義                                               */
/* ============================================================ */


/* ============================================================ */
/* 型定義                                                       */
/* ============================================================ */


/* ============================================================ */
/* 関数プロトタイプ宣言(static)                                 */
/* ============================================================ */
static void vd_s_WheelDrvMtrPower(void);
static void vd_s_WheelDrvMtrActR(void);
static void vd_s_WheelDrvMtrActL(void);

/* ============================================================ */
/* 変数定義(extern)                                             */
/* ============================================================ */


/* ============================================================ */
/* 変数定義(static)                                             */
/* ============================================================ */
static U2 u2_s_WheelCycleTimeR;
static U2 u2_s_WheelCycleTimeL;
static S1 s1_s_WheelMtrModeR;
static S1 s1_s_WheelMtrModeL;
static U1 u1_s_WheelMtrPower;

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
/* 関数名 : vd_g_InitializeWheel                                */
/*          初期化処理                                          */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : モジュールで使用する変数の初期化を行う              */
/* 制約   : メイン処理実行前にコールすること                    */
/* ============================================================ */
void vd_g_InitializeWheel(void)
{
    u2_s_WheelCycleTimeR = (U2)0;
    u2_s_WheelCycleTimeL = (U2)0;
    s1_s_WheelMtrModeR   = (S1)MTR_STOP;
    s1_s_WheelMtrModeL   = (S1)MTR_STOP;
    u1_s_WheelMtrPower   = (U1)MTR_OFF;
}

/* ============================================================ */
/* 関数名 : vd_g_set_WheelMtrModeR                              */
/*          右モーター回転方向                                  */
/* 引数   : S1 s1_a_set … MTR_STOP( 0):停止                    */
/*                         MTR_RUN ( 1):前進                    */
/*                         MTR_BACK(-1):後進                    */
/* 戻り値 : なし                                                */
/* 概要   : 右モーター回転方向設定を行う                        */
/* 制約   : なし                                                */
/* ============================================================ */
void vd_g_set_WheelMtrModeR(S1 s1_a_set)
{
    /* モーター励磁 ON/OFF */
    s1_s_WheelMtrModeR = s1_a_set;
}

/* ============================================================ */
/* 関数名 : vd_g_set_WheelMtrModeL                              */
/*          左モーター回転方向                                  */
/* 引数   : S1 s1_a_set … MTR_STOP( 0):停止                    */
/*                         MTR_RUN ( 1):前進                    */
/*                         MTR_BACK(-1):後進                    */
/* 戻り値 : なし                                                */
/* 概要   : 左モーター回転方向設定を行う                        */
/* 制約   : なし                                                */
/* ============================================================ */
void vd_g_set_WheelMtrModeL(S1 s1_a_set)
{
    /* モーター励磁 ON/OFF */
    s1_s_WheelMtrModeL = s1_a_set;
}

/* ============================================================ */
/* 関数名 : vd_g_set_WheelMtrPower                              */
/*          モーター励磁 ON/OFF設定                             */
/* 引数   : U1 u1_a_set … MTR_ON (0):励磁                      */
/*                         MTR_OFF(1):励磁解除                  */
/* 戻り値 : なし                                                */
/* 概要   : モーターの励磁のON/OFF設定を行う                    */
/* 制約   : なし                                                */
/* ============================================================ */
void vd_g_set_WheelMtrPower(U1 u1_a_set)
{
    /* モーター励磁 ON/OFF */
    u1_s_WheelMtrPower = u1_a_set;
}

/* ============================================================ */
/* 関数名 : vd_g_set_WheelCycleTimeR                            */
/*          右モーターの周期情報設定                            */
/* 引数   : U2 u2_a_set                                         */
/* 戻り値 : なし                                                */
/* 概要   : 周波数情報の設定を行う                              */
/* 制約   : なし                                                */
/* ============================================================ */
void vd_g_set_WheelCycleTimeR(U2 u2_a_set)
{
    /* モーター励磁 周波数設定 */
    u2_s_WheelCycleTimeR = u2_a_set;
}

/* ============================================================ */
/* 関数名 : vd_g_set_WheelCycleTimeL                            */
/*          左モーターの周期情報設定                            */
/* 引数   : U2 u2_a_set                                         */
/* 戻り値 : なし                                                */
/* 概要   : 周波数情報の設定を行う                              */
/* 制約   : なし                                                */
/* ============================================================ */
void vd_g_set_WheelCycleTimeL(U2 u2_a_set)
{
    /* モーター励磁 周波数設定 */
    u2_s_WheelCycleTimeL = u2_a_set;
}

/* ============================================================ */
/* 関数名 : vd_g_IntWheelDrvTask                                */
/*          モータードライバ(1ms割り込み)                       */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : モーターMTUの周期を設定する                         */
/* 制約   : なし                                                */
/* ============================================================ */
void vd_g_IntWheelDrvTask(void)
{
    /* モーターMTUの周期を設定する。 */
    MTU_MTR_CYCLE_R = u2_s_WheelCycleTimeR;
    MTU_MTR_CYCLE_L = u2_s_WheelCycleTimeL;
}

/* ============================================================ */
/* 関数名 : vd_g_IntWheelMtrR                                   */
/*          右モーターMTU割込み処理                             */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 右モーターが１ステップ進む毎の割込み                */
/* 制約   : なし                                                */
/* ============================================================ */
void vd_g_IntWheelMtrR(void)
{
    /* フラグクリア */
#if 0
    MTU_R_INT_F = 0;
#endif
    FnVD_HwPph_IntCtrl_clrIntReq(CEN_HwPph_IntCtrl_VecId_TPU9_TGI9B_MTU3_TGIB3);
}

/* ============================================================ */
/* 関数名 : vd_g_IntWheelMtrL                                   */
/*          左モーターMTU割込み処理                             */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 左モーターが１ステップ進む毎の割込み                */
/* 制約   : なし                                                */
/* ============================================================ */
void vd_g_IntWheelMtrL(void)
{
    /* フラグクリア */
#if 0
    MTU_L_INT_F = 0;
#endif
    FnVD_HwPph_IntCtrl_clrIntReq(CEN_HwPph_IntCtrl_VecId_TPU10_TGI10B_MTU4_TGIB4);
}

/* ============================================================ */
/* 関数名 : vd_g_Intcmt0                                        */
/*          CMT0割込み処理                                      */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : タイマー割込み(1ms)                                 */
/* 制約   : なし                                                */
/* ============================================================ */
void vd_g_Intcmt0(void)
{
    /* フラグクリア */
#if 0
    CMT0_INT_F = 0;
#endif
    FnVD_HwPph_IntCtrl_clrIntReq(CEN_HwPph_IntCtrl_VecId_CMT0_CMI0);
}

/* ============================================================ */
/* 関数名 : vd_g_WheelDrvMtrTask                                */
/*          モータードライバ 定期タスク                         */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 回転方向を指定して                                  */
/*          左右モーターMTUのカウントをスタートする             */
/* 制約   : なし                                                */
/* ============================================================ */
void vd_g_WheelDrvMtrTask(void)
{
    /* モーター励磁 */
    vd_s_WheelDrvMtrPower();

    /* 右モーター */
    vd_s_WheelDrvMtrActR();

    /* 左モーター */
    vd_s_WheelDrvMtrActL();
}

/* ============================================================ */
/* 関数名 : vd_g_WheelDrvMtrPower                               */
/*          モーター励磁                                        */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : モーターの励磁のON/OFFを行う                        */
/* 制約   : なし                                                */
/* ============================================================ */
static void vd_s_WheelDrvMtrPower(void)
{
    /* モーター励磁 ON/OFF */
    FnVD_HwDrv_Mtr_setEnbPort(u1_s_WheelMtrPower);
#if 0
    MTR_POWER = u1_s_WheelMtrPower;
#endif
}

/* ============================================================ */
/* 関数名 : vd_s_WheelDrvMtrActR                                */
/*          右モータードライバ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 回転方向を指定して                                  */
/*          モーターMTUのカウントをスタートする                 */
/* 制約   : なし                                                */
/* ============================================================ */
static void vd_s_WheelDrvMtrActR(void)
{
    if(s1_s_WheelMtrModeR == (S1)MTR_RUN){        /* 前進 */
#if 0
        MTR_CWCCW_R = (U1)MTR_FORWARD;            /* CWCCW 前進 */
        MTU_MTR_R   = (U1)MTU_ON;                 /* モーターMTUカウント開始 */
#endif
        FnVD_HwDrv_Mtr_setRotDirPortRight((U1)MTR_FORWARD);
        FnVD_HwDrv_Mtr_ctrlStpAndGoRight((U1)MTU_ON);
    }
    else if(s1_s_WheelMtrModeR == (S1)MTR_BACK){  /* 後進 */
#if 0
        MTR_CWCCW_R = (U1)MTR_BACKWARD;           /* CWCCW 後進 */
        MTU_MTR_R   = (U1)MTU_ON;                 /* モーターMTUカウント開始 */
#endif
        FnVD_HwDrv_Mtr_setRotDirPortRight((U1)MTR_BACKWARD);
        FnVD_HwDrv_Mtr_ctrlStpAndGoRight((U1)MTU_ON);
    }
    else{                                         /* 停止 */
#if 0
    	MTU_MTR_R   = (U1)MTU_OFF;                /* モーターMTU停止 */
#endif
    	FnVD_HwDrv_Mtr_ctrlStpAndGoRight((U1)MTU_OFF);
    }
}

/* ============================================================ */
/* 関数名 : vd_s_WheelDrvMtrActL                                */
/*          左モータードライバ                                  */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : 回転方向を指定して                                  */
/*          モーターMTUのカウントをスタートする                 */
/* 制約   : なし                                                */
/* ============================================================ */
static void vd_s_WheelDrvMtrActL(void)
{
    if(s1_s_WheelMtrModeL == (S1)MTR_RUN){        /* 前進 */
#if 0
        MTR_CWCCW_R = (U1)MTR_FORWARD;            /* CWCCW 前進 */
        MTU_MTR_R   = (U1)MTU_ON;                 /* モーターMTUカウント開始 */
#endif
        FnVD_HwDrv_Mtr_setRotDirPortLeft((U1)MTR_FORWARD);
        FnVD_HwDrv_Mtr_ctrlStpAndGoLeft((U1)MTU_ON);
    }
    else if(s1_s_WheelMtrModeL == (S1)MTR_BACK){  /* 後進 */
#if 0
        MTR_CWCCW_R = (U1)MTR_BACKWARD;           /* CWCCW 後進 */
        MTU_MTR_R   = (U1)MTU_ON;                 /* モーターMTUカウント開始 */
#endif
        FnVD_HwDrv_Mtr_setRotDirPortLeft((U1)MTR_BACKWARD);
        FnVD_HwDrv_Mtr_ctrlStpAndGoLeft((U1)MTU_ON);
    }
    else{                                         /* 停止 */
#if 0
        MTU_MTR_R   = (U1)MTU_OFF;                /* モーターMTU停止 */
#endif
        FnVD_HwDrv_Mtr_ctrlStpAndGoLeft((U1)MTU_OFF);
    }
}

