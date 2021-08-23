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
	@brief   : ���� Ŭ����
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
	@brief ���� �ʱ�ȭ(�������� ȣ��)
		   ���� ī�� ����̹��� ���� �Ǿ����� ������, ��������^^ �����ϻ�
	@param
	@param 	
	@param 	
	@return ����
	*/
	void InitSound();

	FMOD::System*				m_pSystem;	
	std::vector<FMOD::Sound*>	m_stdSamples;

public:
	static CEMSound* Instance();
	
/**
	@brief ���� ���� ����
	@param const char* fFileName : ���� ���� 
	@param bool bIsStream : ��Ʈ�� (�⺻ true)
	@param 	
	@return SAMPLE_HANDLE 
	*/
	SAMPLE_HANDLE FileOpen(const char* fFileName, bool bIsStream = true);

	/**
	@brief ���� �÷���
	@param SAMPLE_HANDLE pSound : FileOPen���� �Ѿ�� ������ �ֱ�
	@param float fVol : ����
	@param bool bLoop : ��� �ݺ� true, �ѹ��� false
	@param int fFlag : ��� x
	@return SOUND_HANDLE(�ڵ�)
	*/
	SOUND_HANDLE Play(SAMPLE_HANDLE pSound, float fVol=1.0f, bool bLoop=false, int fFlag=0);
	

/**
	@brief ���� ����
	@param SOUND_HANDLE pSound : ���� ������
	@param
	@param
	@param
	@return ����
	*/
	void Stop(SOUND_HANDLE pSound);

	/**
	@brief ��� ����
	@param SOUND_HANDLE pSound : ���� ������
	@param bool bPaused : true/false
	@param
	@param
	@return ����
	*/
	void Pause(SOUND_HANDLE pSound, bool bPaused);

	/**
	@brief �÷��� ������?
	@param SOUND_HANDLE pSound : ���� ������
	@param 
	@param
	@param
	@return true/false
	*/
	bool IsPlaying(SOUND_HANDLE pSound);

	/**
	@brief ����������
	@param SOUND_HANDLE pSound : ���� ������
	@param 
	@param
	@param
	@return true/false
	*/
	bool IsPaused(SOUND_HANDLE pSound);

	/**
	@brief ����Ŀ ��/�� ����
	@param SOUND_HANDLE pSound
	@param fPan : ������ ��������� �¿� ���� (-1.0f  ~ 1.0f)   -1�̸� ���ʸ� �鸮�� 1�̸� �����ʸ� �����
	@param 
	@param 
	@return ����
	*/
	void SetPan(SOUND_HANDLE pSound, float fPan);

	/**
	@brief ����
	@param SOUND_HANDLE pSound : ���� ������
	@param float fVol : ����  ����(-1.0f ~ 1.0f) 
	@param 
	@param 
	@return ����
	*/
	void SetVolume(SOUND_HANDLE pSound, float fVol);


	/**
	@brief ������Ʈ�Լ�(�������� ȣ��)
	@param 
	@param 
	@param 
	@param 
	@return ����
	*/
	void Update();
	void Shutdown();
};
