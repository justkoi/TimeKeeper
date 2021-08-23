#pragma once
#include "stdafx.h"

class CInventory
{
private:
	// stVec2i m_stSize; //!< 인벤토리 가로세로 크기
	CItem m_pInventory[D_INVENTORY_HEIGHT][D_INVENTORY_WIDTH]; //!< 실제 인벤토리 가로세로크기에 따른 동적할당 // 할라다가 귀찮아서(이런말쓰면안되는데) 정적할당
	CEMPlane* m_pItemBox[D_INVENTORY_HEIGHT][D_INVENTORY_WIDTH];
	CRootScene* m_pThisScene; //!< 
	int m_nMaxItemNumber;//!< 칸당 최대 보유 개수

public:
	void Init(CRootScene* pThisScene, int nMaxItemNumber);
	void Update(float dt);
	void Exit();
public:
	stVec2i SearchSpace(); //!< 가장 가까운 빈 공간을 찾는다. 존재하지 않을경우 -1 리턴;
	stVec2i SearchItem_NoFull(int nIndex); //!< 가장 가까운 해당 아이템을 찾는다. 존재하지 않을경우 -1 리턴;
	stVec2i SearchItem_All(int nIndex); //!< 가장 가까운 해당 아이템을 찾는다. 존재하지 않을경우 -1 리턴;
public:
	bool Push_Item(int nIndex, int nNumber);
	bool Pull_Item(int nIndex, int nNumber);
};