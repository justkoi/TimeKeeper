#pragma once

using namespace std;

typedef enum {
	E_IME_RIGHT = 0,
	E_IME_LEFT,
	E_IME_HOME,
	E_IME_END,
	E_IME_CURRENT,
} E_MOVEINDEX;

typedef enum{
	E_IME_COMP = 1,
	E_IME_RESULT,
	E_IME_RETURN,
	E_IME_DELETE,
} enumIME;

class CEMIme : public CEMImm
{
public:
	CEMIme();
	~CEMIme();

public:
	void		InitInput(CEMText* pFont, const char* pFontName, stEMRect& rt);

	/* messages */ 
	void		OnInputLanguageChange(HWND hWnd, WPARAM wParam, LPARAM lParam);
	bool		OnComposition(HWND hWnd, WPARAM wParam, LPARAM lParam);
	bool		OnEndComposition(HWND hWnd, WPARAM wParam, LPARAM lParam);
	bool		OnNotify(HWND hWnd, WPARAM wParam, LPARAM lParam);
	bool		OnChar(HWND hWnd, WPARAM wParam, LPARAM lParam);

	int			GetInput(char* text, int len);
	int			GetComp(char* text, int len);
		
	int			GetReading(char* text, int len);

	int			GetCandidate(DWORD index, char* text, int len);
	int			GetCandidateCount();
	int			GetCandidateSelection();
	int			GetCandidatePageSize();
	int			GetCandidatePageStart();
	void		GetUnderLine(int* start, int* end);

	/* property */ 
	bool		IsVerticalReading(){ return m_bVerticalReading; }
	bool		IsVerticalCandidate(){ return m_bVerticalCandidate; }
	WORD		GetCodePage() { return m_codePage; }
	LANGID		GetLangId() { return m_langId; }
	int			GetCharSet() { return GetCharsetFromLang(m_langId); }
	wchar_t*	GetIndicator() { return m_wszCurrIndicator; }
	IMPLEMENT_GET(int, ImeState);
	IMPLEMENT_GET(int, CurrentIndex);
	IMPLEMENT_SET_GET(bool, Password);
	IMPLEMENT_GET(std::wstring, String);
	IMPLEMENT_GET(std::wstring, wsPassword);
//	int			GetImeState() { return m_ImeState; }

	/*My Created*/ 
	void		Delete();
	int			Clear();

	const WCHAR*		GetInput();
	stdEMWString		GetComp();
	//stdEMWString		GetString();

	void MoveLeft();
	void MoveRight();
	void MoveEnd();
	void MoveHome();
	void Update();
	void		CheckToggleState(HWND hWnd);

protected:
	void		SetupImeApi(HWND hWnd);
	void		GetImeId();
	bool		GetReadingWindowOrientation();
	void		GetPrivateReadingString(HWND hWnd);

	int			ConvertString(UINT codePage, const wchar_t* wText, int wLen, char* text, int len);
	int			GetCharsetFromLang( LANGID langid );
	int			GetCodePageFromCharset( int charset );
	int			GetCodePageFromLang( LANGID langid );
	
	std::wstring		ReplaceAll(const std::wstring& source, const WCHAR* pReplace);

protected:
	HWND		m_hWnd;

	CEMText*			m_pFont;
	std::string			m_FontName;

	std::wstring		m_input;
	std::wstring		m_comp;
	std::wstring		m_wsPassword;
	std::wstring		m_String;
	bool				m_Password;
	bool				m_bOverFlow;
	//std::wstring		m_wsString;

	std::wstring		m_reading;
	std::vector<BYTE>	m_candidate;

	stEMRect			m_rtArea;

	int					m_ulStart;
	int					m_ulEnd;
	int					m_CurrentIndex;

	HKL					m_hkl;
	LANGID				m_langId;
	WORD				m_codePage;

	bool				m_bUnicodeIME;
	bool				m_bVerticalReading;
	bool				m_bVerticalCandidate;
	int					m_ImeState;
	wchar_t*			m_wszCurrIndicator;

	DWORD				m_dwId[2];

	HINSTANCE			m_hDllIme;

	CRITICAL_SECTION	m_csLock;

	UINT				(WINAPI * _GetReadingString)( HIMC, UINT, LPWSTR, PINT, BOOL*, PUINT );
	BOOL				(WINAPI * _ShowReadingWindow)( HIMC, BOOL );
};