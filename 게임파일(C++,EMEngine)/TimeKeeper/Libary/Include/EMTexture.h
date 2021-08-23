#pragma once

#include "EMString.h"
#include "EMColor.h"
#include "EMSprite.h"
#include "EMVector.h"


/**
	@file    : EMTexture.h
	@author  : wo
	@version : 1.0f
	@brief   : �ؽ��� �ε��� ����Ǿ����� ����ü
 */
typedef struct stTextureCacheEntry
{
	stdEMString		filename;				//!< ���� �̸�
	GLint			clampMode;
	GLint			filterMode;
	GLuint			textureIndex;			//! gl�� ��ϵǾ��� ���̵�

	int				m_nImageWidth;			//!< �̹��� ������
	int				m_nImageHeight;			//!< �̹��� ������

	int				m_nImageWidthHalf;		//!< �̹��� ������ /2
	int				m_nImageHeightHalf;		//!< �̹��� ������ /2

	bool			dirty;

}stTextureCacheEntry;


/**
	@brief �ؽ��� �ʱ�ȭ (OpenGL �ʱ�ȭ�Ҷ� �־�����մϴ�)
	@param 
	@param 
	@param 
	@param 
	@param 
	@return ����
	*/
void InitTexture();


/**
	@brief strFileName�� ��ġ�� �ִ� ������ �о�ͼ� gl�� ��Ͻ�Ų�� Id���� �����Ѵ�.
	@param stdEMString strFileName		: �����̸�
	@param GLint nClampMode=GL_CLAMP	: GL �ɼ�
	@param GLint nFilterMode=GL_LINEAR	: GL �ɼ�
	@param int* nWidth = NULL			: ����
	@param int* nHeight = NULL			: ����
	@param bool bOptional				: �⺻ FALSE�� ���μſ�^^
	@param 
	@param 
	@param 
	@return int (-1�� �����ߴٴ� ��)
	*/
int GetTextureReference(stdEMString strFileName, GLint nClampMode=GL_CLAMP, GLint nFilterMode=GL_LINEAR, int* nWidth = NULL, int* nHeight = NULL, bool bOptional = FALSE);
int GetTextureReference(const char* cpName,  stEMVec2* OffSet, stEMVec2* ll, stEMVec2* ru, GLint clampmode, GLint filtermode, int* pWidth, int* pHeight, bool optional);

/**
	@brief �о���� �ؽ��� �� �����ִ� �Լ��Դϴ�. 
	@param 
	@param 
	@param 
	@param 
	@param 
	@return ����
	*/
void TextureRelease();

/**
	@brief EMS���Ͽ��� data�� �о� ��
	@param 
	@param 
	@param 
	@param 
	@param 
	@return ����
	*/
void SetEMSReference(const _Texture& Tex, const char* pData, long size, GLint clampmode = GL_CLAMP, GLint filtermode = GL_LINEAR, bool optional = false);