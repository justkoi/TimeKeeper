#pragma once

/**
	@file    : EMObject.h
	@author  : wo
	@version : 1.0f
	@brief   : 최상의 클래스입니다.
			   CEMPlane, CEMText...등등에서 상속 받아 사용됨
 */
class CEMObject
{
	friend class CEMWorld;

protected:
	bool	m_bDeleteMe;	//!< 지워졌는지 아닌지를 파악
	int		m_nLayer;		//!< 오브젝트가 속한 레이어구분
	bool	m_bShow;		//!< 화면에 보여줄지 말지를 결정
	bool	m_bFrustumShow;	//!< 프러스텀 컬링시 보여줄지 말지 결정하는 함수

	POINT	m_bCenterPoint;	//!< 오브젝트 출력 중점 좌표 저장 변수

public:
	CEMObject()
	{
		m_bCenterPoint.x = 0;
		m_bCenterPoint.y = 0;

		m_bDeleteMe = false;
		m_bShow	= true;
		m_bFrustumShow = true;
	};

	virtual ~CEMObject()
	{
		
	};

	virtual void Update(float dt){};
	virtual void UpdatePhysic(){};
	virtual void Render(){};
	virtual void CalcPos(){};
	virtual void PreDestroy(){};

public:

	/**
	@brief : 삭제 하는 함수입니다
			 이 함수안에서 직접 동적 메모리할당한 것들을 Delete해주는 것이 아니라
			 m_bDeleteMe 라는 곳에 true를 넣어줘서, 지워달라는 값만 넣어주는 것입니다
			 그러면 엔진 내부에서 IsDestroy()함수를 호출하여 true면 엔진내부에서 delete 해줍니다

	@return : 리턴
	*/
	void Destroy()
	{
		if(IsDestroy())
			return;

		PreDestroy();

		m_bDeleteMe = true;
	}


	/**
	@brief : 삭제 하는 함수입니다
			 이 함수안에서 직접 동적 메모리할당한 것들을 Delete해주는 것이 아니라
			 m_bDeleteMe 라는 곳에 true를 넣어줘서, 지워달라는 값만 넣어주는 것입니다
			 그러면 엔진 내부에서 IsDestroy()함수를 호출하여 true면 엔진내부에서 delete 해줍니다.

	@return : true/false   
	*/
	bool IsDestroy()	{return m_bDeleteMe;}

	/**
	@brief : 레이어 번호 얻기
	@param : 
	@return : 레이어 번호
	*/	
	int GetLayer()		{return m_nLayer;}

	/**
	@brief : 레이어 번호 넣기
	@param int nLayer : 레이어
	@return 없음
	*/	
	void SetLayer(int nLayer) {m_nLayer = nLayer;}

	/**
	@brief 보여줄지 말지를 설정
	@param bool bShow : true면 화면에 출력합니다.
	@return 없음
	*/	
	void SetShow(bool bShow)		{m_bShow = bShow;}

	/**
	@brief 보여줄지 말지를 설정(프러스텀 컬링시)
	@param bool bShow : true면 화면에 출력합니다.
	@return 없음
	*/	
 	void SetFrustumShow(bool bFShow)		{m_bFrustumShow = bFShow;}
 	bool GetFrustumShow()					{return m_bFrustumShow;}
// 	

	/**
	@brief 현재 Show 상태를 얻어온다.
	@return 
	*/	
	bool GetShow()					{return m_bShow;}



};