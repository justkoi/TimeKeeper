#pragma once

class CEMMatrix3x3
{
public:
    // constructor/destructor
    inline CEMMatrix3x3() {}
    inline ~CEMMatrix3x3() {}

    
    // copy operations
    CEMMatrix3x3(const CEMMatrix3x3& other);
    CEMMatrix3x3& operator=(const CEMMatrix3x3& other);


    // accessors
    inline float& operator()(unsigned int i, unsigned int j);
    inline float operator()(unsigned int i, unsigned int j) const;

    // comparison
    bool operator==( const CEMMatrix3x3& other ) const;
    bool operator!=( const CEMMatrix3x3& other ) const;
    bool IsZero() const;
    bool IsIdentity() const;

    // manipulators
    void SetRows( const stEMVec3& row1, const stEMVec3& row2, const stEMVec3& row3 ); 
    void GetRows( stEMVec3& row1, stEMVec3& row2, stEMVec3& row3 ) const; 
    stEMVec3 GetRow( unsigned int i ) const; 

    void SetColumns( const stEMVec3& col1, const stEMVec3& col2, const stEMVec3& col3 ); 
    void GetColumns( stEMVec3& col1, stEMVec3& col2, stEMVec3& col3 ) const; 
    stEMVec3 GetColumn( unsigned int i ) const; 

    void Clean();
    void Identity();

    CEMMatrix3x3& Inverse();
    friend CEMMatrix3x3 Inverse( const CEMMatrix3x3& mat );

    CEMMatrix3x3& Transpose();
    friend CEMMatrix3x3 Transpose( const CEMMatrix3x3& mat );

    // useful computations
    CEMMatrix3x3 Adjoint() const;
    float Determinant() const;
    float Trace() const;
        
    // transformations
    /*CEMMatrix3x3& Rotation( const IvQuat& rotate );*/
    CEMMatrix3x3& Rotation( float zRotation, float yRotation, float xRotation );
    CEMMatrix3x3& Rotation( const stEMVec3& axis, float angle );
	  
    CEMMatrix3x3& Scaling( const stEMVec3& scale );

    CEMMatrix3x3& RotationX( float angle );
    CEMMatrix3x3& RotationY( float angle );
    CEMMatrix3x3& RotationZ( float angle );

    void GetFixedAngles( float& zRotation, float& yRotation, float& xRotation );
    void GetAxisAngle( stEMVec3& axis, float& angle );

    // operators

    // addition and subtraction
    CEMMatrix3x3 operator+( const CEMMatrix3x3& other ) const;
    CEMMatrix3x3& operator+=( const CEMMatrix3x3& other );
    CEMMatrix3x3 operator-( const CEMMatrix3x3& other ) const;
    CEMMatrix3x3& operator-=( const CEMMatrix3x3& other );

    CEMMatrix3x3 operator-() const;

    // multiplication
    CEMMatrix3x3& operator*=( const CEMMatrix3x3& matrix );
    CEMMatrix3x3 operator*( const CEMMatrix3x3& matrix ) const;

    // column vector multiplier
    stEMVec3 operator*( const stEMVec3& vector ) const;
    // row vector multiplier
    friend stEMVec3 operator*( const stEMVec3& vector, const CEMMatrix3x3& matrix );

    CEMMatrix3x3& operator*=( float scalar );
    friend CEMMatrix3x3 operator*( float scalar, const CEMMatrix3x3& matrix );
    CEMMatrix3x3 operator*( float scalar ) const;

    // low-level data accessors - implementation-dependent
    operator float*() { return mV; }
    operator const float*() const { return mV; }

    // member variables
    float mV[9];

protected:

private:
};

//-------------------------------------------------------------------------------
//-- Inlines --------------------------------------------------------------------
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
// @ CEMMatrix3x3::operator()()
//-------------------------------------------------------------------------------
// 2D array accessor
//-------------------------------------------------------------------------------
inline float&
CEMMatrix3x3::operator()(unsigned int i, unsigned int j)
{
   return mV[i + 3*j];

}   // End of CEMMatrix3x3::operator()()

//-------------------------------------------------------------------------------
// @ CEMMatrix3x3::operator()()
//-------------------------------------------------------------------------------
// 2D array accessor
//-------------------------------------------------------------------------------
inline float
CEMMatrix3x3::operator()(unsigned int i, unsigned int j) const
{
   return mV[i + 3*j];

}   // End of CEMMatrix3x3::operator()()

//-------------------------------------------------------------------------------
//-- Externs --------------------------------------------------------------------
//-------------------------------------------------------------------------------
