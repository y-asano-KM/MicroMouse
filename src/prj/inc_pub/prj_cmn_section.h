/* ================================================== */
/* ファイル名 : prj_cmn_section.h                     */
/* 機能       : セクション定義                        */
/* ================================================== */
/* このファイルは多重インクルード防止は不要 */
#if (0)
#elif defined(SECTION_PRJ)
  /* プロジェクト共通セクション定義 */
  #pragma section P PROG_PRJ
  #pragma section C CONST_PRJ
  #pragma section B RAM_PRJ
  #pragma section D ROMVAL_PRJ
#elif defined(SECTION_HW)
  /* HW層セクション定義 */
  #pragma section P PROG_HW
  #pragma section C CONST_HW
  #pragma section B RAM_HW
  #pragma section D ROMVAL_HW
#elif defined(SECTION_PF)
  /* PF層セクション定義 */
  #pragma section P PROG_PF
  #pragma section C CONST_PF
  #pragma section B RAM_PF
  #pragma section D ROMVAL_PF
#elif defined(SECTION_APP)
  /* APP層セクション定義 */
  #pragma section P PROG_APP
  #pragma section C CONST_APP
  #pragma section B RAM_APP
  #pragma section D ROMVAL_APP
#else
  #error /* 未実装 */
#endif
