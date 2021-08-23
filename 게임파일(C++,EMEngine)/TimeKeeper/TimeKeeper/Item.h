#pragma once 
#include "stdafx.h"

class CItem
{
private:
public:
	CEMPlane* m_pPlane;//!< ������ �̹���
	CEMText* m_pNumber;//!< ������ ���� ǥ��
	stVec2i m_stPos;//!< ������ �κ��丮 ��ǥ (������)
	CRootScene* m_pThisScene;//!< ��� Scene
	int	m_nIndex;//!< ������ ���� �ĺ���ȣ
	int m_nNumber;//!< ������ ����

	void SetPos(stVec2i stPos);
	void SetIndex(int nIndex);
	void SetNumber(int nNumber);
	CItem()
	{
		m_pPlane = NULL;
		m_pNumber = NULL;
		m_stPos.m_fX = -1;
		m_stPos.m_fY = -1;
		m_nIndex = -1;
		m_nNumber = -1;
	}
public:
	void Init(CRootScene* pThisScene,stVec2i stPos, int nIndex, int nNumber);
	void Update(float dt);
	void Empty();
	void Create(stVec2i stPos, int nIndex, int nNumber);


};