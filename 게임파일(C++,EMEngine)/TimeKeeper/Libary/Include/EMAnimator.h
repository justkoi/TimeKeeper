#pragma once

#include <map>
#include "EMVector.h"
#include "EMAnimatorList.h"

typedef struct _EMA_FRAME_tag
{
	char		cpTextureName[32];	//!< 출력될 프레임(texture) 이름
	float		fTime;				//!< 프레임 출력 시간 : 기본 1초
	float		fR;					//!< 프레임 색상 (red)	빨강색 = 1
	float		fG;					//!< 프레임 색상 (green)초록색 = 1
	float		fB;					//!< 프레임 색상 (blue)	파랑색 = 1
	float		fA;					//!< 프레임 투명도 (alpha) 불투명 = 1
	float		fSizeX;				//!< 프레임 크기 ( Scale x ) 기본 크기 = 1
	float		fSizeY;				//!< 프레임 크기 ( Scale y ) 기본 크기 = 1
	_EMA_FRAME_tag()
	{
		fTime			= 1.f;
		fR				= 1.f;
		fG				= 1.f;
		fB				= 1.f;
		fA				= 1.f;
		fSizeX			= 1.f;
		fSizeY			= 1.f;
		memset(cpTextureName, 0, sizeof(cpTextureName));
	}
} _Ema_Frame;


cEmAnimatorList* EMALoader(const char* sFileName);
void SetEmaReference(const stdEMString sEmaName, _Ema_Frame& _Frame);

int					GetFrameCount(const stdEMString sEmaName);
float				GetFrameTime(const stdEMString sEmaName, int index);
CEMColor 			GetFrameColor(const stdEMString sEmaName, int index);
stEMVec2 			GetFrameSize(const stdEMString sEmaName, int index);
const stdEMString	GetFrameName(const stdEMString sEmaName, int index);
void				AniListClear();

void FindFilePahtToFileTitle(const string sFilePath, string* sFileTitle);