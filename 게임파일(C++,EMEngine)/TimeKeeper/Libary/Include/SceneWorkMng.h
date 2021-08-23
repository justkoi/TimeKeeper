#pragma once

/************************************************************************/
/* 기본 클래스                                                          */
/************************************************************************/
class CSceneWorkMng
{
private:
	int			m_ID;					//!< 아이디
	static int	m_iNextValidID;			//!< 다음아이디값


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