#pragma once

#include "atltypes.h"

class CEMMatrix4x4;

/**
	@file    : EMCamera.h
	@author  : wo
	@version : 1.0f
	@brief   : �ִϸ��̼� Ŭ����
 */
class CEMCamera : public CEMPlane
{
private:
	static CEMCamera*	m_pCamera;			//!< �̱���
	int					m_nWinWidth;		//!< ������ ����
	int					m_nWinHeight;		//!< ������ ����
	double				m_dAper;			//!< 

	stEMVec3 			m_vPos;				//!< ī�޶� ��ġ
	stEMVec3			m_vRightVector;		//!< ������ ����
	stEMVec3 			m_vView;			//!< �ٶ󺸴� ��
	stEMVec3 			m_vUp;				//!< �� ����

	float				m_fNear;			//!< ���� ���
	float				m_fFar;				//!< ���� ���

	GLfloat				m_fRotX;			//!< x�� ȸ��
	GLfloat				m_fRotY;			//!< y�� ȸ��
	GLfloat				m_fRotZ;			//!< z�� ȸ��

public:
	CEMMatrix4x4		mWorldToViewMatrix;
	CEMMatrix4x4		mViewToWorldMatrix;
	stEMVec3			mEyePoint;
	stEMVec3			mClickPosition;
	float				m_fFov_PI_Calc;		//!<fov*kpi/360.0f;���Ǿ��� �� ����
	float				m_fAspect;
	stEMVec3			m_stViewPoint;

protected:
	CEMCamera()
	{
		m_nWinWidth = 0;
		m_nWinHeight = 0;
		m_pCamera = NULL;

		m_fRotX = 0.0f;
		m_fRotY = 0.0f;
		m_fRotZ = 0.0f;
		m_fFov_PI_Calc = 0.0f;//
		m_fAspect = 0.0f;
		m_stViewPoint = stEMVec3(0.0f, 0.0f, 0.0f);

		InitCamera();
	};

public:
	virtual ~CEMCamera(void)
	{
		
	};

	static CEMCamera* Instance();

public:
	/**
	@brief �̱����� ���� �޸� �Ҵ��� �߱⶧���� �� �Լ��� delete���ְ� �ִ�.

	@param 
	@param 	
	@param 	
	@return ����
	*/
	void Destroy();	
	
public:
	void LootAtCalc(stEMVec3& eye, stEMVec3 lookat, stEMVec3 up);

public:
	double GetFov()				{return m_dAper;}

	/**
	@brief ������ ������ ����

	@param int nWidth  : ����
	@param int nHeight : ����
	@param 	
	@return ����
	*/
	void WindowReSize(int nWidth, int nHeight);
	void MFCWindowReSize(RECT rt);

	void Update(float dt);
	/**
	@brief �����찡 �������� �Ǹ� ȣ��Ǵ� callback�Լ� �Դϴ�.

	@param int w : ����
	@param int h : ����
	@param 	
	@return ����
	*/
	static void	GLFWCALL ResizeCallback(int w, int h);
	static void GLFWCALL MFCResizeCallback(RECT rt);

/**
	@brief ī�޶� ������ �Լ�
		   ���������� �� glutLookAt�Լ��� ȣ��˴ϴ�
	@return ����
	*/
	void Render();

	/**
	@brief ī�޶� �ʱ�ȭ�Լ�

	@param 
	@param 
	@param 	
	@return ����
	*/
	void InitCamera();


	/**
	@brief ������ ���� ���� �˾ƿ��� �Լ�

	@param 
	@param 
	@param 	
	@return ����
	*/
	int GetWinWidth()			{return m_nWinWidth;}
	int GetWinHeight()			{return m_nWinHeight;}

	void SetWinWidth(int nWidth)  {m_nWinWidth = nWidth;}
	void SetWinHeight(int nHeight) {m_nWinHeight = nHeight;}
 

	/**
	@brief Radius�˾ƿ��� �Լ�

	@param 
	@param 
	@param 	
	@return ����
	*/
 	double GetViewRadius();


	/**
	@brief ������� Max �� Min Vertex���� ������

	@param 
	@param 
	@param 	
	@return ����
	*/
	stEMVec2 GetWorldMaxVertex();
	stEMVec2 GetWorldMinVertex();

public:

	/**
	@brief ��ġ ����

	@param float fX : x
	@param float fY : y
	@param float fZ : z
	@param 
	@param 
	@return ����
	*/
 	virtual void SetPos(float fX, float fY, float fZ);
 	virtual void SetPos(float fX, float fY);
 	virtual void SetPos(stEMVec3 vPos);
	virtual void SetPosX(float fX);
 	virtual void SetPosZ(float fZ);
 	virtual void SetPosY(float fY);

	/**
	@brief Near �� ����

	@param float fNear : near��
	@param 
	@param 
	@return ����
	*/
	virtual void SetNear(float fNear);

	/**
	@brief Far�� ����

	@param fFar : fFar��
	@param 
	@param 
	@return ����
	*/
 	virtual void SetFar(float fFar);

	/**
	@brief �� �����Լ�

	@param
	@param 
	@param 
	@return ����
	*/
 	virtual void SetView(float fX, float fY, float fZ);
 
	/**
	@brief ī�޶� ��ġ������

	@param
	@param 
	@param 
	@return stEMVec3 / stEMVec2
	*/
 	virtual stEMVec3 GetPosVec3()	{return m_vPos;}
 	virtual stEMVec2 GetPosVec2();

	/**
	@brief Near / Far���

	@param
	@param 
	@param 
	@return float
	*/
	virtual float GetNear()		{return m_fNear;}
	virtual float GetFar()		{return m_fFar;}

	/**
	@brief �� ���

	@param
	@param 
	@param 
	@return stEMVec3
	*/
	virtual stEMVec3 GetView()	{return m_vView;}

	/**
	@brief �� ���

	@param float fAngle : ȸ�� ����(��׸����� �Է��Ͻø� �˴ϴ�)
	@param 
	@param 
	@return ����
	*/
	void RotX( float fAngle);
	void RotY( float Angle);
	void RotZ( float Angle);

	void Move( stEMVec3 stDir );

	/**
	@brief ī�޶� �̵�

	@param 
	@param 
	@param 
	@return ����
	*/
	virtual void MoveZ( float fDis );
	virtual void MoveY( float fDis );
	virtual void MoveX( float fDis );
};

GLfloat GetF3dVectorLength( stEMVec3 * v);
stEMVec3 Normalize3dVector( stEMVec3 v);
stEMVec3 CrossProduct (stEMVec3 * u, stEMVec3 * v);
