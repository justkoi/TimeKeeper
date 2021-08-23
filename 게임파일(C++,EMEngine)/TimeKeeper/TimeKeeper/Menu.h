#pragma once

#include "EM2DEngine.h"
#include <math.h>

/*
	1. 물리 안붙은 Plane
		- 물리가 붙이 않았으므로 충돌 계산을 사용자가 직접 해줘야합니다
*/
class CMenu : public CRootScene
{
private:
	bool		m_GameOverCheck;
	bool		m_OptionOverCheck;
	bool		m_CreditOverCheck;
	bool		m_ExitOverCheck;
	
public:
	TwBar* m_pBar;			//!< 디버그용 바입니다

public:
	CEMText*		m_pText;	//!< 글자출력
	CEMPlane*		m_pPlane;	//!< Plane 출력
	
	CEMSound*		m_Sound;
	CEMPlane*		m_pBackShadow;
	CEMAnimation*	m_MouseAni;
	CEMPlane*		m_Game;
	CEMPlane*		m_Option;
	CEMPlane*		m_Credit;
	CEMPlane*		m_Exit;
	CEMPlane*		m_Title;

	CEMPlane*		m_pClock;
	CEMPlane*		m_pPin;
	CEMPlane*		m_pPin2;

	CEMPlane*		m_Wheel1;
	CEMPlane*		m_Wheel2;
	CEMPlane*		m_Wheel3;
	CEMParticle*	m_Particle;
	CEMParticle*	m_Particle2;

	CEMParticle*	m_MouseParticle;

	CEMPlane*		m_BackGround;
	CEMColor		m_EndColor;
	CEMPlane*		m_Practice;

	CEMPlane*		m_VolumeControl;

	stEMVec3	m_GameXY;
	stEMVec3	m_OptionXY;
	stEMVec3	m_CreditXY;
	stEMVec3	m_ExitXY;
	stEMVec3	m_TitleXY;

	
	
	SOUND_HANDLE	m_SHandle;
	SOUND_HANDLE	m_SRoot;
	SOUND_HANDLE	m_SButton;

	stEMVec3	m_stCamPos;	//!< 카메라 위치 저장 벡터

	CEMPlane*	MakerInfo;

public:

	float		m_WheelZRot;
	float		m_WheelZRot2;
	float		m_fBackGroundAlpha;
	float		m_fAlphaCount;
	float		m_fShadowAlpha;
	float		m_fClockZRot;
	float		m_fClockPinZRot;

	bool		m_GameClickCheck;
	bool		m_OptionClickCheck;
	bool		m_CreditClickCheck;
	bool		m_ExitClickCheck;
	
	bool		m_GameChange;
	bool		m_OptionChange;
	bool		m_CreditChange;
	bool		m_ExitChange;
	
	bool		m_TitleMoveCheck;

	bool		m_MakeClick;
	bool		m_TitleShow;

	bool		m_bParticleCheck;

	bool		m_SkipCheck;
	bool		m_SoundOnCheck;
	bool		m_SoundOffCheck;

public:
	CMenu(void)
	{	
		m_pPlane = NULL;
		m_pText = NULL;
		m_pBar = NULL;
		
		m_MakeClick = false;
		m_TitleShow = false;
		m_SoundOnCheck    = true;
		m_SoundOffCheck   = true;

		m_stCamPos.m_fX = 0.0f;
		m_stCamPos.m_fY = 0.0f;
		m_stCamPos.m_fZ = 300.0f;


		m_GameXY.m_fX = -120.0f;
		m_GameXY.m_fY = -20.0f;
		m_GameXY.m_fZ = 10.0f;

		m_CreditXY.m_fX = 20.0f;
		m_CreditXY.m_fY = -20.0f;
		m_CreditXY.m_fZ = 10.0f;

		m_OptionXY.m_fY = -80.0f;
		m_OptionXY.m_fX = -120.0f;
		m_OptionXY.m_fZ = 10.0f;

		m_ExitXY.m_fY = -80.0f;
		m_ExitXY.m_fX = 20.0f;
		m_ExitXY.m_fZ = 10.0f;

		m_TitleXY.m_fX = -50.0f;
		m_TitleXY.m_fY = 50.0f;
		m_TitleXY.m_fZ = 0.0f;

		m_WheelZRot = 0.0f;
		m_WheelZRot2 = 0.0f;
		m_fClockZRot = 0.0f;

		m_CreditClickCheck = false;
		m_OptionClickCheck = false;
		m_GameClickCheck = false;
		m_ExitClickCheck = false;
		
		m_CreditChange = false;
		m_OptionChange = false;
		m_GameChange = false;
		m_ExitChange = false;
		
		m_TitleMoveCheck = false;
		m_SkipCheck = false;

		m_bParticleCheck = false;
		m_fBackGroundAlpha	= 0.0f;
		m_fAlphaCount	= 0.0f;
		m_fShadowAlpha	= 1.0f;
		m_fClockPinZRot	= 0.0f;
	};
	virtual ~CMenu(void)
	{
		
	};

public:
	void							Clock					(float  dt);
	void							Twinkl					(float dt);
	void							Particles				(stEMVec2 stPos,stdEMString sCommitName);
	void							MousePoint				(stMouseInfo stPos);
	void DamageEffect				(float dt);
	virtual void Enter				(CSceneWork* pSceneWork);										//!< 진입(로딩)
	virtual void Update				(CSceneWork*, float dt);										//!< Update
	virtual void Render				(CSceneWork*);													//!< Render
	virtual void Exit				(CSceneWork* pSceneWork);										//!< 탈출(메모리 해제등)
	virtual void MouseDownEvent		(stMouseInfo stPos, enumMouseButton eButton);					//!< 마우스 다운 이벤트
	virtual void MouseUpEvent		(stMouseInfo stPos, enumMouseButton eButton);					//!< 마우스 업 이벤트
	virtual void MouseMoveEvent		(stMouseInfo stPos);											//!< 마우스 이동 이벤트
	virtual HRESULT WindowMessage	(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);			//!< 윈도우 이벤트

	//!=================================================================================================
	//! 물리 충돌 이벤트들 입니다.
	virtual void BeginContact		(b2Contact* contact); 											//!< 충돌시작  되면 자동 호출된다
	virtual void EndContact			(b2Contact* contact); 											//!< 충돌이 끝나고 떨어질때 자동 호출된다
	virtual void PreSolve			(b2Contact* contact, const b2Manifold* oldManifold);			//!< 물리량계산이 발생했을때(충격이 발생했을때처리^^(
	virtual void PostSolve			(const b2Contact* contact, const b2ContactImpulse* impulse);	//!< 물리량계산이 끝났을때
};