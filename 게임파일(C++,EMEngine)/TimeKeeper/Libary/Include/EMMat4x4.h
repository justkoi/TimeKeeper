#ifndef			CEMMat4x4_H_INCLUDED
#define			CEMMat4x4_H_INCLUDED

#ifdef			_MSC_VER
#if				_MSC_VER > 1000
#pragma once
#endif 
#endif 

#include		"EMMathBase.h"
#include		"EMVec3.h"
#include		"EMVec4.h"
#include		"EMAxisAngle.h"
#include		"EMEulerAngles.h"
#include		"EMSphericalRotation.h"
#include		"EMQuaternion.h"
#include		"EMMat3x3.h"

//*************************************************************************************************
//*************************************************************************************************
//*************************************************************************************************

//*****************************************************************************
//	CEMMat4x4
//*****************************************************************************
//
//!	Representation of a 4x4 matrix
//
//*****************************************************************************
class CEMMat4x4
{

public:

	// Enums

	enum	ERow											//! Matrix' row indices
	{
		ERow_RotationAxisX								,	//!< Row containing x axis rotation scalars
		ERow_RotationAxisY								,	//!< Row containing y axis rotation scalars
		ERow_RotationAxisZ								,	//!< Row containing z axis rotation scalars
		ERow_Translation								,	//!< Row containing translation
		ERow_Count										,	//!< The number of rows
		ERow_Min				= ERow_RotationAxisX	,	//!< The first row
		ERow_Max				= ERow_Translation		,	//!< The last row
		ERow_ForceDWORD			= FORCE_DWORD				//!< Forces all compilers to reserve 32 bits for the enumeration
	};																	

	enum	EColumn											//! Matrix' column indices
	{
		EColumn_X									,		//!< Column containing x coordinate scalars / offsets
		EColumn_Y									,		//!< Column containing y coordinate scalars / offsets
		EColumn_Z									,		//!< Column containing z coordinate scalars / offsets
		EColumn_Reserved							,		//!< Column containing reserved values
		EColumn_Count								,		//!< The number of columns
		EColumn_Min				= EColumn_X			,		//!< The first column
		EColumn_Max				= EColumn_Reserved	,		//!< The last column
		EColumn_ForceDWORD		= FORCE_DWORD				//!< Forces all compilers to reserve 32 bits for the enumeration
	};																	

	enum	EElement										//! Matrix' element indices
	{
		EElement_11								,			//!< x axis rotation scalar for x coordinate 
		EElement_12								,			//!< x axis rotation scalar for y coordinate 
		EElement_13								,			//!< x axis rotation scalar for z coordinate 
		EElement_14								,			//!< reserved (must be set to 0.0f for multiplication to work properly) 
		EElement_21								,			//!< y axis rotation scalar for x coordinate 
		EElement_22								,			//!< y axis rotation scalar for y coordinate 
		EElement_23								,			//!< y axis rotation scalar for z coordinate
		EElement_24								,			//!< reserved (must be set to 0.0f for multiplication to work properly) 
		EElement_31								,			//!< z axis rotation scalar for x coordinate  
		EElement_32								,			//!< z axis rotation scalar for y coordinate  
		EElement_33								,			//!< z axis rotation scalar for z coordinate 
		EElement_34								,			//!< reserved (must be set to 0.0f for multiplication to work properly)
		EElement_41								,			//!< x axis translation offset (position)
		EElement_42								,			//!< y axis translation offset (position)
		EElement_43								,			//!< z axis translation offset (position)
		EElement_44								,			//!< reserved (must be set to 1.0f for multiplication to work properly)
		EElement_Count							,			//!< The number of elements
		EElement_Min			= EElement_11	,			//!< The first element
		EElement_Max			= EElement_44	,			//!< The last element
		EElement_ForceDWORD		= FORCE_DWORD				//!< Forces all compilers to reserve 32 bits for the enumeration
	};																																								

protected:

	// Attribs

	union
	{
		float	m_pfElements [ EElement_Count ];				//!< Matrix' elements 
		float	m_pfRowColumn[ ERow_Count ][ EColumn_Count ];	//!< Matrix' elements split into row and column
	};																																

	// Get/Set

			CEMVec3&	AccessRow				(		int				a_iRow		)														;
			CEMVec4&	AccessRow4				(		int				a_iRow		)														;
	const	CEMVec3&	GetRow					(		int				a_iRow		)												const	;
	const	CEMVec4&	GetRow4					(		int				a_iRow		)												const	;
			CEMVec3	GetColumn				(		int				a_iColumn	)												const	;
			CEMVec4	GetColumn4				(		int				a_iColumn	)												const	;

			void		GetRow					(		int				a_iRow 														
												,		CEMVec3&		a_vecRow										)			const	;
			void		GetRow					(		int				a_iRow 														
												,		CEMVec4&		a_vecRow										)			const	;
			void		GetColumn				(		int				a_iColumn 													
												,		CEMVec3&		a_vecColumn										)			const	;
			void		GetColumn				(		int				a_iColumn 													
												,		CEMVec4&		a_vecColumn										)			const	;

	// Modification

			void		ValidateReserved		( void )																					;
			void		InvertExcentric			( void )																					;
			CEMMat4x4	GetInvertedExcentric	( void )																			const	;
			void		GetInvertedExcentric	(		CEMMat4x4&		a_matInverted	)											const	;

public:																																		

	// Con-/Destruction

			 CEMMat4x4(	const	CEMAxisAngle&		a_Rotation		, const CEMVec3&	a_vecTranslation	)									;
			 CEMMat4x4(	const	CEMEulerAngles&	a_Rotation		, const CEMVec3&	a_vecTranslation	)									;
			 CEMMat4x4(	const	CEMQuaternion&	a_quatRotation	, const CEMVec3&	a_vecTranslation	)									;
	explicit CEMMat4x4(	const	float			a_pfElements	[ EElement_Count ]						)									;
	explicit CEMMat4x4(	const	float			a_pfRowColumn	[ ERow_Count ][ EColumn_Count ]			)									;
	explicit CEMMat4x4(	const	CEMVec4	    a_pvecRows		[ ERow_Count ]							)									;
	explicit CEMMat4x4(	const	CEMVec3	    a_pvecRows		[ ERow_Count ]							)									;
	explicit CEMMat4x4(			float			a_fElements	)																				;
			 CEMMat4x4(	const	CEMMat4x4&		a_matSource )																				;
			 CEMMat4x4()																														;
			~CEMMat4x4()																														;

	// Get/Set

			float&	AccessElement				(		int				a_iRow														
												,		int				a_iColumn	)														;
			float&	AccessElement				(		int				a_iElement	)														;
			CEMVec3&	AccessXAxis				( void )																					;
			CEMVec4&	AccessXAxis4			( void )																					;
			CEMVec3&	AccessYAxis				( void )																					;
			CEMVec4&	AccessYAxis4			( void )																					;
			CEMVec3&	AccessZAxis				( void )																					;
			CEMVec4&	AccessZAxis4			( void )																					;
			CEMVec3&	AccessTranslation		( void )																					;
			CEMVec4&	AccessTranslation4		( void )																					;
																																	
			float		GetElement				(		int				a_iRow														
												,		int				a_iColumn	)												const	;
			float		GetElement				(		int				a_iElement	)												const	;
	const	CEMVec3&	GetXAxis				( void )																			const	;
	const	CEMVec4&	GetXAxis4				( void )																			const	;
	const	CEMVec3&	GetYAxis				( void )																			const	;
	const	CEMVec4&	GetYAxis4				( void )																			const	;
	const	CEMVec3&	GetZAxis				( void )																			const	;
	const	CEMVec4&	GetZAxis4				( void )																			const	;
	const	CEMVec3&	GetTranslation			( void )																			const	;
	const	CEMVec4&	GetTranslation4			( void )																			const	;
			CEMMat4x4	GetRotation				( void )																			const	;
			CEMMat3x3	GetRotation3			( void )																			const	;
																																	
			void		GetElement				(		int				a_iRow														
												,		int				a_iComumn													
												,		float&			a_fElement										)			const	;
			void		GetElement				(		int				a_iElement													
												,		float&			a_fElement										)			const	;
			void		GetRow					(		int				a_iRow 														
												,		float			a_pfRow				[ EColumn_Count ]			)			const	;
			void		GetColumn				(		int				a_iColumn 													
												,		float			a_pfColumn			[ ERow_Count ]				)			const	;								
			void		GetXAxis				(		CEMVec3&		a_vecAxisX										)			const	;
			void		GetXAxis				(		CEMVec4&		a_vecAxisX										)			const	;
			void		GetYAxis				(		CEMVec3&		a_vecAxisY										)			const	;
			void		GetYAxis				(		CEMVec4&		a_vecAxisY										)			const	;
			void		GetZAxis				(		CEMVec3&		a_vecAxisZ										)			const	;
			void		GetZAxis				(		CEMVec4&		a_vecAxisZ										)			const	;
			void		GetTranslation			(		CEMVec3&		a_vecTranslation								)			const	;
			void		GetTranslation			(		CEMVec4&		a_vecTranslation								)			const	;
			void		GetRotation				(		CEMMat4x4&		a_matRotation									)			const	;
			void		GetRotation				(		CEMMat3x3&		a_matRotation									)			const	;
																																	
			void		SetIdentityRotation		( void )																					;
			void		SetIdentity				( void )																					;
			void		SetElement				(		int				a_iElement													
												,		int				a_iColumn													
												,		float			a_fElement										)					;
			void		SetElement				(		int				a_iElement													
												,		float			a_fElement										)					;
			void		SetRow					(		int				a_iRow 														
												, const	CEMVec3&		a_vecRow										)					;
			void		SetRow					(		int				a_iRow 														
												, const	CEMVec4&		a_vecRow										)					;
			void		SetRow					(		int				a_iRow														
												, const	float			a_pfRow				[ EColumn_Count ]			)					;
			void		ModifyXAxis				( const	CEMVec3&		a_vecAxisX										)					;
			void		ModifyXAxis				( const	CEMVec4&		a_vecAxisX										)					;
			void		ModifyYAxis				( const	CEMVec3&		a_vecAxisY										)					;
			void		ModifyYAxis				( const	CEMVec4&		a_vecAxisY										)					;
			void		ModifyZAxis				( const	CEMVec3&		a_vecAxisZ										)					;
			void		ModifyZAxis				( const	CEMVec4&		a_vecAxisZ										)					;
			void		ModifyScaling			(		float			a_fScaling										)					;
			void		ModifyScaling			( const	CEMVec3&		a_vecScaling									)					;
			void		ModifyTranslation		( const	CEMVec3&		a_vecTranslation								)					;
			void		ModifyRotation			( const	CEMQuaternion&	a_quatRotation									)					;
			void		ModifyRotation			( const	CEMMat3x3&		a_matRotation									)					;
			void		ModifyRotation			( const	CEMAxisAngle&		a_Rotation										)					;
			void		ModifyRotation			( const	CEMEulerAngles&	a_Rotation										)					;
			void		ModifyRotationAxisX		(		float			a_fAngle										)					;
			void		ModifyRotationAxisY		(		float			a_fAngle										)					;
			void		ModifyRotationAxisZ		(		float			a_fAngle										)					;
																																	
			void		SetToScaling			(		float			a_fScaling										)					;
			void		SetToScaling			( const	CEMVec3&		a_vecScaling									)					;
			void		SetToTranslation		( const	CEMVec3&		a_vecTranslation								)					;
			void		SetToRotation			( const	CEMQuaternion&	a_quatRotation									)					;
			void		SetToRotation			( const	CEMAxisAngle&		a_Rotation										)					;
			void		SetToRotation			( const	CEMEulerAngles&	a_Rotation										)					;
			void		SetToRotationAxisX		(		float			a_fAngle										)					;
			void		SetToRotationAxisY		(		float			a_fAngle										)					;
			void		SetToRotationAxisZ		(		float			a_fAngle										)					;
			void		SetToCrossProduct		( const	CEMVec3&		a_vecFactor										)					;
			void		SetToProduct			( const	CEMMat4x4&		a_matLeft															
												, const	CEMMat4x4&		a_matRight										)					;
																																	
			void		SetMatrix				( const CEMMat4x4&		a_matSource										)					;
			void		SetMatrix				(		float			a_fElements										)					;
			void		SetMatrix				( const	CEMVec3	    a_pvecRows	 [ ERow_Count ]						)					;
			void		SetMatrix				( const	CEMVec4	    a_pvecRows	 [ ERow_Count ]						)					;
			void		SetMatrix				( const	float			a_pfRowColumn[ ERow_Count ][ EColumn_Count ]	)					;
			void		SetMatrix				( const	float			a_pfElements [ EElement_Count ]					)					;

			void		SetMatrix				( const	CEMQuaternion&	a_quatRotation														
												, const CEMVec3&		a_vecTranslation								)					;
			void		SetMatrix				( const	CEMEulerAngles&	a_Rotation															
												, const CEMVec3&		a_vecTranslation								)					;
			void		SetMatrix				( const	CEMAxisAngle&		a_Rotation															
												, const CEMVec3&		a_vecTranslation								)					;
			void		SetMatrix				( const CEMVec3&		a_vecTranslation
												, const CEMQuaternion&	a_quatRotation
												, const CEMVec3&		a_vecScale										)					;
			void		SetMatrix				( const CEMVec3&		a_vecTranslation
												, const CEMEulerAngles&	a_eulerRotation
												, const CEMVec3&		a_vecScale										)					;

	// Modification

			void		Clear					( void )																					;
			void		ClearRotation			( void )																					;
			void		TransposeRotation		( void )																					;
			void		Transpose				( void )																					;
			void		Negate					( void )																					;
			void		Invert					( void )																					;
			void		Orthogonalize			( void )																					;
			void		Orthonormalize			( void )																					;
			void		Add						( const	CEMMat4x4&		a_mat			)													;
			void		Sub						( const	CEMMat4x4&		a_mat			)													;
			void		Multiply				(		float			a_fFactor		)													;
			void		Divide					(		float			a_fDivisor		)													;
			void		ReverseMultiply			( const CEMMat4x4&		a_matPrefix		)													;
			void		Multiply				( const CEMMat4x4&		a_matFactor		)													;
			void		Scale					(		float			a_fScaling		)													;
			void		Scale					( const CEMVec3&		a_vecScaling	)													;
			void		Rotate					( const	CEMQuaternion&	a_quatRotation	)													;
			void		Rotate					( const	CEMAxisAngle&		a_Rotation		)													;
			void		Rotate					( const	CEMEulerAngles&	a_Rotation		)													;
			void		RotateAxisX				(		float			a_fAngle		)													;
			void		RotateAxisY				(		float			a_fAngle		)													;
			void		RotateAxisZ				(		float			a_fAngle		)													;
			void		RotateLocal				( const	CEMQuaternion&	a_quatRotation	)													;
			void		RotateLocal				( const	CEMAxisAngle&		a_Rotation		)													;
			void		RotateLocal				( const	CEMEulerAngles&	a_Rotation		)													;
			void		RotateLocalAxisX		(		float			a_fAngle		)													;
			void		RotateLocalAxisY		(		float			a_fAngle		)													;
			void		RotateLocalAxisZ		(		float			a_fAngle		)													;
			void		LookAt					( const CEMVec3&		a_vecLookAt		)													;
			void		LookAt					( const CEMVec3&		a_vecLookAt
												, const CEMVec3&		a_vecUp			)													;

	// Computations

			bool		IsExcentric				( void )																			const	;
			bool		IsIdentity				( void )																			const	;
																																	
			bool		IsEqual					( const	CEMMat4x4&		a_matOther		)											const	;
																																	
			float		GetDeterminant			( void )																			const	;
			float		GetDeterminantRotation	( void )																			const	;
			float		GetDeterminantAdjoint	(		int				a_iRow														
												,		int				a_iColumn		)											const	;														
	static	CEMMat4x4	GetIdentity				( void )																					;
			CEMMat4x4	GetNegated				( void )																			const	;
			CEMMat4x4	GetInverted				( void )																			const	;
			CEMMat4x4	GetOrthogonalized		( void )																			const	;
			CEMMat4x4	GetOrthonormalized		( void )																			const	;
																																			
			CEMMat4x4	GetSum					( const CEMMat4x4&		a_matOffset		)											const	;
			CEMMat4x4	GetDifference			( const CEMMat4x4&		a_matOffset		)											const	;
			CEMMat4x4	GetProductPrefix		( const CEMMat4x4&		a_matPrefix		)											const	;
			CEMMat4x4	GetProduct				( const CEMMat4x4&		a_matFactor		)											const	;
			CEMMat4x4	GetProduct				(		float			a_fFactor		)											const	;
			CEMMat4x4	GetQuotient				(		float			a_fDivisor		)											const	;
			CEMMat4x4	GetRotated				( const	CEMQuaternion&	a_quatRotation	)											const	;
			CEMMat4x4	GetRotated				( const	CEMAxisAngle&		a_Rotation		)											const	;
			CEMMat4x4	GetRotated				( const	CEMEulerAngles&	a_Rotation		)											const	;
			CEMMat4x4	GetRotatedByAxisX		(		float			a_fAngle		)											const	;
			CEMMat4x4	GetRotatedByAxisY		(		float			a_fAngle		)											const	;
			CEMMat4x4	GetRotatedByAxisZ		(		float			a_fAngle		)											const	;
			CEMMat4x4	GetRotatedLocal			( const	CEMQuaternion&	a_quatRotation	)											const	;
			CEMMat4x4	GetRotatedLocal			( const	CEMAxisAngle&		a_Rotation		)											const	;
			CEMMat4x4	GetRotatedLocal			( const	CEMEulerAngles&	a_Rotation		)											const	;
			CEMMat4x4	GetRotatedByLocalAxisX	(		float			a_fAngle		)											const	;
			CEMMat4x4	GetRotatedByLocalAxisY	(		float			a_fAngle		)											const	;
			CEMMat4x4	GetRotatedByLocalAxisZ	(		float			a_fAngle		)											const	;
																																	
	static	void		GetIdentity				(		CEMMat4x4&		a_matIdentity	)													;
			void		GetNegated				(		CEMMat4x4&		a_matNegated	)											const	;
			void		GetInverted				(		CEMMat4x4&		a_matInverted	)											const	;
			void		GetOrthogonalized		(		CEMMat4x4&		a_matOrthogon	)											const	;
			void		GetOrthonormalized		(		CEMMat4x4&		a_matOrthonorm	)											const	;
																																			
			void		GetSum					(		CEMMat4x4&		a_matSum		, const CEMMat4x4&		a_matOffset		)	const	;
			void		GetDifference			(		CEMMat4x4&		a_matDifference	, const CEMMat4x4&		a_matOffset		)	const	;
			void		GetProductPrefix		(		CEMMat4x4&		a_matProduct	, const CEMMat4x4&		a_matPrefix		)	const	;
			void		GetProduct				(		CEMMat4x4&		a_matProduct	, const CEMMat4x4&		a_matFactor		)	const	;
			void		GetProduct				(		CEMMat4x4&		a_matProduct	,		float			a_fFactor		)	const	;
			void		GetQuotient				(		CEMMat4x4&		a_matQuotient	,		float			a_fDivisor		)	const	;
			void		GetRotated				(		CEMMat4x4&		a_matRotated	, const	CEMQuaternion&	a_quatRotation	)	const	;
			void		GetRotated				(		CEMMat4x4&		a_matRotated	, const	CEMAxisAngle&		a_Rotation		)	const	;
			void		GetRotated				(		CEMMat4x4&		a_matRotated	, const	CEMEulerAngles&	a_Rotation		)	const	;
			void		GetRotatedByAxisX		(		CEMMat4x4&		a_matRotated	,		float			a_fAngle		)	const	;
			void		GetRotatedByAxisY		(		CEMMat4x4&		a_matRotated	,		float			a_fAngle		)	const	;
			void		GetRotatedByAxisZ		(		CEMMat4x4&		a_matRotated	,		float			a_fAngle		)	const	;
			void		GetRotatedLocal			(		CEMMat4x4&		a_matRotated	, const	CEMQuaternion&	a_quatRotation	)	const	;
			void		GetRotatedLocal			(		CEMMat4x4&		a_matRotated	, const	CEMAxisAngle&		a_Rotation		)	const	;
			void		GetRotatedLocal			(		CEMMat4x4&		a_matRotated	, const	CEMEulerAngles&	a_Rotation		)	const	;
			void		GetRotatedByLocalAxisX	(		CEMMat4x4&		a_matRotated	,		float			a_fAngle		)	const	;
			void		GetRotatedByLocalAxisY	(		CEMMat4x4&		a_matRotated	,		float			a_fAngle		)	const	;
			void		GetRotatedByLocalAxisZ	(		CEMMat4x4&		a_matRotated	,		float			a_fAngle		)	const	;

	// Operators

			bool		operator	==			( const CEMMat4x4&		a_matOther		)											const	;
			bool		operator	!=			( const CEMMat4x4&		a_matOther		)											const	;
			CEMMat4x4&	operator	=			( const	CEMMat4x4&		a_matOther		)													;
			CEMMat4x4&	operator	+=			( const CEMMat4x4&		a_matOffset		)													;
			CEMMat4x4&	operator	-=			( const CEMMat4x4&		a_matOffset		)													;
			CEMMat4x4&	operator	*=			(		float			a_fFactor		)													;
			CEMMat4x4&	operator	/=			(		float			a_fFactor		)													;
			CEMMat4x4&	operator	*=			( const CEMMat4x4&		a_matFactor		)													;
			CEMMat4x4&	operator	*=			( const CEMAxisAngle&		a_Rotation		)													;
			CEMMat4x4&	operator	*=			( const CEMEulerAngles&	a_Rotation		)													;
			CEMMat4x4&	operator	*=			( const CEMQuaternion&	a_quatRotation	)													;
			CEMMat4x4	operator	~			( void )																			const	;
			CEMMat4x4	operator	-			( void )																			const	;
			CEMMat4x4	operator	+			( const CEMMat4x4&		a_matOffset		)											const	;
			CEMMat4x4	operator	-			( const CEMMat4x4&		a_matOffset		)											const	;
			CEMMat4x4	operator	*			(		float			a_fFactor		)											const	;
			CEMMat4x4	operator	/			(		float			a_fFactor		)											const	;
			CEMMat4x4	operator	*			( const CEMMat4x4&		a_matFactor		)											const	;
			CEMVec3	operator	*			( const CEMVec3&		a_vec			)											const	;
			CEMMat4x4	operator	*			( const CEMAxisAngle&		a_Rotation		)											const	;
			CEMMat4x4	operator	*			( const CEMEulerAngles&	a_Rotation		)											const	;
			CEMMat4x4	operator	*			( const CEMQuaternion&	a_quatRotation	)											const	;
	friend	CEMMat4x4	operator	*			(		float			a_fFactor		, const CEMMat4x4&		a_matFactor		)			;
			float		operator	[]			(		int				a_iElement		)											const	;
			float&		operator	[]			(		int				a_iElement		)													;
	const	CEMVec3&	operator	()			(		int				a_iRow			)											const	;
			CEMVec3&	operator	()			(		int				a_iRow			)													;
			float		operator	()			(		int				a_iRow			,		int				a_iColumn		)	const	;
			float&		operator	()			(		int				a_iRow			,		int				a_iColumn		)			;

};

//*************************************************************************************************
//*************************************************************************************************
//*************************************************************************************************

#define	FOR_EACH_ROW_CEMMat4x4( iRow )					for( int iRow = ERow_Min; iRow < ERow_Count; ++iRow )		

#define	FOR_EACH_ROW_COLUMN_CEMMat4x4( iRow, iColumn )	for( int iRow = ERow_Min; iRow < ERow_Count; ++iRow )		\
														for( int iColumn  = EColumn_Min ; iColumn	< EColumn_Count	; ++iColumn )			

#define	FOR_EACH_ELEMENT_CEMMat4x4( iElement )			for( int iElement = EElement_Min; iElement < EElement_Count; ++iElement )

#define SWAP_CEMMat4x4( fSwap, iRow, iColumn )			fSwap = m_pfRowColumn[ iRow ][ iColumn ];								\
														m_pfRowColumn[ iRow ][ iColumn ] = m_pfRowColumn[ iColumn ][ iRow ];	\
														m_pfRowColumn[ iColumn ][ iRow ] = fSwap;									 

//*************************************************************************************************
//*************************************************************************************************
//*************************************************************************************************

#include	<memory>

//*****************************************************************************
//	AccessElement
//*****************************************************************************
//
//! \brief	Returns the element at the specified row and column for modification purposes
//! \param	[in] The desired element's row index
//! \param	[in] The desired element's column index
//! \return	A reference to the desired element
//
//*****************************************************************************
inline float& CEMMat4x4::AccessElement( int a_iRow, int a_iColumn ) 
{
	return m_pfRowColumn[ a_iRow ][ a_iColumn ];
}

//*****************************************************************************
//	AccessElement
//*****************************************************************************
//
//! \brief	Returns the element at the specified index for modification purposes
//! \param	[in] The desired element's index
//! \return	The element at the specified index 
//
//*****************************************************************************
inline float& CEMMat4x4::AccessElement( int a_iElement ) 
{
	return m_pfElements[ a_iElement ];
}

//*****************************************************************************
//	AccessRow
//*****************************************************************************
//
//! \brief	Returns a 3D vector representation of the specified row for modification purposes
//! \param	[in] The desired row's index 
//! \return	The vector representation of the specified row 
//
//*****************************************************************************
inline CEMVec3& CEMMat4x4::AccessRow( int a_iRow ) 
{
	return ( (CEMVec3&) ( m_pfRowColumn[ a_iRow ] [ EColumn_X ] ) );
}

//*****************************************************************************
//	AccessRow
//*****************************************************************************
//
//! \brief	Returns a 4D vector representation of the specified row for modification purposes
//! \param	[in] The desired row's index 
//! \return	The vector representation of the specified row 
//
//****************************************************************************
inline CEMVec4& CEMMat4x4::AccessRow4( int a_iRow ) 
{
	return ( (CEMVec4&) ( m_pfRowColumn[ a_iRow ] [ EColumn_X ] ) );
}

//*****************************************************************************
//	AccessXAxis
//*****************************************************************************
//
//! \brief	Returns a 3D vector representation of the matrix' rotation's x axis
//! \return	The vector representation of the matrix' rotation's x axis
//
//*****************************************************************************
inline CEMVec3& CEMMat4x4::AccessXAxis()
{
	return AccessRow( ERow_RotationAxisX );
}

//*****************************************************************************
//	AccessXAxis
//*****************************************************************************
//
//! \brief	Returns a 4D vector representation of the matrix' rotation's x axis
//! \return	The vector representation of the matrix' rotation's x axis
//
//*****************************************************************************
inline CEMVec4& CEMMat4x4::AccessXAxis4()
{
	return AccessRow4( ERow_RotationAxisX );
}

//*****************************************************************************
//	AccessYAxis
//*****************************************************************************
//
//! \brief	Returns a 3D vector representation of the matrix' rotation's y axis
//! \return	The vector representation of the matrix' rotation's y axis
//
//*****************************************************************************
inline CEMVec3& CEMMat4x4::AccessYAxis()
{
	return AccessRow( ERow_RotationAxisY );
}

//*****************************************************************************
//	AccessYAxis
//*****************************************************************************
//
//! \brief	Returns a 4D vector representation of the matrix' rotation's y axis
//! \return	The vector representation of the matrix' rotation's y axis
//
//*****************************************************************************
inline CEMVec4& CEMMat4x4::AccessYAxis4()
{
	return AccessRow4( ERow_RotationAxisY );
}

//*****************************************************************************
//	AccessZAxis
//*****************************************************************************
//
//! \brief	Returns a 3D vector representation of the matrix' rotation's z axis
//! \return	The vector representation of the matrix' rotation's z axis
//
//*****************************************************************************
inline CEMVec3& CEMMat4x4::AccessZAxis()
{
	return AccessRow( ERow_RotationAxisZ );
}

//*****************************************************************************
//	AccessZAxis
//*****************************************************************************
//
//! \brief	Returns a 4D vector representation of the matrix' rotation's z axis
//! \return	The vector representation of the matrix' rotation's z axis
//
//*****************************************************************************
inline CEMVec4& CEMMat4x4::AccessZAxis4()
{
	return AccessRow4( ERow_RotationAxisZ );
}

//*****************************************************************************
//	AccessTranslation
//*****************************************************************************
//
//! \brief	Returns a 3D vector representation of the translation offsets for modification purposes
//! \return	The vector representation of the translation offsets 
//
//*****************************************************************************
inline CEMVec3& CEMMat4x4::AccessTranslation( void ) 
{
	return AccessRow( ERow_Translation );
} 

//*****************************************************************************
//	AccessTranslation
//*****************************************************************************
//
//! \brief	Returns a 4D vector representation of the translation offsets for modification purposes
//! \return	The vector representation of the translation offsets 
//
//*****************************************************************************
inline CEMVec4& CEMMat4x4::AccessTranslation4( void ) 
{
	return AccessRow4( ERow_Translation );
} 

//*****************************************************************************
//	GetElement
//*****************************************************************************
//
//! \brief	Returns the element at the specified row and column for look-up purposes
//! \param	[in] The desired element's row index
//! \param	[in] The desired element's column index
//! \return	The element at the specified row and column 
//
//*****************************************************************************
inline float CEMMat4x4::GetElement( int a_iRow, int a_iColumn ) const 
{
	return m_pfRowColumn[ a_iRow ][ a_iColumn ];
}

//*****************************************************************************
//	GetElement
//*****************************************************************************
//
//! \brief	Returns the element at the specified index for look-up purposes
//! \param	[in] The desired element's index
//! \return	The element at the specified row and column 
//
//*****************************************************************************
inline float CEMMat4x4::GetElement( int a_iElement ) const 
{
	return m_pfElements[ a_iElement ];
}

//*****************************************************************************
//	GetRow
//*****************************************************************************
//
//! \brief	Returns a 3D vector representation of the specified row for look-up purposes
//! \param	[in] The desired row's index
//! \return	The vector representation of the specified row
//
//*****************************************************************************
inline const CEMVec3& CEMMat4x4::GetRow( int a_iRow ) const 
{
	return ( (CEMVec3&) ( m_pfRowColumn[ a_iRow ] [ EColumn_X ] ) );
}

//*****************************************************************************
//	GetRow
//*****************************************************************************
//
//! \brief	Returns a 4D vector representation of the specified row for look-up purposes
//! \param	[in] The desired row's index
//! \return	The vector representation of the specified row
//
//*****************************************************************************
inline const CEMVec4& CEMMat4x4::GetRow4( int a_iRow ) const 
{
	return ( (CEMVec4&) ( m_pfRowColumn[ a_iRow ] [ EColumn_X ] ) );
}

//*****************************************************************************
//	GetXAxis
//*****************************************************************************
//
//! \brief	Returns a 3D vector representation of the matrix' rotation's x axis
//! \return	The vector representation of the matrix' rotation's x axis
//
//*****************************************************************************
inline const CEMVec3& CEMMat4x4::GetXAxis() const 
{
	return GetRow( ERow_RotationAxisX );
}

//*****************************************************************************
//	GetXAxis
//*****************************************************************************
//
//! \brief	Returns a 4D vector representation of the matrix' rotation's x axis
//! \return	The vector representation of the matrix' rotation's x axis
//
//*****************************************************************************
inline const CEMVec4& CEMMat4x4::GetXAxis4() const 
{
	return GetRow4( ERow_RotationAxisX );
}

//*****************************************************************************
//	GetYAxis
//*****************************************************************************
//
//! \brief	Returns a 3D vector representation of the matrix' rotation's y axis
//! \return	The vector representation of the matrix' rotation's y axis
//
//*****************************************************************************
inline const CEMVec3& CEMMat4x4::GetYAxis() const 
{
	return GetRow( ERow_RotationAxisY );
}

//*****************************************************************************
//	GetYAxis
//*****************************************************************************
//
//! \brief	Returns a 4D vector representation of the matrix' rotation's y axis
//! \return	The vector representation of the matrix' rotation's y axis
//
//*****************************************************************************
inline const CEMVec4& CEMMat4x4::GetYAxis4() const 
{
	return GetRow4( ERow_RotationAxisY );
}

//*****************************************************************************
//	GetZAxis
//*****************************************************************************
//
//! \brief	Returns a 3D vector representation of the matrix' rotation's z axis
//! \return	The vector representation of the matrix' rotation's z axis
//
//*****************************************************************************
inline const CEMVec3& CEMMat4x4::GetZAxis() const 
{
	return GetRow( ERow_RotationAxisZ );
}

//*****************************************************************************
//	GetZAxis
//*****************************************************************************
//
//! \brief	Returns a 4D vector representation of the matrix' rotation's z axis
//! \return	The vector representation of the matrix' rotation's z axis
//
//*****************************************************************************
inline const CEMVec4& CEMMat4x4::GetZAxis4() const 
{
	return GetRow4( ERow_RotationAxisZ );
}

//*****************************************************************************
//	GetTranslation
//*****************************************************************************
//
//! \brief	Returns a 3D vector representation of the translation offsets for look-up purposes
//! \return	The vector representation of the translation offsets
//
//*****************************************************************************
inline const CEMVec3& CEMMat4x4::GetTranslation( void ) const 
{
	return GetRow( ERow_Translation );
} 

//*****************************************************************************
//	GetTranslation
//*****************************************************************************
//
//! \brief	Returns a 4D vector representation of the translation offsets for look-up purposes
//! \return	The vector representation of the translation offsets
//
//*****************************************************************************
inline const CEMVec4& CEMMat4x4::GetTranslation4( void ) const 
{
	return GetRow4( ERow_Translation );
} 

//*****************************************************************************
//	GetElement
//*****************************************************************************
//
//! \brief	Returns the element at the specified row and column 
//! \param	[in] The desired element's row index
//! \param	[in] The desired element's column index
//! \param	[out] The element at the specified row and column 
//
//*****************************************************************************
inline void CEMMat4x4::GetElement( int a_iRow, int a_iColumn, float& a_fElement ) const 
{
	a_fElement = GetElement( a_iRow, a_iColumn );
}

//*****************************************************************************
//	GetElement
//*****************************************************************************
//
//! \brief	Returns the element at the specified index
//! \param	[in] The desired element's index
//! \param	[out] The element at the specified index
//
//*****************************************************************************
inline void CEMMat4x4::GetElement( int a_iElement, float& a_fElement ) const 
{
	a_fElement = GetElement( a_iElement );
}

//*****************************************************************************
//	GetRow
//*****************************************************************************
//
//! \brief	Returns a vector representation of the specified row for look-up purposes
//! \param	[in] The desired row's index
//! \param	[out] The vector representation of the specified row 
//
//*****************************************************************************
inline void CEMMat4x4::GetRow( int a_iRow, CEMVec3& a_vecRow ) const 
{
	a_vecRow = GetRow( a_iRow );
}

//*****************************************************************************
//	GetRow
//*****************************************************************************
//
//! \brief	Returns a vector representation of the specified row for look-up purposes
//! \param	[in] The desired row's index
//! \param	[out] The vector representation of the specified row 
//
//*****************************************************************************
inline void CEMMat4x4::GetRow( int a_iRow, CEMVec4& a_vecRow ) const 
{
	a_vecRow = GetRow4( a_iRow );
}

//*****************************************************************************
//	GetRow
//*****************************************************************************
//
//! \brief	Returns the specified row's columns for look-up purposes
//! \param	[in] The desired row's index
//! \param	[out] The specified row's columns 
//
//*****************************************************************************
inline void CEMMat4x4::GetRow( int a_iRow, float a_pfRow [ CEMMat4x4::EColumn_Count ] ) const 
{
	memcpy(	a_pfRow							,	
			m_pfRowColumn[ a_iRow ]			,
			EColumn_Count * sizeof(float)	);
}

//*****************************************************************************
//	GetTranslation
//*****************************************************************************
//
//! \brief	Returns a vector representation of the translation for look-up purposes	
//! \return	[out] The vector representation of the translation 
//
//*****************************************************************************
inline void CEMMat4x4::GetTranslation( CEMVec3& a_vecTranslation ) const 
{
	a_vecTranslation = GetTranslation();
}

//*****************************************************************************
//	GetTranslation
//*****************************************************************************
//
//! \brief	Returns a vector representation of the translation for look-up purposes	
//! \return	[out] The vector representation of the translation 
//
//*****************************************************************************
inline void CEMMat4x4::GetTranslation( CEMVec4& a_vecTranslation ) const 
{
	a_vecTranslation = GetTranslation4();
}

//*****************************************************************************
//	GetXAxis
//*****************************************************************************
//
//! \brief	Returns the 3D vector representation of the matrix' rotation's x axis
//! \param	[out] The vector representation of the matrix' rotation's x axis
//
//*****************************************************************************
inline void CEMMat4x4::GetXAxis( CEMVec3& a_vecAxisX ) const 
{
	GetRow( ERow_RotationAxisX, a_vecAxisX );
}

//*****************************************************************************
//	GetXAxis
//*****************************************************************************
//
//! \brief	Returns the 4D vector representation of the matrix' rotation's x axis
//! \param	[out] The vector representation of the matrix' rotation's x axis
//
//*****************************************************************************
inline void CEMMat4x4::GetXAxis( CEMVec4& a_vecAxisX ) const 
{
	GetRow( ERow_RotationAxisX, a_vecAxisX );
}

//*****************************************************************************
//	 GetYAxis
//*****************************************************************************
//
//! \brief	Returns the 3D vector representation of the matrix' rotation's y axis
//! \param	[out] The vector representation of the matrix' rotation's y axis
//
//*****************************************************************************
inline void CEMMat4x4::GetYAxis( CEMVec3& a_vecAxisY ) const 
{
	GetRow( ERow_RotationAxisY, a_vecAxisY );
}

//*****************************************************************************
//	GetYAxis
//*****************************************************************************
//
//! \brief	Returns the 4D vector representation of the matrix' rotation's y axis
//! \param	[out] The vector representation of the matrix' rotation's y axis
//
//*****************************************************************************
inline void CEMMat4x4::GetYAxis( CEMVec4& a_vecAxisY ) const 
{
	GetRow( ERow_RotationAxisY, a_vecAxisY );
}

//*****************************************************************************
//	GetZAxis
//*****************************************************************************
//
//! \brief	Returns the 3D vector representation of the matrix' rotation's z axis
//! \param	[out] The vector representation of the matrix' rotation's z axis
//
//*****************************************************************************
inline void CEMMat4x4::GetZAxis( CEMVec3& a_vecAxisZ ) const 
{
	GetRow( ERow_RotationAxisZ, a_vecAxisZ );
}

//*****************************************************************************
//	GetZAxis
//*****************************************************************************
//
//! \brief	Returns the 4D vector representation of the matrix' rotation's z axis
//! \param	[out] The vector representation of the matrix' rotation's z axis
//
//*****************************************************************************
inline void CEMMat4x4::GetZAxis( CEMVec4& a_vecAxisZ ) const 
{
	GetRow( ERow_RotationAxisZ, a_vecAxisZ );
}

//*****************************************************************************
//	SetElement
//*****************************************************************************
//
//! \brief	Modifies the element at the specified row and column
//! \param	[in] The row index of the element to set
//! \param	[in] The column index of the element to set
//! \return	[in] The element's new value
//
//*****************************************************************************
inline void CEMMat4x4::SetElement( int a_iRow, int a_iColumn, float a_fElement ) 
{
	AccessElement( a_iRow, a_iColumn ) = a_fElement;
}

//*****************************************************************************
//	SetElement
//*****************************************************************************
//
//! \brief	Modifies the element at the specified index
//! \param	[in] The index of the element to set
//! \return	[in] The element's new value
//
//*****************************************************************************
inline void CEMMat4x4::SetElement( int a_iElement, float a_fElement ) 
{
	AccessElement( a_iElement ) = a_fElement;
}

//*****************************************************************************
//	SetRow
//*****************************************************************************
//
//! \brief	Modifies the specified row vector
//! \param	[in] The index of the row to set
//! \param	[in] The vector representation of the row to set
//
//*****************************************************************************
inline void CEMMat4x4::SetRow( int a_iRow, const CEMVec3& a_vecRow ) 
{
	AccessRow( a_iRow ) = a_vecRow;
}

//*****************************************************************************
//	SetRow
//*****************************************************************************
//
//! \brief	Modifies the specified row vector
//! \param	[in] The index of the row to set
//! \param	[in] The vector representation of the row to set
//
//*****************************************************************************
inline void CEMMat4x4::SetRow( int a_iRow, const CEMVec4& a_vecRow ) 
{
	AccessRow4( a_iRow ) = a_vecRow;
}

//*****************************************************************************
//	SetRow
//*****************************************************************************
//
//! \brief	Modifies the specified row's columns 
//! \param	[in] The index of the row to set
//! \param	[in] The values to set for the row
//
//*****************************************************************************
inline void CEMMat4x4::SetRow( int a_iRow, const float a_pfRow [ CEMMat4x4::EColumn_Count ] ) 
{
	memcpy(	m_pfRowColumn[ a_iRow ]			, 
			a_pfRow							, 
			EColumn_Count * sizeof(float)	);
}

//*****************************************************************************
//	ModifyXAxis
//*****************************************************************************
//
//! \brief	Modifies the matrix' rotation's x axis
//! \param	[in] The matrix' rotation's x axis
//
//*****************************************************************************
inline void CEMMat4x4::ModifyXAxis( const CEMVec3& a_vecAxisX )
{
	SetRow( ERow_RotationAxisX, a_vecAxisX );
}

//*****************************************************************************
//	ModifyXAxis
//*****************************************************************************
//
//! \brief	Modifies the matrix' rotation's x axis
//! \param	[in] The matrix' rotation's x axis
//
//*****************************************************************************
inline void CEMMat4x4::ModifyXAxis( const CEMVec4& a_vecAxisX )
{
	SetRow( ERow_RotationAxisX, a_vecAxisX );
}

//*****************************************************************************
//	ModifyYAxis
//*****************************************************************************
//
//! \brief	Modifies the matrix' rotation's y axis
//! \param	[in] The matrix' rotation's y axis
//
//*****************************************************************************
inline void CEMMat4x4::ModifyYAxis( const CEMVec3& a_vecAxisY )
{
	SetRow( ERow_RotationAxisY, a_vecAxisY );
}

//*****************************************************************************
//	ModifyYAxis
//*****************************************************************************
//
//! \brief	Modifies the matrix' rotation's y axis
//! \param	[in] The matrix' rotation's y axis
//
//*****************************************************************************
inline void CEMMat4x4::ModifyYAxis( const CEMVec4& a_vecAxisY )
{
	SetRow( ERow_RotationAxisY, a_vecAxisY );
}

//*****************************************************************************
//	ModifyZAxis
//*****************************************************************************
//
//! \brief	Modifies the matrix' rotation's z axis
//! \param	[in] The matrix' rotation's z axis
//
//*****************************************************************************
inline void CEMMat4x4::ModifyZAxis( const CEMVec3& a_vecAxisZ )
{
	SetRow( ERow_RotationAxisZ, a_vecAxisZ );
}

//*****************************************************************************
//	ModifyZAxis
//*****************************************************************************
//
//! \brief	Modifies the matrix' rotation's z axis
//! \param	[in] The matrix' rotation's z axis
//
//*****************************************************************************
inline void CEMMat4x4::ModifyZAxis( const CEMVec4& a_vecAxisZ )
{
	SetRow( ERow_RotationAxisZ, a_vecAxisZ );
}

//*****************************************************************************
//	ModifyTranslation
//*****************************************************************************
//
//! \brief	Modifies the translation offsets 
//! \param	[in] The translation to set
//
//*****************************************************************************
inline void CEMMat4x4::ModifyTranslation( const CEMVec3& a_vecTranslation )
{
	AccessTranslation() = a_vecTranslation;
}

//*****************************************************************************
//	SetMatrix
//*****************************************************************************
//
//! \brief	Copies the specified matrix
//! \param	[in] The matrix to copy
//
//*****************************************************************************
inline void CEMMat4x4::SetMatrix ( const CEMMat4x4& a_matSource ) 
{
	memcpy(	m_pfElements					,
			a_matSource.m_pfElements		,
			EElement_Count * sizeof(float)	);
}

//*****************************************************************************
//	SetMatrix
//*****************************************************************************
//
//! \brief	Copies the specified array
//! \param	[in] The array to copy
//
//*****************************************************************************
inline void CEMMat4x4::SetMatrix ( const float a_pfRowColumn [ CEMMat4x4::ERow_Count ][ CEMMat4x4::EColumn_Count ] ) 
{
	memcpy(	m_pfRowColumn								,
			a_pfRowColumn								,
			ERow_Count * EColumn_Count * sizeof(float)	);
}

//*****************************************************************************
//	SetMatrix
//*****************************************************************************
//
//! \brief	Copies the specified array
//! \param	[in] The array to copy
//
//*****************************************************************************
inline void CEMMat4x4::SetMatrix ( const float a_pfElements [ CEMMat4x4::EElement_Count ] ) 
{
	memcpy(	m_pfElements					,
			a_pfElements					,
			EElement_Count * sizeof(float)	);
}

//*****************************************************************************
//	InvertExcentric								 
//*****************************************************************************
//
//! \brief	Completely inverts the matrix	(regular matrix inversion)
//
//*****************************************************************************
inline void CEMMat4x4::InvertExcentric( void ) 
{
	SetMatrix( GetInvertedExcentric() );
}

//*****************************************************************************
//	GetInvertedExcentric
//*****************************************************************************
//
//! \brief	Returns a completely inverted copy of the matrix
//! \param	[out]The completely inverted copy of the matrix
//
//*****************************************************************************
inline void CEMMat4x4::GetInvertedExcentric( CEMMat4x4& a_matInverted ) const 
{
	a_matInverted = GetInvertedExcentric();
}

//*****************************************************************************
//	Clear
//*****************************************************************************
//
//! \brief	Clears the matrix (sets all elements to 0.0f)
//
//*****************************************************************************
inline void CEMMat4x4::Clear( void ) 
{
	SetMatrix( 0.0f );
}

//*****************************************************************************
//	Divide
//*****************************************************************************
//
//! \brief	Divides each element by the specified factor
//! \param	[in] The factor to divide by
//
//*****************************************************************************
inline void CEMMat4x4::Divide( float a_fDivisor ) 
{
	Multiply( 1.0f / a_fDivisor );
}

//*****************************************************************************
//	ReverseMultiply
//*****************************************************************************
//
//! \brief	Returns the matrix product of this matrix and the specified one
//! \param	[in] The matrix to multiply by this one
//
//*****************************************************************************
inline void CEMMat4x4::ReverseMultiply( const CEMMat4x4& a_matPrefix )
{
	SetToProduct( a_matPrefix, *this );
}

//*****************************************************************************
//	Multiply
//*****************************************************************************
//
//! \brief	Multiplies the matrix by the specified matrix
//! \param	[in] The matrix to multiply this one by
//
//*****************************************************************************
inline void CEMMat4x4::Multiply( const CEMMat4x4& a_matFactor ) 
{
	SetToProduct( *this, a_matFactor );
}

//*****************************************************************************
//	GetDeterminant
//*****************************************************************************
//
//! \brief	Determines the matrix' determinant
//! \return	The matrix' determinant
//
//*****************************************************************************
inline float CEMMat4x4::GetDeterminant( void ) const 
{
	return	  GetElement( 3, 3 ) * GetDeterminantAdjoint( 3, 3 )
			- GetElement( 3, 2 ) * GetDeterminantAdjoint( 3, 2 )
			+ GetElement( 3, 1 ) * GetDeterminantAdjoint( 3, 1 )
			- GetElement( 3, 0 ) * GetDeterminantAdjoint( 3, 0 );
}

//*****************************************************************************
//	GetDeterminantRotation
//*****************************************************************************
//
//! \brief	Determines the matrix' rotation's determinant
//! \return	The matrix' rotation's determinant
//
//*****************************************************************************
inline float CEMMat4x4::GetDeterminantRotation( void ) const 
{
	return GetDeterminantAdjoint( 3, 3 );
}

//*****************************************************************************
//	GetIdentity
//*****************************************************************************
//
//! \brief	Returns an identity matrix
//! \param	[out] An identity matrix
//
//*****************************************************************************
inline void CEMMat4x4::GetIdentity( CEMMat4x4& a_matIdentity )
{
	a_matIdentity.SetIdentity();
}

//*****************************************************************************
//	GetProductPrefix
//*****************************************************************************
//
//! \brief	Returns the product of the specified matrix and this one
//! \param	[out] The product
//! \param	[in] The matrix to multiply by this one
//
//*****************************************************************************
inline void CEMMat4x4::GetProductPrefix( CEMMat4x4& a_matProduct, const CEMMat4x4& a_matPrefix ) const 
{
	a_matProduct.SetToProduct( a_matPrefix, (*this) );
}

//*****************************************************************************
//	GetProduct
//*****************************************************************************
//
//! \brief	Returns the product of this matrix and the specified one
//! \param	[out] The product
//! \param	[in] The matrix to multiply
//
//*****************************************************************************
inline void CEMMat4x4::GetProduct( CEMMat4x4& a_matProduct, const CEMMat4x4& a_matFactor ) const 
{
	a_matProduct.SetToProduct( (*this), a_matFactor );
}

//*****************************************************************************
//	Invert
//*****************************************************************************
//
//! \brief	Inverts the matrix
//
//*****************************************************************************
inline void CEMMat4x4::Invert( void ) 
{
	InvertExcentric();
}

//*****************************************************************************
//	operator ==
//*****************************************************************************
//
//! \brief	Determines whether or not the matrix equals the specified matrix
//! \param	[in] The matrix to compare to
//! \return	The method returns either of the following values
//! \retval	true	| The matrices are equal
//! \retval	false	| The matrices differ
//
//*****************************************************************************
inline bool CEMMat4x4::operator == ( const CEMMat4x4& a_matOther ) const 
{
	return IsEqual( a_matOther );
}

//*****************************************************************************
//	operator != 
//*****************************************************************************
//
//! \brief	Determines whether or not the matrix differs the specified matrix
//! \param	[in] The matrix to compare to
//! \return	The method returns either of the following values
//! \retval	true	| The matrices differ
//! \retval	false	| The matrices are equal
//
//*****************************************************************************
inline bool CEMMat4x4::operator != ( const CEMMat4x4& a_matOther ) const 
{
	return ! ( IsEqual( a_matOther ) );
}

//*****************************************************************************
//	operator ~
//*****************************************************************************
//
//! \brief	Inverts the matrix
//! \return	The inverted matrix	
//
//*****************************************************************************
inline CEMMat4x4 CEMMat4x4::operator ~ ( void ) const 
{
	return GetInverted();
}

//*****************************************************************************
//	operator -
//*****************************************************************************
//
//! \brief	Negates the matrix
//! \return	The negated matrix	
//
//*****************************************************************************
inline CEMMat4x4 CEMMat4x4::operator - ( void ) const 
{
	return GetNegated();
}

//*****************************************************************************
//	operator +
//*****************************************************************************
//
//! \brief	Adds another matrix to this one
//! \param	[in] The matrix to add
//! \param	The sum matrix
//
//*****************************************************************************
inline CEMMat4x4 CEMMat4x4::operator + ( const CEMMat4x4& a_matOffset ) const 
{
	return GetSum( a_matOffset );
}

//*****************************************************************************
//	operator -
//*****************************************************************************
//
//! \brief	Subtracts another matrix from this one
//! \param	[in] The matrix to subtract
//! \param	The difference matrix
//
//*****************************************************************************
inline CEMMat4x4 CEMMat4x4::operator - ( const CEMMat4x4& a_matOffset ) const 
{
	return GetDifference( a_matOffset );
}

//*****************************************************************************
//	operator *
//*****************************************************************************
//
//! \brief	Multiplies the matrix by the specified scalar factor
//! \param	[in] The factor to multiply by
//! \return	The product matrix
//
//*****************************************************************************
inline CEMMat4x4 CEMMat4x4::operator * ( float a_fFactor ) const 
{
	return GetProduct( a_fFactor );
}

//*****************************************************************************
//	operator /
//*****************************************************************************
//
//! \brief	Multiplies the matrix by the reciprocal of the specified scalar factor
//! \param	[in] The factor
//! \return	The quotient matrix
//
//*****************************************************************************
inline CEMMat4x4 CEMMat4x4::operator / ( float a_fFactor ) const 
{
	return GetQuotient( a_fFactor );
}

//*****************************************************************************
//	operator *
//*****************************************************************************
//
//! \brief	Multiplies the matrix by the specified matrix
//! \param	[in] The matrix to multiply by
//! \return	The product matrix
//
//*****************************************************************************
inline CEMMat4x4 CEMMat4x4::operator * ( const CEMMat4x4& a_matFactor ) const 
{
	return GetProduct( a_matFactor );
}

//*****************************************************************************
//	operator *
//*****************************************************************************
//
//! \brief	Rotates the matrix by the specified axis and angle
//! \param	[in] The axis and angle to rotate by
//! \return	The rotated matrix
//
//*****************************************************************************
inline CEMMat4x4 CEMMat4x4::operator * ( const CEMAxisAngle& a_Rotation ) const 
{
	return GetRotated( a_Rotation );
}

//*****************************************************************************
//	operator *
//*****************************************************************************
//
//! \brief	Rotates the matrix by the specified euler angles
//! \param	[in] The euler angles to rotate by
//! \return	The rotated matrix
//
//*****************************************************************************
inline CEMMat4x4 CEMMat4x4::operator * ( const CEMEulerAngles& a_Rotation ) const 
{
	return GetRotated( a_Rotation );
}

//*****************************************************************************
//	operator *
//*****************************************************************************
//
//! \brief	Rotates the matrix by the specified quaternion
//! \param	[in] The quaternion to rotate by
//! \return	The rotated matrix
//
//*****************************************************************************
inline CEMMat4x4 CEMMat4x4::operator * ( const CEMQuaternion& a_quatRotation ) const 
{
	return GetRotated( a_quatRotation );
}

//*****************************************************************************
//	operator *
//*****************************************************************************
//
//! \brief	Multiplies the specified scalar with the specified matrix
//! \param	[in] The scalar factor
//! \param	[in] The matrix
//! \return	The product matrix
//
//*****************************************************************************
inline CEMMat4x4 operator * ( float a_fFactor, const CEMMat4x4& a_matFactor ) 
{
	return ( a_matFactor * a_fFactor );
}

//*****************************************************************************
//	operator []
//*****************************************************************************
//
//! \brief	Returns the element at the specified index
//! \param	[in] The element's index
//! \return	The element at the specified index
//
//*****************************************************************************
inline float CEMMat4x4::operator [] ( int a_iElement ) const 
{
	return GetElement( a_iElement );
}

//*****************************************************************************
//	operator []
//*****************************************************************************
//
//! \brief	Returns the element at the specified index
//! \param	[in] The element's index
//! \return	The element at the specified index
//
//*****************************************************************************
inline float& CEMMat4x4::operator [] ( int a_iElement ) 
{
	return AccessElement( a_iElement );
}

//*****************************************************************************
//	operator ()
//*****************************************************************************
//
//! \brief	Returns a vector representation of the specified row
//! \param	[in] The desired row's index
//! \return	A reference to the vector representation of the specified row
//
//*****************************************************************************
inline const CEMVec3& CEMMat4x4::operator () ( int a_iRow ) const
{
	return GetRow( a_iRow );
}

//*****************************************************************************
//	operator ()
//*****************************************************************************
//
//! \brief	Returns a vector representation of the specified row
//! \param	[in] The desired row's index
//! \return	A reference to the vector representation of the specified row
//
//*****************************************************************************
inline CEMVec3& CEMMat4x4::operator () ( int a_iRow ) 
{
	return AccessRow( a_iRow );
}

//*****************************************************************************
//	operator ()
//*****************************************************************************
//
//! \brief	Returns the element at the specified row and column
//! \param	[in] The desired element's row index
//! \param	[in] The desired element's column index
//! \return	A reference to the desired element
//
//*****************************************************************************
inline float CEMMat4x4::operator () ( int a_iRow, int a_iColumn ) const 
{
	return GetElement( a_iRow, a_iColumn );
}

//*****************************************************************************
//	operator ()
//*****************************************************************************
//
//! \brief	Returns the element at the specified row and column
//! \param	[in] The desired element's row index
//! \param	[in] The desired element's column index
//! \return	A reference to the desired element
//
//*****************************************************************************
inline float& CEMMat4x4::operator () ( int a_iRow, int a_iColumn ) 
{
	return AccessElement( a_iRow, a_iColumn );
}

//*************************************************************************************************
//*************************************************************************************************
//*************************************************************************************************

#endif	// CEMMat4x4_H_INCLUDED
