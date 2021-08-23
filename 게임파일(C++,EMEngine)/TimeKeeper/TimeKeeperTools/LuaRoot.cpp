//#include "stdafx.h"
//
//bool CLuaRoot::LuaStart()
//{
//	//루아 시작염
//	m_pLua = lua_open();
//
//	if(!m_pLua)
//		return false;
//
//	luabind::open(m_pLua);
//
//	return true;
//}
//
//bool CLuaRoot::LuaStop()
//{
//	if(m_pLua)
//	{
//		lua_close(m_pLua);
//		m_pLua = NULL;
//	}
//	else
//		return false;
//
//	return true;
//}
//
//bool CLuaRoot::ImportLuaInFile(char* pFileName)
//{
//	if(m_pLua)
//	{
//		//실시간으로 변경하고 싶어서 여기 에 우치 시켰어염^^
//		if(luaL_dofile(m_pLua, pFileName))
//		{
//			//	printf("luattest.lua를 읽지 못했어요");
//			return false;
//		}
//	}
//	return true;
//}