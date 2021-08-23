#include "stdafx.h"

class CBlokingBlock
{
protected:
	stEMVec2 m_stPos;
public:
	CBlokingBlock(stEMVec2 stPos)
	{
		m_stPos = stPos;
	};
	~CBlokingBlock()
	{

	};
public:
	stEMVec2 getPos();
	void setPos(stEMVec2 stPos);
	
};