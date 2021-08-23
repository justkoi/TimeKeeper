#pragma once

#include "EMVector.h"


/**
	@file    : CEMGrid.h
	@author  : wo
	@version : 1.0f
	@brief   : ����� ���� ������ Ŭ���� 
 */
class CEMGrid : public CEMObject
{
private:
	CEMColor	m_LineColor;		//!< ���� Į��
	CEMColor	m_AxisColor;		//!< ��� �� Į��(�⺻ ������)
	float		m_fInterval;		//!< ����

	stEMVec3	m_stMinCoord;		//!< �ּ�
	stEMVec3	m_stMaxCoord;		//!< �ִ�
	bool		m_bDraw;			//!< �׸��� ��� ����
	
public:
	CEMGrid();
	CEMGrid(CEMColor lines, CEMColor axis, float interval, stEMVec3 minCoord, stEMVec3 maxCoord);

	virtual ~CEMGrid()
	{
		
	};
public:
	void SetDrawFlag(bool bFlag);
	bool GetDrawFlag();

public:
	virtual void Update(float dt) {};
	virtual void Render();
};