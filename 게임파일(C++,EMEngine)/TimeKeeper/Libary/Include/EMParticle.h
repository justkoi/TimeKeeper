#pragma once

typedef struct stparticle
{
	stEMVec3	m_stPos;			//!< ��ġ
	stEMVec3	m_stVel;			
	float		m_fAge;				//!< ����
	float		m_fLifeTime;		//!< ����ִ� �ð�(�������� �ð�)
	CEMColor	m_Color;			//!< Į��
	float		m_fScale;			//!< ũ��
}stEMParticle;


/**
	@file    : EMParticle.h
	@author  : wo
	@version : 1.0f
	@brief   : �ִϸ��̼� Ŭ����
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
		@brief �ð� �����Լ�

		@param fPs : �ʴ�ð�
		@param 	
		@param 	
		@return ����
	*/
	void SetPerSecond(float fPs);

	/**
		@brief �ý��ۿ��� ���Ǿ����� �ð� ����

		@param fLifeTime : �ð�
		@param 	
		@param 	
		@return ����
	*/
	void SetLifeTime(float fLifeTime);

	/**
	@brief ��ƼŬ ����ִ� �ð�����

	@param fLifeTime : �ð�
	@param 	
	@param 	
	@return ����
	*/
	void SetParticleLifetime(float fLifeTime);
	
	/**
	@brief ��ƼŬ ��ħ ����

	@param fRadian : ���� �Է�
	@param 	
	@param 	
	@return ����
	*/
	void SetSpread(float fRadian);

	/**
	@brief ��ƼŬ ���������(��) ũ�� ����

	@param fScale : ũ��
	@param 	
	@param 	
	@return ����
	*/
	void SetEndScale(float fScale);

	/**
	@brief ��ƼŬ ���������(��) Į�� ����

	@param CEMColor : Į��
	@param 	
	@param 	
	@return ����
	*/
	void SetEndColor(CEMColor& Color);

	/**
	@brief ���ǵ� ����

	@param 
	@param 	
	@param 	
	@return ����
	*/
	void SetSpeedRange(float fMinSpeed, float fMaxSpeed);

	/**
	@brief �߷� ����

	@param stEMVec2 stGravity : �߷�vec2����
	@param 	
	@param 	
	@return ����
	*/
	void SetGravity(stEMVec3& stGravity);

	/**
	@brief ��ƼŬ ���� ����

	@param int nMaxParticles : ȭ�鿡 ��µǾ��� ��ƼŬ ���� ����
	@param 	
	@param 	
	@return ����
	*/
	void SetMaxParticles(int nMaxParticles);

public:
	virtual void SetBoundingBox(stEMVec3 stLT, stEMVec3 stLB, stEMVec3 stRT, stEMVec3 stRB);
	virtual void SetBoundingBox();
	virtual const stdEMString GetClassName() { return "CEMParticle"; }

};