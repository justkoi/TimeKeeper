//#pragma once
//
//
////!========================================================
////! 루아관련 include
//extern "C" 
//{
//#include "lua.h"
//#include "lualib.h"
//#include "lauxlib.h"
//}
//
//#include <luabind/luabind.hpp>
//
///**
//	@file    : CLuaRoot
//	@author  : wo
//	@version : 1.0f
//	@brief   : 루아 설정 최상위 클래스 입니다. 
//				  상속 받으셔서 사용하시면됩니다.
//
//			    [사용하시려면]
//					1. 루아를 연결하시기 위해서는 Lua라이브러리 파일을 복사합니다
//					2. 프로젝트의 속성창으로 가셔서 lu/include  와 lua/luabind/incldue 를추가하셔야합니다
//					3. lua/lib  와 lua/luabind도 추가하셔야합니다
//					4. 마지막으로 lua.x86.debug.lib;luabind_d.lib 를 추가해야합니다 Release모드일때는 lua.x86.release.lib;luabind.lib를 추가해야합니다^^
//*/
//class CLuaRoot
//{
//private:
//	lua_State*		m_pLua;
//
//public:
//	CLuaRoot()
//	{
//		m_pLua = NULL;
//	};
//
//	virtual ~CLuaRoot()
//	{
//		LuaStop();
//	};
//
//public:
//	// 상속 받은 곳에서 연결하삼^^
//	virtual bool LuaInit() = 0;
//
//public:
//	lua_State*		GetLuaPt()			{ return m_pLua; }
//
//	bool LuaStart();
//	bool LuaStop();
//
//	bool ImportLuaInFile(char* pFileName);
//};