#pragma once

//��ó : ���ڳݿ� �ִ� ����� ���� �Ͽ����ϴ�.
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

	// ���ϴ� �����Ӻ��� �ʹ� ������, 
	// false�� ��ȯ�ؼ� �ڵ带 ���۽�Ű�� �ʵ��� �Ѵ�. 
	// dt�� '��'���� (�и��� �ƴ�!!!) 
	bool Update( float dt ) 
	{ 
		m_fTimer += dt;

		if( m_fTimer<0 ) 
			return false;

		// �������ӿ� �ش��ϴ� �ð��� ����. 
		m_fTimer -= m_fSecPerFrame;

		return true; 
	} 

	// Update�Ŀ� ȣ���ؼ� frame skip�� �����ؾ� �ϴ��� �˻��Ѵ�. 
	// frame skip�� �Ͼ�� �Ѵٸ� true�� ��ȯ�Ѵ�. 
	bool IsFrameSkip() 
	{ 
		return m_fTimer >= 0; 
	} 

}; 


