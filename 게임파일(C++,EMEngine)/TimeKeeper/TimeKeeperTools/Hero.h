#pragma once

#include "stdafx.h"

typedef enum
{
	E_Derection_Left,
	E_Derection_Right,
	E_Derection_Up,
	E_Derection_Down,
	E_Derection_Max
}E_Derection;

class CHero : public CUnit
{
private:
	float	m_fMoveSpeed;
	bool	m_bKeyDown[E_Derection_Max];
	bool	m_bHitTest[E_Derection_Max];
	CChatWindow* m_pChatWindow;
public:
	bool	m_bNPCHit;
	bool	m_bMapChangeAble;
	int		m_nNPCIndex;

	CHero() : CUnit()
	{

	}
	~CHero()
	{

	}

public:
	float getMoveSpeed();
	void setMoveSpeed(float fMoveSpeed);

public:
	void Init(CRootScene* pThisScene,CChatWindow* pChatWindow, string strPlaneName, string strFileName,int nLayer, stEMVec2 stPos);
	void Update(float dt, CMapManager* MapManager);
	void Exit();
public:
	void MoveUpdate(float dt, CMapManager* MapManager);
	bool HitTest(stEMVec2 stPos1, stEMVec2 stPixel1, stEMVec2 stPos2, stEMVec2 stPixel2);
};