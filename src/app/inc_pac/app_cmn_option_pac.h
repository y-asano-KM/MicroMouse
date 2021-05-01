#if !defined(INCLUDED_app_cmn_option_pac_h)
#define INCLUDED_app_cmn_option_pac_h
/* ================================================== */
/* ファイル名 : app_cmn_option_pac.h                  */
/* 機能       : APPオプション定義                     */
/* ================================================== */

/* ================================================== */
/* インクルード                                       */
/* ================================================== */
#include "prj_cmn_option.h"
#include "app_cmn_option.h"

/* ================================================== */
/* オプション定義                                     */
/* ================================================== */
/* 姿勢制御(PID)機能 有効/無効フラグ */
/* #define OP_AppCmn_PidMode */

/* 加速制御 */
/* #define OP_AppCmn_LogicTypePhysical */
/* #define OP_AppCmn_LogicTypeTable */
#define OP_AppCmn_LogicTypePulseCnt


/* ================================================== */
/* オプションチェック                                 */
/* ================================================== */
#include "app_cmn_chk_option_pac.h"

#endif
