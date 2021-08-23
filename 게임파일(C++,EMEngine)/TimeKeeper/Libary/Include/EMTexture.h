#pragma once

#include "EMString.h"
#include "EMColor.h"
#include "EMSprite.h"
#include "EMVector.h"


/**
	@file    : EMTexture.h
	@author  : wo
	@version : 1.0f
	@brief   : 텍스쳐 로딩후 저장되어지는 구조체
 */
typedef struct stTextureCacheEntry
{
	stdEMString		filename;				//!< 파일 이름
	GLint			clampMode;
	GLint			filterMode;
	GLuint			textureIndex;			//! gl에 등록되어진 아이디

	int				m_nImageWidth;			//!< 이미지 사이즈
	int				m_nImageHeight;			//!< 이미지 사이즈

	int				m_nImageWidthHalf;		//!< 이미지 사이즈 /2
	int				m_nImageHeightHalf;		//!< 이미지 사이즈 /2

	bool			dirty;

}stTextureCacheEntry;


/**
	@brief 텍스쳐 초기화 (OpenGL 초기화할때 넣어줘야합니다)
	@param 
	@param 
	@param 
	@param 
	@param 
	@return 없음
	*/
void InitTexture();


/**
	@brief strFileName에 위치에 있는 파일을 읽어와서 gl에 등록시킨후 Id값을 리턴한다.
	@param stdEMString strFileName		: 파일이름
	@param GLint nClampMode=GL_CLAMP	: GL 옵션
	@param GLint nFilterMode=GL_LINEAR	: GL 옵션
	@param int* nWidth = NULL			: 넓이
	@param int* nHeight = NULL			: 높이
	@param bool bOptional				: 기본 FALSE로 놔두셔요^^
	@param 
	@param 
	@param 
	@return int (-1면 실패했다는 뜻)
	*/
int GetTextureReference(stdEMString strFileName, GLint nClampMode=GL_CLAMP, GLint nFilterMode=GL_LINEAR, int* nWidth = NULL, int* nHeight = NULL, bool bOptional = FALSE);
int GetTextureReference(const char* cpName,  stEMVec2* OffSet, stEMVec2* ll, stEMVec2* ru, GLint clampmode, GLint filtermode, int* pWidth, int* pHeight, bool optional);

/**
	@brief 읽어들인 텍스쳐 다 지워주는 함수입니다. 
	@param 
	@param 
	@param 
	@param 
	@param 
	@return 없음
	*/
void TextureRelease();

/**
	@brief EMS파일에서 data를 읽어 옴
	@param 
	@param 
	@param 
	@param 
	@param 
	@return 없음
	*/
void SetEMSReference(const _Texture& Tex, const char* pData, long size, GLint clampmode = GL_CLAMP, GLint filtermode = GL_LINEAR, bool optional = false);