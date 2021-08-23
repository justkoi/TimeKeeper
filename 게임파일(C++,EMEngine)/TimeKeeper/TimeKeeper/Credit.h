#pragma once

#include "stdafx.h"
class CCredit: public CRootScene
{
public:
	TwBar* m_pBar;	
public:
	CEMText*		m_pText;	//!< �������
	CEMPlane*		m_pPlane;	//!< Plane ���
	stEMVec3		m_stCamPos;

	stEMVec2		m_stStar;
	stEMVec2		m_stStar2;

	CEMAnimation*	m_MouseAni;
	CEMParticle*	m_MouseParticle;

	CEMPlane*		m_Topni;
	CEMPlane*		m_Maker1;
	CEMPlane*		m_Maker2;
	CEMPlane*		m_Maker3;
	CEMPlane*		m_TeamName;
	CEMPlane*		m_BackGround;
	CEMPlane*		m_BackButton;

	CEMPlane*		m_pStar2;

	CEMPlane*		m_pStar;

	SOUND_HANDLE	m_SHandle;
public:
	float			m_ZRot;
	int				m_CountCheck;
	float			m_fEffect;
	float			m_fTriangleFx;
	float			m_fTriangleFx2;
	float			m_fTriangleFx3;
	float			m_fTriangleFx4;
	float			m_Alpha;

	bool			m_bMouseMoveCheck;

	float			m_fGetCount;
public:
	CCredit(void)
	{
		m_fEffect =0.0f;
		
		m_stCamPos.m_fX = 0.0f;
		m_stCamPos.m_fY = 0.0f;
		m_stCamPos.m_fZ = 300.0f;
		m_ZRot = 0.0f;
		m_CountCheck = 1;
		m_bMouseMoveCheck	= false;
		
		m_Alpha =0.0f;

		m_fGetCount =0.0f;
		m_fTriangleFx = 0.0f;
		m_fTriangleFx2 = 20.0f;

		m_fTriangleFx3 = 10.0f;
		m_fTriangleFx4 = 10.0f;

		m_stStar.m_fX = -200.0f;
		m_stStar.m_fY = -230.0f;

		m_stStar2.m_fX = 20.0f;
		m_stStar2.m_fY = 0.0f;

	};
	virtual ~CCredit(void)
	{
	
	};
public:
	void	Particles				(stEMVec2 stPos,stdEMString sCommitName);
	void	fuck					(stMouseInfo	stPos);
	void	Init					();
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
	virtual void PostSolve			(const b2Contact* contact, const b2ContactImpulse* impulse);
};

