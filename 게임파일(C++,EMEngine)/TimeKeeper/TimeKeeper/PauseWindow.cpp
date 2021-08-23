#include "stdafx.h"
bool g_bPause = false;
E_PAUSEWINDOW_BUTTON g_PauseWindowState = E_PAUSEWINDOW_BUTTON_ITEM;
void CPauseWindow::Init(CRootScene* pThisScene)
{
	m_pThisScene = pThisScene;

	m_stPos = stEMVec2(612,768/2);
	m_fDistance = 0.0f;
	m_fMoveSpeed = 500.0f;
	m_fPlusMoveSpeed = 1000.0f;

	
	m_pPlane = new CEMPlane();
	m_pPlane->SetTexture(pThisScene,"Data/Image/Effect/Pause.png");
	m_pPlane->SetSize(1.0f,1.0f);
	m_pPlane->SetPos(0.0f,0.0f);
	m_pPlane->SetBlend(true);
	m_pPlane->SetOrtho2D(true);
	pThisScene->Commit(-1002,"PauseWindow", m_pPlane);

	m_pBlind = new CEMPlane();
	m_pBlind->SetTexture(pThisScene,"Data/Image/Effect/Blind.png");
	m_pBlind->SetSize(1.0f,1.0f);
	m_pBlind->SetPos(512.0f,512.0f);
	m_pBlind->SetBlend(true);
	m_pBlind->SetOrtho2D(true);
	m_pBlind->SetAlpha(0.7f);
	pThisScene->Commit(-1001,"PauseWindowBlind", m_pBlind);
	
	for(int j=1; j<E_PAUSEWINDOW_BUTTON_MAX; j++)
	{
		m_pPauseImg[j] = new CEMPlane();
		m_pPauseImg[j]->SetTexture(pThisScene,"Data/Image/Stage/PauseWindow"+IntToEMString(((int)j)+1)+".png");
		m_pPauseImg[j]->SetSize(0.5f,0.5f);
		m_pPauseImg[j]->SetPos(180.0f,(768/2) - 100);
		m_pPauseImg[j]->SetBlend(true);
		m_pPauseImg[j]->SetShow(true);
		m_pPauseImg[j]->SetOrtho2D(true);
		pThisScene->Commit(-1003,j,"PauseWindow", m_pPauseImg[j]);
	}

	for(int j=0; j<E_PAUSEWINDOW_BUTTON_MAX; j++)
	{
		

		

		for(int i=0; i<3; i++)
		{
			m_pButtonImg[j][i] = new CEMPlane();						
			m_pButtonImg[j][i]->SetSize(1.0f, 1.0f);				
			m_pButtonImg[j][i]->SetPos(512.0f, 512.0f, 0.0f);
			m_pButtonImg[j][i]->SetTexture(pThisScene, "Data/Image/Button/Button_PauseWindow"+IntToEMString(((int)j)+1)+"_"+IntToEMString(i+1)+".png");
			m_pButtonImg[j][i]->SetFrustumCulling(true);
			m_pButtonImg[j][i]->SetBlend(true);	
			m_pButtonImg[j][i]->SetOrtho2D(true);
			m_pButtonImg[j][i]->SetShow(true);
			pThisScene->Commit(-1003,(j*100)+i, "E_PAUSEWINDOW_BUTTON", m_pButtonImg[j][i]);
		}
	}

	for(int i=0; i<E_PAUSEWINDOW_BUTTON_MAX; i++)
	{
		m_Button[i].Init(pThisScene,m_pButtonImg[i][0],m_pButtonImg[i][1],m_pButtonImg[i][2], stEMVec2(600,200 + (i*80)), true);
	}
}
void CPauseWindow::Update(float dt)
{
	m_pBlind->SetShow(g_bPause);
	m_pPlane->SetShow(g_bPause);


	for(int i=0; i<E_PAUSEWINDOW_BUTTON_MAX; i++)
	{
		m_Button[i].Update(dt);
		m_Button[i].m_bVisible = g_bPause;
	}

	for(int i=0; i<E_PAUSEWINDOW_BUTTON_MAX; i++)
	{
		if(m_Button[i].IsAction() == true)
		{
			m_Button[i].m_bAction = false;
			g_PauseWindowState = (E_PAUSEWINDOW_BUTTON)i;
		}
	}
	for(int i=1; i<E_PAUSEWINDOW_BUTTON_MAX; i++)
	{
		m_pPauseImg[i]->SetShow(false);
	}
	if(g_bPause == true)
	{
		if(g_PauseWindowState != E_PAUSEWINDOW_BUTTON_ITEM)
			m_pPauseImg[g_PauseWindowState]->SetShow(true);
	}
	else if(g_bPause == false)
	{
		for(int i=1; i<E_PAUSEWINDOW_BUTTON_MAX; i++)
		{
			m_pPauseImg[i]->SetShow(false);
		}
	}



	/*if(m_fDistance < 0)
	{
		m_fDistance += m_fMoveSpeed * dt;
		m_stPos.m_fX -= m_fMoveSpeed * dt;
		m_fMoveSpeed += m_fPlusMoveSpeed * dt;
		if(m_fDistance >= 0)
		{
			m_fDistance = 0;
			m_fMoveSpeed = 500.0f;
			m_fPlusMoveSpeed = 1000.0f;
		}
	}
	else if(m_fDistance > 0)
	{
		m_fDistance -= m_fMoveSpeed * dt;
		m_stPos.m_fX += m_fMoveSpeed * dt;
		m_fMoveSpeed += m_fPlusMoveSpeed * dt;
		if(m_fDistance <= 0)
		{
			m_fDistance = 0;
			m_fMoveSpeed = 500.0f;
			m_fPlusMoveSpeed = 1000.0f;
		}
	}*/

	m_pPlane->SetPos(m_stPos);
}

void CPauseWindow::Check_Down(stMouseInfo stPos)
{
	for(int i=0; i<E_PAUSEWINDOW_BUTTON_MAX; i++)
	{
		m_Button[i].Check_Down(stPos);
	}
}
void CPauseWindow::Check_Move(stMouseInfo stPos)
{
	for(int i=0; i<E_PAUSEWINDOW_BUTTON_MAX; i++)
	{
		m_Button[i].Check_Move(stPos);
	}
}
void CPauseWindow::Check_Up(stMouseInfo stPos)
{
	for(int i=0; i<E_PAUSEWINDOW_BUTTON_MAX; i++)
	{
		m_Button[i].Check_Up(stPos);
	}
}

void CPauseWindow::Exit()
{

}

void CPauseWindow::Pause()
{
	g_bPause = true;
}
void CPauseWindow::Resume()
{
	g_bPause = false;
}

bool CPauseWindow::Moving()
{/*
	if(m_fDistance == 0)
		return false;*/
	return false;
}

void CPauseWindow::SaveStage(int nStage)
{
	char strFilePath[256];
	sprintf(strFilePath,"Data/SaveData%d.sav",nStage);
	//FILE * fp = fopen(strFilePath);

	//fwrite(&g_bStageLock[i],sizeof(bool),1,fp);
	

	//fclose(fp);
}
void CPauseWindow::LoadStage(int nStage)
{

}