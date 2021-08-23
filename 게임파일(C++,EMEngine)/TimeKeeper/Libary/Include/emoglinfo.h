#pragma once

typedef struct createwininfo
{
	int	m_nXPos;
	int	m_nYPos;
	int	m_nWidth;
	int	m_nHeight;
	char* m_pWinName;
}ST_CREATEINFO;

class CEMOpenglCerate
{
public:
	WNDCLASSEX		m_WinClass;
	HINSTANCE		m_hInst;
/*	MSG				m_uMsg;*/
	HWND			m_hWnd;
	//EMWndProc		m_WndProc;
	ST_CREATEINFO	m_stWinInfo;
	bool			m_bFullScreen;
	HDC				m_hDC;
	HGLRC			m_hRC;

	


	GLuint			m_unPixelFormat;
	DWORD			m_dwExStyle;			
	DWORD			m_dwStyle;

	int				m_nCnt;			// m_hWnds °³¼ö 
	HWND			m_hWnds[10];
	HDC				m_hDCs[10];
	HGLRC			m_hRCs[10];


public:
	//CEMOGLInfo(HINSTANCE hInst);
	CEMOpenglCerate(char* pWinName, HINSTANCE hInst, int nStartXpos, int nStartYpos, int nWidth, int nHeight, bool bFullScreen);
	CEMOpenglCerate()
	{
		memset(&m_WinClass, 0, sizeof(WNDCLASSEX));
		m_hInst = NULL;
		m_hWnd = NULL;
		memset(&m_stWinInfo, 0, sizeof(ST_CREATEINFO));
		m_bFullScreen = false;
		m_hDC = NULL;
		m_hRC = NULL;
		m_unPixelFormat = 0;	
		m_dwExStyle = 0;	
		m_dwStyle = 0;			

		ZeroMemory(m_hWnds, sizeof(HWND)*10);
		ZeroMemory(m_hDCs, sizeof(HWND)*10);
		ZeroMemory(m_hRCs, sizeof(HWND)*10);
		m_nCnt = 0;
	};
	~CEMOpenglCerate()
	{
// 		DeleteObject(m_hBitmap);			// Delete The Device Dependant Bitmap Object
// 		DrawDibClose(m_hdd);				// Closes The DrawDib Device Context
// 		AVIStreamGetFrameClose(m_pgf);		// Deallocates The GetFrame Resources
// 		AVIStreamRelease(m_pavi);			// Release The Stream
// 		AVIFileExit();						// Release The File
	};

public:
	void SetInfo( char* pWinName, int nStartXpos, int nStartYpos, int nWidth, int nHeight, bool bFullScreen);

public:
	HINSTANCE			 GetHinstance()		{return m_hInst;}
	HWND				 GetHWND()			{return m_hWnd;}
	const ST_CREATEINFO* GetWinInfo()		{return &m_stWinInfo;}
	//EMWndProc			GetWndProc()		{return m_WndProc;}
	
};