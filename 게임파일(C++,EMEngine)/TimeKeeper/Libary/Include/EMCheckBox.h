#pragma once

class CEMCheckBox : public CEMUIEvent
{
private:
	enum CHECKBOXSTATE { RELEASE = 0, HIGHLIGHT, CHECK };
	enum BUTTONSOUND {CLICK = 0, OVER };

private:
	std::vector<CEMPlane*>	m_Plane;				//!< ��ư�� �̹������� ��� ���� vector
	//std::vector<CEMAnimation*>	m_Animate;			//!< ��ư�� �ִϸ��̼ǵ��� ��� ���� vector

	stdEMString				m_sParentName;			//!< ���� ��ư�� window�̸�
	
	stEMVec3				m_vPos;					//!< �θ�(CEMWindow)�� ���Ͽ� ��� ��ǥ
	stEMVec3				m_vParent;				//!< �θ� ��ǥ
	stEMVec3				m_vRender;				//!< ���������� �׷����� ��ǥ
	
	CHECKBOXSTATE			m_eButtonState;			//!< ��ư�� ����
	
	bool					m_bDisable;				//!< Ȱ��ȭ ��Ȱ��ȭ
	bool					m_bVisible;				//!< ȭ��� �׷����� ����
	bool					m_bOvered;				//!< ��ư���� ���콺�� �ִ��� ����
	
	float					m_fWidth;				//!< ��ư�� ���� ����
	float					m_fWidthHalf;			//!< ��ư���� ������ ����
	float					m_fHeight;				//!< ��ư�� ���� ����
	float					m_fHeightHalf;			//!< ��ư���� ������ ����

	stEMRect				m_rtRect;				//!< ��ư�� ũ��
	
	SAMPLE_HANDLE			m_shSound[2];			//!< ��ư ȿ����

	enumRenderType 			m_eRenderType;			//!< �׷��ִ� ���

public:
	UINT					m_id;					//!< üũ�ڽ��� id 

public:
	void Update			(float dt);											//!< Update
	void Render			();													//!< Render
	void MouseDownEvent (stMouseInfo stPos, enumMouseButton eButton);		//!< ���콺 �ٿ� �̺�Ʈ
	void MouseUpEvent	(stMouseInfo stPos, enumMouseButton eButton);		//!< ���콺 �� �̺�Ʈ
	void MouseMoveEvent (stMouseInfo stPos);								//!< ���콺 �̵� �̺�Ʈ

public:
	/**
	@brief �����찡 �����̸� ��ư�� ���� �����̰� �ϴ� �Լ�
	@param stEMVec3& ������ �̵� ��ǥ
	@return ����
	*/
	void SetCoordinator(stEMVec3& vPos);
	/**
	@brief ���� ��ư�� ��ǥ�� �����մϴ�.
	@param stEMVec3& ������ ��ǥ( �θ� ) �����쿡 ���Ͽ� ��� ��ǥ �Դϴ�.
	@return ����
	*/
	void SetPos(stEMVec3& vPos);
	/**
	@brief ���� ��ư�� ��ǥ��� �Ϳ�
	@param bool true(���� �׷�������ǥ)/ false(�θ� ���Ͽ� ��� ��ǥ)
	@return stEMVec3 �Ѱ��� flag���� ���� ���� ���� �޶����ϴ�.
	*/
	stEMVec3 GetPos(bool bFlag = true);
	/**
	@brief ��ư�� ��������� Ŭ�����带 �������ش�.
	@param const char*  Ŭ�������� ���,
	@param const char*  ���������� ���,
	@return ����
	*/
	void SetSound	(const char* cpClick = NULL, const char* cpOver = NULL);
	/**
	@brief ��ư ���¸� ����( Ȱ��ȭ / ��Ȱ��ȭ )
	@param bool ���°�
	@return ����
	*/
	void SetDisable	(bool bDisable);
	/**
	@brief ��ư�� ���������� ���θ� ���� (�������� ���� true / �Ⱥ��̴� ���� false)
	@param bool ���°�
	@return ����
	*/
	void SetVisible	(bool bVisible);
	/**
	@brief üũ�ڽ� ���û��·� ����
	@param bool (���� : true / ���� : false)
	@return ����
	*/
	void SetSelected(bool bSelected);
	/**
	@brief ���� ��ư�� Ȱ��ȭ/ ��Ȱ��ȭ ���¸� ������ �Լ�
	@param 
	@return bool (��Ȱ��ȭ true / Ȱ��ȭ false)
	*/
	bool GetDisable	();
	/**
	@brief ��ư�� render���¸� ������ �Լ�
	@param 
	@return bool (�������� true / �Ⱥ��̸� false)
	*/
	bool GetVisible	();
	/**
	@brief �ش� üũ�ڽ��� ���õǾ��ִ��� ����
	@param 
	@return (���õ� true / ���� �ȵ� false)
	*/
	bool GetSelected();
	/**
	@brief ���콺�� �⵿ ������ �˾� ���� �Լ�
	@param ���콺 x ��
	@param ���콺 y ��
	@return (�浹 true / �� �浹 false)
	*/
	bool Collision	(int x, int y);

protected:
	CEMPlane* Create(const char* cpTexture, stEMVec3& vPos);

public:
	CEMCheckBox(UINT id, const char* cpParent, const char* cpDefault, const char* cpOver, const char* cpCheck, stEMVec3& vPos, stEMVec3& vParent, UIEvent* pUIEvent, bool bCheck = false);
	//CEMCheckBox(UINT id, const char* cpParent, CEMAnimation* pDefault, CEMAnimation* pOver, CEMAnimation* pCheck, stEMVec3& vPos, stEMVec3& vParent, UIEvent* pUIEvent, bool bCheck = false);
	~CEMCheckBox();
};