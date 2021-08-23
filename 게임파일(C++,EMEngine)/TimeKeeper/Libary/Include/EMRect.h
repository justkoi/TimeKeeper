#pragma once

struct stEMRect
{
	float m_fLeft;
	float m_fTop;
	float m_fRight;
	float m_fBottom;
	RECT m_rtRect;

	stEMRect();
	stEMRect(float fLeft, float fTop, float fRight, float fBottom);
	operator RECT*  ();
	//operator CONST			RECT*  () const;

	stEMRect& operator -= (FLOAT fValue);
	stEMRect& operator += (FLOAT fValue);
	stEMRect& operator *= (FLOAT fValue);
	stEMRect& operator /= (FLOAT fValue);
	stEMRect& operator += (stEMVec2& Vec2);
	stEMRect& operator -= (stEMVec2& Vec2);
	stEMRect& operator *= (stEMVec2& Vec2);
	stEMRect& operator /= (stEMVec2& Vec2);
	stEMRect& operator /= (stEMVec3& Vec3);
	stEMRect& operator *= (stEMVec3& Vec3);
	stEMRect& operator += (stEMVec3& Vec3);
	stEMRect& operator -= (stEMVec3& Vec3);
	stEMRect& operator -= (stEMRect& rt);
	stEMRect& operator += (stEMRect& rt);
	stEMRect& operator /= (stEMRect& rt);
	stEMRect& operator *= (stEMRect& rt);

	stEMRect operator + (const stEMVec2& Vec2);
	stEMRect operator - (const stEMVec2& Vec2);
	stEMRect operator / (const stEMVec2& Vec2);
	stEMRect operator * (const stEMVec2& Vec2);
	stEMRect operator + (const stEMVec3& Vec3);
	stEMRect operator - (const stEMVec3& Vec3);
	stEMRect operator / (const stEMVec3& Vec3);
	stEMRect operator * (const stEMVec3& Vec3);
	stEMRect operator + (const stEMRect& rt);
	stEMRect operator - (const stEMRect& rt);
	stEMRect operator / (const stEMRect& rt);
	stEMRect operator *  (const stEMRect& rt);
	stEMRect& operator = (const stEMBoundingBox& BB);
	stEMRect& operator = (const RECT& rt);

	bool operator==(const stEMRect& rt);

public:
	void Clear();
	/**
	@brief rect�� ���� ���̸� ���Ѵ�.
	@param 
	@return rect�� ���� ����
	*/
	float width();

	/**
	@brief rect�� ���� ���̸� ���Ѵ�.
	@param 
	@return rect�� ���� ����
	*/
	float height();

	/**
	@brief rect�� ���� ������ ������ ���ϴ� �Լ�
	@param 
	@return rect�� ���� ������ ����
	*/
	float HalfWidth();

	/**
	@brief rect�� ���� ������ ������ ���ϴ� �Լ�
	@param 
	@return rect�� ���� ������ ����
	*/
	float HalfHeight();
	
	/**
	@brief stEMRect���� RECT����ü�� ����
	@param 
	@return RECT��
	*/
	RECT& rect();

	/**
	@brief �浹 ó�� �Լ� �Դϴ�. ( �� vs �簢�� )
	@param x��
	@param y��
	@return �浹 : true / false
	*/
	bool isOverlap(int x, int y);

	/**
	@brief �浹 ó�� �Լ� �Դϴ�. ( �� vs �簢�� )
	@param x��
	@param y��
	@return �浹 : true / false
	*/
	bool isOverlap(float x, float y);

	/**
	@brief �浹 ó�� �Լ� �Դϴ�. ( �� vs �簢�� )
	@param stEMVec2
	@return �浹 : true / false
	*/
	bool isOverlap(const stEMVec2& Vec2);

	/**
	@brief �浹 ó�� �Լ� �Դϴ�. ( �� vs �簢�� )
	@param stEMVec3
	@return �浹 : true / false
	*/
	bool isOverlap(const stEMVec3& Vec3);

	/**
	@brief �浹 ó�� �Լ� �Դϴ�. ( �簢�� vs �簢�� )
	@param stEMRect
	@return �浹 : true / false
	*/
	bool isOverlap(const stEMRect& rt);
};