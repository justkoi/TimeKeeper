 #pragma once
// 
// #include "EMPhysicRoot.h"
// /**
// 	@file    : CEMPhysic.h
// 	@author  : wo
// 	@version : 1.2
// 	@date	 : 2012_1_25
// 	@brief   : Box2d관리 클래스입니다
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
// 	@brief CEMPhysicRoot 포인터 얻기
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
// 	@brief Box2D World포인터 얻기
// 	@return b2Body*
// 	*/
// 	b2World* GetWorldPt()	{ return m_pPhysic->m_world; }
// 
// 	/**
// 	@brief Box2D 물리 얻기
// 	@return CEMPhysicRoot*
// 	*/
// 	CEMPhysicRoot* GetPhysicPt()	{ return m_pPhysic; }
// 
// 	/**
// 	@brief Physic설정이 되어있는지.
// 	@return 설정/실패
// 	*/
// 	bool IsPhysic();
// 
// 	/**
// 		@brief 메모리 해제
// 		@return 없음
// 	*/
// 	void Release()
// 	{
// 		if(m_pPhysic)
// 			delete m_pPhysic;
// 	}
// 
// 	/**
// 	@brief Box2D를 시작합니다.
// 	@param stGravityVec : 중력위치 설정
// 	@return 성공/실패
// 	*/
// 	bool StartPhysic(stEMVec2 stGravityVec);
// 
// 	/**
// 	@brief physic 설정 정보(Settings)
// 	@param 
// 	@param 
// 	@return Setting
// 	*/
// 	Settings* GetSetInfo()					{ return &m_PhysicSetting; }
// 	void SetSettingInfo(Settings stSet)		{ m_PhysicSetting = stSet; }
// }; 