#pragma once
#include "stdafx.h"


class CStage : public CRootScene
{
public:
	
public:
	stEMVec3	m_stSmoothCamPos; //!< 스무스 카메라 위치 (실제보는화면)
	float		m_fFixZ;
	stEMVec2	m_stScreenMousePos;//!< 마우스 좌표 표시
	stEMVec2	m_stMousePos;//!< 마우스 좌표 표시
	//TwBar* m_pBar;			//!< 디버그용 바입니다
public:
	CMapTools m_MapTools;
public:
	CStage(void)
	{	
		
	};
	virtual ~CStage(void)
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