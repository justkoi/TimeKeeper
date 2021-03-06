#ifndef			CEMVec4_H_INCLUDED
#define			CEMVec4_H_INCLUDED

#ifdef			_MSC_VER
#if				_MSC_VER > 1000
#pragma once
#endif 
#endif


#include		"EMMathBase.h"
class CEMMat4x4;

#pragma	warning( push )
#pragma warning( disable : 4201 )	// nonstandard extension used : nameless struct/union

//*************************************************************************************************
//*************************************************************************************************
//*************************************************************************************************

//*****************************************************************************
//	CEMVec4
//*****************************************************************************
//
//!	Representation of a 4-dimensional vector
//
//*****************************************************************************
class CEMVec4
{
public:

	// Enums

	enum ECoordinate								//! Coordinate indices
	{
		ECoordinate_X							,	//!< The x	(width)		coordinate
		ECoordinate_Y							,	//!< The y	(height)	coordinate	
		ECoordinate_Z							,	//!< The z	(depth)		coordinate	
		ECoordinate_W							,	//!< The w	(reserved)	coordinate	
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
			float	m_fX;								//!< Vector's X coordinate
			float	m_fY;								//!< Vector's Y coordinate
			float	m_fZ;								//!< Vector's Z coordinate
			float	m_fW;								//!< Vector's W coordinate
		};
	};

public:

	// Con-/Destruction

			 CEMVec4	(		float		a_fX															
						,		float		a_fY															
						,		float		a_fZ				
						,		float		a_fW				);											
	explicit CEMVec4	(		float		a_fCoordinates		);											
	explicit CEMVec4	( const	float		a_pfCoordinates[4]	);											
			 CEMVec4	( const	CEMVec4&	a_vecSource			);											
			 CEMVec4	();																					
			~CEMVec4	();																					

	// Get/Set

			float&			AccessX					( void )												;
			float&			AccessY					( void )												;
			float&			AccessZ					( void )												;
			float&			AccessW					( void )												;
			float(&			AccessCoordinates		( void )										  ) [4]	;
			float&			AccessCoordinate		(		int			a_iIndex )							;
																							
			float			GetX					( void )									const		;
			float			GetY					( void )									const		;
			float			GetZ					( void )									const		;
			float			GetW					( void )									const		;
	const	float(&			GetCoordinates			( void )									const ) [4]	;
	const	float&			GetCoordinate			(		int			a_iIndex )				const		;
																										
			void			GetX					(		float&		a_fX )					const		;
			void			GetY					(		float&		a_fY )					const		;
			void			GetZ					(		float&		a_fZ )					const		;
			void			GetW					(		float&		a_fW )					const		;
			void			GetCoordinates			(		float		a_pfCoordinates[4]	)	const		;
			void			GetCoordinates			(		float&		a_fX				
													,		float&		a_fY				
													,		float&		a_fZ				
													,		float&		a_fW				)	const		;
			void			GetCoordinate			(		int			a_iIndex 
													,		float&		a_fCoordinate		)	const		;
													
			void			SetX					( const float&		a_fX )								;
			void			SetY					( const float&		a_fY )								;
			void			SetZ					( const float&		a_fZ )								;
			void			SetW					( const float&		a_fW )								;
			void			SetCoordinates			( const	float		a_pfCoordinates[4]	)				;
			void			SetCoordinates			(		float		a_fX
													,		float		a_fY
													,		float		a_fZ				
													,		float		a_fW				)				;
			void			SetCoordinate			(		int			a_iIndex 
													,		float		a_fCoordinate		)				;
													
			void			SetVector				(		float		a_fCoordinates		)				;
			void			SetVector				( const CEMVec4&	a_vecSource			)				;
			void			SetVector				(		float		a_fX
													,		float		a_fY
													,		float		a_fZ				
													,		float		a_fW				)				;

	// Modification

			void			Clear					( void )												;
			void			Invert					( void )												;
			void			Normalize				( void )												;
			void			Scale					(		float		a_fScalar		)					;
			void			Scale					( const CEMVec4&	a_vecScalar		)					;
			void			Translate				(		float		a_fTranslate	)					;
			void			Translate				( const CEMVec4&	a_vecTranslate	)					;
			void			Transform				( const CEMMat4x4&	a_matTransform	)					;
			void			InvScale				(		float		a_fScalar		)					;
			void			InvScale				( const CEMVec4&	a_vecScalar		)					;
			void			InvTranslate			(		float		a_fScalar		)					;
			void			InvTranslate			( const CEMVec4&	a_vecScalar		)					;
			void			InvTransform			( const CEMMat4x4&	a_matTransform	)					;

			void			SetTransformed			( const CEMVec4&	a_vecBase	,
													  const CEMMat4x4&	a_matTransform	)					;

	// Computations

	static	float			DotProduct				( const CEMVec4&	a_vecFactorA, 
													  const CEMVec4&	a_vecFactorB	)					;
													
			bool			IsEqual					( const CEMVec4&	a_vecOther		)		const		;

			float			GetMagnitude			( void )									const		;
			float			GetMagnitudeNormalize	( void )												;
			float			GetSquareMagnitude		( void )									const		;
													
			CEMVec4		GetInverted				( void )									const		;
			CEMVec4		GetNormalized			( void )									const		;
			CEMVec4		GetScaled				(		float		a_fScalar		)		const		;
			CEMVec4		GetScaled				( const CEMVec4&	a_vecScalar		)		const		;
			CEMVec4		GetTranslated			(		float		a_fTranslate	)		const		;
			CEMVec4		GetTranslated			( const CEMVec4&	a_vecTranslate	)		const		;
			float		GetDotProduct		( const CEMVec4&	a_vecScalar		)			const		;
			CEMVec4		GetTransformed			( const CEMMat4x4&	a_matTransform	)		const		;
													
			CEMVec4		GetInvScaled			( const float		a_fScalar		)		const		;
			CEMVec4		GetInvScaled			( const CEMVec4&	a_vecScalar		)		const		;
			CEMVec4		GetInvTranslated		( const float		a_fScalar		)		const		;
			CEMVec4		GetInvTranslated		( const CEMVec4&	a_vecScalar		)		const		;
			CEMVec4		GetInvTransformed		( const CEMMat4x4&	a_matTransform	)		const		;

	// Operators

			CEMVec4&		operator	=			( const CEMVec4&	a_vecSource		)					;
													
			CEMVec4&		operator	+=			( const CEMVec4&	a_vecTranslate	)					;
			CEMVec4&		operator	-=			( const CEMVec4&	a_vecTranslate	)					;
			CEMVec4&		operator	*=			(		float		a_fScale		)					;
			CEMVec4&		operator	/=			(		float		a_fScale		)					;
			CEMVec4&		operator	*=			( const	CEMMat4x4&	a_matTransform	)					;
			CEMVec4&		operator	/=			( const	CEMMat4x4&	a_matTransform	)					;
													
			CEMVec4		operator	-			( void )									const		;
			CEMVec4		operator	+			( const CEMVec4&	a_vecTranslate	)		const		;
			CEMVec4		operator	-			( const CEMVec4&	a_vecTranslate	)		const		;
			CEMVec4		operator	*			(		float		a_fScale		)		const		;
			CEMVec4		operator	/			(		float		a_fScale		)		const		;
			CEMVec4		operator	*			( const	CEMMat4x4&	a_matTransform	)		const		;
			CEMVec4		operator	/			( const	CEMMat4x4&	a_matTransform	)		const		;
													
	friend	CEMVec4		operator	*			(		float		a_fScale		
													, const CEMVec4&	a_vecSource		)					;
	friend	CEMVec4		operator	/			(		float		a_fScale		
													, const CEMVec4&	a_vecSource		)					;
													
			bool			operator	==			( const CEMVec4&	a_vecOther		)		const		;
			bool			operator	!=			( const CEMVec4&	a_vecOther		)		const		;
													
	const	float&			operator	[]			(		int			a_iIndex		)		const		;
			float&			operator	[]			(		int			a_iIndex		)					;

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
inline float& CEMVec4::AccessX( void )
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
inline float& CEMVec4::AccessY( void )
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
inline float& CEMVec4::AccessZ( void )
{
	return m_fZ;
}

//*****************************************************************************
//	AccessW
//*****************************************************************************
//
//! \brief		Returns the vector's w coordinate for modification purposes
//! \return		The vector's w coordinate
//
//*****************************************************************************
inline float& CEMVec4::AccessW( void )
{
	return m_fW;
}

//*****************************************************************************
//	AccessCoordinates
//*****************************************************************************
//
//! \brief		Returns the vector's coordinates for modification purposes
//! \return		The vector's coordinates
//
//*****************************************************************************
inline float (&CEMVec4::AccessCoordinates( void )) [4]
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
inline float& CEMVec4::AccessCoordinate( int a_iCoordinate )
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
inline float CEMVec4::GetX( void ) const			
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
inline float CEMVec4::GetY( void ) const			
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
inline float CEMVec4::GetZ( void ) const			
{
	return m_fZ;
}

//*****************************************************************************
//	GetW
//*****************************************************************************
//
//! \brief		Returns the vector's w coordinate for look-up purposes
//! \return		The vector's w coordinate
//
//*****************************************************************************
inline float CEMVec4::GetW( void ) const			
{
	return m_fW;
}

//*****************************************************************************
//	GetCoordinates
//*****************************************************************************
//
//! \brief		Returns the vector's coordinates for look-up purposes
//! \return		The vector's coordinates
//
//*****************************************************************************
inline const float (&CEMVec4::GetCoordinates( void ) const) [4]
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
inline const float& CEMVec4::GetCoordinate( int a_iCoordinate ) const
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
inline void CEMVec4::GetX( float& a_fX ) const  
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
inline void CEMVec4::GetY( float& a_fY ) const
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
inline void CEMVec4::GetZ( float& a_fZ ) const
{
	a_fZ = m_fZ;
}

//*****************************************************************************
//	GetW
//*****************************************************************************
//
//! \brief		Retrieves the vector's w coordinate
//! \param		[out] The vector's w coordinate
//
//*****************************************************************************
inline void CEMVec4::GetW( float& a_fW ) const
{
	a_fW = m_fW;
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
inline void CEMVec4::GetCoordinate( int a_iCoordinate, float& a_fCoordinate ) const
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
inline void CEMVec4::SetX( const float& a_fX )
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
inline void CEMVec4::SetY( const float& a_fY )
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
inline void CEMVec4::SetZ( const float& a_fZ )
{
	m_fZ = a_fZ;
}

//*****************************************************************************
//	SetW
//*****************************************************************************
//
//! \brief		Sets the vector's w coordinate
//! \param		[in] The vector's w coordinate to set
//
//*****************************************************************************
inline void CEMVec4::SetW( const float& a_fW )
{
	m_fW = a_fW;
}

//*****************************************************************************
//	SetCoordinate
//*****************************************************************************
//
//! \brief		Returns the specified coordinate for modification purposes
//! \param		[in] The index of the coordinate's to set
//! \param		[in] The coordinate's value
//
//*****************************************************************************
inline void CEMVec4::SetCoordinate( int a_iCoordinate, float a_fCoordinate )
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
inline void CEMVec4::SetVector( float a_fCoordinates )
{
	SetCoordinates( a_fCoordinates, a_fCoordinates, a_fCoordinates, a_fCoordinates );
}

//*****************************************************************************
//	SetVector
//*****************************************************************************
//
//! \brief		Sets the vector's coordinates
//! \param		[in] The vector's coordinates to set
//
//*****************************************************************************
inline void CEMVec4::SetVector( float a_fX, float a_fY, float a_fZ, float a_fW )
{
	SetCoordinates( a_fX, a_fY, a_fZ, a_fW );
}

//*****************************************************************************
//	Transform
//*****************************************************************************
//
//! \brief		Transforms the vector by the specified matrix (matrix multiplication). 
//!				The vector4 is treated as a 4-dimensional vector whose last element is 
//!				considered to be 1.0.
//! \param		[in] The matrix to transform by
//
//*****************************************************************************
inline void CEMVec4::Transform( const CEMMat4x4& a_matTransform )
{
	SetVector( GetTransformed( a_matTransform ) );
}

//*****************************************************************************
//	InvScale
//*****************************************************************************
//
//! \brief		Scales the vector by the inverse of the specified factor (outer/scalar product)
//! \param		[in] The factor to scale by
//
//*****************************************************************************
inline void CEMVec4::InvScale( float a_fScalar )
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
inline void CEMVec4::InvTransform( const CEMMat4x4& a_matTransform )
{
	SetVector( GetInvTransformed( a_matTransform ) );
}

//*****************************************************************************
//	DotProduct
//*****************************************************************************
//
//! \brief		Returns the outer/dot product of the specified vector4s
//! \param		[in] A vector4
//! \param		[in] A vector4
//! \return		The dot product
//
//*****************************************************************************
inline float CEMVec4::DotProduct( const CEMVec4& a_vecFactorA, const CEMVec4& a_vecFactorB )
{
	return a_vecFactorA.GetDotProduct( a_vecFactorB );
}

//*****************************************************************************
//	GetMagnitude
//*****************************************************************************
//
//! \brief		Returns the vector's magnitude (length)
//! \return		The vector's magnitude
//
//*****************************************************************************
inline float CEMVec4::GetMagnitude( void ) const			
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
inline float CEMVec4::GetSquareMagnitude( void ) const			
{
	return ( m_fX * m_fX + m_fY * m_fY + m_fZ * m_fZ + m_fW * m_fW );
}

//*****************************************************************************
//	GetDotProduct
//*****************************************************************************
//
//! \brief		Returns the outer/dot product of this vector4 and the specified vector4
//! \param		[in] The factor to multiply by
//! \return		The dot product
//
//*****************************************************************************
inline float CEMVec4::GetDotProduct( const CEMVec4& a_vecFactor ) const			
{
	return	( m_fX * a_vecFactor.m_fX 
			+ m_fY * a_vecFactor.m_fY 
			+ m_fZ * a_vecFactor.m_fZ 
			+ m_fW * a_vecFactor.m_fW );
}

//*****************************************************************************
//	operator -
//*****************************************************************************
//
//! \brief		Neg operator
//! \return		The inverted vector4
//
//*****************************************************************************
inline CEMVec4 CEMVec4::operator - () const
{	
	return GetInverted();
}

//*****************************************************************************
//	operator +
//*****************************************************************************
//
//! \brief		Add operator
//! \param		[in] The vector4 to translate by
//! \return		The translated vector4
//
//*****************************************************************************
inline CEMVec4 CEMVec4::operator + ( const CEMVec4& a_vecTranslate ) const
{
	return GetTranslated( a_vecTranslate );
}

//*****************************************************************************
//	operator -
//*****************************************************************************
//
//! \brief		Sub operator
//! \param		[in] The vector4 to translate by
//! \return		The translated vector4
//
//*****************************************************************************
inline CEMVec4 CEMVec4::operator - ( const CEMVec4& a_vecTranslate ) const
{	
	return GetInvTranslated( a_vecTranslate );
}

//*****************************************************************************
//	operator *
//*****************************************************************************
//
//! \brief		Mul operator
//! \param		[in] The factor to scale by
//! \return		The scaled vector4
//
//*****************************************************************************
inline CEMVec4 CEMVec4::operator * ( float a_fScale ) const
{
	return GetScaled( a_fScale );
}

//*****************************************************************************
//	operator /
//*****************************************************************************
//
//! \brief		Div operator
//! \param		[in] The factor to scale by 
//! \return		The scaled vector4
//
//*****************************************************************************
inline CEMVec4 CEMVec4::operator / ( float a_fScale ) const
{
	return GetInvScaled( a_fScale );
}

//*****************************************************************************
//	operator *
//*****************************************************************************
//
//! \brief		Mul operator
//! \param		[in] The matrix to transform by
//! \return		The transformed vector4
//
//*****************************************************************************
inline CEMVec4 CEMVec4::operator * ( const CEMMat4x4& a_matTransform ) const
{
	return GetTransformed( a_matTransform );
}

//*****************************************************************************
//	operator /
//*****************************************************************************
//
//! \brief		Div operator
//! \param		[in] The matrix to transform by 
//! \return		The transformed vector4
//
//*****************************************************************************
inline CEMVec4 CEMVec4::operator / ( const CEMMat4x4& a_matTransform ) const
{
	return GetInvTransformed( a_matTransform );
}

//*****************************************************************************
//	operator *
//*****************************************************************************
//
//! \brief		Mul operator
//! \param		[in] The factor to scale by
//! \return		The scaled vector4
//
//*****************************************************************************
inline CEMVec4 operator * ( float a_fScale, const CEMVec4& a_vecSource )
{
	return ( a_vecSource * a_fScale );
}

//*****************************************************************************
//	operator ==
//*****************************************************************************
//
//! \brief		Comparison operator
//! \param		[in] The vector4 to compare to
//! \return		The method returns either of the following values
//! \retval		true	| The vector4s are identical
//! \retval		false	| The vector4s differ
//
//*****************************************************************************
inline bool CEMVec4::operator == ( const CEMVec4& a_vecOther ) const
{
	return IsEqual( a_vecOther );
}

//*****************************************************************************
//	operator !=
//*****************************************************************************
//
//! \brief		Comparison operator
//! \param		[in] The vector4 to compare to
//! \return		The method returns either of the following values
//! \retval		true	| The vector4s differ
//! \retval		false	| The vector4s are identical
//
//*****************************************************************************
inline bool CEMVec4::operator != ( const CEMVec4& a_vecOther ) const
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
inline const float& CEMVec4::operator [] ( int a_iIndex ) const 
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
inline float& CEMVec4::operator [] ( int a_iIndex ) 
{
	return AccessCoordinate( a_iIndex );
}

//*************************************************************************************************
//*************************************************************************************************
//*************************************************************************************************

#endif	// CEMVec4_H_INCLUDED
