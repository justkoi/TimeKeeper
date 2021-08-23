#pragma once

#include "EMString.h"

class CEMPlane;
class CRootScene;

typedef enum emirrortype
{
	E_RIGHT_MIRROR,				//!< 오른쪽 보기
	E_UP_LEFT_MIRROR,			//!< 왼쪽 바라보고 있으면서 위쪽
	E_UP_RIGHT_MIRROR,			//!< 오른쪽 바라보고 있으면서 위
	E_LEFT_MIRROR				//!< 왼쪽 보기
}eMirrorType;

typedef std::vector<CEMPlane*>	stdPlaneList;
typedef std::set<CEMPlane*>	stdPlaneSet;

/**
	@file    : EMPlane.h
	@author  : wo
	@version : 1.0f
	@brief   : 2D 바운딩 박스 구조체
 */
struct stEMBoundingBox
{
/*
 (-+) LT ---------- RT(++)
	    |	  	   |
	    |		   |
 (--) LB ---------- RB(+-)
*/
	stEMVec3 stLT;					//!< 왼쪽 위
	stEMVec3 stLB;					//!< 왼쪽 아래
	stEMVec3 stRT;					//!< 오른쪽 위
	stEMVec3 stRB;					//!< 오른쪽 아래

	float fRadius;					//!< 반지름
	stEMVec3 stCenterPosVec3;		//!< 구 및 box의 중심 offset위치가 적용되어진 최종 출력위치

	bool operator==(const stEMBoundingBox &stBBox) const;
};

/**
	@file    : EMPlane.h
	@author  : wo
	@version : 1.0f
	@brief   : 면충돌 관련
 */
class CEMCollisionPlane
{
public:
	stEMVec3	m_VN;		//!< Vertex Normal
	float		m_fD;		//!< Distance (거리)

	CEMCollisionPlane(const stEMVec3& stVev3,float fDistance)
	{
		m_VN = stVev3;
		m_fD = fDistance;
	}

	~CEMCollisionPlane(){}


public:
	/**
	@brief 평면과 직석Ray의 교차점 구하는 함수

	@param stStartVec : Ray시작점
	@param stEndVec : Ray끝점
	@param stIntersectionVec : 교차점
	@param 
	@param 
	@return true/false   충돌 비충돌
	*/
	bool GetIntersectionVec(const stEMVec3& stStartVec, const stEMVec3& stEndVec,  stEMVec3* stIntersectionVec);	//SP(시점),EP(종점) 으로 이루어진 직선과 평면의 통과 지점을 pRET로 되돌립니다.
};


typedef enum e_planestate
{
	E_NO_PHYSIC				= 0,	//!< 물리 없어요
	E_DYNAMIC_BOX,
	E_DYNAMIC_CICLE,
	E_DYNAMIC_POLYGON,
	E_KINEMATIC_BOX,
	E_KINEMATIC_CICLE,
	E_KINEMATIC_POLYGON,
	E_STATIC_BOX,
	E_STATIC_CICLE,
	E_STATIC_POLYGON
}E_PLANESTATE;


/**
	@file    : EMPlane.h
	@author  : wo
	@version : 1.0f
	@brief   : plane의 상태 정보 저장 구조체입니다

			   |--------------------|----------------------------------------------------|------------------------------------------------|
			   |		bool		|					  enum 							 |					enum						  |	
			   |--------------------|----------------------------------------------------|------------------------------------------------|
			   |	   물리유무		|				    물리종류						 	 |		  		  물리 모양 				  		  |
			   |--------|-----------|-------|---------|---------------|---------|--------|--------|---------|-------|-------------|-------|
			   |    0   |	  1		|		|	0	  |		1	      |		2	|        |	      | 	0	| 	1	| 	  3       |	  4	  |	
			   |--------|-----------|-------|---------|---------------|---------|--------|--------|---------|-------|-------------|-------|
			   | 물리 X	|  물리 0	|       | static  |    kinematic  |	dynamic |        |	      |  cicle 	| edge  |	polygon	  |	chain |
			   |--------|-----------|-------|---------|---------------|---------|--------|--------|---------|-------|-------------|-------|
 */
struct stEMPlaneState
{
	bool m_bPhysic;						//!< 물리 유무

	b2BodyType		m_bPhysicType;		//!< 물리 종류
	b2Shape::Type	m_bPhysicShape;		//!< 물리 모양

	stEMPlaneState()
	{
		Reset();
	}

	~stEMPlaneState()
	{
	}

	void Reset()
	{
		m_bPhysic = false;

		m_bPhysicType = b2_dynamicBody;					//!< dynamic
		m_bPhysicShape = b2Shape::Type::e_polygon;		//!< 모양
	}
};

typedef struct RGB24Pixel
{
	unsigned char nRed;
	unsigned char nGreen;
	unsigned char nBlue;
} RGB24Pixel;


#define D_POLYGONS		30
/**
	화면에 출력되어진 Plane입니다
	Plane에 object클래스를 연결시키고 
	텍스쳐를 연결시켜서 화면에 출력되게 되는 것입니다.
*/
class CEMPlane : public CEMObject
{
protected:
	stEMPlaneState	m_stPlaneState;			//!< 정보 저장 변수(물리 붙었는지 기타 등등의 정보)
	stdEMString		m_sFilePath;			//!< SetTexture시 파일의 경로를 저장
	stdEMString		m_sFileName;			//!< SetTexture시 파일의 경로에서 이름만 축출
	stdEMString		m_sName;				//!< Commint시 두번째 인자에 들어가는 문자(아이디)
	int				m_nID;					//!< 아이디
	
	CEMColor		m_Color;				//!< 색상
	
	stEMVec2		m_stSize;				//!< 사이즈 관련 변수	
	stEMVec3		m_stPosVec3;			//!< 이놈을 주로 사용합니다. 3d vertex

// 	RGB24Pixel*	m_pucUserTexture;			//!< 실시간 텍스쳐 사용할때 쓰세염
// 	int				m_nW;
// 	int				m_nH;
// 	GLuint			m_nTexthihi;

// 		0, 1 -------------- 1,1 (RU)
// 			|			  |            
// 			|			  |    
// 			|			  |
// 			|			  |
// 	(LL)0,0	 -------------- 1,0
	stEMVec2		m_stUVRU;				//!< uv관련
	stEMVec2		m_stUVLL;				//!< uv관련

	stEMVec2		m_stLocalVec2;			//!< Plane의 로컬 중심값 이동하기 위한 변수
	stEMOffset		m_stOffset;				//!< plane의 offset값을 조절합니다
	stEMBoundingBox	m_stBBox;				//!< BoundingBox

	bool			m_bBoundBoxCalcFlag;	//!< BoundingBox 실시간 계산 유무 기본값 false입니다( true면 실시간 계산하기 false면 안하기)
	bool			m_bOrtho2D;				//!< true면 직교 투영하기 false면 원근 투영하기
	bool			m_bBlend;				//!< blend할것인지 안할것인지를 선택 함
	bool			m_bFrstumCulling;		//!< 프러스텀 컬링 할건지 말건지를 결정하는 함수 true면 컬링 검사 하고요 false면 안하고요 기본 true, textplane은 자동 false입니다
	bool			m_bBackCulling;			//!< 뒷부분 출력 유무 기본은 true로 되어있습니다 뒷면이 안보입니다

	float			m_fXRot;				//!< x축 회전
	float			m_fYRot;				//!< y축 회전
	float			m_fZRot;				//!< z축회전
	
	GLuint			m_nTextureID;			//!< 사용할 텍스쳐 ID
	int				m_nImageWidthHalf;		//!< width/2
	int				m_nImageHeightHalf;		//!< Height/2

	int				m_nImageWidth;			//!< width 원본 사이즈
	int				m_nImageHeigh;			//!< Height 원본 사이즈

	eMirrorType		m_eMirrorType;			//!< 반전관련
	int				m_nType;				//!< 이 타일의 속성을 의미합니다.(걷기 타일이냐, 점프 타일이냐 등등)

	
public:
	b2Body*			m_pBody;				//!< 물리 바디
	b2Fixture*		m_pFixture;				//!< 물리 Fixture
	bool			m_bPhysicConnectFlag;	//!< 물리 연결 유무
	b2Vec2*			m_stPolygonVertex;		//!< 다각형 으로 만들때 사용
	b2Vec2			m_stPolygonLocalVec;	//!< 다각형 으로 만들때 사용
	
public:
	/*
		(-+) LT  ----------  RT (++)
				|	  	   |
				|		   |
		(--) LB  ----------  RB (+-)
	*/
	float			m_fLTLBSize;			//!< LTLB
	float			m_fRTRBSize;			//!< RTRB
	float			m_fLTRTSize;			//!< LTRT
	float			m_fLBRBSize;			//!< LBRB

	float			m_fBSphereRadius;		//!< 바운딩 구 반지름
	
	stEMVec2		m_stBBoxOffset;			//!< BoundingBox Offset
	stEMVec2		m_stBBoxSphereOffset;	//!< BoudnignBox Sphere Offset

public:
	CEMPlane();
	CEMPlane(stEMVec2 stPos, stEMVec2 stSize, float fRot);
	CEMPlane(stEMVec2 stPos, float fWidth, float fHeight, float fRot);

	virtual ~CEMPlane()
	{
		//물리 만들어졌을때 바디 제거염
		if(GetConnectPhysicState())
		{
			m_pBody->GetWorld()->DestroyBody(m_pBody);
		}


	};

public:
	/**
	@brief m_stPlaneState정보를 설정합니다^^
	@return 없음
	*/
	void SetPlaneState(stEMPlaneState stState);

	/**
	@brief CEMPlane의 설정 정보 얻어오는 함수 입니다. (물리 유무/ 물리종류/물리모양등)
	@return E_PLANESTATE(현재 설정 되어진 정보리턴)
	*/
	E_PLANESTATE GetPlaneState();


	/**
	@brief 현재 등록되어진 텍스처의 파일 경로를 알아내는 함수입니다. ( 파일 이름까지 포함)
	@return 파일 경로
	*/
	stdEMString GetFilePath() { return m_sFilePath;}

	/**
	@brief 현재 등록되어진 텍스처의 파일 이름을 알아내는 함수입니다.
	@return 파일 이름
	*/
	stdEMString GetFileName() { return m_sFileName;}	

	/**
	@brief 등록할 오브젝트의 이름을 저장합니다.
	@param sName : 등록할 오브젝트 이름
	@return 없음
	*/
	void SetName(stdEMString sName) { m_sName = sName; }
	stdEMString GetName()			{return m_sName;}

	/**
	@brief Commit할때 추가되는 아이디값 설정함수입니다. (엔진내부에서 사용)

	@param int nID : 아디이값
	@return 없음
	*/
	void SetID(int nID)			{m_nID = nID;}
	int GetID()					{return m_nID;}

	virtual void PolygonVertexRelease();

	/**
	@brief 색 지정
	@param fR 
	@param fG
	@param fB
	@param fA 알파 기본값 1.0f
	@return 없음
	*/
	virtual void SetColor(float fR, float fG, float fB, float fA=1.0f);
	virtual void SetColor(CEMColor color);
	virtual CEMColor GetColor()	{return m_Color;}

	/**
	@brief 사이즈 설정 함수 
	@param fX
	@param fY
	@return 없음
	*/
	virtual void SetSize(float fX, float fY=-1.0f);
	virtual void SetSize(stEMVec2 stSize);
	virtual stEMVec2 GetSize()	{return m_stSize;}

	/**
	@brief 위치값 세팅 오브젝트 이동시 이함수를 호출하면안되고 아래에 있는 MoveX, MoveY, MoveZ 함수를 호출하셔야합니다.
	@param fX
	@param fY
	@param fZ
	@return 없음
	*/
	virtual void SetPos(float fX, float fY, float fZ);
	virtual void SetPos(float fX, float fY);
	virtual void SetPos(stEMVec2 vec2);	
	virtual void SetPos(stEMVec3 vec3);

	virtual stEMVec2 GetPosVec2()		{stEMVec2 ntemp;  ntemp.m_fX = m_stPosVec3.m_fX, ntemp.m_fY = m_stPosVec3.m_fY; return ntemp;}
	virtual stEMVec3 GetPosVec3()		{return m_stPosVec3;}

	/**
	@brief uv 왼쪽 위 설정
	@param stUv : 위치 
	@return 없음
	*/
	virtual void SetUV(stEMVec2 stLowLeft, stEMVec2 stUpRight);
	virtual void GetUV(stEMVec2& stLowLeft, stEMVec2& stUpRight);

	/**
	@brief 화면에 출력되는 Plane들의 로컬좌표를 변경할 수 있도록 합니다.
	@param stPt : 로컬좌표 
	@return 없음
	*/
	virtual void SetLocalVec(stEMVec2 stPt)			{ m_stLocalVec2 = stPt; }
	virtual void SetLocalVec(float fX, float fy)	{ m_stLocalVec2.m_fX = fX; m_stLocalVec2.m_fY = fy; }
	virtual stEMVec2 GetLocalVec()					{ return m_stLocalVec2; }

	/**
	@brief plane의 출력위치를 변경 할 수 있습니다.
	@param stOffset : 이동값
	@return 없음
	*/
	virtual void SetOffset(stEMOffset stOffset);//		{ m_stOffset = stOffset; }
	virtual void SetOffset(float fX, float fY);	//	{ m_stOffset.m_fX; m_stOffset.m_fY; }
	virtual stEMOffset GetOffset()					{ return m_stOffset; }

	/**
	@brief 충돌영역 지정 함수 입니다.
		   Update()에서 실시간으로 호출해줍니다.
	@param stLT : 왼쪽 위
	@param stLB : 왼쪽 아래
	@param stRT : 오른쪽 위
	@param stRB : 오른쪽 아래
	@return 없음
	*/	
	virtual void SetBoundingBox(stEMVec3 stLT, stEMVec3 stLB, stEMVec3 stRT, stEMVec3 stRB);
	virtual void SetBoundingBox();

	/**
	@brief 바운딩 박스 정보를 얻어옵니다.
		   물리가 없으면 Plane의 위치 까지 계산되어져서 리턴되고
		   물리가 있으면 물리에서 위치까지 계산해주므로 그냥 리턴된다.
	@return stBoundingBox
	*/
	virtual stEMBoundingBox GetBoundingBox();

	/**
	@brief 바운딩 박스 계산할것인지 안할것인지를 검사!
	@return 없음
	*/
	virtual void SetBoundingBoxCalc(bool bFlag)		{m_bBoundBoxCalcFlag = bFlag;}
	virtual bool GetBoundingBoxCalc()				{ return m_bBoundBoxCalcFlag; }

	/**
	@brief 직교투영 해야할때는 직교 투영으로 처리한다. 
		   직교투영시에는 자동으로 SetFrustumCulling(false) 합니다
		   화면벗어나는 Plane은 사용자가 직접 제어해야합니다

	@param bFlag : true면 직교투영으로 false면 원근투영으로 출력
	@return 없음
	*/
	virtual void SetOrtho2D(bool bFlag);
	virtual bool GetOrtho2D()	{ return m_bOrtho2D;}

	/**
	@brief 블랜딩 키고, 끄고
	@param bBlend
	@return 없음
	*/
	virtual void SetBlend(bool bBlend)	{ m_bBlend = bBlend; }
	virtual bool GetBlend()	{ return m_bBlend; }

	/**
	@brief 프러스텀 컬링 On/OFF
	@param bFlag : true/false
	@return 없음
	*/
	virtual void SetFrustumCulling(bool bFlag)	{ m_bFrstumCulling = bFlag; }
	virtual bool GetFrustumCulling()			{return m_bFrstumCulling;}

	/** 
	@brief 뒷면 출력유무 y축 회전시 뒷면이 안보일때 이놈을 false로 해줍니다. 
	@param bool bFlag : true면 뒷면 안보이고 false면 뒷면 보인다.
	@return 성공 유무
	*/
	virtual void SetBackFaceCulling(bool bFlag)		{m_bBackCulling = bFlag;}
	virtual bool GetBackFaceCulling()				{return m_bBackCulling;}

	/**
	@brief x,y,z 회전값 세팅  
		   [주의] 물리는 z축 회전만 있어요^^ 명심하삼
	@param fRot : (Degree)도로 입력하시면 됩니다
	@return 없음
	*/
	virtual void SetXRot(float fRot);
	virtual void SetYRot(float fRot);
	virtual void SetZRot(float fRot);
	virtual float GetXRot()	{return m_fXRot;}		
	virtual float GetYRot()	{return m_fYRot;}
	virtual float GetZRot()	{return m_fZRot;}
	
	/**
	@brief 텍스쳐 넓이 높이 설정
	@param nWidth : 넓이
	@return 없음
	*/
	virtual void SetTextureWidthSize(int nWidth)			{ m_nImageWidth = nWidth;}
	virtual void SetTexTureHeightSize(int nHeight)			{ m_nImageHeigh = nHeight;}
	virtual void SetTextureWidthHalfSize(int nWidth)		{ m_nImageWidthHalf = nWidth;}
	virtual void SetTexTureHeightHalfSize(int nHeight)		{ m_nImageHeightHalf = nHeight;}
	virtual int GetTextureWidthSize()						{return m_nImageWidth;}
	virtual int GetTexTureHeightSize()						{return m_nImageHeigh;}
	virtual int GetTextureWidthHalfSize()					{return m_nImageWidthHalf;}
	virtual int GetTexTureHeightHalfSize()					{return m_nImageHeightHalf;}

	/**
	@brief plane 좌<--->우   상--->하 반전 설정
	@param eType : E_RIGHT_MIRROR,	E_UP_LEFT_MIRROR,	E_UP_RIGHT_MIRROR,	E_LEFT_MIRROR
	@return 없음
	*/	
	virtual void SetMirrorType(eMirrorType eType)			{ m_eMirrorType = eType;}
	eMirrorType GetMirrorType()		{ return m_eMirrorType; }

	/** 
	@brief plane의 종류 설정(ex) 타일1, 타일2 ^^
	@param nType : 타입 번호
	@return 없음
	*/
	virtual void SetType(int nType)	{m_nType = nType;}
	virtual int GetType()			{return m_nType;}

	/**
	@brief Body를 전달해 줌
	@return b2Body*
	 */
	virtual b2Body*	GetBody(void);

	/**
	@brief Fixture를 얻어온다.
	@return b2Fixture*
	 */
	virtual b2Fixture*	GetFixture();



		/**
	@brief 바운딩 박스 왼쪽/오른쪽/위/아래 사이즈 조절
	       fVal값이 -면 왼쪽으로 더 늘어나고
		   fVal값이 +면 오른쪽으로 줄어든다.
		
		(-+) LT  ---------- RT (++)
				|	  	   |
				|		   |
		(--) LB  ---------- RB (+-)
		
	@param float : 값 조절
	@return 없음
	*/
	virtual void SetLeftSizeOfBBox(float fVal);
	virtual void SetRightSizeOfBBox(float fVal);
	virtual void SetUpSizeOfBBox(float fVal);
	virtual void SetDownSizeOfBBox(float fVal);

		/**
	@brief 바운딩 박스 중앙위치 설정

	@param float : fX
	@param float : fY
	@param 
	@return 없음
	*/
	virtual void SetBoundingBoxCenterPos(float fX, float fY);
	virtual void SetBoundingBoxCenterPos(stEMVec2 stVec2);

		/**
	@brief 바운딩 구 반지름 조절

	@param float : 반지름
	@param 
	@param 
	@return 없음
	*/
	virtual void SetBoundingSphereRadius(float fRadius);

	/**
	@brief 구 중앙 위치 설정

	@param float : fX
	@param float : fY
	@param 
	@return 없음
	*/
	virtual void SetBoundingSphereCenterPos(float fX, float fY);
	virtual void SetBoundingSphereCenterPos(stEMVec2 stVec2);

	//====================================================================================
	public:
	/**
	@brief Body를 연결해 줍니다
	@param boBody* body : 사이즈와 회전값등을 알아냄
	@return 없음
	 */
	virtual void ConnectBody(b2Body* pBody);

	/**
	@brief 물리 연결 상태 설정
	@param state : 상태 (true/false
	@return 없음
	*/
	virtual void SetConnectPhysicState(bool state)	{ m_bPhysicConnectFlag = state;}
	virtual bool GetConnectPhysicState();

	/**
	@brief 새로운 알파 지정합니다.
	@param fA 
	@param 
	@param 
	@param 
	@param 
	@return 없음
	*/
	virtual void SetAlpha(float fA);
	virtual float GetAlpha()	{return m_Color.m_fA;}

	/**
	@brief 반지름을 설정하거나 알아오는 함수입니다 b2CircleShape로 만들었을때 사용
	@param 
	@param 
	@return 없음
	*/
	virtual void SetRadius(float fRadius);
	virtual float GetRadius()	{return m_stBBox.fRadius;}
	
	/**
	@brief Plane 이동시 호출해주는 함수 입니다. 
	@param fMove : 이동한 거리
	@return 없음
	*/
	virtual void MoveX(float fMove);
	virtual void MoveY(float fMove);
	virtual void MoveZ(float fMove);
	
	virtual void UpdatePhysic();
	virtual void Update(float dt);
	virtual void Render();

	//virtual bool SetTexutre( RGB24Pixel* pImageData=NULL, int nWidth=0, int nHeight=0){return true;}

	/**
	@brief 설정되어져있는 텍스쳐 관련 정보를 초기화합니다
	@return 없음
	*/
	void ResetTextureInfo();

	/**
	@brief 원그려주는 함수입니다.

	@param fR : 반지름값
	@return 없음
	*/
	void RenderCircle(const float fR, stEMVec3 stVec3, CEMColor color);

	

		/**
	@brief PLANE에 Texture연결하는 함수입니다. (월드에서 관리하는 텍스쳐입니다) 이함수는 전역으로 사용할시에^^ 씬에서는 가급적
	       이 함수를 사용하지 말고 아래 있는 함수를 사용하시기 바랍니다.

	@param stdEMString strFileName	: 파일 이름
	@param GLint nClampMode = GL_CLAMP : clamp
	@param GLint nFilter = GL_LINEAR : filter
	@param  bool bOption = FALSE : bOption
	@param 
	@return 성공유무
	*/
	bool SetTexture(stdEMString strFileName, GLint nClampMode = GL_CLAMP, GLint nFilter = GL_LINEAR, bool bOption = FALSE);
	
	/**
	@brief 씬에 텍스쳐를 추가할때에는 이함수를 사용합니다.(각씬에서의 텍스쳐추가는 이걸로 해줍니다)

	@param pScene : 텍스쳐를 추가할 씬 포인터
	@param stdEMString strFileName	: 파일 이름
	@param GLint nClampMode = GL_CLAMP : clamp
	@param GLint nFilter = GL_LINEAR : filter
	@param bool bOption = FALSE : bOption
	@param 
	@return 성공유무
	*/
	bool SetTexture(CRootScene* pScene, stdEMString strFileName, GLint nClampMode = GL_CLAMP, GLint nFilter = GL_LINEAR, bool bOption = FALSE);

	// 사용하지 마세요^ 임시입니다Kinect에서 사용되어질
	//bool UpdateTexture(RGB24Pixel* pData, int nWidth, int nHeight, GLuint nID);
	/**
	@brief 현재 클래스 이름 얻어오기
	@return stdEMString
	*/
	virtual const stdEMString GetClassName() { return "CEMPlane"; }

	private:


	/**
	@brief plane에 연결할 텍스쳐 id값을 설정합니다. 
		  -1로 설정하면 텍스쳐가 출력되지 않아요 기본값은 -1입니다.  혹시 텍스쳐를 제거 하시려면 -1을 넣어줘야합니다.

	@param int nID : 아이디값 설정
	@return 없음
	*/
	void SetTextureID(int nID)		{ m_nTextureID = nID;}
	int GetTextureID()				{ return m_nTextureID;  }

	/**
	@brief 물리설정을 staitc-->에서 dynamic으로 변경할경우가 있으므로 이런 상태를 계속 upate()에서 체크해줘야합니다.
		   그런일을 하는 함수 입니다. 
	@param 
	@return 없음
	 */
	void UpdateBodyType();


	/**
	@brief 최고점과 최고점을 계산 하여주는 함수 입니다(엔진 내부에서 사용)
	@param pShape : 
	@param stMin : 최소점 저장
	@param stMax : 최고점 저장
	@return 
	 */
	void CalcMinMax(b2PolygonShape* pShape, b2Vec2* stMin, b2Vec2* stMax);
};



