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


	
	CEMText* m_pTextMsg; //!< 출력 "현재 선택된 개체"
	CEMText* m_pTextMsg2; //!< 출력 "TAB"
	int			m_nNowSelectTile;
	CEMPlane*   m_pNowSelectTile;
	
	int			m_nNowSelectNPC;
	CEMPlane*   m_pNowSelectNPC;

	CEMText* m_pTextWidth;
	CEMText* m_pTextHeight;

	CRootScene* m_pThisScene; //!< 현재 씬

	stTileMap** m_aTileMap; //!< 타일맵 2차원배열 동적할당.

	float		m_fMoveSpeed;//! < 카메라 이동속도
	list<stNPC*> m_NPCList;//!< NPC리스트저장
	bool		m_bNPCPlaceAble[D_MAX_NPC];//!< NPC배치가능
public:
	E_EDIT_MOD m_eEditMod;

	int m_nNumberFocus;//!< 숫자포커스
	bool		m_bNowDrag; //!< 타일 배치중 드래그중 인가?
	
	int m_nWidth;//!< 맵 가로크기
	int m_nHeight;//!< 맵 세로크기

	int m_nIndex;//!< 현재 맵 번호
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