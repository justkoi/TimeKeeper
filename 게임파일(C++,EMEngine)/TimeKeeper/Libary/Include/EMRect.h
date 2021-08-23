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
	@brief rect의 가로 길이를 구한다.
	@param 
	@return rect의 가로 길이
	*/
	float width();

	/**
	@brief rect의 세로 길이를 구한다.
	@param 
	@return rect의 세로 길이
	*/
	float height();

	/**
	@brief rect의 가로 길이의 절반을 구하는 함수
	@param 
	@return rect의 가로 길이의 절반
	*/
	float HalfWidth();

	/**
	@brief rect의 세로 길이의 절반을 구하는 함수
	@param 
	@return rect의 세로 길이의 절반
	*/
	float HalfHeight();
	
	/**
	@brief stEMRect에서 RECT구조체로 리턴
	@param 
	@return RECT값
	*/
	RECT& rect();

	/**
	@brief 충돌 처리 함수 입니다. ( 점 vs 사각형 )
	@param x값
	@param y값
	@return 충돌 : true / false
	*/
	bool isOverlap(int x, int y);

	/**
	@brief 충돌 처리 함수 입니다. ( 점 vs 사각형 )
	@param x값
	@param y값
	@return 충돌 : true / false
	*/
	bool isOverlap(float x, float y);

	/**
	@brief 충돌 처리 함수 입니다. ( 점 vs 사각형 )
	@param stEMVec2
	@return 충돌 : true / false
	*/
	bool isOverlap(const stEMVec2& Vec2);

	/**
	@brief 충돌 처리 함수 입니다. ( 점 vs 사각형 )
	@param stEMVec3
	@return 충돌 : true / false
	*/
	bool isOverlap(const stEMVec3& Vec3);

	/**
	@brief 충돌 처리 함수 입니다. ( 사각형 vs 사각형 )
	@param stEMRect
	@return 충돌 : true / false
	*/
	bool isOverlap(const stEMRect& rt);
};