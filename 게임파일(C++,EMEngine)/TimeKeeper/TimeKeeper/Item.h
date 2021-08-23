#pragma once 
#include "stdafx.h"

class CItem
{
private:
public:
	CEMPlane* m_pPlane;//!< 아이템 이미지
	CEMText* m_pNumber;//!< 아이템 개수 표시
	stVec2i m_stPos;//!< 아이템 인벤토리 좌표 (정수형)
	CRootScene* m_pThisScene;//!< 등록 Scene
	int	m_nIndex;//!< 아이템 고유 식별번호
	int m_nNumber;//!< 아이템 개수

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