#pragma once

typedef struct ListEvent_tag
{
	virtual void CALLBACK OnEvent(int Step){}
} ListEvent;

enum BUTTONID{FRONT = 0, BACK};

class ListButton
{
private:
	enum BTSTATE{DEFAULT = 0, OVER, CLICK};

private:
	stEMVec3		m_vPos;
	stEMRect		m_rtRect;
	BTSTATE			m_State;
	ListEvent*		m_pEvent;

	bool			m_bMouse;
	stMouseInfo		m_vMouse;

	float			m_fTime;
	bool			m_bAuto;
	BUTTONID		m_id;

	CRITICAL_SECTION	m_csLock;
public:
	CEMPlane*		m_pButton[3];

public:
	ListButton(ListEvent* pList, BUTTONID id);
	~ListButton();

public:
	void Update(float dt);
	void Render();
	void MouseDownEvent (stMouseInfo stPos, enumMouseButton eButton);
	void MouseUpEvent	(stMouseInfo stPos, enumMouseButton eButton);
	void MouseMoveEvent (stMouseInfo stPos);

	void SetCoordinator(stEMVec3& vPos, bool bFlag);

	int SetTexture(stdEMString strDefault, stdEMString strOver, stdEMString strClick, stEMVec3& vPos, bool bFlag = true);
};

class CEMListBox : public ListEvent
{
private:
	CEMPlane* m_pPlane;
	stEMVec3 m_vPos;
	stEMVec3 m_vRender;
	stEMVec3 m_vIndex;
	stEMVec3 m_vParent;
	stEMRect m_rtArea;
	stEMRect m_rtArea2;

	bool		m_Disable;
	bool		m_Visible;

	int m_nButtonSize;
	float m_FontSize;				//!< 폰트 크기
	
	vector<CEMText*>	m_List;			//!< 추가된 문자의 list
	vector<ListButton*>	m_ListButton;	//!< list스크롤 버튼

	stdEMString m_sFontName;		//!< 폰트 이름

	int m_nCurrent;					//!< 현재 위치
	int m_nShowLimit;				//!< 보여 줄수 있는 한계 ( m_nCurrent + m_nShowLimit ) 하면 될껄?
	int m_nMaximum;					//!< 최대 추가할수 있는 수
	int m_nSize;					//!< list에 추가된 수


	CRITICAL_SECTION m_csLock;		//!< 임계영역

public:
	UINT m_id;						//!< 요놈 아이디

public:
	void Update(float dt);
	void Render();

	void MouseDownEvent (stMouseInfo stPos, enumMouseButton eButton);
	void MouseUpEvent	(stMouseInfo stPos, enumMouseButton eButton);
	void MouseMoveEvent (stMouseInfo stPos);

	void Clear();
	void Push(const char* cpInput, CEMColor& color = CEMColor(0.0f, 1.0f, 0.0f, 1.0f));
	void Push(stdEMString strInput, CEMColor& color = CEMColor(0.0f, 1.0f, 0.0f, 1.0f));
	void SetCoordinator(stEMVec3& vPos);

	bool Collision(stMouseInfo stPos);

	void AddButton(stdEMString default_1, stdEMString over_1, stdEMString click_1,
					stdEMString default_2, stdEMString over_2, stdEMString click_2);
	void SetFontSize(float FontSize);
	void SetMaxLine(int nMaximum);
	void SetDisable(bool bDisable);
	void SetVisible(bool bVisible);

	IMPLEMENT_GET(float, FontSize);
	IMPLEMENT_GET(bool, Disable);
	IMPLEMENT_GET(bool, Visible);

private:
	virtual void CALLBACK OnEvent(int Step);

public:
	CEMListBox(UINT id, const char* cpFontName, stEMVec3& vParent, stEMRect& rtRect, int nMaximum, float fFontSize);
	CEMListBox(UINT id, const char* cpFontName, const char* cpBoard, stEMVec3& vParent, stEMVec3& vPos, int nMaximum, float fFontSize);
	~CEMListBox();
};