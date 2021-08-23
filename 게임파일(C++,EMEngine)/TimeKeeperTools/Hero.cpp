#include "stdafx.h"


void CHero::Init(CRootScene* pThisScene,CChatWindow* pChatWindow, string strPlaneName, string strFileName,int nLayer, stEMVec2 stPos)
{
	m_bMapChangeAble = true;
	m_pChatWindow = pChatWindow;
	CUnit::Init(pThisScene,strPlaneName,strFileName,nLayer,stPos);
	//!< 아래에 초기화 추가 구문을 작성합니다.
	m_fMoveSpeed = 170.0f;
	m_nNPCIndex = 0;
}

void CHero::Update(float dt, CMapManager* MapManager)
{
	MoveUpdate(dt, MapManager);
	//!< 위에 업데이트 추가 구문을 작성합니다.
	CUnit::Update(dt);
}
void CHero::Exit()
{
	CUnit::Exit();
}

/////////////////



float CHero::getMoveSpeed()
{
	return m_fMoveSpeed;
}

void CHero::setMoveSpeed(float fMoveSpeed)
{
	m_fMoveSpeed = fMoveSpeed;
}
void CHero::MoveUpdate(float dt, CMapManager* MapManager)
{
	
	for(int i=0; i<E_Derection_Max; i++)
	{
		m_bKeyDown[i] = false;
		m_bHitTest[i] = false;
	}
	
	m_bNPCHit = false;
	
	if(g_bChating == false)
	{
		if(GetKeyState(VK_LEFT) & 0x8000)
		{
			list<CBlokingBlock*>::iterator it;
			for(it = MapManager->getCurMap()->m_BlokingMap.begin(); it != MapManager->getCurMap()->m_BlokingMap.end(); it++)
			{
				stEMVec2 stTemp1 = m_stPos;
				stTemp1.m_fX = stTemp1.m_fX - (m_fMoveSpeed * dt);//  //
				stTemp1.m_fY = stTemp1.m_fY; //
			

				stEMVec2 stTemp2 = (*it)->getPos();
				stTemp2.m_fX = stTemp2.m_fX;//  //
				stTemp2.m_fY = stTemp2.m_fY; //
			
				if(HitTest(stTemp1, stEMVec2(D_HERO_WIDTH,D_HERO_HEIGHT), stTemp2,stEMVec2(D_TILE_WIDTH,D_TILE_HEIGHT)) == true)
				{
					m_bHitTest[E_Derection_Left] = true;
					break;
				}
			}
			if(m_bHitTest[E_Derection_Left] == false)
			{
				m_bKeyDown[E_Derection_Left] = true;
				MoveX(-m_fMoveSpeed * dt);
			}
		}
		else if(GetKeyState(VK_RIGHT) & 0x8000)
		{
			list<CBlokingBlock*>::iterator it;
			for(it = MapManager->getCurMap()->m_BlokingMap.begin(); it != MapManager->getCurMap()->m_BlokingMap.end(); it++)
			{
				stEMVec2 stTemp1 = m_stPos;
				stTemp1.m_fX = stTemp1.m_fX + (m_fMoveSpeed * dt);//  //
				stTemp1.m_fY = stTemp1.m_fY; //
			

				stEMVec2 stTemp2 = (*it)->getPos();
				stTemp2.m_fX = stTemp2.m_fX;//  //
				stTemp2.m_fY = stTemp2.m_fY; //
			
				if(HitTest(stTemp1, stEMVec2(D_HERO_WIDTH,D_HERO_HEIGHT), stTemp2,stEMVec2(D_TILE_WIDTH,D_TILE_HEIGHT)) == true)
				{
					m_bHitTest[E_Derection_Right] = true;
					break;
				}
			}
			if(m_bHitTest[E_Derection_Right] == false)
			{
				m_bKeyDown[E_Derection_Right] = true;
				MoveX(+m_fMoveSpeed * dt);
			}
		}


		if(GetKeyState(VK_UP) & 0x8000)
		{
			list<CBlokingBlock*>::iterator it;
			for(it = MapManager->getCurMap()->m_BlokingMap.begin(); it != MapManager->getCurMap()->m_BlokingMap.end(); it++)
			{
				stEMVec2 stTemp1 = m_stPos;
				stTemp1.m_fX = stTemp1.m_fX;//  //
				stTemp1.m_fY = stTemp1.m_fY + (m_fMoveSpeed * dt); //
			

				stEMVec2 stTemp2 = (*it)->getPos();
				stTemp2.m_fX = stTemp2.m_fX;//  //
				stTemp2.m_fY = stTemp2.m_fY; //
			
				if(HitTest(stTemp1, stEMVec2(D_HERO_WIDTH,D_HERO_HEIGHT), stTemp2,stEMVec2(D_TILE_WIDTH,D_TILE_HEIGHT)) == true)
				{
					m_bHitTest[E_Derection_Up] = true;
					break;
				}
			}
			if(m_bHitTest[E_Derection_Up] == false)
			{
				m_bKeyDown[E_Derection_Up] = true;
				MoveY(+m_fMoveSpeed * dt);
			}
		}
		else if(GetKeyState(VK_DOWN) & 0x8000)//(D_TILE_HEIGHT * 1))
		{
			list<CBlokingBlock*>::iterator it;
			for(it = MapManager->getCurMap()->m_BlokingMap.begin(); it != MapManager->getCurMap()->m_BlokingMap.end(); it++)
			{
				stEMVec2 stTemp1 = m_stPos;
				stTemp1.m_fX = stTemp1.m_fX;//  //
				stTemp1.m_fY = stTemp1.m_fY - (m_fMoveSpeed * dt); //
			

				stEMVec2 stTemp2 = (*it)->getPos();
				stTemp2.m_fX = stTemp2.m_fX;//  //
				stTemp2.m_fY = stTemp2.m_fY; //
			
				if(HitTest(stTemp1, stEMVec2(D_HERO_WIDTH,D_HERO_HEIGHT), stTemp2,stEMVec2(D_TILE_WIDTH,D_TILE_HEIGHT)) == true)
				{
					m_bHitTest[E_Derection_Down] = true;
					break;
				}
			}
			if(m_bHitTest[E_Derection_Down] == false)
			{
				m_bKeyDown[E_Derection_Down] = true;
				MoveY(-m_fMoveSpeed * dt);
			}
		}
	}
	if(m_bMapChangeAble == true)
	{
		list<CPortal*>::iterator it;
		for(it = MapManager->getCurMap()->m_PortalMap.begin(); it != MapManager->getCurMap()->m_PortalMap.end(); it++)
		{
			stEMVec2 stTemp1 = m_stPos;
			stTemp1.m_fX = stTemp1.m_fX;//  //
			stTemp1.m_fY = stTemp1.m_fY; //
			

			stEMVec2 stTemp2 = (*it)->getPos();
			stTemp2.m_fX = stTemp2.m_fX;//  //
			stTemp2.m_fY = stTemp2.m_fY; //
			
			if(HitTest(stTemp1, stEMVec2(D_HERO_WIDTH,D_HERO_HEIGHT), stTemp2,stEMVec2(D_TILE_WIDTH,D_TILE_HEIGHT)) == true)
			{
				MapManager->ChangeMap((*it)->getNextMapIndex(),this);
				MapManager->m_stNextHeroPos = (*it)->getHeroPos();

				//this->setPos((*it)->getHeroPos()); 
			/*	g_stCamPos_Stage.m_fX = this->getPos().m_fX;
				if(g_stCamPos_Stage.m_fX <= D_SCREEN_WIDTH/2)
					g_stCamPos_Stage.m_fX = D_SCREEN_WIDTH/2;
				else if(g_stCamPos_Stage.m_fX >= (MapManager->getCurMap()->getMapWidth() * D_TILE_WIDTH) - (D_SCREEN_WIDTH/2) - D_TILE_WIDTH)
					g_stCamPos_Stage.m_fX = (MapManager->getCurMap()->getMapWidth() * D_TILE_WIDTH) - (D_SCREEN_WIDTH/2) - D_TILE_WIDTH;

				g_stCamPos_Stage.m_fY = this->getPos().m_fY;
				if(g_stCamPos_Stage.m_fY >= -(D_SCREEN_HEIGHT/2))
					g_stCamPos_Stage.m_fY = -(D_SCREEN_HEIGHT/2);
				else if(g_stCamPos_Stage.m_fY <= -(MapManager->getCurMap()->getMapHeight() * D_TILE_HEIGHT) + (D_SCREEN_HEIGHT/2) + D_TILE_WIDTH)
					g_stCamPos_Stage.m_fY = -(MapManager->getCurMap()->getMapHeight() * D_TILE_HEIGHT) + (D_SCREEN_HEIGHT/2) + D_TILE_WIDTH;


				g_stSmoothCamPos_Stage = g_stCamPos_Stage;*/

				break;
			}
		}
	}






	list<CNPC*>::iterator it;
	for(it = MapManager->getCurMap()->m_NPCMap.begin(); it != MapManager->getCurMap()->m_NPCMap.end(); it++)
	{
		stEMVec2 stTemp1 = m_stPos;
		stTemp1.m_fX = stTemp1.m_fX;//  //
		stTemp1.m_fY = stTemp1.m_fY; //
			
		
		stEMVec2 stTemp2 = (*it)->getPos();
		stTemp2.m_fX = stTemp2.m_fX;//  //
		stTemp2.m_fY = stTemp2.m_fY; //

		if( HitTest(stTemp1, stEMVec2(D_HERO_WIDTH,D_HERO_HEIGHT), stTemp2,stEMVec2(D_TILE_WIDTH,D_TILE_HEIGHT))  == true )
		{
			m_bNPCHit = true;
			m_nNPCIndex = (*it)->getIndex();
			break;
		}
	}




	//!< 스무스스텝

	//if(m_bKeyDown[E_Derection_Right] == false)
	//{
	//	if(m_stPos.m_fX > (D_SCREEN_SIZE_X(40))) //!< 캐릭터가 화면의 50% 이상 넘어왓을때
	//	{
	//		float fTemp = ( (m_stPos.m_fX ) - (D_SCREEN_SIZE_X(40)))/50;
	//		if( !(m_stRealPos.m_fX <= (D_SCREEN_WIDTH/2) - 512.0f + 500.0f) && !(m_stRealPos.m_fX >= (D_TILE_WIDTH * (CNowMap->getMapWidth())) - (D_SCREEN_WIDTH/2) -80.0f)) //!< 화면넘어가지 않아야할경우
	//		{
	//			m_stPos.m_fX -= fTemp;
	//			g_stVirtualCamPos.m_fX -= fTemp;
	//		}
	//	}
	//}
	//
	//if(m_bKeyDown[E_Derection_Left] == false)
	//{
	//	if(m_stPos.m_fX < (D_SCREEN_SIZE_X(40))) //!< 캐릭터가 화면의 50% 이하로 넘어왓을때
	//	{
	//		float fTemp = ( (m_stPos.m_fX ) - (D_SCREEN_SIZE_X(40)))/50;
	//		if(!(m_stRealPos.m_fX <= (D_SCREEN_WIDTH/2) - 512.0f + 256.0f + 80.0f) && !(m_stRealPos.m_fX >= (D_TILE_WIDTH * (CNowMap->getMapWidth())) - (D_SCREEN_WIDTH/2) -218.0f)) //!< 화면넘어가지 않아야할경우
	//		{
	//			m_stPos.m_fX -= fTemp;
	//			g_stVirtualCamPos.m_fX -= fTemp;
	//		}
	//	}
	//}

	//
	//if(m_bKeyDown[E_Derection_Up] == false)
	//{
	//	if(m_stPos.m_fY < (D_SCREEN_SIZE_Y(40))) //!< 캐릭터가 화면의 50% 이상 넘어왓을때
	//	{
	//		float fTemp = ( (m_stPos.m_fY ) - (D_SCREEN_SIZE_Y(40)))/50;
	//		if( !(m_stRealPos.m_fY <= (D_SCREEN_HEIGHT/2) - (D_SCREEN_HEIGHT/2) + 256.0f + 64.0f) && !(m_stRealPos.m_fY >= (D_TILE_HEIGHT * (CNowMap->getMapHeight())) - (D_SCREEN_HEIGHT/2) - 180.0f)) //!< 화면넘어가지 않아야할경우
	//		{
	//			m_stPos.m_fY -= fTemp;
	//			g_stVirtualCamPos.m_fY -= fTemp;
	//		}
	//	}
	//}
	//
	//if(m_bKeyDown[E_Derection_Down] == false)
	//{
	//	if(m_stPos.m_fY > (D_SCREEN_SIZE_Y(40))) //!< 캐릭터가 화면의 50% 이하로 넘어왓을때
	//	{
	//		float fTemp = ( (m_stPos.m_fY ) - (D_SCREEN_SIZE_Y(40)))/50;
	//		if(!(m_stRealPos.m_fY <= (D_SCREEN_HEIGHT/2) - (D_SCREEN_HEIGHT/2) + 256.0f + 64.0f) && !(m_stRealPos.m_fY >= (D_TILE_HEIGHT * (CNowMap->getMapHeight())) - (D_SCREEN_HEIGHT/2) - 180.0f)) //!< 화면넘어가지 않아야할경우
	//		{
	//			m_stPos.m_fY -= fTemp;
	//			g_stVirtualCamPos.m_fY -= fTemp;
	//		}
	//	}
	//}
	int i=0;
	for(i=0; i<E_Derection_Max; i++)
	{
		if(m_bHitTest[i] == true)
		{
			m_pPlane->SetColor(0.0f,0.0f,0.0f,0.5f);
			break;
		}
	}
	if(i == E_Derection_Max)
	{
		m_pPlane->SetColor(1.0f,1.0f,1.0f,1.0f);
	}

	if(m_bNPCHit == true)
	{
		m_pPlane->SetColor(1.0f,0.2f,0.2f,0.5f);
		
		if(GetKeyState(VK_RETURN) & 0x8000)
		{
			if(g_bChating == false)
			{
				m_pChatWindow->ChatStart(m_nNPCIndex);
			}
		}
	}

 }
 
bool CHero::HitTest(stEMVec2 stPos1, stEMVec2 stPixel1, stEMVec2 stPos2, stEMVec2 stPixel2)
{
	float x1 = stPos1.m_fX - (stPixel1.m_fX/2);
	float x2 = stPos2.m_fX - (stPixel2.m_fX/2);
	float y1 = stPos1.m_fY - (stPixel1.m_fY/2);
	float y2 = stPos2.m_fY - (stPixel2.m_fY/2);
	float w = 0;
	float h = 0;

	if(x1 <= x2)
	{
		w = stPixel1.m_fX;
	}
	else
	{
		w = stPixel2.m_fX;
	}
	
	if(y1 <= y2)
	{
		h = stPixel1.m_fY;
	}
	else
	{
		h = stPixel2.m_fY;
	}

	if(CEMMath::Abs<float>(x1-x2) <= w && CEMMath::Abs<float>(y1-y2) <= h)
		return true;
	else
		return false;
}