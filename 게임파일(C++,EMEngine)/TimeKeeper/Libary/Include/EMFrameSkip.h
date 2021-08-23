#pragma once

//출처 : 감자넷에 있는 기법을 참고 하였습니다.
class CEMFrameSkip 
{ 
///protected: 

	
public:
	float m_fTimer; 
	float m_fSecPerFrame; 

public:
	CEMFrameSkip()	
	{
		Clear();
	} 
	virtual ~CEMFrameSkip(){} 

public: 
 	void Clear() 
 	{ 
 		SetFramePerSec( m_fSecPerFrame ); 
 		//m_fSecPerFrame = 0.0f;
 		m_fTimer = 0.0f; 
 	} 

	void SetFramePerSec( float fps ) 
	{ 
		m_fSecPerFrame = 1.0f/fps;
	} 

	// 원하는 프레임보다 너무 빠르면, 
	// false를 반환해서 코드를 동작시키지 않도록 한다. 
	// dt는 '초'단위 (밀리초 아님!!!) 
	bool Update( float dt ) 
	{ 
		m_fTimer += dt;

		if( m_fTimer<0 ) 
			return false;

		// 한프레임에 해당하는 시간을 뺀다. 
		m_fTimer -= m_fSecPerFrame;

		return true; 
	} 

	// Update후에 호출해서 frame skip을 수행해야 하는지 검사한다. 
	// frame skip이 일어나야 한다면 true를 반환한다. 
	bool IsFrameSkip() 
	{ 
		return m_fTimer >= 0; 
	} 

}; 


