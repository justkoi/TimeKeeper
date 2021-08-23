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

stVec2i CInventory::SearchSpace() //!< ���� ����� �� ������ ã�´�. �������� ������� -1 ����;
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
stVec2i CInventory::SearchItem_All(int nIndex) //!< ���� ����� �ش� �������� ã�´�. �������� ������� -1 ����; ��, �ش� �������� ������ full�ϰ�� ��ȿ
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
stVec2i CInventory::SearchItem_NoFull(int nIndex) //!< ���� ����� �ش� �������� ã�´�. �������� ������� -1 ����; ��, �ش� �������� ������ full�ϰ�� ��ȿ
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

bool CInventory::Push_Item(int nIndex, int nNumber) //!< ��������
{
	
	stVec2i stTemp = SearchItem_NoFull(nIndex); //!< ���Ͼ������� ã�´�.
	if(stTemp.m_fX == -1 || stTemp.m_fY == -1) //!< ���Ͼ������� ����.
	{
		stTemp = SearchSpace();
		if(stTemp.m_fX == -1 || stTemp.m_fY == -1) //!< ������� ����.
		{
			return false;						//!< false����
		}
		else
		{
			if(nNumber <= m_nMaxItemNumber) //!< �������� �������� �ִ밳������ �۰ų� ����
				m_pInventory[stTemp.m_fY][stTemp.m_fX].Create(stTemp,nIndex,nNumber); //!< ������� �ִ�. �ش� ��ġ�� �������� ����� �ִ´�.
			else//!< �׷��� �ʴٸ�
			{
				while(nNumber > 0) //!< �������� ���� �������� ���鼭 0�� �ɶ����� �ִ밳�� ��ŭ������ ���ؼ� �ִ´�.
				{
					int nMaxPushNumber = nNumber; //!< �������ִ� �ִ� ����
					if(nMaxPushNumber > m_nMaxItemNumber)
						nMaxPushNumber = m_nMaxItemNumber;
					m_pInventory[stTemp.m_fY][stTemp.m_fX].Create(stTemp,nIndex,nMaxPushNumber); //!< ������� �ִ�. �ش� ��ġ�� �������� ����� �ִ´�.
					nNumber -= nMaxPushNumber; //!< ������ŭ ���ش�.
					stTemp = SearchSpace(); //!< ��˻� 
					if(stTemp.m_fX == -1 || stTemp.m_fY == -1)//!< �����ϰ�� false���� (���� ���� �����ϴ�.)
					{
						return false;
					}
				}
			}
		}
	}
	else //!< ���� �������� �ִ�.
	{
		if(m_pInventory[stTemp.m_fY][stTemp.m_fX].m_nNumber + nNumber <= m_nMaxItemNumber) //!< �������� �������� �ִ밳������ �۰ų� ����
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
bool CInventory::Pull_Item(int nIndex, int nNumber) //!< �������� //!< �ش� �������� �ش簳����ŭ ���� �ִ� = true else false ����
//!< nIndex�� �������� nNumber��ŭ ���ɴϴ�. ��� �����ۿ��� -�մϴ�.
{
	return false;
}