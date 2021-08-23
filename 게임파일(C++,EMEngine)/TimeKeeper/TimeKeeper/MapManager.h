#pragma once

#include "stdafx.h"

class CHero;
class CMapManager
{
private:
	CPartMap* m_CNowMap;
	int		m_nNowMap;

	CBlindManager m_BlindManager;
	CHero* m_CTargetHero;
public:
	bool	m_bNowChange;
	CRootScene* m_pThisScene;
	stEMVec2 m_stNextHeroPos;
	CMapManager()
	{
		m_pThisScene = NULL;
		m_CNowMap = NULL;
		m_nNowMap = 1;
	};
	~CMapManager()
	{

	};
public:
	CPartMap* getCurMap();
public:
	void Init(CRootScene* pThisScene, CHero* CTargetHero);
	void Update(float dt);
	void Exit();
public:
	CPartMap* CreateMap(CHero* CTargetHero); //!< »õ·Î¿î ¸ÊÀ» ¸¸µé¾î¼­ Return;
	void DeleteMap(); //!< ÇöÀç ¸ÊÀ» Áö¿î´Ù.

	void ChangeMap(int nMapIndex, CHero* CTargetHero); //!< ¸ÊÀ» ¹Ù²Û´Ù.

};