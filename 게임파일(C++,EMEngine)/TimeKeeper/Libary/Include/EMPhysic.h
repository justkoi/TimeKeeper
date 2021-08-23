 #pragma once
// 
// #include "EMPhysicRoot.h"
// /**
// 	@file    : CEMPhysic.h
// 	@author  : wo
// 	@version : 1.2
// 	@date	 : 2012_1_25
// 	@brief   : Box2d���� Ŭ�����Դϴ�
//  */
// class CEMPhysic
// {
// private:
// 	CEMPhysic()
// 	{
// 		m_pPhysic = NULL;
// 	};
// 
// 	CEMPhysicRoot*	m_pPhysic;
// 	Settings		m_PhysicSetting;
// 
// public:
// 	virtual ~CEMPhysic(void)
// 	{
// 		/*DeleteAllBody();*/
// 	};
// 	static CEMPhysic* Instance();
// 
// public:
// 	/**
// 	@brief CEMPhysicRoot ������ ���
// 	@return CEMPhysicRoot*
// 	*/
// 	CEMPhysicRoot*	GetPt()		
// 	{
// 		if(m_pPhysic) 
// 			return m_pPhysic; 
// 		else 
// 			return NULL;
// 	}
// 
// 	/**
// 	@brief Box2D World������ ���
// 	@return b2Body*
// 	*/
// 	b2World* GetWorldPt()	{ return m_pPhysic->m_world; }
// 
// 	/**
// 	@brief Box2D ���� ���
// 	@return CEMPhysicRoot*
// 	*/
// 	CEMPhysicRoot* GetPhysicPt()	{ return m_pPhysic; }
// 
// 	/**
// 	@brief Physic������ �Ǿ��ִ���.
// 	@return ����/����
// 	*/
// 	bool IsPhysic();
// 
// 	/**
// 		@brief �޸� ����
// 		@return ����
// 	*/
// 	void Release()
// 	{
// 		if(m_pPhysic)
// 			delete m_pPhysic;
// 	}
// 
// 	/**
// 	@brief Box2D�� �����մϴ�.
// 	@param stGravityVec : �߷���ġ ����
// 	@return ����/����
// 	*/
// 	bool StartPhysic(stEMVec2 stGravityVec);
// 
// 	/**
// 	@brief physic ���� ����(Settings)
// 	@param 
// 	@param 
// 	@return Setting
// 	*/
// 	Settings* GetSetInfo()					{ return &m_PhysicSetting; }
// 	void SetSettingInfo(Settings stSet)		{ m_PhysicSetting = stSet; }
// }; 