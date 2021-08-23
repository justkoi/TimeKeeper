#include "stdafx.h"


void CBlindManager::Init(CRootScene* pThisScene)
{
	m_eState = E_BLINDSTATE_FADE_IN;
	m_bAction  = false; //!< 액션완료
	m_nNumber = 0; //!< 반복횟수
	m_fTimer = 0.0f;
	m_bPause = false; //!< 일시정지
	m_fBlindTime = 3.0f; //!< 블라인드 지속시간 한큐
	m_bVisible = true;
	m_bNextDtPass = false;

	m_pPlane = new CEMPlane();
	m_pPlane->SetTexture(pThisScene,"Data/Image/Effect/Blind.png");
	m_pPlane->SetSize(1.0f,1.0f);
	m_pPlane->SetPos(0.0f + 512,0.0f + 512);
	m_pPlane->SetBlend(true);
	m_pPlane->SetOrtho2D(true);
	pThisScene->Commit(-999,"Blind", m_pPlane);

}
void CBlindManager::Update(float dt)
{
	if(m_bPause == false)
	{
		if(m_nNumber >= 1)
		{
			if(m_eState == E_BLINDSTATE_FADE_IN)
			{
				if(m_bNextDtPass == false)
					m_fTimer -= dt;
				else if(m_bNextDtPass == true)
					m_bNextDtPass = false;
				if(m_fTimer <= 0.0f)
				{
					m_fTimer = 0.0f;
					m_nNumber--;
					if(m_nNumber == 0)
					{
						m_bAction = true;
						m_bVisible = false;
					}
				}
			}
			else if(m_eState == E_BLINDSTATE_FADE_OUT)
			{
				if(m_bNextDtPass == false)
					m_fTimer += dt;
				else if(m_bNextDtPass == true)
					m_bNextDtPass = false;
				if(m_fTimer >= m_fBlindTime)
				{
					m_fTimer = m_fBlindTime;
					m_nNumber--;
					if(m_nNumber == 0)
					{
						m_bAction = true;
						//m_bVisible = false;
					}
				}
			}
		}
	/*	if(m_nNumber == 0)
			m_bAction = false;
		else
			m_bAction = true;*/
		m_pPlane->SetAlpha(m_fTimer/m_fBlindTime);
		m_pPlane->SetShow(m_bVisible);
	}
}
void CBlindManager::Exit()
{

}

void CBlindManager::Pause()
{
	m_bPause = true;
}
void CBlindManager::Resume()
{
	m_bPause = false;
}


void CBlindManager::StartBlind(int nNumber, E_BLINDSTATE_FADE eState, float fBlindTime, bool bNextDtPass)
{
	m_bAction = false;
	m_eState = eState;
	m_nNumber = nNumber;
	m_bPause = false;
	m_bVisible = true;
	m_fBlindTime = fBlindTime;
	if(m_eState == E_BLINDSTATE_FADE_IN)
		m_fTimer = m_fBlindTime;
	else if(m_eState == E_BLINDSTATE_FADE_OUT)
		m_fTimer = 0.0f;
}