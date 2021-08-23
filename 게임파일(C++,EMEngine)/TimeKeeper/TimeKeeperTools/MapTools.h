#pragma once

#include "stdafx.h"
typedef struct
{
	int m_nTileMap;
	CEMPlane* m_pTileMap;
}stTileMap;
typedef struct
{
	int m_nIndex;
	stEMVec2 m_stPos;
	CEMPlane* m_pNPC;
}stNPC;
typedef enum
{
	E_EDIT_MOD_TILE,
	E_EDIT_MOD_NPC
}E_EDIT_MOD;
class CMapTools
{
private:
	CEMText* m_pTextIndex;
	CEMPlane*   m_pInterface;


	
	CEMText* m_pTextMsg; //!< ��� "���� ���õ� ��ü"
	CEMText* m_pTextMsg2; //!< ��� "TAB"
	int			m_nNowSelectTile;
	CEMPlane*   m_pNowSelectTile;
	
	int			m_nNowSelectNPC;
	CEMPlane*   m_pNowSelectNPC;

	CEMText* m_pTextWidth;
	CEMText* m_pTextHeight;

	CRootScene* m_pThisScene; //!< ���� ��

	stTileMap** m_aTileMap; //!< Ÿ�ϸ� 2�����迭 �����Ҵ�.

	float		m_fMoveSpeed;//! < ī�޶� �̵��ӵ�
	list<stNPC*> m_NPCList;//!< NPC����Ʈ����
	bool		m_bNPCPlaceAble[D_MAX_NPC];//!< NPC��ġ����
public:
	E_EDIT_MOD m_eEditMod;

	int m_nNumberFocus;//!< ������Ŀ��
	bool		m_bNowDrag; //!< Ÿ�� ��ġ�� �巡���� �ΰ�?
	
	int m_nWidth;//!< �� ����ũ��
	int m_nHeight;//!< �� ����ũ��

	int m_nIndex;//!< ���� �� ��ȣ
public:

	void SelectTile(int nIndex);
	void TabTile();

public:

	void Init(CRootScene* pThisScene);
	void Update(float dt);
	void Exit();

	void CheckDown(stEMVec2 stPos);
	void CheckMove(stEMVec2 stPos);
	void CheckUp(stEMVec2 stPos);
public:
	
	void LoadData();
	void SaveData();


};