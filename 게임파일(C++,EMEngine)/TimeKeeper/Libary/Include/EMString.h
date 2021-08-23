
#include <vector>
#include <string>
#include <set>

#pragma once

typedef std::string					stdEMString;
typedef std::wstring				stdEMWString;
typedef std::vector<stdEMString>	stdEMStringList;
typedef std::set<stdEMString>		stdEMStringSet;

	/**
	@brief 문자를 정수형으로 변환
	@param const stdEMString& stdSTring : 변환할 문자
	@return int
	*/
int  EMStringToInt( const stdEMString& stdSTring );

	/**
	@brief 문자를 실수형으로 변환
	@param const stdEMString& stdSTring : 변환할 문자
	@return float
	*/
float EMStringToFloat( const stdEMString& stdSTring );

	/**
	@brief 정수(실수) 를 문자로
	@param int nVal : 변환할 정수형
	@return stdEMString
	*/
stdEMString IntToEMString( int nVal );
stdEMString FloatToEMString( float fVal );

	/**
	@brief bool->문자로
	@param int bVal : 변환할 정수형
	@return stdEMString
	*/
stdEMString BoolToEMString( bool bVal );

	/**
	@brief 대문자로 변환
	@param const stdEMString& stdSTring : 변환할 문자
	@return stdEMString
	*/
stdEMString ToUpper( const stdEMString& stdSTring );

	/**
	@brief 소문자로 변환
	@param const stdEMString& stdSTring : 변환할 문자
	@return stdEMString
	*/
stdEMString ToLower( const stdEMString& stdSTring );

	/**
	@brief 엔진단에서 사용(
	@return stdEMStringList
	*/
stdEMStringList SplitEMString( const stdEMString& splitMe, const stdEMString& splitChars, bool bRemoveEmptyEntries = true );
stdEMStringList SplitEMString( const stdEMString& splitMe );
bool OutPutLogFileListToFile( const stdEMString& fileName, const stdEMStringList& strings );
bool OutPutLogFileToFile( const stdEMString& fileName, const stdEMString& line );

	/**
	@brief 파일이름만 얻어오는 함수
	@param const stdEMString strName : 주소 문자열
	@return stdEMString
	*/
stdEMString GetOnlyFileName(const stdEMString strName);

	/**
	@brief 파일 이름얻어 오기
	@param const stdEMString strName : 주소 문자열
	@return stdEMString
	*/
stdEMString GetExtFileName(const stdEMString strName);

	/**
	@brief 확장자 이름 얻어오기
	@param const stdEMString strName : 확장자 이름 얻을 문자열
	@return stdEMString
	*/
stdEMString GetExtName(const stdEMString strName);