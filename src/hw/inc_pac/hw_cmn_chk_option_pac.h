#if !defined(INCLUDED_hw_cmn_chk_option_pac_h)
#define INCLUDED_hw_cmn_chk_option_pac_h
/* ================================================== */
/* ファイル名 : hw_cmn_chk_option_pac.h               */
/* 機能       : HWオプションチェック                  */
/* ================================================== */

/* -------------------------------- */
/* コンパイラオプション設定チェック */
/* -------------------------------- */
/* バージョン */
#if defined(__RXV1)
  /* RXV1 */
#elif defined(__RXV2)
  /* RXV2 */
  #error  /* 未検討 */
#else
  /* 規定外 */
  #error
#endif

/* エンディアン */
#if defined(__BIG)
  /* BIG ENDIAN */
  #error  /* 未検討 */
#elif defined(__LIT)
  /* LITTLE ENDIAN */
#else
  #error  /* 未検討 */
#endif

/* 浮動小数演算ユニット */
#if defined(__FPU)
  /* 有効 */

  /* 浮動小数点定数演算の丸め方式 */
  #if defined(__ROZ)
    /* zero */
    #error  /* 未検討 */
  #elif defined(__RON)
    /* nearest */
  #else
    /* 規定外 */
    #error
  #endif

  /* 浮動小数点定数に非正規化数を記述した場合の扱い */
  #if defined(__DOFF)
    /* 0として扱う */
  #elif defined(__DON)
    /* 非正規化数として扱う */
    #error  /* 未検討 */
  #else
    /* 規定外 */
    #error
  #endif

  /* 倍精度浮動小数型サイズ */
  #if defined(__DBL4)
    /* 4Byte */
    #error  /* 未検討 */
  #elif defined(__DBL8)
    /* 8Byte */
  #else
    /* 規定外 */
    #error
  #endif
#else
  /* 無効 */
  #error  /* 未検討 */
#endif

/* int型サイズ */
#if defined(__INT_SHORT)
  /* 2Byte */
  #error  /* 未検討 */
#else
  /* 4Byte */
#endif

/* char型符号有無 */
#if defined(__SCHAR)
  /* 符号あり */
  #error  /* 未検討 */
#elif defined(__UCHAR)
  /* 符号なし */
#endif

/* ビットフィールド型の符号有無 */
#if defined(__SBIT)
  /* 符号あり */
  #error  /* 未検討 */
#elif defined(__UBIT)
  /* 符号なし */
#endif

/* ビットフィールドメンバーの並び順 */
#if defined(__BITLEFT)
  /* 左から右へ */
  #error  /* 未検討 */
#elif defined(__BITRIGHT)
  /* 右から左へ */
#else
  /* 規定外 */
  #error
#endif

/* 列挙型のサイズ */
#if defined(__AUTO_ENUM)
  /* 自動選択 */
#else
  /* int型と同じ */
  #error  /* 未検討 */
#endif

/* PIC機能 */
#if defined(__PIC)
  /* 有効 */
  #error  /* 未検討 */
#else
  /* 無効 */
#endif

/* PID機能 */
#if defined(__PID)
  /* 有効 */
  #error  /* 未検討 */
#else
  /* 無効 */
#endif

/* RX命令に展開可能なライブラリ関数の実行方法 */
#if defined(__FUNCTION_LIB)
  /* 関数呼び出し */
  #error  /* 未検討 */
#elif defined(__INTRINSIC_LIB)
  /* RX命令に展開 */
#else
  /* 規定外 */
  #error
#endif

#endif
