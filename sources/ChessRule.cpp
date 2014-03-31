#include "ChessRule.h"

// (x,y) The original coordinates,(tx, ty) The target coordinates
bool judge(CHESS_TYPE enChessType, int x, int y, int tx, int ty)
{
	switch(enChessType)
	{
	case CHESS_BK:
		return judgeBK(x, y, tx, ty);
		break;
	case CHESS_BA:
		return judgeBA(x, y, tx, ty);
		break;
	case CHESS_BB:
		return judgeBB(x, y, tx, ty);
		break;
	case CHESS_BP:
		return judgeBP(x, y, tx, ty);
		break;
	case CHESS_RK:
		return judgeRK(x, y, tx, ty);
		break;
	case CHESS_RA:
		return judgeRA(x, y, tx, ty);
		break;
	case CHESS_RB:
		return judgeRB(x, y, tx, ty);
		break;
	case CHESS_RC:
	case CHESS_BC:
		return judgeC(x, y, tx, ty);
		break;
	case CHESS_BN:
	case CHESS_RN:
		return judgeN(x, y, tx, ty);
		break;
	case CHESS_BR:
	case CHESS_RR:
		return judgeR(x, y, tx, ty);
		break;
	case CHESS_RP:
		return judgeRP(x, y, tx, ty);
		break;
	default:
		return false;
	}
}

bool judgeBK(int x, int y, int tx, int ty)
{
	if (tx < 0 || tx > 2 || ty < 3 || ty > 5)
	{
		return false;
	}
	int x0 = tx - x;
	int y0 = ty - y;
	for(int i = 0; i < 4; ++i)
	{
		if(k[i][0] == x0 && k[i][1] == y0)
		{
			return true;
		}
	}
	return false;
}

bool judgeBA(int x, int y, int tx, int ty)
{
	if (tx < 0 || tx > 2 || ty < 3 || ty > 5)
	{
		return false;
	}
	
	int x0 = tx - x;
	int y0 = ty - y;
	for (int i = 0; i < 4; ++i)
	{
		if (a[i][0] == x0 && a[i][1] == y0)
		{
			return true;
		}
	}
	return false;
}

bool judgeBB(int x, int y, int tx, int ty)
{
	if (tx < 0 || tx > 4)
	{
		return false;
	}
	int x0 = tx - x;
	int y0 = ty - y;
	for (int i = 0; i < 4; ++i)
	{
		if (b[i][0] == x0 && b[i][1] == y0 && g_cur_map[x + tx >> 1][y + ty >> 1] == 0)
		{
			return true;
		}
	}
	return false;
}

bool judgeBP(int x, int y, int tx, int ty)
{
	if (tx < 3 || x - tx > 0)
	{
		return false;
	}
	if (x > 4 && ( (tx - x == 1 && abs(y - ty) == 0) ||
		(tx - x == 0 && abs(y - ty) == 1)))
	{
		return true;
	}
	else if (x <= 4 && tx - x == 1 && y == ty)
	{
		return true;
	}
	return false;
}

bool judgeRK(int x, int y, int tx, int ty)
{
	if (tx < 7 || tx > 9 || ty < 3 || ty > 5)
	{
		return false;
	}
	int x0 = tx - x;
	int y0 = ty - y;
	bool ret = false;
	for(int i = 0; i < 4; ++i)
	{
		if(k[i][0] == x0 && k[i][1] == y0)
		{
			return true;
		}
	}
	return false;
}

bool judgeRA(int x, int y, int tx, int ty)
{
	if (tx < 7 || tx > 9 || ty < 3 || ty > 5)
	{
		return false;
	}
	int a[4][2] = {{-1, 1}, {-1, -1}, {1, 1}, {1, -1}};
	int x0 = tx - x;
	int y0 = ty - y;
	for (int i = 0; i < 4; ++i)
	{
		if (a[i][0] == x0 && a[i][1] == y0)
		{
			return true;
		}
	}
	return false;
}

bool judgeRB(int x, int y, int tx, int ty)
{
	if (tx < 5 || tx > 9)
	{
		return false;
	}
	int x0 = tx - x;
	int y0 = ty - y;
	for (int i = 0; i < 4; ++i)
	{
		if (b[i][0] == x0 && b[i][1] == y0 && g_cur_map[x + tx >> 1][y + ty >> 1] == 0)
		{
			return true;
		}
	}
	return false;
}

bool judgeRP(int x, int y, int tx, int ty)
{
	if (tx > 7 || x - tx < 0)
	{
		return false;
	}
	if (x < 5 && ( (x - tx == 1 && abs(y - ty) == 0) ||
		(x - tx == 0 && abs(y - ty) == 1)))
	{
		return true;
	}
	else if (x >= 5 && abs(x - tx) == 1 && y == ty)
	{
		return true;
	}
	return false;
}

bool judgeC(int x, int y, int tx, int ty)
{
	int n = 0;
	if (x == tx && y - ty > 0)
	{
		for (int i = y - 1; i > ty; --i)
		{
			if(g_cur_map[x][i] != 0 && (++n == 2 || g_cur_map[tx][ty] == 0))
			{
				return false;
			}
		}
		return true;
	}
	else if (x == tx && y - ty < 0)
	{
		for (int i = y + 1; i < ty; ++i)
		{
			if(g_cur_map[x][i] != 0 && (++n == 2 || g_cur_map[tx][ty] == 0))
			{
				return false;
			}
		}
		return true;
	}
	else if (y == ty && x - tx > 0)
	{
		for (int i = x - 1; i > tx; --i)
		{
			if (g_cur_map[i][y] != 0 && (++n == 2 || g_cur_map[tx][ty] == 0))
			{
				return false;
			}
		}
		return true;
	}
	else if (y == ty && x - tx < 0)
	{
		for (int i = x + 1; i < tx; ++i)
		{
			if (g_cur_map[i][y] != 0 && (++n == 2 || g_cur_map[tx][ty] == 0))
			{
				return false;
			}
		}
		return true;
	}

	return false;
}

bool judgeN(int x, int y, int tx, int ty)
{
	int x0 = tx - x;
	int y0 = ty - y;
	for (int i = 0; i < 8; ++i)
	{
		if (n[i][0] == x0 && n[i][1] == y0)
		{
			if(abs(x0) == 2 && g_cur_map[x + tx >> 1][y] == 0)
			{
				return true;
			}
			else if (abs(x0) == 1 && g_cur_map[x][y + ty >> 1] == 0)
			{
				return true;
			}
			return false;
		}
	}
	return false;
}

bool judgeR(int x, int y, int tx, int ty)
{
	if (x == tx && y - ty > 0)
	{
		for (int i = y - 1; i > ty; --i)
		{
			if(g_cur_map[x][i] != 0)
			{
				return false;
			}
		}
		return true;
	}
	else if (x == tx && y - ty < 0)
	{
		for (int i = y + 1; i < ty; ++i)
		{
			if(g_cur_map[x][i] != 0)
			{
				return false;
			}
		}
		return true;
	}
	else if (y == ty && x - tx > 0)
	{
		for (int i = x - 1; i > tx; --i)
		{
			if (g_cur_map[i][y] != 0)
			{
				return false;
			}
		}
		return true;
	}
	else if (y == ty && x - tx < 0)
	{
		for (int i = x + 1; i < tx; ++i)
		{
			if (g_cur_map[i][y] != 0)
			{
				return false;
			}
		}
		return true;
	}

	return false;
}