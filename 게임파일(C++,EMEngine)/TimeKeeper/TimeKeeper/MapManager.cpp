#include "stdafx.h"

void CMapManager::Init(CRootScene* pThisScene, CHero* CTargetHero)
{
	m_bNowChange = false;
	m_stNextHeroPos = stEMVec2(90.0f,90.0f);
	m_BlindManager.Init(pThisScene);
	m_CTargetHero = CTargetHero;
	m_pThisScene = pThisScene;
	ChangeMap(1,CTargetHero);
}
void CMapManager::Update(float dt)
{
	m_CNowMap->Update(dt);
	m_BlindManager.Update(dt);

	if(m_bNowChange == true)
	{
		if( m_BlindManager.m_bAction == true )
		{
			m_CNowMap->Exit();
			delete m_CNowMap;
			m_CNowMap = NULL;
			m_CNowMap = CreateMap(m_CTargetHero);
			m_BlindManager.StartBlind(1,E_BLINDSTATE_FADE_IN,1.0f,true);
			m_bNowChange = false;
			m_CTargetHero->m_bMapChangeAble = true;
			m_CTargetHero->setPos(m_stNextHeroPos);

			g_stCamPos_Stage.m_fX = m_CTargetHero->getPos().m_fX;
			if(g_stCamPos_Stage.m_fX <= D_SCREEN_WIDTH/2)
				g_stCamPos_Stage.m_fX = D_SCREEN_WIDTH/2;
			else if(g_stCamPos_Stage.m_fX >= (getCurMap()->getMapWidth() * D_TILE_WIDTH) - (D_SCREEN_WIDTH/2) - D_TILE_WIDTH)
				g_stCamPos_Stage.m_fX = (getCurMap()->getMapWidth() * D_TILE_WIDTH) - (D_SCREEN_WIDTH/2) - D_TILE_WIDTH;

			g_stCamPos_Stage.m_fY = m_CTargetHero->getPos().m_fY;
			if(g_stCamPos_Stage.m_fY >= -(D_SCREEN_HEIGHT/2))
				g_stCamPos_Stage.m_fY = -(D_SCREEN_HEIGHT/2);
			else if(g_stCamPos_Stage.m_fY <= -(getCurMap()->getMapHeight() * D_TILE_HEIGHT) + (D_SCREEN_HEIGHT/2) + D_TILE_WIDTH)
				g_stCamPos_Stage.m_fY = -(getCurMap()->getMapHeight() * D_TILE_HEIGHT) + (D_SCREEN_HEIGHT/2) + D_TILE_WIDTH;


			g_stSmoothCamPos_Stage = g_stCamPos_Stage;
		}
	}
	if(m_BlindManager.m_eState == E_BLINDSTATE_FADE_IN)
	{
		if( m_BlindManager.m_bAction == true )
		{
			m_CTargetHero->m_bMapChangeAble = true;
			m_BlindManager.m_bAction = false;
		}
	}
}
void CMapManager::Exit()
{
	
	m_CNowMap->Exit_End();
	delete m_CNowMap;
}
CPartMap* CMapManager::getCurMap()
{
	return m_CNowMap;
}
CPartMap* CMapManager::CreateMap(CHero* CTargetHero)
{
	CPartMap* CNewMap = new CPartMap();
	CNewMap->Init(m_pThisScene,m_nNowMap,CTargetHero);
	return CNewMap;
}
void CMapManager::ChangeMap(int nMapIndex, CHero* CTargetHero)
{
	//if(m_bNowChange == false)
	//{
		if(m_CNowMap == NULL)
		{
			m_nNowMap = nMapIndex;
			m_CNowMap = CreateMap(CTargetHero);
			m_BlindManager.StartBlind(1,E_BLINDSTATE_FADE_IN,1.0f);
			CTargetHero->m_bMapChangeAble = false;
		}
		else
		{
			//if(m_bNowChange == false)
			//{
				m_BlindManager.StartBlind(1,E_BLINDSTATE_FADE_OUT,1.0f);
				m_bNowChange = true;
				m_CTargetHero = CTargetHero;
				m_nNowMap = nMapIndex;
				CTargetHero->m_bMapChangeAble = false;
			//}
		}
	//}
}