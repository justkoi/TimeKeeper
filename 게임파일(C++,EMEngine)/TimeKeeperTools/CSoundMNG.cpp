#include "stdafx.h"

void CSoundMNG::Commit(const char* pSoundName, const char* pFileName)
{
	_Sound tmp;
	tmp.hSample				= D_SOUND->FileOpen(pFileName);
	map<stdEMString, _Sound>::iterator itr = m_Table.find(pSoundName);

	if(itr == m_Table.end())
	{
		m_Table.insert(INSERT(pSoundName, tmp));
	}
}

void CSoundMNG::Play(const char* pSoundName, bool IsLoop, float fVol)
{
	map<stdEMString, _Sound>::iterator itr = m_Table.find(pSoundName);

	if(itr != m_Table.end())
	{
		(*itr).second.hSound = D_SOUND->Play((*itr).second.hSample, fVol, IsLoop);
	}
}

bool CSoundMNG::IsPlay(const char* pSoundName)
{
	map<stdEMString, _Sound>::iterator itr = m_Table.find(pSoundName);

	if(itr != m_Table.end())
	{
		return D_SOUND->IsPlaying((*itr).second.hSound);
	}
	return false;
}

void CSoundMNG::Pause(const char* pSoundName, bool bPause)
{
	map<stdEMString, _Sound>::iterator itr = m_Table.find(pSoundName);

	if(itr != m_Table.end())
	{
		D_SOUND->Pause((*itr).second.hSound, bPause);
	}
}

bool CSoundMNG::IsPause(const char* pSoundName)
{
	map<stdEMString, _Sound>::iterator itr = m_Table.find(pSoundName);

	if(itr != m_Table.end())
	{
		return D_SOUND->IsPaused((*itr).second.hSound);
	}
	return false;
}

void CSoundMNG::Stop(const char* pSoundName)
{
	map<stdEMString, _Sound>::iterator itr = m_Table.find(pSoundName);

	if(itr != m_Table.end())
	{
		D_SOUND->Stop((*itr).second.hSound);
		(*itr).second.hSound = NULL;
	}
}

void CSoundMNG::SetVolume(const char* pSoundName, float fVol)
{
	map<stdEMString, _Sound>::iterator itr = m_Table.find(pSoundName);

	if(itr != m_Table.end())
	{
		D_SOUND->SetVolume((*itr).second.hSound, fVol);
	}
}

void CSoundMNG::SetPan(const char* pSoundName, float fPan)
{
	map<stdEMString, _Sound>::iterator itr = m_Table.find(pSoundName);

	if(itr != m_Table.end())
	{
		D_SOUND->SetPan((*itr).second.hSound, fPan);
	}
}

CSoundMNG* CSoundMNG::Instance()
{
	static CSoundMNG instance;

	return &instance;
}