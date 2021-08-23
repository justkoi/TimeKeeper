#pragma once

void FindFontFile();
bool LoadFont(stdEMString strPath, int nSize, stdEMString strFontName);
bool DestroyFont(stdEMString strFontName);			//!< �̸��� �ش��ϴ³� ����� (����_
bool DestroyAllFont();								//!< ��� �����(�������� ȣ��)

stEMVec2 RenderText(stdEMWString strOutPutString, stdEMString strFontName, int nx, int nY, stEMVec2 stSize, float fAngle = 0.0f);
stEMVec2 GetTextEtents(stdEMString strOutPutString, stdEMString strFontName);
stEMRect GetBBox(stdEMString OutPutString, stdEMString strFontName, float x, float y); //������
stEMRect GetBBox(stdEMWString wOutPutString, stdEMString strFontName, float x, float y); //������

enum enumTextAlignment
{
	E_TEXT_LEFT
	//E_TEXT_CENTER,			//!< ������Ʈ ������
	//E_TEXT_RIGHT				//!< ������Ʈ ������
};

typedef struct sttextInfo
{
	stdEMString		m_strString;
	stdEMWString	m_wstrString;		//!< �����ڵ�� ����Ǿ� ����
	stEMVec2		m_stVec2Ext;		
	stEMVec2		m_stVec2Pos;
}stTextInfo;

/**
	@file    : EMText.h
	@author  : wo
	@version : 1.0f
	@brief   : �ؽ�Ʈ Ŭ����
 */
class CEMText : public CEMPlane
{
private:
	stdEMString				m_strCurFontName;				//!< ���� ���� �Ǿ��� ��Ʈ �̸�
	stdEMString				m_strOutPut;					//!< ����� ���� 
	stdEMString				m_strNewOutputString;			//!< ����� ����
	enumTextAlignment		m_eAlign;
	
	stEMVec2				m_stViewPos;					//!< ��ġ
	CEMBBox					m_Extents;						//!< �ڽ�
	int						m_nLineSpac;					//!< �ٰ���^^(�����������Ŀ� ���� �ȵǾ���)

	std::vector<stTextInfo> m_stdOutPutString;				//!< ���� ȭ�鿡 ����� �� �߰�

public:
	CEMText( stdEMString strFontName, stdEMString strOutPut,
			 enumTextAlignment eAlign = E_TEXT_LEFT, int lineSpacing = 5
		   );

	CEMText();
	~CEMText(){}

public:
	/**
	@brief : ȭ�鿡 ��� �Ǿ��� ���� �����Լ�

	@param : strOutPut ��µǾ��� ����
	@param : 
	@param : 
	@param : 
	@param : 

	@return : ����
	*/
	void SetOutPutString(stdEMString strOutPut);

	/**
	@brief : �ٰ��� ���� �Լ�
	@param nSpace : �ٰ��� �����մϴ�
	@param  
	@param  
	@param  
	@param  

	@return : ����
	*/
	void SetLineSpace(int nSpace);

	/**
	@brief : ������ boundingbox �� rect���� �˾� ���� �Լ� ( ������ )
	@return : ����
	*/
	stEMRect GetRect(stdEMString str, stdEMString FontName, float fX, float fY);
	stEMRect GetRect(stdEMWString str, stdEMString FontName, float fX, float fY);

private:
	
	/**
	@brief : ��Ƽ����Ʈ�� WideChar�� ��ȯ(���� ���ο��� ���)
	@param const stdEMString strOutPut : ��Ƽ����Ʈ
	@param stdEMWString* wstrOutput : WideChar
	@param 
	@param 
	@param 

	@return : ����
	*/
	void MultiToWideChar(const stdEMString strOutPut, stdEMWString* wstrOutput);

	/**
	@brief : ���� ���
	@param enumTextAlignment enumAlig : E_TEXT_LEFT ���� �ϳ��� ������
	@param 
	@param 
	@param 
	@param 

	@return : ����
	*/
	void SetAlignment(enumTextAlignment enumAlig);

private:
	/**
	@brief : ��ġ���(�������ο��� ȣ��)

	@param : 
	@param : 
	@param : 
	@param : 
	@param : 

	@return : ����
	*/
	virtual void CalcPos();

public:
	virtual void Update(float dt);
	virtual void Render();

	/**
	@brief : ��Ʈ ��ġ ����(�������� 2d��ǥ ���)

	@param float fX : ������ x��ġ(���������� int�� ó��)
	@param float fY : ������ y��ġ
	@param 
	@param 
	@param 

	@return : ����
	*/
	virtual void SetPos(float fX, float fY);
	virtual void SetPos(stEMVec2 vec2);
	

	/**
	@brief : Ŭ���� �̸� ������
	@return : const stdEMString
	*/
	virtual const stdEMString GetClassName() { return "CEMText"; }
};