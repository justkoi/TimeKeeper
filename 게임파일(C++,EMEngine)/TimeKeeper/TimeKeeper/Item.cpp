#include "stdafx.h"
unsigned long nItemCreateNumber = 0;
void CItem::Init(CRootScene* pThisScene,stVec2i stPos, int nIndex, int nNumber)
{
	m_nIndex = nIndex;
	m_nNumber = nNumber;
	m_stPos = stPos;
	m_pThisScene = pThisScene;

	string strTemp = "Data/Image/Item/Item_"+IntToEMString(nIndex)+".png";
	m_pPlane = new CEMPlane();
	m_pPlane->SetTexture(pThisScene,strTemp);
	m_pPlane->SetSize(1.0f,1.0f);
	m_pPlane->SetPos(D_INVENTORY_START_X + (D_ITEM_WIDTH*stPos.m_fX),D_INVENTORY_START_Y + (D_ITEM_HEIGHT*stPos.m_fY));
	m_pPlane->SetBlend(true);
	m_pPlane->SetOrtho2D(true);
	pThisScene->Commit(-1003,nItemCreateNumber,"Item", m_pPlane);

	m_pNumber = new CEMText("À¸¶äÃ¼",IntToEMString(m_nNumber));
	m_pNumber->SetSize(1.0f,1.0f);
	m_pNumber->SetPos(D_INVENTORY_START_X + (D_ITEM_WIDTH*stPos.m_fX) + 15,D_INVENTORY_START_Y + (D_ITEM_HEIGHT*stPos.m_fY) + 25);
	m_pNumber->SetBlend(true);
	m_pNumber->SetOrtho2D(true);
	pThisScene->Commit(-1003,nItemCreateNumber,"TextNumber", m_pNumber);
	nItemCreateNumber++;
}
void CItem::Update(float dt)
{
	int nCount = 0;
	int nTempNumber = m_nNumber;

	m_pPlane->SetShow(g_bPause);
	m_pNumber->SetShow(g_bPause);
	if(m_nIndex == -1)
	{
		m_pPlane->SetShow(false);
		m_pNumber->SetShow(false);
	}
	if(g_PauseWindowState != E_PAUSEWINDOW_BUTTON_ITEM)
	{
		m_pPlane->SetShow(false);
		m_pNumber->SetShow(false);
	}
	m_pNumber->SetOutPutString(IntToEMString(m_nNumber));

	while( (nTempNumber /= 10) > 0)
	{
		nCount++;
	}
	m_pPlane->SetPos(D_INVENTORY_START_X + (D_ITEM_WIDTH*m_stPos.m_fX),D_INVENTORY_START_Y + (D_ITEM_HEIGHT*m_stPos.m_fY));
	m_pNumber->SetPos(D_INVENTORY_START_X + (D_ITEM_WIDTH*m_stPos.m_fX) + 15 - (13*nCount),D_INVENTORY_START_Y + (D_ITEM_HEIGHT*m_stPos.m_fY) + 25);
}
void CItem::Empty()
{
	//m_pPlane = NULL;
	//m_pNumber = NULL;
	m_stPos.m_fX = -1;
	m_stPos.m_fY = -1;
	m_nIndex = -1;
	m_nNumber = -1;
}
void CItem::Create(stVec2i stPos, int nIndex, int nNumber)
{
	m_stPos = stPos;
	m_nIndex = nIndex;
	m_nNumber = nNumber;
	string strTemp = "Data/Image/Item/Item_"+IntToEMString(m_nIndex)+".png";
	m_pPlane->SetTexture(m_pThisScene,strTemp);
}

void CItem::SetPos(stVec2i stPos)
{
	m_stPos = stPos;
}
void CItem::SetIndex(int nIndex)
{
	m_nIndex = nIndex;
}
void CItem::SetNumber(int nNumber)
{
	m_nNumber = nNumber;
}