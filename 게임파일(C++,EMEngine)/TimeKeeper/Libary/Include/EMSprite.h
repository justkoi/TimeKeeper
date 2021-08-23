#pragma once

#include "EMSpriteList.h"
#include <map>

using namespace std;

typedef struct _UV_tag
{
	_UV_tag()
	{
		u = 0.f;
		v = 0.f;
	}
	_UV_tag(float _u, float _v)
	{
		u = _u;
		v = _v;
	}
	float u;
	float v;
} _UV;

typedef struct _Texture_tag
{
	_Texture_tag()
	{
		memset(cpName, 0, sizeof(cpName));
		xPos = 0.f;
		yPos = 0.f;
		Width = 0.f;
		Height = 0.f;
		WidthHalf = 0.f;
		HeightHalf = 0.f;
		OffSetX = 0;
		OffSetY = 0;
		LeftLow = _UV(0.f, 0.f);
		RightUp = _UV(1.f, 1.f);
	}
	_Texture_tag(const char* _cpName, float x, float y, float width, float height, float wHalf, float hHalf, _UV& ll = _UV(0.f, 0.f), _UV& ru = _UV(1.f, 1.f), float offsetX = 0, float offsetY = 0)
	{
		strcpy(cpName, _cpName);
		xPos = x;
		yPos = y;
		Width = width ;
		Height = height;
		WidthHalf = wHalf;
		HeightHalf = hHalf;
		OffSetX = offsetX;
		OffSetY = offsetY;
		LeftLow = ll;
		RightUp = ru;
	}
	char cpName[64];
	float xPos;
	float yPos;
	float Width;
	float Height;
	float WidthHalf;
	float HeightHalf;
	float OffSetX;
	float OffSetY;
	_UV LeftLow;
	_UV RightUp;
	UINT reserve;
} _Texture;

cEmSpriteList* EMSLoader(const char* sFileName, GLint clampmode = GL_CLAMP, GLint filtermode = GL_LINEAR, bool optional = FALSE);
//cEmSpriteList* EMSLoader2(const char* sFileName, GLint clampmode = GL_CLAMP, GLint filtermode = GL_LINEAR, bool optional = FALSE);

_Texture* GetTexture(const char* cpName);

void SpriteDestroy();
