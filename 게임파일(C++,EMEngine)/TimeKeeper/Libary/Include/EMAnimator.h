#pragma once

#include <map>
#include "EMVector.h"
#include "EMAnimatorList.h"

typedef struct _EMA_FRAME_tag
{
	char		cpTextureName[32];	//!< ��µ� ������(texture) �̸�
	float		fTime;				//!< ������ ��� �ð� : �⺻ 1��
	float		fR;					//!< ������ ���� (red)	������ = 1
	float		fG;					//!< ������ ���� (green)�ʷϻ� = 1
	float		fB;					//!< ������ ���� (blue)	�Ķ��� = 1
	float		fA;					//!< ������ ���� (alpha) ������ = 1
	float		fSizeX;				//!< ������ ũ�� ( Scale x ) �⺻ ũ�� = 1
	float		fSizeY;				//!< ������ ũ�� ( Scale y ) �⺻ ũ�� = 1
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