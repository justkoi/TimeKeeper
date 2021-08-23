#pragma once
#include "stdafx.h"

class CObject
{
private:

public:
	CEMPlane* m_pPlane;//!< 아이템 이미지
	int m_nIndex;//!< 아이템 번호
	int m_nNumber;//!< 아이템 개수
	stEMVec2 m_stPos;//!< 아이템 좌표

public:
	void Init(CRootScene* pThisScene,stEMVec2 stPos, int nIndex, int nNumber);
	void Update(float dt);
	void Exit();
public:
	void CreateItem(CInventory* Inventory);

};