#pragma once

#define kEpsilon    1.0e-6f
#define kPI         3.1415926535897932384626433832795f
#define kHalfPI     1.5707963267948966192313216916398f
#define kTwoPI      2.0f*kPI


inline float EMSqrt( float val )        { return sqrtf( val ); }
inline float EMInvSqrt( float val )     { return 1.0f/sqrtf( val ); }
inline float EMAbs( float f )           { return fabsf(f); }


inline bool IsZero( float a ) 
{
	return ( fabsf(a) < kEpsilon );

}   // End of IsZero()


inline bool IvAreEqual( float a, float b ) 
{
	return ( ::IsZero(a-b) );

}   // End of IvAreEqual()

inline void IvSinCos( float a, float& sina, float& cosa )
{
	sina = sinf(a);
	cosa = cosf(a);

}  // End of IvSinCos




/**
	@file    : EMVector.h
	@author  : wo
	@version : 1.0f
	@brief   : 옵셋 위치 저장
 */
struct stEMOffset
{
	float m_fX;		//!< x위치
	float m_fY;		//!< y위치

	stEMOffset(float fX, float fY)
	{
		m_fX = fX;
		m_fY = fY;
	}

	stEMOffset()
	{
		m_fX = 0.0f;
		m_fY = 0.0f;
	};

	bool operator==(const stEMOffset &fValue) const;
	bool operator!=(const stEMOffset &fValue) const;

	
	stEMOffset operator-(const stEMOffset &fValue) const;
	stEMOffset operator+(const stEMOffset &fValue) const;

	stEMOffset& operator+=(const stEMOffset &fValue);
	stEMOffset& operator-=(const stEMOffset &fValue);
	stEMOffset& operator*=(float f);
	stEMOffset& operator/=(float f);
};



/**
	@file    : EMVector.h
	@author  : wo
	@version : 1.0f
	@brief   : int형 Vector2
 */
struct stVec2i
{
	int m_fX, m_fY;
	stVec2i(int fX, int fY) : m_fX(fX), m_fY(fY) {}
	stVec2i() : m_fX(0), m_fY(0) {}
};	

/**
	@file    : EMVector.h
	@author  : wo
	@version : 1.0f
	@brief   : float형 Vector2
 */
struct stEMVec2
{
	float m_fX;
	float m_fY;

	static stEMVec2 m_fVec2Zero;		
	static stEMVec2 m_fVec2One;
	static stEMVec2 m_fVec2UnitX;
	static stEMVec2 m_fVec2UnitY;


	stEMVec2(float fX, float fY)
	{
		m_fX = fX;
		m_fY = fY;
	};

	stEMVec2(float fValue)
	{
		m_fX = m_fY = fValue;
	};

	stEMVec2()
	{
		m_fX = 0.0f;
		m_fY = 0.0f;
	};

	~stEMVec2()
	{
		
	};

	bool operator==(const stEMVec2 &fValue) const;
	bool operator!=(const stEMVec2 &fValue) const;

	stEMVec2 operator-() const;
	stEMVec2 operator-(const stEMVec2 &fValue) const;
	stEMVec2 operator+(const stEMVec2 &fValue) const;
	stEMVec2 operator/(float divider) const;
	stEMVec2 operator*(float scaleFactor) const;

	stEMVec2& operator+=(const stEMVec2 &fValue);
	stEMVec2& operator-=(const stEMVec2 &fValue);
	stEMVec2& operator*=(float f);
	stEMVec2& operator/=(float f);


	/**
	@brief 벡터의 길이

	@param 
	@param 
	@param 
	@param 
	@param 
	@return 길이
	*/
	float	Length();

	/**
	@brief 벡터의 길이
		   내부 적으로 sqrt를 뺀 즉 루트를 뺀 벡터의 길이 입니다.
	@param 
	@param 
	@param 
	@param 
	@param 
	@return 길이
	*/
	float	LengthSquared();


	/**
	@brief 두벡터의 거리

	@param const stEMVec2& fOne : 첫번째 벡터
	@param const stEMVec2& fTwo	: 두번째 벡터
	@param 
	@param 
	@param 
	@return 길이
	*/
	static float	Distance(const stEMVec2& fOne, const stEMVec2& fTwo);


	/**
	@brief 두벡터의 거리(sqrt를 빼고 계산)

	@param const stEMVec2& fOne : 첫번째 벡터
	@param const stEMVec2& fTwo	: 두번째 벡터
	@param 
	@param 
	@param 
	@return 길이
	*/
	static float	DistanceSquared(const stEMVec2& fOne, const stEMVec2& fTwo);

	/**
	@brief 두벡터의 내적

	@param const stEMVec2& fOne : 첫번째 벡터
	@param const stEMVec2& fTwo	: 두번째 벡터
	@param 
	@param 
	@param 
	@return 내적
	*/
	static float	Dot(const stEMVec2& fOne, const stEMVec2& fTwo);

	/**
	@brief 두벡터에서 작은 값 x,y만찾아내어 리턴

	@param const stEMVec2& fOne : 첫번째 벡터
	@param const stEMVec2& fTwo	: 두번째 벡터
	@param 
	@param 
	@param 
	@return stEMVec2 Min값
	*/
	static stEMVec2 Min(const stEMVec2& fOne, const stEMVec2& fTwo);

	/**
	@brief 두벡터에서 큰 값 x,y만찾아내어 리턴

	@param const stEMVec2& fOne : 첫번째 벡터
	@param const stEMVec2& fTwo	: 두번째 벡터
	@param 
	@param 
	@param 
	@return stEMVec2 Max값
	*/
	static stEMVec2 Max(const stEMVec2& fOne, const stEMVec2& fTwo);

	/**
	@brief 단위벡터만들기(정규화)

	@return 없음
	*/
	void Normalize();

	/**
	@brief 단위벡터만들기(정규화)
	@param const stEMVec2& stVec2
	@return 단위벡터
	*/
	static stEMVec2	Normalize(const stEMVec2& stVec2);

	//stEMVec2	Lerp(const stEMVec2& fOne, const stEMVec2& fTwo, float fAmount);

	/**
	@brief 벡터 회전
	@param const stEMVec2& stVec2 : 회전할 벡터
	@param const float fRadians : 회전각도 (라디안으로)
	@return 단위벡터
	*/
	static stEMVec2 Rotate(const stEMVec2& stVec2, const float fRadians);
};


struct stEMVec3
{
	union
	{
		struct
		{
			float m_fX;
			float m_fY;
			float m_fZ;
		};
		float v[3];
	};
	
	static stEMVec3 m_fVec3Zero;
	static stEMVec3 m_fVec3One;
	static stEMVec3 m_fVec3UnitX;
	static stEMVec3 m_fVec3UnitY;
	static stEMVec3 m_fVec3UnitZ;

// 	static stEMVec3 m_fLeftDir;		//왼쪽 방향 x기준
// 	static stEMVec3 m_fRightDir;	//오른족 방향
// 	static stEMVec3 m_fUpDir;		//위쪽 방향 y기준
// 	static stEMVec3 m_fDownDir;		//아래쪽 방향
// 	static stEMVec3 m_fForWardDir;	// 앞쪽 방향 z기준 (나쪽으로 오는거) +
// 	static stEMVec3 m_fBackWardDir; // 뒤쪽 방향		  (모니터뒤쪽으로 가는거) -
	   
	stEMVec3(float fX, float fY, float fZ)
	{
		m_fX = fX;
		m_fY = fY;
		m_fZ = fZ;



	};

	stEMVec3(float fValue)
	{
		m_fX = m_fY = m_fZ = fValue;


	};
	stEMVec3(const stEMVec3& v)
	{
		m_fX = v.m_fX;
		m_fY = v.m_fY;
		m_fZ = v.m_fZ;


	}

	stEMVec3()
	{
		m_fX = 0.0f;
		m_fY = 0.0f;
		m_fZ = 0.0f;

	};

	~stEMVec3()
	{

	};

	bool operator==(const stEMVec3 &fValue) const;
	bool operator!=(const stEMVec3 &fValue) const;


	stEMVec3 operator-() const;
	stEMVec3 operator-(const stEMVec3 &fValue) const;
	stEMVec3 operator+(const stEMVec3 &fValue) const;		// ex) v3 = v1 + v2
	stEMVec3 operator*(const stEMVec3 &fValue) const;

	stEMVec3 operator/(float divider) const;
	stEMVec3 operator*(float scaleFactor) const;

	stEMVec3& operator+=(const stEMVec3 &fValue);
	stEMVec3& operator-=(const stEMVec3 &fValue);
	stEMVec3& operator*=(float f);
	stEMVec3& operator/=(float f);

	float& operator[] (int index)
	{
		return v[index];
	}

// 	float operator* (const stEMVec3& rhs) const
// 	{
// 		return m_fX * rhs.m_fX + m_fY * rhs.m_fY + m_fZ * rhs.m_fZ;
// 	}

	stEMVec3 operator *(stEMVec3 &v);

public:   
	/**
	@brief 벡터의 길이

	@param 
	@param 
	@param 
	@param 
	@param 
	@return 길이
	*/
	float Length();

	/**
	@brief 벡터의 길이
		   내부 적으로 sqrt를 뺀 즉 루트를 뺀 벡터의 길이 입니다.
	@param 
	@param 
	@param 
	@param 
	@param 
	@return 길이
	*/
	float LengthSquared();

	void SetVec3(float fX, float fY, float fZ);


	/**
	@brief 두벡터의 거리

	@param const stEMVec2& fOne : 첫번째 벡터
	@param const stEMVec2& fTwo	: 두번째 벡터
	@param 
	@param 
	@param 
	@return 길이
	*/
    static float Distance(const stEMVec3& fOne, const stEMVec3& fTwo);

	/**
	@brief 두벡터의 거리(sqrt를 빼고 계산)

	@param const stEMVec2& fOne : 첫번째 벡터
	@param const stEMVec2& fTwo	: 두번째 벡터
	@param 
	@param 
	@param 
	@return 길이
	*/
	static float DistanceSquared(const stEMVec3& fOne, const stEMVec3& fTwo);
	
	/**
	@brief 두벡터의 내적

	@param const stEMVec2& fOne : 첫번째 벡터
	@param const stEMVec2& fTwo	: 두번째 벡터
	@param 
	@param 
	@param 
	@return 내적
	*/	
	static float Dot(const stEMVec3& fOne, const stEMVec3& fTwo);

	/**
	@brief 단위벡터만들기(정규화)

	@return 없음
	*/
	void Normalize();
	void Normalize(float fLength);


	/**
	@brief 인자값으로 넘어온 벡터를 현재벡터에 복사한다.

	@param const stEMVec2& fOne : 첫번째 벡터
	@param const stEMVec2& fTwo	: 두번째 벡터
	@param 
	@param 
	@param 
	@return 복사
	*/	
	void Copy(const stEMVec3& stVec3);

	/**
	@brief 내적계산

	@param stEMVec3& stVec3 :  현재 vec와 입력한 stVec3와의 내적계산
	@param 
	@param 
	@param 
	@param 
	@return 내적
	*/	
	float Dot(stEMVec3& stVec3);

	stEMVec3 Cross(stEMVec3& stVec3);


	/**
	@brief 단위벡터 

	@param const stEMVec3& stValueVec3 : 단위벡터 만들놈
	@param 
	@param 
	@param 
	@param 
	@return stEMVec3 단위벡터
	*/	
	static stEMVec3 Normalize(const stEMVec3& stValueVec3);


// 	/**
// 	@brief 두벡터에서 작은 값 x,y,z 만 찾아내 어 리턴
// 
// 	@param const stEMVec3& fOne : 첫번째 벡터
// 	@param const stEMVec3& fTwo	: 두번째 벡터
// 	@param const stEMVec3& fThree	: 세번째 벡터
// 	@param 
// 	@param 
// 	@return stEMVec2 Min값
// 	*/
// 	static stEMVec3 Min(const stEMVec3& fOne, const stEMVec3& fThree);
// 
// 	/**
// 	@brief 두벡터에서 큰 값 x,y,z만찾아내어 리턴
// 
// 	@param const stEMVec3& fOne : 첫번째 벡터
// 	@param const stEMVec3& fTwo	: 두번째 벡터
// 	@param const stEMVec3& fThree	: 세번째 벡터
// 	@param 
// 	@param 
// 	@return stEMVec2 Max값
// 	*/
// 	static stEMVec2 Max(const stEMVec3& fOne, const stEMVec3& fThree);



	//stEMVec2	Lerp(const stEMVec2& fOne, const stEMVec2& fTwo, float fAmount);
};


class stEMvec4
{
public:
    // constructor/destructor
    inline stEMvec4() {}
    inline stEMvec4( float _x, float _y, float _z, float _w ) :
        m_fX(_x), m_fY(_y), m_fZ(_z), m_fW(_w)
    {
    }
    inline ~stEMvec4() {}

    // copy operations
    stEMvec4(const stEMvec4& other);
    stEMvec4& operator=(const stEMvec4& other);


    // accessors
    inline float& operator[]( unsigned int i )         { return (&m_fX)[i]; }
    inline float operator[]( unsigned int i ) const    { return (&m_fY)[i]; }

    float Length() const;
    float LengthSquared() const;

    // comparison
    bool operator==( const stEMvec4& other ) const;
    bool operator!=( const stEMvec4& other ) const;
    bool IsZero() const;
    bool IsUnit() const;

    // manipulators
    inline void Set( float _x, float _y, float _z, float _w );
    void Clean();       // sets near-zero elements to 0
    inline void Zero(); // sets all elements to 0
    void Normalize();   // sets to unit vector

    // operators

    // addition/subtraction
    stEMvec4 operator+( const stEMvec4& other ) const;
    stEMvec4& operator+=( const stEMvec4& other );
    stEMvec4 operator-( const stEMvec4& other ) const;
    stEMvec4& operator-=( const stEMvec4& other );

    // scalar multiplication
    stEMvec4    operator*( float scalar );
    friend stEMvec4    operator*( float scalar, const stEMvec4& vector );
    stEMvec4&          operator*=( float scalar );
    stEMvec4    operator/( float scalar );
    stEMvec4&          operator/=( float scalar );

    // dot product
    float              Dot( const stEMvec4& vector ) const;
    friend float       Dot( const stEMvec4& vector1, const stEMvec4& vector2 );

    // useful defaults
    static stEMvec4    xAxis;
    static stEMvec4    yAxis;
    static stEMvec4    zAxis;
    static stEMvec4    wAxis;
    static stEMvec4    origin;
        
    // member variables
    float m_fX, m_fY, m_fZ, m_fW;

protected:

private:
};

//-------------------------------------------------------------------------------
//-- Inlines --------------------------------------------------------------------
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
// @ stEMvec4::Set()
//-------------------------------------------------------------------------------
// Set vector elements
//-------------------------------------------------------------------------------
inline void 
stEMvec4::Set( float _x, float _y, float _z, float _w )
{
    m_fX = _x; m_fY = _y; m_fZ = _z; m_fW = _w;
}   // End of stEMvec4::Set()

//-------------------------------------------------------------------------------
// @ stEMvec4::Zero()
//-------------------------------------------------------------------------------
// Zero all elements
//-------------------------------------------------------------------------------
inline void 
stEMvec4::Zero()
{
    m_fX = m_fY = m_fZ = m_fW = 0.0f;
}   // End of stEMvec4::Zero()

//-------------------------------------------------------------------------------
//-- Externs --------------------------------------------------------------------
//-------------------------------------------------------------------------------



