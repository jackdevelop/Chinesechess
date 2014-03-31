#ifndef __CHINESE_CHESS_DEFINE_H__
#define __CHINESE_CHESS_DEFINE_H__

#include "cocos2d.h"

USING_NS_CC;

enum CHESS_TYPE
{
	CHESS_NONE,
	CHESS_BK		= 1,
	CHESS_BA,
	CHESS_BB,
	CHESS_BN,
	CHESS_BR,
	CHESS_BC,
	CHESS_BP,
	CHESS_BORDER	= 10,
	CHESS_RK		= 11,
	CHESS_RA,
	CHESS_RB,
	CHESS_RN,
	CHESS_RR,
	CHESS_RC,
	CHESS_RP,
};

extern int				g_cur_map[10][9];
extern int				g_out_map[10][9];
extern CCPoint			g_chess_coord[10][9];
extern const int		g_chess_map[10][9];
extern const CHESS_TYPE g_chess[2][16];

extern const int k[4][2];
extern const int a[4][2];
extern const int b[4][2];
extern const int n[8][2];

#endif // __CHINESE_CHESS_DEFINE_H__