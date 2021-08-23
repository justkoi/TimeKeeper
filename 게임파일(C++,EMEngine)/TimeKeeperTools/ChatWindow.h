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
	string strName;//!< 이름
	string strTalk;//!< 대화내용
}stTalk;
class CChatWindow
{
private:
	CEMPlane* m_pBlind;//!< 대화중에 약간 어둡게 만듬
	CEMPlane* m_pPlane;//!< 대화창
	CEMPlane* m_pFace[E_FACE_MAX];//!< 일러스트
	stEMVec2 m_FacePos[E_FACE_MAX];
	int m_nFaceLevel; //!< 일러스트 레벨

	int			m_nNowIndex; //!< 현재 어떤 NPC와의 대화인지,
	CEMText*		   m_CTextName;//!< 이름 표시
	CEMTextDisplay m_CTextDisplay; //!< 텍스트  표시
	bool		m_bFirstEnterd;//!< 첫번째 엔터 생략
public:
	vector<stTalk*> m_TalkList; //!< 대화 리스트

	int m_nMaxChatLevel;//!<대화 최고 레벨
	bool m_bEntered; //!< 눌럿다가

public:
	void Init(CRootScene* pThisScene);
	void Update(float dt);
	void Exit();

public:

	void ChatStart(int nIndex);
	void ChatEnd();//!< 메모리 해제 텍스트 리스트 해제

};
