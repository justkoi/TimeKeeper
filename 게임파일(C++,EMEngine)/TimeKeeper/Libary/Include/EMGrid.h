#pragma once

#include "EMVector.h"


/**
	@file    : CEMGrid.h
	@author  : wo
	@version : 1.0f
	@brief   : 월드상에 격자 랜더링 클래스 
 */
class CEMGrid : public CEMObject
{
private:
	CEMColor	m_LineColor;		//!< 라인 칼라
	CEMColor	m_AxisColor;		//!< 가운데 축 칼라(기본 빨간색)
	float		m_fInterval;		//!< 간격

	stEMVec3	m_stMinCoord;		//!< 최소
	stEMVec3	m_stMaxCoord;		//!< 최대
	bool		m_bDraw;			//!< 그리드 출력 유무
	
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