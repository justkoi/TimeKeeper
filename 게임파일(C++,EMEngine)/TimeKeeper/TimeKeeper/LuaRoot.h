//#pragma once
//
//
////!========================================================
////! ��ư��� include
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
//	@brief   : ��� ���� �ֻ��� Ŭ���� �Դϴ�. 
//				  ��� �����ż� ����Ͻø�˴ϴ�.
//
//			    [����Ͻ÷���]
//					1. ��Ƹ� �����Ͻñ� ���ؼ��� Lua���̺귯�� ������ �����մϴ�
//					2. ������Ʈ�� �Ӽ�â���� ���ż� lu/include  �� lua/luabind/incldue ���߰��ϼž��մϴ�
//					3. lua/lib  �� lua/luabind�� �߰��ϼž��մϴ�
//					4. ���������� lua.x86.debug.lib;luabind_d.lib �� �߰��ؾ��մϴ� Release����϶��� lua.x86.release.lib;luabind.lib�� �߰��ؾ��մϴ�^^
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
//	// ��� ���� ������ �����ϻ�^^
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