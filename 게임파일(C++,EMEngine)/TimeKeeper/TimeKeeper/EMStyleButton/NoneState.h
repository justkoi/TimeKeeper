#pragma once

#include "stdafx.h"

class CNoneState : public CButtonState
{
private:
	CNoneState(){};
	SOUND_HANDLE m_SoundButtonFp;

public:
	static CNoneState* Instance();
	virtual ~CNoneState(){};

	virtual void Enter(void*);					//!< ���º���� �ѹ��� ȣ��˴ϴ�
	virtual void Execute(void*, float fDt);		//!< ���º��������� ��� ȣ��˴ϴ�
	virtual void Exit(void*);					//!< �ٸ� ���·� �Ѿ������ �ѹ� ȣ��˴ϴ�
	
	virtual void Check_Down(void* pPt, stMouseInfo stPos, int nLayer);
	virtual void Check_Up(void* pPt, stMouseInfo stPos, int nLayer);
	virtual void Check_Move(void* pPt, stMouseInfo stPos, int nLayer);
};