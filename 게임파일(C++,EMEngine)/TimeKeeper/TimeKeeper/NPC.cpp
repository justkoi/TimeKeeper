#include "stdafx.h"

void CNPC::Init(CRootScene* pThisScene,int nIndex, string strPlaneName, string strFileName,int nLayer, stEMVec2 stPos)
{
	m_nIndex = nIndex;
	CUnit::Init(pThisScene,strPlaneName,strFileName,nLayer,stPos);
	//!< 아래에 초기화 추가 구문을 작성합니다.
	
}

void CNPC::Update(float dt, CMapManager* MapManager)
{
	//!< 위에 업데이트 추가 구문을 작성합니다.
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