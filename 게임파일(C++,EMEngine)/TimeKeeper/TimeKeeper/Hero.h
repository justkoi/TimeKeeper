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

class CHero
{
private:
	stEMVec2 m_stPos;
	float	m_fMoveSpeed;
	bool	m_bKeyDown[E_Derection_Max];
	bool	m_bHitTest[E_Derection_Max];
	CChatWindow* m_pChatWindow;
	CEMPlane* m_pFlash;
	E_Derection m_eDerection;
	CEMAnimation* m_pHero[E_Derection_Max];
public:
	bool	m_bNPCHit;
	bool	m_bMapChangeAble;
	int		m_nNPCIndex;

	CHero()
	{
		m_stPos = stEMVec2(0.0f,0.0f);
	}
	~CHero()
	{

	}

public:
	float getMoveSpeed();
	void setMoveSpeed(float fMoveSpeed);

public:
	void Init(CRootScene* pThisScene,CChatWindow* pChatWindow, string strPlaneName, string strFileName,int nLayer, stEMVec2 stPos);
	void Update(float dt, CMapManager* MapManager, CInventory* Inventory);
	void Exit();
public:
	void MoveUpdate(float dt, CMapManager* MapManager, CInventory* Inventory);
	void ShowUpdate();
	bool HitTest(stEMVec2 stPos1, stEMVec2 stPixel1, stEMVec2 stPos2, stEMVec2 stPixel2);
	void MoveX(float fX);
	void MoveY(float fY);
	stEMVec2 getPos();
	void setPos(stEMVec2 stPos);
};