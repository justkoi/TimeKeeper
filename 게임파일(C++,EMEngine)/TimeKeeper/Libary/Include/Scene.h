#pragma once

#include "EMString.h"
#include "EMASE.h"

typedef enum e_collision_type
{
	E_SPHERE_VS_SPHERE,		//!< 구대구 충돌
	E_BOX_VS_BOX,			//!< 박스대 박스 충돌
	E_SPHERE_VS_BOX			//!< 구대 박스 충돌
}E_COLLISION_TYPE;

typedef enum e_collision_face
{
	E_COLL_LEFT_FACE,		//!< 왼쪽 면
	E_COLL_RIGHT_FACE,		//!< 오른쪽 면
	E_COLL_UP_FACE,			//!< 2010년 7월 진여준을 위해 추가 고마워 하려나~~ 휙(나의 일을 뒤로한 어느날...)
	E_COLL_DOWN_FACE,		//!< 2010년 7월 진여준을 위해 추가
	E_COLL_ALL_FACE			//!< 모든면 
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
class CEMWindow;			// 윤영재
class CEMAseImport;

typedef std::map<stdEMString, CEMPlane*> stdPlane;
typedef pair<stdEMString, CEMPlane*> stdPlanePair;
typedef pair<stdEMString, CEMWindow*> stdUserInterfacePair;		//!< 윤영재

class CRootScene : public CEMPhysicRoot
{
private:
	stdEMString			m_sSceneName;
	E_CURSCENE_STATE	m_eCruScene;

protected:
	//! 화면에 출력할 plane들을 모두 이곳에 add하면 됩니다ㅣ. 
	std::map<int, stdPlane> m_stdPlaneList;								//!< 현재 씬 화면에 출력 되어질 오브젝트들
	std::map<stdEMString, stTextureCacheEntry> m_stdTextureList;		//!< 현재 씬 화면에서 사용되어질 텍스쳐들
	
	std::map<stdEMString, CEMWindow*> m_stdUserInterfacelist;			//!< 등록시킨 모든 UI집합체 윤영재
	std::list<CEMWindow*> m_stdDynamicList;								//!< dynamic 윈도우만 관리하는 list 윤영재
	std::list<CEMWindow*> m_stdStaticList;								//!< static 윈도우만 관리하는 list 윤영재
	CEMWindow* m_pCurrentUI;											//!< 현재 선택된 ui 윤영재
	CEMWindow* m_pOverlapUI;											//!< 현재 마우스가 올라온 ui 윤영재

	Settings m_PhysicSetting;

public:
	std::map<stdEMString, CEMAseImport*> m_stdASEList;					//!< 현재 씬 화면에서 사용되어질 ASE파일 데이타 입니다 (한곳에서 관리) 중복로딩때문에^^
	
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
	@brief BoundingBox 출력해줍니다(엔진에서 사용)
	@return 없음
	*/
	void RenderBBox(CEMAnimation* pAni);

	/**
	@brief 프러스텀 컬링 계산
		   내부에서 계산하여 Show(true) Show(false) 결정
	@return 없음
	*/
	void FrustumCullingCalc(CEMPlane* pPlane);

		/**
	@brief 프러스텀 컬링 계산
		   내부에서 계산하여 Show(true) Show(false) 결정
	@return 없음
	*/
	void FrustumCullingCalc(CEMAse* pAse);

/**
	@brief 바운딩 박스 계산
	@param CEMPlane* pPlane : 계산할 plane
	@return 없음
	*/
	void BoundingBoxCalc(CEMPlane* pPlane);			
	
	/**
	@brief 
	@param GLint ClampMode : 
	@param GLint FilterMode : 
	@return GLUint 아이디
	*/
	GLuint BindTexImageWithClampAndFilter(GLint ClampMode, GLint FilterMode);
	
	/**
	@brief OGL에 연결되어진 텍스쳐를 다 지워줍니다.
	@return 없음
	*/	
	void TextureRelease();

	/**
	@brief 읽어들인 모든 ASE파일은 삭제합니다.
	@return 없음
	*/	
	void ASERelease();

	/**
	@brief 구대구 충돌 : 
		   박스대 박스 : fA와 fB의 m_fZ값이 같아야 비교 대상이 됩니다.(주의)
		   구대 박스 : 
	@return 없음
	*/	
	bool SpherevsSphere(stEMBoundingBox fA, stEMBoundingBox fB);

	/**
	@brief 박스대 박스 충돌
		   박스대 박스 : fA와 fB의 m_fZ값이 같아야 비교 대상이 됩니다.(주의)
	@param E_COLLISION_FACE eFace : 왼쪽 면 or 오른쪽 면
	@param float fScope : 범위(오른족 검사 범위 Or 왼쪽 검사 범위)
	@param fA : 주인공
	@param fB : 오브젝트
	@return 없음
	*/	
	bool AABBvsAABB(E_COLLISION_FACE eFace, float fScope, stEMBoundingBox fA, stEMBoundingBox fB);
	bool SpherevsAABB(E_COLLISION_FACE eFace, float fScope,stEMBoundingBox fA, stEMBoundingBox fB);


public:

	/**
	@brief aabb와 ray의 충돌감사입니다

	@param nX : 마우스 x좌표
	@param nY : 마우스 y좌표
	@param nLayerScope : -1이면 모든 레이어 검사 0이면 0번레이어만 검사 1이면 1번레이어만검사 ^^
	@param 
	@return 충돌했다면 CEMPlane*리턴
	*/	
	CEMPlane* AABBvsRay(int nX, int nY, int nLayerScope = -1);
	CEMPlane* AABBvsRay(stEMVec3 stPos, int nLayerScope = -1);

	/**
	@brief 충돌유무 판정
		   : nScope가 -1이면 전체레이어와 충돌 처리를 한다. 
		     (단) pPlane가 만약 1번레이어라면 1번레이어에있는 Plane들은 충돌 처리 하지 않는다. 

			 CHero생성시 -1레이어에다가 만들고 충돌할 맵들은 0번레이어에 만들어야한다. 같은 0번레이어에 만들면 충돌 되지 않는다. -1했을경우

    @param E_COLLISION_FACE eFace : E_COLL_LEFT_FACE(왼쪽 면 검사),E_COLL_RIGHT_FACE(오른쪽 면 검사)
	@param float fScope : 검사 범위
	@param E_COLLISION_TYPE eType : E_SPHERE_VS_SPHERE, E_BOX_VS_BOX, E_SPHERE_VS_BOX
	@param CEMPlane* pPlane : 충돌처리할놈
	@param int nLayerScope = 0	0이면 0번레이어만 충돌처리 판정 한다는 의미입죠  -1이면 모든 오브젝트 충돌 처리합니다(화면에 보이는 놈들만)
	@return 충돌되어진 포인터가 넘어온다.
	*/
	CEMPlane* IsCollision(E_COLLISION_FACE eFace, float fScope, E_COLLISION_TYPE eType, CEMPlane* pPlane, int nLayerScope = 0);

/**
	@brief 충돌유무 판정
		   : nScope가 -1이면 전체레이어와 충돌 처리를 한다. 
		     (단) pPlane가 만약 1번레이어라면 1번레이어에있는 Plane들은 충돌 처리 하지 않는다. 

			 CHero생성시 -1레이어에다가 만들고 충돌할 맵들은 0번레이어에 만들어야한다. 같은 0번레이어에 만들면 충돌 되지 않는다. -1했을경우

	@param E_COLLISION_TYPE eType : E_SPHERE_VS_SPHERE, E_BOX_VS_BOX, E_SPHERE_VS_BOX
	@param CEMPlane* pPlane : CEMPlane이 될수도 있고 CEMPlane이 인자값으로 넘어갈 수도 있다.
	@param int nLayerScope = 0	0이면 0번레이어만 충돌처리 판정 한다는 의미입죠  -1이면 모든 오브젝트 충돌 처리합니다(화면에 보이는 놈들만)
	@return 충돌되어진 포인터가 넘어온다.
	*/
	CEMPlane* IsCollision( E_COLLISION_TYPE eType, CEMPlane* pPlane, int nLayerScope = 0);


	/**
	@brief 충돌유무 판정
		   : nScope가 -1이면 전체레이어와 충돌 처리를 한다. 
		     (단) pPlane가 만약 1번레이어라면 1번레이어에있는 Plane들은 충돌 처리 하지 않는다. 

			 CHero생성시 -1레이어에다가 만들고 충돌할 맵들은 0번레이어에 만들어야한다. 같은 0번레이어에 만들면 충돌 되지 않는다. -1했을경우

	@param CEMPlane* pPlane : CEMPlane이 될수도 있고 CEMPlane이 인자값으로 넘어갈 수도 있다.
	@param int nLayerScope = 0	0이면 0번레이어만 충돌처리 판정 한다는 의미입죠  -1이면 모든 오브젝트 충돌 처리합니다(화면에 보이는 놈들만)
	@return 충돌되어진 포인터가 넘어온다.
	*/

	CEMPlane* IsCollision(CEMPlane* pPlane, int nLayerScope = 0);

	/**
	@brief 등록한 폰트의 위치값을 재조정 합니다(화면사이즈가 변경되었을시)(엔진에서 호출)
	@return 없음
	*/
	void CalcFontPos();

	/**
	@brief 
	@param stdEMString strFileName : 읽어들일 파일이름
	@param GLint nClampMode=GL_CLAMP : clamp
	@param GLint nFilterMode=GL_LINEAR :  FilterMode
	@param int* nWidth = NULL : 그림 넓이
	@param int* nHeight = NULL : 그림 높이 
	@param bool bOptional = FALSE : 옵션(미사용)
	@param
	@return 없음
	*/
	int  GetTextureReference(stdEMString strFileName, GLint nClampMode=GL_CLAMP, GLint nFilterMode=GL_LINEAR, int* nWidth = NULL, int* nHeight = NULL, bool bOptional = FALSE);
	
	/**
	@brief new로 생성된 Plane을 추가합니다
		   [주의사항]
				추가할 stdPlaneName의 이름이 이미 추가 되어있다면 추가할수 없습니다. 
				같은 이름이 존해아혀 추가하지 못한 Plane은 자동 메모리 해제 됩니다
				추가하지 못하고 메모리 해제가 되므로 주의하시기 바랍니다.


			[필독]
				nLayer의 값이 작으면 가까이 있는 Plane들을 넣어주고 값이 많으면
				멀리있는 값들을 넣어주세요

				0번레이어에 약 100개의 Plane들이 있다면, 출력우선순위는 
				아래의 stdPlaneName에 의해 결정된다. "0_plane" "1_plane"두개의 
				plane이 있다면 0_plane이 먼저 출력되고 그 후 에 1_plane이 출력된다. 

	@param nLayer
	@param stdPlaneName
	@param pPlane
	@param 
	@param 
	@return void* 추가한 plane의 포인터를 리턴한다. 추가 하지 못햇다면 pPlane 을 delete한 후 NULL을 리턴합니다.
	*/
	void* Commit				(int nLayer, stdEMString stdPlaneName, CEMPlane* pPlane);
	void* Commit				(int nLayer, int nID, stdEMString stdPlaneName,  CEMPlane* pPlane);

	/**
	@brief new로 생성된 pWindow을 추가합니다
	[주의사항]
	추가할 pWindow의 이름이 이미 추가 되어있다면 추가할수 없습니다. 
	추가하지 못하고 메모리 해제가 되므로 주의하시기 바랍니다. 
	@param CEMWindow*
	@param enumUserInterfaceType (E_DYNAMIC : 유동적 / E_STATIC : 고정)
	@param 
	@param 
	@param 
	@return void* 추가한 pWindow의 포인터를 리턴한다. 추가 하지 못햇다면 pWindow 을 delete한 후 NULL을 리턴합니다. 윤영재
	*/
	void* Commit				(CEMWindow* pWindow, enumUserInterfaceType eType = E_DYNAMIC);

	/**
	@brief 지정 레이어 안에서의 총 plane개수
	@param nLayer
	@param 
	@param 
	@param 
	@param 
	@return int(개수) 
	*/
	int GetTotalPlanesInLayer	(int nLayer);	

	/**
	@brief 모든레이어에서의 총 plane수
	@param 
	@param 
	@param 
	@param 
	@param 
	@return int(개수) 
	*/
	int GetTotalPlanes();	

	/**
	@brief 추가한 모든 plane을 메모리해제 후 제거합니다. Scene 전환시 Destroy()함수를 호출해주면 
		   현재 씬에서 추가한 모든 Plane들은 다 제거합니다. 
		   프로그램이 끝나면 자동으로 모든 Plane들은 삭제됩니다. 

	@param 
	@param 
	@param 
	@param 
	@param 
	@return 없음
	*/
	void Destroy ();

	/**
	@brief 추가한 plane에서 선택하여 바로 삭제 합니다.
	@param 삭제할 plane의 주소
	@return 없음
	*/
	void DeletePlane(CEMPlane* pPlane);

	/**
	@brief 추가한 animation에서 선택하여 바로 삭제 합니다.
	@param 삭제할 animation의 주소 
	@return 없음
	*/
	void DeleteAnimation(CEMAnimation* pAnimation);

	/**
	@brief 추가한 number에서 선택하여 바로 삭제 합니다.
	@param 삭제할 number의 주소 
	@return 없음.
	*/
	//void DeleteNumber(CEMNumber* pNumber);

	/**
	@brief Plane등록시 등록한 이름으로 추가한plane의 포인터를 얻어옵니다.
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
	@brief 씬의 이름을 알아옵니다.
	@param 
	@param 
	@param 
	@param 
	@param 
	@return stdEMString 이름
	*/
	stdEMString GetSceneName()	{return m_sSceneName;}
	void SetSceneName(stdEMString SceneName)		{m_sSceneName = SceneName;}

	/**
	@brief IsDestroy()해서true가 넘어온놈들을 삭제합니다.( 한번 보여주고 없어지는 놈들때문에이렇게 만들었어요 );
	@param 
	@param 
	@param 
	@param 
	@param 
	@return stdEMString 이름
	*/
	void DestroyObjectCheck();

	virtual void Enter		(CSceneWork*);				//!< 진입(로딩)
	virtual void Update		(CSceneWork*, float dt);		//!< 업데이트
	virtual void Render		(CSceneWork*);					//!< 실행
	virtual void Exit		(CSceneWork*);				//!< 탈출(해제)

// 	virtual void BeginContact(b2Contact* contact) = 0			//!< 충돌되면 호출된다
// 	virtual void EndContact(b2Contact* contact) = 0			//!< 충돌되고 끝날때 호출된다
// 	virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);			//!< 물리량계산이 발생했을때
// 	virtual void PostSolve(const b2Contact* contact, const b2ContactImpulse* impulse)	//!< 물리량계산이 끝났을때

	virtual void MouseDownEvent (stMouseInfo stPos, enumMouseButton eButton) = 0;
	virtual void MouseUpEvent (stMouseInfo stPos, enumMouseButton eButton) = 0;
	virtual void MouseMoveEvent (stMouseInfo stPos) = 0;
	virtual HRESULT WindowMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) = 0;
	
	/**
	@brief Box2D World포인터 얻기
	@return b2Body*
	*/
	b2World* GetWorldPt()	{ return CEMPhysicRoot::m_world; }

	/**
	@brief Box2D를 시작합니다.
	@param stGravityVec : 중력위치 설정
	@return 성공/실패
	*/
	bool StartPhysic(stEMVec2 stGravityVec);
	


	Settings* GetSetInfo()					{ return &m_PhysicSetting; }
	void SetSettingInfo(Settings stSet)		{ m_PhysicSetting = stSet; }
	 
private:
	bool OverlapChk(CEMPlane* pPlane, stdEMString stdPlaneName);
	bool OverlapChk(CEMPlane* pPlane, stdEMString stdPlaneName, int nID);

public:
	CEMWindow* GetCurrentUI(){ return m_pCurrentUI;	}		//!< 윤여재
	CEMWindow* GetOverlapUI(){ return m_pOverlapUI;	}		//!< 윤여재
	CEMWindow* GetUI(const char* cpWindowName);				//!< 윤영재 컨트롤할 윈도우 선택
	
	void GetOverlapWindow(stMouseInfo& info);				//!< 윤영재
	void ChangeFocus(stMouseInfo& info, enumMouseButton e);	//!< 윤영재 포커스 체인지.
	void SendMouseMove(stMouseInfo& info);
};