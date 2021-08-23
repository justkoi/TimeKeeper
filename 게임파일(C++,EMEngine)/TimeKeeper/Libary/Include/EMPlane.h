#pragma once

#include "EMString.h"

class CEMPlane;
class CRootScene;

typedef enum emirrortype
{
	E_RIGHT_MIRROR,				//!< ������ ����
	E_UP_LEFT_MIRROR,			//!< ���� �ٶ󺸰� �����鼭 ����
	E_UP_RIGHT_MIRROR,			//!< ������ �ٶ󺸰� �����鼭 ��
	E_LEFT_MIRROR				//!< ���� ����
}eMirrorType;

typedef std::vector<CEMPlane*>	stdPlaneList;
typedef std::set<CEMPlane*>	stdPlaneSet;

/**
	@file    : EMPlane.h
	@author  : wo
	@version : 1.0f
	@brief   : 2D �ٿ�� �ڽ� ����ü
 */
struct stEMBoundingBox
{
/*
 (-+) LT ---------- RT(++)
	    |	  	   |
	    |		   |
 (--) LB ---------- RB(+-)
*/
	stEMVec3 stLT;					//!< ���� ��
	stEMVec3 stLB;					//!< ���� �Ʒ�
	stEMVec3 stRT;					//!< ������ ��
	stEMVec3 stRB;					//!< ������ �Ʒ�

	float fRadius;					//!< ������
	stEMVec3 stCenterPosVec3;		//!< �� �� box�� �߽� offset��ġ�� ����Ǿ��� ���� �����ġ

	bool operator==(const stEMBoundingBox &stBBox) const;
};

/**
	@file    : EMPlane.h
	@author  : wo
	@version : 1.0f
	@brief   : ���浹 ����
 */
class CEMCollisionPlane
{
public:
	stEMVec3	m_VN;		//!< Vertex Normal
	float		m_fD;		//!< Distance (�Ÿ�)

	CEMCollisionPlane(const stEMVec3& stVev3,float fDistance)
	{
		m_VN = stVev3;
		m_fD = fDistance;
	}

	~CEMCollisionPlane(){}


public:
	/**
	@brief ���� ����Ray�� ������ ���ϴ� �Լ�

	@param stStartVec : Ray������
	@param stEndVec : Ray����
	@param stIntersectionVec : ������
	@param 
	@param 
	@return true/false   �浹 ���浹
	*/
	bool GetIntersectionVec(const stEMVec3& stStartVec, const stEMVec3& stEndVec,  stEMVec3* stIntersectionVec);	//SP(����),EP(����) ���� �̷���� ������ ����� ��� ������ pRET�� �ǵ����ϴ�.
};


typedef enum e_planestate
{
	E_NO_PHYSIC				= 0,	//!< ���� �����
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
	@brief   : plane�� ���� ���� ���� ����ü�Դϴ�

			   |--------------------|----------------------------------------------------|------------------------------------------------|
			   |		bool		|					  enum 							 |					enum						  |	
			   |--------------------|----------------------------------------------------|------------------------------------------------|
			   |	   ��������		|				    ��������						 	 |		  		  ���� ��� 				  		  |
			   |--------|-----------|-------|---------|---------------|---------|--------|--------|---------|-------|-------------|-------|
			   |    0   |	  1		|		|	0	  |		1	      |		2	|        |	      | 	0	| 	1	| 	  3       |	  4	  |	
			   |--------|-----------|-------|---------|---------------|---------|--------|--------|---------|-------|-------------|-------|
			   | ���� X	|  ���� 0	|       | static  |    kinematic  |	dynamic |        |	      |  cicle 	| edge  |	polygon	  |	chain |
			   |--------|-----------|-------|---------|---------------|---------|--------|--------|---------|-------|-------------|-------|
 */
struct stEMPlaneState
{
	bool m_bPhysic;						//!< ���� ����

	b2BodyType		m_bPhysicType;		//!< ���� ����
	b2Shape::Type	m_bPhysicShape;		//!< ���� ���

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
		m_bPhysicShape = b2Shape::Type::e_polygon;		//!< ���
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
	ȭ�鿡 ��µǾ��� Plane�Դϴ�
	Plane�� objectŬ������ �����Ű�� 
	�ؽ��ĸ� ������Ѽ� ȭ�鿡 ��µǰ� �Ǵ� ���Դϴ�.
*/
class CEMPlane : public CEMObject
{
protected:
	stEMPlaneState	m_stPlaneState;			//!< ���� ���� ����(���� �پ����� ��Ÿ ����� ����)
	stdEMString		m_sFilePath;			//!< SetTexture�� ������ ��θ� ����
	stdEMString		m_sFileName;			//!< SetTexture�� ������ ��ο��� �̸��� ����
	stdEMString		m_sName;				//!< Commint�� �ι�° ���ڿ� ���� ����(���̵�)
	int				m_nID;					//!< ���̵�
	
	CEMColor		m_Color;				//!< ����
	
	stEMVec2		m_stSize;				//!< ������ ���� ����	
	stEMVec3		m_stPosVec3;			//!< �̳��� �ַ� ����մϴ�. 3d vertex

// 	RGB24Pixel*	m_pucUserTexture;			//!< �ǽð� �ؽ��� ����Ҷ� ������
// 	int				m_nW;
// 	int				m_nH;
// 	GLuint			m_nTexthihi;

// 		0, 1 -------------- 1,1 (RU)
// 			|			  |            
// 			|			  |    
// 			|			  |
// 			|			  |
// 	(LL)0,0	 -------------- 1,0
	stEMVec2		m_stUVRU;				//!< uv����
	stEMVec2		m_stUVLL;				//!< uv����

	stEMVec2		m_stLocalVec2;			//!< Plane�� ���� �߽ɰ� �̵��ϱ� ���� ����
	stEMOffset		m_stOffset;				//!< plane�� offset���� �����մϴ�
	stEMBoundingBox	m_stBBox;				//!< BoundingBox

	bool			m_bBoundBoxCalcFlag;	//!< BoundingBox �ǽð� ��� ���� �⺻�� false�Դϴ�( true�� �ǽð� ����ϱ� false�� ���ϱ�)
	bool			m_bOrtho2D;				//!< true�� ���� �����ϱ� false�� ���� �����ϱ�
	bool			m_bBlend;				//!< blend�Ұ����� ���Ұ������� ���� ��
	bool			m_bFrstumCulling;		//!< �������� �ø� �Ұ��� �������� �����ϴ� �Լ� true�� �ø� �˻� �ϰ�� false�� ���ϰ�� �⺻ true, textplane�� �ڵ� false�Դϴ�
	bool			m_bBackCulling;			//!< �޺κ� ��� ���� �⺻�� true�� �Ǿ��ֽ��ϴ� �޸��� �Ⱥ��Դϴ�

	float			m_fXRot;				//!< x�� ȸ��
	float			m_fYRot;				//!< y�� ȸ��
	float			m_fZRot;				//!< z��ȸ��
	
	GLuint			m_nTextureID;			//!< ����� �ؽ��� ID
	int				m_nImageWidthHalf;		//!< width/2
	int				m_nImageHeightHalf;		//!< Height/2

	int				m_nImageWidth;			//!< width ���� ������
	int				m_nImageHeigh;			//!< Height ���� ������

	eMirrorType		m_eMirrorType;			//!< ��������
	int				m_nType;				//!< �� Ÿ���� �Ӽ��� �ǹ��մϴ�.(�ȱ� Ÿ���̳�, ���� Ÿ���̳� ���)

	
public:
	b2Body*			m_pBody;				//!< ���� �ٵ�
	b2Fixture*		m_pFixture;				//!< ���� Fixture
	bool			m_bPhysicConnectFlag;	//!< ���� ���� ����
	b2Vec2*			m_stPolygonVertex;		//!< �ٰ��� ���� ���鶧 ���
	b2Vec2			m_stPolygonLocalVec;	//!< �ٰ��� ���� ���鶧 ���
	
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

	float			m_fBSphereRadius;		//!< �ٿ�� �� ������
	
	stEMVec2		m_stBBoxOffset;			//!< BoundingBox Offset
	stEMVec2		m_stBBoxSphereOffset;	//!< BoudnignBox Sphere Offset

public:
	CEMPlane();
	CEMPlane(stEMVec2 stPos, stEMVec2 stSize, float fRot);
	CEMPlane(stEMVec2 stPos, float fWidth, float fHeight, float fRot);

	virtual ~CEMPlane()
	{
		//���� ����������� �ٵ� ���ſ�
		if(GetConnectPhysicState())
		{
			m_pBody->GetWorld()->DestroyBody(m_pBody);
		}


	};

public:
	/**
	@brief m_stPlaneState������ �����մϴ�^^
	@return ����
	*/
	void SetPlaneState(stEMPlaneState stState);

	/**
	@brief CEMPlane�� ���� ���� ������ �Լ� �Դϴ�. (���� ����/ ��������/��������)
	@return E_PLANESTATE(���� ���� �Ǿ��� ��������)
	*/
	E_PLANESTATE GetPlaneState();


	/**
	@brief ���� ��ϵǾ��� �ؽ�ó�� ���� ��θ� �˾Ƴ��� �Լ��Դϴ�. ( ���� �̸����� ����)
	@return ���� ���
	*/
	stdEMString GetFilePath() { return m_sFilePath;}

	/**
	@brief ���� ��ϵǾ��� �ؽ�ó�� ���� �̸��� �˾Ƴ��� �Լ��Դϴ�.
	@return ���� �̸�
	*/
	stdEMString GetFileName() { return m_sFileName;}	

	/**
	@brief ����� ������Ʈ�� �̸��� �����մϴ�.
	@param sName : ����� ������Ʈ �̸�
	@return ����
	*/
	void SetName(stdEMString sName) { m_sName = sName; }
	stdEMString GetName()			{return m_sName;}

	/**
	@brief Commit�Ҷ� �߰��Ǵ� ���̵� �����Լ��Դϴ�. (�������ο��� ���)

	@param int nID : �Ƶ��̰�
	@return ����
	*/
	void SetID(int nID)			{m_nID = nID;}
	int GetID()					{return m_nID;}

	virtual void PolygonVertexRelease();

	/**
	@brief �� ����
	@param fR 
	@param fG
	@param fB
	@param fA ���� �⺻�� 1.0f
	@return ����
	*/
	virtual void SetColor(float fR, float fG, float fB, float fA=1.0f);
	virtual void SetColor(CEMColor color);
	virtual CEMColor GetColor()	{return m_Color;}

	/**
	@brief ������ ���� �Լ� 
	@param fX
	@param fY
	@return ����
	*/
	virtual void SetSize(float fX, float fY=-1.0f);
	virtual void SetSize(stEMVec2 stSize);
	virtual stEMVec2 GetSize()	{return m_stSize;}

	/**
	@brief ��ġ�� ���� ������Ʈ �̵��� ���Լ��� ȣ���ϸ�ȵǰ� �Ʒ��� �ִ� MoveX, MoveY, MoveZ �Լ��� ȣ���ϼž��մϴ�.
	@param fX
	@param fY
	@param fZ
	@return ����
	*/
	virtual void SetPos(float fX, float fY, float fZ);
	virtual void SetPos(float fX, float fY);
	virtual void SetPos(stEMVec2 vec2);	
	virtual void SetPos(stEMVec3 vec3);

	virtual stEMVec2 GetPosVec2()		{stEMVec2 ntemp;  ntemp.m_fX = m_stPosVec3.m_fX, ntemp.m_fY = m_stPosVec3.m_fY; return ntemp;}
	virtual stEMVec3 GetPosVec3()		{return m_stPosVec3;}

	/**
	@brief uv ���� �� ����
	@param stUv : ��ġ 
	@return ����
	*/
	virtual void SetUV(stEMVec2 stLowLeft, stEMVec2 stUpRight);
	virtual void GetUV(stEMVec2& stLowLeft, stEMVec2& stUpRight);

	/**
	@brief ȭ�鿡 ��µǴ� Plane���� ������ǥ�� ������ �� �ֵ��� �մϴ�.
	@param stPt : ������ǥ 
	@return ����
	*/
	virtual void SetLocalVec(stEMVec2 stPt)			{ m_stLocalVec2 = stPt; }
	virtual void SetLocalVec(float fX, float fy)	{ m_stLocalVec2.m_fX = fX; m_stLocalVec2.m_fY = fy; }
	virtual stEMVec2 GetLocalVec()					{ return m_stLocalVec2; }

	/**
	@brief plane�� �����ġ�� ���� �� �� �ֽ��ϴ�.
	@param stOffset : �̵���
	@return ����
	*/
	virtual void SetOffset(stEMOffset stOffset);//		{ m_stOffset = stOffset; }
	virtual void SetOffset(float fX, float fY);	//	{ m_stOffset.m_fX; m_stOffset.m_fY; }
	virtual stEMOffset GetOffset()					{ return m_stOffset; }

	/**
	@brief �浹���� ���� �Լ� �Դϴ�.
		   Update()���� �ǽð����� ȣ�����ݴϴ�.
	@param stLT : ���� ��
	@param stLB : ���� �Ʒ�
	@param stRT : ������ ��
	@param stRB : ������ �Ʒ�
	@return ����
	*/	
	virtual void SetBoundingBox(stEMVec3 stLT, stEMVec3 stLB, stEMVec3 stRT, stEMVec3 stRB);
	virtual void SetBoundingBox();

	/**
	@brief �ٿ�� �ڽ� ������ ���ɴϴ�.
		   ������ ������ Plane�� ��ġ ���� ���Ǿ����� ���ϵǰ�
		   ������ ������ �������� ��ġ���� ������ֹǷ� �׳� ���ϵȴ�.
	@return stBoundingBox
	*/
	virtual stEMBoundingBox GetBoundingBox();

	/**
	@brief �ٿ�� �ڽ� ����Ұ����� ���Ұ������� �˻�!
	@return ����
	*/
	virtual void SetBoundingBoxCalc(bool bFlag)		{m_bBoundBoxCalcFlag = bFlag;}
	virtual bool GetBoundingBoxCalc()				{ return m_bBoundBoxCalcFlag; }

	/**
	@brief �������� �ؾ��Ҷ��� ���� �������� ó���Ѵ�. 
		   ���������ÿ��� �ڵ����� SetFrustumCulling(false) �մϴ�
		   ȭ������ Plane�� ����ڰ� ���� �����ؾ��մϴ�

	@param bFlag : true�� ������������ false�� ������������ ���
	@return ����
	*/
	virtual void SetOrtho2D(bool bFlag);
	virtual bool GetOrtho2D()	{ return m_bOrtho2D;}

	/**
	@brief ���� Ű��, ����
	@param bBlend
	@return ����
	*/
	virtual void SetBlend(bool bBlend)	{ m_bBlend = bBlend; }
	virtual bool GetBlend()	{ return m_bBlend; }

	/**
	@brief �������� �ø� On/OFF
	@param bFlag : true/false
	@return ����
	*/
	virtual void SetFrustumCulling(bool bFlag)	{ m_bFrstumCulling = bFlag; }
	virtual bool GetFrustumCulling()			{return m_bFrstumCulling;}

	/** 
	@brief �޸� ������� y�� ȸ���� �޸��� �Ⱥ��϶� �̳��� false�� ���ݴϴ�. 
	@param bool bFlag : true�� �޸� �Ⱥ��̰� false�� �޸� ���δ�.
	@return ���� ����
	*/
	virtual void SetBackFaceCulling(bool bFlag)		{m_bBackCulling = bFlag;}
	virtual bool GetBackFaceCulling()				{return m_bBackCulling;}

	/**
	@brief x,y,z ȸ���� ����  
		   [����] ������ z�� ȸ���� �־��^^ ����ϻ�
	@param fRot : (Degree)���� �Է��Ͻø� �˴ϴ�
	@return ����
	*/
	virtual void SetXRot(float fRot);
	virtual void SetYRot(float fRot);
	virtual void SetZRot(float fRot);
	virtual float GetXRot()	{return m_fXRot;}		
	virtual float GetYRot()	{return m_fYRot;}
	virtual float GetZRot()	{return m_fZRot;}
	
	/**
	@brief �ؽ��� ���� ���� ����
	@param nWidth : ����
	@return ����
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
	@brief plane ��<--->��   ��--->�� ���� ����
	@param eType : E_RIGHT_MIRROR,	E_UP_LEFT_MIRROR,	E_UP_RIGHT_MIRROR,	E_LEFT_MIRROR
	@return ����
	*/	
	virtual void SetMirrorType(eMirrorType eType)			{ m_eMirrorType = eType;}
	eMirrorType GetMirrorType()		{ return m_eMirrorType; }

	/** 
	@brief plane�� ���� ����(ex) Ÿ��1, Ÿ��2 ^^
	@param nType : Ÿ�� ��ȣ
	@return ����
	*/
	virtual void SetType(int nType)	{m_nType = nType;}
	virtual int GetType()			{return m_nType;}

	/**
	@brief Body�� ������ ��
	@return b2Body*
	 */
	virtual b2Body*	GetBody(void);

	/**
	@brief Fixture�� ���´�.
	@return b2Fixture*
	 */
	virtual b2Fixture*	GetFixture();



		/**
	@brief �ٿ�� �ڽ� ����/������/��/�Ʒ� ������ ����
	       fVal���� -�� �������� �� �þ��
		   fVal���� +�� ���������� �پ���.
		
		(-+) LT  ---------- RT (++)
				|	  	   |
				|		   |
		(--) LB  ---------- RB (+-)
		
	@param float : �� ����
	@return ����
	*/
	virtual void SetLeftSizeOfBBox(float fVal);
	virtual void SetRightSizeOfBBox(float fVal);
	virtual void SetUpSizeOfBBox(float fVal);
	virtual void SetDownSizeOfBBox(float fVal);

		/**
	@brief �ٿ�� �ڽ� �߾���ġ ����

	@param float : fX
	@param float : fY
	@param 
	@return ����
	*/
	virtual void SetBoundingBoxCenterPos(float fX, float fY);
	virtual void SetBoundingBoxCenterPos(stEMVec2 stVec2);

		/**
	@brief �ٿ�� �� ������ ����

	@param float : ������
	@param 
	@param 
	@return ����
	*/
	virtual void SetBoundingSphereRadius(float fRadius);

	/**
	@brief �� �߾� ��ġ ����

	@param float : fX
	@param float : fY
	@param 
	@return ����
	*/
	virtual void SetBoundingSphereCenterPos(float fX, float fY);
	virtual void SetBoundingSphereCenterPos(stEMVec2 stVec2);

	//====================================================================================
	public:
	/**
	@brief Body�� ������ �ݴϴ�
	@param boBody* body : ������� ȸ�������� �˾Ƴ�
	@return ����
	 */
	virtual void ConnectBody(b2Body* pBody);

	/**
	@brief ���� ���� ���� ����
	@param state : ���� (true/false
	@return ����
	*/
	virtual void SetConnectPhysicState(bool state)	{ m_bPhysicConnectFlag = state;}
	virtual bool GetConnectPhysicState();

	/**
	@brief ���ο� ���� �����մϴ�.
	@param fA 
	@param 
	@param 
	@param 
	@param 
	@return ����
	*/
	virtual void SetAlpha(float fA);
	virtual float GetAlpha()	{return m_Color.m_fA;}

	/**
	@brief �������� �����ϰų� �˾ƿ��� �Լ��Դϴ� b2CircleShape�� ��������� ���
	@param 
	@param 
	@return ����
	*/
	virtual void SetRadius(float fRadius);
	virtual float GetRadius()	{return m_stBBox.fRadius;}
	
	/**
	@brief Plane �̵��� ȣ�����ִ� �Լ� �Դϴ�. 
	@param fMove : �̵��� �Ÿ�
	@return ����
	*/
	virtual void MoveX(float fMove);
	virtual void MoveY(float fMove);
	virtual void MoveZ(float fMove);
	
	virtual void UpdatePhysic();
	virtual void Update(float dt);
	virtual void Render();

	//virtual bool SetTexutre( RGB24Pixel* pImageData=NULL, int nWidth=0, int nHeight=0){return true;}

	/**
	@brief �����Ǿ����ִ� �ؽ��� ���� ������ �ʱ�ȭ�մϴ�
	@return ����
	*/
	void ResetTextureInfo();

	/**
	@brief ���׷��ִ� �Լ��Դϴ�.

	@param fR : ��������
	@return ����
	*/
	void RenderCircle(const float fR, stEMVec3 stVec3, CEMColor color);

	

		/**
	@brief PLANE�� Texture�����ϴ� �Լ��Դϴ�. (���忡�� �����ϴ� �ؽ����Դϴ�) ���Լ��� �������� ����ҽÿ�^^ �������� ������
	       �� �Լ��� ������� ���� �Ʒ� �ִ� �Լ��� ����Ͻñ� �ٶ��ϴ�.

	@param stdEMString strFileName	: ���� �̸�
	@param GLint nClampMode = GL_CLAMP : clamp
	@param GLint nFilter = GL_LINEAR : filter
	@param  bool bOption = FALSE : bOption
	@param 
	@return ��������
	*/
	bool SetTexture(stdEMString strFileName, GLint nClampMode = GL_CLAMP, GLint nFilter = GL_LINEAR, bool bOption = FALSE);
	
	/**
	@brief ���� �ؽ��ĸ� �߰��Ҷ����� ���Լ��� ����մϴ�.(���������� �ؽ����߰��� �̰ɷ� ���ݴϴ�)

	@param pScene : �ؽ��ĸ� �߰��� �� ������
	@param stdEMString strFileName	: ���� �̸�
	@param GLint nClampMode = GL_CLAMP : clamp
	@param GLint nFilter = GL_LINEAR : filter
	@param bool bOption = FALSE : bOption
	@param 
	@return ��������
	*/
	bool SetTexture(CRootScene* pScene, stdEMString strFileName, GLint nClampMode = GL_CLAMP, GLint nFilter = GL_LINEAR, bool bOption = FALSE);

	// ������� ������^ �ӽ��Դϴ�Kinect���� ���Ǿ���
	//bool UpdateTexture(RGB24Pixel* pData, int nWidth, int nHeight, GLuint nID);
	/**
	@brief ���� Ŭ���� �̸� ������
	@return stdEMString
	*/
	virtual const stdEMString GetClassName() { return "CEMPlane"; }

	private:


	/**
	@brief plane�� ������ �ؽ��� id���� �����մϴ�. 
		  -1�� �����ϸ� �ؽ��İ� ��µ��� �ʾƿ� �⺻���� -1�Դϴ�.  Ȥ�� �ؽ��ĸ� ���� �Ͻ÷��� -1�� �־�����մϴ�.

	@param int nID : ���̵� ����
	@return ����
	*/
	void SetTextureID(int nID)		{ m_nTextureID = nID;}
	int GetTextureID()				{ return m_nTextureID;  }

	/**
	@brief ���������� staitc-->���� dynamic���� �����Ұ�찡 �����Ƿ� �̷� ���¸� ��� upate()���� üũ������մϴ�.
		   �׷����� �ϴ� �Լ� �Դϴ�. 
	@param 
	@return ����
	 */
	void UpdateBodyType();


	/**
	@brief �ְ����� �ְ����� ��� �Ͽ��ִ� �Լ� �Դϴ�(���� ���ο��� ���)
	@param pShape : 
	@param stMin : �ּ��� ����
	@param stMax : �ְ��� ����
	@return 
	 */
	void CalcMinMax(b2PolygonShape* pShape, b2Vec2* stMin, b2Vec2* stMax);
};



