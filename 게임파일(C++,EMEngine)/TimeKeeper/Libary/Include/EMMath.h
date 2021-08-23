
#pragma once

#include "EMBBox.h"

/**
	@file    : EMMath.h
	@author  : wo
	@version : 1.0f
	@brief   : ��ŷ�� ���Ǿ��� ����Դϴ�
 */
class CCollisionPlane
{
public:
	stEMVec3	m_stVec3N;
	float		m_fDinstance;

	CCollisionPlane(const stEMVec3& stVectorN,float fDistance)
	{
		Set(stVectorN,fDistance);
	}

	CCollisionPlane()
	{
	}

	void Set(const stEMVec3& stVertexN,float fDistance);														//!< VN �븻 ���Ϳ� ���� �߽� �������� �ִܰŸ� -fD�� ��� ���� �մϴ�.

	/**
	* ���� �浹�ϴ� ������ ��ġ���� �˾ƿɴϴ�.
	* 
	* 
	* @param stIntersectionVec  : �浹�Ǿ����� ��ġ��
	* @param stStartPt	: ray���� ������(ī�޶� ��ġ�� �ǰ���)
	* @param stEndPt	: ray�� ������
	* @param 
	* @return true/false
	*/
	bool GetIntersectionPoint(stEMVec3* stIntersectionVec,const stEMVec3& stStartPt,const stEMVec3& stEndPt);	//stStartPt(����),stEndPt(����) ���� �̷���� ������ ����� ��� ������ stIntersectionVec�� �ǵ����ϴ�.
	stEMVec3 GetIntersectionPoint(const stEMVec3& stStartPt,const stEMVec3& stEndPt);

};


class CEMMath
{
public:
	/** 
	* Euler's number: http://en.wikipedia.org/wiki/E_(mathematical_constant)
	*/
	static const float m_fE;

	/** 
	* Base-10 logarithm of Euler's number
	*/
	static const float m_fLog10E;

	/** 
	* Base-2 logarithm of Euler's number
	*/
	static const float m_fLog2E;

	/** 
	* Pi: http://en.wikipedia.org/wiki/Pi
	*/
	static const float m_fPi;

	/** 
	* Pi divided by 2
	*/
	static const float m_fPiOver2;

	/** 
	* Pi divided by 4
	*/
	static const float m_fPiOver4;

	/** 
	* 2 times Pi
	*/
	static const float m_fTwoPi;

	/** 
	* The maximum value that can be represented by a 32-bit floating point
	*  number
	*/
	static const float m_fMaxFloat;

	/** 
	* The minimum value that can be represented by a 32-bit floating point
	*  number
	*/
	static const float m_fMinFloat;

	/** 
	* A very tiny number, useful for floating point comparisons (10e-6)
	*/
	static const float m_fEpsilon;

	/** 
	* A templated absolute value function that can handle any class where
	*  a comparison against 0 makes sense (floats and ints, mostly). 
	* 
	* @param val The number
	* @return The absolute value of that number
	*/
	template<typename T>
	static T Abs(T val )
	{
		return val >= 0 ? val : -val;
	}

	/**
	* A templated max function that returns the greater of two values. Works
	*  for any class that implements a > operator. 
	* 
	* @param value1 The first value
	* @param value2 The second value
	* @return The greater of the two
	*/
	template<typename T>
	static T Max(T value1, T value2)
	{
		return value1 > value2 ? value1 : value2;
	}

	/**
	* A templated min function that returns the lesser of two values. Works
	*  for any class that implements a < operator. 
	* 
	* @param value1 The first value
	* @param value2 The second value
	* @return The lesser of the two
	*/
	template<typename T>
	static T Min(T value1, T value2)
	{
		return value1 < value2 ? value1 : value2;
	}

	/**
	* Find the distance between two values. Works for any class that has a 
	*  subtraction operator and will work with the #Abs function. 
	* 
	* @param value1 The first value
	* @param value2 The second value
	* @return The distance between them
	*/
	template<typename T>
	static T Distance(T value1, T value2)
	{
		return Abs(value1 - value2);
	}

	/**
	* Linearly interpolates between two values. Works for any classes that
	*  define addition, subtraction, and multiplication (by a float)
	*  operators. 
	* 
	* http://en.wikipedia.org/wiki/Lerp_(computing)
	* 
	* @param value1 The starting value
	* @param value2 The ending value
	* @param amount The amount to lerp (from 0.0 to 1.0)
	* @return The interpolated value
	*/
	template<typename T>
	static T Lerp(T value1, T value2, float amount)
	{
		return T(value1 + ((T)(value2 - value1) * amount ));
	}

	/**
	* Smoothly step between two values. Works for any classes that Lerp
	*  would work for (and is essentially a drop-in replacement).
	* 
	* http://www.fundza.com/rman_shaders/smoothstep/index.html
	* 
	* @param value1 The starting value
	* @param value2 The ending value
	* @param amount The amount to interpolate (from 0.0 to 1.0)
	* @return The interpolated value
	*/
	template<typename T>
	static T SmoothStep(T value1, T value2, float amount)
	{
		float num = Clamp(amount, 0.0f, 1.0f);
		return Lerp(value1, value2, (num * num) * (3.0f - (2.0f * num)));
	}

	/**
	* Clamps an integer to a specified range
	* 
	* @param value The integer in question
	* @param min The minimum of the range
	* @param max The maximum of the range
	* @return The clamped value
	*/
	static int Clamp(int value, int min, int max)
	{
		return Max(min, Min(max, value));
	}

	/**
	* value���� min �� max���̿� �����Ѵٸ� value���� �����ϰ� 
	* min���� �۴ٸ� min����   max���� ũ�ٸ� max���� �����մϴ�^^
	* 
	* @param value The float in question
	* @param min The minimum of the range
	* @param max The maximum of the range
	* @return The clamped value
	*/
	static float Clamp(float value, float min, float max)
	{
		return Max(min, Min(max, value));
	}

	/**
	* Clamps a double-precision float to a specified range
	* 
	* @param value The double in question
	* @param min The minimum of the range
	* @param max The maximum of the range
	* @return The clamped value
	*/
	static double Clamp(double value, double min, double max)
	{
		return Max(min, Min(max, value));
	}

	/**
	* Convert radians to degrees
	* 
	* @param radians The angle in radians
	* @return The angle in degrees
	*/
	static float ToDegrees(float radians);

	/**
	* Convert degrees to radians
	* 
	* @param degrees The angle in degrees
	* @return The angle in radians
	*/
	static float ToRadians(float degrees);

	/**
	* Get a unit-length vector which indicate a direction along the given
	*  angle relative to the screen. 
	* 
	* @param angle_in_degrees The angle, in degrees
	* @return A vector moving along that angle
	*/
	static stEMVec2 VectorFromAngle(float angle_in_degrees);

	/**
	* Get an angle from a vector indicating direction
	* 
	* @param v1 The vector direction
	* @return The vector's angle
	*/
	static float AngleFromVector(const stEMVec2& v1);

	/**
	* Get the angle between two vectors
	* 
	* @param v1 The first vector
	* @param v2 The second vector
	* @return The angle between them in radians
	*/
	static float AngleFromVectors(const stEMVec2& v1, const stEMVec2& v2);

	/**
	* Takes a double or float and removes everything after the decimal
	*  point, making it into an integer. 
	* 
	* @param x The double or float to round
	* @return The rounded integer
	*/
	static int RoundToInt(double x);

	/**
	* Get a random non-negative integer.
	* 
	* @param maximum The maximum value you want to see
	* @return A random number between 0 (inclusive) and maximum (exclusive)
	*/
	static int RandomInt(int maximum);

	/**
	* Get a random integer in a specified range.
	* 
	* @param min The minimum value you want to see
	* @param max The maximum value you want to see
	* @return A random number between min (inclusive) and max (exclusive)
	*/
	static int RandomIntInRange(int min, int max);

	/**
	* Get a random integer within a specified range of another one. 
	* 
	* @param target The target integer
	* @param error The maximum amount the returned value can differ from
	*  the target (in either direction)
	* @return A random int from (target - error) to (target + error)
	*/
	static int RandomIntWithError(int target, int error);

	/**
	* Get a random non-negative float.
	* 
	* @param maximum The maximum value you want to see
	* @return A random number between 0.0 (inclusive) and maximum (exclusive)
	*/
	static float RandomFloat(float maximum=1.0f);

	/**
	* Get a random float in a specified range.
	* 
	* @param min The minimum value you want to see
	* @param max The maximum value you want to see
	* @return A random number between min (inclusive) and max (exclusive)
	*/
	static float RandomFloatInRange(float min, float max);

	/**
	* Get a random float within a specified range of another one. 
	* 
	* @param target The target float
	* @param error The maximum amount the returned value can differ from
	*  the target (in either direction)
	* @return A random float from (target - error) to (target + error)
	*/
	static float RandomFloatWithError(float target, float error);

	/**
	* Get a random bool.
	* 
	* @return Either true or false, randomly. :-)
	*/
	static bool RandomBool();

	/**
	* Get a random unit-length stEMVec2
	* 
	* @return A unit-length stEMVec2 pointing in a random direction
	*/
	static stEMVec2 RandomVector();

	/**
	* Get a random stEMVec2 with specified maximum values
	* 
	* @param maxValues The highest values for both axes
	* @return A random vector ranging from (0, 0) to (maxValues.X, 
	*   maxValuesY)
	*/
	static stEMVec2 RandomVector(stEMVec2 maxValues);

	/**
	* Get a random stEMVec2 within a specified range
	* 
	* @param minValues The lowest values for both axes
	* @param maxValues The highest values for both axes
	* @return A random vector ranging from (minValues.X, minValues.Y) to 
	*   (maxValues.X, maxValues.y)
	*/
	static stEMVec2 RandomVector(stEMVec2 minValues, stEMVec2 maxValues);

	/**
	* Compare two floating point values for "equality," with a permissible
	*  amount of error. Oftentimes you only care if floats are "close enough
	*  for government work," and this function lets you make that 
	*  determination. 
	* 
	* (Because of rounding errors inherent in floating point arithmetic, 
	*   direct comparison of floats is often inadvisable.
	* http://en.wikipedia.org/wiki/Floating_point#Accuracy_problems )
	* 
	* @param value1 The first value
	* @param value2 The second value
	* @param epsilon The maximum allowable difference (defaults to 
	*   CEMMath::Epsilon)
	* @return Whether the two values are within epsilon of each other
	*/
	static bool FuzzyEquals(float value1, float value2, float epsilon=m_fEpsilon);

	/**
	* A stEMVec2 comparison function using FuzzyEquals on the components. 
	* 
	* @param v1 The first vector
	* @param v2 The second vector
	* @param epsilon The maximum allowable difference between them
	* @return Whether the two vectors have components within epsilon of 
	*  each other
	*/
	static bool FuzzyEquals(stEMVec2 v1, stEMVec2 v2, float epsilon=m_fEpsilon);

	/**
	* Convert screen (pixel) coordinates to world (GL unit) coordinates. 
	*  This function is not terribly efficient, so be careful calling it 
	*  too frequently. 
	* 
	* @param x The pixel X coordinate
	* @param y The pixel Y coordinate
	* @return The world space coordinates
	*/
	static stEMVec2 ScreenToWorld(int x, int y);

	/**
	* @param x : mouse x��ǥ
	* @param y : mouse y��ǥ
	* @param pColPlane : NULL�� �Ͻø� �⺻ �� ���� �����˴ϴ�.

			(ex)
				CEMCollisionPlane pPlane(stEMVec3(0.0f, 1.0f, 0.0f), 0);		--> �⺻���Դϴ�. 

				y�� 1.0f�̹Ƿ� y���� �����Ͱ� �ǰ�
				-100��ġ ��(y 100)��ġ�� plane�� ��������ϴ�. y���� 0.0f�� �����Ǿ� ���ɴϴ�


				CEMCollisionPlane* pPlane(stEMVec3(0.0f, 0.0f, 1.0f), 0);
				z���� �����Ͱ� �ǰ� �ڿ� �ִ� 0�� z���� 0.0f�� ������ �ǰ� ���Ǿ��� x�� y���� ���ɴϴ�


			
		
	* @return ���� ��ǥ
	*/
	static stEMVec3 ScreenToWorld(int x, int y, CEMCollisionPlane* pCollPlane/*=NULL*/);
	
	/**
	* Convert screen (pixel) coordinates to world (GL unit) coordinates. 
	*  This function is not terribly efficient, so be careful calling it 
	*  too frequently. 
	* 
	* @param screenCoordinates The pixel coordinates
	* @return The world space coordinates
	*/
	static stEMVec2 ScreenToWorld(stVec2i screenCoordinates);

	/**
	* Convert world (GL unit) coordinates to screen (pixel) coordinates. 
	* 	This function is not terribly efficient, so be careful calling it 
	*  too frequently.
	* 
	* @param x The world X coordinate
	* @param y The world Y coordinate
	* @return The screen space coordinates
	*/
	static stEMVec2 WorldToScreen(float x, float y);

	/**
	* Convert world (GL unit) coordinates to screen (pixel) coordinates. 
	* 	This function is not terribly efficient, so be careful calling it 
	*  too frequently.
	* 
	* @param worldCoordinates The world coordinates
	* @return The screen space coordinates
	*/
	static stEMVec2 WorldToScreen(stEMVec2 worldCoordinates);

	/**
	* Find out the dimensions of the area currently displayed in the window.
	* 
	* @return The dimensions of the viewport in GL units
	*/
	static stEMVec2 GetWorldDimensions();

	/**
	* Take a number of pixels and find out how many GL units they cover
	* 
	* @param pixels The number of pixels
	* @return The number of GL units
	*/
	static float PixelsToWorldUnits(float pixels);

	/**
	* Take a number of GL units and find out how many pixels stretch across
	*  that distance. 
	* 
	* @param worldUnits The number of GL units
	* @return The number of pixels
	*/
	static float WorldUnitsToPixels(float worldUnits);

	enum AABBSplittingAxis
	{
		AA_X,
		AA_Y
	};

	/**
	* Used internally by the SpatialGraph when it generates. 
	* 
	* @param source The bounding box to split
	* @return The appropriate axis on which to split it
	*/
	static AABBSplittingAxis GetMajorAxis(const CEMBBox& source);

	/**
	* Used internally by the SpatialGraph when it generates
	* 
	* @param source The bounding box to split
	* @param axis The axis on which to split it
	* @param LHS An out parameter that will be set to the left-hand-side 
	*   bounding box resulting from the split
	* @param RHS An out parameter that will be set to the right-hand-side
	*   bounding box resulting from the split
	*/
	static void SplitCEMBBox(const CEMBBox& source, AABBSplittingAxis axis, CEMBBox& LHS, CEMBBox& RHS);

	/**
	* Calculates the difference in two angles (in radians) and remaps it
	*  to a range from -Pi to Pi. 
	* 
	* @param A1 The first angle (in radians)
	* @param A2 The second angle (in radians)
	* @return The difference, mapped appropriately
	*/
	static float DeltaAngle(float A1, float A2);

	/**
	* Calculate the difference in angles between two vectors.
	* 
	* @param v1 The first vector
	* @param v2 The second vector
	* @return The difference in their angles
	*/
	static float VectorDeltaAngle(stEMVec2 v1, stEMVec2 v2);

	/**
	* 800 x 600�� �Է��ϸ� 800�� 600�� �����ϴ� SetSize(???, ???)�� �˾ƿ��� �Լ��Դϴ�
	* ���׸��� ȭ�鿡 �� �°� ����ϰ� �ʹٸ� SetSize()�Լ��� ���ߵ� ����� ��� �Ҷ� ����Ͻø� 
	* �˴ϴ�
	* 
	* @param nWidth ��ȯ�� ����
	* @param nHeight ��ȯ�� ����
	* @param fMultiPle �Է��� nWidth * fMultiple , nHeight * fMultiple �̵˴ϴ�. �⺻�� 1��
	* @return stEMVec2 ��ȯ�� ����
	*/
	static stEMVec2 SizeToScreenSize(int nWidth, int nHeight, float fMultiPle = 1.0f);

};
