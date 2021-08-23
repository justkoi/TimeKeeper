#pragma once

#include "stdafx.h"

class CPortal : public CBlokingBlock
{
private:
	
	int		m_nNextMapIndex;//!< ���� �̵� �� ��ȣ
	stEMVec2 m_stHeroPos; //!< �� �̵� �� ����� ��ǥ


public:
	CEMAnimation* m_pPlane;
	//CEMPlane* m_pPlane; //!< ��Ż �̹���
	CPortal(stEMVec2 stPos, int nNextMapIndex, stEMVec2 stHeroPos)
		: CBlokingBlock(stPos)
	{
		m_stHeroPos = stHeroPos;
		m_nNextMapIndex = nNextMapIndex;
	}
	~CPortal()
	{

	}
public:
	void Init(CRootScene* pThisScene);

	void setNextMapIndex(int nIndex);
	void setHeroPos(stEMVec2 stHeroPos);

	int getNextMapIndex();
	stEMVec2 getHeroPos();
};