#include "stdafx.h"

void CEMTempest::Init(CRootScene* pThisScene)
{
	m_pThisScene = pThisScene;
}

void CEMTempest::Update(float dt)
{
	list<stTempe*>::iterator it;
	for(it = m_TempeList.begin(); it != m_TempeList.end(); it++)
	{
		float fAskChange = (*it)->m_fMoveSpeedX;

		(*it)->m_stPos.m_fX += (*it)->m_fMoveSpeedX * dt;
		(*it)->m_fMoveSpeedX += (*it)->m_fPlusSpeedX * dt;
		
		if((*it)->m_eType == E_TEMPE_TYPE_NORMAL)
		{
			if( (*it)->m_fMoveSpeedY >= 0)
			{
				if((*it)->m_stPos.m_fY <= (*it)->m_stTargetPos.m_fY)
				{
					(*it)->m_stPos.m_fY += (*it)->m_fMoveSpeedY * dt;
					(*it)->m_fMoveSpeedY += (*it)->m_fPlusSpeedY * dt;
					if((*it)->m_stPos.m_fY >= (*it)->m_stTargetPos.m_fY)
					{
						(*it)->m_stPos.m_fY = (*it)->m_stTargetPos.m_fY;
					}
				}
			}
			else if( (*it)->m_fMoveSpeedY <= 0)
			{
				if((*it)->m_stPos.m_fY >= (*it)->m_stTargetPos.m_fY)
				{
					(*it)->m_stPos.m_fY += (*it)->m_fMoveSpeedY * dt;
					(*it)->m_fMoveSpeedY += (*it)->m_fPlusSpeedY * dt;
					if((*it)->m_stPos.m_fY <= (*it)->m_stTargetPos.m_fY)
					{
						(*it)->m_stPos.m_fY = (*it)->m_stTargetPos.m_fY;
					}
				}
			}
		}
		else if((*it)->m_eType == E_TEMPE_TYPE_TIMER)
		{
			(*it)->m_stPos.m_fY += (*it)->m_fMoveSpeedY * dt;
			(*it)->m_fMoveSpeedY += (*it)->m_fPlusSpeedY * dt;
		}
		
		(*it)->m_fLifeTimer += dt;
 		(*it)->m_pPlane->SetPos((*it)->m_stPos);

		if((*it)->m_bPassed == false)
		{
			if( fAskChange > 0 && (*it)->m_fMoveSpeedX <= 0)
			{
				(*it)->m_bPassed = true;
			}
			else if( fAskChange < 0 && (*it)->m_fMoveSpeedX >= 0)
			{
				(*it)->m_bPassed = true;
			}
		}
		else if((*it)->m_bPassed == true)
		{
			if( (*it)->m_fMoveSpeedX >= 0)
			{
				if( (*it)->m_stPos.m_fX >= (*it)->m_stTargetPos.m_fX )
				{
					if( (*it)->m_fMoveSpeedY >= 0)
					{
						if((*it)->m_stPos.m_fY >= (*it)->m_stTargetPos.m_fY)
						{
							(*it)->m_bFinished = true;
						}
					}
					else if( (*it)->m_fMoveSpeedY <= 0)
					{
						if((*it)->m_stPos.m_fY <= (*it)->m_stTargetPos.m_fY)
						{
							(*it)->m_bFinished = true;
						}
					}
				}
			}
			else if( (*it)->m_fMoveSpeedX <= 0)
			{
				if( (*it)->m_stPos.m_fX <= (*it)->m_stTargetPos.m_fX)
				{
					if( (*it)->m_fMoveSpeedY >= 0)
					{
						if((*it)->m_stPos.m_fY >= (*it)->m_stTargetPos.m_fY)
						{
							(*it)->m_bFinished = true;
						}
					}
					else if( (*it)->m_fMoveSpeedY <= 0)
					{
						if((*it)->m_stPos.m_fY <= (*it)->m_stTargetPos.m_fY)
						{
							(*it)->m_bFinished = true;
						}
					}
				}
			}

		}
	}

	for(it = m_TempeList.begin(); it != m_TempeList.end();)
	{
		bool bItPlus = true;

		if((*it)->m_eType == E_TEMPE_TYPE_NORMAL)
		{
			if((*it)->m_bPassed == true && (*it)->m_bFinished == true)
			{
				if((*it)->m_bDestroyFlag == true)
				{
					m_pThisScene->DeletePlane( (*it)->m_pPlane );
					delete (*it);
					
				}
				it = m_TempeList.erase(it);
				bItPlus = false;
			}
		}
		else if((*it)->m_eType == E_TEMPE_TYPE_TIMER)
		{
			if((*it)->m_fLifeTimer >= (*it)->m_fLifeTime)
			{
				if((*it)->m_bDestroyFlag == true)
				{
					m_pThisScene->DeletePlane( (*it)->m_pPlane );
					delete (*it);
				}
				it = m_TempeList.erase(it);
				bItPlus = false;
			}
		}

		if(bItPlus == true)
			it++;
	}
}

void CEMTempest::Exit()
{

}

void CEMTempest::Insert(CEMPlane* pPlane, stEMVec2 stPos, stEMVec2 stTargetPos, float fMoveSpeedX, float fPlusSpeedX, float fMoveSpeedY, float fPlusSpeedY, bool bDestroyFlag)
{
	stTempe* pTempTempe = new stTempe();
	pTempTempe->m_eType = E_TEMPE_TYPE_NORMAL;
	pTempTempe->m_pPlane = pPlane;
	pTempTempe->m_stPos = stPos;
	pTempTempe->m_stTargetPos = stTargetPos;
	pTempTempe->m_fMoveSpeedX = fMoveSpeedX;
	pTempTempe->m_fPlusSpeedX = fPlusSpeedX;
	pTempTempe->m_fMoveSpeedY = fMoveSpeedY;
	pTempTempe->m_fPlusSpeedY = fPlusSpeedY;
	pTempTempe->m_bPassed = false;
	pTempTempe->m_bFinished = false;
	pTempTempe->m_bDestroyFlag = bDestroyFlag;
	pTempTempe->m_fLifeTimer = 0.0f;
	pTempTempe->m_fLifeTime = 0.0f;

	m_TempeList.push_back(pTempTempe);


}
void CEMTempest::Insert_Time(CEMPlane* pPlane, stEMVec2 stPos, float fLifeTime, float fMoveSpeedX, float fPlusSpeedX, float fMoveSpeedY, float fPlusSpeedY, bool bDestroyFlag)
{
	stTempe* pTempTempe = new stTempe();
	pTempTempe->m_eType = E_TEMPE_TYPE_TIMER;
	pTempTempe->m_pPlane = pPlane;
	pTempTempe->m_stPos = stPos;
	pTempTempe->m_stTargetPos = stPos;
	pTempTempe->m_fMoveSpeedX = fMoveSpeedX;
	pTempTempe->m_fPlusSpeedX = fPlusSpeedX;
	pTempTempe->m_fMoveSpeedY = fMoveSpeedY;
	pTempTempe->m_fPlusSpeedY = fPlusSpeedY;
	pTempTempe->m_bPassed = false;
	pTempTempe->m_bFinished = false;
	pTempTempe->m_bDestroyFlag = bDestroyFlag;
	pTempTempe->m_fLifeTimer = 0.0f;
	pTempTempe->m_fLifeTime = fLifeTime;

	m_TempeList.push_back(pTempTempe);


}
