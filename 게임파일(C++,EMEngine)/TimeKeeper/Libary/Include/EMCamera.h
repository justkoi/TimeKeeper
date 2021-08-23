#pragma once

#include "atltypes.h"

class CEMMatrix4x4;

/**
	@file    : EMCamera.h
	@author  : wo
	@version : 1.0f
	@brief   : 애니메이션 클래스
 */
class CEMCamera : public CEMPlane
{
private:
	static CEMCamera*	m_pCamera;			//!< 싱글톤
	int					m_nWinWidth;		//!< 윈도우 넓이
	int					m_nWinHeight;		//!< 윈도우 높이
	double				m_dAper;			//!< 

	stEMVec3 			m_vPos;				//!< 카메라 위치
	stEMVec3			m_vRightVector;		//!< 오른쪽 벡터
	stEMVec3 			m_vView;			//!< 바라보는 곳
	stEMVec3 			m_vUp;				//!< 업 벡터

	float				m_fNear;			//!< 앞쪽 경계
	float				m_fFar;				//!< 뒤쪽 경계

	GLfloat				m_fRotX;			//!< x축 회전
	GLfloat				m_fRotY;			//!< y축 회전
	GLfloat				m_fRotZ;			//!< z축 회전

public:
	CEMMatrix4x4		mWorldToViewMatrix;
	CEMMatrix4x4		mViewToWorldMatrix;
	stEMVec3			mEyePoint;
	stEMVec3			mClickPosition;
	float				m_fFov_PI_Calc;		//!<fov*kpi/360.0f;계산되어진 값 저장
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
	@brief 싱글톤이 동적 메모리 할당을 했기때문에 이 함수로 delete해주고 있다.

	@param 
	@param 	
	@param 	
	@return 없음
	*/
	void Destroy();	
	
public:
	void LootAtCalc(stEMVec3& eye, stEMVec3 lookat, stEMVec3 up);

public:
	double GetFov()				{return m_dAper;}

	/**
	@brief 윈도우 사이즈 설정

	@param int nWidth  : 넓이
	@param int nHeight : 높이
	@param 	
	@return 없음
	*/
	void WindowReSize(int nWidth, int nHeight);
	void MFCWindowReSize(RECT rt);

	void Update(float dt);
	/**
	@brief 윈도우가 리사이즈 되면 호출되는 callback함수 입니다.

	@param int w : 넓이
	@param int h : 높이
	@param 	
	@return 없음
	*/
	static void	GLFWCALL ResizeCallback(int w, int h);
	static void GLFWCALL MFCResizeCallback(RECT rt);

/**
	@brief 카메라 랜더링 함수
		   내무적으로 는 glutLookAt함수가 호출됩니다
	@return 없음
	*/
	void Render();

	/**
	@brief 카메라 초기화함수

	@param 
	@param 
	@param 	
	@return 없음
	*/
	void InitCamera();


	/**
	@brief 윈도우 넓이 높이 알아오는 함수

	@param 
	@param 
	@param 	
	@return 없음
	*/
	int GetWinWidth()			{return m_nWinWidth;}
	int GetWinHeight()			{return m_nWinHeight;}

	void SetWinWidth(int nWidth)  {m_nWinWidth = nWidth;}
	void SetWinHeight(int nHeight) {m_nWinHeight = nHeight;}
 

	/**
	@brief Radius알아오는 함수

	@param 
	@param 
	@param 	
	@return 없음
	*/
 	double GetViewRadius();


	/**
	@brief 월드상의 Max 및 Min Vertex정보 얻어오기

	@param 
	@param 
	@param 	
	@return 없음
	*/
	stEMVec2 GetWorldMaxVertex();
	stEMVec2 GetWorldMinVertex();

public:

	/**
	@brief 위치 설정

	@param float fX : x
	@param float fY : y
	@param float fZ : z
	@param 
	@param 
	@return 없음
	*/
 	virtual void SetPos(float fX, float fY, float fZ);
 	virtual void SetPos(float fX, float fY);
 	virtual void SetPos(stEMVec3 vPos);
	virtual void SetPosX(float fX);
 	virtual void SetPosZ(float fZ);
 	virtual void SetPosY(float fY);

	/**
	@brief Near 값 설정

	@param float fNear : near값
	@param 
	@param 
	@return 없음
	*/
	virtual void SetNear(float fNear);

	/**
	@brief Far값 설정

	@param fFar : fFar값
	@param 
	@param 
	@return 없음
	*/
 	virtual void SetFar(float fFar);

	/**
	@brief 뷰 설정함수

	@param
	@param 
	@param 
	@return 없음
	*/
 	virtual void SetView(float fX, float fY, float fZ);
 
	/**
	@brief 카메라 위치얻어오기

	@param
	@param 
	@param 
	@return stEMVec3 / stEMVec2
	*/
 	virtual stEMVec3 GetPosVec3()	{return m_vPos;}
 	virtual stEMVec2 GetPosVec2();

	/**
	@brief Near / Far얻기

	@param
	@param 
	@param 
	@return float
	*/
	virtual float GetNear()		{return m_fNear;}
	virtual float GetFar()		{return m_fFar;}

	/**
	@brief 뷰 얻기

	@param
	@param 
	@param 
	@return stEMVec3
	*/
	virtual stEMVec3 GetView()	{return m_vView;}

	/**
	@brief 뷰 얻기

	@param float fAngle : 회전 각도(디그리각도 입력하시면 됩니다)
	@param 
	@param 
	@return 없음
	*/
	void RotX( float fAngle);
	void RotY( float Angle);
	void RotZ( float Angle);

	void Move( stEMVec3 stDir );

	/**
	@brief 카메라 이동

	@param 
	@param 
	@param 
	@return 없음
	*/
	virtual void MoveZ( float fDis );
	virtual void MoveY( float fDis );
	virtual void MoveX( float fDis );
};

GLfloat GetF3dVectorLength( stEMVec3 * v);
stEMVec3 Normalize3dVector( stEMVec3 v);
stEMVec3 CrossProduct (stEMVec3 * u, stEMVec3 * v);
