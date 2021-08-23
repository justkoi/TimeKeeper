#pragma once

typedef enum numberstyle
{
	E_NUMSTYLE_BASIC,		//!< 기본 출력	(기본 숫자 출력입니다)
}eEMNumStyle;

/**
	@file    : CEMNumber.h
	@author  : wo
	@version : 1.0f
	@brief   : 숫자 출력 관리 클래스

   [구현 방법론]
		1. 

 */
class CEMNumber : public CEMAnimation
{
private:
	stdEMString	m_stNumber;				//!< 숫자를 문자로 변환하여 저장(입력한 숫자 몇개인지 알아보기 위한 방법
	int			m_nArraryTemp[100];		//!< 임시 저장소
	float		m_fYPosTemp[100];		//!< Y축으로 이동할 놈 누적
	float		m_fAlphaCtlr[100];		//!< 알파값 컨트롤

	int 		m_nNumberSize;			//!< 숫자 크기
	int 		m_nNumberTemp;			//!< 임시 저장소
	int 		m_nArraryNum;			//!< 방번호

private:
	int			m_nOutPutNumber;		//!< 실제 출력할 숫자 저장 변수
	eEMNumStyle	m_nOUtPutStyle;			//!< 랜더링 스타일 eNumStyle참조하삼

	float		m_fElapsedTime;			//!< Render에서 사용할 경과시간 저장 변수
	float		m_fCalcCurTime;				

public:
	CEMNumber(int nPlans);
	virtual ~CEMNumber(void){};
	
public:
	int GetNumber()								{return m_nOutPutNumber;}
	void SetNumber(int nNumber);

	eEMNumStyle GetNumberStyle()				{return m_nOUtPutStyle;}
	void SetStyle(eEMNumStyle enumStyle)		{m_nOUtPutStyle = enumStyle;}

public:
	virtual void SetTime(float fTime)			{m_fAniTimeCtrl = fTime;}
	virtual void Update(float dt);
	virtual void Render();
	virtual const stdEMString GetClassName()	{ return "CEMNumber"; }


};