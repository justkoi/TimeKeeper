//#include "stdafx.h"
//
//bool CLuaRoot::LuaStart()
//{
//	//��� ���ۿ�
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
//		//�ǽð����� �����ϰ� �; ���� �� ��ġ ���׾^^
//		if(luaL_dofile(m_pLua, pFileName))
//		{
//			//	printf("luattest.lua�� ���� ���߾��");
//			return false;
//		}
//	}
//	return true;
//}