#pragma once

#include <map>
#include <vector>
#include <assert.h>

#include "fmod.hpp"
#include "fmod_errors.h"

void ERRCHECK(FMOD_RESULT result);

#define FMOD_CHECKED( call ) \
{ \
	FMOD_RESULT result = call; \
	ERRCHECK(result); \
} 

typedef void* SOUND_HANDLE;
typedef void* SAMPLE_HANDLE;


/**
	@file    : EMSound.h
	@author  : wo
	@version : 1.0f
	@brief   : 사운드 클래스
 */
class CEMSound
{
private:
	CEMSound() : m_pSystem(NULL)
	{
		assert(m_pSystem == NULL);
		InitSound();
	}
/**
	@brief 사운드 초기화(엔진에서 호출)
		   사운드 카드 드라이버가 설정 되어있지 않으면, 에러나요^^ 주의하삼
	@param
	@param 	
	@param 	
	@return 없음
	*/
	void InitSound();

	FMOD::System*				m_pSystem;	
	std::vector<FMOD::Sound*>	m_stdSamples;

public:
	static CEMSound* Instance();
	
/**
	@brief 사운드 파일 열기
	@param const char* fFileName : 사운드 파일 
	@param bool bIsStream : 스트림 (기본 true)
	@param 	
	@return SAMPLE_HANDLE 
	*/
	SAMPLE_HANDLE FileOpen(const char* fFileName, bool bIsStream = true);

	/**
	@brief 사운드 플레이
	@param SAMPLE_HANDLE pSound : FileOPen으로 넘어온 포인터 넣기
	@param float fVol : 볼륨
	@param bool bLoop : 계속 반복 true, 한번만 false
	@param int fFlag : 사용 x
	@return SOUND_HANDLE(핸들)
	*/
	SOUND_HANDLE Play(SAMPLE_HANDLE pSound, float fVol=1.0f, bool bLoop=false, int fFlag=0);
	

/**
	@brief 사운드 정지
	@param SOUND_HANDLE pSound : 사운드 포인터
	@param
	@param
	@param
	@return 없음
	*/
	void Stop(SOUND_HANDLE pSound);

	/**
	@brief 잠시 멈춤
	@param SOUND_HANDLE pSound : 사운드 포인터
	@param bool bPaused : true/false
	@param
	@param
	@return 없음
	*/
	void Pause(SOUND_HANDLE pSound, bool bPaused);

	/**
	@brief 플레이 중인지?
	@param SOUND_HANDLE pSound : 사운드 포인터
	@param 
	@param
	@param
	@return true/false
	*/
	bool IsPlaying(SOUND_HANDLE pSound);

	/**
	@brief 멈춤중인지
	@param SOUND_HANDLE pSound : 사운드 포인터
	@param 
	@param
	@param
	@return true/false
	*/
	bool IsPaused(SOUND_HANDLE pSound);

	/**
	@brief 스피커 좌/우 조절
	@param SOUND_HANDLE pSound
	@param fPan : 음수값 양수값으로 좌우 조절 (-1.0f  ~ 1.0f)   -1이면 왼쪽만 들리고 1이면 오른쪽만 들려요
	@param 
	@param 
	@return 없음
	*/
	void SetPan(SOUND_HANDLE pSound, float fPan);

	/**
	@brief 볼륨
	@param SOUND_HANDLE pSound : 사운드 포인터
	@param float fVol : 뵬륨  범위(-1.0f ~ 1.0f) 
	@param 
	@param 
	@return 없음
	*/
	void SetVolume(SOUND_HANDLE pSound, float fVol);


	/**
	@brief 업데이트함수(엔진에서 호출)
	@param 
	@param 
	@param 
	@param 
	@return 없음
	*/
	void Update();
	void Shutdown();
};
