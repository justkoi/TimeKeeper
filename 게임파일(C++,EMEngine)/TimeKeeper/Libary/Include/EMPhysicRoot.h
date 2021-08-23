#pragma once

#define	RAND_LIMIT	32767

#include "Box2D/Box2D.h"

struct b2AABB;

class CEMPlane;

// �������� �浹�Ǵ� ������ ������ �����Դϴ�.
class CCollisions
{
public:
	b2Fixture* m_pFixtureA;
	b2Fixture* m_pFixtureB;

	CEMPlane* m_pPlaneA;
	CEMPlane* m_pPlaneB;

public:
	CCollisions()
	{
		m_pFixtureA = NULL;
		m_pFixtureB = NULL;
		m_pPlaneA = NULL;
		m_pPlaneB = NULL;
	};

	CCollisions(b2Fixture* pFixtureA, b2Fixture* pFixtureB)
	{
		m_pFixtureA = NULL;
		m_pFixtureB = NULL;
		m_pPlaneA = NULL;
		m_pPlaneB = NULL;

		if(pFixtureA && pFixtureB)
		{
			m_pFixtureA = pFixtureA;
			m_pFixtureB = pFixtureB;

			m_pPlaneA = (CEMPlane*)pFixtureA->GetBody()->GetUserData();
			m_pPlaneB = (CEMPlane*)pFixtureB->GetBody()->GetUserData();
		}		
	};

	~CCollisions(){};

public:
	bool operator==(const CCollisions& other) const
	{
		return (m_pFixtureA == other.m_pFixtureA) && (m_pFixtureB == other.m_pFixtureB);
	}
};

class CEMPhysicDebug : public b2Draw
{
public:
	void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
	void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
	void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color);
	void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color);
	void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color);
	void DrawTransform(const b2Transform& xf);
	void DrawPoint(const b2Vec2& p, float32 size, const b2Color& color);
	void DrawString(int x, int y, const char* string, ...); 
	void DrawAABB(b2AABB* aabb, const b2Color& color);
};



/// Random number in range [-1,1]
inline float32 RandomFloat()
{
	float32 r = (float32)(rand() & (RAND_LIMIT));
	r /= RAND_LIMIT;
	r = 2.0f * r - 1.0f;
	return r;
}

/// Random floating point number in range [lo, hi]
inline float32 RandomFloat(float32 lo, float32 hi)
{
	float32 r = (float32)(rand() & (RAND_LIMIT));
	r /= RAND_LIMIT;
	r = (hi - lo) * r + lo;
	return r;
}

struct Settings
{
	Settings() :
		hz(60.0f),
		velocityIterations(8),
		positionIterations(3),
		drawStats(0),
		drawShapes(1),
		drawJoints(1),
		drawAABBs(0),
		drawPairs(0),
		drawContactPoints(0),
		drawContactNormals(0),
		drawContactForces(0),
		drawFrictionForces(0),
		drawCOMs(0),
		enableWarmStarting(1),
		enableContinuous(1),
		pause(0),
		singleStep(0)
		{}

	float32 hz;
	int32 velocityIterations;
	int32 positionIterations;
	int32 drawShapes;
	int32 drawJoints;
	int32 drawAABBs;
	int32 drawPairs;
	int32 drawContactPoints;
	int32 drawContactNormals;
	int32 drawContactForces;
	int32 drawFrictionForces;
	int32 drawCOMs;
	int32 drawStats;
	int32 enableWarmStarting;
	int32 enableContinuous;
	int32 pause;
	int32 singleStep;
};

class DestructionListener : public b2DestructionListener
{
public:
	friend class CEMPhysicRoot;
	CEMPhysicRoot* test;

public:
	void SayGoodbye(b2Fixture* fixture) { B2_NOT_USED(fixture); }
	void SayGoodbye(b2Joint* joint);

public:
	DestructionListener(){test = NULL;}

	
};

const int32 k_maxContactPoints = 2048;

struct ContactPoint
{
	b2Fixture* fixtureA;
	b2Fixture* fixtureB;
	b2Vec2 normal;
	b2Vec2 position;
	b2PointState state;
};

class CEMPlane;

// Box2D���� Test�� �ش��ϴ� �κ��Դϴ�. 
class CEMPhysicRoot : public b2ContactListener
{
public:
	friend class DestructionListener;
	friend class BoundaryListener;
	friend class ContactListener;

	b2Body*						m_groundBody;
	b2AABB						m_worldAABB;
	ContactPoint				m_points[k_maxContactPoints];
	int32						m_pointCount;
	DestructionListener			m_destructionListener;
	CEMPhysicDebug				m_debugDraw;
	int32						m_textLine;
	b2World*					m_world;
	b2Body*						m_bomb;
	b2MouseJoint*				m_mouseJoint;
	b2Vec2						m_bombSpawnPoint;
	bool						m_bombSpawning;
	b2Vec2						m_mouseWorld;
	int32						m_stepCount;
	b2Body*						m_bodyList;

	std::vector<CCollisions>	m_stdCollisions;			//! �浹 ������ ���� ���� 
	bool						m_bAutoCollisionInfoCheck;	//!< �ڵ����� ���� �浹 ������ üũ�Ұ������� Ȯ�� true/�ڵ� �浹 ���� m_stdCollisions�� ����   false/���� ���� ���� �ʾƿ�

	std::vector<CEMPlane*>		m_stdColl;					//!< Ư�� Plane�̶� �浹������ ������ ����

	bool						m_bCreateWorld;				//!<` ���� ���尡 �����Ǿ�����üũ
																	
public:
	
	CEMPhysicRoot(/*stEMVec2 gravity*/)
	{
		m_world = NULL;
		m_bCreateWorld = false;
		m_bomb = NULL;
		m_mouseJoint = NULL;
		m_bodyList = NULL;
		m_bAutoCollisionInfoCheck = true;
	};
	virtual ~CEMPhysicRoot();

public:
	bool IsCreateWorld()		{return m_bCreateWorld;}

	bool CreateWorld(stEMVec2 gravity);

	/**
	@brief �����Ǿ��� ��� Body�� ����ϴ�
	@param 
	@return ����/����
	*/
	bool DeleteAllBody();

	/**
	@brief ��������մϴ�
	@param 
	@return ����/����
	*/
	bool DeleteWorld();

	/**
	@brief �ڵ����� ���� �浹 ������ üũ�Ұ������� Ȯ�� true/�ڵ� �浹 ���� m_stdCollisions�� ����   false/���� ���� ���� �ʾƿ�
	@param bstate :true/false
	@return ����
	*/
	void SetPhysicAutoCollisionInfoCheckOnOff(bool bSate = true)		{m_bAutoCollisionInfoCheck = bSate;}
	bool GetPhysicAutoCollisionInfoCheckOnOff()							{ return m_bAutoCollisionInfoCheck;}

	/**
	@brief ���ڰ����� �Ѿ�� pPlane�� �浹�Ǿ��� ��� pPlane���� �Ѱ��ݴϴ�.
			
	@param pPlane : Ư�� pPlane�� �־��ݴϴ�. �־��� pPlane�� �浹�� ��� plane���� �ѱ�ϴ�.
	@return std::vector<CEMPlane*> �浹�� plane����
	*/
	std::vector<CEMPlane*> GetCollisionPlanes(CEMPlane* pPlane);


	void SetTextLine(int32 line) { m_textLine = line; }
	void DrawTitle(int x, int y, const char *string);
	virtual void Step(Settings* settings);
	virtual void Keyboard(unsigned char key) { B2_NOT_USED(key); }
	void ShiftMouseDown(const b2Vec2& p);
	virtual void MouseDown(const b2Vec2& p);
	virtual void MouseUp(const b2Vec2& p);
	void MouseMove(const b2Vec2& p);
	void LaunchBomb();
	void LaunchBomb(const b2Vec2& position, const b2Vec2& velocity);

	void SpawnBomb(const b2Vec2& worldPt);
	void CompleteBombSpawn(const b2Vec2& p);
	

	// Let derived tests know that a joint was destroyed.
	virtual void JointDestroyed(b2Joint* joint) { B2_NOT_USED(joint); }

	// Callbacks for derived classes.
	virtual void BeginContact(b2Contact* contact); /*{ B2_NOT_USED(contact); }	*/			//!< �浹�Ǹ� ȣ��ȴ�
	virtual void EndContact(b2Contact* contact);/* { B2_NOT_USED(contact); }			*/	//!< �浹�ǰ� ������ ȣ��ȴ�

	virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold)			//!< ����������� �߻�������
	{
		B2_NOT_USED(contact);
		B2_NOT_USED(oldManifold);
	}

	virtual void PostSolve(const b2Contact* contact, const b2ContactImpulse* impulse)	//!< ����������� ��������
	{
		B2_NOT_USED(contact);
		B2_NOT_USED(impulse);
	}
};

