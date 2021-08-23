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
	CRootScene*	m_pCurrentScene;			//!< ���� ����
	std::vector<CRootScene*> m_pstdScene;	//!< �� �߰�
	bool m_nFirstEnter;						//!< �� ó�� �����Ҷ�üũ Flag

	CEMPlane* m_pPlaneFadeInOut;

	bool m_bSceneChangeOn;					//!< �� ��ü�ؾߵǴ� ��Ȳ���� �ƴ��� �ľ�
	stdEMString m_strChangeSceneName;		//!< ��ü�� ���� �̸��� ������ �д�.

	float m_fLayerDepthLength;				//!< �����̾�� ������ ���� �� ����

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
	@brief ���������� �����մϴ�.(m_pCurrentState)�� ���¸� �����ͷ� �����Ѵ�.
	@param sSceneName : �����ϰ��� �ϴ� �� �̸�
	@param 
	@param 
	@param 
	@param 
	@return void
	*/
	void ChangeScene( stdEMString sSceneName );
	/**
	@brief ���������� �����մϴ�.(m_pCurrentState)�� ���¸� �����ͷ� �����Ѵ�.
	@param sSceneName : �����ϰ��� �ϴ� �� �̸�
	@param fade in time	: (tick per second) �־��ذ�(��) ���� ���մϴ�.
	@param fade out time : (tick per second) �־��ذ�(��) ���� ���մϴ�.
	@param fade in color
	@param fade out color
	@return void
	*/
	void ChangeSceneFade( stdEMString sSceneName, float fInTime = 0.06f, float fOutTime = 0.06f, CEMColor& InColor = CEMColor(0, 0, 0, 1), CEMColor& OutColor = CEMColor(0, 0, 0, 1));

	/**
	@brief �޸� ����(�߰��� ������ �ڵ� ���� �ǹǷ� ���� �Ͻ� �ʿ� �����)
	@param 
	@param 
	@param 
	@param 
	@param 
	@return ����
	*/
	void Release();

	/**
	@brief �� Ŭ������ �߰��մϴ�.
	       ���� ó�� ����Ǵ� ���� ó�� ����� ���� �ڵ����� ����˴ϴ�

	@param pNewScene : ���ο� �� Ŭ���� �߰�
	@param sSceneName : �� �̸� �߰�
	@param	
	@param 
	@param 
	@return E_RETURN_SUCESS : �߰� ����, E_RETURN_NAME_OVERLAP : ���� ���̸� ����(����) 2, 
	*/
	int Commit( CRootScene* pNewScene, stdEMString sSceneName );

	/**
	@brief ���ߺ� üũ
	@param 
	@param 
	@param 
	@param 
	@param 
	@return �� ���� �ߺ��ϰ�� true���� �ߺ� �ƴ� ��� false���� 
	*/
	bool SceneOverlapChk(stdEMString sSceneName);

	/**
	@brief �߰��Ǿ��� �� ����
	@param 
	@param 
	@param 
	@param 
	@param 
	@return �߰��Ǿ��� �� ������
	*/
	int SceneTotals();

	/**
	@brief �� �̸��� �ش��ϴ� ���� �����͸� �˾ƿ´�. ����^^^
	@param sSceneName : ã�� ��
	@param 
	@param 
	@param 
	@param 
	@return ã�� ��
	*/
	CRootScene* GetScene(stdEMString sSceneName);

	/**
	@brief ���������� �����͸� ��� ����
	@return CRootScene*
	*/
	CRootScene* GetCurScene()	{ return m_pCurrentScene; }
};

