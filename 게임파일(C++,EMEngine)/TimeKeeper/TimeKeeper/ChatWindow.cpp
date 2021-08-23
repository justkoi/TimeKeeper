#include "stdafx.h"

int g_nEventLevel = 0; //!< 무슨 행동을 할것인지 결정 증거수집 대화하기 등등
int g_nQuestLevel = 1; //!< 현재 사건의 순서
int g_nChatLevel = 0;
int g_nConditionLevel = 1;//!< 현재 해당되는 조건 레벨
bool g_bChating = false;

void CChatWindow::Init(CRootScene* pThisScene)
{
//	m_stRealPos.m_fX = stPos.m_fX - D_TILE_WIDTH;
//	m_stRealPos.m_fY = stPos.m_fY;
	m_pBlind = new CEMPlane();
	m_pBlind->SetTexture(pThisScene,"Data/Image/Effect/Blind.png");
	m_pBlind->SetSize(1.0f,1.0f);
	m_pBlind->SetPos(512.0f,512.0f);
	m_pBlind->SetBlend(true);
	m_pBlind->SetOrtho2D(true);
	m_pBlind->SetAlpha(0.7f);
	//m_pPlane->SetOrtho2D(true);
	pThisScene->Commit(-997,"ChatWindowBlind", m_pBlind);



	m_pPlane = new CEMPlane();
	m_pPlane->SetTexture(pThisScene,"Data/Image/ChatWindow.png");
	m_pPlane->SetSize(1.0f,1.0f);
	m_pPlane->SetPos(362.0f + 48.0f,460.0f);
	m_pPlane->SetBlend(true);
	m_pPlane->SetOrtho2D(true);
	//m_pPlane->SetOrtho2D(true);
	pThisScene->Commit(-999,"ChatWindow", m_pPlane);

	m_pSelect = new CEMPlane();
	m_pSelect->SetTexture(pThisScene,"Data/Image/ChatSelect.png");
	m_pSelect->SetSize(1.0f,1.0f);
	m_pSelect->SetPos(150.0f, 400.0f);
	m_pSelect->SetBlend(true);
	m_pSelect->SetOrtho2D(true);
	//m_pPlane->SetOrtho2D(true);
	pThisScene->Commit(-1000,"ChatSelect", m_pSelect);

	//
	m_FacePos[E_FACE_KJH_NONE] = stEMVec2(400.0f,260.0f);
	m_pFace[E_FACE_KJH_NONE] = new CEMPlane();
	m_pFace[E_FACE_KJH_NONE]->SetTexture(pThisScene,"Data/Man/0.png");
	m_pFace[E_FACE_KJH_NONE]->SetSize(1.0f,1.0f);
	m_pFace[E_FACE_KJH_NONE]->SetPos(m_FacePos[E_FACE_KJH_NONE]);
	m_pFace[E_FACE_KJH_NONE]->SetBlend(true);
	m_pFace[E_FACE_KJH_NONE]->SetOrtho2D(true);
	//m_pPlane->SetOrtho2D(true);
	pThisScene->Commit(-998,"E_FACE_KJH_NONE", m_pFace[E_FACE_KJH_NONE]);
	m_pFace[E_FACE_KJH_NONE]->SetShow(g_bChating);

	m_FacePos[E_FACE_KJH_WORRY] = stEMVec2(400.0f,260.0f);
	m_pFace[E_FACE_KJH_WORRY] = new CEMPlane();
	m_pFace[E_FACE_KJH_WORRY]->SetTexture(pThisScene,"Data/Man/1.png");
	m_pFace[E_FACE_KJH_WORRY]->SetSize(1.0f,1.0f);
	m_pFace[E_FACE_KJH_WORRY]->SetPos(m_FacePos[E_FACE_KJH_WORRY]);
	m_pFace[E_FACE_KJH_WORRY]->SetBlend(true);
	m_pFace[E_FACE_KJH_WORRY]->SetOrtho2D(true);
	//m_pPlane->SetOrtho2D(true);
	pThisScene->Commit(-998,"E_FACE_KJH_WORRY", m_pFace[E_FACE_KJH_WORRY]);
	m_pFace[E_FACE_KJH_WORRY]->SetShow(g_bChating);

	
	m_FacePos[E_FACE_HUMAN_1] = stEMVec2(350.0f,295.0f);
	m_pFace[E_FACE_HUMAN_1] = new CEMPlane();
	m_pFace[E_FACE_HUMAN_1]->SetTexture(pThisScene,"Data/Man/2.png");
	m_pFace[E_FACE_HUMAN_1]->SetSize(0.6f,0.6f);
	m_pFace[E_FACE_HUMAN_1]->SetPos(m_FacePos[E_FACE_HUMAN_1]);
	m_pFace[E_FACE_HUMAN_1]->SetBlend(true);
	m_pFace[E_FACE_HUMAN_1]->SetOrtho2D(true);
	//m_pPlane->SetOrtho2D(true);
	pThisScene->Commit(-998,"Lum", m_pFace[E_FACE_HUMAN_1]);
	m_pFace[E_FACE_HUMAN_1]->SetShow(g_bChating);

	m_FacePos[E_FACE_HUMAN_2] = stEMVec2(400.0f,295.0f);
	m_pFace[E_FACE_HUMAN_2] = new CEMPlane();
	m_pFace[E_FACE_HUMAN_2]->SetTexture(pThisScene,"Data/Man/3.png");
	m_pFace[E_FACE_HUMAN_2]->SetSize(0.6f,0.6f);
	m_pFace[E_FACE_HUMAN_2]->SetPos(m_FacePos[E_FACE_HUMAN_2]);
	m_pFace[E_FACE_HUMAN_2]->SetBlend(true);
	m_pFace[E_FACE_HUMAN_2]->SetOrtho2D(true);
	pThisScene->Commit(-998,"E_FACE_HUMAN_2", m_pFace[E_FACE_HUMAN_2]);
	m_pFace[E_FACE_HUMAN_2]->SetShow(g_bChating);

	m_FacePos[E_NOTICE] = stEMVec2(400.0f,295.0f);
	m_pFace[E_NOTICE] = new CEMPlane();
	m_pFace[E_NOTICE]->SetTexture(pThisScene,"Data/Man/4.png");
	m_pFace[E_NOTICE]->SetSize(0.6f,0.6f);
	m_pFace[E_NOTICE]->SetPos(m_FacePos[E_NOTICE]);
	m_pFace[E_NOTICE]->SetBlend(true);
	m_pFace[E_NOTICE]->SetOrtho2D(true);
	pThisScene->Commit(-998,"E_NOTICE", m_pFace[E_NOTICE]);
	m_pFace[E_NOTICE]->SetShow(g_bChating);
	
	m_FacePos[E_FACE_ROYAL_FORCES] = stEMVec2(400.0f,295.0f);
	m_pFace[E_FACE_ROYAL_FORCES] = new CEMPlane();
	m_pFace[E_FACE_ROYAL_FORCES]->SetTexture(pThisScene,"Data/Man/5.png");
	m_pFace[E_FACE_ROYAL_FORCES]->SetSize(0.6f,0.6f);
	m_pFace[E_FACE_ROYAL_FORCES]->SetPos(m_FacePos[E_FACE_ROYAL_FORCES]);
	m_pFace[E_FACE_ROYAL_FORCES]->SetBlend(true);
	m_pFace[E_FACE_ROYAL_FORCES]->SetOrtho2D(true);
	pThisScene->Commit(-998,"E_FACE_ROYAL_FORCES", m_pFace[E_FACE_ROYAL_FORCES]);
	m_pFace[E_FACE_ROYAL_FORCES]->SetShow(g_bChating);

	m_FacePos[E_FACE_LSY] = stEMVec2(400.0f,295.0f);
	m_pFace[E_FACE_LSY] = new CEMPlane();
	m_pFace[E_FACE_LSY]->SetTexture(pThisScene,"Data/Man/6.png");
	m_pFace[E_FACE_LSY]->SetSize(1.0f,1.0f);
	m_pFace[E_FACE_LSY]->SetPos(m_FacePos[E_FACE_LSY]);
	m_pFace[E_FACE_LSY]->SetBlend(true);
	m_pFace[E_FACE_LSY]->SetOrtho2D(true);
	pThisScene->Commit(-998,"E_FACE_LSY", m_pFace[E_FACE_LSY]);
	m_pFace[E_FACE_LSY]->SetShow(g_bChating);

	
	m_FacePos[E_FACE_HNPC1] = stEMVec2(400.0f,295.0f);
	m_pFace[E_FACE_HNPC1] = new CEMPlane();
	m_pFace[E_FACE_HNPC1]->SetTexture(pThisScene,"Data/Man/7.png");
	m_pFace[E_FACE_HNPC1]->SetSize(1.0f,1.0f);
	m_pFace[E_FACE_HNPC1]->SetPos(m_FacePos[E_FACE_HNPC1]);
	m_pFace[E_FACE_HNPC1]->SetBlend(true);
	m_pFace[E_FACE_HNPC1]->SetOrtho2D(true);
	pThisScene->Commit(-998,"E_FACE_HNPC1", m_pFace[E_FACE_HNPC1]);
	m_pFace[E_FACE_HNPC1]->SetShow(g_bChating);

	m_FacePos[E_FACE_HNPC2] = stEMVec2(400.0f,295.0f);
	m_pFace[E_FACE_HNPC2] = new CEMPlane();
	m_pFace[E_FACE_HNPC2]->SetTexture(pThisScene,"Data/Man/8.png");
	m_pFace[E_FACE_HNPC2]->SetSize(1.0f,1.0f);
	m_pFace[E_FACE_HNPC2]->SetPos(m_FacePos[E_FACE_HNPC2]);
	m_pFace[E_FACE_HNPC2]->SetBlend(true);
	m_pFace[E_FACE_HNPC2]->SetOrtho2D(true);
	pThisScene->Commit(-998,"E_FACE_HNPC2", m_pFace[E_FACE_HNPC2]);
	m_pFace[E_FACE_HNPC2]->SetShow(g_bChating);
	
	m_FacePos[E_FACE_HNPC3] = stEMVec2(400.0f,295.0f);
	m_pFace[E_FACE_HNPC3] = new CEMPlane();
	m_pFace[E_FACE_HNPC3]->SetTexture(pThisScene,"Data/Man/9.png");
	m_pFace[E_FACE_HNPC3]->SetSize(1.0f,1.0f);
	m_pFace[E_FACE_HNPC3]->SetPos(m_FacePos[E_FACE_HNPC3]);
	m_pFace[E_FACE_HNPC3]->SetBlend(true);
	m_pFace[E_FACE_HNPC3]->SetOrtho2D(true);
	pThisScene->Commit(-998,"E_FACE_HNPC3", m_pFace[E_FACE_HNPC3]);
	m_pFace[E_FACE_HNPC3]->SetShow(g_bChating);


	m_nMaxChatLevel = 0;
	m_bEntered = false;

	m_CTextName = new CEMText("으뜸체","이름저장");
	m_CTextName->SetPos(75.0f,410.0f);

	pThisScene->Commit(-1000,"TextName",m_CTextName);
	m_CTextDisplay.Init(pThisScene,"ChatText",75.0f + 100.0f,410.0f,60,30,stEMVec2(1.0f,1.0f),CEMColor(0.0f,0.0f,0.0f));
	m_CTextDisplay.SetText("대화내용저장");
	m_CTextDisplay.SetProgressTime(0.02f);
	m_CTextDisplay.Skip();
	//m_CTextDisplay.SetPause(true);
	m_nFaceLevel = 0;
	m_bSelect = false;
	m_nSelect = 1;

	m_bFirstEnterd = false;
}

void CChatWindow::Update(float dt, CInventory* Inventory)
{
	
	m_CTextDisplay.Update(dt);
	bool bEnterDown = false;
	m_pBlind->SetShow(g_bChating);
	m_pPlane->SetShow(g_bChating);
	m_pSelect->SetShow(m_bSelect);
	m_pSelect->SetPos(stEMVec2(150.0f, 400.0f + ((m_nSelect-1) * 30)));
	m_CTextDisplay.SetShow(g_bChating);
	m_CTextName->SetShow(g_bChating);
	for(int i = 0; i < E_FACE_MAX ; i++)
	{
		m_pFace[i]->SetShow(false);
	}
	//!< 키체크 저장
	if(GetKeyState(VK_RETURN) & 0x8000)
	{
		m_bEntered = true;
		bEnterDown = true;
		if(g_bChating == true &&m_bSelect == true && m_bFirstEnterd == true)
		{
			g_nChatLevel = 0;
			g_bChating = false;
			ChatEnd();
			m_bSelect = false;


			g_nEventLevel = m_nSelect;
			ChatStart(m_nNowIndex);
			m_bFirstEnterd = false;
		}
	}

	if(m_bSelect == true)
	{
		if(D_INPUT->IsKeyDown(VK_DOWN))
		{
			if(m_nSelect < D_CHATSELECT_MAX)
			{
				m_nSelect++;
			}
		}
		else if(D_INPUT->IsKeyDown(VK_UP))
		{
			if(m_nSelect > 1)
			{
				m_nSelect--;
			}
		}
	}

	if(g_nChatLevel < m_nMaxChatLevel) //!< 아직 최대대화에 도달하지 못했을경우
	{
		if(g_bChating == true)
		{
			if(m_TalkList[m_nFaceLevel]->nLeftFace != -1)
			{
				m_pFace[m_TalkList[m_nFaceLevel]->nLeftFace]->SetShow(true);
				m_pFace[m_TalkList[m_nFaceLevel]->nLeftFace]->SetMirrorType(E_LEFT_MIRROR);
				m_pFace[m_TalkList[m_nFaceLevel]->nLeftFace]->SetPos(m_FacePos[m_TalkList[m_nFaceLevel]->nLeftFace].m_fX - 190,m_FacePos[m_TalkList[m_nFaceLevel]->nLeftFace].m_fY);
				
			}
			if(m_TalkList[m_nFaceLevel]->nRightFace != -1)
			{
				m_pFace[m_TalkList[m_nFaceLevel]->nRightFace]->SetShow(true);
				m_pFace[m_TalkList[m_nFaceLevel]->nRightFace]->SetMirrorType(E_RIGHT_MIRROR);
				m_pFace[m_TalkList[m_nFaceLevel]->nRightFace]->SetPos(m_FacePos[m_TalkList[m_nFaceLevel]->nRightFace].m_fX + 220,m_FacePos[m_TalkList[m_nFaceLevel]->nRightFace].m_fY);
			}
		}
		if(g_bChating == true)
		{
			if(m_bEntered == true && bEnterDown == false) //!< 눌렀었다가 뗌
			{
				if(m_bFirstEnterd == false)
				{
					m_bFirstEnterd = true;

					m_bEntered = false;
				}
				else if(m_bFirstEnterd == true)
				{
					if(g_bChating == true)
					{
						D_SOUNDMNG->Play("Enter",false,1.5f);
					}

					m_bEntered = false;

					if(m_CTextDisplay.IsViewing() == true)
					{
					m_CTextDisplay.Skip();
						g_nChatLevel--;
					}
					else if(m_CTextDisplay.IsViewing() == false)
					{
						if(g_nChatLevel < m_nMaxChatLevel-1)
						{
							m_CTextDisplay.m_nNowChar = m_CTextDisplay.m_nMaxChar;
							m_CTextDisplay.SetText(m_TalkList[g_nChatLevel]->strTalk);
							m_CTextName->SetOutPutString(m_TalkList[g_nChatLevel]->strName);
							m_nFaceLevel++;
						}
					}
					g_nChatLevel++;

					//if(m_nNowIndex == 1) //!< 1번 NPC
					//{
					//	switch(g_nChatLevel)
					//	{
					//	case 2:
					//		m_CTextDisplay.m_nNowChar = m_CTextDisplay.m_nMaxChar;
					//		m_CTextDisplay.SetText("백노연 : 아ㅋㅋ");
					//		break;
					//	case 3:
					//		m_pFace[E_FACE_CDS]->SetShow(false);
					//		m_pFace[E_FACE_MGH]->SetShow(true);
					//		m_CTextDisplay.m_nNowChar = m_CTextDisplay.m_nMaxChar;
					//		m_CTextDisplay.SetText("마광휘 : 펜!타!킬!");
					//		break;
					//	}
					//}
					//else if(m_nNowIndex == 2)
					//{
					//	switch(g_nChatLevel)
					//	{
					//	case 2:
					//		m_CTextDisplay.m_nNowChar = m_CTextDisplay.m_nMaxChar;
					//		m_CTextDisplay.SetText("도우미 : 즐거운 TimeKeeper 되세요!");
					//		break;
					//	}
					//}
				}
				if(g_nChatLevel >= m_nMaxChatLevel)
				{
					/*m_pFace[E_FACE_LUM]->SetShow(false);
					m_pFace[E_FACE_CDS]->SetShow(false);
					m_pFace[E_FACE_MGH]->SetShow(false);*/
					g_nChatLevel = 0;
					g_bChating = false;


					ChatEnd();
					/*if(m_bSelect == true)
					{
						m_bSelect = false;
						g_nEventLevel = m_nSelect;
						ChatStart(m_nNowIndex);
					}*/
				
					if(m_bSelect == false)
					{


						if(g_nEventLevel == 1)
						{
							if(g_nQuestLevel == 1)
							{
								if(m_nNowIndex == 1)
								{
									D_SOUNDMNG->Play("Clear",false,1.5f);
									g_nQuestLevel++;

								}
							}
							else if(g_nQuestLevel == 2)
							{
								if(m_nNowIndex == 2)
								{
									D_SOUNDMNG->Play("Clear",false,1.5f);
									g_nQuestLevel++;
									g_CMapManager.ChangeMap(2,&g_CHero);
									g_CMapManager.m_stNextHeroPos = stEMVec2(120,-144);
								}
							}
							else if(g_nQuestLevel == 3)
							{
								if(m_nNowIndex == 3)
								{
									D_SOUNDMNG->Play("Clear",false,1.5f);
									g_nQuestLevel++;
								}
							}
							else if(g_nQuestLevel == 6)
							{
								if(m_nNowIndex == 6)
								{
									D_SOUNDMNG->Play("Clear",false,1.5f);
									g_nQuestLevel++;
								}
							}
							else if(g_nQuestLevel == 7)
							{
								if(m_nNowIndex == 7)
								{
									D_SOUNDMNG->Play("Clear",false,1.5f);
									g_nQuestLevel++;
								}
							}
							else if(g_nQuestLevel == 8)
							{
								if(m_nNowIndex == 8)
								{
									D_SOUNDMNG->Play("Clear",false,1.5f);
									g_nQuestLevel++;
								}
							}
							else if(g_nQuestLevel == 9)
							{
								if(m_nNowIndex == 9)
								{
									D_SOUNDMNG->Play("Clear",false,1.5f);
									g_nQuestLevel++;
								}
							}
						}
						if(g_nEventLevel == 0)
						{
							if(g_nQuestLevel == 5)
							{
								if(m_nNowIndex == -1)
								{
									D_SOUNDMNG->Play("Clear",false,1.5f);
									g_CInventory.Push_Item(0,1);
									g_nQuestLevel++;
								}
							}
						}
						/*if(g_nEventLevel == 1)
						{
							if(g_nQuestLevel == 1)
							{
								if(m_nNowIndex == 1)
								{
									D_SOUNDMNG->Play("LevelUp",false,1.5f);
									g_nQuestLevel++;
								}
							}
							else if(g_nQuestLevel == 2)
							{
								if(m_nNowIndex == 2)
								{
									D_SOUNDMNG->Play("LevelUp",false,1.5f);
									g_nQuestLevel++;
								}
							}
							else if(g_nQuestLevel == 3)
							{
								if(m_nNowIndex == 4)
								{
									if(Inventory->SearchItem_All(3).m_fX != -1)
									{
										D_SOUNDMNG->Play("LevelUp",false,1.5f);
										g_nQuestLevel++;
									}
								}
							}
						}*/




					}


				}
			
			}
		}
	}
	
}
void CChatWindow::ChatStart(int nIndex)
{
	char strTemp[256];


	g_nConditionLevel = 1;

	sprintf(strTemp,"Data/Talk/Talk_%d_%d_%d_%d.txt",nIndex,g_nEventLevel,g_nQuestLevel,g_nConditionLevel);
	FILE* fp = fopen(strTemp,"rt");

	if(g_nEventLevel == 1)
	{
		if(fp == NULL)
		{
			sprintf(strTemp,"Data/Talk/Talk_%d_%d_%d_%d.txt",1,1,2,1);
			fp = fopen(strTemp,"rt");
		}
	}
	else if(g_nEventLevel == 2)
	{
		if(fp == NULL)
		{
			sprintf(strTemp,"Data/Talk/Talk_%d_%d_%d_%d.txt",1,2,1,1);
			fp = fopen(strTemp,"rt");
		}
	}
	m_nNowIndex = nIndex;
	m_nMaxChatLevel = 1;
	g_nChatLevel = 1;
	if(g_nEventLevel == 0)
	{
		m_bFirstEnterd = false;
	}
	
	while(feof(fp) == 0)
	{
		char strName[256];
		char strTalk[256];
		stTalk* pTalk = new stTalk();
		fscanf(fp,"%d %d",&pTalk->nLeftFace,&pTalk->nRightFace);
		fscanf(fp,"%s",&strName);
		fscanf(fp,"%s",&strTalk);
		int i=0;
		while(strName[i] != '\0')
		{
			if(strName[i] == '\\')
			{
				strName[i] = ' ';
			}
			i++;
		}
		i=0;
		while(strTalk[i] != '\0')
		{
			if(strTalk[i] == '\\')
			{
				strTalk[i] = ' ';
			}
			i++;
		}
		pTalk->strName = strName;
		pTalk->strTalk = strTalk;

		m_TalkList.push_back(pTalk);
		m_nMaxChatLevel++;
	}
	m_nFaceLevel = 0;
	m_CTextDisplay.m_nNowChar = m_CTextDisplay.m_nMaxChar;
	m_CTextDisplay.SetText(m_TalkList[0]->strTalk);
	m_CTextName->SetOutPutString(m_TalkList[0]->strName);
		
	g_bChating = true;
	m_CTextDisplay.SetPause(false);

}

void CChatWindow::ChatSelect(int nIndex)
{
	char strTemp[256];


	m_nNowIndex = nIndex;

	m_nMaxChatLevel = 1;
	g_nChatLevel = 1;
	m_bFirstEnterd = false;

	
	char strName[256];
	char strTalk[256];

	stTalk* pTalk = new stTalk();
	pTalk->nLeftFace = -1;
	pTalk->nRightFace = -1;
	pTalk->strName = " ";
	pTalk->strTalk = "대화하기/증거수집";

	m_TalkList.push_back(pTalk);
	m_nMaxChatLevel++;
	
	m_nFaceLevel = 0;
	m_CTextDisplay.SetText(m_TalkList[0]->strTalk);
	m_CTextName->SetOutPutString(m_TalkList[0]->strName);
		
	g_bChating = true;
	m_CTextDisplay.SetPause(false);
	m_bSelect = true;

}
void CChatWindow::ChatEnd()
{
	vector<stTalk*>::iterator it;
	for(it = m_TalkList.begin(); it != m_TalkList.end(); it++)
	{
		delete (*it);
	}
	m_TalkList.clear();
	m_CTextDisplay.m_nNowChar = m_CTextDisplay.m_nMaxChar;
	m_CTextDisplay.SetText(" ");
}