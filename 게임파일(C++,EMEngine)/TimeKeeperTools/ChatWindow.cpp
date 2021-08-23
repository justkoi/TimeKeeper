#include "stdafx.h"

int g_nEventLevel = 1;
int g_nQuestLevel = 1;
int g_nChatLevel = 0;
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

	//
	m_FacePos[E_FACE_CDS] = stEMVec2(400.0f,260.0f);
	m_pFace[E_FACE_CDS] = new CEMPlane();
	m_pFace[E_FACE_CDS]->SetTexture(pThisScene,"Data/Man/1.png");
	m_pFace[E_FACE_CDS]->SetSize(0.8f,0.8f);
	m_pFace[E_FACE_CDS]->SetPos(m_FacePos[E_FACE_CDS]);
	m_pFace[E_FACE_CDS]->SetBlend(true);
	m_pFace[E_FACE_CDS]->SetOrtho2D(true);
	//m_pPlane->SetOrtho2D(true);
	pThisScene->Commit(-998,"CDS", m_pFace[E_FACE_CDS]);
	m_pFace[E_FACE_CDS]->SetShow(g_bChating);

	m_FacePos[E_FACE_MGH] = stEMVec2(400.0f,260.0f);
	m_pFace[E_FACE_MGH] = new CEMPlane();
	m_pFace[E_FACE_MGH]->SetTexture(pThisScene,"Data/Man/2.png");
	m_pFace[E_FACE_MGH]->SetSize(0.8f,0.8f);
	m_pFace[E_FACE_MGH]->SetPos(m_FacePos[E_FACE_MGH]);
	m_pFace[E_FACE_MGH]->SetBlend(true);
	m_pFace[E_FACE_MGH]->SetOrtho2D(true);
	//m_pPlane->SetOrtho2D(true);
	pThisScene->Commit(-998,"E_FACE_MGH", m_pFace[E_FACE_MGH]);
	m_pFace[E_FACE_MGH]->SetShow(g_bChating);

	
	m_FacePos[E_FACE_LUM] = stEMVec2(350.0f,295.0f);
	m_pFace[E_FACE_LUM] = new CEMPlane();
	m_pFace[E_FACE_LUM]->SetTexture(pThisScene,"Data/Man/3.png");
	m_pFace[E_FACE_LUM]->SetSize(0.6f,0.6f);
	m_pFace[E_FACE_LUM]->SetPos(m_FacePos[E_FACE_LUM]);
	m_pFace[E_FACE_LUM]->SetBlend(true);
	m_pFace[E_FACE_LUM]->SetOrtho2D(true);
	//m_pPlane->SetOrtho2D(true);
	pThisScene->Commit(-998,"Lum", m_pFace[E_FACE_LUM]);
	m_pFace[E_FACE_LUM]->SetShow(g_bChating);

	m_FacePos[E_FACE_ARN] = stEMVec2(400.0f,295.0f);
	m_pFace[E_FACE_ARN] = new CEMPlane();
	m_pFace[E_FACE_ARN]->SetTexture(pThisScene,"Data/Man/4.png");
	m_pFace[E_FACE_ARN]->SetSize(0.6f,0.6f);
	m_pFace[E_FACE_ARN]->SetPos(m_FacePos[E_FACE_ARN]);
	m_pFace[E_FACE_ARN]->SetBlend(true);
	m_pFace[E_FACE_ARN]->SetOrtho2D(true);
	pThisScene->Commit(-998,"ARAN", m_pFace[E_FACE_ARN]);
	m_pFace[E_FACE_ARN]->SetShow(g_bChating);

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
	
	m_bFirstEnterd = false;
}

void CChatWindow::Update(float dt)
{
	m_CTextDisplay.Update(dt);
	bool bEnterDown = false;
	m_pBlind->SetShow(g_bChating);
	m_pPlane->SetShow(g_bChating);
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
				m_pFace[E_FACE_LUM]->SetShow(false);
				m_pFace[E_FACE_CDS]->SetShow(false);
				m_pFace[E_FACE_MGH]->SetShow(false);
				g_nChatLevel = 0;
				g_bChating = false;
				ChatEnd();

				if(g_nEventLevel == 1)
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
							D_SOUNDMNG->Play("LevelUp",false,1.5f);
							g_nQuestLevel++;
						}
					}
				}
			}
		}
	}
	
}
void CChatWindow::ChatStart(int nIndex)
{
	char strTemp[256];
	sprintf(strTemp,"Data/Talk/Talk_%d_%d_%d.txt",nIndex,g_nEventLevel,g_nQuestLevel);
	FILE* fp = fopen(strTemp,"rt");
	m_nNowIndex = nIndex;
	m_nMaxChatLevel = 1;
	g_nChatLevel = 1;
	m_bFirstEnterd = false;
	
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
	m_CTextDisplay.SetText(m_TalkList[0]->strTalk);
	m_CTextName->SetOutPutString(m_TalkList[0]->strName);
		
	g_bChating = true;
	m_CTextDisplay.SetPause(false);

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