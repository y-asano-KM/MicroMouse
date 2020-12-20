/* ============================================================ */
/* ファイル名 : hw_pph_intctrl.c                                */
/* 機能       : 割り込み制御処理                                */
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
#include "hw_pph_reg_pac.h"

/* 本体 */
#include "hw_pph_intctrl_pac.h"


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
/* 関数名 : FnVD_HwPph_IntCtrl_initForStartup                   */
/*          割り込み制御関連レジスタ初期化(スタートアップ用)    */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : ハード初期値に頼らずソフトにて初期値設定を行う      */
/* 制約   : 割り込み禁止中に実行すること                        */
/* ============================================================ */
VD FnVD_HwPph_IntCtrl_initForStartup(VD)
{
  /* 処理速度優先のためベタ書きとする */
  /* ------------------------------------------ */
  /* 割り込み要求許可レジスタm 割り込み禁止設定 */
  /* ------------------------------------------ */
  /* m = 00 レジスタ無し */
  /* m = 01 レジスタ無し */
  stRegICU.staIERm[0x02].u1Val = (U1)0x00;
  stRegICU.staIERm[0x03].u1Val = (U1)0x00;
  stRegICU.staIERm[0x04].u1Val = (U1)0x00;
  stRegICU.staIERm[0x05].u1Val = (U1)0x00;
  stRegICU.staIERm[0x06].u1Val = (U1)0x00;
  stRegICU.staIERm[0x07].u1Val = (U1)0x00;
  stRegICU.staIERm[0x08].u1Val = (U1)0x00;
  stRegICU.staIERm[0x09].u1Val = (U1)0x00;
  /* m = 0A レジスタ無し */
  stRegICU.staIERm[0x0B].u1Val = (U1)0x00;
  stRegICU.staIERm[0x0C].u1Val = (U1)0x00;
  stRegICU.staIERm[0x0D].u1Val = (U1)0x00;
  stRegICU.staIERm[0x0E].u1Val = (U1)0x00;
  stRegICU.staIERm[0x0F].u1Val = (U1)0x00;
  stRegICU.staIERm[0x10].u1Val = (U1)0x00;
  stRegICU.staIERm[0x11].u1Val = (U1)0x00;
  stRegICU.staIERm[0x12].u1Val = (U1)0x00;
  stRegICU.staIERm[0x13].u1Val = (U1)0x00;
  stRegICU.staIERm[0x14].u1Val = (U1)0x00;
  stRegICU.staIERm[0x15].u1Val = (U1)0x00;
  stRegICU.staIERm[0x16].u1Val = (U1)0x00;
  stRegICU.staIERm[0x17].u1Val = (U1)0x00;
  stRegICU.staIERm[0x18].u1Val = (U1)0x00;
  stRegICU.staIERm[0x19].u1Val = (U1)0x00;
  stRegICU.staIERm[0x1A].u1Val = (U1)0x00;
  stRegICU.staIERm[0x1B].u1Val = (U1)0x00;
  stRegICU.staIERm[0x1C].u1Val = (U1)0x00;
  stRegICU.staIERm[0x1D].u1Val = (U1)0x00;
  stRegICU.staIERm[0x1E].u1Val = (U1)0x00;
  stRegICU.staIERm[0x1F].u1Val = (U1)0x00;

  /* --------------------------------------------- */
  /* 高速割り込み設定レジスタ 高速割り込み禁止設定 */
  /* --------------------------------------------- */
  stRegICU.stFIR.u2Val = (U2)0x0000;

  /* ------------------------------------------------------------- */
  /* 割り込み要因プライオリティレジスタn 割り込み禁止(優先度0)設定 */
  /* ------------------------------------------------------------- */
  stRegICU.staIPRn[0].u1Val = (U1)0x00;
  stRegICU.staIPRn[1].u1Val = (U1)0x00;
  stRegICU.staIPRn[2].u1Val = (U1)0x00;
  stRegICU.staIPRn[3].u1Val = (U1)0x00;
  stRegICU.staIPRn[4].u1Val = (U1)0x00;
  stRegICU.staIPRn[5].u1Val = (U1)0x00;
  stRegICU.staIPRn[6].u1Val = (U1)0x00;
  stRegICU.staIPRn[7].u1Val = (U1)0x00;
  /* n =  8 レジスタ無し */
  /* n =  9 レジスタ無し */
  /* n = 10 レジスタ無し */
  /* n = 11 レジスタ無し */
  /* n = 12 レジスタ無し */
  /* n = 13 レジスタ無し */
  /* n = 14 レジスタ無し */
  /* n = 15 レジスタ無し */
  /* n = 16 レジスタ無し */
  /* n = 17 レジスタ無し */
  /* n = 18 レジスタ無し */
  /* n = 19 レジスタ無し */
  /* n = 20 レジスタ無し */
  /* n = 21 レジスタ無し */
  /* n = 22 レジスタ無し */
  /* n = 23 レジスタ無し */
  /* n = 24 レジスタ無し */
  /* n = 25 レジスタ無し */
  /* n = 26 レジスタ無し */
  /* n = 27 レジスタ無し */
  /* n = 28 レジスタ無し */
  /* n = 29 レジスタ無し */
  /* n = 30 レジスタ無し */
  /* n = 31 レジスタ無し */
  stRegICU.staIPRn[32].u1Val = (U1)0x00;
  stRegICU.staIPRn[33].u1Val = (U1)0x00;
  stRegICU.staIPRn[34].u1Val = (U1)0x00;
  stRegICU.staIPRn[35].u1Val = (U1)0x00;
  stRegICU.staIPRn[36].u1Val = (U1)0x00;
  stRegICU.staIPRn[37].u1Val = (U1)0x00;
  stRegICU.staIPRn[38].u1Val = (U1)0x00;
  stRegICU.staIPRn[39].u1Val = (U1)0x00;
  /* n = 40 レジスタ無し */
  /* n = 41 レジスタ無し */
  stRegICU.staIPRn[42].u1Val = (U1)0x00;
  /* n = 43 レジスタ無し */
  /* n = 44 レジスタ無し */
  stRegICU.staIPRn[45].u1Val = (U1)0x00;
  /* n = 46 レジスタ無し */
  /* n = 47 レジスタ無し */
  stRegICU.staIPRn[48].u1Val = (U1)0x00;
  /* n = 49 レジスタ無し */
  /* n = 50 レジスタ無し */
  /* n = 51 レジスタ無し */
  stRegICU.staIPRn[52].u1Val = (U1)0x00;
  /* n = 53 レジスタ無し */
  /* n = 54 レジスタ無し */
  /* n = 55 レジスタ無し */
  stRegICU.staIPRn[56].u1Val = (U1)0x00;
  /* n = 57 レジスタ無し */
  /* n = 58 レジスタ無し */
  /* n = 59 レジスタ無し */
  /* n = 60 レジスタ無し */
  /* n = 61 レジスタ無し */
  stRegICU.staIPRn[62].u1Val = (U1)0x00;
  /* n = 63 レジスタ無し */
  stRegICU.staIPRn[64].u1Val = (U1)0x00;
  stRegICU.staIPRn[65].u1Val = (U1)0x00;
  stRegICU.staIPRn[66].u1Val = (U1)0x00;
  stRegICU.staIPRn[67].u1Val = (U1)0x00;
  stRegICU.staIPRn[68].u1Val = (U1)0x00;
  stRegICU.staIPRn[69].u1Val = (U1)0x00;
  stRegICU.staIPRn[70].u1Val = (U1)0x00;
  stRegICU.staIPRn[71].u1Val = (U1)0x00;
  stRegICU.staIPRn[72].u1Val = (U1)0x00;
  stRegICU.staIPRn[73].u1Val = (U1)0x00;
  stRegICU.staIPRn[74].u1Val = (U1)0x00;
  stRegICU.staIPRn[75].u1Val = (U1)0x00;
  stRegICU.staIPRn[76].u1Val = (U1)0x00;
  stRegICU.staIPRn[77].u1Val = (U1)0x00;
  stRegICU.staIPRn[78].u1Val = (U1)0x00;
  stRegICU.staIPRn[79].u1Val = (U1)0x00;
  /* n = 80 レジスタ無し */
  /* n = 81 レジスタ無し */
  /* n = 82 レジスタ無し */
  /* n = 83 レジスタ無し */
  /* n = 84 レジスタ無し */
  /* n = 85 レジスタ無し */
  /* n = 86 レジスタ無し */
  /* n = 87 レジスタ無し */
  /* n = 88 レジスタ無し */
  /* n = 89 レジスタ無し */
  stRegICU.staIPRn[90].u1Val = (U1)0x00;
  stRegICU.staIPRn[91].u1Val = (U1)0x00;
  stRegICU.staIPRn[92].u1Val = (U1)0x00;
  stRegICU.staIPRn[93].u1Val = (U1)0x00;
  /* n = 94 レジスタ無し */
  /* n = 95 レジスタ無し */
  /* n = 96 レジスタ無し */
  /* n = 97 レジスタ無し */
  stRegICU.staIPRn[98].u1Val = (U1)0x00;
  /* n = 99 レジスタ無し */
  /* n = 100 レジスタ無し */
  /* n = 101 レジスタ無し */
  stRegICU.staIPRn[102].u1Val = (U1)0x00;
  /* n = 103 レジスタ無し */
  /* n = 104 レジスタ無し */
  /* n = 105 レジスタ無し */
  stRegICU.staIPRn[106].u1Val = (U1)0x00;
  stRegICU.staIPRn[107].u1Val = (U1)0x00;
  stRegICU.staIPRn[108].u1Val = (U1)0x00;
  stRegICU.staIPRn[109].u1Val = (U1)0x00;
  stRegICU.staIPRn[110].u1Val = (U1)0x00;
  stRegICU.staIPRn[111].u1Val = (U1)0x00;
  stRegICU.staIPRn[112].u1Val = (U1)0x00;
  /* n = 113 レジスタ無し */
  stRegICU.staIPRn[114].u1Val = (U1)0x00;
  /* n = 115 レジスタ無し */
  /* n = 116 レジスタ無し */
  /* n = 117 レジスタ無し */
  /* n = 118 レジスタ無し */
  /* n = 119 レジスタ無し */
  /* n = 120 レジスタ無し */
  /* n = 121 レジスタ無し */
  stRegICU.staIPRn[122].u1Val = (U1)0x00;
  /* n = 123 レジスタ無し */
  /* n = 124 レジスタ無し */
  /* n = 125 レジスタ無し */
  stRegICU.staIPRn[126].u1Val = (U1)0x00;
  /* n = 127 レジスタ無し */
  /* n = 128 レジスタ無し */
  /* n = 129 レジスタ無し */
  stRegICU.staIPRn[130].u1Val = (U1)0x00;
  /* n = 131 レジスタ無し */
  stRegICU.staIPRn[132].u1Val = (U1)0x00;
  /* n = 133 レジスタ無し */
  stRegICU.staIPRn[134].u1Val = (U1)0x00;
  /* n = 135 レジスタ無し */
  /* n = 136 レジスタ無し */
  /* n = 137 レジスタ無し */
  stRegICU.staIPRn[138].u1Val = (U1)0x00;
  /* n = 139 レジスタ無し */
  stRegICU.staIPRn[140].u1Val = (U1)0x00;
  /* n = 141 レジスタ無し */
  stRegICU.staIPRn[142].u1Val = (U1)0x00;
  /* n = 143 レジスタ無し */
  /* n = 144 レジスタ無し */
  /* n = 145 レジスタ無し */
  stRegICU.staIPRn[146].u1Val = (U1)0x00;
  /* n = 147 レジスタ無し */
  stRegICU.staIPRn[148].u1Val = (U1)0x00;
  /* n = 149 レジスタ無し */
  stRegICU.staIPRn[150].u1Val = (U1)0x00;
  /* n = 151 レジスタ無し */
  stRegICU.staIPRn[152].u1Val = (U1)0x00;
  /* n = 153 レジスタ無し */
  /* n = 154 レジスタ無し */
  /* n = 155 レジスタ無し */
  stRegICU.staIPRn[156].u1Val = (U1)0x00;
  /* n = 157 レジスタ無し */
  /* n = 158 レジスタ無し */
  /* n = 159 レジスタ無し */
  stRegICU.staIPRn[160].u1Val = (U1)0x00;
  stRegICU.staIPRn[161].u1Val = (U1)0x00;
  /* n = 162 レジスタ無し */
  /* n = 163 レジスタ無し */
  stRegICU.staIPRn[164].u1Val = (U1)0x00;
  /* n = 165 レジスタ無し */
  stRegICU.staIPRn[166].u1Val = (U1)0x00;
  /* n = 167 レジスタ無し */
  /* n = 168 レジスタ無し */
  /* n = 169 レジスタ無し */
  stRegICU.staIPRn[170].u1Val = (U1)0x00;
  /* n = 171 レジスタ無し */
  /* n = 172 レジスタ無し */
  stRegICU.staIPRn[173].u1Val = (U1)0x00;
  /* n = 174 レジスタ無し */
  /* n = 175 レジスタ無し */
  stRegICU.staIPRn[176].u1Val = (U1)0x00;
  /* n = 177 レジスタ無し */
  /* n = 178 レジスタ無し */
  stRegICU.staIPRn[179].u1Val = (U1)0x00;
  /* n = 180 レジスタ無し */
  /* n = 181 レジスタ無し */
  stRegICU.staIPRn[182].u1Val = (U1)0x00;
  stRegICU.staIPRn[183].u1Val = (U1)0x00;
  stRegICU.staIPRn[184].u1Val = (U1)0x00;
  stRegICU.staIPRn[185].u1Val = (U1)0x00;
  stRegICU.staIPRn[186].u1Val = (U1)0x00;
  stRegICU.staIPRn[187].u1Val = (U1)0x00;
  stRegICU.staIPRn[188].u1Val = (U1)0x00;
  stRegICU.staIPRn[189].u1Val = (U1)0x00;
  stRegICU.staIPRn[190].u1Val = (U1)0x00;
  stRegICU.staIPRn[191].u1Val = (U1)0x00;
  stRegICU.staIPRn[192].u1Val = (U1)0x00;
  stRegICU.staIPRn[193].u1Val = (U1)0x00;
  stRegICU.staIPRn[194].u1Val = (U1)0x00;
  stRegICU.staIPRn[195].u1Val = (U1)0x00;
  stRegICU.staIPRn[196].u1Val = (U1)0x00;
  stRegICU.staIPRn[197].u1Val = (U1)0x00;
  stRegICU.staIPRn[198].u1Val = (U1)0x00;
  stRegICU.staIPRn[199].u1Val = (U1)0x00;
  stRegICU.staIPRn[200].u1Val = (U1)0x00;
  stRegICU.staIPRn[201].u1Val = (U1)0x00;
  stRegICU.staIPRn[202].u1Val = (U1)0x00;
  stRegICU.staIPRn[203].u1Val = (U1)0x00;
  /* n = 204 レジスタ無し */
  /* n = 205 レジスタ無し */
  stRegICU.staIPRn[206].u1Val = (U1)0x00;
  stRegICU.staIPRn[207].u1Val = (U1)0x00;
  stRegICU.staIPRn[208].u1Val = (U1)0x00;
  /* n = 209 レジスタ無し */
  /* n = 210 レジスタ無し */
  /* n = 211 レジスタ無し */
  /* n = 212 レジスタ無し */
  /* n = 213 レジスタ無し */
  stRegICU.staIPRn[214].u1Val = (U1)0x00;
  /* n = 215 レジスタ無し */
  /* n = 216 レジスタ無し */
  stRegICU.staIPRn[217].u1Val = (U1)0x00;
  /* n = 218 レジスタ無し */
  /* n = 219 レジスタ無し */
  stRegICU.staIPRn[220].u1Val = (U1)0x00;
  /* n = 221 レジスタ無し */
  /* n = 222 レジスタ無し */
  stRegICU.staIPRn[223].u1Val = (U1)0x00;
  /* n = 224 レジスタ無し */
  /* n = 225 レジスタ無し */
  stRegICU.staIPRn[226].u1Val = (U1)0x00;
  /* n = 227 レジスタ無し */
  /* n = 228 レジスタ無し */
  stRegICU.staIPRn[229].u1Val = (U1)0x00;
  /* n = 230 レジスタ無し */
  /* n = 231 レジスタ無し */
  stRegICU.staIPRn[232].u1Val = (U1)0x00;
  /* n = 233 レジスタ無し */
  /* n = 234 レジスタ無し */
  stRegICU.staIPRn[235].u1Val = (U1)0x00;
  /* n = 236 レジスタ無し */
  /* n = 237 レジスタ無し */
  stRegICU.staIPRn[238].u1Val = (U1)0x00;
  /* n = 239 レジスタ無し */
  /* n = 240 レジスタ無し */
  stRegICU.staIPRn[241].u1Val = (U1)0x00;
  /* n = 242 レジスタ無し */
  /* n = 243 レジスタ無し */
  stRegICU.staIPRn[244].u1Val = (U1)0x00;
  /* n = 245 レジスタ無し */
  /* n = 246 レジスタ無し */
  stRegICU.staIPRn[247].u1Val = (U1)0x00;
  /* n = 248 レジスタ無し */
  /* n = 249 レジスタ無し */
  stRegICU.staIPRn[250].u1Val = (U1)0x00;
  /* n = 251 レジスタ無し */
  /* n = 252 レジスタ無し */
  stRegICU.staIPRn[253].u1Val = (U1)0x00;
  /* n = 254 レジスタ無し */
  /* n = 255 レジスタ無し */

  /* ---------------------------------------- */
  /* 割り込み要求レジスタn 割り込み要求クリア */
  /* ---------------------------------------- */
  /* n =  0 レジスタ無し */
  /* n =  1 レジスタ無し */
  /* n =  2 レジスタ無し */
  /* n =  3 レジスタ無し */
  /* n =  4 レジスタ無し */
  /* n =  5 レジスタ無し */
  /* n =  6 レジスタ無し */
  /* n =  7 レジスタ無し */
  /* n =  8 レジスタ無し */
  /* n =  9 レジスタ無し */
  /* n = 10 レジスタ無し */
  /* n = 11 レジスタ無し */
  /* n = 12 レジスタ無し */
  /* n = 13 レジスタ無し */
  /* n = 14 レジスタ無し */
  /* n = 15 レジスタ無し */
  stRegICU.staIRn[16].u1Val = (U1)0x00;
  /* n = 17 レジスタ無し */
  /* n = 18 レジスタ無し */
  /* n = 19 レジスタ無し */
  /* n = 20 レジスタ無し */
  stRegICU.staIRn[21].u1Val = (U1)0x00;
  /* n = 22 レジスタ無し */
  stRegICU.staIRn[23].u1Val = (U1)0x00;
  /* n = 24 レジスタ無し */
  /* n = 25 レジスタ無し */
  /* n = 26 レジスタ無し */
  stRegICU.staIRn[27].u1Val = (U1)0x00;
  stRegICU.staIRn[28].u1Val = (U1)0x00;
  stRegICU.staIRn[29].u1Val = (U1)0x00;
  stRegICU.staIRn[30].u1Val = (U1)0x00;
  stRegICU.staIRn[31].u1Val = (U1)0x00;
  stRegICU.staIRn[32].u1Val = (U1)0x00;
  stRegICU.staIRn[33].u1Val = (U1)0x00;
  stRegICU.staIRn[34].u1Val = (U1)0x00;
  stRegICU.staIRn[35].u1Val = (U1)0x00;
  stRegICU.staIRn[36].u1Val = (U1)0x00;
  stRegICU.staIRn[37].u1Val = (U1)0x00;
  stRegICU.staIRn[38].u1Val = (U1)0x00;
  stRegICU.staIRn[39].u1Val = (U1)0x00;
  stRegICU.staIRn[40].u1Val = (U1)0x00;
  stRegICU.staIRn[41].u1Val = (U1)0x00;
  stRegICU.staIRn[42].u1Val = (U1)0x00;
  stRegICU.staIRn[43].u1Val = (U1)0x00;
  stRegICU.staIRn[44].u1Val = (U1)0x00;
  stRegICU.staIRn[45].u1Val = (U1)0x00;
  stRegICU.staIRn[46].u1Val = (U1)0x00;
  stRegICU.staIRn[47].u1Val = (U1)0x00;
  stRegICU.staIRn[48].u1Val = (U1)0x00;
  stRegICU.staIRn[49].u1Val = (U1)0x00;
  stRegICU.staIRn[50].u1Val = (U1)0x00;
  stRegICU.staIRn[51].u1Val = (U1)0x00;
  stRegICU.staIRn[52].u1Val = (U1)0x00;
  stRegICU.staIRn[53].u1Val = (U1)0x00;
  stRegICU.staIRn[54].u1Val = (U1)0x00;
  stRegICU.staIRn[55].u1Val = (U1)0x00;
  stRegICU.staIRn[56].u1Val = (U1)0x00;
  stRegICU.staIRn[57].u1Val = (U1)0x00;
  stRegICU.staIRn[58].u1Val = (U1)0x00;
  stRegICU.staIRn[59].u1Val = (U1)0x00;
  /* n = 60 レジスタ無し */
  /* n = 61 レジスタ無し */
  stRegICU.staIRn[62].u1Val = (U1)0x00;
  /* n = 63 レジスタ無し */
  stRegICU.staIRn[64].u1Val = (U1)0x00;
  stRegICU.staIRn[65].u1Val = (U1)0x00;
  stRegICU.staIRn[66].u1Val = (U1)0x00;
  stRegICU.staIRn[67].u1Val = (U1)0x00;
  stRegICU.staIRn[68].u1Val = (U1)0x00;
  stRegICU.staIRn[69].u1Val = (U1)0x00;
  stRegICU.staIRn[70].u1Val = (U1)0x00;
  stRegICU.staIRn[71].u1Val = (U1)0x00;
  stRegICU.staIRn[72].u1Val = (U1)0x00;
  stRegICU.staIRn[73].u1Val = (U1)0x00;
  stRegICU.staIRn[74].u1Val = (U1)0x00;
  stRegICU.staIRn[75].u1Val = (U1)0x00;
  stRegICU.staIRn[76].u1Val = (U1)0x00;
  stRegICU.staIRn[77].u1Val = (U1)0x00;
  stRegICU.staIRn[78].u1Val = (U1)0x00;
  stRegICU.staIRn[79].u1Val = (U1)0x00;
  /* n = 80 レジスタ無し */
  /* n = 81 レジスタ無し */
  /* n = 82 レジスタ無し */
  /* n = 83 レジスタ無し */
  /* n = 84 レジスタ無し */
  /* n = 85 レジスタ無し */
  /* n = 86 レジスタ無し */
  /* n = 87 レジスタ無し */
  /* n = 88 レジスタ無し */
  /* n = 89 レジスタ無し */
  stRegICU.staIRn[90].u1Val = (U1)0x00;
  stRegICU.staIRn[91].u1Val = (U1)0x00;
  stRegICU.staIRn[92].u1Val = (U1)0x00;
  stRegICU.staIRn[93].u1Val = (U1)0x00;
  /* n = 94 レジスタ無し */
  /* n = 95 レジスタ無し */
  /* n = 96 レジスタ無し */
  /* n = 97 レジスタ無し */
  stRegICU.staIRn[98].u1Val = (U1)0x00;
  /* n = 99 レジスタ無し */
  /* n = 100 レジスタ無し */
  /* n = 101 レジスタ無し */
  stRegICU.staIRn[102].u1Val = (U1)0x00;
  /* n = 103 レジスタ無し */
  /* n = 104 レジスタ無し */
  /* n = 105 レジスタ無し */
  stRegICU.staIRn[106].u1Val = (U1)0x00;
  stRegICU.staIRn[107].u1Val = (U1)0x00;
  stRegICU.staIRn[108].u1Val = (U1)0x00;
  stRegICU.staIRn[109].u1Val = (U1)0x00;
  stRegICU.staIRn[110].u1Val = (U1)0x00;
  stRegICU.staIRn[111].u1Val = (U1)0x00;
  stRegICU.staIRn[112].u1Val = (U1)0x00;
  /* n = 113 レジスタ無し */
  stRegICU.staIRn[114].u1Val = (U1)0x00;
  /* n = 115 レジスタ無し */
  /* n = 116 レジスタ無し */
  /* n = 117 レジスタ無し */
  /* n = 118 レジスタ無し */
  /* n = 119 レジスタ無し */
  /* n = 120 レジスタ無し */
  /* n = 121 レジスタ無し */
  stRegICU.staIRn[122].u1Val = (U1)0x00;
  stRegICU.staIRn[123].u1Val = (U1)0x00;
  stRegICU.staIRn[124].u1Val = (U1)0x00;
  stRegICU.staIRn[125].u1Val = (U1)0x00;
  stRegICU.staIRn[126].u1Val = (U1)0x00;
  stRegICU.staIRn[127].u1Val = (U1)0x00;
  stRegICU.staIRn[128].u1Val = (U1)0x00;
  stRegICU.staIRn[129].u1Val = (U1)0x00;
  stRegICU.staIRn[130].u1Val = (U1)0x00;
  stRegICU.staIRn[131].u1Val = (U1)0x00;
  stRegICU.staIRn[132].u1Val = (U1)0x00;
  stRegICU.staIRn[133].u1Val = (U1)0x00;
  stRegICU.staIRn[134].u1Val = (U1)0x00;
  stRegICU.staIRn[135].u1Val = (U1)0x00;
  stRegICU.staIRn[136].u1Val = (U1)0x00;
  stRegICU.staIRn[137].u1Val = (U1)0x00;
  stRegICU.staIRn[138].u1Val = (U1)0x00;
  stRegICU.staIRn[139].u1Val = (U1)0x00;
  stRegICU.staIRn[140].u1Val = (U1)0x00;
  stRegICU.staIRn[141].u1Val = (U1)0x00;
  stRegICU.staIRn[142].u1Val = (U1)0x00;
  stRegICU.staIRn[143].u1Val = (U1)0x00;
  stRegICU.staIRn[144].u1Val = (U1)0x00;
  stRegICU.staIRn[145].u1Val = (U1)0x00;
  stRegICU.staIRn[146].u1Val = (U1)0x00;
  stRegICU.staIRn[147].u1Val = (U1)0x00;
  stRegICU.staIRn[148].u1Val = (U1)0x00;
  stRegICU.staIRn[149].u1Val = (U1)0x00;
  stRegICU.staIRn[150].u1Val = (U1)0x00;
  stRegICU.staIRn[151].u1Val = (U1)0x00;
  stRegICU.staIRn[152].u1Val = (U1)0x00;
  stRegICU.staIRn[153].u1Val = (U1)0x00;
  stRegICU.staIRn[154].u1Val = (U1)0x00;
  stRegICU.staIRn[155].u1Val = (U1)0x00;
  stRegICU.staIRn[156].u1Val = (U1)0x00;
  stRegICU.staIRn[157].u1Val = (U1)0x00;
  stRegICU.staIRn[158].u1Val = (U1)0x00;
  stRegICU.staIRn[159].u1Val = (U1)0x00;
  stRegICU.staIRn[160].u1Val = (U1)0x00;
  stRegICU.staIRn[161].u1Val = (U1)0x00;
  stRegICU.staIRn[162].u1Val = (U1)0x00;
  stRegICU.staIRn[163].u1Val = (U1)0x00;
  stRegICU.staIRn[164].u1Val = (U1)0x00;
  stRegICU.staIRn[165].u1Val = (U1)0x00;
  stRegICU.staIRn[166].u1Val = (U1)0x00;
  stRegICU.staIRn[167].u1Val = (U1)0x00;
  /* n = 168 レジスタ無し */
  /* n = 169 レジスタ無し */
  stRegICU.staIRn[170].u1Val = (U1)0x00;
  stRegICU.staIRn[171].u1Val = (U1)0x00;
  stRegICU.staIRn[172].u1Val = (U1)0x00;
  stRegICU.staIRn[173].u1Val = (U1)0x00;
  stRegICU.staIRn[174].u1Val = (U1)0x00;
  stRegICU.staIRn[175].u1Val = (U1)0x00;
  stRegICU.staIRn[176].u1Val = (U1)0x00;
  stRegICU.staIRn[177].u1Val = (U1)0x00;
  stRegICU.staIRn[178].u1Val = (U1)0x00;
  stRegICU.staIRn[179].u1Val = (U1)0x00;
  stRegICU.staIRn[180].u1Val = (U1)0x00;
  stRegICU.staIRn[181].u1Val = (U1)0x00;
  stRegICU.staIRn[182].u1Val = (U1)0x00;
  stRegICU.staIRn[183].u1Val = (U1)0x00;
  stRegICU.staIRn[184].u1Val = (U1)0x00;
  stRegICU.staIRn[185].u1Val = (U1)0x00;
  stRegICU.staIRn[186].u1Val = (U1)0x00;
  stRegICU.staIRn[187].u1Val = (U1)0x00;
  stRegICU.staIRn[188].u1Val = (U1)0x00;
  stRegICU.staIRn[189].u1Val = (U1)0x00;
  stRegICU.staIRn[190].u1Val = (U1)0x00;
  stRegICU.staIRn[191].u1Val = (U1)0x00;
  stRegICU.staIRn[192].u1Val = (U1)0x00;
  stRegICU.staIRn[193].u1Val = (U1)0x00;
  stRegICU.staIRn[194].u1Val = (U1)0x00;
  stRegICU.staIRn[195].u1Val = (U1)0x00;
  stRegICU.staIRn[196].u1Val = (U1)0x00;
  stRegICU.staIRn[197].u1Val = (U1)0x00;
  stRegICU.staIRn[198].u1Val = (U1)0x00;
  stRegICU.staIRn[199].u1Val = (U1)0x00;
  stRegICU.staIRn[200].u1Val = (U1)0x00;
  stRegICU.staIRn[201].u1Val = (U1)0x00;
  stRegICU.staIRn[202].u1Val = (U1)0x00;
  stRegICU.staIRn[203].u1Val = (U1)0x00;
  /* n = 204 レジスタ無し */
  /* n = 205 レジスタ無し */
  /* n = 206 レジスタ無し */
  /* n = 207 レジスタ無し */
  /* n = 208 レジスタ無し */
  /* n = 209 レジスタ無し */
  /* n = 210 レジスタ無し */
  /* n = 211 レジスタ無し */
  /* n = 212 レジスタ無し */
  /* n = 213 レジスタ無し */
  stRegICU.staIRn[214].u1Val = (U1)0x00;
  stRegICU.staIRn[215].u1Val = (U1)0x00;
  stRegICU.staIRn[216].u1Val = (U1)0x00;
  stRegICU.staIRn[217].u1Val = (U1)0x00;
  stRegICU.staIRn[218].u1Val = (U1)0x00;
  stRegICU.staIRn[219].u1Val = (U1)0x00;
  stRegICU.staIRn[220].u1Val = (U1)0x00;
  stRegICU.staIRn[221].u1Val = (U1)0x00;
  stRegICU.staIRn[222].u1Val = (U1)0x00;
  stRegICU.staIRn[223].u1Val = (U1)0x00;
  stRegICU.staIRn[224].u1Val = (U1)0x00;
  stRegICU.staIRn[225].u1Val = (U1)0x00;
  stRegICU.staIRn[226].u1Val = (U1)0x00;
  stRegICU.staIRn[227].u1Val = (U1)0x00;
  stRegICU.staIRn[228].u1Val = (U1)0x00;
  stRegICU.staIRn[229].u1Val = (U1)0x00;
  stRegICU.staIRn[230].u1Val = (U1)0x00;
  stRegICU.staIRn[231].u1Val = (U1)0x00;
  stRegICU.staIRn[232].u1Val = (U1)0x00;
  stRegICU.staIRn[233].u1Val = (U1)0x00;
  stRegICU.staIRn[234].u1Val = (U1)0x00;
  stRegICU.staIRn[235].u1Val = (U1)0x00;
  stRegICU.staIRn[236].u1Val = (U1)0x00;
  stRegICU.staIRn[237].u1Val = (U1)0x00;
  stRegICU.staIRn[238].u1Val = (U1)0x00;
  stRegICU.staIRn[239].u1Val = (U1)0x00;
  stRegICU.staIRn[240].u1Val = (U1)0x00;
  stRegICU.staIRn[241].u1Val = (U1)0x00;
  stRegICU.staIRn[242].u1Val = (U1)0x00;
  stRegICU.staIRn[243].u1Val = (U1)0x00;
  stRegICU.staIRn[244].u1Val = (U1)0x00;
  stRegICU.staIRn[245].u1Val = (U1)0x00;
  stRegICU.staIRn[246].u1Val = (U1)0x00;
  stRegICU.staIRn[247].u1Val = (U1)0x00;
  stRegICU.staIRn[248].u1Val = (U1)0x00;
  stRegICU.staIRn[249].u1Val = (U1)0x00;
  stRegICU.staIRn[250].u1Val = (U1)0x00;
  stRegICU.staIRn[251].u1Val = (U1)0x00;
  stRegICU.staIRn[252].u1Val = (U1)0x00;
  stRegICU.staIRn[253].u1Val = (U1)0x00;
  /* n = 254 レジスタ無し */
  /* n = 255 レジスタ無し */
}


/* ============================================================ */
/* 関数名 : FnVD_HwPph_IntCtrl_initToKill                       */
/*          割り込み制御関連レジスタ初期化(システム停止用)      */
/* 引数   : なし                                                */
/* 戻り値 : なし                                                */
/* 概要   : システム停止時に行う割り込み制御関連レジスタ設定    */
/* 制約   : 割り込み禁止中に実行すること                        */
/* ============================================================ */
VD FnVD_HwPph_IntCtrl_initToKill(VD)
{
  /* 処理速度優先のためベタ書きとする */
  /* ------------------------------------------ */
  /* 割り込み要求許可レジスタm 割り込み禁止設定 */
  /* ------------------------------------------ */
  /* m = 00 レジスタ無し */
  /* m = 01 レジスタ無し */
  stRegICU.staIERm[0x02].u1Val = (U1)0x00;
  stRegICU.staIERm[0x03].u1Val = (U1)0x00;
  stRegICU.staIERm[0x04].u1Val = (U1)0x00;
  stRegICU.staIERm[0x05].u1Val = (U1)0x00;
  stRegICU.staIERm[0x06].u1Val = (U1)0x00;
  stRegICU.staIERm[0x07].u1Val = (U1)0x00;
  stRegICU.staIERm[0x08].u1Val = (U1)0x00;
  stRegICU.staIERm[0x09].u1Val = (U1)0x00;
  /* m = 0A レジスタ無し */
  stRegICU.staIERm[0x0B].u1Val = (U1)0x00;
  stRegICU.staIERm[0x0C].u1Val = (U1)0x00;
  stRegICU.staIERm[0x0D].u1Val = (U1)0x00;
  stRegICU.staIERm[0x0E].u1Val = (U1)0x00;
  stRegICU.staIERm[0x0F].u1Val = (U1)0x00;
  stRegICU.staIERm[0x10].u1Val = (U1)0x00;
  stRegICU.staIERm[0x11].u1Val = (U1)0x00;
  stRegICU.staIERm[0x12].u1Val = (U1)0x00;
  stRegICU.staIERm[0x13].u1Val = (U1)0x00;
  stRegICU.staIERm[0x14].u1Val = (U1)0x00;
  stRegICU.staIERm[0x15].u1Val = (U1)0x00;
  stRegICU.staIERm[0x16].u1Val = (U1)0x00;
  stRegICU.staIERm[0x17].u1Val = (U1)0x00;
  stRegICU.staIERm[0x18].u1Val = (U1)0x00;
  stRegICU.staIERm[0x19].u1Val = (U1)0x00;
  stRegICU.staIERm[0x1A].u1Val = (U1)0x00;
  stRegICU.staIERm[0x1B].u1Val = (U1)0x00;
  stRegICU.staIERm[0x1C].u1Val = (U1)0x00;
  stRegICU.staIERm[0x1D].u1Val = (U1)0x00;
  stRegICU.staIERm[0x1E].u1Val = (U1)0x00;
  stRegICU.staIERm[0x1F].u1Val = (U1)0x00;

  /* --------------------------------------------- */
  /* 高速割り込み設定レジスタ 高速割り込み禁止設定 */
  /* --------------------------------------------- */
  stRegICU.stFIR.u2Val = (U2)0x0000;

  /* ------------------------------------------------------------- */
  /* 割り込み要因プライオリティレジスタn 割り込み禁止(優先度0)設定 */
  /* ------------------------------------------------------------- */
  stRegICU.staIPRn[0].u1Val = (U1)0x00;
  stRegICU.staIPRn[1].u1Val = (U1)0x00;
  stRegICU.staIPRn[2].u1Val = (U1)0x00;
  stRegICU.staIPRn[3].u1Val = (U1)0x00;
  stRegICU.staIPRn[4].u1Val = (U1)0x00;
  stRegICU.staIPRn[5].u1Val = (U1)0x00;
  stRegICU.staIPRn[6].u1Val = (U1)0x00;
  stRegICU.staIPRn[7].u1Val = (U1)0x00;
  /* n =  8 レジスタ無し */
  /* n =  9 レジスタ無し */
  /* n = 10 レジスタ無し */
  /* n = 11 レジスタ無し */
  /* n = 12 レジスタ無し */
  /* n = 13 レジスタ無し */
  /* n = 14 レジスタ無し */
  /* n = 15 レジスタ無し */
  /* n = 16 レジスタ無し */
  /* n = 17 レジスタ無し */
  /* n = 18 レジスタ無し */
  /* n = 19 レジスタ無し */
  /* n = 20 レジスタ無し */
  /* n = 21 レジスタ無し */
  /* n = 22 レジスタ無し */
  /* n = 23 レジスタ無し */
  /* n = 24 レジスタ無し */
  /* n = 25 レジスタ無し */
  /* n = 26 レジスタ無し */
  /* n = 27 レジスタ無し */
  /* n = 28 レジスタ無し */
  /* n = 29 レジスタ無し */
  /* n = 30 レジスタ無し */
  /* n = 31 レジスタ無し */
  stRegICU.staIPRn[32].u1Val = (U1)0x00;
  stRegICU.staIPRn[33].u1Val = (U1)0x00;
  stRegICU.staIPRn[34].u1Val = (U1)0x00;
  stRegICU.staIPRn[35].u1Val = (U1)0x00;
  stRegICU.staIPRn[36].u1Val = (U1)0x00;
  stRegICU.staIPRn[37].u1Val = (U1)0x00;
  stRegICU.staIPRn[38].u1Val = (U1)0x00;
  stRegICU.staIPRn[39].u1Val = (U1)0x00;
  /* n = 40 レジスタ無し */
  /* n = 41 レジスタ無し */
  stRegICU.staIPRn[42].u1Val = (U1)0x00;
  /* n = 43 レジスタ無し */
  /* n = 44 レジスタ無し */
  stRegICU.staIPRn[45].u1Val = (U1)0x00;
  /* n = 46 レジスタ無し */
  /* n = 47 レジスタ無し */
  stRegICU.staIPRn[48].u1Val = (U1)0x00;
  /* n = 49 レジスタ無し */
  /* n = 50 レジスタ無し */
  /* n = 51 レジスタ無し */
  stRegICU.staIPRn[52].u1Val = (U1)0x00;
  /* n = 53 レジスタ無し */
  /* n = 54 レジスタ無し */
  /* n = 55 レジスタ無し */
  stRegICU.staIPRn[56].u1Val = (U1)0x00;
  /* n = 57 レジスタ無し */
  /* n = 58 レジスタ無し */
  /* n = 59 レジスタ無し */
  /* n = 60 レジスタ無し */
  /* n = 61 レジスタ無し */
  stRegICU.staIPRn[62].u1Val = (U1)0x00;
  /* n = 63 レジスタ無し */
  stRegICU.staIPRn[64].u1Val = (U1)0x00;
  stRegICU.staIPRn[65].u1Val = (U1)0x00;
  stRegICU.staIPRn[66].u1Val = (U1)0x00;
  stRegICU.staIPRn[67].u1Val = (U1)0x00;
  stRegICU.staIPRn[68].u1Val = (U1)0x00;
  stRegICU.staIPRn[69].u1Val = (U1)0x00;
  stRegICU.staIPRn[70].u1Val = (U1)0x00;
  stRegICU.staIPRn[71].u1Val = (U1)0x00;
  stRegICU.staIPRn[72].u1Val = (U1)0x00;
  stRegICU.staIPRn[73].u1Val = (U1)0x00;
  stRegICU.staIPRn[74].u1Val = (U1)0x00;
  stRegICU.staIPRn[75].u1Val = (U1)0x00;
  stRegICU.staIPRn[76].u1Val = (U1)0x00;
  stRegICU.staIPRn[77].u1Val = (U1)0x00;
  stRegICU.staIPRn[78].u1Val = (U1)0x00;
  stRegICU.staIPRn[79].u1Val = (U1)0x00;
  /* n = 80 レジスタ無し */
  /* n = 81 レジスタ無し */
  /* n = 82 レジスタ無し */
  /* n = 83 レジスタ無し */
  /* n = 84 レジスタ無し */
  /* n = 85 レジスタ無し */
  /* n = 86 レジスタ無し */
  /* n = 87 レジスタ無し */
  /* n = 88 レジスタ無し */
  /* n = 89 レジスタ無し */
  stRegICU.staIPRn[90].u1Val = (U1)0x00;
  stRegICU.staIPRn[91].u1Val = (U1)0x00;
  stRegICU.staIPRn[92].u1Val = (U1)0x00;
  stRegICU.staIPRn[93].u1Val = (U1)0x00;
  /* n = 94 レジスタ無し */
  /* n = 95 レジスタ無し */
  /* n = 96 レジスタ無し */
  /* n = 97 レジスタ無し */
  stRegICU.staIPRn[98].u1Val = (U1)0x00;
  /* n = 99 レジスタ無し */
  /* n = 100 レジスタ無し */
  /* n = 101 レジスタ無し */
  stRegICU.staIPRn[102].u1Val = (U1)0x00;
  /* n = 103 レジスタ無し */
  /* n = 104 レジスタ無し */
  /* n = 105 レジスタ無し */
  stRegICU.staIPRn[106].u1Val = (U1)0x00;
  stRegICU.staIPRn[107].u1Val = (U1)0x00;
  stRegICU.staIPRn[108].u1Val = (U1)0x00;
  stRegICU.staIPRn[109].u1Val = (U1)0x00;
  stRegICU.staIPRn[110].u1Val = (U1)0x00;
  stRegICU.staIPRn[111].u1Val = (U1)0x00;
  stRegICU.staIPRn[112].u1Val = (U1)0x00;
  /* n = 113 レジスタ無し */
  stRegICU.staIPRn[114].u1Val = (U1)0x00;
  /* n = 115 レジスタ無し */
  /* n = 116 レジスタ無し */
  /* n = 117 レジスタ無し */
  /* n = 118 レジスタ無し */
  /* n = 119 レジスタ無し */
  /* n = 120 レジスタ無し */
  /* n = 121 レジスタ無し */
  stRegICU.staIPRn[122].u1Val = (U1)0x00;
  /* n = 123 レジスタ無し */
  /* n = 124 レジスタ無し */
  /* n = 125 レジスタ無し */
  stRegICU.staIPRn[126].u1Val = (U1)0x00;
  /* n = 127 レジスタ無し */
  /* n = 128 レジスタ無し */
  /* n = 129 レジスタ無し */
  stRegICU.staIPRn[130].u1Val = (U1)0x00;
  /* n = 131 レジスタ無し */
  stRegICU.staIPRn[132].u1Val = (U1)0x00;
  /* n = 133 レジスタ無し */
  stRegICU.staIPRn[134].u1Val = (U1)0x00;
  /* n = 135 レジスタ無し */
  /* n = 136 レジスタ無し */
  /* n = 137 レジスタ無し */
  stRegICU.staIPRn[138].u1Val = (U1)0x00;
  /* n = 139 レジスタ無し */
  stRegICU.staIPRn[140].u1Val = (U1)0x00;
  /* n = 141 レジスタ無し */
  stRegICU.staIPRn[142].u1Val = (U1)0x00;
  /* n = 143 レジスタ無し */
  /* n = 144 レジスタ無し */
  /* n = 145 レジスタ無し */
  stRegICU.staIPRn[146].u1Val = (U1)0x00;
  /* n = 147 レジスタ無し */
  stRegICU.staIPRn[148].u1Val = (U1)0x00;
  /* n = 149 レジスタ無し */
  stRegICU.staIPRn[150].u1Val = (U1)0x00;
  /* n = 151 レジスタ無し */
  stRegICU.staIPRn[152].u1Val = (U1)0x00;
  /* n = 153 レジスタ無し */
  /* n = 154 レジスタ無し */
  /* n = 155 レジスタ無し */
  stRegICU.staIPRn[156].u1Val = (U1)0x00;
  /* n = 157 レジスタ無し */
  /* n = 158 レジスタ無し */
  /* n = 159 レジスタ無し */
  stRegICU.staIPRn[160].u1Val = (U1)0x00;
  stRegICU.staIPRn[161].u1Val = (U1)0x00;
  /* n = 162 レジスタ無し */
  /* n = 163 レジスタ無し */
  stRegICU.staIPRn[164].u1Val = (U1)0x00;
  /* n = 165 レジスタ無し */
  stRegICU.staIPRn[166].u1Val = (U1)0x00;
  /* n = 167 レジスタ無し */
  /* n = 168 レジスタ無し */
  /* n = 169 レジスタ無し */
  stRegICU.staIPRn[170].u1Val = (U1)0x00;
  /* n = 171 レジスタ無し */
  /* n = 172 レジスタ無し */
  stRegICU.staIPRn[173].u1Val = (U1)0x00;
  /* n = 174 レジスタ無し */
  /* n = 175 レジスタ無し */
  stRegICU.staIPRn[176].u1Val = (U1)0x00;
  /* n = 177 レジスタ無し */
  /* n = 178 レジスタ無し */
  stRegICU.staIPRn[179].u1Val = (U1)0x00;
  /* n = 180 レジスタ無し */
  /* n = 181 レジスタ無し */
  stRegICU.staIPRn[182].u1Val = (U1)0x00;
  stRegICU.staIPRn[183].u1Val = (U1)0x00;
  stRegICU.staIPRn[184].u1Val = (U1)0x00;
  stRegICU.staIPRn[185].u1Val = (U1)0x00;
  stRegICU.staIPRn[186].u1Val = (U1)0x00;
  stRegICU.staIPRn[187].u1Val = (U1)0x00;
  stRegICU.staIPRn[188].u1Val = (U1)0x00;
  stRegICU.staIPRn[189].u1Val = (U1)0x00;
  stRegICU.staIPRn[190].u1Val = (U1)0x00;
  stRegICU.staIPRn[191].u1Val = (U1)0x00;
  stRegICU.staIPRn[192].u1Val = (U1)0x00;
  stRegICU.staIPRn[193].u1Val = (U1)0x00;
  stRegICU.staIPRn[194].u1Val = (U1)0x00;
  stRegICU.staIPRn[195].u1Val = (U1)0x00;
  stRegICU.staIPRn[196].u1Val = (U1)0x00;
  stRegICU.staIPRn[197].u1Val = (U1)0x00;
  stRegICU.staIPRn[198].u1Val = (U1)0x00;
  stRegICU.staIPRn[199].u1Val = (U1)0x00;
  stRegICU.staIPRn[200].u1Val = (U1)0x00;
  stRegICU.staIPRn[201].u1Val = (U1)0x00;
  stRegICU.staIPRn[202].u1Val = (U1)0x00;
  stRegICU.staIPRn[203].u1Val = (U1)0x00;
  /* n = 204 レジスタ無し */
  /* n = 205 レジスタ無し */
  stRegICU.staIPRn[206].u1Val = (U1)0x00;
  stRegICU.staIPRn[207].u1Val = (U1)0x00;
  stRegICU.staIPRn[208].u1Val = (U1)0x00;
  /* n = 209 レジスタ無し */
  /* n = 210 レジスタ無し */
  /* n = 211 レジスタ無し */
  /* n = 212 レジスタ無し */
  /* n = 213 レジスタ無し */
  stRegICU.staIPRn[214].u1Val = (U1)0x00;
  /* n = 215 レジスタ無し */
  /* n = 216 レジスタ無し */
  stRegICU.staIPRn[217].u1Val = (U1)0x00;
  /* n = 218 レジスタ無し */
  /* n = 219 レジスタ無し */
  stRegICU.staIPRn[220].u1Val = (U1)0x00;
  /* n = 221 レジスタ無し */
  /* n = 222 レジスタ無し */
  stRegICU.staIPRn[223].u1Val = (U1)0x00;
  /* n = 224 レジスタ無し */
  /* n = 225 レジスタ無し */
  stRegICU.staIPRn[226].u1Val = (U1)0x00;
  /* n = 227 レジスタ無し */
  /* n = 228 レジスタ無し */
  stRegICU.staIPRn[229].u1Val = (U1)0x00;
  /* n = 230 レジスタ無し */
  /* n = 231 レジスタ無し */
  stRegICU.staIPRn[232].u1Val = (U1)0x00;
  /* n = 233 レジスタ無し */
  /* n = 234 レジスタ無し */
  stRegICU.staIPRn[235].u1Val = (U1)0x00;
  /* n = 236 レジスタ無し */
  /* n = 237 レジスタ無し */
  stRegICU.staIPRn[238].u1Val = (U1)0x00;
  /* n = 239 レジスタ無し */
  /* n = 240 レジスタ無し */
  stRegICU.staIPRn[241].u1Val = (U1)0x00;
  /* n = 242 レジスタ無し */
  /* n = 243 レジスタ無し */
  stRegICU.staIPRn[244].u1Val = (U1)0x00;
  /* n = 245 レジスタ無し */
  /* n = 246 レジスタ無し */
  stRegICU.staIPRn[247].u1Val = (U1)0x00;
  /* n = 248 レジスタ無し */
  /* n = 249 レジスタ無し */
  stRegICU.staIPRn[250].u1Val = (U1)0x00;
  /* n = 251 レジスタ無し */
  /* n = 252 レジスタ無し */
  stRegICU.staIPRn[253].u1Val = (U1)0x00;
  /* n = 254 レジスタ無し */
  /* n = 255 レジスタ無し */
}


/* ============================================================ */
/* 関数名 : FnU1_HwPph_IntCtrl_getIntReq                        */
/*          割り込み要求取得                                    */
/* 引数   : tenId  割り込みベクタ番号                           */
/* 戻り値 : 割り込み要求(0:なし, 1:あり)                        */
/* 概要   : 割り込み要求要求を提供する                          */
/* 制約   : なし                                                */
/* ============================================================ */
U1 FnU1_HwPph_IntCtrl_getIntReq(EN_HwPph_IntCtrl_VecId tenId)
{
  ST_IRn tstIR;

  tstIR.u1Val = stRegICU.staIRn[tenId].u1Val;

  return (tstIR.stBit.b1IR);
}


/* ============================================================ */
/* 関数名 : FnVD_HwPph_IntCtrl_clrIntReq                        */
/*          割り込み要求クリア                                  */
/* 引数   : tenId  割り込みベクタ番号                           */
/* 戻り値 : なし                                                */
/* 概要   : 割り込み要求レジスタをクリアする                    */
/* 制約   : 割り込み禁止中に実行すること                        */
/*          割り込み要因が発生しない状況で実行すること          */
/* ============================================================ */
VD FnVD_HwPph_IntCtrl_clrIntReq(EN_HwPph_IntCtrl_VecId tenId)
{
  stRegICU.staIRn[tenId].u1Val = (U1)0x00;
}


/* ============================================================ */
/* 関数名 : FnU1_HwPph_IntCtrl_getAndClrIntReq                  */
/*          割り込み要求取得及びクリア                          */
/* 引数   : tenId  割り込みベクタ番号                           */
/* 戻り値 : なし                                                */
/* 概要   : 割り込み要求を取得し要求ありの場合は                */
/*          レジスタをクリアする                                */
/* 制約   : 割り込み禁止中に実行すること                        */
/* ============================================================ */
U1 FnU1_HwPph_IntCtrl_getAndClrIntReq(EN_HwPph_IntCtrl_VecId tenId)
{
  ST_IRn tstIR;

  tstIR.u1Val = stRegICU.staIRn[tenId].u1Val;
  if (tstIR.stBit.b1IR == (U1)C_ON) {
    stRegICU.staIRn[tenId].u1Val = (U1)0x00;
  }

  return (tstIR.stBit.b1IR);
}


/* ============================================================ */
/* 関数名 : FnVD_HwPph_IntCtrl_setEnbInt                        */
/*          割り込み要求マスク許可禁止設定                      */
/* 引数   : tenId  割り込みベクタ番号                           */
/*          tu1Enb 許可設定(0:禁止, 1:許可)                     */
/* 戻り値 : なし                                                */
/* 概要   : 割り込み要求許可レジスタの設定を行う                */
/* 制約   : 割り込み禁止中に実行すること                        */
/*          禁止する場合、割り込みは発生しなくなるが            */
/*          割り込み要求は滞留することに注意                    */
/*          (要求が滞留した状態でマスクを解除すると             */
/*           即時割り込みが発生する)                            */
/* ============================================================ */
VD FnVD_HwPph_IntCtrl_setEnbInt(EN_HwPph_IntCtrl_VecId tenId, U1 tu1Enb)
{
  U1 tu1Idx;  /* レジスタアクセス用インデックス */
  U1 tu1Pos;  /* ビット位置 */
  U1 tu1Val;  /* 作業用 */

  tu1Idx = (U1)((U1)tenId >> (U1)3);                    /* Idx = RoundDown(VecNum / 8) */
  tu1Pos = (U1)((U1)1 << (U1)((U1)tenId & (U1)0x07));   /* Pos = VecNum % 8 */

  tu1Val = stRegICU.staIERm[tu1Idx].u1Val;
  if (tu1Enb == (U1)C_OFF) {
    /* 割り込み発生禁止 */
    tu1Val &= (U1)~tu1Pos;
  }
  else {
    /* 割り込み発生許可 */
    tu1Val |= tu1Pos;
  }
  stRegICU.staIERm[tu1Idx].u1Val = tu1Val;
}


/* ============================================================ */
/* 関数名 : FnVD_HwPph_IntCtrl_setPriority                      */
/*          割り込み優先度設定                                  */
/* 引数   : tenId  割り込みベクタ番号                           */
/*          tenP   優先度(0:割り込み禁止, 1:低, ..., 15:高)     */
/* 戻り値 : なし                                                */
/* 概要   : 割り込み要因プライオリティレジスタ設定              */
/* 制約   : 割り込み禁止中に実行すること                        */
/* ============================================================ */
VD FnVD_HwPph_IntCtrl_setPriority(EN_HwPph_IntCtrl_VecId tenId, EN_HwPph_IntCtrl_Priority tenP)
{
  ST_IPRn tstIPR;  /* 割り込み要因プライオリティレジスタ */

  tstIPR.u1Val = stRegICU.staIPRn[tenId].u1Val;
  tstIPR.stBit.b4IPR = (U1)tenP;
  stRegICU.staIPRn[tenId].u1Val = tstIPR.u1Val;
}


