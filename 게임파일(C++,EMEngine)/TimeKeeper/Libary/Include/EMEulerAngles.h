#ifndef			CEMEulerAngles_H_INCLUDED
#define			CEMEulerAngles_H_INCLUDED

#ifdef			_MSC_VER
#if				_MSC_VER > 1000
#pragma once
#endif 
#endif 

#include		"EMVec3.h"

class			CEMMat3x3			;
class			CEMAxisAngle			;
class			CEMQuaternion			;
class			CEMSphericalRotation	;

//*************************************************************************************************
//*************************************************************************************************
//*************************************************************************************************

//*****************************************************************************
//	CEMEulerAngles
//*****************************************************************************
//
//!	Representation of Euler angles
//
//! Definition: in GLOBAL coordinates, rotate by m_fRoll around
//! the z-axis, then by m_fPitch around the x-axis and finally by
//! m_fYaw around the y-axis (or the inverse order in local coordinates)
//
//*****************************************************************************
class CEMEulerAngles 
{

protected:

	// Attribs

	float	m_fYaw;		//!< Yaw angle	( heading; direction the local z-axis points to in the global z-x-plane)
	float	m_fPitch;	//!< Pitch angle ( elevation; determines the projection of the local z-Axis onto the global y-axis; positive values push the z-axis down. )
	float	m_fRoll;	//!< Roll angle  ( determines rotation around the local z-axis )

public:

	// Con-/Destruction

			 CEMEulerAngles	(		float			a_fYaw
							,		float			a_fPitch
							,		float			a_fRoll			);							
	explicit CEMEulerAngles	( const	CEMQuaternion&	a_quatRotation	);							
	explicit CEMEulerAngles	( const	CEMAxisAngle&		a_Rotation		);							
			 CEMEulerAngles	( const	CEMEulerAngles&	a_Source		);							
			 CEMEulerAngles	();																	
			~CEMEulerAngles	();																	

	// Get/Set

			float&			AccessYaw		( void )											;
			float&			AccessPitch		( void )											;
			float&			AccessRoll		( void )											;
																						
			float			GetYaw			( void )									const	;
			float			GetPitch		( void )									const	;
			float			GetRoll			( void )									const	;
																						
			void			GetYaw			(		float&			a_fYaw			)	const	;
			void			GetPitch		(		float&			a_fPitch		)	const	;
			void			GetRoll			(		float&			a_fRoll			)	const	;
																						
			void			SetYaw			(		float			a_fYaw			)			;
			void			SetPitch		(		float			a_fPitch		)			;
			void			SetRoll			(		float			a_fRoll			)			;
																						
			void			SetEulerAngles	(		float			a_fYaw				
											,		float			a_fPitch			
											,		float			a_fRoll			)			;
			void			SetEulerAngles	( const CEMQuaternion&	a_quatRotation	)			;
			void			SetEulerAngles	( const CEMAxisAngle&		a_Rotation		)			;
			void			SetEulerAngles	( const CEMMat4x4&		a_matRotation	)			;
			void			SetEulerAngles	( const CEMEulerAngles&	a_Source		)			;
																								
	// Modification

			void			Clear			( void )											;

	// Computations

			CEMQuaternion		GetQuaternion	( void )									const	;
			CEMAxisAngle		GetAxisAngle	( void )									const	;
																																
	// Operators

			bool			operator ==		( const CEMEulerAngles&	a_Other			)	const	;
			bool			operator !=		( const CEMEulerAngles&	a_Other			)	const	;

			CEMEulerAngles&	operator =		( const CEMEulerAngles&	a_Source		)			;
			CEMEulerAngles&	operator =		( const CEMQuaternion&	a_quatRotation	)			;
			CEMEulerAngles&	operator =		( const CEMAxisAngle&		a_Source		)			;
			CEMEulerAngles&	operator =		( const CEMMat4x4&		a_Source		)			;
																			
			CEMEulerAngles&	operator +=		( const CEMEulerAngles&	a_Rotation		)			;
			CEMEulerAngles&	operator -=		( const CEMEulerAngles&	a_Rotation		)			;
			CEMEulerAngles&	operator *=		(		float			a_fScale		)			;
																						
	const	CEMEulerAngles	operator -		( void )									const	;
	const	CEMEulerAngles	operator +		( const CEMEulerAngles&	a_Rotation		)	const	;
	const	CEMEulerAngles	operator -		( const CEMEulerAngles&	a_Rotation		)	const	;
	const	CEMEulerAngles	operator *		(		float			a_fScale		)	const	;
	friend const CEMEulerAngles	operator  *	(		float			a_fScale		,
											  const CEMEulerAngles&	a_quatSource	)			;
																								
			float&			operator []		(		int				a_iIndex		)			;
			float			operator []		(		int				a_iIndex		)	const	;

};

//*************************************************************************************************
//*************************************************************************************************
//*************************************************************************************************

//*****************************************************************************
//	AccessYaw
//*****************************************************************************
//
//! \brief	Returns the yaw angle for modification purposes
//! \return	The yaw angle
//
//*****************************************************************************
inline float& CEMEulerAngles::AccessYaw( void )
{
	return m_fYaw;
}

//*****************************************************************************
//	AccessPitch
//*****************************************************************************
//
//! \brief	Returns the pitch angle for modification purposes
//! \return	The pitch angle
//
//*****************************************************************************
inline float& CEMEulerAngles::AccessPitch( void )
{
	return m_fPitch;
}

//*****************************************************************************
//	AccessRoll
//*****************************************************************************
//
//! \brief	Returns the roll angle for modification purposes
//! \return	The roll angle
//
//*****************************************************************************
inline float& CEMEulerAngles::AccessRoll( void )
{
	return m_fRoll;
}

//*****************************************************************************
//	GetYaw
//*****************************************************************************
//
//! \brief	Returns the yaw angle for look-up purposes
//! \return	The yaw angle
//
//*****************************************************************************
inline float CEMEulerAngles::GetYaw( void ) const			
{
	return m_fYaw;
}

//*****************************************************************************
//	GetPitch
//*****************************************************************************
//
//! \brief	Returns the pitch angle for look-up purposes
//! \return	The pitch angle
//
//*****************************************************************************
inline float CEMEulerAngles::GetPitch( void ) const			
{
	return m_fPitch;
}

//*****************************************************************************
//	GetRoll
//*****************************************************************************
//
//! \brief	Returns the roll angle for look-up purposes
//! \return	The roll angle
//
//*****************************************************************************
inline float CEMEulerAngles::GetRoll( void ) const			
{
	return m_fRoll;
}

//*****************************************************************************
//	GetYaw
//*****************************************************************************
//
//! \brief	Retrieves the yaw angle
//! \param	[out] The yaw angle
//
//*****************************************************************************
inline void CEMEulerAngles::GetYaw( float& a_fYaw ) const
{
	a_fYaw = m_fYaw;
}

//*****************************************************************************
//	GetPitch
//*****************************************************************************
//
//! \brief	Retrieves the pitch angle
//! \param	[out] The pitch angle
//
//*****************************************************************************
inline void CEMEulerAngles::GetPitch( float& a_fPitch ) const
{
	a_fPitch = m_fPitch;
}

//*****************************************************************************
//	GetRoll
//*****************************************************************************
//
//! \brief	Retrieves the roll angle
//! \param	[out] The roll angle
//
//*****************************************************************************
inline void CEMEulerAngles::GetRoll( float& a_fRoll ) const
{
	a_fRoll = m_fRoll;
}

//*****************************************************************************
//	SetYaw
//*****************************************************************************
//
//! \brief	Sets the yaw angle
//! \param	[in] The yaw angle to set
//
//*****************************************************************************
inline void CEMEulerAngles::SetYaw( float a_fYaw )
{
	m_fYaw = a_fYaw;
}

//*****************************************************************************
//	SetPitch
//*****************************************************************************
//
//! \brief	Sets the pitch angle
//! \param	[in] The pitch angle to set
//
//*****************************************************************************
inline void CEMEulerAngles::SetPitch( float a_fPitch )
{
	m_fPitch = a_fPitch;
}

//*****************************************************************************
//	SetRoll
//*****************************************************************************
//
//! \brief	Sets the roll angle
//! \param	[in] The roll angle to set
//
//*****************************************************************************
inline void CEMEulerAngles::SetRoll( float a_fRoll )
{
	m_fRoll = a_fRoll;
}

//*****************************************************************************
//	operator -
//*****************************************************************************
//
//! \brief	Sub operator
//! \return	The negative Euler angle
//
//*****************************************************************************
inline const CEMEulerAngles CEMEulerAngles::operator - ( void ) const
{
	return CEMEulerAngles(	- m_fYaw   ,
							- m_fPitch ,
							- m_fRoll  );
}

//*****************************************************************************
//	operator +
//*****************************************************************************
//
//! \brief	Add operator
//! \return	The result of the addition
//
//*****************************************************************************
inline const CEMEulerAngles CEMEulerAngles::operator + ( const CEMEulerAngles& a_Rotation ) const
{
	return CEMEulerAngles(	m_fYaw   + a_Rotation.m_fYaw  ,
							m_fPitch + a_Rotation.m_fPitch,
							m_fRoll  + a_Rotation.m_fRoll );
}

//*****************************************************************************
//	operator -
//*****************************************************************************
//
//! \brief	Sub operator
//! \return	The result of the subtraction
//
//*****************************************************************************
inline const CEMEulerAngles CEMEulerAngles::operator - ( const CEMEulerAngles& a_Rotation ) const
{
	return CEMEulerAngles(	m_fYaw   - a_Rotation.m_fYaw  ,
							m_fPitch - a_Rotation.m_fPitch,
							m_fRoll  - a_Rotation.m_fRoll );
}

//*****************************************************************************
//	operator -
//*****************************************************************************
//
//! \brief	Sub operator
//! \return	The result of the multiplication
//
//*****************************************************************************
inline const CEMEulerAngles CEMEulerAngles::operator * ( float a_fScale	 ) const
{
	return CEMEulerAngles(	m_fYaw   * a_fScale,
							m_fPitch * a_fScale,
							m_fRoll  * a_fScale );
}

//*****************************************************************************
//	operator *
//*****************************************************************************
//
//! \brief	Mul operator
//! \return	The result of the multiplication
//
//*****************************************************************************
inline const CEMEulerAngles operator * ( float a_fFactor, const CEMEulerAngles& a_Factor )
{
	return a_Factor * a_fFactor;
}

//*****************************************************************************
//	operator []
//*****************************************************************************
//
//! \brief	Subscription operator
//! \return	A reference to an angle by index
//
//*****************************************************************************
inline float& CEMEulerAngles::operator [] ( int a_iIndex )
{
	return ((CEMVec3&) (*this))[ a_iIndex ];
}

//*****************************************************************************
//	operator []
//*****************************************************************************
//
//! \brief	Subscription operator
//! \return	An angle by index
//
//*****************************************************************************
inline float CEMEulerAngles::operator [] ( int a_iIndex ) const
{
	return ((CEMVec3&) (*this))[ a_iIndex ];
}

//*************************************************************************************************
//*************************************************************************************************
//*************************************************************************************************

#endif	// CEMEulerAngles_H_INCLUDED
