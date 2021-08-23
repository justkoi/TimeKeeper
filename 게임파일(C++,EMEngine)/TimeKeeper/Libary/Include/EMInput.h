#pragma once

// void KeyInputCallBack(int nKey, int nState);
// void CharInputCallBack(int nKey, int nState);

class CEMText;
enum
{
	E_KEY_UP,			// 0 [눌렀다 놨을때]
	E_KEY_DOWN,			// 1 [눌렸을때]
	E_KEY_DONTTOUCH,    // 2 [아무것도 안눌린상태]
};

enum enumMouseButton
{
	E_MOUSE_LEFT,		//!< 마우스 왼쪽 클릭
	E_MOUSE_RIGHT,		//!< 마우스 오른쪽 클릭
	E_MOUSE_MIDDLE		//!< 마우스 중앙 클릭
};

/**
	@file    : EMInput.h
	@author  : wo
	@version : 1.0f
	@brief   : 키정보 저장 구조체
 */
typedef struct keyinfo
{
	int iState;

	DWORD dwKDownTime;
	DWORD dwKUpTime;
	DWORD dwOldDownTime;
	DWORD dwOldUpTime;

	bool bKeyDown;
}stKeyInfo;

/**
	@file    : EMInput.h
	@author  : wo
	@version : 1.0f
	@brief   : 마우스 정보 저장 구조체
 */
typedef struct MouseInfo
{
	int m_nX;
	int m_nY;
}stMouseInfo;

/**
	@file    : EMAnimation.h
	@author  : wo
	@version : 1.0f
	@brief   : 키 정보 클래스
 */
class CEMInput 
{
private:
	stKeyInfo m_stKey[256];
	float m_fDelayTime;

	bool m_bActive;			//!윈도우가 활성화냐 아니냐 판단요

	stMouseInfo m_stMousePos;					//!< 마우스 실시간 이동 위치값
	stMouseInfo m_stLButtonClickMousePos;		//!< 왼쪽 마우스 클릭 위치
	stMouseInfo m_stRButtonClickMousePos;		//!< 오른쪽 마우스 클릭 위치

protected:	
	CEMInput()
	{
		m_bActive = false;
	/*	m_pText = NULL;*/

		for(int i=0; i<256; i++)
			m_stKey[i].iState = E_KEY_DONTTOUCH;
		/*memset(m_stKey, 0, sizeof(m_stKey));*/
		memset(&m_stMousePos, 0, sizeof(stMouseInfo));
		memset(&m_stLButtonClickMousePos, 0,sizeof(stMouseInfo));
		memset(&m_stRButtonClickMousePos, 0,sizeof(stMouseInfo));
	};
	
public:
	/*CEMText* m_pText;*/

	virtual ~CEMInput()
	{
		
	};
	static CEMInput* Instance();

public:
	bool GetWinActiveState()	{return m_bActive;}
	void SetWinActiveState(bool bState)	{m_bActive = bState;}

public:
	/**
	@brief 키보드 및 마우스 정보 업데이트 완료
	@param 
	@param 
	@param 
	@param 
	@param 
	@return void
	*/
	void Update();

	/**
	@brief 특정 키가 눌렸는지를 파악합니다
	@param 
	@param 
	@param 
	@param 
	@param 
	@return E_KEY_DONTTOUCH, E_KEY_UP,	E_KEY_DOWN	눌렸다면 셋중에 down이 리턴됩니다ㅣ.
	*/
	int IsKeyDown(int vk);

	/**
	@brief 특정 키가 눌렀다 띠어졌는지를 알아옵니다
	@param 
	@param 
	@param 
	@param 
	@param 
	@return E_KEY_UP 조건이 맞는다면 이놈 리턴요^^
	*/
	int IsKeyUp(int vk);

// 	bool IsKeyLongDown(int vk , float delay);
// 	bool IsKeyDoubleDown(int vk , float delay);

	/**
	@brief 키상태를 알아오는 함수 입니다. 
	@param 
	@param 
	@param 
	@param 
	@param 
	@return E_KEY_DONTTOUCH, E_KEY_UP,	E_KEY_DOWN 중 하나가 리턴되겠군요^^
	*/
	int GetKeyState(int vk);

	/**
	@brief 키상태를 알아오는 함수 입니다. 
		   E_KEY_DONTTOUCH 가 없이 E_KEY_UP or E_KEY_DOWN 둘중 하나만 리턴해줍니다ㅣ. 
	@param 
	@param 
	@param 
	@param 
	@param 
	@return E_KEY_DONTTOUCH, E_KEY_UP,	E_KEY_DOWN 중 하나가 리턴되겠군요^^
	*/
	int GetKeyStateExt(int vk);

	/**
	@brief 마우스 이동 위치 알아옵니다.
	@param 
	@param 
	@param 
	@param 
	@param 
	@return 
	*/	
	stMouseInfo GetMouseMovePos();
	
	/**
	@brief 마우스 위치 지정
	@param 
	@param 
	@param 
	@param 
	@param 
	@return 없음
	*/		
	void SetMousePos(stMouseInfo stMPos);

	/**
	@brief 씬 변경시에 전씬에서 키눌린것이 바뀐씬에서 적용되지 않도록 이 함수를 호출하여 초기화하는 것이다.
 	@param 
	@param 
	@param 
	@param 
	@param 
	@return 없음
	*/		
	void Reset();

	//! 콜백함수 static으로 선언했어염^^^ ㅋ ㅑㅋ ㅑ 이안에서는 싱글톤으로 접속 하셔야해염^^(주의)
	static void GLFWCALL MousePosCallBack(int nX, int nY);
	static void GLFWCALL MouseButtonCallBack(int nButton, int nState);
};