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
	@brief   : RayŬ���� (�浹ó���� ����)	   
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
	@brief   : BoxŬ���� 
			   �浹ó�� �Ҷ����Ǵ� �ڽ� Ŭ���� �Դϴ�			   
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
	@brief   : BoxŬ���� 
			   �浹ó�� �Ҷ����Ǵ� �ڽ� Ŭ���� �Դϴ�			   
 */
class CEMBBox
{
public:
	stEMVec2 m_vMin;		//!< �簢���� �ּҰ� 
	stEMVec2 m_vMax;		//!< �簢���� �ִ밪


public:
	CEMBBox(const stEMVec2& min, const stEMVec2& max);

	CEMBBox() {};
	~CEMBBox(){};



public:

	/**
	@brief �߽� ���ϱ�
		   ���Լ��� �߽��� ������ m_vMin �� �����ݴϴ�.
	@param 
	@param 
	@param 
	@return stEMVec2 
	*/
	stEMVec2 Centroid() const;

	/**
	@brief m_vMin �� m_vMax �� �߽��� ���ϴ� �Լ�
	
	@param 
	@param 
	@param 
	@return stEMVec2 
	*/
	stEMVec2 HalfLength() const;


	/**
	@brief 2���� �ڽ��� ��ġ�� �Լ�

	@param const CEMBBox& original : ����
	@param const CEMBBox& additional : ������ ��ĥ �ڽ�
	@param 	
	@return ����/�ȱ���
	*/
	static CEMBBox CreateMerged(const CEMBBox& original, const CEMBBox& additional);
	void GetCorners(stEMVec2 corners[]) const;
	static CEMBBox CreateFromPoints(stEMVec2 points[], int count);

	/**
	@brief ���� ����

	@param 	CEMBBox& box : ������ �ڽ�
	@param 	
	@param 	
	@return ����/�ȱ���
	*/
	bool Intersects(const CEMBBox& box) const;
	bool Intersects(const stEMVec2& point, float radius) const;
	bool Intersect(const Ray2& ray, float& distanceAlongRay) const;

	ContainmentType Contains(const CEMBBox& box) const;
	bool Contains(const stEMVec2& point) const;

	/**
	@brief �ڽ� �ƿ� ���� �׷��ִ� �Լ�

	@param
	@param 	
	@param 	
	@return ����
	*/
	void RenderOutline() const;

	/**
	@brief �ڽ� ������ ���ִ� �Լ�

	@param
	@param 	
	@param 	
	@return ����
	*/
	void RenderBox() const;
};

bool operator ==(const CEMBBox& a, const CEMBBox& b);
bool operator !=(const CEMBBox& a, const CEMBBox& b);
