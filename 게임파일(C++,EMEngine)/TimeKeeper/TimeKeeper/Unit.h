#pragma once

#include "stdafx.h"

class CUnit
{
protected:
	stEMVec2 m_stPos;
	CEMPlane* m_pPlane;
public:

	CUnit()
	{
		m_stPos = stEMVec2(0.0f,0.0f);
	}
	virtual ~CUnit()
	{

	}

public:
	stEMVec2 getPos();
	void setPos(stEMVec2 stPos);
	CEMPlane* getPlane();




public:
	virtual void Init(CRootScene* pThisScene, string strPlaneName, string strFileName,int nLayer, stEMVec2 stPos);
	virtual void Update(float dt);
	virtual void Exit();
public:
	void MoveX(float fX);
	void MoveY(float fY);


};