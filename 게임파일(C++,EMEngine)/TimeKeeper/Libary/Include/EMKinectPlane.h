#pragma once


/**
	@file    : EMKinectPlane.h
	@author  : wo
	@date	 : 2012_5_2 
	@version : 1.1f
	@brief   : Ű��Ʈ ���� �� ȭ�鿡 ������ִ� Plane �Դϴ�.
 */
class CEMKinectPlane : public CEMPlane
{
private:
	RGB24Pixel*			m_pImageData;		
	bool				m_bSetTextureState;			//!< �ؽ��� ���� �Ǿ����� �ľ�
	
	int					m_nTexMapX;
	int					m_nTexMapY;

	int					m_nResX;
	int					m_nResY;
	


public:	
	CEMKinectPlane()
	{
		m_pImageData = NULL;
		m_bSetTextureState = false;

		m_nTexMapX = 0;
		m_nTexMapY = 0;

		m_nResX = 0;
		m_nResY = 0;
	};

	virtual ~CEMKinectPlane(void)
	{
		m_pImageData = NULL;
	};

public:
	virtual void Update(float dt);
	virtual void Render();

	virtual const stdEMString GetClassName() { return "CEMKinectPlane";}

public:
	bool UserSetTexture(RGB24Pixel* pImageData=NULL, int nTexMapX=0, int nTexMapY=0, int nResX=0, int nResY=0);
};