#pragma once

class CEMStatic
{
private:
	enum INDEX {SHADOW = 0, STRING};
private:
	stEMVec3			m_vRender;				//!<���������� �׷����� ��ǥ
	stEMVec3			m_vString;				//!< �θ� (CEMWindow)�� ���� ��� ��ǥ ��� ����
	stEMVec3			m_vShadow;				//!< �θ� (CEMWindow)�� ���� ��� ��ǥ �׸���
	stEMVec3			m_vParent;

	CEMColor			m_Color;				//!< ��� ���� ��
	CEMColor			m_ShadowColor;			//!< �׸��� ��

	bool				m_bDisable;				//!< Ȱ��ȭ(false) ��Ȱ��ȭ(true)
	bool				m_bVisible;				//!< render���� (true �׸��� / false �ȱ׸���.)

	float				m_fShadowGap;			//!< ��¹��ڿ��� �׸����� ����

	stEMRect			m_Space;				//!< ��� ����

	float				m_fSize;

	std::vector<CEMText*> m_Table;
	std::vector<CEMText*>::iterator itr;

public:
	UINT				m_id;

public:
	void Render			();													//!< Render

public:
	/**
	@brief static ���¸� ����( Ȱ��ȭ / ��Ȱ��ȭ )
	@param bool ���°�
	@return ����
	*/
	void SetDisable(bool bDisable);
	/**
	@brief static ���������� ���θ� ���� (�������� ���� true / �Ⱥ��̴� ���� false)
	@param bool ���°�
	@return ����
	*/
	void SetVisible(bool bVisible);
	/**
	@brief ��� ���ڿ� ����
	@param ����� ���ڿ�
	@param ���ڿ� ����
	@param �׸��� ����
	@return ����
	*/
	void SetText(const char* cpString, CEMColor& Color = CEMColor(1.f, 1.f, 1.f, 1.f), CEMColor& ShadowColor = CEMColor(0.f, 0.f, 0.f, 1.f));
	/**
	@brief ��� ���ڿ� ����
	@param ����� ���ڿ�
	@param ���ڿ� ����
	@param �׸��� ����
	@return ����
	*/
	void SetText(const stdEMString str, CEMColor& Color = CEMColor(1.f, 1.f, 1.f, 1.f), CEMColor& ShadowColor = CEMColor(0.f, 0.f, 0.f, 1.f));
	/**
	@brief ��� ���� ����
	@param ���ڿ� ����
	@return ����
	*/
	void SetColor(CEMColor& Color = CEMColor(1.f, 1.f, 1.f, 1.f));
	/**
	@brief ��� ���ڿ��� �׸��� ����
	@param �׸��� ����
	@param ��� ���ڿ��� �׸����� ����
	@return ����
	*/
	void SetShadow(CEMColor& Color = CEMColor(0.f, 0.f, 0.f, 1.f), float fGap = 2.0f);
	/**
	@brief ��� ��ǥ ����
	@param ��ǥ��
	@return ����
	*/
	void SetCoordinator(stEMVec3& vPos);
	void SetFormat(DWORD Format = E_TEXT_LEFT);

public:
	CEMStatic(UINT id, const char* cpFontName, const char* cpString, stEMVec3& vPos, stEMVec3& vParent, CEMColor& color, float fSize = 1.f);
	CEMStatic(UINT id, const char* cpFontName, const char* cpString, stEMRect& rt, stEMVec3& vParent, CEMColor& color, DWORD Format = E_TEXT_LEFT, float fSize = 1.f);
	~CEMStatic();

};