#include "stdafx.h"
#include <crtdbg.h>
#define CRTDBG_MAP_ALLOC
#ifdef _DEBUG
	#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

INT WINAPI WinMain( HINSTANCE hInstance, HINSTANCE, LPSTR,  int)
{
#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc( 167466 ); 
#endif
	D_SOUNDMNG->Commit("BGM_1","Data/Sound/BGM_1.mp3");
	D_WORLD->WorldInit("TimeKeeperTools",  D_SCREEN_SIZE_X(D_SCREEN_SCALE), D_SCREEN_SIZE_Y(D_SCREEN_SCALE), false);			//!< ���带 �����մϴ�
	//D_WORLD->WorldInit();
	D_WORLD->SetBackColor(CEMColor(255, 255, 255));														//!< ������ �����մϴ�.
	D_WORLD->Commit(new CEMGrid());																		//!< �׸��� �߰��մϴ�.
	D_WORLD->SetBoundingBoxShowFlag(true);																//!< �ٿ�� �ڽ� �����ְ��մϴ�
	//D_WORLD->SetFpsShowFlag(true);
 	//D_WORLD->SetMouseCursor( "data/image/Mouse/cursor_up.png",
 	//				 		  stEMVec2(15.0f, -15.0f),
 	//						 "data/image/Mouse/cursor_down.png",
 	//						  stEMVec2(20.0f, -20.0f)			//!< �׸� �� �ǿ������� offset�� �̵��ؾ��ϹǷ� �׸� ������(32) - 16��ŭ ���ָ� �˴ϴ�
		//					 );	

	D_WORLD->SetMaxFrame(E_FRAMESKIP_MAX, 60.0f);				//! Ű�Է�/����/������Ʈ ���� ���� 50���������� �����մϴ�
	
	D_SCENE->Commit(new CStage, "Stage");				//!< ���þ� ���
	D_SCENE->ChangeScene("Stage");

	D_WORLD->RunLoop();
	return 1;
}