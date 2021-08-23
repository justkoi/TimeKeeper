#pragma once

#include "stdafx.h"

typedef enum
{
	E_BLINDSTATE_FADE_IN, //!< 점점 밝아지는 중
	E_BLINDSTATE_FADE_OUT, //!< 점점 어두워 지는 중
}E_BLINDSTATE_FADE;

class CBlindManager
{
private:
public:
	CEMPlane* m_pPlane;
	E_BLINDSTATE_FADE m_eState;
	bool	m_bAction; //!< 액션완료
	int		m_nNumber; //!< 반복횟수
	float	m_fTimer;
	bool	m_bPause; //!< 일시정지
	float	m_fBlindTime; //!< 블라인드 지속시간 한큐
	bool	m_bVisible;
	bool	m_bNextDtPass;
public:
	void Init(CRootScene* pThisScene);
	void Update(float dt);
	void Exit();
public:
	void Pause();
	void Resume();

	void StartBlind(int nNumber, E_BLINDSTATE_FADE eState, float fBlindTime, bool bNextDtPass = false); //!< 마지막 인자값은 맵을 읽어들이는 시간동안 손해본 dt를 무시합니다.
};