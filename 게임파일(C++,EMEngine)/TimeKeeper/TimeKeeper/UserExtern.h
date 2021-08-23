#pragma once

//extern stEMVec2 g_stVirtualCamPos;
extern stEMVec3 g_stCamPos_Stage;
extern stEMVec3 g_stSmoothCamPos_Stage;
extern bool g_bChating;
extern bool g_bPause;
extern CInventory g_CInventory;
extern E_PAUSEWINDOW_BUTTON g_PauseWindowState;


extern int g_nEventLevel;
extern int g_nQuestLevel;
extern int g_nChatLevel;
extern int g_nConditionLevel;//!< 현재 해당되는 조건 레벨

extern float	g_SVolume;
extern bool		g_bSoundCheck;
extern bool		g_bEffectSoundCheck;
extern stEMVec2	m_stSoundGageXY;
extern stEMVec2	g_MousePosition;
extern float	g_fMouseX;
extern float	g_fMouseY;


extern CMapManager g_CMapManager;
extern CHero		g_CHero;
extern CChatWindow g_CChatWindow;