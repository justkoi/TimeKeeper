#include "stdafx.h"
unsigned int nTileIndex = 0;


void CMapTools::TabTile()
{
	char strTemp[256];
	string strFilePath;
	if(m_eEditMod == E_EDIT_MOD_TILE)
	{
		m_nNowSelectTile++;
		if(m_nNowSelectTile > D_MAX_TILE)
		{
			m_nNowSelectTile = 1;
		}

		sprintf(strTemp,"Data/Image/Map/Tile/Tile_%d.png",m_nNowSelectTile);
		strFilePath = strTemp;
		m_pNowSelectTile->SetTexture(m_pThisScene, strFilePath );
	}
	else if(m_eEditMod == E_EDIT_MOD_NPC)
	{
		int i = 0;

		for(i=0; i<D_MAX_NPC; i++)
		{
			if( m_bNPCPlaceAble[i] == true)
				break;
		}
		if( i >= D_MAX_NPC)
		{
			return;
		}

		m_nNowSelectNPC++;
		if(m_nNowSelectNPC > D_MAX_NPC)
		{
			m_nNowSelectNPC = 1;
		}

		while(m_bNPCPlaceAble[m_nNowSelectNPC-1] == false)
		{
			m_nNowSelectNPC++;
			if(m_nNowSelectNPC > D_MAX_NPC)
			{
				m_nNowSelectNPC = 1;
			}
		}
		

		sprintf(strTemp,"Data/Man/%d.png",m_nNowSelectNPC);
		strFilePath = strTemp;
		m_pNowSelectNPC->SetTexture(m_pThisScene, strFilePath );
	}
}
void CMapTools::SelectTile(int nIndex)
{
	char strTemp[256];
	m_nNowSelectTile = nIndex;

	sprintf(strTemp,"Data/Image/Map/Tile/Tile_%d.png",m_nNowSelectTile);
	string strFilePath = strTemp;
	m_pNowSelectTile->SetTexture(m_pThisScene, strFilePath );

}
void CMapTools::Init(CRootScene* pThisScene)
{
	for(int i=0; i<D_MAX_NPC; i++)
	{
		m_bNPCPlaceAble[i] = true;
	}

	m_nNumberFocus = 1; //!< 1인덱스 2가로길이 3세로길이
	
	char strTemp[256];
	m_pThisScene = pThisScene;

	m_nIndex = 1;

	m_nWidth = 30;
	m_nHeight = 30;
	
	m_eEditMod = E_EDIT_MOD_NPC;
	nTileIndex = 0;

	m_nNowSelectTile = 2;
	m_nNowSelectNPC = 1;

	m_fMoveSpeed = 400.0f;


	m_pTextMsg = new CEMText("으뜸체","현재 선택된 타일");
	m_pTextMsg->SetSize(1.0f,1.0f);
	m_pTextMsg->SetColor(1.0f,1.0f,1.0f);
	m_pTextMsg->SetPos(10.0f,60.0f);
	m_pThisScene->Commit(-999,"TextMsg",m_pTextMsg);

	

	m_pTextMsg2 = new CEMText("으뜸체","Press Tab");
	m_pTextMsg2->SetSize(0.7f,0.7f);
	m_pTextMsg2->SetColor(1.0f,1.0f,1.0f);
	m_pTextMsg2->SetPos(90.0f,130.0f);
	m_pThisScene->Commit(-999,"TextMsg2",m_pTextMsg2);


	m_pTextIndex = new CEMText("으뜸체","");
	m_pTextIndex->SetSize(1.0f,1.0f);
	m_pTextIndex->SetColor(1.0f,1.0f,1.0f);
	m_pTextIndex->SetPos(30.0f,30.0f);
	m_pThisScene->Commit(-999,"TextIndex",m_pTextIndex);


	m_pTextWidth = new CEMText("으뜸체","");
	m_pTextWidth->SetSize(1.0f,1.0f);
	m_pTextWidth->SetColor(1.0f,1.0f,1.0f);
	m_pTextWidth->SetPos(60.0f,30.0f);
	m_pThisScene->Commit(-999,"TextWidth",m_pTextWidth);

	m_pTextHeight = new CEMText("으뜸체","");
	m_pTextHeight->SetSize(1.0f,1.0f);
	m_pTextHeight->SetColor(1.0f,1.0f,1.0f);
	m_pTextHeight->SetPos(100.0f,30.0f);
	m_pThisScene->Commit(-999,"TextHeight",m_pTextHeight);

	m_aTileMap = new stTileMap*[m_nHeight];
	for(int i=0; i<m_nHeight; i++)
	{
		m_aTileMap[i] = new stTileMap[m_nWidth];
	}
	for(int i=0; i<m_nHeight; i++)
	{
		for(int j=0; j<m_nWidth; j++)
		{
			m_aTileMap[i][j].m_nTileMap = 1;
			sprintf(strTemp,"Data/Image/Map/Tile/Tile_%d.png",m_aTileMap[i][j].m_nTileMap);
			string strFilePath = strTemp;

			m_aTileMap[i][j].m_pTileMap = new CEMPlane();
			m_aTileMap[i][j].m_pTileMap->SetTexture(m_pThisScene, strFilePath ,GL_REPEAT,GL_LINEAR,true);
			m_aTileMap[i][j].m_pTileMap->SetSize(1.00f,1.00f);
			m_aTileMap[i][j].m_pTileMap->SetPos(D_TOOLS_OFFSET_X + 0.0f + (double)(D_TILE_WIDTH * j), D_TOOLS_OFFSET_Y + 0.0f - (double)(D_TILE_HEIGHT * i));
			m_aTileMap[i][j].m_pTileMap->SetBlend(true);
			m_aTileMap[i][j].m_pTileMap->SetColor(1.0f,1.0f,1.0f,D_TILE_ALPHA);
			m_aTileMap[i][j].m_pTileMap->SetFrustumCulling(true);
			m_pThisScene->Commit(100,nTileIndex++,"Tile", m_aTileMap[i][j].m_pTileMap);
		}
	}
	m_bNowDrag = false;

	sprintf(strTemp,"Data/Image/Map/Tile/Tile_%d.png",m_nNowSelectTile);
	string strFilePath2 = strTemp;

	m_pNowSelectTile = new CEMPlane();
	m_pNowSelectTile->SetTexture(m_pThisScene, strFilePath2 );
	m_pNowSelectTile->SetSize(1.00f,1.00f);
	m_pNowSelectTile->SetPos(50.0f,100.0f);
	m_pNowSelectTile->SetBlend(true);
	m_pNowSelectTile->SetColor(1.0f,1.0f,1.0f);
	m_pNowSelectTile->SetFrustumCulling(true);
	m_pNowSelectTile->SetOrtho2D(true);
	m_pThisScene->Commit(-999,"NowSelectTile", m_pNowSelectTile);
	
	sprintf(strTemp,"Data/Man/%d.png",m_nNowSelectNPC);
	strFilePath2 = strTemp;

	m_pNowSelectNPC = new CEMPlane();
	m_pNowSelectNPC->SetTexture(m_pThisScene, strFilePath2 );
	m_pNowSelectNPC->SetSize(0.3f,0.3f);
	m_pNowSelectNPC->SetPos(50.0f,100.0f);
	m_pNowSelectNPC->SetBlend(true);
	m_pNowSelectNPC->SetColor(1.0f,1.0f,1.0f);
	m_pNowSelectNPC->SetFrustumCulling(true);
	m_pNowSelectNPC->SetOrtho2D(true);
	m_pThisScene->Commit(-999,"NowSelectNPC", m_pNowSelectNPC);


	m_pInterface = new CEMPlane();
	m_pInterface->SetTexture(m_pThisScene, "Data/Image/Interface_1.png" );
	m_pInterface->SetSize(1.00f,1.00f);
	m_pInterface->SetPos(-60.0f,325.0f);
	m_pInterface->SetBlend(true);
	m_pInterface->SetColor(1.0f,1.0f,1.0f);
	m_pInterface->SetFrustumCulling(true);
	m_pInterface->SetOrtho2D(true);
	m_pThisScene->Commit(-998,"Interface", m_pInterface);
}

void CMapTools::Update(float dt)
{
	m_pTextIndex->SetOutPutString(IntToEMString(m_nIndex));
	m_pTextWidth->SetOutPutString(IntToEMString(m_nWidth));
	m_pTextHeight->SetOutPutString(IntToEMString(m_nHeight));
	m_pNowSelectTile->SetShow(false);
	m_pNowSelectNPC->SetShow(false);
	

	if(m_eEditMod == E_EDIT_MOD_TILE)
	{
		m_pNowSelectTile->SetShow(true);
	}
	else if(m_eEditMod == E_EDIT_MOD_NPC)
	{
		m_pNowSelectNPC->SetShow(true);
		int i = 0;
		for(i=0; i<D_MAX_NPC; i++)
		{
			if( m_bNPCPlaceAble[i] == true)
				break;
		}
		if( i >= D_MAX_NPC)
		{
			m_pNowSelectNPC->SetShow(false);
		}
	}
	if(GetKeyState(VK_LEFT) & 0x8000)
	{
		g_stSmoothCamPos_Stage.m_fX -= (m_fMoveSpeed * dt);
	}
	else if(GetKeyState(VK_RIGHT) & 0x8000)
	{
		g_stSmoothCamPos_Stage.m_fX += (m_fMoveSpeed * dt);
	}
	if(GetKeyState(VK_UP) & 0x8000)
	{
		g_stSmoothCamPos_Stage.m_fY += (m_fMoveSpeed * dt);
	}
	else if(GetKeyState(VK_DOWN) & 0x8000)
	{
		g_stSmoothCamPos_Stage.m_fY -= (m_fMoveSpeed * dt);
	}

	if(g_stSmoothCamPos_Stage.m_fX <= -D_TOOLS_OFFSET_X + (D_SCREEN_WIDTH/2))
		g_stSmoothCamPos_Stage.m_fX = -D_TOOLS_OFFSET_X + (D_SCREEN_WIDTH/2);
	else if(g_stSmoothCamPos_Stage.m_fX >= D_TOOLS_OFFSET_X + (m_nWidth * D_TILE_WIDTH) - (D_SCREEN_WIDTH/2) - D_TILE_WIDTH)
		g_stSmoothCamPos_Stage.m_fX = D_TOOLS_OFFSET_X + (m_nWidth* D_TILE_WIDTH) - (D_SCREEN_WIDTH/2) - D_TILE_WIDTH;

	if(g_stSmoothCamPos_Stage.m_fY >= D_TOOLS_OFFSET_Y-(D_SCREEN_HEIGHT/2))
		g_stSmoothCamPos_Stage.m_fY = D_TOOLS_OFFSET_Y-(D_SCREEN_HEIGHT/2);
	else if(g_stSmoothCamPos_Stage.m_fY <= D_TOOLS_OFFSET_Y-(m_nHeight * D_TILE_HEIGHT) + (D_SCREEN_HEIGHT/2) + D_TILE_WIDTH)
	g_stSmoothCamPos_Stage.m_fY = D_TOOLS_OFFSET_Y-(m_nHeight * D_TILE_HEIGHT) + (D_SCREEN_HEIGHT/2) + D_TILE_WIDTH;

}
void CMapTools::CheckDown(stEMVec2 stPos)
{
	if(m_eEditMod == E_EDIT_MOD_TILE)
	{
		m_bNowDrag = true;
		char strTemp[256];
	

		for(int i=0; i<m_nHeight; i++)
		{
			for(int j=0; j<m_nWidth; j++)
			{
				if( stPos.m_fX >= m_aTileMap[i][j].m_pTileMap->GetPosVec2().m_fX - (D_TILE_WIDTH/2) &&
					stPos.m_fX <= m_aTileMap[i][j].m_pTileMap->GetPosVec2().m_fX + (D_TILE_WIDTH/2) &&
					stPos.m_fY <= m_aTileMap[i][j].m_pTileMap->GetPosVec2().m_fY + (D_TILE_WIDTH/2) &&
					stPos.m_fY >= m_aTileMap[i][j].m_pTileMap->GetPosVec2().m_fY - (D_TILE_WIDTH/2) )
				{
					if(m_aTileMap[i][j].m_nTileMap != m_nNowSelectTile)
					{
						m_aTileMap[i][j].m_nTileMap = m_nNowSelectTile;
						sprintf(strTemp,"Data/Image/Map/Tile/Tile_%d.png",m_nNowSelectTile);
						string strFilePath = strTemp;
						m_aTileMap[i][j].m_pTileMap->SetTexture(m_pThisScene, strFilePath,GL_REPEAT,GL_LINEAR,true);
					}
				}
			}
		}
	}
	else if(m_eEditMod == E_EDIT_MOD_NPC)
	{
		int i = 0;

		for(i=0; i<D_MAX_NPC; i++)
		{
			if( m_bNPCPlaceAble[i] == true)
				break;
		}
		if( i >= D_MAX_NPC)
		{
			return;
		}

		stNPC* pNPC = new stNPC();
		pNPC->m_nIndex = m_nNowSelectNPC;
		pNPC->m_stPos = stPos;
		pNPC->m_pNPC = new CEMPlane();

		char strTemp[256];
		sprintf(strTemp,"Data/Man/%d.png",m_nNowSelectNPC);
		string strFilePath = strTemp;

		pNPC->m_pNPC = new CEMPlane();
		pNPC->m_pNPC->SetTexture(m_pThisScene, strFilePath );
		pNPC->m_pNPC->SetSize(0.25f,0.25f);
		pNPC->m_pNPC->SetPos(pNPC->m_stPos);
		pNPC->m_pNPC->SetBlend(true);
		pNPC->m_pNPC->SetColor(1.0f,1.0f,1.0f);
		pNPC->m_pNPC->SetFrustumCulling(true);
		m_pThisScene->Commit(-999,m_nNowSelectNPC,"NPC", pNPC->m_pNPC);
		m_bNPCPlaceAble[m_nNowSelectNPC-1] = false;
		m_nNowSelectNPC++;
		if(m_nNowSelectNPC > D_MAX_NPC)
		{
			m_nNowSelectNPC = 1;
		}

		sprintf(strTemp,"Data/Man/%d.png",m_nNowSelectNPC);
		strFilePath = strTemp;
		m_pNowSelectNPC->SetTexture(m_pThisScene, strFilePath );

		m_NPCList.push_back(pNPC);
	}
}

void CMapTools::CheckMove(stEMVec2 stPos)
{
	if(m_eEditMod == E_EDIT_MOD_TILE)
	{
		if(m_bNowDrag == false)
			return;
		char strTemp[256];
	

		for(int i=0; i<m_nHeight; i++)
		{
			for(int j=0; j<m_nWidth; j++)
			{
				if( stPos.m_fX >= m_aTileMap[i][j].m_pTileMap->GetPosVec2().m_fX - (D_TILE_WIDTH/2) &&
					stPos.m_fX <= m_aTileMap[i][j].m_pTileMap->GetPosVec2().m_fX + (D_TILE_WIDTH/2) &&
					stPos.m_fY <= m_aTileMap[i][j].m_pTileMap->GetPosVec2().m_fY + (D_TILE_WIDTH/2) &&
					stPos.m_fY >= m_aTileMap[i][j].m_pTileMap->GetPosVec2().m_fY - (D_TILE_WIDTH/2) )
				{
					if(m_aTileMap[i][j].m_nTileMap != m_nNowSelectTile)
					{
						m_aTileMap[i][j].m_nTileMap = m_nNowSelectTile;
						sprintf(strTemp,"Data/Image/Map/Tile/Tile_%d.png",m_nNowSelectTile);
						string strFilePath = strTemp;
						m_aTileMap[i][j].m_pTileMap->SetTexture(m_pThisScene, strFilePath,GL_REPEAT,GL_LINEAR,true);
					}
				}
			}
		}
	}
}

void CMapTools::CheckUp(stEMVec2 stPos)
{
	if(m_eEditMod == E_EDIT_MOD_TILE)
	{
		m_bNowDrag = false;
	}
}

void CMapTools::SaveData()
{
	char strFilePath[256];
	int i = 0;
	sprintf(strFilePath,"Data/Map/Map_Max_%d.txt",m_nIndex);
	FILE* fp1 = fopen(strFilePath,"wt");
	sprintf(strFilePath,"Data/Map/Map_Tile_%d.txt",m_nIndex);
	FILE* fp2 = fopen(strFilePath,"wt");
	sprintf(strFilePath,"Data/Map/Map_Bloking_%d.txt",m_nIndex);
	FILE* fp3 = fopen(strFilePath,"wt");
	sprintf(strFilePath,"Data/Map/Map_Portal_%d.txt",m_nIndex);
	FILE* fp4 = fopen(strFilePath,"wt");
	sprintf(strFilePath,"Data/Map/Map_NPC_%d.txt",m_nIndex);
	FILE* fp5 = fopen(strFilePath,"wt");

	fprintf(fp1,"%d %d",m_nWidth,m_nHeight);
	for(int i=0; i<m_nHeight; i++)
	{
		for(int j=0; j<m_nWidth; j++)
		{
			
			fputc(m_aTileMap[i][j].m_nTileMap + '0',fp2);
			if(m_aTileMap[i][j].m_nTileMap != 1)
			{
				fputc('1',fp3);
			}
			else
			{
				fputc('0',fp3);
			}
		}
		fputc('\n',fp2);
		fputc('\n',fp3);
	}
	list<stNPC*>::iterator it;
	for(it = m_NPCList.begin(); it != m_NPCList.end(); it++, i++)
	{
		if(i != 0)
			fprintf(fp5,"\n");

		fprintf(fp5,"%d %f %f",(*it)->m_nIndex,(*it)->m_stPos.m_fX-D_TOOLS_OFFSET_X,(*it)->m_stPos.m_fY-D_TOOLS_OFFSET_Y);
	}


	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	fclose(fp4);
	fclose(fp5);
}
