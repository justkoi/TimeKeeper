#pragma once

class CEMEditBox : public CEMIme
{
private:
	bool m_Disable;
	bool m_Focus;
	bool m_Visible;

	stdEMString m_sText;				//!< 문자조함 comp를 제외한 문자열(멀티 바이트)
	stdEMWString m_wsText;				//!< 화면에 출력될 문자열
	stdEMString m_sFontName;			//!< 출력될 폰트의 이름

	CEMPlane* m_pTyping;				//!< 한영 출력이미지
	vector<stdEMString> m_vsTyping;		//!< 이미지 이름
	
	CEMColor m_Color;					//!< 글자 색
	
	float m_Size;						//!< 폰트 크기

	stEMVec3 m_vPos;					//!< 출력 좌표
	stEMRect m_rtArea;					//!< 출력 영역
	stEMRect m_rtRender;				//!< 실질적인 출력 영역 ( window + vpos )
	stEMRect m_rtCurrent;				//!< 출력 중인 문자열의 영역
	
	CEMText* m_pFont;
	//CEMIme m_Ime;

	float m_fCursorTime;				//!< 커서의 깜빡임 속도
	bool m_bCursor;						//!< 커서 깜빡임을 처리하는 변수 ( 출력 했다 안했다.)
	bool m_bStartComp;
	bool m_bTypingMode;					//!< 현재 타이핑모드출력 유무

	int m_nCurrsorPos;
	int m_nLimite;

	CRITICAL_SECTION m_csLock;

public:
	UINT m_id;

public:
	CEMEditBox(UINT id, const char* cpFontName, stEMRect& rtArea, stEMVec3& vParent, float fSize);
	~CEMEditBox();

public:
	void Update		(float dt);											//!< Update
	void Render		();													//!< Render
	HRESULT WinProc	(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

public:
	/**
	@brief define함수 Disable의 Get과 Set함수를만들어 줌 Get함수일때는 return사용 Set함수일때는 인자 사용
	@param 변경하려는 상태
	@return 현재 상태
	*/
	IMPLEMENT_SET_GET(bool, Focus);
	IMPLEMENT_SET_GET(bool, Visible);
	IMPLEMENT_GET(bool, Disable);
	IMPLEMENT_GET(float, Size);
	IMPLEMENT_GET(CEMColor, Color);

	//IMPLEMENT_SET(CEMColor&, Color);
	
	/**
	@brief 한영 상태를 반환 합니다.
	@param 
	@return 한글 상태 일때 ( 1 ) / 영문 일때 ( 0 )
	*/
	int GetMode();

	void SetDisable(bool bDisable);
	void SetSize(float fSize);
	void SetColor(CEMColor& color);
	void SetCoordinator(stEMVec3& vPos);
	void SetPassWord(bool bPassword);
	void SetShowState(bool bState);
	void SetTyping(stdEMString sEng, stdEMString sKor);

	const stdEMString GetTextA();
	const stdEMWString GetTextW();

	void Clear();

protected:
	void 				RednerCursor(stdEMWString str);
	void 				MultiToWideChar(const stdEMString strOutPut, stdEMWString* wstrOutput);
	void 				WideCharToMulti(const stdEMWString wstrOutput, stdEMString* strOutPut);
	void 				RenderLayout(stEMRect rt);
};