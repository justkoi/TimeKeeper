#pragma once


/**
	@file    : EMColor.h
	@author  : wo
	@version : 1.0f
	@brief   : »öÁöÁ¤ 
 */
class CEMColor
{
public:
	float m_fR;	//!< red
	float m_fG; //!< grren
	float m_fB; //!< blue
	float m_fA; //!< alpha

public:
	CEMColor();
	CEMColor(float fR, float fG, float fB, float fA=1.0f, bool bClamp=true);
	CEMColor(int nR, int nG, int nB, int nA=255, bool bClamp=true);

	~CEMColor()
	{

	};

public:
	void Clamp();

public:
	bool operator==(const CEMColor &c) const;
	bool operator!=(const CEMColor &c) const;

	CEMColor operator-(const CEMColor &c) const;
	CEMColor operator+(const CEMColor &c) const;
	CEMColor operator/(float fDivider) const;
	CEMColor operator*(float fScaleFactor) const;
};
