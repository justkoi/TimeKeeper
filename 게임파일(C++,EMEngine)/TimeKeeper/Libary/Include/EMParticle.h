#pragma once

typedef struct stparticle
{
	stEMVec3	m_stPos;			//!< 위치
	stEMVec3	m_stVel;			
	float		m_fAge;				//!< 수명
	float		m_fLifeTime;		//!< 살아있는 시간(보여지는 시간)
	CEMColor	m_Color;			//!< 칼라
	float		m_fScale;			//!< 크기
}stEMParticle;


/**
	@file    : EMParticle.h
	@author  : wo
	@version : 1.0f
	@brief   : 애니메이션 클래스
 */
class CEMParticle	: public CEMPlane
{
protected:
	stEMParticle*	m_stpParticles;				

	int				m_nMaxParticlesAlive;		
	int				m_nNumParticlesAlive;

	float			m_fParticlesPerSecond;		
	int				m_nMaxParticlesToGenerate;	
	float			m_fGenerationResidue;

	float			m_fSystemLifeTile;
	float			m_fParticleLifeTime;
	float			m_fSpreadRadians;

	CEMColor		m_EndColor;

	float			m_fMinSpped;
	float			m_fMaxSpeed;
	float			m_fEndScale;

	stEMVec3		m_stGravity;

public:
	CEMParticle()
	{
 		m_stpParticles				= NULL;

		m_nMaxParticlesAlive		= 0;
		m_nNumParticlesAlive		= 0;

		m_fParticlesPerSecond		= 20.0f;
		m_nMaxParticlesToGenerate	= 0;
		m_fGenerationResidue		= 0.0f;

		m_fSystemLifeTile			= 0.0f;
		m_fParticleLifeTime			= 2.0f;
		m_fSpreadRadians			= 0.0f;

		m_EndColor					= CEMColor(1.0f, 1.0f, 1.0f);

		m_fMinSpped 				= 2.0f;
		m_fMaxSpeed 				= 4.0f;
		m_fEndScale 				= 1.0f;

		m_stGravity.m_fX			= 0.0f;
		m_stGravity.m_fY			= -4.0f;
		m_stGravity.m_fZ			= 0.0f;
	};

	~CEMParticle()
	{
		if(m_stpParticles)
		{
			delete [] m_stpParticles;
			m_stpParticles = NULL;
		}
	};


public:
	virtual void Update(float dt);
	virtual void Render();

public:

	/**
		@brief 시간 설정함수

		@param fPs : 초당시간
		@param 	
		@param 	
		@return 없음
	*/
	void SetPerSecond(float fPs);

	/**
		@brief 시스템에서 사용되어지는 시간 설정

		@param fLifeTime : 시간
		@param 	
		@param 	
		@return 없음
	*/
	void SetLifeTime(float fLifeTime);

	/**
	@brief 파티클 살아있는 시간설정

	@param fLifeTime : 시간
	@param 	
	@param 	
	@return 없음
	*/
	void SetParticleLifetime(float fLifeTime);
	
	/**
	@brief 파티클 펼침 설정

	@param fRadian : 라디안 입력
	@param 	
	@param 	
	@return 없음
	*/
	void SetSpread(float fRadian);

	/**
	@brief 파티클 사라지기전(끝) 크기 설정

	@param fScale : 크기
	@param 	
	@param 	
	@return 없음
	*/
	void SetEndScale(float fScale);

	/**
	@brief 파티클 사라지기전(끝) 칼라 설정

	@param CEMColor : 칼라
	@param 	
	@param 	
	@return 없음
	*/
	void SetEndColor(CEMColor& Color);

	/**
	@brief 스피드 설정

	@param 
	@param 	
	@param 	
	@return 없음
	*/
	void SetSpeedRange(float fMinSpeed, float fMaxSpeed);

	/**
	@brief 중력 설정

	@param stEMVec2 stGravity : 중력vec2설정
	@param 	
	@param 	
	@return 없음
	*/
	void SetGravity(stEMVec3& stGravity);

	/**
	@brief 파티클 개수 설정

	@param int nMaxParticles : 화면에 출력되어질 파티클 개수 설정
	@param 	
	@param 	
	@return 없음
	*/
	void SetMaxParticles(int nMaxParticles);

public:
	virtual void SetBoundingBox(stEMVec3 stLT, stEMVec3 stLB, stEMVec3 stRT, stEMVec3 stRB);
	virtual void SetBoundingBox();
	virtual const stdEMString GetClassName() { return "CEMParticle"; }

};