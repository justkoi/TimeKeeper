#ifndef			CEMQuaternion_H_INCLUDED
#define			CEMQuaternion_H_INCLUDED

#ifdef			_MSC_VER
#if				_MSC_VER > 1000
#pragma once
#endif 
#endif 

#include		"EMVec3.h"

class			CEMAxisAngle			;
class			CEMEulerAngles		;
class			CEMSphericalRotation	;
class			CEMMat3x3			;
class			CEMMat4x4			;

//*************************************************************************************************
//*************************************************************************************************
//*************************************************************************************************

//*****************************************************************************
//	CEMQuaternion
//*****************************************************************************
//
//!	Representation of a quaternion
//
//*****************************************************************************
class CEMQuaternion 
{

protected:

	// Attribs

	float m_fX;	//!< Quaternion's x coordinate
	float m_fY;	//!< Quaternion's y coordinate
	float m_fZ;	//!< Quaternion's z coordinate
	float m_fW;	//!< Quaternion's w coordinate
																																									
public:

	// Con-/Destruction

			 CEMQuaternion( float a_fX, float a_fY, float a_fZ, float a_fW );
	explicit CEMQuaternion( const CEMMat4x4&			a_matRotation	);																					
	explicit CEMQuaternion( const CEMMat3x3&			a_matRotation	);																					
	explicit CEMQuaternion( const CEMAxisAngle&			a_Rotation		);																					
	explicit CEMQuaternion( const CEMEulerAngles&		a_Rotation		);																					
	explicit CEMQuaternion( const CEMSphericalRotation&	a_Rotation		);																					
			 CEMQuaternion( const CEMQuaternion&		a_quatRotation	);																					
			 CEMQuaternion();																																
			~CEMQuaternion();																																

	// Get/Set

			float&				AccessX				( void )																							;
			float&				AccessY				( void )																							;
			float&				AccessZ				( void )																							;
			float&				AccessW				( void )																							;
																																				
			float				GetX				( void )																					const	;
			float				GetY				( void )																					const	;
			float				GetZ				( void )																					const	;
			float				GetW				( void )																					const	;
																																				
			void				GetX				(		float&				a_fX			)												const	;
			void				GetY				(		float&				a_fY			)												const	;
			void				GetZ				(		float&				a_fZ			)												const	;
			void				GetW				(		float&				a_fW			)												const	;
																																			
			void				SetX				(		float				a_fX			)														;
			void				SetY				(		float				a_fY			)														;
			void				SetZ				(		float				a_fZ			)														;
			void				SetW				(		float				a_fW			)														;

			void				SetQuaternion		(		float				a_fX																	
													,		float				a_fY																	
													,		float				a_fZ																	
													,		float				a_fW			)														;
			void				SetQuaternion		( const	CEMVec3&			a_vecAxisSrc
													, const	CEMVec3&			a_vecAxisDst	)														;													
			void				SetQuaternion		( const CEMMat4x4&			a_matRotation	)														;
			void				SetQuaternion		( const CEMMat3x3&			a_matRotation	)														;
			void				SetQuaternion		( const CEMAxisAngle&			a_Rotation		)														;
			void				SetQuaternion		( const CEMEulerAngles&		a_Rotation		)														;
			void				SetQuaternion		( const CEMSphericalRotation&	a_Rotation		)														;
			void				SetQuaternion		( const CEMQuaternion&		a_quatRotation	)														;

	// Modification

			void				Clear				( void );																							
			void				Invert				( void );																							
			void				Negate				( void );																							
			void				Normalize			( void );																							
																																						
			void				Add					( const CEMQuaternion&		a_quat			)														;
			void				Sub					( const CEMQuaternion&		a_quat			)														;
			void				Multiply			(		float				a_fFactor		)														;
			void				Multiply			( const CEMQuaternion&		a_quatFactor	)														;
			void				ReverseMultiply		( const CEMQuaternion&		a_quatPrefix	)														;
			void				RotateAxisX			(		float				a_fAngle		)														;
			void				RotateAxisY			(		float				a_fAngle		)														;
			void				RotateAxisZ			(		float				a_fAngle		)														;
			void				RotateLocalAxisX	(		float				a_fAngle		)														;
			void				RotateLocalAxisY	(		float				a_fAngle		)														;
			void				RotateLocalAxisZ	(		float				a_fAngle		)														;

			void				SetToProduct		( const	CEMQuaternion&		a_quatLeft		
													, const	CEMQuaternion&		a_quatRight	)															;
			void				SetLerp				(		CEMQuaternion			a_quatSource
													, const	CEMQuaternion&		a_quatTarget
													,		float				a_fAlpha		)														;
			void				SetSlerp			(		CEMQuaternion			a_quatSource
													,		CEMQuaternion			a_quatTarget
													,		float				a_fAlpha		)														;

	// Computations

			bool				IsEqual				( const CEMQuaternion&		a_quatFactor	)												const	;

			float				GetMagnitude		( void )																					const	;
			float				GetSquareMagnitude	( void )																					const	;
			float				GetDotProduct		( const CEMQuaternion&		a_quatFactor	)												const	;
																																				
			CEMMat4x4			GetMatrix			( void )																					const	;
			CEMMat3x3			GetMatrix3			( void )																					const	;
			CEMAxisAngle			GetAxisAngle		( void )																					const	;
			CEMEulerAngles		GetEulerAngles		( void )																					const	;
			CEMSphericalRotation	GetSphericalRotation( void )																					const	;
																																					
			CEMQuaternion			GetInverted			( void	)																					const	;
			CEMQuaternion			GetNegated			( void	)																					const	;
			CEMQuaternion			GetNormalized		( void	)																					const	;
			CEMQuaternion			GetSum				( const CEMQuaternion&		a_quat			)												const	;
			CEMQuaternion			GetDifference		( const CEMQuaternion&		a_quat			)												const	;
			CEMQuaternion			GetProduct			(		float				a_fFactor		)												const	;
			CEMQuaternion			GetProduct			( const CEMQuaternion&		a_quatFactor	)												const	;
			CEMQuaternion			GetReverseProduct	( const CEMQuaternion&		a_quatPrefix	)												const	;
			CEMQuaternion			GetRotatedAxisX		(		float				a_fAngle		)												const	;
			CEMQuaternion			GetRotatedAxisY		(		float				a_fAngle		)												const	;
			CEMQuaternion			GetRotatedAxisZ		(		float				a_fAngle		)												const	;
			CEMQuaternion			GetRotatedLocalAxisX(		float				a_fAngle		)												const	;
			CEMQuaternion			GetRotatedLocalAxisY(		float				a_fAngle		)												const	;
			CEMQuaternion			GetRotatedLocalAxisZ(		float				a_fAngle		)												const	;
			CEMQuaternion			GetLerp				( const CEMQuaternion&		a_quatTarget	
													,		float				a_fAlpha		)												const	;
			CEMQuaternion			GetSlerp			( const	CEMQuaternion&		a_quatTarget
													,		float				a_fAlpha		)												const	;
			CEMVec3			GetTransformedVector( const	CEMVec3&			a_vecVector		)												const	;
																																				
			void				GetMatrix			(		CEMMat4x4&			a_matRotation	)												const	;
			void				GetMatrix3			(		CEMMat3x3&			a_matRotation	)												const	;
			void				GetAxisAngle		(		CEMAxisAngle&			a_Rotation		)												const	;
			void				GetEulerAngles		(		CEMEulerAngles&		a_Rotation		)												const	;
			void				GetSphericalRotation(		CEMSphericalRotation&	a_Rotation		)												const	;
																																			
			void				GetInverted			(		CEMQuaternion&		a_quatInverted		)											const	;
			void				GetNegated			(		CEMQuaternion&		a_quatNegated		)											const	;
			void				GetNormalized		(		CEMQuaternion&		a_quatNormalized	)											const	;
			void				GetSum				(		CEMQuaternion&		a_quatProduct		, const	CEMQuaternion&	a_quatFactor	)	const	;
			void				GetDifference		(		CEMQuaternion&		a_quatProduct		, const	CEMQuaternion&	a_quatFactor	)	const	;
			void				GetProduct			(		CEMQuaternion&		a_quatProduct		,		float			a_fFactor		)	const	;
			void				GetProduct			(		CEMQuaternion&		a_quatProduct		, const	CEMQuaternion&	a_quatFactor	)	const	;
			void				GetReverseProduct	(		CEMQuaternion&		a_quatReverseProduct, const	CEMQuaternion&	a_quatPrefix	)	const	;
			void				GetRotatedAxisX		(		CEMQuaternion&		a_quatRotated		, 		float			a_fAngle		)	const	;
			void				GetRotatedAxisY		(		CEMQuaternion&		a_quatRotated		, 		float			a_fAngle		)	const	;
			void				GetRotatedAxisZ		(		CEMQuaternion&		a_quatRotated		,		float			a_fAngle		)	const	;
			void				GetRotatedLocalAxisX(		CEMQuaternion&		a_quatRotated		,		float			a_fAngle		)	const	;
			void				GetRotatedLocalAxisY(		CEMQuaternion&		a_quatRotated		,		float			a_fAngle		)	const	;
			void				GetRotatedLocalAxisZ(		CEMQuaternion&		a_quatRotated		,		float			a_fAngle		)	const	;

	// Operators

			bool				operator ==			( const CEMQuaternion&		a_quatOther		)												const	;
			bool				operator !=			( const CEMQuaternion&		a_quatOther		)												const	;

			CEMQuaternion&		operator =			( const CEMMat4x4&			a_matRotation	)														;
			CEMQuaternion&		operator =			( const CEMMat3x3&			a_matRotation	)														;
			CEMQuaternion&		operator =			( const CEMAxisAngle&			a_Rotation		)														;
			CEMQuaternion&		operator =			( const CEMEulerAngles&		a_Rotation		)														;
			CEMQuaternion&		operator =			( const CEMSphericalRotation&	a_Rotation		)														;

			CEMQuaternion&		operator *=			(		float				a_fFactor		)														;
			CEMQuaternion&		operator /=			(		float				a_fFactor		)														;
			CEMQuaternion&		operator *=			( const CEMQuaternion&		a_quatRotation	)														;
			CEMQuaternion&		operator +=			( const CEMQuaternion&		a_quatRotation	)														;
			CEMQuaternion&		operator -=			( const CEMQuaternion&		a_quatRotation	)														;

			CEMQuaternion			operator  ~			( void )																					const	;
			CEMQuaternion			operator  -			( void )																					const	;

			CEMQuaternion			operator  *			(		float				a_fFactor		)												const	;
			CEMQuaternion			operator  /			(		float				a_fFactor		)												const	;
			CEMQuaternion			operator  +			( const CEMQuaternion&		a_quatRotation	)												const	;
			CEMQuaternion			operator  -			( const CEMQuaternion&		a_quatRotation	)												const	;
			CEMQuaternion			operator  *			( const CEMQuaternion&		a_quatRotation	)												const	;
	friend	CEMQuaternion			operator  *			(		float				a_fFactor
													, const CEMQuaternion&		a_quatSource	)														;
																																																					
};

//*************************************************************************************************
//*************************************************************************************************
//*************************************************************************************************

//*****************************************************************************
//	AccessX
//*****************************************************************************
//
//! \brief		Returns the quaternion's x coordinate for modification purposes
//! \return		The quaternion's x coordinate
//
//*****************************************************************************
inline float& CEMQuaternion::AccessX( void )
{
	return m_fX;
}

//*****************************************************************************
//	AccessY
//*****************************************************************************
//
//! \brief		Returns the quaternion's y coordinate for modification purposes
//! \return		The quaternion's y coordinate
//
//*****************************************************************************
inline float& CEMQuaternion::AccessY( void )
{
	return m_fY;
}

//*****************************************************************************
//	AccessZ
//*****************************************************************************
//
//! \brief		Returns the quaternion's z coordinate for modification purposes
//! \return		The quaternion's z coordinate
//
//*****************************************************************************
inline float& CEMQuaternion::AccessZ( void )
{
	return m_fZ;
}

//*****************************************************************************
//	AccessW
//*****************************************************************************
//
//! \brief		Returns the quaternion's w coordinate for modification purposes
//! \return		The quaternion's w coordinate
//
//*****************************************************************************
inline float& CEMQuaternion::AccessW( void )
{
	return m_fW;
}

//*****************************************************************************
//	GetX
//*****************************************************************************
//
//! \brief		Returns the quaternion's x coordinate for look-up purposes
//! \return		The quaternion's x coordinate
//
//*****************************************************************************
inline float CEMQuaternion::GetX( void ) const			
{
	return m_fX;
}

//*****************************************************************************
//	GetY
//*****************************************************************************
//
//! \brief		Returns the quaternion's y coordinate for look-up purposes
//! \return		The quaternion's y coordinate
//
//*****************************************************************************
inline float CEMQuaternion::GetY( void ) const			
{
	return m_fY;
}

//*****************************************************************************
//	GetZ
//*****************************************************************************
//
//! \brief		Returns the quaternion's z coordinate for look-up purposes
//! \return		The quaternion's z coordinate
//
//*****************************************************************************
inline float CEMQuaternion::GetZ( void ) const			
{
	return m_fZ;
}

//*****************************************************************************
//	GetW
//*****************************************************************************
//
//! \brief		Returns the quaternion's w coordinate for look-up purposes
//! \return		The quaternion's w coordinate
//
//*****************************************************************************
inline float CEMQuaternion::GetW( void ) const			
{
	return m_fW;
}

//*****************************************************************************
//	GetX
//*****************************************************************************
//
//! \brief		Retrieves the quaternion's x coordinate
//! \param		[out] The quaternion's x coordinate
//
//*****************************************************************************
inline void CEMQuaternion::GetX( float& a_fX ) const
{
	a_fX = m_fX;
}

//*****************************************************************************
//	GetY
//*****************************************************************************
//
//! \brief		Retrieves the quaternion's y coordinate
//! \param		[out] The quaternion's y coordinate
//
//*****************************************************************************
inline void CEMQuaternion::GetY( float& a_fY ) const
{
	a_fY = m_fY;
}

//*****************************************************************************
//	GetZ
//*****************************************************************************
//
//! \brief		Retrieves the quaternion's z coordinate
//! \param		[out] The quaternion's z coordinate
//
//*****************************************************************************
inline void CEMQuaternion::GetZ( float& a_fZ ) const
{
	a_fZ = m_fZ;
}

//*****************************************************************************
//	GetW
//*****************************************************************************
//
//! \brief		Retrieves the quaternion's w coordinate
//! \param		[out] The quaternion's w coordinate
//
//*****************************************************************************
inline void CEMQuaternion::GetW( float& a_fW ) const
{
	a_fW = m_fW;
}

//*****************************************************************************
//	SetX
//*****************************************************************************
//
//! \brief		Sets the quaternion's x coordinate
//! \param		[in] The quaternion's x coordinate to set
//
//*****************************************************************************
inline void CEMQuaternion::SetX( float a_fX )
{
	m_fX = a_fX;
}

//*****************************************************************************
//	SetY
//*****************************************************************************
//
//! \brief		Sets the quaternion's y coordinate
//! \param		[in] The quaternion's y coordinate to set
//
//*****************************************************************************
inline void CEMQuaternion::SetY( float a_fY )
{
	m_fY = a_fY;
}

//*****************************************************************************
//	SetZ
//*****************************************************************************
//
//! \brief		Sets the quaternion's z coordinate
//! \param		[in] The quaternion's z coordinate to set
//
//*****************************************************************************
inline void CEMQuaternion::SetZ( float a_fZ )
{
	m_fZ = a_fZ;
}

//*****************************************************************************
//	SetW
//*****************************************************************************
//
//! \brief		Sets the quaternion's w coordinate
//! \param		[in] The quaternion's w coordinate to set
//
//*****************************************************************************
inline void CEMQuaternion::SetW( float a_fW )
{
	m_fW = a_fW;
}

//*****************************************************************************
//	Clear
//*****************************************************************************
//
//! \brief	Clears the quaternion
//
//*****************************************************************************
inline void CEMQuaternion::Clear()
{
	SetQuaternion( 0.0f, 0.0f, 0.0f, 1.0f );
}

//*****************************************************************************
//	ReverseMultiply
//*****************************************************************************
//
//! \brief	Multiplies a prefix by the quatertnion
//! \param	[in] The prefix to multiply by the quaternion
//
//*****************************************************************************
inline void CEMQuaternion::ReverseMultiply( const CEMQuaternion& a_quatPrefix ) 
{
	SetToProduct( a_quatPrefix, (*this) );
}

//*****************************************************************************
//	Multiply
//*****************************************************************************
//
//! \brief	Multiplies the quaternion by another one
//! \param	[in] The quaternion to multiply with
//
//*****************************************************************************
inline void CEMQuaternion::Multiply( const CEMQuaternion& a_quatFactor ) 
{
	SetToProduct( (*this), a_quatFactor );
}

//*****************************************************************************
//	RotateAxisX
//*****************************************************************************
//
//! \brief	Rotates the quaternion by the specified angle along the x axis
//! \param	[in] The angle to rotate by along the x axis
//
//*****************************************************************************
inline void CEMQuaternion::RotateAxisX( float a_fAngle ) 
{
	Multiply( CEMQuaternion( ::g_sinf( a_fAngle * 0.5f ), 0.0f, 0.0f, ::g_cosf( a_fAngle * 0.5f ) ) );
}

//*****************************************************************************
//	RotateAxisY
//*****************************************************************************
//
//! \brief	Rotates the quaternion by the specified angle along the y axis
//! \param	[in] The angle to rotate by along the y axis
//
//*****************************************************************************
inline void CEMQuaternion::RotateAxisY( float a_fAngle ) 
{
	Multiply( CEMQuaternion( 0.0f, ::g_sinf( a_fAngle * 0.5f ), 0.0f, ::g_cosf( a_fAngle * 0.5f ) ) );
}

//*****************************************************************************
//	RotateAxisZ
//*****************************************************************************
//
//! \brief	Rotates the quaternion by the specified angle along the z axis
//! \param	[in] The angle to rotate by along the z axis
//
//*****************************************************************************
inline void CEMQuaternion::RotateAxisZ( float a_fAngle ) 
{
	Multiply( CEMQuaternion( 0.0f, 0.0f, ::g_sinf( a_fAngle * 0.5f ), ::g_cosf( a_fAngle * 0.5f ) ) );
}

//*****************************************************************************
//	RotateLocalAxisX
//*****************************************************************************
//
//! \brief	Locally rotates the quaternion by the specified angle along the x axis
//! \param	[in] The angle to rotate by along the x axis
//
//*****************************************************************************
inline void CEMQuaternion::RotateLocalAxisX( float a_fAngle ) 
{
	ReverseMultiply( CEMQuaternion( ::g_sinf( a_fAngle * 0.5f ), 0.0f, 0.0f, ::g_cosf( a_fAngle * 0.5f ) ) );
}

//*****************************************************************************
//	RotateLocalAxisY
//*****************************************************************************
//
//! \brief	Locally rotates the quaternion by the specified angle along the y axis
//! \param	[in] The angle to rotate by along the y axis
//
//*****************************************************************************
inline void CEMQuaternion::RotateLocalAxisY( float a_fAngle ) 
{
	ReverseMultiply( CEMQuaternion( 0.0f, ::g_sinf( a_fAngle * 0.5f ), 0.0f, ::g_cosf( a_fAngle * 0.5f ) ) );
}

//*****************************************************************************
//	RotateLocalAxisZ
//*****************************************************************************
//
//! \brief	Locally rotates the quaternion by the specified angle along the z axis
//! \param	[in] The angle to rotate by along the z axis
//
//*****************************************************************************
inline void CEMQuaternion::RotateLocalAxisZ( float a_fAngle ) 
{
	ReverseMultiply( CEMQuaternion( 0.0f, 0.0f, ::g_sinf( a_fAngle * 0.5f ), ::g_cosf( a_fAngle * 0.5f ) ) );
}

//*****************************************************************************
//	GetMagnitude
//*****************************************************************************
//
//! \brief	Determines the quaternion's magnitude
//! \return	The magnitude
//
//*****************************************************************************
inline float CEMQuaternion::GetMagnitude( void ) const 
{
	return ::g_sqrtf( GetSquareMagnitude() );
}

//*****************************************************************************
//	GetSquareMagnitude
//*****************************************************************************
//
//! \brief	Determines the quaternion's square magnitude
//! \return	The square of the megnitude
//
//*****************************************************************************
inline float CEMQuaternion::GetSquareMagnitude( void ) const 
{
	return (  m_fX * m_fX
			+ m_fY * m_fY
			+ m_fZ * m_fZ
			+ m_fW * m_fW );
}

//*****************************************************************************
//	GetDotProduct
//*****************************************************************************
//
//! \brief	Determines the dot product of this quaternion an dthe specified one
//! \return	The result of the dotproduct
//
//*****************************************************************************
inline float CEMQuaternion::GetDotProduct( const CEMQuaternion& a_quatFactor ) const 
{
   return (	 m_fX * a_quatFactor.m_fX 
		   + m_fY * a_quatFactor.m_fY 
		   + m_fZ * a_quatFactor.m_fZ 
		   + m_fW * a_quatFactor.m_fW );
}

//*****************************************************************************
//	GetReverseProduct
//*****************************************************************************
//
//! \brief	Returns the product of the specified quaternion and this one
//! \param	[out] The calculated quaternion
//! \param	[in] The other quaternion needed for the calculation
//
//*****************************************************************************
inline void CEMQuaternion::GetReverseProduct( CEMQuaternion& a_quatReverseProduct, const CEMQuaternion& a_quatPrefix ) const 
{
	a_quatReverseProduct.SetToProduct( a_quatPrefix, (*this) );
}

//*****************************************************************************
//	GetProduct
//*****************************************************************************
//
//! \brief	Returns the product of this quaternion and the specified one 
//! \param	[out] The result quaternion
//! \param	[in] The quaternion to be multiplied to this one
//
//*****************************************************************************
inline void CEMQuaternion::GetProduct( CEMQuaternion& a_quatProduct, const CEMQuaternion& a_quatFactor ) const 
{
	a_quatProduct.SetToProduct( (*this), a_quatFactor );
}

//*****************************************************************************
//	operator Comparison
//*****************************************************************************
//
//! \brief	Comparison operator
//! \return	The method returns either of the following values
//! \retval	true	|	The quaternions are equal
//! \retval	false	|	The quaternions differ
//
//*****************************************************************************
inline bool CEMQuaternion::operator == ( const CEMQuaternion& a_quatOther ) const 
{
	return IsEqual( a_quatOther );
}

//*****************************************************************************
//	operator Comparison
//*****************************************************************************
//
//! \brief	Comparison operator
//! \return	The method returns either of the following values
//! \retval	true	|	The quaternions differ
//! \retval	false	|	The quaternions are equal
//
//*****************************************************************************
inline bool CEMQuaternion::operator != ( const CEMQuaternion& a_quatOther ) const 
{
	return ! ( IsEqual( a_quatOther ) );
}

//*****************************************************************************
//	operator Inv
//*****************************************************************************
//
//! \brief	inv operator
//! \return	An inverted copy of this quaternion
//
//*****************************************************************************
inline CEMQuaternion CEMQuaternion::operator ~ ( void ) const 
{
	return GetInverted();
}

//*****************************************************************************
//	operator Neg
//*****************************************************************************
//
//! \brief	Neg operator
//! \return	A negated copy of this quaternion
//
//*****************************************************************************
inline CEMQuaternion CEMQuaternion::operator - ( void ) const 
{
	return GetNegated();
}

//*****************************************************************************
//	operator *
//*****************************************************************************
//
//! \brief	mul operator
//! \param	[in] The factor to multiply with
//! \return	The result of the multiplication
//
//*****************************************************************************
inline CEMQuaternion CEMQuaternion::operator * ( float a_fFactor ) const 
{
	return GetProduct( a_fFactor );
}

//*****************************************************************************
//	operator /
//*****************************************************************************
//
//! \brief	div operator
//! \param	[in] The factor to divide by
//! \return	The result of the division
//
//*****************************************************************************
inline CEMQuaternion CEMQuaternion::operator / ( float a_fFactor ) const 
{
	return GetProduct( 1.0f / a_fFactor );
}

//*****************************************************************************
//	operator +
//*****************************************************************************
//
//! \brief	add operator
//! \param	[in] The quaternion to add to this one
//! \return	The result of the addition
//
//*****************************************************************************
inline CEMQuaternion CEMQuaternion::operator + ( const CEMQuaternion& a_quatRotation ) const 
{
	return GetSum( a_quatRotation );
}

//*****************************************************************************
//	operator -
//*****************************************************************************
//
//! \brief	sub operator
//! \param	[in] The quaternion to subtract from this one
//! \return	The result of the subtraction
//
//*****************************************************************************
inline CEMQuaternion CEMQuaternion::operator - ( const CEMQuaternion& a_quatRotation ) const 
{
	return GetDifference( a_quatRotation );
}

//*****************************************************************************
//	operator *
//*****************************************************************************
//
//! \brief	mul operator
//! \param	[in] The quaternion to multiply by this one
//! \return	The result of the multiplikation
//
//*****************************************************************************
inline CEMQuaternion CEMQuaternion::operator * ( const CEMQuaternion& a_quatRotation ) const 
{
	return GetProduct( a_quatRotation );
}

//*****************************************************************************
//	operator *
//*****************************************************************************
//
//! \brief	Mul operator
//! \param	[in] The factor for the multiplication
//! \param	[in] The quaternion to be multiplied with the specified factor
//! \return	The result of multiplying the specified factor with the specified quaternion
//
//*****************************************************************************
inline CEMQuaternion operator * ( float a_fFactor, const CEMQuaternion& a_quatFactor )
{
	return a_quatFactor.GetProduct( a_fFactor );
}

#endif	// CEMQuaternion_H_INCLUDED
