
#include <vector>
#include <string>
#include <set>

#pragma once

typedef std::string					stdEMString;
typedef std::wstring				stdEMWString;
typedef std::vector<stdEMString>	stdEMStringList;
typedef std::set<stdEMString>		stdEMStringSet;

	/**
	@brief ���ڸ� ���������� ��ȯ
	@param const stdEMString& stdSTring : ��ȯ�� ����
	@return int
	*/
int  EMStringToInt( const stdEMString& stdSTring );

	/**
	@brief ���ڸ� �Ǽ������� ��ȯ
	@param const stdEMString& stdSTring : ��ȯ�� ����
	@return float
	*/
float EMStringToFloat( const stdEMString& stdSTring );

	/**
	@brief ����(�Ǽ�) �� ���ڷ�
	@param int nVal : ��ȯ�� ������
	@return stdEMString
	*/
stdEMString IntToEMString( int nVal );
stdEMString FloatToEMString( float fVal );

	/**
	@brief bool->���ڷ�
	@param int bVal : ��ȯ�� ������
	@return stdEMString
	*/
stdEMString BoolToEMString( bool bVal );

	/**
	@brief �빮�ڷ� ��ȯ
	@param const stdEMString& stdSTring : ��ȯ�� ����
	@return stdEMString
	*/
stdEMString ToUpper( const stdEMString& stdSTring );

	/**
	@brief �ҹ��ڷ� ��ȯ
	@param const stdEMString& stdSTring : ��ȯ�� ����
	@return stdEMString
	*/
stdEMString ToLower( const stdEMString& stdSTring );

	/**
	@brief �����ܿ��� ���(
	@return stdEMStringList
	*/
stdEMStringList SplitEMString( const stdEMString& splitMe, const stdEMString& splitChars, bool bRemoveEmptyEntries = true );
stdEMStringList SplitEMString( const stdEMString& splitMe );
bool OutPutLogFileListToFile( const stdEMString& fileName, const stdEMStringList& strings );
bool OutPutLogFileToFile( const stdEMString& fileName, const stdEMString& line );

	/**
	@brief �����̸��� ������ �Լ�
	@param const stdEMString strName : �ּ� ���ڿ�
	@return stdEMString
	*/
stdEMString GetOnlyFileName(const stdEMString strName);

	/**
	@brief ���� �̸���� ����
	@param const stdEMString strName : �ּ� ���ڿ�
	@return stdEMString
	*/
stdEMString GetExtFileName(const stdEMString strName);

	/**
	@brief Ȯ���� �̸� ������
	@param const stdEMString strName : Ȯ���� �̸� ���� ���ڿ�
	@return stdEMString
	*/
stdEMString GetExtName(const stdEMString strName);