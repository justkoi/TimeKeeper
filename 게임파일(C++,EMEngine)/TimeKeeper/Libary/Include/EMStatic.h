#pragma once

class CEMStatic
{
private:
	enum INDEX {SHADOW = 0, STRING};
private:
	stEMVec3			m_vRender;				//!<실질적으러 그려지는 좌표
	stEMVec3			m_vString;				//!< 부모 (CEMWindow)에 대한 상대 좌표 출력 문자
	stEMVec3			m_vShadow;				//!< 부모 (CEMWindow)에 대한 상대 좌표 그림자
	stEMVec3			m_vParent;

	CEMColor			m_Color;				//!< 출력 문자 색
	CEMColor			m_ShadowColor;			//!< 그림자 색

	bool				m_bDisable;				//!< 활성화(false) 비활성화(true)
	bool				m_bVisible;				//!< render유무 (true 그린다 / false 안그린다.)

	float				m_fShadowGap;			//!< 출력문자열과 그림자의 간격

	stEMRect			m_Space;				//!< 출력 공간

	float				m_fSize;

	std::vector<CEMText*> m_Table;
	std::vector<CEMText*>::iterator itr;

public:
	UINT				m_id;

public:
	void Render			();													//!< Render

public:
	/**
	@brief static 상태를 설정( 활성화 / 비활성화 )
	@param bool 상태값
	@return 없음
	*/
	void SetDisable(bool bDisable);
	/**
	@brief static 보여지는지 여부를 셋팅 (보여지는 상태 true / 안보이는 상태 false)
	@param bool 상태값
	@return 없음
	*/
	void SetVisible(bool bVisible);
	/**
	@brief 출력 문자열 셋팅
	@param 출력할 문자열
	@param 문자열 색상
	@param 그림자 색상
	@return 없음
	*/
	void SetText(const char* cpString, CEMColor& Color = CEMColor(1.f, 1.f, 1.f, 1.f), CEMColor& ShadowColor = CEMColor(0.f, 0.f, 0.f, 1.f));
	/**
	@brief 출력 문자열 셋팅
	@param 출력할 문자열
	@param 문자열 색상
	@param 그림자 색상
	@return 없음
	*/
	void SetText(const stdEMString str, CEMColor& Color = CEMColor(1.f, 1.f, 1.f, 1.f), CEMColor& ShadowColor = CEMColor(0.f, 0.f, 0.f, 1.f));
	/**
	@brief 출력 색상 셋팅
	@param 문자열 색상
	@return 없음
	*/
	void SetColor(CEMColor& Color = CEMColor(1.f, 1.f, 1.f, 1.f));
	/**
	@brief 출력 문자열의 그림자 셋팅
	@param 그림자 색상
	@param 출력 문자열과 그림자의 간격
	@return 없음
	*/
	void SetShadow(CEMColor& Color = CEMColor(0.f, 0.f, 0.f, 1.f), float fGap = 2.0f);
	/**
	@brief 출력 좌표 셋팅
	@param 좌표값
	@return 없음
	*/
	void SetCoordinator(stEMVec3& vPos);
	void SetFormat(DWORD Format = E_TEXT_LEFT);

public:
	CEMStatic(UINT id, const char* cpFontName, const char* cpString, stEMVec3& vPos, stEMVec3& vParent, CEMColor& color, float fSize = 1.f);
	CEMStatic(UINT id, const char* cpFontName, const char* cpString, stEMRect& rt, stEMVec3& vParent, CEMColor& color, DWORD Format = E_TEXT_LEFT, float fSize = 1.f);
	~CEMStatic();

};