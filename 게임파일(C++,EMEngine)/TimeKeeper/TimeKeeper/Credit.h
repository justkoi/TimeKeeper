#pragma once

#include "stdafx.h"
class CCredit: public CRootScene
{
public:
	TwBar* m_pBar;	
public:
	CEMText*		m_pText;	//!< 글자출력
	CEMPlane*		m_pPlane;	//!< Plane 출력
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
	virtual void PostSolve			(const b2Contact* contact, const b2ContactImpulse* impulse);
};

