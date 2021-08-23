//#include "stdafx.h"
//
//
//CMng* CMng::Instance()
//{
//	static CMng I;
//	return &I;
//}
//
//void CMng::Update(float dt)
//{
//
//}
//
// bool CMng::SetModule(lua_State* pLua)
// {
//	 //===================================================
//	 //  #define 되어진것 연결합니다
//	 luabind::globals( pLua )[ "VK_LEFT" ]				= VK_LEFT;
//	 luabind::globals( pLua )[ "VK_UP" ]					= VK_UP;
//	 luabind::globals( pLua )[ "VK_RIGHT" ]				= VK_RIGHT;
//	 luabind::globals( pLua )[ "VK_DOWN" ]				= VK_DOWN;
//	 luabind::globals( pLua )[ "VK_SPACE" ]			= VK_SPACE;
//	 luabind::globals(pLua)["NULL"]						= NULL;
//
// 	// luabind::module(pLua)
// 	//	[
//			////===================================================
//			//// CEMAnimation
//			//luabind::class_<CEMAnimation>("CEMAnimation")
//			//.def(luabind::constructor<int>())
//			//.def("MoveX", &CEMAnimation::MoveX)
//			//.def("MoveY", &CEMAnimation::MoveY)
//			//.def("MoveZ", &CEMAnimation::MoveZ),
//			//
//			////===================================================
//			//// CEMInput
// 		//	luabind::class_<CEMInput>("CEMInput")
// 		//	.def("IsKeyDown", &CEMInput::IsKeyDown)
// 		//	.def("IsKeyUp", &CEMInput::IsKeyUp),		
//
//			////===================================================
//			//// CEHero
//			//luabind::class_<CHero>("CHero")
//			//.def(luabind::constructor<>())
//			//.def("SetJumpPower", &CHero::SetJumpPower)
//	//	];
//
// 	return true;
// }
