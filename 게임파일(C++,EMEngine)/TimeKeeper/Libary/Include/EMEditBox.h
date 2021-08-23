#pragma once

class CEMEditBox : public CEMIme
{
private:
	bool m_Disable;
	bool m_Focus;
	bool m_Visible;

	stdEMString m_sText;				//!< �������� comp�� ������ ���ڿ�(��Ƽ ����Ʈ)
	stdEMWString m_wsText;				//!< ȭ�鿡 ��µ� ���ڿ�
	stdEMString m_sFontName;			//!< ��µ� ��Ʈ�� �̸�

	CEMPlane* m_pTyping;				//!< �ѿ� ����̹���
	vector<stdEMString> m_vsTyping;		//!< �̹��� �̸�
	
	CEMColor m_Color;					//!< ���� ��
	
	float m_Size;						//!< ��Ʈ ũ��

	stEMVec3 m_vPos;					//!< ��� ��ǥ
	stEMRect m_rtArea;					//!< ��� ����
	stEMRect m_rtRender;				//!< �������� ��� ���� ( window + vpos )
	stEMRect m_rtCurrent;				//!< ��� ���� ���ڿ��� ����
	
	CEMText* m_pFont;
	//CEMIme m_Ime;

	float m_fCursorTime;				//!< Ŀ���� ������ �ӵ�
	bool m_bCursor;						//!< Ŀ�� �������� ó���ϴ� ���� ( ��� �ߴ� ���ߴ�.)
	bool m_bStartComp;
	bool m_bTypingMode;					//!< ���� Ÿ���θ����� ����

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
	@brief define�Լ� Disable�� Get�� Set�Լ�������� �� Get�Լ��϶��� return��� Set�Լ��϶��� ���� ���
	@param �����Ϸ��� ����
	@return ���� ����
	*/
	IMPLEMENT_SET_GET(bool, Focus);
	IMPLEMENT_SET_GET(bool, Visible);
	IMPLEMENT_GET(bool, Disable);
	IMPLEMENT_GET(float, Size);
	IMPLEMENT_GET(CEMColor, Color);

	//IMPLEMENT_SET(CEMColor&, Color);
	
	/**
	@brief �ѿ� ���¸� ��ȯ �մϴ�.
	@param 
	@return �ѱ� ���� �϶� ( 1 ) / ���� �϶� ( 0 )
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