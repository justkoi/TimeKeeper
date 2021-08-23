#include "stdafx.h"
stEMVec3	g_stCamPos_Stage;	//!< ī�޶� ��ġ ���� ����
stEMVec3	g_stSmoothCamPos_Stage;	//!< ī�޶� ��ġ ���� ����
CInventory	g_CInventory;//!< �κ��丮
CMapManager g_CMapManager;
CHero		g_CHero;
CChatWindow g_CChatWindow;
void CStage::Enter(CSceneWork* pSceneWork)
{
	g_stCamPos_Stage = stEMVec3(D_TILE_WIDTH * 9 , -(D_TILE_HEIGHT * 9),D_CAM_Z_FIXED);
	g_stSmoothCamPos_Stage = g_stCamPos_Stage;

	m_fFixZ = D_CAM_Z_FIXED;
	
	//m_pBar = TwNewBar("Test");
//	TwAddVarRW(m_pBar, "Camera_z", TW_TYPE_FLOAT, &m_fFixZ, " label = 'Camera z' min=-1000 max=2500 step=0.1 keyIncr=z keyDecr=Z help = 'Camera z' ");
	g_CMapManager.Init(this, &g_CHero);
	g_CChatWindow.Init(this);
	m_CPauseWindow.Init(this);

	g_CHero.Init(this,&g_CChatWindow,"Hero","Data/Man/3.png",-3,stEMVec2(D_TILE_WIDTH * 6 , -(D_TILE_HEIGHT * 6) ));
	//g_CHero.getPlane()->SetSize(0.3f,0.3f);
	g_CInventory.Init(this,99);


	//g_CMapManager.ChangeMap(3,&g_CHero);
	g_CMapManager.m_stNextHeroPos = stEMVec2(128,-128);
	// g_CInventory.Push_Item(0,98);
	
	// g_nEventLevel = 0; //!< ���� �ൿ�� �Ұ����� ���� ���ż��� ��ȭ�ϱ� ���
	// g_nQuestLevel = 4; //!< ���� ����� ����
	// g_nChatLevel = 0;
	// g_nConditionLevel = 1;//!< ���� �ش�Ǵ� ���� ����



	m_fGame_PlayTimer = 0;



	m_CTextDebug = new CEMText("����ü","");
	m_CTextDebug->SetPos(30.0f,30.0f);
    Commit(-10,"TextDebug",m_CTextDebug);


	D_SOUNDMNG->Play("BGM_1",false,0.4f);
	CRootScene::Enter(pSceneWork);
}

void CStage::Update(CSceneWork* pSceneWork, float dt)
{
	// m_CTextDebug->SetOutPutString("����ʹ�ȣ ("+IntToEMString(g_CMapManager.getCurMap()->getIndex())+"), ����Ʈ���� ("+IntToEMString(g_nQuestLevel)+"), �̺�Ʈ����("+IntToEMString(g_nEventLevel)+"), ���ǹ�ȣ("+IntToEMString(g_nConditionLevel)+")");

	g_CHero.Update(dt, &g_CMapManager, &g_CInventory);
	m_CPauseWindow.Update(dt);
	g_CMapManager.Update(dt);
	g_CChatWindow.Update(dt, &g_CInventory);
	g_CInventory.Update(dt);

	m_fGame_PlayTimer += dt;
	if(m_fGame_PlayTimer >= 1.0f && g_nQuestLevel == 0)
	{
		g_nQuestLevel++;
		g_nEventLevel = 0;
		g_CChatWindow.ChatStart(-1);
	}






	g_stCamPos_Stage.m_fX = g_CHero.getPos().m_fX;
	if(g_stCamPos_Stage.m_fX <= D_SCREEN_WIDTH/2)
		g_stCamPos_Stage.m_fX = D_SCREEN_WIDTH/2;
	else if(g_stCamPos_Stage.m_fX >= (g_CMapManager.getCurMap()->getMapWidth() * D_TILE_WIDTH) - (D_SCREEN_WIDTH/2) - D_TILE_WIDTH)
		g_stCamPos_Stage.m_fX = (g_CMapManager.getCurMap()->getMapWidth() * D_TILE_WIDTH) - (D_SCREEN_WIDTH/2) - D_TILE_WIDTH;

	g_stCamPos_Stage.m_fY = g_CHero.getPos().m_fY;
	if(g_stCamPos_Stage.m_fY >= -(D_SCREEN_HEIGHT/2))
		g_stCamPos_Stage.m_fY = -(D_SCREEN_HEIGHT/2);
	else if(g_stCamPos_Stage.m_fY <= -(g_CMapManager.getCurMap()->getMapHeight() * D_TILE_HEIGHT) + (D_SCREEN_HEIGHT/2) + D_TILE_WIDTH)
		g_stCamPos_Stage.m_fY = -(g_CMapManager.getCurMap()->getMapHeight() * D_TILE_HEIGHT) + (D_SCREEN_HEIGHT/2) + D_TILE_WIDTH;

	g_stSmoothCamPos_Stage = CEMMath::SmoothStep<stEMVec3>(g_stSmoothCamPos_Stage,g_stCamPos_Stage,0.08f);
	g_stSmoothCamPos_Stage.m_fZ = m_fFixZ;
	D_CAMERA->SetPos(g_stSmoothCamPos_Stage);



	CRootScene::Update(pSceneWork, dt);
}

void CStage::Render(CSceneWork* pSceneWork)
{


	CRootScene::Render(pSceneWork);
}

void CStage::Exit(CSceneWork* pSceneWork)
{

	
	g_CMapManager.Exit();
	Destroy();

	g_CHero.Exit();
	//delete m_pBar;

	CRootScene::Exit(pSceneWork);
}

void CStage::MouseDownEvent(stMouseInfo stPos, enumMouseButton eButton)
{
	/*if(g_CMapManager.getCurMap()->getIndex() == 1)
		g_CMapManager.ChangeMap(2, &g_CHero);
	else if(g_CMapManager.getCurMap()->getIndex() == 2)
		g_CMapManager.ChangeMap(1, &g_CHero);*/

	if(eButton == E_MOUSE_LEFT)
	{
		m_CPauseWindow.Check_Down(stPos);
	}
}

void CStage::MouseUpEvent(stMouseInfo stPos, enumMouseButton eButton)
{
	if(eButton == E_MOUSE_LEFT)
	{
		m_CPauseWindow.Check_Up(stPos);
	}
}

void CStage::MouseMoveEvent(stMouseInfo stPos)
{
	m_CPauseWindow.Check_Move(stPos);
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
			case VK_ESCAPE:
				if(m_CPauseWindow.Moving() == false)
				{
					if(g_bPause == false)
						m_CPauseWindow.Pause();
					else if(g_bPause == true)
						m_CPauseWindow.Resume();
				}
				break;
			}
		}break;
	}
	return msg;
}


void CStage::BeginContact(b2Contact* contact)
{
	CEMPhysicRoot::BeginContact(contact);
	//�Ʒ��� �ڵ带 �ۼ��ϼ���


}

void CStage::EndContact(b2Contact* contact)
{
	CEMPhysicRoot::EndContact(contact);
	//�Ʒ��� �ڵ带 �ۼ��ϼ���

}

void CStage::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
{
	CEMPhysicRoot::PreSolve(contact, oldManifold);
	//�Ʒ��� �ڵ带 �ۼ��ϼ���

}

void CStage::PostSolve(const b2Contact* contact, const b2ContactImpulse* impulse)
{
	CEMPhysicRoot::PostSolve(contact, impulse);
	//�Ʒ��� �ڵ带 �ۼ��ϼ���

}
