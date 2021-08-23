#include "stdafx.h"

void CInventory::Init(CRootScene* pThisScene, int nMaxItemNumber)
{
	m_pThisScene = pThisScene;
	m_nMaxItemNumber = nMaxItemNumber;
	for(int i=0; i<D_INVENTORY_HEIGHT; i++)
	{
		for(int j=0; j<D_INVENTORY_WIDTH; j++)
		{
			m_pInventory[i][j].Init(m_pThisScene,stVec2i(j,i),0,1);
			m_pInventory[i][j].Empty();
			m_pItemBox[i][j] = new CEMPlane();
			m_pItemBox[i][j]->SetTexture(pThisScene,"Data/Image/Item/Item_Box.png");
			m_pItemBox[i][j]->SetSize(1.0f,1.0f);
			m_pItemBox[i][j]->SetPos(D_INVENTORY_START_X + (D_ITEM_WIDTH*j),D_INVENTORY_START_Y + (D_ITEM_HEIGHT*i));
			m_pItemBox[i][j]->SetBlend(true);
			m_pItemBox[i][j]->SetOrtho2D(true);
			pThisScene->Commit(-1002,(i*D_INVENTORY_WIDTH) + j,"Item_Box", m_pItemBox[i][j]);
		}
	}
}


void CInventory::Update(float dt)
{
	for(int i=0; i<D_INVENTORY_HEIGHT; i++)
	{
		for(int j=0; j<D_INVENTORY_WIDTH; j++)
		{
			m_pInventory[i][j].Update(dt);
			m_pItemBox[i][j]->SetShow(g_bPause);
			if(g_PauseWindowState != E_PAUSEWINDOW_BUTTON_ITEM)
			{
				m_pItemBox[i][j]->SetShow(false);
			}
		}
	}
}

stVec2i CInventory::SearchSpace() //!< 가장 가까운 빈 공간을 찾는다. 존재하지 않을경우 -1 리턴;
{
	for(int i=0; i<D_INVENTORY_HEIGHT; i++)
	{
		for(int j=0; j<D_INVENTORY_WIDTH; j++)
		{
			if(m_pInventory[i][j].m_stPos.m_fX == -1 || m_pInventory[i][j].m_stPos.m_fY == -1)
			{
				return stVec2i(j,i);
			}
		}
	}
	return stVec2i(-1,-1);
}
stVec2i CInventory::SearchItem_All(int nIndex) //!< 가장 가까운 해당 아이템을 찾는다. 존재하지 않을경우 -1 리턴; 단, 해당 아이템의 개수가 full일경우 무효
{
	for(int i=0; i<D_INVENTORY_HEIGHT; i++)
	{
		for(int j=0; j<D_INVENTORY_WIDTH; j++)
		{
			if(m_pInventory[i][j].m_nIndex == nIndex)
			{
				return stVec2i(j,i);
			}
		}
	}
	return stVec2i(-1,-1);
}
stVec2i CInventory::SearchItem_NoFull(int nIndex) //!< 가장 가까운 해당 아이템을 찾는다. 존재하지 않을경우 -1 리턴; 단, 해당 아이템의 개수가 full일경우 무효
{
	for(int i=0; i<D_INVENTORY_HEIGHT; i++)
	{
		for(int j=0; j<D_INVENTORY_WIDTH; j++)
		{
			if(m_pInventory[i][j].m_nIndex == nIndex && m_pInventory[i][j].m_nNumber < m_nMaxItemNumber)
			{
				return stVec2i(j,i);
			}
		}
	}
	return stVec2i(-1,-1);
}

bool CInventory::Push_Item(int nIndex, int nNumber) //!< 성공여부
{
	
	stVec2i stTemp = SearchItem_NoFull(nIndex); //!< 동일아이템을 찾는다.
	if(stTemp.m_fX == -1 || stTemp.m_fY == -1) //!< 동일아이템이 없다.
	{
		stTemp = SearchSpace();
		if(stTemp.m_fX == -1 || stTemp.m_fY == -1) //!< 빈공간이 없다.
		{
			return false;						//!< false리턴
		}
		else
		{
			if(nNumber <= m_nMaxItemNumber) //!< 넣으려는 아이템이 최대개수보다 작거나 같다
				m_pInventory[stTemp.m_fY][stTemp.m_fX].Create(stTemp,nIndex,nNumber); //!< 빈공간은 있다. 해당 위치에 아이템을 만들어 넣는다.
			else//!< 그렇지 않다면
			{
				while(nNumber > 0) //!< 넣으려는 현재 아이템을 빼면서 0이 될때까지 최대개수 만큼씩만을 구해서 넣는다.
				{
					int nMaxPushNumber = nNumber; //!< 넣을수있는 최대 개수
					if(nMaxPushNumber > m_nMaxItemNumber)
						nMaxPushNumber = m_nMaxItemNumber;
					m_pInventory[stTemp.m_fY][stTemp.m_fX].Create(stTemp,nIndex,nMaxPushNumber); //!< 빈공간은 있다. 해당 위치에 아이템을 만들어 넣는다.
					nNumber -= nMaxPushNumber; //!< 넣은만큼 빼준다.
					stTemp = SearchSpace(); //!< 재검사 
					if(stTemp.m_fX == -1 || stTemp.m_fY == -1)//!< 예외일경우 false리턴 (넣을 곳이 없습니다.)
					{
						return false;
					}
				}
			}
		}
	}
	else //!< 동일 아이템이 있다.
	{
		if(m_pInventory[stTemp.m_fY][stTemp.m_fX].m_nNumber + nNumber <= m_nMaxItemNumber) //!< 넣으려는 아이템이 최대개수보다 작거나 같다
			m_pInventory[stTemp.m_fY][stTemp.m_fX].m_nNumber += nNumber;
		else
		{
			while(nNumber > 0)
			{
				m_pInventory[stTemp.m_fY][stTemp.m_fX].m_nNumber += m_nMaxItemNumber - m_pInventory[stTemp.m_fY][stTemp.m_fX].m_nNumber;
				nNumber -= m_nMaxItemNumber - m_pInventory[stTemp.m_fY][stTemp.m_fX].m_nNumber;
				stTemp = SearchItem_NoFull(nIndex);
				if(stTemp.m_fX == -1 || stTemp.m_fY == -1)
				{
					return false;
				}
			}
		}
	}
}
bool CInventory::Pull_Item(int nIndex, int nNumber) //!< 성공여부 //!< 해당 아이템을 해당개수만큼 뺄수 있다 = true else false 리턴
//!< nIndex의 아이템을 nNumber만큼 빼옵니다. 결과 아이템에서 -합니다.
{
	return false;
}