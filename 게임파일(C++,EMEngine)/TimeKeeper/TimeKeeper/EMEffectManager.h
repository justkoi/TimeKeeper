#pragma once

#include "stdafx.h"
//=====================================================

/**
	@file    : < EMEffectManager >
	@author  : < ��뿬 >
	@version : < 0.1 >
	@brief   : < ����Ʈ�� STL LIST�� �߰��Ͽ� �����ִ� Ŭ���� �Դϴ�. >
 */


//=====================================================

class CEMEffectManager
{
public:
	CRootScene* m_pThisScene;			//!< ��� ��� ��
	list<CEMAnimation*> m_pEffectList;	//!< ��� ������� ����Ʈ ���� STL LIST

public:

	CEMEffectManager()
	{
		
	};
	~CEMEffectManager()
	{

	};
	//=====================================================
	/**
		@brief     : ����� ����Ʈ ���

		@param : ����Ʈ ��ȣ
		@param : ��� X��ǥ
		@param : ��� Y��ǥ
		@param : 
		@param : 

		@return : ����.
	*/
	//=====================================================
	void Insert(int nIndex, float fX, float fY, float fSizeW = 1.0f, float fSizeH = 1.0f);	
	//=====================================================
	/**
		@brief     : �ʱ�ȭ (��� ��� �� ����)

		@param : ��� ��� ��
		@param : 
		@param : 
		@param : 
		@param : 

		@return : ����.
	*/
	//=====================================================
	void Init(CRootScene* pThisScene);
	//=====================================================
	/**
		@brief     : ������Ʈ

		@param : �ǽð����� ����Ʈ ����� �Ϸ�� ����Ʈ�� �޸� ����
		@param : 
		@param : 
		@param : 
		@param : 

		@return : ����.
	*/
	//=====================================================
	void Update(float dt);
	//=====================================================
	/**
		@brief     : ���� ( ��� �޸� ����)

		@param : 
		@param : 
		@param : 
		@param : 
		@param : 

		@return : ����.
	*/
	//=====================================================
	void Exit();

	

};