#pragma once

/************************************************************************/
/* �⺻ Ŭ����                                                          */
/************************************************************************/
class CSceneWorkMng
{
private:
	int			m_ID;					//!< ���̵�
	static int	m_iNextValidID;			//!< �������̵�


public:
	CSceneWorkMng()
	{
		m_ID = 0;
	};

	CSceneWorkMng				(int id)			{ SetID(id); }
	virtual ~CSceneWorkMng		(void)				{ }


	void			SetID		(int val)			{ m_ID = val;  }	
	int				GetID		()					{ return m_ID; }

	virtual void	Update		(float dt) = 0;
	virtual void	Render		() = 0;
};