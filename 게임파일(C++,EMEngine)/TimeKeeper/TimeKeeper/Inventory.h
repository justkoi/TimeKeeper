#pragma once
#include "stdafx.h"

class CInventory
{
private:
	// stVec2i m_stSize; //!< �κ��丮 ���μ��� ũ��
	CItem m_pInventory[D_INVENTORY_HEIGHT][D_INVENTORY_WIDTH]; //!< ���� �κ��丮 ���μ���ũ�⿡ ���� �����Ҵ� // �Ҷ�ٰ� �����Ƽ�(�̷�������ȵǴµ�) �����Ҵ�
	CEMPlane* m_pItemBox[D_INVENTORY_HEIGHT][D_INVENTORY_WIDTH];
	CRootScene* m_pThisScene; //!< 
	int m_nMaxItemNumber;//!< ĭ�� �ִ� ���� ����

public:
	void Init(CRootScene* pThisScene, int nMaxItemNumber);
	void Update(float dt);
	void Exit();
public:
	stVec2i SearchSpace(); //!< ���� ����� �� ������ ã�´�. �������� ������� -1 ����;
	stVec2i SearchItem_NoFull(int nIndex); //!< ���� ����� �ش� �������� ã�´�. �������� ������� -1 ����;
	stVec2i SearchItem_All(int nIndex); //!< ���� ����� �ش� �������� ã�´�. �������� ������� -1 ����;
public:
	bool Push_Item(int nIndex, int nNumber);
	bool Pull_Item(int nIndex, int nNumber);
};