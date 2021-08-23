#pragma once


//!==============================================================
//! ����Ŭ����
//!==============================================================
#define D_WORLD		CEMWorld::Instance()			//!< ���� ����
#define D_SCENE		CSceneWork::Instance()			//!< �� ���� ����
#define D_CAMERA	CEMCamera::Instance()			//!< ī�޶� ����
#define D_INPUT		CEMInput::Instance()			//!< Ű���� or ���콺
#define D_SOUND		CEMSound::Instance()			//!< ���� ����
#define D_SOUNDMNG	CSoundMNG::Instance()			//!< ���� ����
#define D_DEBUG		CDebugLogOutput::Instance()		//!< ����� ��Ʃ����� ���â���� ����� ������ ��µ˴ϴ�. 
#define D_FRUSTUM	CEMFrustum::Instance()			//!< �������� ����
//#define D_PHYSIC	CEMPhysic::Instance()			//!< �翬 ������������^^
 
#define D_MAX_LOG_LENGTH 1024						//!< �α� ���� ����
#define D_ANTWEAKBAR								//!< antweakbar�� ����ϰ� �ʹٸ� �ּ��� �����ϼ���

#define GLFW_DLL									//!< �̰� �� ����� GLFW��� ���� �մϴ� ^^ �����ϻ�
#define ILUT_USE_OPENGL								//!< Devil���� �־�����մϴ�
#undef  _UNICODE

#define D_MAX_Z	-50000.0f
#define D_MAX_VALUE 99999

#define D_MAX_TOOLCAMERA	10

#define NULL		0								//!< Definition of NULL keyword
#define FORCE_DWORD	0x7fffffff						//!< Force dword to 4 bytes in enum

//!==============================================================
//! ����� 
//!==============================================================
#pragma warning(disable:4244)		
#pragma warning(disable:4005)						//! #include <windows.h> �߰��ó����� warring
#pragma warning(disable:4996)						//!< MLog.cpp(15) : warning C4996: 'vsprintf'��(��) deprecated�� ����Ǿ����ϴ�.
#pragma warning(disable:4129)						//!< warning C4129: ' ' : ���� �̽������� �������� �ν��� �� �����ϴ�.
//#pragma warning(disable:4309)														//!< warning C4309: '�ʱ�ȭ ��' : ��� ���� �߸��ϴ�.
#pragma warning(disable:4819)						//!< warning C4819: ���� �ڵ� ������(949)���� ǥ���� �� ���� ���ڰ� ���Ͽ� ��� �ֽ��ϴ�. �����Ͱ� �սǵ��� �ʰ� �Ϸ��� �ش� ������ �����ڵ� �������� �����Ͻʽÿ�.
#pragma warning(disable:4482)						//!< warning C4482: ��ǥ�� Ȯ���� ���Ǿ����ϴ�. ����ȭ�� �̸��� 'b2Shape::Type' �������� ����߽��ϴ�.
//#include <cximage/ximage.h>

#ifdef _DEBUG
	#pragma comment(lib, "../Libary/lib/EMEngine3_d.lib") 
	#pragma comment(lib, "../Libary/lib/OGL_Core_d.lib") 
	//#pragma comment(lib, "../Libary/lib/cximagecrtd.lib")
#else
	#pragma comment(lib, "../Libary/lib/EMEngine3.lib") 
	#pragma comment(lib, "../Libary/lib/OGL_Core_r.lib") 
	//#pragma comment(lib, "../Libary/lib/cximagecrt.lib")
#endif


#pragma comment(lib, "../Libary/lib/AntTweakBar.lib") 
#pragma comment(lib, "../Libary/lib/Box2D.lib") 
#pragma comment(lib, "../Libary/lib/DevIL.lib") 
#pragma comment(lib, "../Libary/lib/fmodex_vc.lib") 
#pragma comment(lib, "../Libary/lib/freetype237.lib") 
#pragma comment(lib, "../Libary/lib/ftgl_static_MT.lib") 
#pragma comment(lib, "../Libary/lib/glfwdll.lib") 
#pragma comment(lib, "../Libary/lib/glut32.lib") 
#pragma comment(lib, "../Libary/lib/ILU.lib") 
#pragma comment(lib, "../Libary/lib/ILUT.lib") 
#pragma comment(lib, "../Libary/lib/OpenGL32.lib") 

//DevIL.lib ILU.lib ILUT.lib glut32.lib opengl32.lib glu32.lib AntTweakBar.lib fmodex_vc.lib glfwdll.lib freetype237.lib ftgl_static_MT.lib box2d.lib OGL_Core_r.lib EMEngine3.lib Version.lib Imm32.lib odbc32.lib odbccp32.lib
//!==============================================================
//! Include
//!==============================================================
// extern "C" {
// #include "lua.h"
// #include "lualib.h"
// #include "lauxlib.h"
// }

//!==============================================================
//! typedef 
//!==============================================================


//!==============================================================
//! extern
//!==============================================================


	
#pragma comment(lib, "Vfw32.lib")
#pragma comment(lib, "comctl32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "imm32.lib")
#pragma comment(lib, "version.lib")			//! Visual Studio 2010���� ���� ���� ���� ���� �����Ϸ��� �߰�������մϴ�.

#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>
// #include <conio.h>
// #include <afxwin.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <direct.h>
#include <assert.h>
#include <malloc.h>
#include <time.h>
#include <io.h>
#include <limits.h>
#include <float.h>
#include <shellapi.h>
#include <commdlg.h>
#include <string.h>
#include <tchar.h>
#include <vfw.h>
#include <imm.h>
#include <cmath> 
#include <cstdlib>

/*												*/ 
#include <assert.h>					//! ������
#include <objbase.h>				//! ������
#include <dimm.h>					//! ������
/*												*/ 
#include <process.h>
#include <digitalv.h>
#include <Mmsystem.h>
#include <exdisp.h>
#include <comdef.h> 
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <list>				//!< ������ list�߰� �߾��
#include <math.h>
#include <time.h>
#include <AntTweakBar.h>
//#include <luabind/luabind.hpp>
#include "gl/glfw.h"
#include "gl/glext.h"
#include "IL/il.h"
#include "IL/ilu.h"
#include "IL/ilut.h"

//! ���� ���� Ŭ���� �߰���
#include "EMMathBase.h"
#include "EMMat4x4.h"
#include "EMMat3x3.h"
#include "EMVec3.h"
#include "EMVec4.h"
#include "EMAxisAngle.h"
#include "EMEulerAngles.h"
#include "EMQuaternion.h"
#include "EMSphericalRotation.h"



#include "EMFrameSkip.h"
#include "EMOglInfo.h"
#include "EMOglCore.h"

#include "EMLog.h"
#include "EMSound.h"
#include "FTFont.h"
#include "FTGLTextureFont.h"
#include "EMInput.h"
#include "EMTexture.h"
#include "EMColor.h"
#include "EMObject.h"
#include "EMGrid.h"
#include "EMPhysic.h"
#include "EMPhysicRoot.h"
#include "EMMatrix3x3.h"
#include "EMMatrix4x4.h"
#include "EMPlane.h"
#include "EMAviPlane.h"

#include "EMUIEvent.h"				//!< ������

#include "Scene.h"
#include "SceneWork.h"
#include "SceneWorkMng.h"
#include "EMString.h"
#include "EMVector.h"
#include "EMRect.h"					//!< ������
#include "EMMath.h"


#include "EMCamera.h"
#include "EMMFCCamera.h"
#include "EMFrustum.h"
#include "EMParticle.h"
#include "EMText.h"
#include "EMBBox.h"
#include "EMWorld.h"
#include "EMAnimation.h"
#include "EMNumber.h"
//#include "EMAvi.h"					//!< Ȳ�Դ� avi���
#include "EMASE.h"						//!< Ȳ�Դ� 
#include "EMKinectPlane.h"				//!< Ȳ�Դ� 2012�� 5�� 2��

#include "EMSprite.h"					//!< ems ���� �δ�
#include "EMAnimator.h"					//!< ema ���� �δ�
#include "EMSpriteList.h"				//!< ems list ����
#include "EMAnimatorList.h"				//!< ema list ����


#include "EMButton.h"			//!< ������
//#include "EMButton2.h"		//!< ������
#include "EMRadioButton.h"		//!< ������
#include "EMCheckBox.h"			//!< ������
#include "EMStatic.h"				//!< ������
#include "EMImm.h"					//!< ������
#include "EMIme.h"					//!< ������
#include "EMEditBox.h"			//!< ������
#include "EMListBox.h"			//!< ������

#include "EMInterface.h"			//!< ������

extern CEMMFCCamera g_Cameras[D_MAX_TOOLCAMERA];

//!==============================================================
//! namespace
//!==============================================================
using namespace std;
//using namespace luabind;