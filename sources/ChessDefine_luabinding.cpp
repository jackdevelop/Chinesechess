/*
** Lua binding: ChessDefine_luabinding
** Generated automatically by tolua++-1.0.92 on 04/01/14 13:27:43.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_ChessDefine_luabinding_open (lua_State* tolua_S);

#include "cocos2d.h"
#include "ChessDefine.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
}

/* Open function */
TOLUA_API int tolua_ChessDefine_luabinding_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_constant(tolua_S,"CHESS_NONE",CHESS_NONE);
  tolua_constant(tolua_S,"CHESS_BK",CHESS_BK);
  tolua_constant(tolua_S,"CHESS_BA",CHESS_BA);
  tolua_constant(tolua_S,"CHESS_BB",CHESS_BB);
  tolua_constant(tolua_S,"CHESS_BN",CHESS_BN);
  tolua_constant(tolua_S,"CHESS_BR",CHESS_BR);
  tolua_constant(tolua_S,"CHESS_BC",CHESS_BC);
  tolua_constant(tolua_S,"CHESS_BP",CHESS_BP);
  tolua_constant(tolua_S,"CHESS_BORDER",CHESS_BORDER);
  tolua_constant(tolua_S,"CHESS_RK",CHESS_RK);
  tolua_constant(tolua_S,"CHESS_RA",CHESS_RA);
  tolua_constant(tolua_S,"CHESS_RB",CHESS_RB);
  tolua_constant(tolua_S,"CHESS_RN",CHESS_RN);
  tolua_constant(tolua_S,"CHESS_RR",CHESS_RR);
  tolua_constant(tolua_S,"CHESS_RC",CHESS_RC);
  tolua_constant(tolua_S,"CHESS_RP",CHESS_RP);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_ChessDefine_luabinding (lua_State* tolua_S) {
 return tolua_ChessDefine_luabinding_open(tolua_S);
};
#endif

