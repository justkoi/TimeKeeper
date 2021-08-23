#pragma once

typedef enum numberstyle
{
	E_NUMSTYLE_BASIC,		//!< �⺻ ���	(�⺻ ���� ����Դϴ�)
}eEMNumStyle;

/**
	@file    : CEMNumber.h
	@author  : wo
	@version : 1.0f
	@brief   : ���� ��� ���� Ŭ����

   [���� �����]
		1. 

 */
class CEMNumber : public CEMAnimation
{
private:
	stdEMString	m_stNumber;				//!< ���ڸ� ���ڷ� ��ȯ�Ͽ� ����(�Է��� ���� ����� �˾ƺ��� ���� ���
	int			m_nArraryTemp[100];		//!< �ӽ� �����
	float		m_fYPosTemp[100];		//!< Y������ �̵��� �� ����
	float		m_fAlphaCtlr[100];		//!< ���İ� ��Ʈ��

	int 		m_nNumberSize;			//!< ���� ũ��
	int 		m_nNumberTemp;			//!< �ӽ� �����
	int 		m_nArraryNum;			//!< ���ȣ

private:
	int			m_nOutPutNumber;		//!< ���� ����� ���� ���� ����
	eEMNumStyle	m_nOUtPutStyle;			//!< ������ ��Ÿ�� eNumStyle�����ϻ�

	float		m_fElapsedTime;			//!< Render���� ����� ����ð� ���� ����
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