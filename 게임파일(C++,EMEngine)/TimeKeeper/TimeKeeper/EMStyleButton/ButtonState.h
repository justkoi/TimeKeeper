#pragma once

class CButtonState
{
public:
	CButtonState(){};
	virtual ~CButtonState(){};
	
public:
	virtual void Enter(void*) = 0;					//!< ���º���� �ѹ��� ȣ��˴ϴ�
	virtual void Execute(void*, float fDt) = 0;		//!< ���º��������� ��� ȣ��˴ϴ�
	virtual void Exit(void*) = 0;					//!< �ٸ� ���·� �Ѿ������ �ѹ� ȣ��˴ϴ�

	virtual void Check_Down(void* pPt, stMouseInfo stPos, int nLayer) = 0;
	virtual void Check_Up(void* pPt, stMouseInfo stPos, int nLayer) = 0;
	virtual void Check_Move(void* pPt, stMouseInfo stPos, int nLayer) = 0;
};