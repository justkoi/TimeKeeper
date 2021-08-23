#pragma once

#include "stdafx.h"

class CNPC : public CUnit
{
private:
	int m_nIndex; //!< NPC¹øÈ£
public:
	CNPC() : CUnit()
	{

	}
	~CNPC()
	{

	}
public:
	void Init(CRootScene* pThisScene,int nIndex, string strPlaneName, string strFileName,int nLayer, stEMVec2 stPos);
	void Update(float dt, CMapManager* MapManager);
	void Exit();

public:
	int getIndex();


};
