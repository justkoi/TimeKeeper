











#pragma once

#include "EMString.h"


/**
	@file    : EMLog.h
	@author  : wo
	@version : 1.0f
	@brief   : 로그파일 최상의 클래스입죠
 */
class CRootLog
{
public:
	virtual ~CRootLog() {};

public:
	virtual void Log( const stdEMString&  ) = 0;		//!< 순수 가상 함수
	
	void Printf(const char* format, ...);				
};
	
/**
	@file    : EMLog.h
	@author  : wo
	@version : 1.0f
	@brief   : 파일로 로그파일 남기는 클래스
 */
class CEMLogFile : public CRootLog
{
private:
	stdEMString m_strLogFileName;			//!< 저장할 파일이름 설정 변수

public:
	CEMLogFile( const stdEMString& fileName );

	/**
	@brief 로그를 ???.txt파일로 생성하는 프로그램 입니다 Logs/???.txt파일로 생성됩니다.
		   CEMLogFile* pLog = new CEMLogFile("???");
		   pLog->Log("히히 ");

		   이렇게 해주면 Logs/???.txt파일이 생기고 그 안에 히히가 출력됩니다.

	@param filename
	@param 
	@param 
	@param 
	@param 
	@return stdEMString 만들어진 파일이름 리턴
	*/
	stdEMString CreateLog( stdEMString fileName );

public:

	/**
	@brief txt파일에 출력해주는 함수
	@param 
	@param 
	@param 
	@param 
	@param 
	@return 없음
	*/
	virtual void Log( const stdEMString& val);
};

/**
	@file    : EMLog.h
	@author  : wo
	@version : 1.0f
	@brief   : 비쥬얼 스튜디오 출력창에 로그를 출력합니다. 전역으로 잡혀있어요.
 */
class CDebugLogOutput : public CRootLog
{
private:

public:
	virtual void Log( const stdEMString& val );
	static CDebugLogOutput* Instance();
};
