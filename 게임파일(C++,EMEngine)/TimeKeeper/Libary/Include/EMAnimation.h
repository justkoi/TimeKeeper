#pragma once

typedef enum enumanimationstyle
{
	E_ANI_LOOP = -1,				//!< ���� ����
	E_ANI_ONE = 0,					//!< �ѹ��� �ִ�
	E_ANI_PINGPONG_LOOP,			//!< ���� ���� ����
	E_ANI_PINGPONG_ONE				//!< ���� �ѹ���
}eAniStyle;


//! �� �ɼ��� �ִϸ��̼��� �ѹ��� ����ɶ��� ����˴ϴ�. ���ѷ���
typedef enum eanimationedingtype
{	
	E_ANI_ENDING_TYPE_DESTROY,			//! �ִϸ��̼��� ������ �޸� �����Ѵ�.
	E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT,	//! �ִϸ��̼��� ������ �ִϸ��̼� �������Ӹ� ��� ����Ѵ�.
	E_ANI_ENDING_TYPE_SHOW_FALSE		//! �ִϸ��̼��� ������ �Ⱥ��̰� �Ѵ�.
}eAniEndingType;

/**
	@file    : EMAnimation.h
	@author  : wo
	@version : 1.0f
	@brief   : �ִϸ��̼� Ŭ����
 */
class CEMAnimation : public CEMPlane
{
protected:
	float						m_fAniTimeCtrl;		//!< �ִϸ��̼� �ð� ��Ʈ��
	float						m_nCurTime;			//!< ���� �ð� ���� ���� �̰��� dt�� ��� ��������.
	bool						m_bCreateAniStop;	//!< �Ư���� ������ ��������� �ȵɶ� �̰��� TRUE�� �־��ָ� �������� �ʽ��ϴ�.
	eAniEndingType				m_eAniEndingType;	//!< �ִϸ��̼� �������� �������,�Ⱥ��̰Ը��Ұ��������� �����ϴ� ����(�⺻���� ����)
	eAniStyle					m_eLoopType;		//!<
	int							m_nFrames;			//!< �� ������ ����
	int							m_nCurFrameNumber;	//!< ���� ������ ��ȣ
	std::vector<stdEMString>	m_stdTexturePath;	//!< �׸�����Ÿ ��ġ ���� ����
	std::vector<stdEMString>	m_stdTextureName;	//!< �׸�����Ÿ �̸�
	std::vector<CEMPlane*>		m_stdPlaneList;		//!<  CEMPlane ���� list

	std::vector<CEMPlane*>::iterator m_stdIt;		//!< Iterator;

	bool						m_bPause;			//!< ��ø���
	bool						m_bDestroy;			//!< �޸� ���� ���^^

	int		m_nStartAniNum;		//!< �ִϸ��̼� ���� ������ ��ȣ
	int		m_nEndAniNum;		//!< �ִϸ��̼� �� ������ ��ȣ

	int		m_nFrameCnt;
	bool	m_nFrmaeEndCheck;	//!< �������� ������ üũ�մϴ�.
	bool	m_nFrameNoCnt;		//!< ������ ī��� ���ϰ� �ϴ� ����
	bool	m_bPingPongTurn;	//!< ���� �� üũ ����
	bool	m_bStartEndFlag;	//!< ���۰� ���� ����ڰ� �����ߴٸ� true�� �Ѿ�´�.

	stdEMString			m_sEmaName;	//!< ������ Ema�̸�
	int					m_nPrevFrame; //!< �� frame��ȣ
protected:
	CEMAnimation();
public:
	
	CEMAnimation(int nPlans);
	CEMAnimation(const stdEMString sEmaName);
	virtual ~CEMAnimation(void)
	{
	
	};

public:
	void Init();
	void Init(float fTime);

public:
	virtual void SetBackFaceCulling(bool bFlag);

	virtual void SetBoundingBox();

	virtual void SetRadius(float fRadius);

	virtual void ConnectBody(b2Body* pBody);

	virtual void SetLocalVec(stEMVec2 stPt);
	virtual void SetLocalVec(float fX, float fY);

	virtual void SetOffset(stEMOffset stOffset);
	virtual void SetOffset(float fX, float fY);	


	virtual void SetFrustumCulling(bool bFlag);
	virtual void SetBlend(bool bBlend);

	
	virtual void SetMirrorType(eMirrorType eType);


	virtual void SetOrtho2D(bool bFlag);

	virtual void SetSize(stEMVec2 stSize);
	virtual void SetSize(float fX, float fY=-1.0f);


	virtual void PolygonVertexRelease();

	virtual void SetColor(float fR, float fG, float fB, float fA=1.0f);
	virtual void SetAlpha(float fA);


	virtual void SetXRot(float fRot);
	virtual void SetYRot(float fRot);
	virtual void SetZRot(float fRot);

	virtual void SetConnectPhysicState(bool state);


	virtual void SetUV(stEMVec2 stLowLeft, stEMVec2 stUpRight);


	virtual void SetPos(float fX, float fY);
	virtual void SetPos(stEMVec2 vec2);
	virtual void SetPos(float fX, float fY, float fZ);
	virtual void SetPos(stEMVec3 vec3);


	virtual void MoveX(float fMove);
	virtual void MoveY(float fMove);
	virtual void MoveZ(float fMove);
	virtual void Update(float dt);

	virtual void Render();
	virtual const stdEMString GetClassName() { return "CEMAnimation"; }

	/**
	@brief 	�ؽ��� �����մϴ�
			- nCnt ������ CEMAnimation(4)�����ڿ��� ������� 4�� ������ ���� �ٸ��� ��������� �ʽ��ϴ�. �����ϼ���
			- �ؽ��� �ּҰ� �ٸ��� ������� ǥ�õ˴ϴ�. �⺻ ������ 100, 100�Դϴ�. 
			- �̹� �ҷ��� �̹������ ���������� �ε����� �ʽ��ϴ�.(�̸����� �����մϴ�)

	@param 	���� ��������
	@param 	�ؽ��� ��
	@param 	�ؽ��� �̸���...
	@return �ϳ��� �ؽ��� ������ ������ �߻��ϸ� false�� �����մϴ�.
	*/
	virtual bool SetTexture(CRootScene* pScene, int nCnt, ...);

private:
	void SetTexture();	//!< ������ ema�� �ִ� ������ ���ο��� setTexture�� ���ش�.
	void UpdateTexture(int nCurFrame);	//!< ������ ���� frame�� �ش��ϴ� texture������ ���
										//!< �ٿ�� �ڽ� ���

protected:
	/**
		@brief 	�ִϸ��̼� ������ �ص� �Ǵ��� �˾ƺ��� �Լ�
				Ư���� ��Ȳ�߻��� ���Լ��� �ִϸ��̼� ������ ���� �� �ִ�. 
		@param 	bool bAniCreate : true/false
		@param 	
		@param 	
		@return 
	*/
	void SetCreateAni(bool bAniCreate)			{m_bCreateAniStop = bAniCreate;}
	void AnimationEndingProcess();

public:
	/**
		@brief �ִϸ��̼ǵǰ��ִ� ���� ������ ��ȣ�� �˾ƿ´�.
				 
		@param 	
		@param 	
		@param 	
		@return 
	*/
	int GetCurFrameNumber()		{return m_nCurFrameNumber;}


		/**
		@brief 	E_ANI_ONE�� �ִϸ��̼��� ������ 
				1. Destory�� ȣ���Ұ����� �ƴϸ�
				2. �Ⱥ��̰� �� �Ұ����� �ƴϸ� 
				3. ������ �����Ӹ� ���̰� �Ұ������� �����Ѵ�. 
				 
		@param 	
		@param 	
		@param 	
		@return 
	*/
	void SetAnimationEndingType(eAniEndingType eType)			{m_eAniEndingType = eType;}

	/**
		@brief 	�ִϸ��̼� ������ Ư�������� ���� ���� ���ߴ����� �˾ƺ��� �Լ� 
			    ����ڰ� ��������������� �ϴ�.
		@param 	
		@param 	
		@param 	
		@return bool
	*/
	bool GetCreateAni()					{return m_bCreateAniStop;}

/**
		@brief 	�ִϸ��̼� ��� ����
		@param 	bool bTrue;
		@return void
	*/
	void SetPause(bool bTrue)			{m_bPause = bTrue;}
	bool GetPause()						{return m_bPause;}

/**
		@brief ��ϵǾ��� �� ������ ���� �˾ƿ���
		@param 
		@return �������� ����
	*/
	int  GetTotalFrame()				{return m_nFrames;}
	
	/**
		@brief nStart->nEnd���� �ִϸ��̼� �մϴ�.
			   �ǽð����� ���Լ� ȣ��� ��簪�� �ʱ�ȭ�Ǿ� �ٽ� �����մϴ�. (����)

		@param eAniStyle eLoopType : eAniStyle ����
		@param int nStart : ���� �ִϸ��̼� ������ ��ȣ
		@param int nEnd : �� �ִϸ��̼� ������ ��ȣ
		@param eAniEndingType eType : eLoopType�� E_ANI_ONE�ϰ�� �ִϸ��̼� �������� ó�� Ÿ��
		@return ����
	*/
	void SetLoopType(eAniStyle eLoopType, int nStart, int nEnd, eAniEndingType eType = E_ANI_ENDING_TYPE_DESTROY);

	/**
	@brief �ִϸ��̼������� ���� ��ȣ�� ������ �� �ִ�.
	       �ǽð����� ���Լ� ȣ��� ��簪�� �ʱ�ȭ�Ǿ� �ٽ� �����մϴ�. (����)

	@param eAniStyle eLoopType : eAniStyle ����
	@param int nStart : ���� �ִϸ��̼� ������ ��ȣ
	@param eAniEndingType eType : eLoopType�� E_ANI_ONE�ϰ�� �ִϸ��̼� �������� ó�� Ÿ��
	@param 
	@return ����
	*/
	void SetLoopType(eAniStyle eLoopType, int nStart, eAniEndingType eType = E_ANI_ENDING_TYPE_DESTROY);

	/**
	@brief �ִϸ��̼� Ÿ��  ����
		  �ǽð����� ���Լ� ȣ��� ��簪�� �ʱ�ȭ�Ǿ� �ٽ� �����մϴ�. (����)

	@param eAniStyle eLoopType : eAniStyle ����
	@param eAniEndingType eType : eLoopType�� E_ANI_ONE�ϰ�� �ִϸ��̼� �������� ó�� Ÿ��
	@param 
	@return ����
	*/
	void SetLoopType(eAniStyle eLoopType, eAniEndingType eType = E_ANI_ENDING_TYPE_DESTROY);

	eAniStyle GetLoopType()					{ return m_eLoopType; }
	eAniEndingType GetEndingType()			{ return m_eAniEndingType;}

	/**
		@brief �ִϸ��̼� �ð����� ���� �Լ��Դϴ�
		@param fTime : ���� �ð�
		@param 
		@return ����
	*/
	void SetTime(float fTime)			{ m_fAniTimeCtrl = fTime; }
	float GetTime()						{ return m_fAniTimeCtrl; }

	/**
		@brief vector�� ����Ǿ����ִ� �ؽ��� ��ġ������ ���� �����Ѵ�.
			   ���� �׸� ����Ÿ�� �������� �ʽ��ϴ�. ������ CEMPlane �޸� �Ҵ�Ǿ����� �� �������ϴ�.
			   ���� �׸� ����Ÿ�� ����ȯ�� Ȥ�� ���� ����� �ڵ� ���� �˴ϴ�.
		@param 
		@param 
		@param 
		@param 
		@param 
		@param 
		@param 
		@return ����
	*/
	void  PlaneRelease();
	/**
		@brief index�� �ش��ϴ� frame�� ���� �̸��� ��� �ȴϴ�.
		@param ã���� �ϴ� index
		@return �����̸�
	*/
	stdEMString GetFileName(int index);
	/**
		@brief index�� �ش��ϴ� frame�� ���� ��θ� ��� �ȴϴ�.
	    @param ã�����ϴ� index
		@return ���� ���
	*/
	stdEMString GetFilePath(int index);
};