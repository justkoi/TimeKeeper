#pragma once
#include "stdafx.h"


class CStage : public CRootScene
{
public:
	
public:
	stEMVec3	m_stSmoothCamPos; //!< ������ ī�޶� ��ġ (��������ȭ��)
	float		m_fFixZ;
	stEMVec2	m_stScreenMousePos;//!< ���콺 ��ǥ ǥ��
	stEMVec2	m_stMousePos;//!< ���콺 ��ǥ ǥ��
	//TwBar* m_pBar;			//!< ����׿� ���Դϴ�
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