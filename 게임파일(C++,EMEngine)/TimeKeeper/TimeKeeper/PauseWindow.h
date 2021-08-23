#pragma once

#include "stdafx.h"
typedef enum
{
	E_PAUSEWINDOW_BUTTON_ITEM,
	E_PAUSEWINDOW_BUTTON_TIME,
	E_PAUSEWINDOW_BUTTON_STATE,
	E_PAUSEWINDOW_BUTTON_LOAD,
	E_PAUSEWINDOW_BUTTON_SAVE,
	E_PAUSEWINDOW_BUTTON_MAX,
}E_PAUSEWINDOW_BUTTON;
class CPauseWindow
{
private:
	CRootScene * m_pThisScene;

	CEMPlane* m_pPlane;
	CEMPlane* m_pBlind;

	CEMStaticButton m_Button[E_PAUSEWINDOW_BUTTON_MAX];
	CEMPlane*	m_pButtonImg[E_PAUSEWINDOW_BUTTON_MAX][3];
	
	CEMPlane*	m_pPauseImg[E_PAUSEWINDOW_BUTTON_MAX];

	stEMVec2 m_stPos;
	float	m_fDistance;
	float	m_fMoveSpeed;
	float	m_fPlusMoveSpeed;
public:
	void Init(CRootScene* pThisScene);
	void Update(float dt);
	void Exit();

	void Check_Down(stMouseInfo stPos);
	void Check_Move(stMouseInfo stPos);
	void Check_Up(stMouseInfo stPos);
public:
	void Pause();
	void Resume();
	bool Moving();
public:
	void SaveStage(int nStage);
	void LoadStage(int nStage);
};