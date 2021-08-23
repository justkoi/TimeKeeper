#ifndef			CEMAxisAngle_H_INCLUDED
#define			CEMAxisAngle_H_INCLUDED

#ifdef			_MSC_VER
#if				_MSC_VER > 1000
#pragma once
#endif 
#endif 

#include		"EMVec3.h"

class			CEMMat3x3;
class			CEMEulerAngles;
class			CEMQuaternion;
class			CEMSphericalRotation;

//*************************************************************************************************
//*************************************************************************************************
//*************************************************************************************************

//*****************************************************************************
//	CEMAxisAngle
//*****************************************************************************
//
//!	Representation of a rotation by an angle along an axis 
//
//*****************************************************************************
class CEMAxisAngle
{

protected:

	// Attribs

	CEMVec3	m_vecAxis	;	//!< Rotation's axis
	float		m_fAngle	;	//!< Rotation's angle

public:

	// Con-/Destruction

			 CEMAxisAngle	( const CEMVec3&		a_vecAxis
						,		float			a_fAngle		);									
	explicit CEMAxisAngle	( const CEMQuaternion&	a_quatRotation	);									
	explicit CEMAxisAngle	( const CEMEulerAngles&	a_Rotation		);									
			 CEMAxisAngle	( const CEMAxisAngle&		a_Source		);									
			 CEMAxisAngle	();																			
			~CEMAxisAngle	();																			

	// Get/Set

			CEMVec3&		AccessAxis		( void )											;	
			float&			AccessAngle		( void )											;	
																						
	const	CEMVec3&		GetAxis			( void )									const	;	
			float			GetAngle		( void )									const	;	
																						
			void			GetAxis			(		CEMVec3&		a_vecAxis		)	const	;	
			void			GetAngle		(		float&			a_fAngle		)	const	;	
																						
			void			SetAxis			( const CEMVec3&		a_vecAxis		)			;	
			void			SetAngle		(		float			a_fAngle		)			;	
																						
			void			SetAxisAngle	( const CEMVec3&		a_vecAxis
											,		float			a_fAngle		)			;	
			void			SetAxisAngle	( const CEMQuaternion&	a_quatRotation	)			;	
			void			SetAxisAngle	( const CEMEulerAngles&	a_Rotation		)			;	
			void			SetAxisAngle	( const CEMAxisAngle&		a_Source		)			;	

	// Modification

			void			Clear			( void )											;	

	// Computations

			bool			IsEqual			( const	CEMAxisAngle&		a_Rotation		)	const	;	
																						
			CEMQuaternion		GetQuaternion	( void )									const	;	
			CEMEulerAngles	GetEulerAngles	( void )									const	;	

	// Operators

			bool			operator ==		( const	CEMAxisAngle&		a_Rotation		)	const	;	
			bool			operator !=		( const CEMAxisAngle&		a_Rotation		)	const	;	
			CEMAxisAngle&		operator =		( const CEMAxisAngle&		a_Rotation		)			;	
			CEMAxisAngle&		operator =		( const CEMQuaternion&	a_quatRotation	)			;	
			CEMAxisAngle&		operator =		( const CEMEulerAngles&	a_Rotation		)			;	

};																															

//*************************************************************************************************
//*************************************************************************************************
//*************************************************************************************************

#include	"EMQuaternion.h"

//*****************************************************************************
//	AccessAxis
//*****************************************************************************
//
//! \brief	Returns the rotation's axis for modification purposes
//! \return	The rotation's axis
//
//*****************************************************************************
inline CEMVec3& CEMAxisAngle::AccessAxis( void )
{
	return m_vecAxis;
}

//*****************************************************************************
//	AccessAngle
//*****************************************************************************
//
//! \brief	Returns the rotation's angle for modification purposes
//! \return	The rotation's angle
//
//*****************************************************************************
inline float& CEMAxisAngle::AccessAngle( void )
{
	return m_fAngle;
}

//*****************************************************************************
//	GetAxis
//*****************************************************************************
//
//! \brief	Returns the rotation's axis for look-up purposes
//! \return	The rotation's axis
//
//*****************************************************************************
inline const CEMVec3& CEMAxisAngle::GetAxis( void ) const			
{
	return m_vecAxis;
}

//*****************************************************************************
//	GetAngle
//*****************************************************************************
//
//! \brief	Returns the rotation's angle for look-up purposes
//! \return	The rotation's angle
//
//*****************************************************************************
inline float CEMAxisAngle::GetAngle( void ) const			
{
	return m_fAngle;
}

//*****************************************************************************
//	GetAxis
//*****************************************************************************
//
//! \brief	Retrieves the rotation's axis
//! \param	[out] The rotation's axis
//
//*****************************************************************************
inline void CEMAxisAngle::GetAxis( CEMVec3& a_vecAxis ) const
{
	a_vecAxis = m_vecAxis;
}

//*****************************************************************************
//	GetAngle
//*****************************************************************************
//
//! \brief	Retrieves the rotation's angle
//! \param	[out] The rotation's angle
//
//*****************************************************************************
inline void CEMAxisAngle::GetAngle( float& a_fAngle ) const
{
	a_fAngle = m_fAngle;
}

//*****************************************************************************
//	SetAxis
//*****************************************************************************
//
//! \brief	Sets the rotation's axis
//! \param	[in] The rotation's axis to set
//
//*****************************************************************************
inline void CEMAxisAngle::SetAxis( const CEMVec3& a_vecAxis )
{
	m_vecAxis = a_vecAxis;
}

//*****************************************************************************
//	SetAngle
//*****************************************************************************
//
//! \brief	Sets the rotation's angle
//! \param	[in] The rotation's angle to set
//
//*****************************************************************************
inline void CEMAxisAngle::SetAngle( float a_fAngle )
{
	m_fAngle = a_fAngle;
}

//*****************************************************************************
//	SetAxisAngle
//*****************************************************************************
//
//! \brief	Sets the rotation's axis and angle
//! \param	[in] The euler angles to set
//
//*****************************************************************************
inline void CEMAxisAngle::SetAxisAngle( const CEMEulerAngles& a_Rotation ) 
{
	SetAxisAngle( CEMQuaternion( a_Rotation ) );
}

//*****************************************************************************
//	SetAxisAngle
//*****************************************************************************
//
//! \brief	Sets the rotation's axis and angle
//! \param	[in] The axis and angle to copy
//
//*****************************************************************************
inline void CEMAxisAngle::SetAxisAngle( const CEMAxisAngle& a_Source ) 
{
	m_vecAxis = a_Source.GetAxis();
}

//*****************************************************************************
//	operator == 
//*****************************************************************************
//
//! \brief	Determines whether the axis and angle equals the specified axis and angle
//! \param	[in] A reference to an axisangle to compare to
//! \return	Returns true, if both axis and angles are equal, either false
//
//*****************************************************************************
inline bool CEMAxisAngle::operator == ( const CEMAxisAngle& a_Rotation ) const
{
	return IsEqual( a_Rotation );
}

//*****************************************************************************
//	operator != 
//*****************************************************************************
//
//! \brief	Determines whether the axis and angle differs from the specified axis and angle
//! \param	[in] A reference to an axisangle to compare to
//! \return	Returns false, if both axis and angles are equal, either true
//
//*****************************************************************************
inline bool CEMAxisAngle::operator != ( const CEMAxisAngle& a_Rotation ) const
{
	return ! (IsEqual( a_Rotation ) ); 
}

//*************************************************************************************************
//*************************************************************************************************
//*************************************************************************************************

#endif	// CEMAxisAngle_H_INCLUDED
