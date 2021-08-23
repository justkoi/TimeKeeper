#pragma once


//!==============================================================
//! 전역클래스
//!==============================================================
#define D_WORLD		CEMWorld::Instance()			//!< 월드 관리
#define D_SCENE		CSceneWork::Instance()			//!< 씬 정보 관리
#define D_CAMERA	CEMCamera::Instance()			//!< 카메라 관리
#define D_INPUT		CEMInput::Instance()			//!< 키보드 or 마우스
#define D_SOUND		CEMSound::Instance()			//!< 사운드 관리
#define D_SOUNDMNG	CSoundMNG::Instance()			//!< 사운드 관리
#define D_DEBUG		CDebugLogOutput::Instance()		//!< 비쥬얼 스튜디오의 출력창으로 디버깅 정보가 출력됩니다. 
#define D_FRUSTUM	CEMFrustum::Instance()			//!< 프러스텀 관리
//#define D_PHYSIC	CEMPhysic::Instance()			//!< 당연 물리관련입죠^^
 
#define D_MAX_LOG_LENGTH 1024						//!< 로그 파일 길이
#define D_ANTWEAKBAR								//!< antweakbar를 사용하고 싶다면 주석을 해지하세요

#define GLFW_DLL									//!< 이거 꼭 해줘야 GLFW사용 가능 합니다 ^^ 주의하삼
#define ILUT_USE_OPENGL								//!< Devil사용시 넣어줘야합니다
#undef  _UNICODE

#define D_MAX_Z	-50000.0f
#define D_MAX_VALUE 99999

#define D_MAX_TOOLCAMERA	10

#define NULL		0								//!< Definition of NULL keyword
#define FORCE_DWORD	0x7fffffff						//!< Force dword to 4 bytes in enum

//!==============================================================
//! 경고문구 
//!==============================================================
#pragma warning(disable:4244)		
#pragma warning(disable:4005)						//! #include <windows.h> 추가시나오는 warring
#pragma warning(disable:4996)						//!< MLog.cpp(15) : warning C4996: 'vsprintf'이(가) deprecated로 선언되었습니다.
#pragma warning(disable:4129)						//!< warning C4129: ' ' : 문자 이스케이프 시퀀스를 인식할 수 없습니다.
//#pragma warning(disable:4309)														//!< warning C4309: '초기화 중' : 상수 값이 잘립니다.
#pragma warning(disable:4819)						//!< warning C4819: 현재 코드 페이지(949)에서 표시할 수 없는 문자가 파일에 들어 있습니다. 데이터가 손실되지 않게 하려면 해당 파일을 유니코드 형식으로 저장하십시오.
#pragma warning(disable:4482)						//!< warning C4482: 비표준 확장이 사용되었습니다. 정규화된 이름에 'b2Shape::Type' 열거형을 사용했습니다.
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
#pragma comment(lib, "version.lib")			//! Visual Studio 2010에서 에러 에러 나는 것을 방지하려면 추가해줘야합니다.

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
#include <assert.h>					//! 윤영재
#include <objbase.h>				//! 윤영재
#include <dimm.h>					//! 윤영재
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
#include <list>				//!< 윤영재 list추가 했어용
#include <math.h>
#include <time.h>
#include <AntTweakBar.h>
//#include <luabind/luabind.hpp>
#include "gl/glfw.h"
#include "gl/glext.h"
#include "IL/il.h"
#include "IL/ilu.h"
#include "IL/ilut.h"

//! 수학 관련 클래스 추가요
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

#include "EMUIEvent.h"				//!< 윤영재

#include "Scene.h"
#include "SceneWork.h"
#include "SceneWorkMng.h"
#include "EMString.h"
#include "EMVector.h"
#include "EMRect.h"					//!< 윤영재
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
//#include "EMAvi.h"					//!< 황규덕 avi재생
#include "EMASE.h"						//!< 황규덕 
#include "EMKinectPlane.h"				//!< 황규덕 2012년 5월 2일

#include "EMSprite.h"					//!< ems 파일 로더
#include "EMAnimator.h"					//!< ema 파일 로더
#include "EMSpriteList.h"				//!< ems list 정보
#include "EMAnimatorList.h"				//!< ema list 정보


#include "EMButton.h"			//!< 윤영재
//#include "EMButton2.h"		//!< 윤영재
#include "EMRadioButton.h"		//!< 윤영재
#include "EMCheckBox.h"			//!< 윤영재
#include "EMStatic.h"				//!< 윤영재
#include "EMImm.h"					//!< 윤영재
#include "EMIme.h"					//!< 윤영재
#include "EMEditBox.h"			//!< 윤영재
#include "EMListBox.h"			//!< 윤영재

#include "EMInterface.h"			//!< 윤영재

extern CEMMFCCamera g_Cameras[D_MAX_TOOLCAMERA];

//!==============================================================
//! namespace
//!==============================================================
using namespace std;
//using namespace luabind;