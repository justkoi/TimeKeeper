#pragma once

class CEMCheckBox : public CEMUIEvent
{
private:
	enum CHECKBOXSTATE { RELEASE = 0, HIGHLIGHT, CHECK };
	enum BUTTONSOUND {CLICK = 0, OVER };

private:
	std::vector<CEMPlane*>	m_Plane;				//!< 버튼의 이미지들을 담아 놓는 vector
	//std::vector<CEMAnimation*>	m_Animate;			//!< 버튼의 애니메이션들을 담아 놓는 vector

	stdEMString				m_sParentName;			//!< 현재 버튼의 window이름
	
	stEMVec3				m_vPos;					//!< 부모(CEMWindow)에 대하여 상대 좌표
	stEMVec3				m_vParent;				//!< 부모 좌표
	stEMVec3				m_vRender;				//!< 실질적으로 그려지는 좌표
	
	CHECKBOXSTATE			m_eButtonState;			//!< 버튼의 상태
	
	bool					m_bDisable;				//!< 활성화 비활성화
	bool					m_bVisible;				//!< 화면상에 그려줄지 말지
	bool					m_bOvered;				//!< 버튼위에 마우스가 있는지 유무
	
	float					m_fWidth;				//!< 버튼의 가로 길이
	float					m_fWidthHalf;			//!< 버튼가로 길이의 절반
	float					m_fHeight;				//!< 버튼의 세로 길이
	float					m_fHeightHalf;			//!< 버튼세로 길이의 절반

	stEMRect				m_rtRect;				//!< 버튼의 크기
	
	SAMPLE_HANDLE			m_shSound[2];			//!< 버튼 효과음

	enumRenderType 			m_eRenderType;			//!< 그려주는 방식

public:
	UINT					m_id;					//!< 체크박스의 id 

public:
	void Update			(float dt);											//!< Update
	void Render			();													//!< Render
	void MouseDownEvent (stMouseInfo stPos, enumMouseButton eButton);		//!< 마우스 다운 이벤트
	void MouseUpEvent	(stMouseInfo stPos, enumMouseButton eButton);		//!< 마우스 업 이벤트
	void MouseMoveEvent (stMouseInfo stPos);								//!< 마우스 이동 이벤트

public:
	/**
	@brief 윈도우가 움직이면 버튼도 같이 움직이게 하는 함수
	@param stEMVec3& 위도우 이동 좌표
	@return 없음
	*/
	void SetCoordinator(stEMVec3& vPos);
	/**
	@brief 현재 버튼의 좌표를 변경합니다.
	@param stEMVec3& 변경할 좌표( 부모 ) 윈도우에 대하여 상대 좌표 입니다.
	@return 없음
	*/
	void SetPos(stEMVec3& vPos);
	/**
	@brief 현재 버튼의 좌표얻어 와요
	@param bool true(현재 그려지는좌표)/ false(부모에 대하여 상대 좌표)
	@return stEMVec3 넘겨진 flag값에 따라 리턴 값이 달라집니다.
	*/
	stEMVec3 GetPos(bool bFlag = true);
	/**
	@brief 버튼의 오버사운드와 클릭사운드를 셋팅해준다.
	@param const char*  클릭사운드의 경로,
	@param const char*  오버사운드의 경로,
	@return 없음
	*/
	void SetSound	(const char* cpClick = NULL, const char* cpOver = NULL);
	/**
	@brief 버튼 상태를 설정( 활성화 / 비활성화 )
	@param bool 상태값
	@return 없음
	*/
	void SetDisable	(bool bDisable);
	/**
	@brief 버튼이 보여지는지 여부를 셋팅 (보여지는 상태 true / 안보이는 상태 false)
	@param bool 상태값
	@return 없음
	*/
	void SetVisible	(bool bVisible);
	/**
	@brief 체크박스 선택상태로 변경
	@param bool (선택 : true / 해제 : false)
	@return 없음
	*/
	void SetSelected(bool bSelected);
	/**
	@brief 현재 버튼의 활성화/ 비활성화 상태를 얻어오는 함수
	@param 
	@return bool (비활성화 true / 활성화 false)
	*/
	bool GetDisable	();
	/**
	@brief 버튼의 render상태를 얻어오는 함수
	@param 
	@return bool (보여지면 true / 안보이면 false)
	*/
	bool GetVisible	();
	/**
	@brief 해당 체크박스가 선택되어있는지 유무
	@param 
	@return (선택됨 true / 선택 안됨 false)
	*/
	bool GetSelected();
	/**
	@brief 마우스와 출동 유무를 알아 내는 함수
	@param 마우스 x 값
	@param 마우스 y 값
	@return (충돌 true / 비 충돌 false)
	*/
	bool Collision	(int x, int y);

protected:
	CEMPlane* Create(const char* cpTexture, stEMVec3& vPos);

public:
	CEMCheckBox(UINT id, const char* cpParent, const char* cpDefault, const char* cpOver, const char* cpCheck, stEMVec3& vPos, stEMVec3& vParent, UIEvent* pUIEvent, bool bCheck = false);
	//CEMCheckBox(UINT id, const char* cpParent, CEMAnimation* pDefault, CEMAnimation* pOver, CEMAnimation* pCheck, stEMVec3& vPos, stEMVec3& vParent, UIEvent* pUIEvent, bool bCheck = false);
	~CEMCheckBox();
};