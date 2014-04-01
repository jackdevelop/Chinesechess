/*
** Lua binding: ChessRule_luabinding
** Generated automatically by tolua++-1.0.92 on 04/01/14 13:08:26.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_ChessRule_luabinding_open (lua_State* tolua_S);

#include "ChessRule.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"CHESS_TYPE");
}

/* function: judge */
#ifndef TOLUA_DISABLE_tolua_ChessRule_luabinding_judge00
static int tolua_ChessRule_luabinding_judge00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"CHESS_TYPE",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CHESS_TYPE enChessType = *((CHESS_TYPE*)  tolua_tousertype(tolua_S,1,0));
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  int tx = ((int)  tolua_tonumber(tolua_S,4,0));
  int ty = ((int)  tolua_tonumber(tolua_S,5,0));
  {
   bool tolua_ret = (bool)  judge(enChessType,x,y,tx,ty);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'judge'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: judgeBK */
#ifndef TOLUA_DISABLE_tolua_ChessRule_luabinding_judgeBK00
static int tolua_ChessRule_luabinding_judgeBK00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int x = ((int)  tolua_tonumber(tolua_S,1,0));
  int y = ((int)  tolua_tonumber(tolua_S,2,0));
  int tx = ((int)  tolua_tonumber(tolua_S,3,0));
  int ty = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   bool tolua_ret = (bool)  judgeBK(x,y,tx,ty);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'judgeBK'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: judgeBA */
#ifndef TOLUA_DISABLE_tolua_ChessRule_luabinding_judgeBA00
static int tolua_ChessRule_luabinding_judgeBA00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int x = ((int)  tolua_tonumber(tolua_S,1,0));
  int y = ((int)  tolua_tonumber(tolua_S,2,0));
  int tx = ((int)  tolua_tonumber(tolua_S,3,0));
  int ty = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   bool tolua_ret = (bool)  judgeBA(x,y,tx,ty);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'judgeBA'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: judgeBB */
#ifndef TOLUA_DISABLE_tolua_ChessRule_luabinding_judgeBB00
static int tolua_ChessRule_luabinding_judgeBB00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int x = ((int)  tolua_tonumber(tolua_S,1,0));
  int y = ((int)  tolua_tonumber(tolua_S,2,0));
  int tx = ((int)  tolua_tonumber(tolua_S,3,0));
  int ty = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   bool tolua_ret = (bool)  judgeBB(x,y,tx,ty);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'judgeBB'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: judgeBP */
#ifndef TOLUA_DISABLE_tolua_ChessRule_luabinding_judgeBP00
static int tolua_ChessRule_luabinding_judgeBP00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int x = ((int)  tolua_tonumber(tolua_S,1,0));
  int y = ((int)  tolua_tonumber(tolua_S,2,0));
  int tx = ((int)  tolua_tonumber(tolua_S,3,0));
  int ty = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   bool tolua_ret = (bool)  judgeBP(x,y,tx,ty);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'judgeBP'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: judgeRK */
#ifndef TOLUA_DISABLE_tolua_ChessRule_luabinding_judgeRK00
static int tolua_ChessRule_luabinding_judgeRK00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int x = ((int)  tolua_tonumber(tolua_S,1,0));
  int y = ((int)  tolua_tonumber(tolua_S,2,0));
  int tx = ((int)  tolua_tonumber(tolua_S,3,0));
  int ty = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   bool tolua_ret = (bool)  judgeRK(x,y,tx,ty);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'judgeRK'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: judgeRA */
#ifndef TOLUA_DISABLE_tolua_ChessRule_luabinding_judgeRA00
static int tolua_ChessRule_luabinding_judgeRA00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int x = ((int)  tolua_tonumber(tolua_S,1,0));
  int y = ((int)  tolua_tonumber(tolua_S,2,0));
  int tx = ((int)  tolua_tonumber(tolua_S,3,0));
  int ty = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   bool tolua_ret = (bool)  judgeRA(x,y,tx,ty);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'judgeRA'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: judgeRB */
#ifndef TOLUA_DISABLE_tolua_ChessRule_luabinding_judgeRB00
static int tolua_ChessRule_luabinding_judgeRB00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int x = ((int)  tolua_tonumber(tolua_S,1,0));
  int y = ((int)  tolua_tonumber(tolua_S,2,0));
  int tx = ((int)  tolua_tonumber(tolua_S,3,0));
  int ty = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   bool tolua_ret = (bool)  judgeRB(x,y,tx,ty);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'judgeRB'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: judgeRP */
#ifndef TOLUA_DISABLE_tolua_ChessRule_luabinding_judgeRP00
static int tolua_ChessRule_luabinding_judgeRP00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int x = ((int)  tolua_tonumber(tolua_S,1,0));
  int y = ((int)  tolua_tonumber(tolua_S,2,0));
  int tx = ((int)  tolua_tonumber(tolua_S,3,0));
  int ty = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   bool tolua_ret = (bool)  judgeRP(x,y,tx,ty);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'judgeRP'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: judgeN */
#ifndef TOLUA_DISABLE_tolua_ChessRule_luabinding_judgeN00
static int tolua_ChessRule_luabinding_judgeN00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int x = ((int)  tolua_tonumber(tolua_S,1,0));
  int y = ((int)  tolua_tonumber(tolua_S,2,0));
  int tx = ((int)  tolua_tonumber(tolua_S,3,0));
  int ty = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   bool tolua_ret = (bool)  judgeN(x,y,tx,ty);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'judgeN'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: judgeR */
#ifndef TOLUA_DISABLE_tolua_ChessRule_luabinding_judgeR00
static int tolua_ChessRule_luabinding_judgeR00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int x = ((int)  tolua_tonumber(tolua_S,1,0));
  int y = ((int)  tolua_tonumber(tolua_S,2,0));
  int tx = ((int)  tolua_tonumber(tolua_S,3,0));
  int ty = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   bool tolua_ret = (bool)  judgeR(x,y,tx,ty);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'judgeR'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: judgeC */
#ifndef TOLUA_DISABLE_tolua_ChessRule_luabinding_judgeC00
static int tolua_ChessRule_luabinding_judgeC00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int x = ((int)  tolua_tonumber(tolua_S,1,0));
  int y = ((int)  tolua_tonumber(tolua_S,2,0));
  int tx = ((int)  tolua_tonumber(tolua_S,3,0));
  int ty = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   bool tolua_ret = (bool)  judgeC(x,y,tx,ty);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'judgeC'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_ChessRule_luabinding_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_function(tolua_S,"judge",tolua_ChessRule_luabinding_judge00);
  tolua_function(tolua_S,"judgeBK",tolua_ChessRule_luabinding_judgeBK00);
  tolua_function(tolua_S,"judgeBA",tolua_ChessRule_luabinding_judgeBA00);
  tolua_function(tolua_S,"judgeBB",tolua_ChessRule_luabinding_judgeBB00);
  tolua_function(tolua_S,"judgeBP",tolua_ChessRule_luabinding_judgeBP00);
  tolua_function(tolua_S,"judgeRK",tolua_ChessRule_luabinding_judgeRK00);
  tolua_function(tolua_S,"judgeRA",tolua_ChessRule_luabinding_judgeRA00);
  tolua_function(tolua_S,"judgeRB",tolua_ChessRule_luabinding_judgeRB00);
  tolua_function(tolua_S,"judgeRP",tolua_ChessRule_luabinding_judgeRP00);
  tolua_function(tolua_S,"judgeN",tolua_ChessRule_luabinding_judgeN00);
  tolua_function(tolua_S,"judgeR",tolua_ChessRule_luabinding_judgeR00);
  tolua_function(tolua_S,"judgeC",tolua_ChessRule_luabinding_judgeC00);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_ChessRule_luabinding (lua_State* tolua_S) {
 return tolua_ChessRule_luabinding_open(tolua_S);
};
#endif

