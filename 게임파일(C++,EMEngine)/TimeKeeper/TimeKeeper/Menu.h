#pragma once

#include "EM2DEngine.h"
#include <math.h>

/*
	1. ���� �Ⱥ��� Plane
		- ������ ���� �ʾ����Ƿ� �浹 ����� ����ڰ� ���� ������մϴ�
*/
class CMenu : public CRootScene
{
private:
	bool		m_GameOverCheck;
	bool		m_OptionOverCheck;
	bool		m_CreditOverCheck;
	bool		m_ExitOverCheck;
	
public:
	TwBar* m_pBar;			//!< ����׿� ���Դϴ�

public:
	CEMText*		m_pText;	//!< �������
	CEMPlane*		m_pPlane;	//!< Plane ���
	
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

	stEMVec3	m_stCamPos;	//!< ī�޶� ��ġ ���� ����

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
	virtual void Enter				(CSceneWork* pSceneWork);										//!< ����(�ε�)
	virtual void Update				(CSceneWork*, float dt);										//!< Update
	virtual void Render				(CSceneWork*);													//!< Render
	virtual void Exit				(CSceneWork* pSceneWork);										//!< Ż��(�޸� ������)
	virtual void MouseDownEvent		(stMouseInfo stPos, enumMouseButton eButton);					//!< ���콺 �ٿ� �̺�Ʈ
	virtual void MouseUpEvent		(stMouseInfo stPos, enumMouseButton eButton);					//!< ���콺 �� �̺�Ʈ
	virtual void MouseMoveEvent		(stMouseInfo stPos);											//!< ���콺 �̵� �̺�Ʈ
	virtual HRESULT WindowMessage	(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);			//!< ������ �̺�Ʈ

	//!=================================================================================================
	//! ���� �浹 �̺�Ʈ�� �Դϴ�.
	virtual void BeginContact		(b2Contact* contact); 											//!< �浹����  �Ǹ� �ڵ� ȣ��ȴ�
	virtual void EndContact			(b2Contact* contact); 											//!< �浹�� ������ �������� �ڵ� ȣ��ȴ�
	virtual void PreSolve			(b2Contact* contact, const b2Manifold* oldManifold);			//!< ����������� �߻�������(����� �߻�������ó��^^(
	virtual void PostSolve			(const b2Contact* contact, const b2ContactImpulse* impulse);	//!< ����������� ��������
};