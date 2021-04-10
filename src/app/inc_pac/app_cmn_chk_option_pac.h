#if !defined(INCLUDED_app_cmn_chk_option_pac_h)
#define INCLUDED_app_cmn_chk_option_pac_h
/* ================================================== */
/* ファイル名 : app_cmn_chk_option_pac.h              */
/* 機能       : APPオプションチェック                 */
/* ================================================== */

/* 加速制御タイプ選択 */
#if (1 < (  (defined(OP_AppCtrl_Accel_LogicTypePhysical) ? 1 : 0) \
          + (defined(OP_AppCtrl_Accel_LogicTypeTable)    ? 1 : 0) \
          + (defined(OP_AppCtrl_Accel_LogicTypePulseCnt) ? 1 : 0)))

  #error  /* 排他選択またはすべて無効のみ許容 */
#endif
#endif

