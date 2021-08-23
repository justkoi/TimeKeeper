#pragma once

/**
	@file    : EMObject.h
	@author  : wo
	@version : 1.0f
	@brief   : �ֻ��� Ŭ�����Դϴ�.
			   CEMPlane, CEMText...���� ��� �޾� ����
 */
class CEMObject
{
	friend class CEMWorld;

protected:
	bool	m_bDeleteMe;	//!< ���������� �ƴ����� �ľ�
	int		m_nLayer;		//!< ������Ʈ�� ���� ���̾��
	bool	m_bShow;		//!< ȭ�鿡 �������� ������ ����
	bool	m_bFrustumShow;	//!< �������� �ø��� �������� ���� �����ϴ� �Լ�

	POINT	m_bCenterPoint;	//!< ������Ʈ ��� ���� ��ǥ ���� ����

public:
	CEMObject()
	{
		m_bCenterPoint.x = 0;
		m_bCenterPoint.y = 0;

		m_bDeleteMe = false;
		m_bShow	= true;
		m_bFrustumShow = true;
	};

	virtual ~CEMObject()
	{
		
	};

	virtual void Update(float dt){};
	virtual void UpdatePhysic(){};
	virtual void Render(){};
	virtual void CalcPos(){};
	virtual void PreDestroy(){};

public:

	/**
	@brief : ���� �ϴ� �Լ��Դϴ�
			 �� �Լ��ȿ��� ���� ���� �޸��Ҵ��� �͵��� Delete���ִ� ���� �ƴ϶�
			 m_bDeleteMe ��� ���� true�� �־��༭, �����޶�� ���� �־��ִ� ���Դϴ�
			 �׷��� ���� ���ο��� IsDestroy()�Լ��� ȣ���Ͽ� true�� �������ο��� delete ���ݴϴ�

	@return : ����
	*/
	void Destroy()
	{
		if(IsDestroy())
			return;

		PreDestroy();

		m_bDeleteMe = true;
	}


	/**
	@brief : ���� �ϴ� �Լ��Դϴ�
			 �� �Լ��ȿ��� ���� ���� �޸��Ҵ��� �͵��� Delete���ִ� ���� �ƴ϶�
			 m_bDeleteMe ��� ���� true�� �־��༭, �����޶�� ���� �־��ִ� ���Դϴ�
			 �׷��� ���� ���ο��� IsDestroy()�Լ��� ȣ���Ͽ� true�� �������ο��� delete ���ݴϴ�.

	@return : true/false   
	*/
	bool IsDestroy()	{return m_bDeleteMe;}

	/**
	@brief : ���̾� ��ȣ ���
	@param : 
	@return : ���̾� ��ȣ
	*/	
	int GetLayer()		{return m_nLayer;}

	/**
	@brief : ���̾� ��ȣ �ֱ�
	@param int nLayer : ���̾�
	@return ����
	*/	
	void SetLayer(int nLayer) {m_nLayer = nLayer;}

	/**
	@brief �������� ������ ����
	@param bool bShow : true�� ȭ�鿡 ����մϴ�.
	@return ����
	*/	
	void SetShow(bool bShow)		{m_bShow = bShow;}

	/**
	@brief �������� ������ ����(�������� �ø���)
	@param bool bShow : true�� ȭ�鿡 ����մϴ�.
	@return ����
	*/	
 	void SetFrustumShow(bool bFShow)		{m_bFrustumShow = bFShow;}
 	bool GetFrustumShow()					{return m_bFrustumShow;}
// 	

	/**
	@brief ���� Show ���¸� ���´�.
	@return 
	*/	
	bool GetShow()					{return m_bShow;}



};