#include "stdafx.h"

void CPartMap::Init(CRootScene* pThisScene,int nIndex, CHero* CTargetHero)
{
	char strFilePath[256];
	m_pThisScene = pThisScene;
	m_nIndex = nIndex;
	sprintf(strFilePath,"Data/Map/Map_Max_%d.txt",nIndex);
	FILE* fp1 = fopen(strFilePath,"rt");
	sprintf(strFilePath,"Data/Map/Map_Tile_%d.txt",nIndex);
	FILE* fp2 = fopen(strFilePath,"rt");
	sprintf(strFilePath,"Data/Map/Map_Bloking_%d.txt",nIndex);
	FILE* fp3 = fopen(strFilePath,"rt");
	sprintf(strFilePath,"Data/Map/Map_Portal_%d.txt",nIndex);
	FILE* fp4 = fopen(strFilePath,"rt");
	sprintf(strFilePath,"Data/Map/Map_NPC_%d.txt",nIndex);
	FILE* fp5 = fopen(strFilePath,"rt");


	fscanf(fp1,"%d %d",&m_nWidth,&m_nHeight);
	
	m_aTileMap = new stTileMap*[m_nHeight];
	for(int i=0; i<m_nHeight; i++)
	{
		m_aTileMap[i] = new stTileMap[m_nWidth];
	}

	for(int i=0; i<m_nHeight; i++)
	{
		for(int j=0; j<m_nWidth; j++)
		{
			m_aTileMap[i][j].m_nTileMap = fgetc(fp2) - '0';


			switch(m_aTileMap[i][j].m_nTileMap)
			{
				case 1:
					m_aTileMap[i][j].m_pTileMap = new CEMPlane();
					m_aTileMap[i][j].m_pTileMap->SetTexture(pThisScene, "Data/Image/Map/Tile/Tile_1.png",GL_REPEAT,GL_LINEAR,true);
					m_aTileMap[i][j].m_pTileMap->SetSize(1.00f,1.00f);
					m_aTileMap[i][j].m_pTileMap->SetPos(0.0f + (double)(D_TILE_WIDTH * j), 0.0f - (double)(D_TILE_HEIGHT * i));
					m_aTileMap[i][j].m_pTileMap->SetBlend(true);
					//m_aTileMap[i][j].m_pTileMap->SetOrtho2D(true);
					m_aTileMap[i][j].m_pTileMap->SetColor(1.0f,1.0f,1.0f,D_TILE_ALPHA);
					//m_aTileMap[i][j].m_pTileMap->SetFrustumShow(false);
					//m_aTileMap[i][j].m_pTileMap->SetBackFaceCulling(false);
					m_aTileMap[i][j].m_pTileMap->SetFrustumCulling(true);
					pThisScene->Commit(100,(i*m_nWidth)+j,"Tile", m_aTileMap[i][j].m_pTileMap);
				break;
				case 2:
					m_aTileMap[i][j].m_pTileMap = new CEMPlane();
					m_aTileMap[i][j].m_pTileMap->SetTexture(pThisScene, "Data/Image/Map/Tile/Tile_2.png",GL_REPEAT,GL_LINEAR,true);
					m_aTileMap[i][j].m_pTileMap->SetSize(1.00f,1.00f);
					m_aTileMap[i][j].m_pTileMap->SetPos(0.0f + (double)(D_TILE_WIDTH * j), 0.0f - (double)(D_TILE_HEIGHT * i));
					m_aTileMap[i][j].m_pTileMap->SetBlend(true);
					//m_aTileMap[i][j].m_pTileMap->SetOrtho2D(true);
					//!<m_aTileMap[i][j].m_pTileMap->SetColor(1.0f,0.0f,0.0f,D_TILE_ALPHA);
					//m_aTileMap[i][j].m_pTileMap->SetFrustumShow(false);
					//m_aTileMap[i][j].m_pTileMap->SetBackFaceCulling(false);
					m_aTileMap[i][j].m_pTileMap->SetFrustumCulling(true);
					pThisScene->Commit(100,(i*m_nWidth)+j,"Tile", m_aTileMap[i][j].m_pTileMap);
				break;
				case 3:
					m_aTileMap[i][j].m_pTileMap = new CEMPlane();
					m_aTileMap[i][j].m_pTileMap->SetTexture(pThisScene, "Data/Image/Map/Tile/Tile_2.png",GL_REPEAT,GL_LINEAR,true);
					m_aTileMap[i][j].m_pTileMap->SetSize(1.00f,1.00f);
					m_aTileMap[i][j].m_pTileMap->SetPos(0.0f + (double)(D_TILE_WIDTH * j), 0.0f - (double)(D_TILE_HEIGHT * i));
					m_aTileMap[i][j].m_pTileMap->SetBlend(true);
					//m_aTileMap[i][j].m_pTileMap->SetOrtho2D(true);
					//m_aTileMap[i][j].m_pTileMap->SetColor(0.0f,1.0f,0.4f,D_TILE_ALPHA);
					//m_aTileMap[i][j].m_pTileMap->SetFrustumShow(false);
					//m_aTileMap[i][j].m_pTileMap->SetBackFaceCulling(false);
					m_aTileMap[i][j].m_pTileMap->SetFrustumCulling(true);
					pThisScene->Commit(100,(i*m_nWidth)+j,"Tile", m_aTileMap[i][j].m_pTileMap);
					//pThisScene->Commit
				break;
				case 4:
					m_aTileMap[i][j].m_pTileMap = new CEMPlane();
					m_aTileMap[i][j].m_pTileMap->SetTexture(pThisScene, "Data/Image/Map/Tile/Tile_2.png",GL_REPEAT,GL_LINEAR,true);
					m_aTileMap[i][j].m_pTileMap->SetSize(1.00f,1.00f);
					m_aTileMap[i][j].m_pTileMap->SetPos(0.0f + (double)(D_TILE_WIDTH * j), 0.0f - (double)(D_TILE_HEIGHT * i));
					m_aTileMap[i][j].m_pTileMap->SetBlend(true);
					//m_aTileMap[i][j].m_pTileMap->SetOrtho2D(true);
					//m_aTileMap[i][j].m_pTileMap->SetColor(0.6f,0.3f,0.4f,D_TILE_ALPHA);
					//m_aTileMap[i][j].m_pTileMap->SetFrustumShow(false);
					//m_aTileMap[i][j].m_pTileMap->SetBackFaceCulling(false);
					m_aTileMap[i][j].m_pTileMap->SetFrustumCulling(true);
					pThisScene->Commit(100,(i*m_nWidth)+j,"Tile", m_aTileMap[i][j].m_pTileMap);
					//pThisScene->Commit
				break;
			}
		}
		fgetc(fp2);
	}
	for(int i=0; i<m_nHeight; i++)
	{
		for(int j=0; j<m_nWidth; j++)
		{
			m_aTileMap[i][j].m_nTileMap = fgetc(fp3) - '0';
			if(m_aTileMap[i][j].m_nTileMap == 1)
			{
				CBlokingBlock* nTemp = new CBlokingBlock(stEMVec2(0.0f + (double)(D_TILE_WIDTH * j), 0.0f - (double)(D_TILE_HEIGHT * i)));
				m_BlokingMap.push_back(nTemp);
			}
		}
		fgetc(fp3);
	}
	
	while(feof(fp4) == 0)
	{
		stEMVec2 stTempPos;
		stEMVec2 stTempHeroPos;
		int		nNextMapIndex = -1;
		fscanf(fp4,"%f %f %d %f %f",&stTempPos.m_fX,&stTempPos.m_fY,&nNextMapIndex,&stTempHeroPos.m_fX,&stTempHeroPos.m_fY);
		
		if( nNextMapIndex != -1)
		{
			CPortal* pPortal = new CPortal(stTempPos,nNextMapIndex,stTempHeroPos);
			pPortal->Init(m_pThisScene);
			m_PortalMap.push_back(pPortal);
		}
	}

	while(feof(fp5) == 0)
	{
		stEMVec2 stTempPos;
		int nIndex;
		fscanf(fp5,"%d %f %f",&nIndex, &stTempPos.m_fX,&stTempPos.m_fY);
		char strTemp[256];
		sprintf(strTemp,"Data/Image/NPC/%d.png",nIndex);
		CNPC* pNPC = new CNPC();
		pNPC->Init(pThisScene,nIndex,"NPC",strTemp,-2,stTempPos);
		//pNPC->m_pPlane->SetSize(0.35f,0.35f);
		pNPC->getPlane()->SetSize(0.25f,0.25f);
		m_NPCMap.push_back(pNPC);
	}


	/*CTargetHero->setPos(stEMVec2(0.0f + (double)(D_TILE_WIDTH * j), 0.0f - (double)(D_TILE_HEIGHT * i))); 
	g_stCamPos_Stage.m_fX = CTargetHero->getPos().m_fX;
	if(g_stCamPos_Stage.m_fX <= D_SCREEN_WIDTH/2)
		g_stCamPos_Stage.m_fX = D_SCREEN_WIDTH/2;
	else if(g_stCamPos_Stage.m_fX >= (getMapWidth() * D_TILE_WIDTH) - (D_SCREEN_WIDTH/2) - D_TILE_WIDTH)
		g_stCamPos_Stage.m_fX = (getMapWidth() * D_TILE_WIDTH) - (D_SCREEN_WIDTH/2) - D_TILE_WIDTH;

	g_stCamPos_Stage.m_fY = CTargetHero->getPos().m_fY;
	if(g_stCamPos_Stage.m_fY >= -(D_SCREEN_HEIGHT/2))
		g_stCamPos_Stage.m_fY = -(D_SCREEN_HEIGHT/2);
	else if(g_stCamPos_Stage.m_fY <= -(getMapHeight() * D_TILE_HEIGHT) + (D_SCREEN_HEIGHT/2) + D_TILE_WIDTH)
		g_stCamPos_Stage.m_fY = -(getMapHeight() * D_TILE_HEIGHT) + (D_SCREEN_HEIGHT/2) + D_TILE_WIDTH;


	g_stSmoothCamPos_Stage = g_stCamPos_Stage;
	*/
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	fclose(fp4);
	fclose(fp5);

	if(m_nIndex == 3)
	{
		D_SOUNDMNG->Play("BGM_2",false,0.55f);
	}

	/*if(m_nIndex == 1)
	{
		CObject* pObject = new CObject();
		pObject->Init(m_pThisScene,stEMVec2(50.0f,-450.0f),0,1);
		m_ObjectList.push_back(pObject);
		
		CObject* pObject2 = new CObject();
		pObject2->Init(m_pThisScene,stEMVec2(150.0f,-450.0f),0,1);
		m_ObjectList.push_back(pObject2);


		CObject* pObject3 = new CObject();
		pObject3->Init(m_pThisScene,stEMVec2(150.0f,-600.0f),1,1);
		m_ObjectList.push_back(pObject3);
		
		CObject* pObject4 = new CObject();
		pObject4->Init(m_pThisScene,stEMVec2(350.0f,-580.0f),2,1);
		m_ObjectList.push_back(pObject4);

	}
	if(m_nIndex == 3)
	{
		CObject* pObject9 = new CObject();
		pObject9->Init(m_pThisScene,stEMVec2(550.0f,-500.0f),3,1);
		m_ObjectList.push_back(pObject9);
	}*/
		
	if(m_nIndex == 2 && g_nQuestLevel == 3)
	{
		g_nEventLevel = 0;
		g_CChatWindow.ChatStart(-1);
	}
}
void CPartMap::Update(float dt)
{
	if(m_nIndex == 3 && g_nQuestLevel == 4)
	{
		if(g_CHero.getPos().m_fX >= 400.0f)
		{
			g_nQuestLevel++;
			g_nEventLevel = 0;
			g_CChatWindow.ChatStart(-1);
		}
	}
}
void CPartMap::Exit()
{
	D_SOUNDMNG->Play("Portal",false,1.5f);
	if(m_nIndex == 2)
	{
		D_SOUNDMNG->Stop("BGM_1");
	}
	else if(m_nIndex == 3)
	{
		D_SOUNDMNG->Stop("BGM_2");
	}
	for(int i=0; i<m_nHeight; i++)
	{
		for(int j=0; j<m_nWidth; j++)
		{
			m_pThisScene->DeletePlane(m_aTileMap[i][j].m_pTileMap);
			//delete m_aTileMap[i][j].m_pTileMap;
		}
	}
	for(int i=0; i<m_nHeight; i++)
		delete [] m_aTileMap[i];
    delete [] m_aTileMap;

	list<CBlokingBlock*>::iterator it;
	for(it = m_BlokingMap.begin(); it != m_BlokingMap.end(); it++)
	{
		delete (*it);
	}
	m_BlokingMap.clear();

	list<CPortal*>::iterator itr;
	for(itr = m_PortalMap.begin(); itr != m_PortalMap.end(); itr++)
	{
		m_pThisScene->DeleteAnimation((*itr)->m_pPlane);
		delete (*itr);
		//!< 윗줄에서 삭제 delete (*itr);
	}
	m_PortalMap.clear();

	
	list<CNPC*>::iterator itr2;
	for(itr2 = m_NPCMap.begin(); itr2 != m_NPCMap.end(); itr2++)
	{
		m_pThisScene->DeletePlane((*itr2)->getPlane());
		delete (*itr2);
		//!< 윗줄에서 삭제 delete (*itr);
	}
	m_NPCMap.clear();

	list<CObject*>::iterator itr3;
	for(itr3 = m_ObjectList.begin(); itr3 != m_ObjectList.end(); itr3++)
	{
		m_pThisScene->DeletePlane((*itr3)->m_pPlane);
		delete (*itr3);
		//!< 윗줄에서 삭제 delete (*itr);
	}
	m_ObjectList.clear();
}

void CPartMap::Exit_End()
{
	for(int i=0; i<m_nHeight; i++)
		delete [] m_aTileMap[i];
    delete [] m_aTileMap;


	list<CBlokingBlock*>::iterator it;
	for(it = m_BlokingMap.begin(); it != m_BlokingMap.end(); it++)
	{
		delete (*it);
	}
	m_BlokingMap.clear();

	
	list<CPortal*>::iterator itr;
	for(itr = m_PortalMap.begin(); itr != m_PortalMap.end(); itr++)
	{
		m_pThisScene->DeleteAnimation((*itr)->m_pPlane);
		delete (*itr);
		//!< 윗줄에서 삭제 delete (*itr);
	}
	m_PortalMap.clear();

	
	list<CNPC*>::iterator itr2;
	for(itr2 = m_NPCMap.begin(); itr2 != m_NPCMap.end(); itr2++)
	{
		m_pThisScene->DeletePlane((*itr2)->getPlane());
		delete (*itr2);
		//!< 윗줄에서 삭제 delete (*itr);
	}
	m_NPCMap.clear();
	
	list<CObject*>::iterator itr3;
	for(itr3 = m_ObjectList.begin(); itr3 != m_ObjectList.end(); itr3++)
	{
		m_pThisScene->DeletePlane((*itr3)->m_pPlane);
		delete (*itr3);
		//!< 윗줄에서 삭제 delete (*itr);
	}
	m_ObjectList.clear();
}

int CPartMap::getMapWidth()
{
	return m_nWidth;
}
int CPartMap::getMapHeight()
{
	return m_nHeight;
}

int CPartMap::getIndex()
{
	return m_nIndex;
}