#pragma once

#include "stdafx.h"
class CBlokingBlock;
class CPortal;
class CObject;
typedef struct
{
	int m_nTileMap;
	CEMPlane* m_pTileMap;
}stTileMap;

class CHero;
class CNPC;
class CPartMap
{
private:
	int m_nIndex; //!< 맵 번호
	int m_nWidth;
	int m_nHeight;
	
	stTileMap** m_aTileMap; //!< 타일맵 2차원배열 동적할당.
public:
	CRootScene* m_pThisScene;

	list<CBlokingBlock*> m_BlokingMap; //!< 블로킹 블록 보관
	list<CPortal*>		m_PortalMap; //!< 포탈 보관
	list<CNPC*>		m_NPCMap; //!< NPC 보관
	list<CObject*> m_ObjectList; //!< Object 보관

	int getMapWidth();
	int getMapHeight();

	int getIndex();

public:
	void Init(CRootScene* pThisScene, int nIndex, CHero* CTargetHero); //!< 타일맵을 읽어들입니다.
	void Update(float dt); //!< 할거없는듯.
	void Exit(); //!< 동적메모리해제
	void Exit_End(); //!< 동적메모리해제
public:

};