#pragma once



class CEMFrustumPlane
{
public:
	stEMVec3 m_stNormalVec3;
	stEMVec3 m_stPointVec3;

	float m_fD;

public:
	CEMFrustumPlane::CEMFrustumPlane( stEMVec3 &v1,  stEMVec3 &v2,  stEMVec3 &v3 );

	CEMFrustumPlane()
	{

		m_fD = 0.0f;
	};

	~CEMFrustumPlane()
	{
		
	}
public:

	void Set3Points( stEMVec3 &v1,  stEMVec3 &v2,  stEMVec3 &v3);
	void SetNormalAndPoint(stEMVec3 &normal, stEMVec3 &point);
	void SetCoefficients(float a, float b, float c, float d);
	float Distance(stEMVec3 &p);
};


enum 
{
	E_TOP = 0,
	E_BOTTOM,
	E_LEFT,
	E_RIGHT,
	E_NEAR,
	E_FAR
};

static enum {
	E_OUTSIDE,		//!< Frustum 밖
	E_INTERSECT,	//!< Frustum 겹침
	E_INSIDE		//!< Frustum 안쪽
};


/**
	@file    : EMFrustum.h
	@author  : wo
	@version : 1.0
	@brief   : 프러스텀 컬링 관련 크래스 
 */
class CEMFrustum
{
private:
	CEMFrustumPlane FrustumPlane[6];				//!< 위 아래 완쪽 오른쪽 앞 뒤
		

public:
	stEMVec3 m_stNtl;
	stEMVec3 m_stNtr;
	stEMVec3 m_stNbl;
	stEMVec3 m_stNbr;
	stEMVec3 m_stFtl;
	stEMVec3 m_stFtr;
	stEMVec3 m_stFbl;
	stEMVec3 m_stFbr;

	float	 m_fNearDistance;
	float	 m_fFarDistance;
	float	 m_fRatio;
	float	 m_fAngle;
	float	 m_fTang;
	
	float	 m_fNw,m_fNh,m_fFw,m_fFh;

	CEMFrustum()
	{
		m_fNearDistance = m_fFarDistance= m_fRatio = m_fAngle = m_fTang = m_fNw = m_fNh = m_fFw = m_fFh = 0.0f;

		ZeroMemory(&m_stNtl, sizeof(stEMVec3));
		ZeroMemory(&m_stNtr, sizeof(stEMVec3));
		ZeroMemory(&m_stNbl, sizeof(stEMVec3));
		ZeroMemory(&m_stNbr, sizeof(stEMVec3));
		ZeroMemory(&m_stFtl, sizeof(stEMVec3));
		ZeroMemory(&m_stFtr, sizeof(stEMVec3));
		ZeroMemory(&m_stFbl, sizeof(stEMVec3));
		ZeroMemory(&m_stFbr, sizeof(stEMVec3));
	};

public:

	virtual ~CEMFrustum(void)
	{
		
	};

	static CEMFrustum* Instance();


public:
	/**
	@brief : 카메라 업데이트시마다 호출되어야합니다.(엔진 부분에서 설정 되어짐)

	@param stEMVec3& stPos : 카메라 위치
	@param stEMVec3& stViewPoint : 바라보는 위치
	@param stEMVec3& stUpVec : 업벡터
	@param 

	@return : 없음
	*/
	void SetCamDef(stEMVec3& stPos, stEMVec3& stViewPoint, stEMVec3& stUpVec);

/**
	@brief : 처음 설정하는 부분 (엔진에서 호출)

	@param float angle : 각도
	@param float fRatio : 화면 비
	@param fNearD : Near
	@param fFarD : Far
	@param 

	@return : 없음
*/
	void SetCamInternals(float fAngle, float fRatio, float fNearD, float fFarD);
	
	/**
	@brief : 점으로 컬링

	@param stVec3Point : 점위치
	@param 

	@return : 컬링 true/false
	*/
	int PointInFrustum(stEMVec3 &stVec3Point);

	/**
	@brief : 구로 컬링

	@param stVec3Point : 원점 위치
	@param fRadius : 반지름
	@param 
	@param 
	@param 

	@return : 컬링 true/false
	*/
	int SphereInFrustum(stEMVec3 &stVec3Point, float fRadius);

	// int boxInFrustum(CEMBBox &b);
};