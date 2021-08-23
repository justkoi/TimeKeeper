#pragma once

void FindFontFile();
bool LoadFont(stdEMString strPath, int nSize, stdEMString strFontName);
bool DestroyFont(stdEMString strFontName);			//!< 이름에 해당하는놈만 지우기 (ㅎㅎ_
bool DestroyAllFont();								//!< 모두 지우기(엔진에서 호출)

stEMVec2 RenderText(stdEMWString strOutPutString, stdEMString strFontName, int nx, int nY, stEMVec2 stSize, float fAngle = 0.0f);
stEMVec2 GetTextEtents(stdEMString strOutPutString, stdEMString strFontName);
stEMRect GetBBox(stdEMString OutPutString, stdEMString strFontName, float x, float y); //윤영재
stEMRect GetBBox(stdEMWString wOutPutString, stdEMString strFontName, float x, float y); //윤영재

enum enumTextAlignment
{
	E_TEXT_LEFT
	//E_TEXT_CENTER,			//!< 업데이트 진행중
	//E_TEXT_RIGHT				//!< 업데이트 진행중
};

typedef struct sttextInfo
{
	stdEMString		m_strString;
	stdEMWString	m_wstrString;		//!< 유니코드로 변경되어 저장
	stEMVec2		m_stVec2Ext;		
	stEMVec2		m_stVec2Pos;
}stTextInfo;

/**
	@file    : EMText.h
	@author  : wo
	@version : 1.0f
	@brief   : 텍스트 클래스
 */
class CEMText : public CEMPlane
{
private:
	stdEMString				m_strCurFontName;				//!< 현재 설정 되어진 폰트 이름
	stdEMString				m_strOutPut;					//!< 출력할 문자 
	stdEMString				m_strNewOutputString;			//!< 출력할 문자
	enumTextAlignment		m_eAlign;
	
	stEMVec2				m_stViewPos;					//!< 위치
	CEMBBox					m_Extents;						//!< 박스
	int						m_nLineSpac;					//!< 줄간격^^(직교투여이후에 적용 안되어짐)

	std::vector<stTextInfo> m_stdOutPutString;				//!< 실제 화면에 출력할 놈 추가

public:
	CEMText( stdEMString strFontName, stdEMString strOutPut,
			 enumTextAlignment eAlign = E_TEXT_LEFT, int lineSpacing = 5
		   );

	CEMText();
	~CEMText(){}

public:
	/**
	@brief : 화면에 출력 되어질 문자 변경함수

	@param : strOutPut 출력되어질 문자
	@param : 
	@param : 
	@param : 
	@param : 

	@return : 없음
	*/
	void SetOutPutString(stdEMString strOutPut);

	/**
	@brief : 줄간격 설정 함수
	@param nSpace : 줄간격 설정합니다
	@param  
	@param  
	@param  
	@param  

	@return : 없음
	*/
	void SetLineSpace(int nSpace);

	/**
	@brief : 문자의 boundingbox 로 rect값을 알아 내는 함수 ( 윤영재 )
	@return : 없음
	*/
	stEMRect GetRect(stdEMString str, stdEMString FontName, float fX, float fY);
	stEMRect GetRect(stdEMWString str, stdEMString FontName, float fX, float fY);

private:
	
	/**
	@brief : 멀티바이트를 WideChar로 변환(엔진 내부에서 사용)
	@param const stdEMString strOutPut : 멀티바이트
	@param stdEMWString* wstrOutput : WideChar
	@param 
	@param 
	@param 

	@return : 없음
	*/
	void MultiToWideChar(const stdEMString strOutPut, stdEMWString* wstrOutput);

	/**
	@brief : 정렬 방법
	@param enumTextAlignment enumAlig : E_TEXT_LEFT 현재 하나만 지원함
	@param 
	@param 
	@param 
	@param 

	@return : 없음
	*/
	void SetAlignment(enumTextAlignment enumAlig);

private:
	/**
	@brief : 위치계산(엔진내부에서 호출)

	@param : 
	@param : 
	@param : 
	@param : 
	@param : 

	@return : 없음
	*/
	virtual void CalcPos();

public:
	virtual void Update(float dt);
	virtual void Render();

	/**
	@brief : 폰트 위치 설정(직교투영 2d좌표 사용)

	@param float fX : 윈도우 x위치(내부적으로 int로 처리)
	@param float fY : 윈도우 y위치
	@param 
	@param 
	@param 

	@return : 없음
	*/
	virtual void SetPos(float fX, float fY);
	virtual void SetPos(stEMVec2 vec2);
	

	/**
	@brief : 클래스 이름 얻어오기
	@return : const stdEMString
	*/
	virtual const stdEMString GetClassName() { return "CEMText"; }
};