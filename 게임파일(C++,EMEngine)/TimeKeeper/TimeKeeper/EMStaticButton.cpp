#include "stdafx.h"

void CEMStaticButton::Init(CRootScene* pScene, CEMPlane* pButton_None, CEMPlane* pButton_Over, CEMPlane* pButton_Clicked, stEMVec2 stPos, bool bVisible)
{
	m_pThisScene = pScene;
	m_eButtonState = E_STATICBUTTON_STATE_NONE;
	m_pButton[E_STATICBUTTON_STATE_NONE] = pButton_None;
	m_pButton[E_STATICBUTTON_STATE_OVER] = pButton_Over;
	m_pButton[E_STATICBUTTON_STATE_CLICKED] = pButton_Clicked;
	
	m_stPos = stPos;
	m_bVisible = bVisible;
	m_bAction = false;
	m_bInited = true;
}
void CEMStaticButton::Update(float dt)
{
	for(int i=0; i<E_STATICBUTTON_STATE_MAX; i++)
	{
		m_pButton[i]->SetShow(false);
		m_pButton[i]->SetPos(m_stPos);
	}

	if(m_bVisible == true)
		m_pButton[m_eButtonState]->SetShow(true);

}
void CEMStaticButton::Exit()
{

}

void CEMStaticButton::Check_Move(stMouseInfo stPos)
{
	if(m_bInited == true)
	{
		if(m_eButtonState == E_STATICBUTTON_STATE_CLICKED)
			return;
		if(stPos.m_nX >= m_stPos.m_fX - m_pButton[m_eButtonState]->GetTextureWidthHalfSize() && stPos.m_nX <= m_stPos.m_fX + m_pButton[m_eButtonState]->GetTextureWidthHalfSize() &&
			stPos.m_nY >= m_stPos.m_fY - m_pButton[m_eButtonState]->GetTexTureHeightHalfSize() && stPos.m_nY <= m_stPos.m_fY + m_pButton[m_eButtonState]->GetTexTureHeightHalfSize() )
		{
			m_eButtonState = E_STATICBUTTON_STATE_OVER;
		}
		else
		{
			m_eButtonState = E_STATICBUTTON_STATE_NONE;
		}
	}
}
void CEMStaticButton::Check_Down(stMouseInfo stPos)
{
	if(m_bInited == true)
	{
		if(stPos.m_nX >= m_stPos.m_fX - m_pButton[m_eButtonState]->GetTextureWidthHalfSize() && stPos.m_nX <= m_stPos.m_fX + m_pButton[m_eButtonState]->GetTextureWidthHalfSize() &&
			stPos.m_nY >= m_stPos.m_fY - m_pButton[m_eButtonState]->GetTexTureHeightHalfSize() && stPos.m_nY <= m_stPos.m_fY + m_pButton[m_eButtonState]->GetTexTureHeightHalfSize() )
		{
			m_eButtonState = E_STATICBUTTON_STATE_CLICKED;
			m_bAction = true;
		}
	}
}
void CEMStaticButton::Check_Up(stMouseInfo stPos)
{
	if(m_bInited == true)
	{
		if(stPos.m_nX >= m_stPos.m_fX - m_pButton[m_eButtonState]->GetTextureWidthHalfSize() && stPos.m_nX <= m_stPos.m_fX + m_pButton[m_eButtonState]->GetTextureWidthHalfSize() &&
			stPos.m_nY >= m_stPos.m_fY - m_pButton[m_eButtonState]->GetTexTureHeightHalfSize() && stPos.m_nY <= m_stPos.m_fY + m_pButton[m_eButtonState]->GetTexTureHeightHalfSize() )
		{
			m_eButtonState = E_STATICBUTTON_STATE_OVER;
		}
		else
		{
			m_eButtonState = E_STATICBUTTON_STATE_NONE;
		}
	}
}