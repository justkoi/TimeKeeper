#pragma once
#include "stdafx.h"

typedef enum
{
	E_STATICBUTTON_STATE_NONE,
	E_STATICBUTTON_STATE_OVER,
	E_STATICBUTTON_STATE_CLICKED,
	E_STATICBUTTON_STATE_MAX,
}E_STATICBUTTON_STATE;

class CEMStaticButton
{
public:
	E_STATICBUTTON_STATE m_eButtonState;
	stEMVec2		m_stPos;

	CEMPlane*		m_pButton[E_STATICBUTTON_STATE_CLICKED];

	CRootScene*		m_pThisScene;
	bool	m_bVisible;
	bool	m_bAction;
	bool m_bInited;
public:
	CEMStaticButton()
	{
		m_bInited = false;
	}
	void Init(CRootScene* pScene, CEMPlane* pButton_None, CEMPlane* pButton_Over, CEMPlane* pButton_Clicked, stEMVec2 stPos, bool bVisible);
	void Update(float dt);
	void Exit();

	bool IsAction() { return m_bAction; };

	void Check_Move(stMouseInfo stPos);
	void Check_Down(stMouseInfo stPos);
	void Check_Up(stMouseInfo stPos);
};