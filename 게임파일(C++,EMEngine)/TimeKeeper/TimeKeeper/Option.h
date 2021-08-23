#pragma once

#include "stdafx.h"

/*
	1. ���� �Ⱥ��� Plane
		- ������ ���� �ʾ����Ƿ� �浹 ����� ����ڰ� ���� ������մϴ�
*/
class COption : public CRootScene
{
public:
	TwBar* m_pBar;			//!< ����׿� ���Դϴ�

public:
	CEMText*		m_pText;	//!< �������
	CEMPlane*		m_pPlane;	//!< Plane ���
	CEMAnimation*	m_MouseAni;
	CEMParticle*	m_MouseParticle;

	CEMPlane*		m_OptionImage;
	CEMPlane*		m_SoundPlus;
	CEMPlane*		m_SoundMinus;
	CEMPlane*		m_SoundGage;
	CEMPlane*		m_pEffectSound;
	CEMPlane*		m_pVolumeControl;
	CEMPlane*		m_pBackButton;

	stEMVec3	m_stCamPos;	//!< ī�޶� ��ġ ���� ����
	stEMVec3	m_stHeroXY;
	
	SOUND_HANDLE	m_SHandle;

public:
	int			m_nRand;

	float		m_fRot;		
	float		m_fSize;
	float		m_fTTime;
	float		m_fTime;
	
	float		m_fPassTime;
	float		m_fAllPassTime;

	float		m_fAllTime;
	float		m_fAlpha;
	float		m_fEAlpha;
	bool		m_bState;
	float		m_fGageSize;

	bool		VolumeClick;
	bool		m_bEffectVolume;
	bool		m_bMouseMoveCheck;

public:
	COption(void)
	{	
		m_pPlane = NULL;
		
		m_fRot = 0.0f; 
		m_fSize = 3.0f;
		m_fTTime = 0;
		m_fAlpha = 1;
		m_bState = false;
		m_fGageSize = 3.2f;
		VolumeClick = false;
		m_bMouseMoveCheck = false;
		m_bEffectVolume = false;

		m_stCamPos = stEMVec3(0.0f, 3.0f,300.0f);
	};
	virtual ~COption(void)
	{
		
	};

public:
	void	fuck					(stMouseInfo	stPos);
	void	Particles				(stEMVec2 stPos,stdEMString sCommitName);
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