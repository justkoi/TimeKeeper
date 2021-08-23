
#pragma once

#include "stdafx.h"
//=====================================================

/**
	@file    : < CEMTextDisplay >
	@author  : < ��뿬 >
	@version : < 0.1 >
	@brief   : < �ؽ�Ʈ�� �������� �ɼ��� �־� �����ִ� Ŭ���� �Դϴ�. >
 */

//!< '/' �� �� ������� ����
//=====================================================

class CEMTextDisplay
{
public:

	CRootScene* m_pThisScene; //!< Commit�� �� ����

	stdEMString m_String;	//!< �� �ؽ�Ʈ ����
	stdEMString m_NowString; //!< ���� �ؽ�Ʈ ����
	stdEMString m_ViewString; //!< �����ִ� �ؽ�Ʈ ���� (�ѱ��� ��� �ڿ� ?���� ������ �̻��ϰ� ���̴� ���� ����)

	stdEMString m_stdFont; //!< ��Ʈ ����
	stdEMString m_stdName; //!< Commit�� ���� �̸� ����

	list<CEMText*> m_pTextList; //!< ��� ���� �ؽ�Ʈ�� ����Ʈ�� ����

	int			m_nMaxChar; //!< ���ڰ��� �ִ�
	int			m_nNowChar; //!< ���� ���� ����

	float		m_fProgressTime; //!< �ϳ��ϳ��� ���� ���� �ð�
	float		m_fNowProgressTime; //!< ���� ��� ���� '�ϳ��ϳ��� ���� ���� �ð�'

	int			m_nOffsetSpace; //!< �ѱ��� �ƴѰ���� ���� ��� ���� ����

	int			m_nLineMaxChar; //!< �� �ִ����
	int			m_nLineHeight; //!< �� ����
	int			m_nNowLineMaxChar; //!< �� �ִ����
	int			m_nNowLine; //!< ���� �� ��

	bool		m_nLineChanged; //!< ���� ���ŵȰ�� ǥ��
	int			m_nLineWidth_Basic; //!< �⺻ �� ����
	int			m_nHangulLevel; //!< 0�� ��� �ѱ� �ϼ�, 1�� ��� �ѱ� �̿ϼ� ǥ��.

	bool		m_bSkip; //!< Skip���ϰ�� true, �ƴҰ�� false
	bool		m_bFastView;//!< FastView���ϰ�� true, �ƴҰ�� false
	bool		m_bPause;//!< �Ͻ�����

	stEMVec2	m_stSize; //!< ���� ũ��
	stEMVec2	m_stPos; //!< ��� ��ǥ ����
	CEMColor	m_Color; //!<���� ��
	
	void DestroyText(); //!< ���� ���ο����� ����

public:

	CEMTextDisplay()
	{
		
	};
	~CEMTextDisplay()
	{

	};
	
	void SetShow(bool bShow);
	
	void Init(CRootScene* pThisScene, stdEMString stdName, float fX, float fY, int nLineWidth, int nLineHeight, stEMVec2 stSize, CEMColor Color, stdEMString stdFont = "����ü", bool Ortho2D = true);
	void Update(float dt);
	void Exit();

	void SetText(stdEMString String);
	void SetProgressTime(float fProgressTime);
	void Skip();

	bool IsViewing();

	void SetFastView(bool bFastView = true);
	void SetPause(bool bPause = true);
	
	bool GetFastView();
	bool GetPause();

	void NextLine();


	/// �߰� ����

	/*
	void SetLineHeight();
	

	*/
	

};