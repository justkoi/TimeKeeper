#pragma once

#include "stdafx.h"

class CPortal : public CBlokingBlock
{
private:
	
	int		m_nNextMapIndex;//!< ´ÙÀ½ ÀÌµ¿ ¸Ê ¹øÈ£
	stEMVec2 m_stHeroPos; //!< ¸Ê ÀÌµ¿ ÈÄ È÷¾î·Î ÁÂÇ¥


public:
	CEMAnimation* m_pPlane;
	//CEMPlane* m_pPlane; //!< Æ÷Å» ÀÌ¹ÌÁö
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