#include "stdafx.h"


void CHero::Init(CRootScene* pThisScene,CChatWindow* pChatWindow, string strPlaneName, string strFileName,int nLayer, stEMVec2 stPos)
{
	m_bMapChangeAble = true;
	m_pChatWindow = pChatWindow;
	m_stPos = stPos;
	//CUnit::Init(pThisScene,strPlaneName,strFileName,nLayer,stPos);
	//!< 아래에 초기화 추가 구문을 작성합니다.
	m_fMoveSpeed = 170.0f;
	m_nNPCIndex = 0;

	

	m_pFlash = new CEMPlane();
	m_pFlash->SetTexture(pThisScene,"Data/Image/Flash.png");
	m_pFlash->SetSize(2.3f,2.3f);
	m_pFlash->SetPos(stPos);
	m_pFlash->SetBlend(true);
	//pThisScene->Commit(-200,"Flash", m_pFlash);

	for(int i=0; i<E_Derection_Max; i++)
	{
		m_pHero[i] = new CEMAnimation(4);
		m_pHero[i]->SetPos(m_stPos);
		m_pHero[i]->SetSize(1.0f,1.0f);
		m_pHero[i]->SetBlend(true);
		m_pHero[i]->SetTime(0.2f);
		if(i == (int)E_Derection_Left)
			m_pHero[i]->SetTexture(pThisScene,4,"Data/Image/Hero/Hero_Left_1.png","Data/Image/Hero/Hero_Left_2.png","Data/Image/Hero/Hero_Left_3.png","Data/Image/Hero/Hero_Left_4.png");
		if(i == (int)E_Derection_Right)
			m_pHero[i]->SetTexture(pThisScene,4,"Data/Image/Hero/Hero_Right_1.png","Data/Image/Hero/Hero_Right_2.png","Data/Image/Hero/Hero_Right_3.png","Data/Image/Hero/Hero_Right_4.png");
		if(i == (int)E_Derection_Up)
			m_pHero[i]->SetTexture(pThisScene,4,"Data/Image/Hero/Hero_Up_1.png","Data/Image/Hero/Hero_Up_2.png","Data/Image/Hero/Hero_Up_3.png","Data/Image/Hero/Hero_Up_4.png");
		if(i == (int)E_Derection_Down)
			m_pHero[i]->SetTexture(pThisScene,4,"Data/Image/Hero/Hero_Down_1.png","Data/Image/Hero/Hero_Down_2.png","Data/Image/Hero/Hero_Down_3.png","Data/Image/Hero/Hero_Down_4.png");

		
		pThisScene->Commit(nLayer,i,"HeroAni", m_pHero[i]);
	}

	m_eDerection = E_Derection_Right;
}

void CHero::Update(float dt, CMapManager* MapManager, CInventory* Inventory)
{
	MoveUpdate(dt, MapManager, Inventory);
	m_pFlash->SetPos(m_stPos);
	for(int i=0; i<E_Derection_Max; i++)
	{
		m_pHero[i]->SetPos(m_stPos);
	}
	
	ShowUpdate();
	//!< 위에 업데이트 추가 구문을 작성합니다.
	//CUnit::Update(dt);
}
void CHero::Exit()
{
	//CUnit::Exit();
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
void CHero::MoveUpdate(float dt, CMapManager* MapManager, CInventory* Inventory)
{

	for(int i=0; i<E_Derection_Max; i++)
	{
		m_bKeyDown[i] = false;
		m_bHitTest[i] = false;
	}
	
	m_bNPCHit = false;
	
	if(g_bChating == false && g_bPause == false)
	{
		if(GetKeyState(VK_LEFT) & 0x8000)
		{
			m_eDerection = E_Derection_Left;
			m_pHero[m_eDerection]->SetPause(false);
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
			m_eDerection = E_Derection_Right;
			m_pHero[m_eDerection]->SetPause(false);
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
		else if(GetKeyState(VK_UP) & 0x8000) //!< else 해제시 대각선 이동가능
		{
			m_eDerection = E_Derection_Up;
			m_pHero[m_eDerection]->SetPause(false);
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
			m_eDerection = E_Derection_Down;
			m_pHero[m_eDerection]->SetPause(false);
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

	list<CObject*>::iterator it2;
	for(it2 = MapManager->getCurMap()->m_ObjectList.begin(); it2 != MapManager->getCurMap()->m_ObjectList.end(); )
	{
		stEMVec2 stTemp1 = m_stPos;
		stTemp1.m_fX = stTemp1.m_fX;//  //
		stTemp1.m_fY = stTemp1.m_fY; //
			
		
		stEMVec2 stTemp2 = (*it2)->m_stPos;
		stTemp2.m_fX = stTemp2.m_fX;//  //
		stTemp2.m_fY = stTemp2.m_fY; //

		if( HitTest(stTemp1, stEMVec2(D_HERO_WIDTH,D_HERO_HEIGHT), stTemp2,stEMVec2(D_TILE_WIDTH,D_TILE_HEIGHT))  == true )
		{
			(*it2)->CreateItem(Inventory);
			

			MapManager->m_pThisScene->DeletePlane((*it2)->m_pPlane);
			delete (*it2);
			it2 = MapManager->getCurMap()->m_ObjectList.erase(it2);
		}
		else
		{
			it2++;
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
	int j=0;
	for(i=0; i<E_Derection_Max; i++)
	{
		if(m_bHitTest[i] == true)
		{
			m_pHero[m_eDerection]->SetColor(0.0f,0.0f,0.0f,0.5f);
			break;
		}
	}
	for(j=0; j<E_Derection_Max; j++)
	{
		if(m_bKeyDown[j] == true)
		{
			break;
		}
	}
	if(j == E_Derection_Max)
	{
		for(int k=0; k<E_Derection_Max; k++)
		{
			m_pHero[k]->SetPause(true);
			m_pHero[k]->SetLoopType(E_ANI_LOOP,0);
		}
	}
	if(i == E_Derection_Max)
	{
		m_pHero[m_eDerection]->SetColor(1.0f,1.0f,1.0f,1.0f);
	}

	if(m_bNPCHit == true)
	{
		m_pHero[m_eDerection]->SetColor(1.0f,0.2f,0.2f,0.5f);
		
		if(GetKeyState(VK_RETURN) & 0x8000)
		{
			if(g_bChating == false && g_bChating == false)
			{
				if(g_CMapManager.m_bNowChange == false)
					m_pChatWindow->ChatSelect(m_nNPCIndex);

				//m_pChatWindow->ChatStart(m_nNPCIndex);
			}
		}
	}

 }
 void CHero::ShowUpdate()
 {
	 for(int i=0; i<E_Derection_Max; i++)
	{
		m_pHero[i]->SetShow(false);
	}
	 m_pHero[m_eDerection]->SetShow(true);
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
void CHero::MoveX(float fX)
{
	m_stPos.m_fX += fX;
}
void CHero::MoveY(float fY)
{
	m_stPos.m_fY += fY;
}
stEMVec2 CHero::getPos()
{
	return m_stPos;
}

void CHero::setPos(stEMVec2 stPos)
{
	m_stPos = stPos;
}