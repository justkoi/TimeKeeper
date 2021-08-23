#pragma once

#include "stdafx.h"
using namespace std;
typedef enum
{
	E_FACE_CDS,
	E_FACE_MGH,
	E_FACE_LUM,
	E_FACE_ARN,
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
	void Update(float dt);
	void Exit();

public:

	void ChatStart(int nIndex);
	void ChatEnd();//!< �޸� ���� �ؽ�Ʈ ����Ʈ ����

};
