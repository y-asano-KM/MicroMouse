#if !defined(INCLUDED_prj_cmn_chk_option_h)
#define INCLUDED_prj_cmn_chk_option_h
/* ================================================== */
/* ファイル名 : prj_cmn_chk_option.h                  */
/* 機能       : 共通オプションチェック                */
/* ================================================== */

/* [排他]エンディアン選択 */
#if (1 != (  (defined(OP_PrjCmn_LittleEndian) ? 1 : 0) \
           + (defined(OP_PrjCmn_BigEndian )   ? 1 : 0)))
  #error /* 排他選択であること */
#endif

#endif
