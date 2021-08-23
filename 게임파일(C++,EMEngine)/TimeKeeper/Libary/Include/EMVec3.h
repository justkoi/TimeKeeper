#ifndef			CEMVec3_H_INCLUDED
#define			CEMVec3_H_INCLUDED

#ifdef			_MSC_VER
#if				_MSC_VER > 1000
#pragma once
#endif 
#endif 

class			CEMMat4x4		;
class			CEMMat3x3		;

#include		"EMMathBase.h"

#pragma	warning( push )
#pragma warning( disable : 4201 )	// nonstandard extension used : nameless struct/union

//*************************************************************************************************
//*************************************************************************************************
//*************************************************************************************************

//*****************************************************************************
//	CEMVec3
//*****************************************************************************
//
//!	Representation of a 3-dimensional vector
//
//*****************************************************************************
class CEMVec3
{

public:

	// Enums

	enum ECoordinate								//! Coordinate indices
	{
		ECoordinate_X							,	//!< The x	(width)		coordinate
		ECoordinate_Y							,	//!< The y	(height)	coordinate	
		ECoordinate_Z							,	//!< The z	(depth)		coordinate	
		ECoordinate_Count						,	//!< The total number of coordinates
		ECoordinate_Min			= ECoordinate_X	,	//!< The first coordinate
		ECoordinate_Max			= ECoordinate_Z	,	//!< The first coordinate
		ECoordinate_ForceDWORD	= FORCE_DWORD		//!< Forces all compilers to reserve 32 bits for the enumeration
	};																												
																												
protected:

	// Attribs

	union
	{
		float m_pfCoordinates[ ECoordinate_Count ];	//!< Array representation of vector's coordinates

		struct
		{
			float	m_fX;							//!< Vector's X coordinate
			float	m_fY;							//!< Vector's Y coordinate
			float	m_fZ;							//!< Vector's Z coordinate
		};
	};

public:

	// Con-/Destruction

			 CEMVec3	(		float		a_fX															
						,		float		a_fY															
						,		float		a_fZ				);											
	explicit CEMVec3	(		float		a_fCoordinates		);											
	explicit CEMVec3	( const	float		a_pfCoordinates[3]	);											
			 CEMVec3	( const	CEMVec3&	a_vecSource			);											
			 CEMVec3	();																					
			~CEMVec3	();																					

	// Get/Set

	static const CEMVec3&	GetUp					( void )												;
			float&			AccessX					( void )												;
			float&			AccessY					( void )												;
			float&			AccessZ					( void )												;
			float(&			AccessCoordinates		( void )										  ) [3]	;
			float&			AccessCoordinate		(		int			a_iIndex )							;
			float			GetX					( void )									const		;
			float			GetY					( void )									const		;
			float			GetZ					( void )									const		;
	const	float(&			GetCoordinates			( void )									const ) [3]	;
	const	float&			GetCoordinate			(		int			a_iIndex )				const		;
			void			GetX					(		float&		a_fX )					const		;
			void			GetY					(		float&		a_fY )					const		;
			void			GetZ					(		float&		a_fZ )					const		;
			void			GetCoordinates			(		float		a_pfCoordinates[3]	)	const		;
			void			GetCoordinates			(		float&		a_fX				
													,		float&		a_fY				
													,		float&		a_fZ				)	const		;
			void			GetCoordinate			(		int			a_iIndex 
													,		float&		a_fCoordinate		)	const		;
			void			SetX					( const float&		a_fX )								;
			void			SetY					( const float&		a_fY )								;
			void			SetZ					( const float&		a_fZ )								;
			void			SetCoordinates			( const	float		a_pfCoordinates[3]	)				;
			void			SetCoordinates			(		float		a_fX
													,		float		a_fY
													,		float		a_fZ				)				;
			void			SetCoordinate			(		int			a_iIndex 
													,		float		a_fCoordinate		)				;
			void			SetVector				(		float		a_fCoordinates		)				;
			void			SetVector				( const CEMVec3&	a_vecSource			)				;
			void			SetVector				(		float		a_fX
													,		float		a_fY
													,		float		a_fZ				)				;

	// Modification

			void			Clear					( void )												;
			void			Invert					( void )												;
			void			Normalize				( void )												;
			void			Scale					(		float		a_fScalar		)					;
			void			Scale					( const CEMVec3&	a_vecScalar		)					;
			void			Translate				(		float		a_fTranslate	)					;
			void			Translate				( const CEMVec3&	a_vecTranslate	)					;
			void			CrossProduct			( const CEMVec3&	a_vecFactor		)					;
			void			Transform				( const CEMMat3x3&	a_matTransform	)					;
			void			Transform				( const CEMMat4x4&	a_matTransform	)					;
			void			TransformDirection		( const CEMMat4x4&	a_matTransform	)					;
			void			TransposedTransform		( const CEMMat3x3&	a_matTransform	)					;
			void			InvScale				(		float		a_fScalar		)					;
			void			InvScale				( const CEMVec3&	a_vecScalar		)					;
			void			InvTranslate			(		float		a_fScalar		)					;
			void			InvTranslate			( const CEMVec3&	a_vecScalar		)					;
			void			InvTransform			( const CEMMat3x3&	a_matTransform	)					;
			void			InvTransform			( const CEMMat4x4&	a_matTransform	)					;
			void			InvTransformDirection	( const CEMMat4x4&	a_matTransform	)					;
			void			SetCrossProduct			( const CEMVec3&	a_vecA		
													, const CEMVec3&	a_vecB			)					;
			void			SetLerp					( const CEMVec3&	a_vecSource		
													, const CEMVec3&	a_vecTarget 
													,		float		a_fAlpha		)					;
			void			SetSlerp				(		CEMVec3	a_vecSource		
													,		CEMVec3	a_vecTarget 
													,		float		a_fAlpha		)					;
			void			SetTransformed			( const CEMVec3&	a_vecBase		,
													  const CEMMat4x4&	a_matTransform	)					;
			void			SetTransformed			( const CEMVec3&	a_vecBase		,
													  const CEMMat3x3&	a_matTransform	)					;
			void			SetTransformedDirection	( const CEMVec3&	a_vecBase		,
													  const CEMMat4x4&	a_matTransform	)					;
			void			SetTransposedTransformed( const CEMVec3&	a_vecBase		,
													  const CEMMat3x3&	a_matTransform	)					;

	// Computations

	static	float			DotProduct					( const CEMVec3&	a_vecFactorA, 
														  const CEMVec3&	a_vecFactorB	)				;
	static	CEMVec3		CrossProduct				( const CEMVec3&	a_vecFactorA, 
														  const CEMVec3&	a_vecFactorB	)				;
			bool			IsEqual						( const CEMVec3&	a_vecOther		)		const	;
			bool			HasZeroMagnitude			( void )									const	;
			float			GetMagnitude				( void )									const	;
			float			GetMagnitudeNormalize		( void )											;
			float			GetSquareMagnitude			( void )									const	;
			CEMVec3		GetInverted					( void )									const	;
			CEMVec3		GetNormalized				( void )									const	;
			CEMVec3		GetScaled					(		float		a_fScalar		)		const	;
			CEMVec3		GetScaled					( const CEMVec3&	a_vecScalar		)		const	;
			CEMVec3		GetTranslated				(		float		a_fTranslate	)		const	;
			CEMVec3		GetTranslated				( const CEMVec3&	a_vecTranslate	)		const	;
			float			GetDotProduct				( const CEMVec3&	a_vecScalar		)		const	;
			CEMVec3		GetCrossProduct				( const CEMVec3&	a_vecScalar		)		const	;
			CEMVec3		GetTransformed				( const CEMMat3x3&	a_matTransform	)		const	;
			CEMVec3		GetTransformed				( const CEMMat4x4&	a_matTransform	)		const	;
			CEMVec3		GetTransformedDirection		( const CEMMat4x4&	a_matTransform	)		const	;
			CEMVec3		GetInvScaled				( const float		a_fScalar		)		const	;
			CEMVec3		GetInvScaled				( const CEMVec3&	a_vecScalar		)		const	;
			CEMVec3		GetInvTranslated			( const float		a_fScalar		)		const	;
			CEMVec3		GetInvTranslated			( const CEMVec3&	a_vecScalar		)		const	;
			CEMVec3		GetInvTransformed			( const CEMMat3x3&	a_matTransform	)		const	;
			CEMVec3		GetInvTransformed			( const CEMMat4x4&	a_matTransform	)		const	;
			CEMVec3		GetInvTransformedDirection	( const CEMMat4x4&	a_matTransform	)		const	;
			CEMVec3		GetLerp						( const CEMVec3&	a_vecTarget		
														,		float		a_fAlpha		)		const	;
			CEMVec3		GetSlerp					( const CEMVec3&	a_vecTarget		
														,		float		a_fAlpha		)		const	;

	// Operators

			CEMVec3&		operator	=				( const CEMVec3&	a_vecSource		)				;
			CEMVec3&		operator	+=				( const CEMVec3&	a_vecTranslate	)				;
			CEMVec3&		operator	-=				( const CEMVec3&	a_vecTranslate	)				;
			CEMVec3&		operator	*=				(		float		a_fScale		)				;
			CEMVec3&		operator	/=				(		float		a_fScale		)				;
			CEMVec3&		operator	*=				( const	CEMMat3x3&	a_matTransform	)				;
			CEMVec3&		operator	/=				( const	CEMMat3x3&	a_matTransform	)				;
			CEMVec3&		operator	*=				( const	CEMMat4x4&	a_matTransform	)				;
			CEMVec3&		operator	/=				( const	CEMMat4x4&	a_matTransform	)				;
			CEMVec3		operator	-				( void )									const	;
			CEMVec3		operator	+				( const CEMVec3&	a_vecTranslate	)		const	;
			CEMVec3		operator	-				( const CEMVec3&	a_vecTranslate	)		const	;
			CEMVec3		operator	*				(		float		a_fScale		)		const	;
			CEMVec3		operator	/				(		float		a_fScale		)		const	;
			CEMVec3		operator	*				( const	CEMMat4x4&	a_matTransform	)		const	;
			CEMVec3		operator	/				( const	CEMMat4x4&	a_matTransform	)		const	;
	friend	CEMVec3		operator	*				(		float		a_fScale		
														, const CEMVec3&	a_vecSource		)				;
	friend	CEMVec3		operator	/				(		float		a_fScale		
														, const CEMVec3&	a_vecSource		)				;
			bool			operator	==				( const CEMVec3&	a_vecOther		)		const	;
			bool			operator	!=				( const CEMVec3&	a_vecOther		)		const	;
	const	float&			operator	[]				(		int			a_iIndex		)		const	;
			float&			operator	[]				(		int			a_iIndex		)				;

};

//*************************************************************************************************
//*************************************************************************************************
//*************************************************************************************************

#pragma warning( pop )

//*****************************************************************************
//	AccessX
//*****************************************************************************
//
//! \brief		Returns the vector's x coordinate for modification purposes
//! \return		The vector's x coordinate
//
//*****************************************************************************
inline float& CEMVec3::AccessX( void )
{
	return m_fX;
}

//*****************************************************************************
//	AccessY
//*****************************************************************************
//
//! \brief		Returns the vector's y coordinate for modification purposes
//! \return		The vector's y coordinate
//
//*****************************************************************************
inline float& CEMVec3::AccessY( void )
{
	return m_fY;
}

//*****************************************************************************
//	AccessZ
//*****************************************************************************
//
//! \brief		Returns the vector's z coordinate for modification purposes
//! \return		The vector's z coordinate
//
//*****************************************************************************
inline float& CEMVec3::AccessZ( void )
{
	return m_fZ;
}

//*****************************************************************************
//	AccessCoordinates
//*****************************************************************************
//
//! \brief		Returns the vector's coordinates for modification purposes
//! \return		The vector's coordinates
//
//*****************************************************************************
inline float (&CEMVec3::AccessCoordinates( void )) [3]
{
	return m_pfCoordinates;
}

//*****************************************************************************
//	AccessCoordinate
//*****************************************************************************
//
//! \brief		Returns the specified coordinate for modification purposes
//! \param		[in] The desired coordinate's index
//! \return		The desired coordinate
//
//*****************************************************************************
inline float& CEMVec3::AccessCoordinate( int a_iCoordinate )
{
	return m_pfCoordinates[ a_iCoordinate ];
}

//*****************************************************************************
//	GetX
//*****************************************************************************
//
//! \brief		Returns the vector's x coordinate for look-up purposes
//! \return		The vector's x coordinate
//
//*****************************************************************************
inline float CEMVec3::GetX( void ) const			
{
	return m_fX;
}

//*****************************************************************************
//	GetY
//*****************************************************************************
//
//! \brief		Returns the vector's y coordinate for look-up purposes
//! \return		The vector's y coordinate
//
//*****************************************************************************
inline float CEMVec3::GetY( void ) const			
{
	return m_fY;
}

//*****************************************************************************
//	GetZ
//*****************************************************************************
//
//! \brief		Returns the vector's z coordinate for look-up purposes
//! \return		The vector's z coordinate
//
//*****************************************************************************
inline float CEMVec3::GetZ( void ) const			
{
	return m_fZ;
}

//*****************************************************************************
//	GetCoordinates
//*****************************************************************************
//
//! \brief		Returns the vector's coordinates for look-up purposes
//! \return		The vector's coordinates
//
//*****************************************************************************
inline const float (&CEMVec3::GetCoordinates( void ) const) [3]
{
	return m_pfCoordinates;
}

//*****************************************************************************
//	GetCoordinate
//*****************************************************************************
//
//! \brief		Returns the specified coordinate for look-up purposes
//! \param		[in] The desired coordinate's index
//! \return		The desired coordinate
//
//*****************************************************************************
inline const float& CEMVec3::GetCoordinate( int a_iCoordinate ) const
{
	return m_pfCoordinates[ a_iCoordinate ];
}

//*****************************************************************************
//	GetX
//*****************************************************************************
//
//! \brief		Retrieves the vector's x coordinate
//! \param		[out] The vector's x coordinate
//
//*****************************************************************************
inline void CEMVec3::GetX( float& a_fX ) const
{
	a_fX = m_fX;
}

//*****************************************************************************
//	GetY
//*****************************************************************************
//
//! \brief		Retrieves the vector's y coordinate
//! \param		[out] The vector's y coordinate
//
//*****************************************************************************
inline void CEMVec3::GetY( float& a_fY ) const
{
	a_fY = m_fY;
}

//*****************************************************************************
//	GetZ
//*****************************************************************************
//
//! \brief		Retrieves the vector's z coordinate
//! \param		[out] The vector's z coordinate
//
//*****************************************************************************
inline void CEMVec3::GetZ( float& a_fZ ) const
{
	a_fZ = m_fZ;
}

//*****************************************************************************
//	GetCoordinate
//*****************************************************************************
//
//! \brief		Returns the specified coordinate for modification purposes
//! \param		[in] The desired coordinate's index
//! \param		[out] The desired coordinate
//
//*****************************************************************************
inline void CEMVec3::GetCoordinate( int a_iCoordinate, float& a_fCoordinate ) const
{
	a_fCoordinate = m_pfCoordinates[ a_iCoordinate ];
}

//*****************************************************************************
//	SetX
//*****************************************************************************
//
//! \brief		Sets the vector's x coordinate
//! \param		[in] The vector's x coordinate to set
//
//*****************************************************************************
inline void CEMVec3::SetX( const float& a_fX )
{
	m_fX = a_fX;
}

//*****************************************************************************
//	SetY
//*****************************************************************************
//
//! \brief		Sets the vector's y coordinate
//! \param		[in] The vector's y coordinate to set
//
//*****************************************************************************
inline void CEMVec3::SetY( const float& a_fY )
{
	m_fY = a_fY;
}

//*****************************************************************************
//	SetZ
//*****************************************************************************
//
//! \brief		Sets the vector's z coordinate
//! \param		[in] The vector's z coordinate to set
//
//*****************************************************************************
inline void CEMVec3::SetZ( const float& a_fZ )
{
	m_fZ = a_fZ;
}

//*****************************************************************************
//	SetCoordinate
//*****************************************************************************
//
//! \brief		Sets the specified coordinate
//! \param		[in] The index of the coordinate's to set
//! \param		[in] The coordinate's value
//
//*****************************************************************************
inline void CEMVec3::SetCoordinate( int a_iCoordinate, float a_fCoordinate )
{
	m_pfCoordinates[ a_iCoordinate ] = a_fCoordinate;
}

//*****************************************************************************
//	SetVector
//*****************************************************************************
//
//! \brief		Sets the vector's coordinates
//! \param		[in] The value to set at all coordinates
//
//*****************************************************************************
inline void CEMVec3::SetVector( float a_fCoordinates )
{
	SetCoordinates( a_fCoordinates, a_fCoordinates, a_fCoordinates );
}

//*****************************************************************************
//	SetVector
//*****************************************************************************
//
//! \brief		Sets the vector's coordinates
//! \param		[in] The vector's coordinates to set
//
//*****************************************************************************
inline void CEMVec3::SetVector( float a_fX, float a_fY, float a_fZ )
{
	SetCoordinates( a_fX, a_fY, a_fZ );
}

//*****************************************************************************
//	CrossProduct
//*****************************************************************************
//
//! \brief		Cross-multiplies this vector with the specified vector
//! \param		[in] The vector to cross-multiply by
//
//*****************************************************************************
inline void CEMVec3::CrossProduct( const CEMVec3& a_vecFactor )
{
	SetVector( GetCrossProduct( a_vecFactor ) );
}

//*****************************************************************************
//	Transform
//*****************************************************************************
//
//! \brief		Transforms the vector by the specified matrix (matrix multiplication). 
//!				The vector is treated as a 4-dimensional vector whose last element is 
//!				considered to be 1.0. (location vector)
//! \param		[in] The matrix to transform by
//
//*****************************************************************************
inline void CEMVec3::Transform( const CEMMat4x4& a_matTransform )
{
	SetVector( GetTransformed( a_matTransform ) );
}

//*****************************************************************************
//	TransformDirection
//*****************************************************************************
//
//! \brief		Transforms the vector by the specified matrix (matrix multiplication). 
//!				The vector is treated as a 4-dimensional vector whose last element is 
//!				considered to be 0.0. (direction vector)
//! \param		[in] The matrix to transform by
//
//*****************************************************************************
inline void CEMVec3::TransformDirection( const CEMMat4x4& a_matTransform )
{
	SetVector( GetTransformedDirection( a_matTransform ) );
}

//*****************************************************************************
//	InvScale
//*****************************************************************************
//
//! \brief		Scales the vector by the inverse of the specified factor (outer/scalar product)
//! \param		[in] The factor to scale by
//
//*****************************************************************************
inline void CEMVec3::InvScale( float a_fScalar )
{
	Scale( 1.0f / a_fScalar );
}

//*****************************************************************************
//	InvTransform
//*****************************************************************************
//
//! \brief		Transforms the vector by the inverse of the specified matrix
//! \param		[in] The matrix to transform by
//
//*****************************************************************************
inline void CEMVec3::InvTransform( const CEMMat4x4& a_matTransform )
{
	SetVector( GetInvTransformed( a_matTransform ) );
}

//*****************************************************************************
//	InvTransformDirection
//*****************************************************************************
//
//! \brief		Transforms the vector by the inverse of the specified matrix; treat it as a direction vector.
//! \param		[in] The matrix to transform by
//
//*****************************************************************************
inline void CEMVec3::InvTransformDirection( const CEMMat4x4& a_matTransform )
{
	SetVector( GetInvTransformedDirection( a_matTransform ) );
}

//*****************************************************************************
//	DotProduct
//*****************************************************************************
//
//! \brief		Returns the outer/dot product of the specified vectors
//! \param		[in] A vector
//! \param		[in] A vector
//! \return		The dot product
//
//*****************************************************************************
inline float CEMVec3::DotProduct( const CEMVec3& a_vecFactorA, const CEMVec3& a_vecFactorB )
{
	return a_vecFactorA.GetDotProduct( a_vecFactorB );
}

//*****************************************************************************
//	HasZeroMagnitude
//*****************************************************************************
//
//! \brief		Determines whether or not the vector has no magnitude
//! \return		The method returns either of the following values
//! \retval		true	| The vector has no magnitude
//! \retval		false	| The vector has a magnitude
//
//*****************************************************************************
inline bool CEMVec3::HasZeroMagnitude( void ) const
{
	return ( 0.0f == m_fX )
		&& ( 0.0f == m_fY )
		&& ( 0.0f == m_fZ );
}

//*****************************************************************************
//	GetMagnitude
//*****************************************************************************
//
//! \brief		Returns the vector's magnitude (length)
//! \return		The vector's magnitude
//
//*****************************************************************************
inline float CEMVec3::GetMagnitude( void ) const			
{
	return ::g_sqrtf( GetSquareMagnitude() );
}

//*****************************************************************************
//	GetSquareMagnitude
//*****************************************************************************
//
//! \brief		Returns the squared vector's magnitude (length)
//! \return		The squared vector's magnitude
//
//*****************************************************************************
inline float CEMVec3::GetSquareMagnitude( void ) const			
{
	return ( m_fX * m_fX + m_fY * m_fY + m_fZ * m_fZ );
}

//*****************************************************************************
//	GetDotProduct
//*****************************************************************************
//
//! \brief		Returns the outer/dot product of this vector and the specified vector
//! \param		[in] The factor to multiply by
//! \return		The dot product
//
//*****************************************************************************
inline float CEMVec3::GetDotProduct( const CEMVec3& a_vecFactor ) const			
{
	return	( m_fX * a_vecFactor.m_fX 
			+ m_fY * a_vecFactor.m_fY 
			+ m_fZ * a_vecFactor.m_fZ );
}

//*****************************************************************************
//	operator -
//*****************************************************************************
//
//! \brief		Neg operator
//! \return		The inverted vector
//
//*****************************************************************************
inline CEMVec3 CEMVec3::operator - () const
{	
	return GetInverted();
}

//*****************************************************************************
//	operator +
//*****************************************************************************
//
//! \brief		Add operator
//! \param		[in] The vector to translate by
//! \return		The translated vector
//
//*****************************************************************************
inline CEMVec3 CEMVec3::operator + ( const CEMVec3& a_vecTranslate ) const
{
	return GetTranslated( a_vecTranslate );
}

//*****************************************************************************
//	operator -
//*****************************************************************************
//
//! \brief		Sub operator
//! \param		[in] The vector to translate by
//! \return		The translated vector
//
//*****************************************************************************
inline CEMVec3 CEMVec3::operator - ( const CEMVec3& a_vecTranslate ) const
{	
	return GetInvTranslated( a_vecTranslate );
}

//*****************************************************************************
//	operator *
//*****************************************************************************
//
//! \brief		Mul operator
//! \param		[in] The factor to scale by
//! \return		The scaled vector
//
//*****************************************************************************
inline CEMVec3 CEMVec3::operator * ( float a_fScale ) const
{
	return GetScaled( a_fScale );
}

//*****************************************************************************
//	operator /
//*****************************************************************************
//
//! \brief		Div operator
//! \param		[in] The factor to scale by 
//! \return		The scaled vector
//
//*****************************************************************************
inline CEMVec3 CEMVec3::operator / ( float a_fScale ) const
{
	return GetInvScaled( a_fScale );
}

//*****************************************************************************
//	operator *
//*****************************************************************************
//
//! \brief		Mul operator
//! \param		[in] The matrix to transform by
//! \return		The transformed vector
//
//*****************************************************************************
inline CEMVec3 CEMVec3::operator * ( const CEMMat4x4& a_matTransform ) const
{
	return GetTransformed( a_matTransform );
}

//*****************************************************************************
//	operator /
//*****************************************************************************
//
//! \brief		Div operator
//! \param		[in] The matrix to transform by 
//! \return		The transformed vector
//
//*****************************************************************************
inline CEMVec3 CEMVec3::operator / ( const CEMMat4x4& a_matTransform ) const
{
	return GetInvTransformed( a_matTransform );
}

//*****************************************************************************
//	operator *
//*****************************************************************************
//
//! \brief		CEMVec3 | operator * | Mul operator
//! \param		[in] The factor to scale by
//! \return		The scaled vector
//
//*****************************************************************************
inline CEMVec3 operator * ( float a_fScale, const CEMVec3& a_vecSource )
{
	return ( a_vecSource * a_fScale );
}

//*****************************************************************************
//	operator /
//*****************************************************************************
//
//! \brief		CEMVec3 | operator / | Div operator
//! \param		[in] The factor to scale by 
//! \return		The scaled vector
//
//*****************************************************************************
inline CEMVec3 operator / ( float a_fScale, const CEMVec3& a_vecSource )
{
	return ( a_vecSource / a_fScale );
}

//*****************************************************************************
//	operator ==
//*****************************************************************************
//
//! \brief		Comparison operator
//! \param		[in] The vector to compare to
//! \return		The method returns either of the following values
//! \retval		true	| The vectors are identical
//! \retval		false	| The vectors differ
//
//*****************************************************************************
inline bool CEMVec3::operator == ( const CEMVec3& a_vecOther ) const
{
	return IsEqual( a_vecOther );
}

//*****************************************************************************
//	operator !=
//*****************************************************************************
//
//! \brief		Comparison operator
//! \param		[in] The vector to compare to
//! \return		The method returns either of the following values
//! \retval		true	| The vectors differ
//! \retval		false	| The vectors are identical
//
//*****************************************************************************
inline bool CEMVec3::operator != ( const CEMVec3& a_vecOther ) const
{
	return ( ! IsEqual( a_vecOther ) );
}

//*****************************************************************************
//	operator []
//*****************************************************************************
//
//! \brief		Array operator
//! \param		[in] The desired coordinate's index 
//! \return		The desired coordinate
//
//*****************************************************************************
inline const float& CEMVec3::operator [] ( int a_iIndex ) const 
{
	return GetCoordinate( a_iIndex );
}

//*****************************************************************************
//	operator []
//*****************************************************************************
//
//! \brief		Array operator
//! \param		[in] The desired coordinate's index 
//! \return		The desired coordinate
//
//*****************************************************************************
inline float& CEMVec3::operator [] ( int a_iIndex ) 
{
	return AccessCoordinate( a_iIndex );
}

//*************************************************************************************************
//*************************************************************************************************
//*************************************************************************************************

#endif	// CEMVec3_H_INCLUDED
