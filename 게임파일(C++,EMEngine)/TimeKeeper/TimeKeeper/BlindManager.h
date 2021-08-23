#pragma once

#include "stdafx.h"

typedef enum
{
	E_BLINDSTATE_FADE_IN, //!< ���� ������� ��
	E_BLINDSTATE_FADE_OUT, //!< ���� ��ο� ���� ��
}E_BLINDSTATE_FADE;

class CBlindManager
{
private:
public:
	CEMPlane* m_pPlane;
	E_BLINDSTATE_FADE m_eState;
	bool	m_bAction; //!< �׼ǿϷ�
	int		m_nNumber; //!< �ݺ�Ƚ��
	float	m_fTimer;
	bool	m_bPause; //!< �Ͻ�����
	float	m_fBlindTime; //!< ����ε� ���ӽð� ��ť
	bool	m_bVisible;
	bool	m_bNextDtPass;
public:
	void Init(CRootScene* pThisScene);
	void Update(float dt);
	void Exit();
public:
	void Pause();
	void Resume();

	void StartBlind(int nNumber, E_BLINDSTATE_FADE eState, float fBlindTime, bool bNextDtPass = false); //!< ������ ���ڰ��� ���� �о���̴� �ð����� ���غ� dt�� �����մϴ�.
};