#pragma once

#include "Scene.h"
#include "SceneWorkMng.h"


#include "EMString.h"

#define TRUE 1
#define FALSE 0

class CSceneWorkMng;

enum
{
	E_RETURN_SUCESS = 0,
	E_RETURN_NAME_OVERLAP,
	E_RETURN_POINT_NULL,
	E_RETURN_MAX
};

enum enumFadeState
{
	E_FADE_IN_BEGIN = 0,
	E_FADE_OUT_BEGIN = 10,
	E_FADE_END,
};

/************************************************************************/
/* FrameWork
/************************************************************************/
class CSceneWork : public CSceneWorkMng
{
private:
	CRootScene*	m_pCurrentScene;			//!< 현재 상태
	std::vector<CRootScene*> m_pstdScene;	//!< 씬 추가
	bool m_nFirstEnter;						//!< 씬 처음 시작할때체크 Flag

	CEMPlane* m_pPlaneFadeInOut;

	bool m_bSceneChangeOn;					//!< 씬 교체해야되는 상황인지 아닌지 파악
	stdEMString m_strChangeSceneName;		//!< 교체할 씬의 이름을 저장해 둔다.

	float m_fLayerDepthLength;				//!< 각레이어들 마다의 깊이 값 조절

	bool m_bFade;
	enumFadeState m_FadeState;

	float m_fDeltaTime;
	float m_fFadeInTime;
	float m_fFadeOutTime;
	float m_fFadeAlpha;

	CEMColor m_FadeInColor;
	CEMColor m_FadeOutColor;

public:
	float	m_fDt;

protected:
	CSceneWork();

public:
	CSceneWork(int ID);
	virtual ~CSceneWork(void);
	static CSceneWork* Instance();

	virtual void Update(float dt);
	virtual void Render();
	
	void SetLayerDepth(float fLength)					{m_fLayerDepthLength = fLength;}
	float GetLyaerDepth()								{return m_fLayerDepthLength;}

	void SetChangeSceneName(stdEMString strName)		{ m_strChangeSceneName = strName;}
	stdEMString GetChangeSceneName()					{ return m_strChangeSceneName;   } 

	void SetSceneChangeOn(bool m_bChange)				{m_bSceneChangeOn = m_bChange;}
	bool GetSceneChangeOn()								{return m_bSceneChangeOn;}

	void SetFadeOn(bool bFade)							{m_bFade = bFade;}
	bool GetFadeOn()									{return m_bFade;}

	/**
	@brief 상태정보를 갱신합니다.(m_pCurrentState)에 상태를 포인터로 연결한다.
	@param sSceneName : 갱신하고자 하는 씬 이름
	@param 
	@param 
	@param 
	@param 
	@return void
	*/
	void ChangeScene( stdEMString sSceneName );
	/**
	@brief 상태정보를 갱신합니다.(m_pCurrentState)에 상태를 포인터로 연결한다.
	@param sSceneName : 갱신하고자 하는 씬 이름
	@param fade in time	: (tick per second) 넣어준값(초) 마다 변합니다.
	@param fade out time : (tick per second) 넣어준값(초) 마다 변합니다.
	@param fade in color
	@param fade out color
	@return void
	*/
	void ChangeSceneFade( stdEMString sSceneName, float fInTime = 0.06f, float fOutTime = 0.06f, CEMColor& InColor = CEMColor(0, 0, 0, 1), CEMColor& OutColor = CEMColor(0, 0, 0, 1));

	/**
	@brief 메모리 제거(추가한 씬정보 자동 제거 되므로 제거 하실 필요 없어요)
	@param 
	@param 
	@param 
	@param 
	@param 
	@return 없음
	*/
	void Release();

	/**
	@brief 씬 클래스를 추가합니다.
	       제일 처음 실행되는 씬은 처음 등록한 씬이 자동으로 실행됩니다

	@param pNewScene : 새로운 씬 클래스 추가
	@param sSceneName : 씬 이름 추가
	@param	
	@param 
	@param 
	@return E_RETURN_SUCESS : 추가 성공, E_RETURN_NAME_OVERLAP : 같은 씬이름 존재(실패) 2, 
	*/
	int Commit( CRootScene* pNewScene, stdEMString sSceneName );

	/**
	@brief 씬중복 체크
	@param 
	@param 
	@param 
	@param 
	@param 
	@return 씬 정보 중복일경우 true리턴 중복 아닐 경우 false리턴 
	*/
	bool SceneOverlapChk(stdEMString sSceneName);

	/**
	@brief 추가되어진 씬 개수
	@param 
	@param 
	@param 
	@param 
	@param 
	@return 추가되어진 씬 ㅎ개수
	*/
	int SceneTotals();

	/**
	@brief 씬 이름에 해당하는 씬의 포인터를 알아온다. 이히^^^
	@param sSceneName : 찾을 씬
	@param 
	@param 
	@param 
	@param 
	@return 찾은 씬
	*/
	CRootScene* GetScene(stdEMString sSceneName);

	/**
	@brief 상태정보를 포인터를 얻어 오기
	@return CRootScene*
	*/
	CRootScene* GetCurScene()	{ return m_pCurrentScene; }
};

