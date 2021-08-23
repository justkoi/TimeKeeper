#pragma once

enum ContainmentType
{
	Disjoint,
	Within,
	Intersects
};

/**
	@file    : EMBBox.h
	@author  : wo
	@version : 1.0f
	@brief   : Ray클래스 (충돌처리할 직선)	   
 */
class CEMRay 
{
public:
	stEMVec3 m_stOrigin;
	stEMVec3 m_stDir;
	stEMVec3 m_stInvDir;
	int m_nSign[3];

public:
	CEMRay() {}
	CEMRay(stEMVec3 stOrigin, stEMVec3 stDir) ;
	CEMRay(const CEMRay &Ray);
};


/**
	@file    : EMBBox.h
	@author  : wo
	@version : 1.0f
	@brief   : Box클래스 
			   충돌처리 할때사용되는 박스 클래스 입니다			   
 */
class CEMBBox3
{
private:
	// corners
	stEMVec3 parameters[2];

public:
	CEMBBox3(const stEMVec3& min, const stEMVec3& max)
	{
		parameters[0] = min;
		parameters[1] = max;
	}

	~CEMBBox3(){};

public:
	// (t0, t1) is the interval for valid hits
	//bool Intersect(const Ray &, float t0, float t1) const;
	bool Intersect(const CEMRay&) const;
};

struct Ray2
{
	stEMVec2 Position;
	stEMVec2 Direction;
	Ray2(const stEMVec2& _position, const stEMVec2& _direction)
		: Position(_position)
		, Direction(_direction)
	{}

	Ray2() {}

	static Ray2 CreateRayFromTo( const stEMVec2& vFrom, const stEMVec2& vTo )
	{
		return Ray2(vFrom, stEMVec2::Normalize( vTo - vFrom ));
	}
};

bool operator ==(const Ray2& a, const Ray2& b);
bool operator !=(const Ray2& a, const Ray2& b);

/**
	@file    : EMBBox.h
	@author  : wo
	@version : 1.0f
	@brief   : Box클래스 
			   충돌처리 할때사용되는 박스 클래스 입니다			   
 */
class CEMBBox
{
public:
	stEMVec2 m_vMin;		//!< 사각형의 최소값 
	stEMVec2 m_vMax;		//!< 사각형의 최대값


public:
	CEMBBox(const stEMVec2& min, const stEMVec2& max);

	CEMBBox() {};
	~CEMBBox(){};



public:

	/**
	@brief 중심 구하기
		   이함수는 중심을 구한후 m_vMin 을 더해줍니다.
	@param 
	@param 
	@param 
	@return stEMVec2 
	*/
	stEMVec2 Centroid() const;

	/**
	@brief m_vMin 과 m_vMax 의 중심을 구하는 함수
	
	@param 
	@param 
	@param 
	@return stEMVec2 
	*/
	stEMVec2 HalfLength() const;


	/**
	@brief 2개의 박스를 합치는 함수

	@param const CEMBBox& original : 원본
	@param const CEMBBox& additional : 원본에 합칠 박스
	@param 	
	@return 교차/안교차
	*/
	static CEMBBox CreateMerged(const CEMBBox& original, const CEMBBox& additional);
	void GetCorners(stEMVec2 corners[]) const;
	static CEMBBox CreateFromPoints(stEMVec2 points[], int count);

	/**
	@brief 교차 판정

	@param 	CEMBBox& box : 교차할 박스
	@param 	
	@param 	
	@return 교차/안교차
	*/
	bool Intersects(const CEMBBox& box) const;
	bool Intersects(const stEMVec2& point, float radius) const;
	bool Intersect(const Ray2& ray, float& distanceAlongRay) const;

	ContainmentType Contains(const CEMBBox& box) const;
	bool Contains(const stEMVec2& point) const;

	/**
	@brief 박스 아웃 라인 그려주는 함수

	@param
	@param 	
	@param 	
	@return 없음
	*/
	void RenderOutline() const;

	/**
	@brief 박스 랜더링 해주는 함수

	@param
	@param 	
	@param 	
	@return 없음
	*/
	void RenderBox() const;
};

bool operator ==(const CEMBBox& a, const CEMBBox& b);
bool operator !=(const CEMBBox& a, const CEMBBox& b);
