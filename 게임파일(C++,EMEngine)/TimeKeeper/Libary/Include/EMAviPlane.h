#pragma once

/**
	@file    : EMAviPlane.h
	@author  : wo
	@version : 1.0f
	@brief   : 동영상 출력 클래스 입니다
 */
class CEMAviPlane : public CEMPlane
{
private:
	int		m_nFrame;
	int		m_nNext;

	//======================================
	//동영상
	HDRAWDIB			m_hdd;					//!< 동영상 때문에 넣었다
	HBITMAP				m_hBitmap;				//!< 동영상 때문에 넣었다
	AVISTREAMINFO		m_psi;					// Pointer To A Structure Containing Stream Info
	PAVISTREAM			m_pavi;					// Handle To An Open Stream
	PGETFRAME			m_pgf;					// Pointer To A GetFrame Object
	BITMAPINFOHEADER	m_bmih;					// Header Information For DrawDibDraw Decoding
	long				m_lastframe;			// Last Frame Of The Stream
	int					m_width;				// Video Width
	int					m_height;				// Video Height
	char*				m_pdata;				// Pointer To Texture Data
	int					m_mpf;					// Will Hold Rough Milliseconds Per Frame
	unsigned char*		m_data;					// Pointer To Our Resized Image
	//======================================
	
public:
	CEMAviPlane(stdEMString stFileName);
	virtual ~CEMAviPlane(void)
	{
		DeleteObject(m_hBitmap);			// Delete The Device Dependant Bitmap Object
		DrawDibClose(m_hdd);				// Closes The DrawDib Device Context
		AVIStreamGetFrameClose(m_pgf);		// Deallocates The GetFrame Resources
		AVIStreamRelease(m_pavi);			// Release The Stream
		AVIFileExit();						// Release The File
	};
	
public:
	virtual void Update(float dt);
	virtual void Render();
	virtual const stdEMString GetClassName() { return "CEMAviPlane"; }

private:
	void GrabAVIFrame(int frame);
	void FileOpenAVI(stdEMString stFileName);
	
};