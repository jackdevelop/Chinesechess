#include "ChessDefine.h"

const int g_chess_map[10][9] =
{
	// black
	{207,205,203,201,200,202,204,206,208},
	{  0,  0,  0,  0,  0,  0,  0,  0,  0},
	{  0,209,  0,  0,  0,  0,  0,210,  0},
	{211,  0,212,  0,213,  0,214,  0,215},
	{  0,  0,  0,  0,  0,  0,  0,  0,  0},
	// border
	{  0,  0,  0,  0,  0,  0,  0,  0,  0},
	{111,  0,112,  0,113,  0,114,  0,115},
	{  0,109,  0,  0,  0,  0,  0,110,  0},
	{  0,  0,  0,  0,  0,  0,  0,  0,  0},
	{107,105,103,101,100,102,104,106,108},
	// red
};

const CHESS_TYPE g_chess[2][16] = 
{
   {CHESS_BK, 
	CHESS_BA, CHESS_BA, 
	CHESS_BB, CHESS_BB, 
	CHESS_BN, CHESS_BN, 
	CHESS_BR, CHESS_BR, 
	CHESS_BC, CHESS_BC,
	CHESS_BP, CHESS_BP, CHESS_BP, CHESS_BP, CHESS_BP},
   {CHESS_RK, 
	CHESS_RA, CHESS_RA, 
	CHESS_RB, CHESS_RB, 
	CHESS_RN, CHESS_RN, 
	CHESS_RR, CHESS_RR, 
	CHESS_RC, CHESS_RC,
	CHESS_RP, CHESS_RP, CHESS_RP, CHESS_RP, CHESS_RP},
};

CCPoint g_chess_coord[10][9];
int g_cur_map[10][9] = {0};
int g_out_map[10][9] = {0};

const int k[4][2] = {{ 0, 1}, { 0, -1}, {-1, 0}, { 1,  0}};
const int a[4][2] = {{-1, 1}, {-1, -1}, { 1, 1}, { 1, -1}};
const int b[4][2] = {{-2, 2}, {-2, -2}, { 2, 2}, { 2, -2}};
const int n[8][2] = {{-2, 1}, {-2,  1}, {-1, 2}, {-1, -2},
					 { 1, 2}, { 1, -2}, { 2, 1}, { 2, -1}};