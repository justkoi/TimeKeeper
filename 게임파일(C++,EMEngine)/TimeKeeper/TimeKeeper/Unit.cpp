#include "stdafx.h"

static unsigned long nCreateUnitNum = 0;
stEMVec2 CUnit::getPos()
{
	return m_stPos;
}

void CUnit::setPos(stEMVec2 stPos)
{
	m_stPos = stPos;
}

void CUnit::Init(CRootScene* pThisScene, string strPlaneName, string strFileName,int nLayer, stEMVec2 stPos)
{
	m_stPos = stPos;
//	m_stRealPos.m_fX = stPos.m_fX - D_TILE_WIDTH;
//	m_stRealPos.m_fY = stPos.m_fY;
	m_pPlane = new CEMPlane();
	m_pPlane->SetTexture(pThisScene,strFileName,GL_REPEAT,GL_LINEAR,true);
	m_pPlane->SetSize(1.0f,1.0f);
	m_pPlane->SetPos(stPos);
	m_pPlane->SetBlend(true);
	m_pPlane->SetBackFaceCulling(true);
	m_pPlane->SetFrustumCulling(true);
	//m_pPlane->SetOrtho2D(true);
	pThisScene->Commit(nLayer,nCreateUnitNum,strPlaneName, m_pPlane);
	nCreateUnitNum++;
}

void CUnit::Update(float dt)
{
	m_pPlane->SetPos(m_stPos);
}
void CUnit::Exit()
{

}
void CUnit::MoveX(float fX)
{
	m_stPos.m_fX += fX;
}
void CUnit::MoveY(float fY)
{
	m_stPos.m_fY += fY;
}

CEMPlane* CUnit::getPlane()
{
	return m_pPlane;
}