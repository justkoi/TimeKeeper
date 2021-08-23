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
	E_OUTSIDE,		//!< Frustum ��
	E_INTERSECT,	//!< Frustum ��ħ
	E_INSIDE		//!< Frustum ����
};


/**
	@file    : EMFrustum.h
	@author  : wo
	@version : 1.0
	@brief   : �������� �ø� ���� ũ���� 
 */
class CEMFrustum
{
private:
	CEMFrustumPlane FrustumPlane[6];				//!< �� �Ʒ� ���� ������ �� ��
		

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
	@brief : ī�޶� ������Ʈ�ø��� ȣ��Ǿ���մϴ�.(���� �κп��� ���� �Ǿ���)

	@param stEMVec3& stPos : ī�޶� ��ġ
	@param stEMVec3& stViewPoint : �ٶ󺸴� ��ġ
	@param stEMVec3& stUpVec : ������
	@param 

	@return : ����
	*/
	void SetCamDef(stEMVec3& stPos, stEMVec3& stViewPoint, stEMVec3& stUpVec);

/**
	@brief : ó�� �����ϴ� �κ� (�������� ȣ��)

	@param float angle : ����
	@param float fRatio : ȭ�� ��
	@param fNearD : Near
	@param fFarD : Far
	@param 

	@return : ����
*/
	void SetCamInternals(float fAngle, float fRatio, float fNearD, float fFarD);
	
	/**
	@brief : ������ �ø�

	@param stVec3Point : ����ġ
	@param 

	@return : �ø� true/false
	*/
	int PointInFrustum(stEMVec3 &stVec3Point);

	/**
	@brief : ���� �ø�

	@param stVec3Point : ���� ��ġ
	@param fRadius : ������
	@param 
	@param 
	@param 

	@return : �ø� true/false
	*/
	int SphereInFrustum(stEMVec3 &stVec3Point, float fRadius);

	// int boxInFrustum(CEMBBox &b);
};