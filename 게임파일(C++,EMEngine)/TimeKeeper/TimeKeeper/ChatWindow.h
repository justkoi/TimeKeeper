#pragma once

#include "stdafx.h"
using namespace std;
class CInventory;
typedef enum
{
	E_FACE_KJH_NONE,
	E_FACE_KJH_WORRY,
	E_FACE_HUMAN_1,
	E_FACE_HUMAN_2,
	E_NOTICE,
	E_FACE_ROYAL_FORCES,
	E_FACE_LSY,
	E_FACE_HNPC1,
	E_FACE_HNPC2,
	E_FACE_HNPC3,
	E_FACE_MAX
}E_FACE_NUM;
typedef struct
{
	int nLeftFace;
	int nRightFace;
	string strName;//!< �̸�
	string strTalk;//!< ��ȭ����
}stTalk;
class CChatWindow
{
private:
	CEMPlane* m_pBlind;//!< ��ȭ�߿� �ణ ��Ӱ� ����
	CEMPlane* m_pPlane;//!< ��ȭâ
	CEMPlane* m_pSelect; //< ����Ʈ ǥ��

	bool m_bSelect;
	int m_nSelect;

	CEMPlane* m_pFace[E_FACE_MAX];//!< �Ϸ���Ʈ
	stEMVec2 m_FacePos[E_FACE_MAX];
	int m_nFaceLevel; //!< �Ϸ���Ʈ ����

	int			m_nNowIndex; //!< ���� � NPC���� ��ȭ����,
	CEMText*		   m_CTextName;//!< �̸� ǥ��
	CEMTextDisplay m_CTextDisplay; //!< �ؽ�Ʈ  ǥ��
	bool		m_bFirstEnterd;//!< ù��° ���� ����
public:
	vector<stTalk*> m_TalkList; //!< ��ȭ ����Ʈ

	int m_nMaxChatLevel;//!<��ȭ �ְ� ����
	bool m_bEntered; //!< �����ٰ�

public:
	void Init(CRootScene* pThisScene);
	void Update(float dt, CInventory* Inventory);
	void Exit();

public:

	void ChatStart(int nIndex);
	void ChatSelect(int nIndex);
	void ChatEnd();//!< �޸� ���� �ؽ�Ʈ ����Ʈ ����

};
