#pragma once
#include "stdafx.h"

class CObject
{
private:

public:
	CEMPlane* m_pPlane;//!< ������ �̹���
	int m_nIndex;//!< ������ ��ȣ
	int m_nNumber;//!< ������ ����
	stEMVec2 m_stPos;//!< ������ ��ǥ

public:
	void Init(CRootScene* pThisScene,stEMVec2 stPos, int nIndex, int nNumber);
	void Update(float dt);
	void Exit();
public:
	void CreateItem(CInventory* Inventory);

};