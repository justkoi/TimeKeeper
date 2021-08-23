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
	@brief ���� ���� ����
	@param const char* pSoundName	: ��Ʈ�� ���� �̸�
	@param const char* pFileName	: ���� �����̸�
	@return void
	*/
	void					Commit(const char* pSoundName, const char* pFileName);
public:
	/**
	@brief ���� ���� ���
	@param const char* pSoundName	: ��Ʈ�� ���� �̸�
	@param IsLoop					: ���� ����
	@param fVol						: ���� ����
	@return void
	*/
	void					Play(const char* pSoundName, bool IsLoop = false, float fVol = 1.000000f);
	/**
	@brief ���� ��� ���� Ȯ��
	@param const char* pSoundName	: ��Ʈ�� ���� �̸�
	@param 
	@param 
	@return true/false
	*/
	bool					IsPlay(const char* pSoundName);
	/**
	@brief ���� �Ͻ�����
	@param const char* pSoundName	: ��Ʈ�� ���� �̸�
	@param bool bPause				: TRUE=���� FALSE=�����
	@param 
	@return void
	*/
	void					Pause(const char* pSoundName, bool bPause = TRUE);
	/**
	@brief ���� �Ͻ����� ���� Ȯ��
	@param const char* pSoundName	: ��Ʈ�� ���� �̸�
	@param 
	@param 
	@return true/false
	*/
	bool					IsPause(const char* pSoundName);
	/**
	@brief ���� ����
	@param const char* pSoundName	: ��Ʈ�� ���� �̸�
	@param 
	@param 
	@return void
	*/
	void					Stop(const char* pSoundName);
	/**
	@brief ���� ���� ��Ʈ��
	@param const char* pSoundName	: ��Ʈ�� ���� �̸�
	@param float fVol				: ���� ����
	@param 
	@return void
	*/
	void					SetVolume(const char* pSoundName, float fVol);
	/**
	@brief ����Ŀ ��,�� ����
	@param const char* pSoundName	: ��Ʈ�� ���� �̸�
	@param float fPan				: -1 ~ 1 -1�Ͻ� ���ʸ� 1�Ͻ� �����ʸ�
	@param 
	@return void
	*/
	void					SetPan(const char* pSoundName, float fPan);
	
public:
	static CSoundMNG* Instance();
};