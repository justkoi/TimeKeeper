#include "stdafx.h"

void CNPC::Init(CRootScene* pThisScene,int nIndex, string strPlaneName, string strFileName,int nLayer, stEMVec2 stPos)
{
	m_nIndex = nIndex;
	CUnit::Init(pThisScene,strPlaneName,strFileName,nLayer,stPos);
	//!< �Ʒ��� �ʱ�ȭ �߰� ������ �ۼ��մϴ�.
	
}

void CNPC::Update(float dt, CMapManager* MapManager)
{
	//!< ���� ������Ʈ �߰� ������ �ۼ��մϴ�.
	CUnit::Update(dt);
}
void CNPC::Exit()
{
	CNPC::Exit();
}

int CNPC::getIndex()
{
	return m_nIndex;
}