#pragma once

#include "stdafx.h"

class CLogo: public CRootScene
{
public:
	CEMText*		m_pText;	//!< �������
	stEMVec3		m_stCamPos;

	CEMAnimation*	m_AniFire;
	CEMAnimation*	m_AniFly;
	CEMPlane*		m_pClock;
	CEMPlane*		m_pPin;
	CEMPlane*		m_pClockBody;
	CEMPlane*		m_KGLogo;
	CEMPlane*		m_KGLogo2;
	CEMPlane*		m_SchoolLogo;
	CEMPlane*		m_BackGround;
	CEMPlane*		m_pFlyAttack;

	stEMVec2			m_stFly;
	stEMVec3			m_KGXY;
	stEMVec3			m_KGXY2;
	stEMVec2			m_stShakeX;
	SOUND_HANDLE		m_SHandle;
public:
	float			m_LogoSize;
	float			m_KGZRot;
	float			m_Volume;
	float			m_fPinZRot;
	float			m_fTimer;
	float			m_fFlyAttackTimer;		//��Ǯ������ ���ݹ��� �̹��� ��½ð�üũ

	bool			m_flyFirstEffect;
	bool			m_flyEffect;
	bool			m_bTimerEffect;
	bool			m_SizeControl;
	bool			m_EffectCheck1;
	bool			m_KGCheck1;
	bool			m_KGCheck2;
	bool			m_bShakeControl;
	bool			m_bBombEffect;
public:
	CLogo(void)
	{
		m_KGXY.m_fX = 0.0f;
		m_KGXY.m_fY = 230.0f;
		m_KGXY.m_fZ = 0.0f;

		m_KGXY2.m_fX = 0.0f;
		m_KGXY2.m_fY = -230.0f;
		m_KGXY2.m_fZ = 0.0f;

		m_stFly.m_fX = -300.0f;
		m_stFly.m_fY = 0.0f;

		m_fTimer	 =	0.0f;
		m_fPinZRot = 180.0f;

		m_KGZRot = 0.0f;
		m_Volume = 0.5f;
		m_stCamPos.m_fX = 0.0f;
		m_stCamPos.m_fY = 0.0f;
		m_LogoSize = 0.4f;
		m_SizeControl = false;
		m_stCamPos.m_fZ = 300.0f;
		m_EffectCheck1		= false;
		m_KGCheck1			= false;
		m_KGCheck2			= false;	
		m_bTimerEffect		= false;
		m_stShakeX.m_fX		= 0.0f;
		m_bShakeControl		= false;
		m_flyEffect			= false;
		m_flyFirstEffect	= false;
		m_bBombEffect		= false;
	};
	virtual ~CLogo(void)
	{
	};
public:
	void Init						();
	void	MousePoint				(stMouseInfo	stPos);
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
	virtual void PostSolve			(const b2Contact* contact, const b2ContactImpulse* impulse);
};

