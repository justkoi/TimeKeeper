#pragma once
#include "stdafx.h"


class CLogo : public CRootScene
{
public:
	
public:
	
	stEMVec3	m_stCamPos;	//!< 카메라 위치 저장 벡터

public:

public:
	CLogo(void)
	{	
		m_stCamPos = stEMVec3(0.0f, 3.0f,D_CAM_Z_FIXED);
	};
	virtual ~CLogo(void)
	{
		
	};

public:
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