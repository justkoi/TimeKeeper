#include "stdafx.h"
unsigned long nObjectCreateNumber = 0;

void CObject::Init(CRootScene* pThisScene,stEMVec2 stPos, int nIndex, int nNumber)
{
	m_nIndex = nIndex;
	m_nNumber = nNumber;
	m_stPos = stPos;

	string strTemp = "Data/Image/Item/Item_"+IntToEMString(nIndex)+".png";
	m_pPlane = new CEMPlane();
	m_pPlane->SetTexture(pThisScene,strTemp);
	m_pPlane->SetSize(0.7f,0.7f);
	m_pPlane->SetPos(m_stPos);
	m_pPlane->SetBlend(true);
	pThisScene->Commit(-1,nObjectCreateNumber,"Object", m_pPlane);

	nObjectCreateNumber++;
}
void CObject::Update(float dt)
{

}
void CObject::Exit()
{

}

void CObject::CreateItem(CInventory* Inventory)
{
	Inventory->Push_Item(m_nIndex,m_nNumber);
}