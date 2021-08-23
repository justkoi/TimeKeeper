#pragma once

class CEMImm
{
private:
	CRITICAL_SECTION m_csLock;

public:
	CEMImm();
	virtual ~CEMImm();

public:
	void			Init();
	INPUTCONTEXT*	LockIMC(HIMC hImc);
	BOOL			UnlockIMC(HIMC hImc);
	LPVOID			LockIMCC( HIMCC );
	BOOL			UnlockIMCC( HIMCC );

protected:
	HINSTANCE			m_hDllImm32;

protected:
	INPUTCONTEXT*	(WINAPI * _ImmLockIMC)( HIMC );
	BOOL			(WINAPI * _ImmUnlockIMC)( HIMC );
	LPVOID			(WINAPI * _ImmLockIMCC)( HIMCC );
	BOOL			(WINAPI * _ImmUnlockIMCC)( HIMCC );
};