#if !defined(INCLUDED_prj_cmn_type_h)
#define INCLUDED_prj_cmn_type_h
/* ================================================== */
/* ファイル名 : prj_cmn_type.h                        */
/* 機能       : 汎用型定義                            */
/* ================================================== */

/* ================================================== */
/* インクルード                                       */
/* ================================================== */
#include "prj_cmn_option.h"

/* ================================================== */
/* 型定義                                             */
/* ================================================== */
typedef void               VD;    /* void型 */
typedef unsigned char      U1;    /* 符号なし1バイト型 */
typedef unsigned short     U2;    /* 符号なし2バイト型 */
#if defined(OP_PrjCmn_LongSize8)
typedef unsigned int       U4;    /* 符号なし4バイト型 */
typedef unsigned long      U8;    /* 符号なし8バイト型 */
#else
typedef unsigned long      U4;    /* 符号なし4バイト型 */
typedef unsigned long long U8;    /* 符号なし8バイト型 */
#endif
typedef signed   char      S1;    /* 符号付き1バイト型 */
typedef signed   short     S2;    /* 符号付き2バイト型 */
#if defined(OP_PrjCmn_LongSize8)
typedef signed   int       S4;    /* 符号なし4バイト型 */
typedef signed   long      S8;    /* 符号なし8バイト型 */
#else
typedef signed   long      S4;    /* 符号付き4バイト型 */
typedef signed   long long S8;    /* 符号付き8バイト型 */
#endif
typedef float              FL;    /* 単精度浮動小数型 */
typedef double             DB;    /* 倍精度浮動小数型 */
typedef char               AC;    /* 文字型(Ascii) */
typedef unsigned char      BL;    /* ブール型(代替) */
typedef unsigned int       UI;    /* 符号なし整数型 */
typedef unsigned int       SI;    /* 符号付き整数型 */

/* フラグ型 */
typedef union {
  U1 u1Val;
  struct {
#if defined(OP_PrjCmn_LittleEndian)
    U1 fBit0 : 1;
    U1 fBit1 : 1;
    U1 fBit2 : 1;
    U1 fBit3 : 1;
    U1 fBit4 : 1;
    U1 fBit5 : 1;
    U1 fBit6 : 1;
    U1 fBit7 : 1;
#elif defined(OP_PrjCmn_BigEndian)
    U1 fBit7 : 1;
    U1 fBit6 : 1;
    U1 fBit5 : 1;
    U1 fBit4 : 1;
    U1 fBit3 : 1;
    U1 fBit2 : 1;
    U1 fBit1 : 1;
    U1 fBit0 : 1;
#else
  #error /* Note:未検討 */
#endif
  } Flag;
} F1;

/* ハーフワード型 */
typedef union {
  U2 u2Val;
  struct {
#if defined(OP_PrjCmn_LittleEndian)
    U2 b8L : 8;
    U2 b8H : 8;
#elif defined(OP_PrjCmn_BigEndian)
    U2 b8H : 8;
    U2 b8L : 8;
#else
  #error /* Note:未検討 */
#endif
  } Byte;
} HW;

/* ワード型 */
typedef union {
  U4 u4Val;
  struct {
#if defined(OP_PrjCmn_LittleEndian)
    U4 b8LL : 8;
    U4 b8LH : 8;
    U4 b8HL : 8;
    U4 b8HH : 8;
#elif defined(OP_PrjCmn_BigEndian)
    U4 b8HH : 8;
    U4 b8HL : 8;
    U4 b8LH : 8;
    U4 b8LL : 8;
#else
  #error /* Note:未検討 */
#endif
  } Byte;
  struct {
#if defined(OP_PrjCmn_LittleEndian)
    U4 b16L : 16;
    U4 b16H : 16;
#elif defined(OP_PrjCmn_BigEndian)
    U4 b16H : 16;
    U4 b16L : 16;
#else
  #error /* Note:未検討 */
#endif
  } HWord;
} WD;

#endif
