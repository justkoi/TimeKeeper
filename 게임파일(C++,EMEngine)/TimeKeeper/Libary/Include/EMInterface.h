#pragma once

//#include "EMUIEvent.h"

class CEMWindow : public CEMUIEvent
{
private:
	typedef struct Texture
	{
		CEMPlane*	m_pPlane;
		stEMVec3	m_vPos;
		UINT		m_id;
		Texture(UINT id, CEMPlane* pPlane, stEMVec3& vPos)
		{
			m_pPlane = pPlane;
			m_vPos = vPos;
			m_id = id;
		}
		~Texture()
		{
			SAFE_DELETE(m_pPlane);
		}
	} Texture;

	typedef struct Animate
	{
		CEMAnimation*	m_pAnimate;
		stEMVec3		m_vPos;
		UINT			m_id;
		Animate(UINT id, CEMAnimation* pAni, stEMVec3& vPos)
		{
			m_pAnimate = pAni;
			m_vPos = vPos;
			m_id = id;
		}
		~Animate()
		{
			SAFE_DELETE(m_pAnimate);
		}
	} Animate;
private:
	CEMPlane*				m_pPlane;			//!< 윈도우 배경이미지
	CEMColor				m_Color;			//!< 윈도우 색상
	stdEMString				m_sWindowName;		//!< 윈도우 이름
	stdEMString				m_sBoardName;		//!< 윈도우 배경 이미지 이름(경로)
	stEMVec3				m_vPos;				//!< 윈도우 출력 좌표
	stEMVec3				m_vLimitPos;				//!< 윈도우 출력 좌표
	stEMVec3				m_vLabel;			//!< 라벨 좌표
	stEMVec3				m_vClick;			//!< 윈도우상 마우스 클릭 좌표
	stEMVec3				m_vLen;				//!< 마우스 클릭좌표와 윈도우 좌표의 차이
	stEMRect				m_rtRect;			//!< 윈도우 크기
	stEMRect				m_rtMove;			//!< 윈도우 움직을때 사용하는 충돌 영역
	stEMRect				m_rtWindow;			//!< 게임 윈도우 사이즈
	float					m_fWidth;			//!< 윈도우 가로
	float					m_fWidthHalf;		//!< 윈도우 가로의 반
	float					m_fHeight;			//!< 윈도우 높이
	float					m_fHeightHalf;		//!< 윈도우 높이의 반
	float					m_fArea;			//!< 윈도우 선택 높이
	bool					m_bDisable;			//!< 활성화 / 비활성화
	bool					m_bVisible;			//!< 화면상에 그려줄지 말지
	bool					m_bMouseClick;		//!< 윈도우상에서 마우스 클릭 
	bool					m_bFocus;			//!< 이윈도우가 선택 되면
	enumUserInterfaceType	m_eLock;			//!< 윈도우의 타입 (고정형 윈도우 / 이동형 윈도우)
	CEMText*				m_pLabel;			//!< 라벨 글씨

	typedef std::vector<CEMRadioButton*> RADIOBT;
	CEMWindow*				m_pParent;
	//typedef std::pair<UINT, CEMPlane*> stdTexturPair;

	std::map<UINT, RADIOBT>		m_RadioButton;
	std::vector<Texture*>		m_Plane;
	std::vector<Animate*>		m_Animate;
	std::vector<CEMButton*>		m_Button;
	//std::vector<CEMButton2*>	m_Button2;
	std::vector<CEMCheckBox*>	m_CheckBox;
	std::vector<CEMStatic*>		m_Static;
	std::vector<CEMEditBox*>	m_EditBox;
	std::vector<CEMListBox*>	m_ListBox;
	std::vector<CEMWindow*>		m_window;

	std::vector<CEMWindow*>::iterator itrw;
	std::map<UINT, RADIOBT>::iterator	itrrbt;
	std::vector<Texture*>::iterator		itrpl;
	std::vector<Animate*>::iterator		itrani;
	std::vector<CEMButton*>::iterator	itrbt;
	//std::vector<CEMButton2*>::iterator	itrbt2;
	std::vector<CEMCheckBox*>::iterator itrcb;
	std::vector<CEMStatic*>::iterator	itrst;
	std::vector<CEMEditBox*>::iterator	itreb;
	std::vector<CEMListBox*>::iterator	itrlb;

public:
	void Update			(float dt);											//!< Update
	void Render			();													//!< Render
	void MouseDownEvent (stMouseInfo stPos, enumMouseButton eButton);		//!< 마우스 다운 이벤트
	void MouseUpEvent	(stMouseInfo stPos, enumMouseButton eButton);		//!< 마우스 업 이벤트
	void MouseMoveEvent (stMouseInfo stPos);								//!< 마우스 이동 이벤트
	HRESULT WinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

public:
	stEMVec3 GetPos(){return m_vPos;}
	void SetCoordinator	(stEMVec3& vPos);
	/**
	@brief 
	@param 
	@return 윈도우에서 마우스를 클릭 했는지 여부 (true / false)
	*/
	bool GetMouseClick();
	/**
	@brief 윈도우 활성화 상태
	@param 
	@return 활성화 false/ 비활성화 true
	*/
	bool GetDisable();
	/**
	@brief 윈도우 선택 상태
	@param 
	@return 선택 true/ 비선택 false
	*/
	bool GetFocus();
	/**
	@brief 윈도우 show 상태
	@param 
	@return 보여줌 true/ 안보여줌 false
	*/
	bool GetVisible();
	/**
	@brief 마우스와 윈도우 충돌 여부
	@param 마우스 x
	@param 마우스 y
	@return 충돌 true/ 비충돌 false
	*/
	bool Collision(int x, int y);
	/**
	@brief 윈도우 크기
	@param 
	@return 윈도우 크기를 리턴
	*/
	RECT& GetRect();
	/**
	@brief 윈도우 이름
	@param 
	@return 윈도우 이름을 리턴
	*/
	const char* GetWindowName();
	/**
	@brief 윈도우 출력 좌표 설정
	@param stEMVec3
	@return 없음
	*/
	void SetPos(stEMVec3& vPos);
	/**
	@brief 윈도우 상태 설정
	@param bool
	@return 없음
	*/
	void SetDisable(bool bDisable);
	/**
	@brief 윈도우 출력 상태 설정
	@param bool
	@return 없음
	*/
	void SetVisible(bool bVisible);
	/**
	@brief 윈도우 라벨을 설정
	@param const char* 폰트이름
	@param stEMVec3 출력할 좌표
	@param float 폰트의 크기 ( 기본 24 에서의 배율 입니다. )
	@return 없음
	*/
	void SetLabel(const char* cpFontName, stEMVec3& vPos, float fSize = 1.0f);
	/**
	@brief 윈도우 배경 색상 지정
	@param CEMColor ( r, g, b, a ) 0.0f ~ 1.0f입니다.
	@return 없음
	*/
	void SetColor(CEMColor& color);
	/**
	@brief 윈도우 배경이미지 변경
	@param const char* 변경할 이미지 경로를 넣어면 됩니다.
	@return 없음
	*/
	void SetBoard(const char* cpBardName);
	/**
	@brief 윈도우를 선택 한다고 설정 합니다.
	@param bool
	@return 없음
	*/
	void SetFocus(bool bFocus);
	/**
	@brief 윈도우의 타입 (고정형 윈도우 / 이동형 윈도우)
	@param enumUserInterfaceType ( E_DYNAMIC / E_STATIC )
	@return 없음
	*/
	void SetLock(enumUserInterfaceType eType);
	/**
	@brief 윈도우를 클릭 & 드레그 하는 부분을 셋팅하는 함수 
	@param 0보다 작거나 같으면 윈도우 전체를 사용 한다는 뜻, 현재 좌표에서 픽셀 단위로 크기 조정
	@return 없음
	*/
	void SetMoveArea(float fArea = -1);
	/**
	@brief 윈도우가 움직일수 있는 영역을 셋팅하는 함수
	@param 영역갑을 셋팅합니다. ~~ 기본은 현재 게임윈도우 크기로 설정 됨니다.
	@return 없음
	*/
	void SetMoveLimit(stEMRect& rt);

public:
	void AddWindow(const char* pWindowName, stEMRect& rt, CEMColor& color = CEMColor(1.0f, 1.0f, 1.0f, 1.0f));
	void AddWindow(const char* pWindowName, const char* pBoard, stEMVec3& vPos, CEMColor& color = CEMColor(1.0f, 1.0f, 1.0f, 1.0f));
	CEMWindow* GetWindow(const char* pWindowName);
	/**
	@brief 윈도우에 버튼 추가
	@param 버튼의 ID
	@param default 이미지 경로
	@param over 이미지 경로
	@param click 이미지 경로
	@param 그려질 봐표 (부모( CEMWindow ) 에 상대 좌표 입니다.)
	@return 없음
	*/
	void AddButton(UINT id, const char* cpDefault, const char* cpOver, const char* cpClick, stEMVec3& vPos);
	//void AddButton2(UINT id, const char* cpTexture, stEMVec3& vPos);
	//void AddAniButton(UINT id, CEMAnimation* pDefault, CEMAnimation* pOver, CEMAnimation* pClick, stEMVec3& vPos);

	/**
	@brief 윈도우에 라디오버튼 추가
	@param 라디오 버튼의 그룹
	@param 버튼의 ID
	@param default 이미지 경로
	@param over 이미지 경로
	@param click 이미지 경로
	@param 그려질 봐표 (부모( CEMWindow ) 에 상대 좌표 입니다.)
	@return 없음
	*/
	void AddRadioButton(UINT group, UINT id, const char* cpDefault, const char* cpOver, const char* cpCheck, stEMVec3& vPos, bool bCheck = false);
	/**
	@brief 윈도우에 채크버튼 추가
	@param 라디오 버튼의 그룹
	@param 버튼의 ID
	@param default 이미지 경로
	@param over 이미지 경로
	@param click 이미지 경로
	@param 그려질 봐표 (현재 윈도우에 상대 좌표 입니다.)
	@return 없음
	*/
	void AddCheckBox(UINT id, const char* cpDefault, const char* cpOver, const char* cpCheck, stEMVec3& vPos, bool bCheck = false);
	//void AddAniCheckBox(UINT id, CEMAnimation* pDefault, CEMAnimation* pOver, CEMAnimation* pCheck, stEMVec3& vPos, bool bCheck = false);
	/**
	@brief 윈도우에 static 추가
	@param static의 ID
	@param 폰트 이름
	@param 출력 문자
	@param 출력 좌표
	@param 폰트 크기
	@param 폰트 색상
	@return 없음
	*/
	void AddStatic(UINT id, const char* cpFontName, const char* cpString, stEMVec3& vPos, float fSize  = 1.f, CEMColor& color = CEMColor(1.f, 1.f, 1.f, 1.f));

	void AddTexture(UINT id, const char* cpFileName, stEMVec3& vPos);
	//void AddAnimate(UINT id, CEMAnimation* pAni, stEMVec3& vPos);

	void AddEditBox(UINT id, const char* cpFontNmae, stEMRect& rtArea, float fSize = 1.0f);

	void AddListBox(UINT id, const char* cpFontName, stEMRect& rtRect, float fFontSize = 1.f, UINT nMaximum = 256);
	void AddListBox(UINT id, const char* cpFontName, const char* cpBoard, stEMVec3& vPos, float fFontSize = 1.f, UINT nMaximum = 256);

	CEMListBox* GetListBox(UINT id);

	CEMEditBox* GetEditBox(UINT id);

	CEMPlane* GetTexture(UINT id);

	/**
	@brief 현재 윈도우에서 id 에 해당하는 static을 가져온다
	@param 등록한 id중에서 찾음
	@return CEMButton*
	*/
	CEMStatic* GetStatic(UINT id);
	/**
	@brief 현재 윈도우에서 id 에 해당하는 버튼을 가저온다...
	@param 등록한 id중에서 찾음
	@return CEMButton*
	*/
	CEMButton* GetButton(UINT id);
	/**
	@brief 현재 윈도우에서 id 에 해당하는 라디오버튼을 가저온다...
	@param 등록한 group에서 찾음
	@param 등록한 id중에서 찾음
	@return CEMRadioButton*
	*/
	CEMRadioButton* GetRadioButton(UINT group, UINT id);
	/**
	@brief 현재 윈도우에서 id 에 해당하는 채크박스을 가저온다...
	@param 등록한 id중에서 찾음
	@return CEMCheckBox*
	*/
	CEMCheckBox* GetCheckBox(UINT id);

private:
	/**
	@brief 템플릿에 해당하는 dialog의 id가 중복되는지여부 채크
	@param iterator의 begin 값
	@param iterator의 end 값
	@param 추가할 id
	@return 등록된 id면 false / 미등록된 id면 true
	*/
	template <class T> bool Overlap(T begin_, T end_, UINT id);
	template <class T> bool Overlap(T begin_, T end_, const char* pName);
	/**
	@brief 해당하는 id값의 *를 이턴 합니다.
	@param iterator의 begin 값
	@param iterator의 end 값
	@param 찾아낼 id
	@return void*
	*/
	template <class D> void* GetDialog(D begin_, D end_, UINT id);
	template <class D> void* GetDialog(D begin_, D end_, const char* pName);

	CEMAnimation* SetAni(CEMAnimation* pAni);

private:
	CEMWindow(const char* cpWindowName, stEMRect& rtRect, UIEvent* pUIEvent, CEMWindow* pParent, CEMColor& color = CEMColor(43, 111, 113, 150));
	CEMWindow(const char* cpWindowName, const char* cpBoard, stEMVec3& vPos, UIEvent* pUIEvent, CEMWindow* pParent, CEMColor& color = CEMColor(1.f, 1.f, 1.f, 1.f));

public:
	CEMWindow(const char* cpWindowName, const char* cpBoard, stEMVec3& vPos, UIEvent* pUIEvent, CEMColor& color = CEMColor(1.f, 1.f, 1.f, 1.f));
	CEMWindow(const char* cpWindowName, stEMRect& rtRect, UIEvent* pUIEvent, CEMColor& color = CEMColor(43, 111, 113, 150));
	~CEMWindow();
};
