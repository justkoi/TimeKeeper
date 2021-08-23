











#pragma once

#include "EMString.h"


/**
	@file    : EMLog.h
	@author  : wo
	@version : 1.0f
	@brief   : �α����� �ֻ��� Ŭ��������
 */
class CRootLog
{
public:
	virtual ~CRootLog() {};

public:
	virtual void Log( const stdEMString&  ) = 0;		//!< ���� ���� �Լ�
	
	void Printf(const char* format, ...);				
};
	
/**
	@file    : EMLog.h
	@author  : wo
	@version : 1.0f
	@brief   : ���Ϸ� �α����� ����� Ŭ����
 */
class CEMLogFile : public CRootLog
{
private:
	stdEMString m_strLogFileName;			//!< ������ �����̸� ���� ����

public:
	CEMLogFile( const stdEMString& fileName );

	/**
	@brief �α׸� ???.txt���Ϸ� �����ϴ� ���α׷� �Դϴ� Logs/???.txt���Ϸ� �����˴ϴ�.
		   CEMLogFile* pLog = new CEMLogFile("???");
		   pLog->Log("���� ");

		   �̷��� ���ָ� Logs/???.txt������ ����� �� �ȿ� ������ ��µ˴ϴ�.

	@param filename
	@param 
	@param 
	@param 
	@param 
	@return stdEMString ������� �����̸� ����
	*/
	stdEMString CreateLog( stdEMString fileName );

public:

	/**
	@brief txt���Ͽ� ������ִ� �Լ�
	@param 
	@param 
	@param 
	@param 
	@param 
	@return ����
	*/
	virtual void Log( const stdEMString& val);
};

/**
	@file    : EMLog.h
	@author  : wo
	@version : 1.0f
	@brief   : ����� ��Ʃ��� ���â�� �α׸� ����մϴ�. �������� �����־��.
 */
class CDebugLogOutput : public CRootLog
{
private:

public:
	virtual void Log( const stdEMString& val );
	static CDebugLogOutput* Instance();
};
