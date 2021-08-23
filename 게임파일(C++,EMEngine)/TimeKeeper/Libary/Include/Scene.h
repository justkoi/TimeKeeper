#pragma once

#include "EMString.h"
#include "EMASE.h"

typedef enum e_collision_type
{
	E_SPHERE_VS_SPHERE,		//!< ���뱸 �浹
	E_BOX_VS_BOX,			//!< �ڽ��� �ڽ� �浹
	E_SPHERE_VS_BOX			//!< ���� �ڽ� �浹
}E_COLLISION_TYPE;

typedef enum e_collision_face
{
	E_COLL_LEFT_FACE,		//!< ���� ��
	E_COLL_RIGHT_FACE,		//!< ������ ��
	E_COLL_UP_FACE,			//!< 2010�� 7�� �������� ���� �߰� ���� �Ϸ���~~ ��(���� ���� �ڷ��� �����...)
	E_COLL_DOWN_FACE,		//!< 2010�� 7�� �������� ���� �߰�
	E_COLL_ALL_FACE			//!< ���� 
}E_COLLISION_FACE;

typedef enum e_curscenestate
{
	E_ENTER,
	E_UPDATE,
	E_RENDER,
	E_EXIT,
	E_SCENE_STATE
}E_CURSCENE_STATE;

using namespace std;

class CSceneWork;
class CEMAnimation;
class CEMWindow;			// ������
class CEMAseImport;

typedef std::map<stdEMString, CEMPlane*> stdPlane;
typedef pair<stdEMString, CEMPlane*> stdPlanePair;
typedef pair<stdEMString, CEMWindow*> stdUserInterfacePair;		//!< ������

class CRootScene : public CEMPhysicRoot
{
private:
	stdEMString			m_sSceneName;
	E_CURSCENE_STATE	m_eCruScene;

protected:
	//! ȭ�鿡 ����� plane���� ��� �̰��� add�ϸ� �˴ϴ٤�. 
	std::map<int, stdPlane> m_stdPlaneList;								//!< ���� �� ȭ�鿡 ��� �Ǿ��� ������Ʈ��
	std::map<stdEMString, stTextureCacheEntry> m_stdTextureList;		//!< ���� �� ȭ�鿡�� ���Ǿ��� �ؽ��ĵ�
	
	std::map<stdEMString, CEMWindow*> m_stdUserInterfacelist;			//!< ��Ͻ�Ų ��� UI����ü ������
	std::list<CEMWindow*> m_stdDynamicList;								//!< dynamic �����츸 �����ϴ� list ������
	std::list<CEMWindow*> m_stdStaticList;								//!< static �����츸 �����ϴ� list ������
	CEMWindow* m_pCurrentUI;											//!< ���� ���õ� ui ������
	CEMWindow* m_pOverlapUI;											//!< ���� ���콺�� �ö�� ui ������

	Settings m_PhysicSetting;

public:
	std::map<stdEMString, CEMAseImport*> m_stdASEList;					//!< ���� �� ȭ�鿡�� ���Ǿ��� ASE���� ����Ÿ �Դϴ� (�Ѱ����� ����) �ߺ��ε�������^^
	
public:
	CRootScene(void)
	{
		m_eCruScene = E_ENTER;
		m_pCurrentUI = NULL;
		m_pOverlapUI = NULL;
	};
	virtual ~CRootScene
		(

		);

public:
	E_CURSCENE_STATE GetCurSceneState()		{return m_eCruScene;}
private:

	/**
	@brief BoundingBox ������ݴϴ�(�������� ���)
	@return ����
	*/
	void RenderBBox(CEMAnimation* pAni);

	/**
	@brief �������� �ø� ���
		   ���ο��� ����Ͽ� Show(true) Show(false) ����
	@return ����
	*/
	void FrustumCullingCalc(CEMPlane* pPlane);

		/**
	@brief �������� �ø� ���
		   ���ο��� ����Ͽ� Show(true) Show(false) ����
	@return ����
	*/
	void FrustumCullingCalc(CEMAse* pAse);

/**
	@brief �ٿ�� �ڽ� ���
	@param CEMPlane* pPlane : ����� plane
	@return ����
	*/
	void BoundingBoxCalc(CEMPlane* pPlane);			
	
	/**
	@brief 
	@param GLint ClampMode : 
	@param GLint FilterMode : 
	@return GLUint ���̵�
	*/
	GLuint BindTexImageWithClampAndFilter(GLint ClampMode, GLint FilterMode);
	
	/**
	@brief OGL�� ����Ǿ��� �ؽ��ĸ� �� �����ݴϴ�.
	@return ����
	*/	
	void TextureRelease();

	/**
	@brief �о���� ��� ASE������ �����մϴ�.
	@return ����
	*/	
	void ASERelease();

	/**
	@brief ���뱸 �浹 : 
		   �ڽ��� �ڽ� : fA�� fB�� m_fZ���� ���ƾ� �� ����� �˴ϴ�.(����)
		   ���� �ڽ� : 
	@return ����
	*/	
	bool SpherevsSphere(stEMBoundingBox fA, stEMBoundingBox fB);

	/**
	@brief �ڽ��� �ڽ� �浹
		   �ڽ��� �ڽ� : fA�� fB�� m_fZ���� ���ƾ� �� ����� �˴ϴ�.(����)
	@param E_COLLISION_FACE eFace : ���� �� or ������ ��
	@param float fScope : ����(������ �˻� ���� Or ���� �˻� ����)
	@param fA : ���ΰ�
	@param fB : ������Ʈ
	@return ����
	*/	
	bool AABBvsAABB(E_COLLISION_FACE eFace, float fScope, stEMBoundingBox fA, stEMBoundingBox fB);
	bool SpherevsAABB(E_COLLISION_FACE eFace, float fScope,stEMBoundingBox fA, stEMBoundingBox fB);


public:

	/**
	@brief aabb�� ray�� �浹�����Դϴ�

	@param nX : ���콺 x��ǥ
	@param nY : ���콺 y��ǥ
	@param nLayerScope : -1�̸� ��� ���̾� �˻� 0�̸� 0�����̾ �˻� 1�̸� 1�����̾�˻� ^^
	@param 
	@return �浹�ߴٸ� CEMPlane*����
	*/	
	CEMPlane* AABBvsRay(int nX, int nY, int nLayerScope = -1);
	CEMPlane* AABBvsRay(stEMVec3 stPos, int nLayerScope = -1);

	/**
	@brief �浹���� ����
		   : nScope�� -1�̸� ��ü���̾�� �浹 ó���� �Ѵ�. 
		     (��) pPlane�� ���� 1�����̾��� 1�����̾�ִ� Plane���� �浹 ó�� ���� �ʴ´�. 

			 CHero������ -1���̾�ٰ� ����� �浹�� �ʵ��� 0�����̾ �������Ѵ�. ���� 0�����̾ ����� �浹 ���� �ʴ´�. -1�������

    @param E_COLLISION_FACE eFace : E_COLL_LEFT_FACE(���� �� �˻�),E_COLL_RIGHT_FACE(������ �� �˻�)
	@param float fScope : �˻� ����
	@param E_COLLISION_TYPE eType : E_SPHERE_VS_SPHERE, E_BOX_VS_BOX, E_SPHERE_VS_BOX
	@param CEMPlane* pPlane : �浹ó���ҳ�
	@param int nLayerScope = 0	0�̸� 0�����̾ �浹ó�� ���� �Ѵٴ� �ǹ�����  -1�̸� ��� ������Ʈ �浹 ó���մϴ�(ȭ�鿡 ���̴� ��鸸)
	@return �浹�Ǿ��� �����Ͱ� �Ѿ�´�.
	*/
	CEMPlane* IsCollision(E_COLLISION_FACE eFace, float fScope, E_COLLISION_TYPE eType, CEMPlane* pPlane, int nLayerScope = 0);

/**
	@brief �浹���� ����
		   : nScope�� -1�̸� ��ü���̾�� �浹 ó���� �Ѵ�. 
		     (��) pPlane�� ���� 1�����̾��� 1�����̾�ִ� Plane���� �浹 ó�� ���� �ʴ´�. 

			 CHero������ -1���̾�ٰ� ����� �浹�� �ʵ��� 0�����̾ �������Ѵ�. ���� 0�����̾ ����� �浹 ���� �ʴ´�. -1�������

	@param E_COLLISION_TYPE eType : E_SPHERE_VS_SPHERE, E_BOX_VS_BOX, E_SPHERE_VS_BOX
	@param CEMPlane* pPlane : CEMPlane�� �ɼ��� �ְ� CEMPlane�� ���ڰ����� �Ѿ ���� �ִ�.
	@param int nLayerScope = 0	0�̸� 0�����̾ �浹ó�� ���� �Ѵٴ� �ǹ�����  -1�̸� ��� ������Ʈ �浹 ó���մϴ�(ȭ�鿡 ���̴� ��鸸)
	@return �浹�Ǿ��� �����Ͱ� �Ѿ�´�.
	*/
	CEMPlane* IsCollision( E_COLLISION_TYPE eType, CEMPlane* pPlane, int nLayerScope = 0);


	/**
	@brief �浹���� ����
		   : nScope�� -1�̸� ��ü���̾�� �浹 ó���� �Ѵ�. 
		     (��) pPlane�� ���� 1�����̾��� 1�����̾�ִ� Plane���� �浹 ó�� ���� �ʴ´�. 

			 CHero������ -1���̾�ٰ� ����� �浹�� �ʵ��� 0�����̾ �������Ѵ�. ���� 0�����̾ ����� �浹 ���� �ʴ´�. -1�������

	@param CEMPlane* pPlane : CEMPlane�� �ɼ��� �ְ� CEMPlane�� ���ڰ����� �Ѿ ���� �ִ�.
	@param int nLayerScope = 0	0�̸� 0�����̾ �浹ó�� ���� �Ѵٴ� �ǹ�����  -1�̸� ��� ������Ʈ �浹 ó���մϴ�(ȭ�鿡 ���̴� ��鸸)
	@return �浹�Ǿ��� �����Ͱ� �Ѿ�´�.
	*/

	CEMPlane* IsCollision(CEMPlane* pPlane, int nLayerScope = 0);

	/**
	@brief ����� ��Ʈ�� ��ġ���� ������ �մϴ�(ȭ������ ����Ǿ�����)(�������� ȣ��)
	@return ����
	*/
	void CalcFontPos();

	/**
	@brief 
	@param stdEMString strFileName : �о���� �����̸�
	@param GLint nClampMode=GL_CLAMP : clamp
	@param GLint nFilterMode=GL_LINEAR :  FilterMode
	@param int* nWidth = NULL : �׸� ����
	@param int* nHeight = NULL : �׸� ���� 
	@param bool bOptional = FALSE : �ɼ�(�̻��)
	@param
	@return ����
	*/
	int  GetTextureReference(stdEMString strFileName, GLint nClampMode=GL_CLAMP, GLint nFilterMode=GL_LINEAR, int* nWidth = NULL, int* nHeight = NULL, bool bOptional = FALSE);
	
	/**
	@brief new�� ������ Plane�� �߰��մϴ�
		   [���ǻ���]
				�߰��� stdPlaneName�� �̸��� �̹� �߰� �Ǿ��ִٸ� �߰��Ҽ� �����ϴ�. 
				���� �̸��� ���ؾ��� �߰����� ���� Plane�� �ڵ� �޸� ���� �˴ϴ�
				�߰����� ���ϰ� �޸� ������ �ǹǷ� �����Ͻñ� �ٶ��ϴ�.


			[�ʵ�]
				nLayer�� ���� ������ ������ �ִ� Plane���� �־��ְ� ���� ������
				�ָ��ִ� ������ �־��ּ���

				0�����̾ �� 100���� Plane���� �ִٸ�, ��¿켱������ 
				�Ʒ��� stdPlaneName�� ���� �����ȴ�. "0_plane" "1_plane"�ΰ��� 
				plane�� �ִٸ� 0_plane�� ���� ��µǰ� �� �� �� 1_plane�� ��µȴ�. 

	@param nLayer
	@param stdPlaneName
	@param pPlane
	@param 
	@param 
	@return void* �߰��� plane�� �����͸� �����Ѵ�. �߰� ���� ���޴ٸ� pPlane �� delete�� �� NULL�� �����մϴ�.
	*/
	void* Commit				(int nLayer, stdEMString stdPlaneName, CEMPlane* pPlane);
	void* Commit				(int nLayer, int nID, stdEMString stdPlaneName,  CEMPlane* pPlane);

	/**
	@brief new�� ������ pWindow�� �߰��մϴ�
	[���ǻ���]
	�߰��� pWindow�� �̸��� �̹� �߰� �Ǿ��ִٸ� �߰��Ҽ� �����ϴ�. 
	�߰����� ���ϰ� �޸� ������ �ǹǷ� �����Ͻñ� �ٶ��ϴ�. 
	@param CEMWindow*
	@param enumUserInterfaceType (E_DYNAMIC : ������ / E_STATIC : ����)
	@param 
	@param 
	@param 
	@return void* �߰��� pWindow�� �����͸� �����Ѵ�. �߰� ���� ���޴ٸ� pWindow �� delete�� �� NULL�� �����մϴ�. ������
	*/
	void* Commit				(CEMWindow* pWindow, enumUserInterfaceType eType = E_DYNAMIC);

	/**
	@brief ���� ���̾� �ȿ����� �� plane����
	@param nLayer
	@param 
	@param 
	@param 
	@param 
	@return int(����) 
	*/
	int GetTotalPlanesInLayer	(int nLayer);	

	/**
	@brief ��緹�̾���� �� plane��
	@param 
	@param 
	@param 
	@param 
	@param 
	@return int(����) 
	*/
	int GetTotalPlanes();	

	/**
	@brief �߰��� ��� plane�� �޸����� �� �����մϴ�. Scene ��ȯ�� Destroy()�Լ��� ȣ�����ָ� 
		   ���� ������ �߰��� ��� Plane���� �� �����մϴ�. 
		   ���α׷��� ������ �ڵ����� ��� Plane���� �����˴ϴ�. 

	@param 
	@param 
	@param 
	@param 
	@param 
	@return ����
	*/
	void Destroy ();

	/**
	@brief �߰��� plane���� �����Ͽ� �ٷ� ���� �մϴ�.
	@param ������ plane�� �ּ�
	@return ����
	*/
	void DeletePlane(CEMPlane* pPlane);

	/**
	@brief �߰��� animation���� �����Ͽ� �ٷ� ���� �մϴ�.
	@param ������ animation�� �ּ� 
	@return ����
	*/
	void DeleteAnimation(CEMAnimation* pAnimation);

	/**
	@brief �߰��� number���� �����Ͽ� �ٷ� ���� �մϴ�.
	@param ������ number�� �ּ� 
	@return ����.
	*/
	//void DeleteNumber(CEMNumber* pNumber);

	/**
	@brief Plane��Ͻ� ����� �̸����� �߰���plane�� �����͸� ���ɴϴ�.
	@param 
	@param 
	@param 
	@param 
	@param 
	@return CEMPlane* 
	*/
	CEMPlane* Find		(stdEMString stdPlaneName);
	CEMPlane* Find		(int nID, stdEMString stdPlaneName);


	/**
	@brief ���� �̸��� �˾ƿɴϴ�.
	@param 
	@param 
	@param 
	@param 
	@param 
	@return stdEMString �̸�
	*/
	stdEMString GetSceneName()	{return m_sSceneName;}
	void SetSceneName(stdEMString SceneName)		{m_sSceneName = SceneName;}

	/**
	@brief IsDestroy()�ؼ�true�� �Ѿ�³���� �����մϴ�.( �ѹ� �����ְ� �������� ��鶧�����̷��� �������� );
	@param 
	@param 
	@param 
	@param 
	@param 
	@return stdEMString �̸�
	*/
	void DestroyObjectCheck();

	virtual void Enter		(CSceneWork*);				//!< ����(�ε�)
	virtual void Update		(CSceneWork*, float dt);		//!< ������Ʈ
	virtual void Render		(CSceneWork*);					//!< ����
	virtual void Exit		(CSceneWork*);				//!< Ż��(����)

// 	virtual void BeginContact(b2Contact* contact) = 0			//!< �浹�Ǹ� ȣ��ȴ�
// 	virtual void EndContact(b2Contact* contact) = 0			//!< �浹�ǰ� ������ ȣ��ȴ�
// 	virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);			//!< ����������� �߻�������
// 	virtual void PostSolve(const b2Contact* contact, const b2ContactImpulse* impulse)	//!< ����������� ��������

	virtual void MouseDownEvent (stMouseInfo stPos, enumMouseButton eButton) = 0;
	virtual void MouseUpEvent (stMouseInfo stPos, enumMouseButton eButton) = 0;
	virtual void MouseMoveEvent (stMouseInfo stPos) = 0;
	virtual HRESULT WindowMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) = 0;
	
	/**
	@brief Box2D World������ ���
	@return b2Body*
	*/
	b2World* GetWorldPt()	{ return CEMPhysicRoot::m_world; }

	/**
	@brief Box2D�� �����մϴ�.
	@param stGravityVec : �߷���ġ ����
	@return ����/����
	*/
	bool StartPhysic(stEMVec2 stGravityVec);
	


	Settings* GetSetInfo()					{ return &m_PhysicSetting; }
	void SetSettingInfo(Settings stSet)		{ m_PhysicSetting = stSet; }
	 
private:
	bool OverlapChk(CEMPlane* pPlane, stdEMString stdPlaneName);
	bool OverlapChk(CEMPlane* pPlane, stdEMString stdPlaneName, int nID);

public:
	CEMWindow* GetCurrentUI(){ return m_pCurrentUI;	}		//!< ������
	CEMWindow* GetOverlapUI(){ return m_pOverlapUI;	}		//!< ������
	CEMWindow* GetUI(const char* cpWindowName);				//!< ������ ��Ʈ���� ������ ����
	
	void GetOverlapWindow(stMouseInfo& info);				//!< ������
	void ChangeFocus(stMouseInfo& info, enumMouseButton e);	//!< ������ ��Ŀ�� ü����.
	void SendMouseMove(stMouseInfo& info);
};