#pragma once

#include "stdafx.h"

class CSoundMNG
{
private:
	typedef struct _SOUND_tag
	{
		SOUND_HANDLE hSound;
		SAMPLE_HANDLE hSample;

		_SOUND_tag()
		{
			hSound = NULL;
			hSample = NULL;
		}
	}_Sound;

private:
	typedef pair<stdEMString, _Sound> INSERT;
	map<stdEMString, _Sound> m_Table;

public:
	/**
	@brief 사운드 파일 열기
	@param const char* pSoundName	: 컨트롤 사운드 이름
	@param const char* pFileName	: 사운드 파일이름
	@return void
	*/
	void					Commit(const char* pSoundName, const char* pFileName);
public:
	/**
	@brief 사운드 파일 재생
	@param const char* pSoundName	: 컨트롤 사운드 이름
	@param IsLoop					: 사운드 루프
	@param fVol						: 사운드 볼륨
	@return void
	*/
	void					Play(const char* pSoundName, bool IsLoop = false, float fVol = 1.000000f);
	/**
	@brief 사운드 재생 상태 확인
	@param const char* pSoundName	: 컨트롤 사운드 이름
	@param 
	@param 
	@return true/false
	*/
	bool					IsPlay(const char* pSoundName);
	/**
	@brief 사운드 일시정지
	@param const char* pSoundName	: 컨트롤 사운드 이름
	@param bool bPause				: TRUE=멈춤 FALSE=재생중
	@param 
	@return void
	*/
	void					Pause(const char* pSoundName, bool bPause = TRUE);
	/**
	@brief 사운드 일시정지 상태 확인
	@param const char* pSoundName	: 컨트롤 사운드 이름
	@param 
	@param 
	@return true/false
	*/
	bool					IsPause(const char* pSoundName);
	/**
	@brief 사운드 정지
	@param const char* pSoundName	: 컨트롤 사운드 이름
	@param 
	@param 
	@return void
	*/
	void					Stop(const char* pSoundName);
	/**
	@brief 사운드 볼륨 컨트롤
	@param const char* pSoundName	: 컨트롤 사운드 이름
	@param float fVol				: 볼륨 조절
	@param 
	@return void
	*/
	void					SetVolume(const char* pSoundName, float fVol);
	/**
	@brief 스피커 좌,우 조절
	@param const char* pSoundName	: 컨트롤 사운드 이름
	@param float fPan				: -1 ~ 1 -1일시 왼쪽만 1일시 오른쪽만
	@param 
	@return void
	*/
	void					SetPan(const char* pSoundName, float fPan);
	
public:
	static CSoundMNG* Instance();
};