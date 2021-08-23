#include "stdafx.h"
stEMVec3	g_stCamPos_Stage;	//!< 카메라 위치 저장 벡터
stEMVec3	g_stSmoothCamPos_Stage;	//!< 카메라 위치 저장 벡터
void CStage::Enter(CSceneWork* pSceneWork)
{
	g_stCamPos_Stage = stEMVec3(D_TILE_WIDTH * 9 , -(D_TILE_HEIGHT * 9),D_CAM_Z_FIXED);
	g_stSmoothCamPos_Stage = g_stCamPos_Stage;

	m_fFixZ = D_CAM_Z_FIXED;

	D_SOUNDMNG->Play("BGM_1",false,0.4f);

	m_stMousePos = stEMVec2(0.0f,0.0f);
	m_stScreenMousePos = stEMVec2(0.0f,0.0f);
	m_MapTools.Init(this);
	CRootScene::Enter(pSceneWork);
}

void CStage::Update(CSceneWork* pSceneWork, float dt)
{
	
	m_MapTools.Update(dt);

	m_stMousePos = CEMMath::ScreenToWorld(m_stScreenMousePos.m_fX,m_stScreenMousePos.m_fY);
	m_MapTools.CheckMove(m_stMousePos);

	D_CAMERA->SetPos(g_stSmoothCamPos_Stage);



	CRootScene::Update(pSceneWork, dt);
}

void CStage::Render(CSceneWork* pSceneWork)
{


	CRootScene::Render(pSceneWork);
}

void CStage::Exit(CSceneWork* pSceneWork)
{

	
	Destroy();

	//delete m_pBar;

	CRootScene::Exit(pSceneWork);
}

void CStage::MouseDownEvent(stMouseInfo stPos, enumMouseButton eButton)
{
	stEMVec2 stTempPos = CEMMath::ScreenToWorld(stPos.m_nX,stPos.m_nY);
	
	m_MapTools.CheckDown(stTempPos);
	/*if(m_CMapManager.getCurMap()->getIndex() == 1)
		m_CMapManager.ChangeMap(2, &m_CHero);
	else if(m_CMapManager.getCurMap()->getIndex() == 2)
		m_CMapManager.ChangeMap(1, &m_CHero);*/
}

void CStage::MouseUpEvent(stMouseInfo stPos, enumMouseButton eButton)
{
	stEMVec2 stTempPos = CEMMath::ScreenToWorld(stPos.m_nX,stPos.m_nY);
	

	m_MapTools.CheckUp(stTempPos);
}

void CStage::MouseMoveEvent(stMouseInfo stPos)
{
	m_stScreenMousePos.m_fX = stPos.m_nX;
	m_stScreenMousePos.m_fY = stPos.m_nY;
	stEMVec2 stTempPos = CEMMath::ScreenToWorld(stPos.m_nX,stPos.m_nY);
	m_stMousePos = stTempPos;
}

HRESULT CStage::WindowMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
	case WM_LBUTTONDOWN:
		{
			int x = 0;
		}break;
	case WM_KEYDOWN:
		{
			switch(wParam)
			{
			case VK_TAB:
				m_MapTools.TabTile();
				break;
			case '1':
				m_MapTools.m_eEditMod = (E_EDIT_MOD)0;
				break;
			case '2':
				m_MapTools.m_eEditMod = (E_EDIT_MOD)1;
				break;
			case 'S':
				m_MapTools.SaveData();
				break;
			case 'O':
				m_MapTools.m_nIndex++;
				break;
			case 'P':
				m_MapTools.m_nIndex--;
				break;
			}
		}break;
	
	
	}
	return msg;
}


void CStage::BeginContact(b2Contact* contact)
{
	CEMPhysicRoot::BeginContact(contact);
	//아래에 코드를 작성하세요


}

void CStage::EndContact(b2Contact* contact)
{
	CEMPhysicRoot::EndContact(contact);
	//아래에 코드를 작성하세요

}

void CStage::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
{
	CEMPhysicRoot::PreSolve(contact, oldManifold);
	//아래에 코드를 작성하세요

}

void CStage::PostSolve(const b2Contact* contact, const b2ContactImpulse* impulse)
{
	CEMPhysicRoot::PostSolve(contact, impulse);
	//아래에 코드를 작성하세요

}
