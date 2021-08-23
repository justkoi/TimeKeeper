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
	int m_nIndex; //!< �� ��ȣ
	int m_nWidth;
	int m_nHeight;
	
	stTileMap** m_aTileMap; //!< Ÿ�ϸ� 2�����迭 �����Ҵ�.
public:
	CRootScene* m_pThisScene;

	list<CBlokingBlock*> m_BlokingMap; //!< ���ŷ ��� ����
	list<CPortal*>		m_PortalMap; //!< ��Ż ����
	list<CNPC*>		m_NPCMap; //!< NPC ����
	list<CObject*> m_ObjectList; //!< Object ����

	int getMapWidth();
	int getMapHeight();

	int getIndex();

public:
	void Init(CRootScene* pThisScene, int nIndex, CHero* CTargetHero); //!< Ÿ�ϸ��� �о���Դϴ�.
	void Update(float dt); //!< �Ұž��µ�.
	void Exit(); //!< �����޸�����
	void Exit_End(); //!< �����޸�����
public:

};