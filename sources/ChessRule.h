#include "ChessDefine.h"

extern bool judge(CHESS_TYPE enChessType, int x/*original coordinate x*/, int y/*original coordinate y*/, 
						int tx/*target coordinate x*/, int ty/*target coordinate y*/);

extern bool judgeBK(int x, int y, int tx, int ty);
extern bool judgeBA(int x, int y, int tx, int ty);
extern bool judgeBB(int x, int y, int tx, int ty);
extern bool judgeBP(int x, int y, int tx, int ty);

extern bool judgeRK(int x, int y, int tx, int ty);
extern bool judgeRA(int x, int y, int tx, int ty);
extern bool judgeRB(int x, int y, int tx, int ty);
extern bool judgeRP(int x, int y, int tx, int ty);

extern bool judgeN(int x, int y, int tx, int ty);
extern bool judgeR(int x, int y, int tx, int ty);
extern bool judgeC(int x, int y, int tx, int ty);