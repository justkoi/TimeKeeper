#include "stdafx.h"
void CMenu::Enter(CSceneWork* pSceneWork)
{
	
	CRootScene::Enter(pSceneWork);
	
}

void CMenu::Update(CSceneWork* pSceneWork, float dt)
{
	
	D_CAMERA->SetPos(m_stCamPos);
	CRootScene::Update(pSceneWork, dt);
}

void CMenu::Render(CSceneWork* pSceneWork)
{


	CRootScene::Render(pSceneWork);
}

void CMenu::Exit(CSceneWork* pSceneWork)
{
	Destroy();
	CRootScene::Exit(pSceneWork);
}

void CMenu::MouseDownEvent(stMouseInfo stPos, enumMouseButton eButton)
{

}

void CMenu::MouseUpEvent(stMouseInfo stPos, enumMouseButton eButton)
{

}

void CMenu::MouseMoveEvent(stMouseInfo stPos)
{

}

HRESULT CMenu::WindowMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
	case WM_LBUTTONDOWN:
		{
			int x = 0;
		}break;
	}
	return msg;
}


void CMenu::BeginContact(b2Contact* contact)
{
	CEMPhysicRoot::BeginContact(contact);
	//아래에 코드를 작성하세요


}

void CMenu::EndContact(b2Contact* contact)
{
	CEMPhysicRoot::EndContact(contact);
	//아래에 코드를 작성하세요

}

void CMenu::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
{
	CEMPhysicRoot::PreSolve(contact, oldManifold);
	//아래에 코드를 작성하세요

}

void CMenu::PostSolve(const b2Contact* contact, const b2ContactImpulse* impulse)
{
	CEMPhysicRoot::PostSolve(contact, impulse);
	//아래에 코드를 작성하세요

}
