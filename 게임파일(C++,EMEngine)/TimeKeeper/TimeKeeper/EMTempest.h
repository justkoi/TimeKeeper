#pragma once

#include "stdafx.h"

//=====================================================

/**
	@file    : < EMTempest >
	@author  : < 백노연 >
	@version : < 0.1 >
	@brief   : < 대상 Plane에 휘돌아오는 효과를 주는 클래스입니다. >
 */


//=====================================================
typedef enum
{
	E_TEMPE_TYPE_NORMAL,
	E_TEMPE_TYPE_TIMER,
}E_TEMPE_TYPE;
typedef struct
{
	E_TEMPE_TYPE m_eType;

	CEMPlane* m_pPlane;

	stEMVec2 m_stPos;
	stEMVec2 m_stTargetPos;

	float	m_fMoveSpeedX;
	float	m_fPlusSpeedX;
	float	m_fMoveSpeedY;
	float	m_fPlusSpeedY;

	bool	m_bPassed;
	bool	m_bFinished;

	bool	m_bDestroyFlag;

	float	m_fLifeTimer;
	float	m_fLifeTime;
}stTempe; //!< 템피라고 정의

class CEMTempest
{
private:
	CRootScene*		m_pThisScene; //!< 출력 대상 씬
	list<stTempe*> m_TempeList; //!< 템피 / 보관 리스트

public:

	void Init(CRootScene* pThisScene);
	void Update(float dt);
	void Exit();

public:

	void Insert(CEMPlane* pPlane, stEMVec2 stPos, stEMVec2 stTargetPos, float fMoveSpeedX, float fPlusSpeedX, float fMoveSpeedY, float fPlusSpeedY, bool bDestroyFlag);
	void Insert_Time(CEMPlane* pPlane, stEMVec2 stPos, float fLifeTime, float fMoveSpeedX, float fPlusSpeedX, float fMoveSpeedY, float fPlusSpeedY, bool bDestroyFlag);

public:


};