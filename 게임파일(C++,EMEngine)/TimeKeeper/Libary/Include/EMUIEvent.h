#pragma once

//#include "EMString.h"


enum enumDialogType
{
	E_BUTTON				= 0,
	E_RADIO_BUTTON,
	E_CHECK_BOX,
};

enum enumUserInterfaceType
{
	E_DYNAMIC				= 0,
	E_STATIC,
};

enum enumListboxScrollBarType
{
	E_SB_LEFT			= 0,
	E_SB_RIGHT,
};

enum enumRenderType
{
	E_RT_LEFT_TOP			= 0,
 	E_RT_RIGHT_TOP,
 	E_RT_LEFT_BOTTOM,
 	E_RT_RIGHT_BOTTOM,
	E_RT_CENTER,
};

typedef struct UIEvent_tag
{
	virtual void CALLBACK OnEvent(stdEMString sWindowName, enumDialogType eType, UINT id){}
} UIEvent;

class CEMUIEvent
{
private:
	UIEvent*			m_pUserInterfaceEvent;

public:
	CEMUIEvent(){m_pUserInterfaceEvent = NULL;}
	virtual ~CEMUIEvent(){m_pUserInterfaceEvent = NULL;}

public:
	virtual void SetUserInterfaceEvent( UIEvent* pWindowEvent )
	{
		m_pUserInterfaceEvent		= pWindowEvent;
	}
	virtual UIEvent* GetUserInterfaceEvent()
	{
		return m_pUserInterfaceEvent;
	}
};

#ifndef	SAFE_SOUND
	#define	SAFE_SOUND(p)			{if(p) {D_SOUND->Play(p);}}
#endif
#ifndef	SAFE_SOUND_LOOP
	#define	SAFE_SOUND_LOOP(p)		{if(p) {D_SOUND->Play(p, 1.0f, true);}}
#endif

#ifndef SAFE_DELETE
	#define SAFE_DELETE(p)			{if(p) {delete (p);     (p)=NULL;}}
#endif

#ifndef SAFE_DELETE_ARRAY
	#define SAFE_DELETE_ARRAY(p)	{if(p) {delete[] (p);     (p)=NULL;}}
#endif

#ifndef SAFE_DELETE_ANIMATE
	#define SAFE_DELETE_ANIMATE(p)	{if(p) {(p)->PlaneRelease(); delete (p);   (p)=NULL;}}
#endif

#ifndef SAFE_WINDOWMSG
#define SAFE_WINDOWMSG(p)			{if(p) {msg = (p)->WinProc(hWnd, msg, wParam, lParam);}}
#endif

class EMLock
{
private:
	CRITICAL_SECTION*		m_csLock;


public:
	EMLock(CRITICAL_SECTION* csLock)	{m_csLock = csLock; EnterCriticalSection(m_csLock);}
	~EMLock()							{LeaveCriticalSection(m_csLock); m_csLock = (CRITICAL_SECTION*)0;}
};
class EMUnLock
{
private:
	CRITICAL_SECTION*		m_csLock;


public:
	EMUnLock(CRITICAL_SECTION* csLock)	{m_csLock = csLock; LeaveCriticalSection(m_csLock);}
	~EMUnLock()							{EnterCriticalSection(m_csLock); m_csLock = (CRITICAL_SECTION*)0;}
};

#define IMPLEMENT_SET(x, y)	void Set##y(x t) {EMLock cLock(&m_csLock); m_##y = t;};
#define IMPLEMENT_GET(x, y)	x Get##y() {EMLock cLock(&m_csLock); return m_##y;};
#define	IMPLEMENT_SET_GET(x, y)	IMPLEMENT_SET(x, y) IMPLEMENT_GET(x, y)
#define	IMPLEMENT_GET_SET(x, y)	IMPLEMENT_SET(x, y) IMPLEMENT_GET(x, y)

#define IMPLEMENT_PSET(x, y)	void Set##y(x t) {EMLock cLock(&m_csLock); m_p##y = t;};
#define IMPLEMENT_PGET(x, y)	x Get##y() {EMLock cLock(&m_csLock); return m_p##y;};
#define	IMPLEMENT_PSET_PGET(x, y)	IMPLEMENT_PSET(x, y) IMPLEMENT_PGET(x, y)
#define	IMPLEMENT_PGET_PSET(x, y)	IMPLEMENT_PSET(x, y) IMPLEMENT_PGET(x, y)

#define IMPLEMENT_SET_NOLOCK(x, y)	void Set##y(x t) {m_##y = t;};
#define IMPLEMENT_GET_NOLOCK(x, y)	x Get##y() {return m_##y;};
#define	IMPLEMENT_SET_GET_NOLOCK(x, y)	IMPLEMENT_SET_NOLOCK(x, y) IMPLEMENT_GET_NOLOCK(x, y)
#define	IMPLEMENT_GET_SET_NOLOCK(x, y)	IMPLEMENT_SET_NOLOCK(x, y) IMPLEMENT_GET_NOLOCK(x, y)

#define IMPLEMENT_PSET_NOLOCK(x, y)	void Set##y(x t) {m_p##y = t;};
#define IMPLEMENT_PGET_NOLOCK(x, y)	x Get##y() {return m_p##y;};
#define	IMPLEMENT_PSET_PGET_NOLOCK(x, y)	IMPLEMENT_PSET_NOLOCK(x, y) IMPLEMENT_PGET_NOLOCK(x, y)
#define	IMPLEMENT_PGET_PSET_NOLOCK(x, y)	IMPLEMENT_PSET_NOLOCK(x, y) IMPLEMENT_PGET_NOLOCK(x, y)

#define	IMPLEMENT_VSET(x, y)	virtual void Set##y(x t) {};
#define	IMPLEMENT_VGET(x, y)	virtual x Get##y() {return NULL;};
#define IMPLEMENT_VSET_VGET(x, y)	IMPLEMENT_VSET(x, y) IMPLEMENT_VGET(x, y)
#define IMPLEMENT_VGET_VSET(x, y)	IMPLEMENT_VSET(x, y) IMPLEMENT_VGET(x, y)

#define	IMPLEMENT_LOCK		EMLock cLock(&m_csLock);
#define	IMPLEMENT_UNLOCK	EMUnLock cLock(&m_csLock);