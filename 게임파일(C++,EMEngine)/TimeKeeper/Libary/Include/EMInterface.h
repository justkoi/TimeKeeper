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
	CEMPlane*				m_pPlane;			//!< ������ ����̹���
	CEMColor				m_Color;			//!< ������ ����
	stdEMString				m_sWindowName;		//!< ������ �̸�
	stdEMString				m_sBoardName;		//!< ������ ��� �̹��� �̸�(���)
	stEMVec3				m_vPos;				//!< ������ ��� ��ǥ
	stEMVec3				m_vLimitPos;				//!< ������ ��� ��ǥ
	stEMVec3				m_vLabel;			//!< �� ��ǥ
	stEMVec3				m_vClick;			//!< ������� ���콺 Ŭ�� ��ǥ
	stEMVec3				m_vLen;				//!< ���콺 Ŭ����ǥ�� ������ ��ǥ�� ����
	stEMRect				m_rtRect;			//!< ������ ũ��
	stEMRect				m_rtMove;			//!< ������ �������� ����ϴ� �浹 ����
	stEMRect				m_rtWindow;			//!< ���� ������ ������
	float					m_fWidth;			//!< ������ ����
	float					m_fWidthHalf;		//!< ������ ������ ��
	float					m_fHeight;			//!< ������ ����
	float					m_fHeightHalf;		//!< ������ ������ ��
	float					m_fArea;			//!< ������ ���� ����
	bool					m_bDisable;			//!< Ȱ��ȭ / ��Ȱ��ȭ
	bool					m_bVisible;			//!< ȭ��� �׷����� ����
	bool					m_bMouseClick;		//!< ������󿡼� ���콺 Ŭ�� 
	bool					m_bFocus;			//!< �������찡 ���� �Ǹ�
	enumUserInterfaceType	m_eLock;			//!< �������� Ÿ�� (������ ������ / �̵��� ������)
	CEMText*				m_pLabel;			//!< �� �۾�

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
	void MouseDownEvent (stMouseInfo stPos, enumMouseButton eButton);		//!< ���콺 �ٿ� �̺�Ʈ
	void MouseUpEvent	(stMouseInfo stPos, enumMouseButton eButton);		//!< ���콺 �� �̺�Ʈ
	void MouseMoveEvent (stMouseInfo stPos);								//!< ���콺 �̵� �̺�Ʈ
	HRESULT WinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

public:
	stEMVec3 GetPos(){return m_vPos;}
	void SetCoordinator	(stEMVec3& vPos);
	/**
	@brief 
	@param 
	@return �����쿡�� ���콺�� Ŭ�� �ߴ��� ���� (true / false)
	*/
	bool GetMouseClick();
	/**
	@brief ������ Ȱ��ȭ ����
	@param 
	@return Ȱ��ȭ false/ ��Ȱ��ȭ true
	*/
	bool GetDisable();
	/**
	@brief ������ ���� ����
	@param 
	@return ���� true/ ���� false
	*/
	bool GetFocus();
	/**
	@brief ������ show ����
	@param 
	@return ������ true/ �Ⱥ����� false
	*/
	bool GetVisible();
	/**
	@brief ���콺�� ������ �浹 ����
	@param ���콺 x
	@param ���콺 y
	@return �浹 true/ ���浹 false
	*/
	bool Collision(int x, int y);
	/**
	@brief ������ ũ��
	@param 
	@return ������ ũ�⸦ ����
	*/
	RECT& GetRect();
	/**
	@brief ������ �̸�
	@param 
	@return ������ �̸��� ����
	*/
	const char* GetWindowName();
	/**
	@brief ������ ��� ��ǥ ����
	@param stEMVec3
	@return ����
	*/
	void SetPos(stEMVec3& vPos);
	/**
	@brief ������ ���� ����
	@param bool
	@return ����
	*/
	void SetDisable(bool bDisable);
	/**
	@brief ������ ��� ���� ����
	@param bool
	@return ����
	*/
	void SetVisible(bool bVisible);
	/**
	@brief ������ ���� ����
	@param const char* ��Ʈ�̸�
	@param stEMVec3 ����� ��ǥ
	@param float ��Ʈ�� ũ�� ( �⺻ 24 ������ ���� �Դϴ�. )
	@return ����
	*/
	void SetLabel(const char* cpFontName, stEMVec3& vPos, float fSize = 1.0f);
	/**
	@brief ������ ��� ���� ����
	@param CEMColor ( r, g, b, a ) 0.0f ~ 1.0f�Դϴ�.
	@return ����
	*/
	void SetColor(CEMColor& color);
	/**
	@brief ������ ����̹��� ����
	@param const char* ������ �̹��� ��θ� �־�� �˴ϴ�.
	@return ����
	*/
	void SetBoard(const char* cpBardName);
	/**
	@brief �����츦 ���� �Ѵٰ� ���� �մϴ�.
	@param bool
	@return ����
	*/
	void SetFocus(bool bFocus);
	/**
	@brief �������� Ÿ�� (������ ������ / �̵��� ������)
	@param enumUserInterfaceType ( E_DYNAMIC / E_STATIC )
	@return ����
	*/
	void SetLock(enumUserInterfaceType eType);
	/**
	@brief �����츦 Ŭ�� & �巹�� �ϴ� �κ��� �����ϴ� �Լ� 
	@param 0���� �۰ų� ������ ������ ��ü�� ��� �Ѵٴ� ��, ���� ��ǥ���� �ȼ� ������ ũ�� ����
	@return ����
	*/
	void SetMoveArea(float fArea = -1);
	/**
	@brief �����찡 �����ϼ� �ִ� ������ �����ϴ� �Լ�
	@param �������� �����մϴ�. ~~ �⺻�� ���� ���������� ũ��� ���� �ʴϴ�.
	@return ����
	*/
	void SetMoveLimit(stEMRect& rt);

public:
	void AddWindow(const char* pWindowName, stEMRect& rt, CEMColor& color = CEMColor(1.0f, 1.0f, 1.0f, 1.0f));
	void AddWindow(const char* pWindowName, const char* pBoard, stEMVec3& vPos, CEMColor& color = CEMColor(1.0f, 1.0f, 1.0f, 1.0f));
	CEMWindow* GetWindow(const char* pWindowName);
	/**
	@brief �����쿡 ��ư �߰�
	@param ��ư�� ID
	@param default �̹��� ���
	@param over �̹��� ���
	@param click �̹��� ���
	@param �׷��� ��ǥ (�θ�( CEMWindow ) �� ��� ��ǥ �Դϴ�.)
	@return ����
	*/
	void AddButton(UINT id, const char* cpDefault, const char* cpOver, const char* cpClick, stEMVec3& vPos);
	//void AddButton2(UINT id, const char* cpTexture, stEMVec3& vPos);
	//void AddAniButton(UINT id, CEMAnimation* pDefault, CEMAnimation* pOver, CEMAnimation* pClick, stEMVec3& vPos);

	/**
	@brief �����쿡 ������ư �߰�
	@param ���� ��ư�� �׷�
	@param ��ư�� ID
	@param default �̹��� ���
	@param over �̹��� ���
	@param click �̹��� ���
	@param �׷��� ��ǥ (�θ�( CEMWindow ) �� ��� ��ǥ �Դϴ�.)
	@return ����
	*/
	void AddRadioButton(UINT group, UINT id, const char* cpDefault, const char* cpOver, const char* cpCheck, stEMVec3& vPos, bool bCheck = false);
	/**
	@brief �����쿡 äũ��ư �߰�
	@param ���� ��ư�� �׷�
	@param ��ư�� ID
	@param default �̹��� ���
	@param over �̹��� ���
	@param click �̹��� ���
	@param �׷��� ��ǥ (���� �����쿡 ��� ��ǥ �Դϴ�.)
	@return ����
	*/
	void AddCheckBox(UINT id, const char* cpDefault, const char* cpOver, const char* cpCheck, stEMVec3& vPos, bool bCheck = false);
	//void AddAniCheckBox(UINT id, CEMAnimation* pDefault, CEMAnimation* pOver, CEMAnimation* pCheck, stEMVec3& vPos, bool bCheck = false);
	/**
	@brief �����쿡 static �߰�
	@param static�� ID
	@param ��Ʈ �̸�
	@param ��� ����
	@param ��� ��ǥ
	@param ��Ʈ ũ��
	@param ��Ʈ ����
	@return ����
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
	@brief ���� �����쿡�� id �� �ش��ϴ� static�� �����´�
	@param ����� id�߿��� ã��
	@return CEMButton*
	*/
	CEMStatic* GetStatic(UINT id);
	/**
	@brief ���� �����쿡�� id �� �ش��ϴ� ��ư�� �����´�...
	@param ����� id�߿��� ã��
	@return CEMButton*
	*/
	CEMButton* GetButton(UINT id);
	/**
	@brief ���� �����쿡�� id �� �ش��ϴ� ������ư�� �����´�...
	@param ����� group���� ã��
	@param ����� id�߿��� ã��
	@return CEMRadioButton*
	*/
	CEMRadioButton* GetRadioButton(UINT group, UINT id);
	/**
	@brief ���� �����쿡�� id �� �ش��ϴ� äũ�ڽ��� �����´�...
	@param ����� id�߿��� ã��
	@return CEMCheckBox*
	*/
	CEMCheckBox* GetCheckBox(UINT id);

private:
	/**
	@brief ���ø��� �ش��ϴ� dialog�� id�� �ߺ��Ǵ������� äũ
	@param iterator�� begin ��
	@param iterator�� end ��
	@param �߰��� id
	@return ��ϵ� id�� false / �̵�ϵ� id�� true
	*/
	template <class T> bool Overlap(T begin_, T end_, UINT id);
	template <class T> bool Overlap(T begin_, T end_, const char* pName);
	/**
	@brief �ش��ϴ� id���� *�� ���� �մϴ�.
	@param iterator�� begin ��
	@param iterator�� end ��
	@param ã�Ƴ� id
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
