#pragma once
#include "stdafx.h"


class CLogo : public CRootScene
{
public:
	
public:
	
	stEMVec3	m_stCamPos;	//!< ī�޶� ��ġ ���� ����

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