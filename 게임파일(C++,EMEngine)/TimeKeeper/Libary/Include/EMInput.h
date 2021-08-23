#pragma once

// void KeyInputCallBack(int nKey, int nState);
// void CharInputCallBack(int nKey, int nState);

class CEMText;
enum
{
	E_KEY_UP,			// 0 [������ ������]
	E_KEY_DOWN,			// 1 [��������]
	E_KEY_DONTTOUCH,    // 2 [�ƹ��͵� �ȴ�������]
};

enum enumMouseButton
{
	E_MOUSE_LEFT,		//!< ���콺 ���� Ŭ��
	E_MOUSE_RIGHT,		//!< ���콺 ������ Ŭ��
	E_MOUSE_MIDDLE		//!< ���콺 �߾� Ŭ��
};

/**
	@file    : EMInput.h
	@author  : wo
	@version : 1.0f
	@brief   : Ű���� ���� ����ü
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
	@brief   : ���콺 ���� ���� ����ü
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
	@brief   : Ű ���� Ŭ����
 */
class CEMInput 
{
private:
	stKeyInfo m_stKey[256];
	float m_fDelayTime;

	bool m_bActive;			//!�����찡 Ȱ��ȭ�� �ƴϳ� �Ǵܿ�

	stMouseInfo m_stMousePos;					//!< ���콺 �ǽð� �̵� ��ġ��
	stMouseInfo m_stLButtonClickMousePos;		//!< ���� ���콺 Ŭ�� ��ġ
	stMouseInfo m_stRButtonClickMousePos;		//!< ������ ���콺 Ŭ�� ��ġ

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
	@brief Ű���� �� ���콺 ���� ������Ʈ �Ϸ�
	@param 
	@param 
	@param 
	@param 
	@param 
	@return void
	*/
	void Update();

	/**
	@brief Ư�� Ű�� ���ȴ����� �ľ��մϴ�
	@param 
	@param 
	@param 
	@param 
	@param 
	@return E_KEY_DONTTOUCH, E_KEY_UP,	E_KEY_DOWN	���ȴٸ� ���߿� down�� ���ϵ˴ϴ٤�.
	*/
	int IsKeyDown(int vk);

	/**
	@brief Ư�� Ű�� ������ ����������� �˾ƿɴϴ�
	@param 
	@param 
	@param 
	@param 
	@param 
	@return E_KEY_UP ������ �´´ٸ� �̳� ���Ͽ�^^
	*/
	int IsKeyUp(int vk);

// 	bool IsKeyLongDown(int vk , float delay);
// 	bool IsKeyDoubleDown(int vk , float delay);

	/**
	@brief Ű���¸� �˾ƿ��� �Լ� �Դϴ�. 
	@param 
	@param 
	@param 
	@param 
	@param 
	@return E_KEY_DONTTOUCH, E_KEY_UP,	E_KEY_DOWN �� �ϳ��� ���ϵǰڱ���^^
	*/
	int GetKeyState(int vk);

	/**
	@brief Ű���¸� �˾ƿ��� �Լ� �Դϴ�. 
		   E_KEY_DONTTOUCH �� ���� E_KEY_UP or E_KEY_DOWN ���� �ϳ��� �������ݴϴ٤�. 
	@param 
	@param 
	@param 
	@param 
	@param 
	@return E_KEY_DONTTOUCH, E_KEY_UP,	E_KEY_DOWN �� �ϳ��� ���ϵǰڱ���^^
	*/
	int GetKeyStateExt(int vk);

	/**
	@brief ���콺 �̵� ��ġ �˾ƿɴϴ�.
	@param 
	@param 
	@param 
	@param 
	@param 
	@return 
	*/	
	stMouseInfo GetMouseMovePos();
	
	/**
	@brief ���콺 ��ġ ����
	@param 
	@param 
	@param 
	@param 
	@param 
	@return ����
	*/		
	void SetMousePos(stMouseInfo stMPos);

	/**
	@brief �� ����ÿ� �������� Ű�������� �ٲ������ ������� �ʵ��� �� �Լ��� ȣ���Ͽ� �ʱ�ȭ�ϴ� ���̴�.
 	@param 
	@param 
	@param 
	@param 
	@param 
	@return ����
	*/		
	void Reset();

	//! �ݹ��Լ� static���� �����߾^^^ �� ���� �� �̾ȿ����� �̱������� ���� �ϼž��ؿ�^^(����)
	static void GLFWCALL MousePosCallBack(int nX, int nY);
	static void GLFWCALL MouseButtonCallBack(int nButton, int nState);
};