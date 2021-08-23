#pragma once



// class CEMMatrix4 
// {
// public:
// 	union 
// 	{	
// 		float m_fTm[16];
// 
// 		struct 
// 		{
// 			float m_0,  m_1,  m_2,  m_3;			//!< 12, 13, 14가 x ,y, z가 되겠습니다.
// 			float m_4,  m_5,  m_6,  m_7;
// 			float m_8,  m_9,  m_10, m_11;
// 			float m_12, m_13, m_14, m_15;
// 		};
// 	};
// 
// public:
// 	CEMMatrix4()
// 	{
// 		ZeroMemory(m_fTm, sizeof(m_fTm));
// 		Identity();
// 	};
// 	~CEMMatrix4(){};
// 
// public:
// 	CEMMatrix4 operator=(CEMMatrix4& tm) const;
// 	CEMMatrix4 operator*(CEMMatrix4& tm) const;
// 	stEMVec3 operator*(stEMVec3& vec) const;
// 
// 
// public:
// 	float* GetTm()			{return m_fTm;}		
// 	void Identity();							//!< 단위 핼렬로 만들기
// };


class CEMMatrix4x4
{
public:
	// constructor/destructor
	inline CEMMatrix4x4() { Identity(); }
	inline ~CEMMatrix4x4() {}


	// copy operations
	CEMMatrix4x4(const CEMMatrix4x4& other);
	CEMMatrix4x4& operator=(const CEMMatrix4x4& other);

	// text output (for debugging)
	

	// accessors
	float &operator()(unsigned int i, unsigned int j);
	float operator()(unsigned int i, unsigned int j) const;

	// comparison
	bool operator==( const CEMMatrix4x4& other ) const;
	bool operator!=( const CEMMatrix4x4& other ) const;
	bool IsZero() const;
	bool IsIdentity() const;

	// manipulators
	void SetRows( const stEMvec4& row1, const stEMvec4& row2, 
		const stEMvec4& row3, const stEMvec4& row4 ); 
	void GetRows( stEMvec4& row1, stEMvec4& row2, stEMvec4& row3, stEMvec4& row4 ); 

	void SetColumns( const stEMvec4& col1, const stEMvec4& col2, 
		const stEMvec4& col3, const stEMvec4& col4 ); 
	void GetColumns( stEMvec4& col1, stEMvec4& col2, stEMvec4& col3, stEMvec4& col4 ); 

	void Clean();
	void Identity();

	CEMMatrix4x4& AffineInverse();
	friend CEMMatrix4x4 AffineInverse( const CEMMatrix4x4& mat );

	CEMMatrix4x4& Transpose();
	friend CEMMatrix4x4 Transpose( const CEMMatrix4x4& mat );

	// transformations
	CEMMatrix4x4& Translation( const stEMVec3& xlate );
	CEMMatrix4x4& Rotation( const CEMMatrix3x3& matrix );
	//CEMMatrix4x4& Rotation( const IvQuat& rotate );
	CEMMatrix4x4& Rotation( float zRotation, float yRotation, float xRotation );
	CEMMatrix4x4& Rotation( const stEMVec3& axis, float angle );

	CEMMatrix4x4& Scaling( const stEMVec3& scale );

	CEMMatrix4x4& RotationX( float angle );
	CEMMatrix4x4& RotationY( float angle );
	CEMMatrix4x4& RotationZ( float angle );

	void GetFixedAngles( float& zRotation, float& yRotation, float& xRotation );
	void GetAxisAngle( stEMVec3& axis, float& angle );

	// operators

	// addition and subtraction
	CEMMatrix4x4 operator+( const CEMMatrix4x4& other ) const;
	CEMMatrix4x4& operator+=( const CEMMatrix4x4& other );
	CEMMatrix4x4 operator-( const CEMMatrix4x4& other ) const;
	CEMMatrix4x4& operator-=( const CEMMatrix4x4& other );

	CEMMatrix4x4 operator-() const;

	// multiplication
	CEMMatrix4x4& operator*=( const CEMMatrix4x4& matrix );
	CEMMatrix4x4 operator*( const CEMMatrix4x4& matrix ) const;

	// column vector multiplier
	stEMvec4 operator*( const stEMvec4& vector ) const;
	stEMVec3 operator*( const stEMVec3& vector ) const;
	// row vector multiplier
	friend stEMvec4 operator*( const stEMvec4& vector, const CEMMatrix4x4& matrix );

	// scalar multiplication
	CEMMatrix4x4& operator*=( float scalar );
	friend CEMMatrix4x4 operator*( float scalar, const CEMMatrix4x4& matrix );
	CEMMatrix4x4 operator*( float scalar ) const;

	// vector3 ops
	stEMVec3 Transform( const stEMVec3& point ) const;

	// point ops
	stEMVec3 TransformPoint( const stEMVec3& point ) const;

	// low-level data accessors - implementation-dependent
	operator float*() { return mV; }
	operator const float*() const { return mV; }

	// member variables
	float mV[16];

protected:

private:
};

//-------------------------------------------------------------------------------
//-- Inlines --------------------------------------------------------------------
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
// @ CEMMatrix4x4::operator()()
//-------------------------------------------------------------------------------
// 2D array accessor
//-------------------------------------------------------------------------------
inline float&
CEMMatrix4x4::operator()(unsigned int i, unsigned int j)
{
	return mV[i + 4*j];

}   // End of CEMMatrix4x4::operator()()

//-------------------------------------------------------------------------------
// @ CEMMatrix4x4::operator()()
//-------------------------------------------------------------------------------
// 2D array accessor
//-------------------------------------------------------------------------------
inline float
CEMMatrix4x4::operator()(unsigned int i, unsigned int j) const
{
	return mV[i + 4*j];

}   // End of CEMMatrix4x4::operator()()

//-------------------------------------------------------------------------------
//-- Externs --------------------------------------------------------------------
//-------------------------------------------------------------------------------


