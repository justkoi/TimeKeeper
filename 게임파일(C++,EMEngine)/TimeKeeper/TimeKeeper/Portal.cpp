#include "stdafx.h"

static unsigned long nCreatePortal = 0;
void CPortal::Init(CRootScene* pThisScene)
{
	m_pPlane = new CEMAnimation(7);
	m_pPlane->SetTexture(pThisScene,7,"Data/Image/Map/Tile/Portal_1.png","Data/Image/Map/Tile/Portal_2.png","Data/Image/Map/Tile/Portal_3.png","Data/Image/Map/Tile/Portal_4.png","Data/Image/Map/Tile/Portal_5.png","Data/Image/Map/Tile/Portal_6.png","Data/Image/Map/Tile/Portal_7.png");
	m_pPlane->SetSize(2.0f,2.0f);
	m_pPlane->SetTime(0.2f);
	m_pPlane->SetPos(m_stPos);
	m_pPlane->SetBlend(true);
	m_pPlane->SetFrustumCulling(true);
	m_pPlane->SetColor(1.0f,0.5f,0.7f);
	//m_pPlane->SetOrtho2D(true);
	pThisScene->Commit(99,nCreatePortal,"Portal", m_pPlane);
	nCreatePortal++;
}

void CPortal::setNextMapIndex(int nIndex)
{
	m_nNextMapIndex = nIndex;
}
void CPortal::setHeroPos(stEMVec2 stHeroPos)
{
	m_stHeroPos = stHeroPos;
}





int CPortal::getNextMapIndex()
{
	return m_nNextMapIndex;
}
stEMVec2 CPortal::getHeroPos()
{
	return m_stHeroPos;
}