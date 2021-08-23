#include "stdafx.h"
#include <crtdbg.h>
#define CRTDBG_MAP_ALLOC
#ifdef _DEBUG
	#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif


float	g_SVolume = 0.5f;
bool	g_bSoundCheck = false;
bool	g_bEffectSoundCheck = false;
float	g_fMouseX	= 0.0f;
float	g_fMouseY	= 0.0f;
stEMVec2	m_stSoundGageXY = stEMVec2(-60.0f,-23.0f);
stEMVec2	g_MousePosition = 0.0f;

INT WINAPI WinMain( HINSTANCE hInstance, HINSTANCE, LPSTR,  int)
{
#ifdef _DEBUG
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc( 167466 );
#endif
	D_SOUNDMNG->Commit("Portal","Data/Sound/Portal.mp3");
	D_SOUNDMNG->Commit("LevelUp","Data/Sound/LevelUp.mp3");
	D_SOUNDMNG->Commit("BGM_1","Data/Sound/BGM_1.mp3");
	D_SOUNDMNG->Commit("BGM_2","Data/Sound/BGM_2.mp3");
	D_SOUNDMNG->Commit("Enter","Data/Sound/Enter.wav");
	D_SOUNDMNG->Commit("Clear","Data/Sound/Clear.mp3");
	D_SOUNDMNG->Commit("Tick","Data/Sound/Tick.mp3");
	D_WORLD->WorldInit("TimeKeeper",  D_SCREEN_SIZE_X(D_SCREEN_SCALE), D_SCREEN_SIZE_Y(D_SCREEN_SCALE), true);//!< 월드를 설정합니다
	//D_WORLD->WorldInit();
	D_WORLD->SetBackColor(CEMColor(255, 255, 255));//!< 배경색을 지정합니다.
	//D_WORLD->Commit(new CEMGrid())//!< 그리드 추가합니다.
	//D_WORLD->SetBoundingBoxShowFlag(true);//!< 바운딩 박스 보여주게합니다
	D_WORLD->SetFpsShowFlag(true);
 	//D_WORLD->SetMouseCursor( "data/image/Mouse/cursor_up.png",
 	//				 		  stEMVec2(15.0f, -15.0f),
 	//						 "data/image/Mouse/cursor_down.png",
 	//						  stEMVec2(20.0f, -20.0f)			//!< 그림 의 맨왼쪽위로 offset이 이동해야하므로 그림 사이즈(32) - 16만큼 해주면 됩니다
		//					 );	

	D_WORLD->SetMaxFrame(E_FRAMESKIP_MAX, 60.0f);//! 키입력/물리/오브젝트 까지 전부 50프레임으로 고정합니다
	
	D_SCENE->Commit(new CStage, "Stage");
	D_SCENE->Commit(new CLogo, "Logo");
	D_SCENE->Commit(new CMenu, "Menu");
	D_SCENE->Commit(new CCredit, "Credit");
	D_SCENE->Commit(new COption, "Option");
	D_SCENE->ChangeScene("Logo");

	D_WORLD->RunLoop();

	return 1;
}