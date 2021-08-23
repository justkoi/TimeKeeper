#pragma once

#include "EM2DEngine.h"

class CEMWorld;

int EMOGL_Init(CEMOpenglCerate* pWinInfo, HICON hIcon);

//void EMOGL_WndProc(EMWndProc CallBack);

LRESULT CALLBACK EMOGL_WinProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);


//int EMOGL_WinMain(CEMOpenglCerate* pWinInfo);
int EMOGL_WinMain(CEMOpenglCerate* pWinInfo, HICON hIcon);
int EMOGL_MFCMain(CEMOpenglCerate* pWinInfo);
void EMOGL_Loop();
void EMOGL_Destroy(CEMOpenglCerate* pWinInfo);
void EMOGL_MFCDestroy();
void EMOGL_Resize( GLsizei nWidth, GLsizei nHeight);