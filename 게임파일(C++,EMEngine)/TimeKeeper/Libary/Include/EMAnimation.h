#pragma once

typedef enum enumanimationstyle
{
	E_ANI_LOOP = -1,				//!< 무한 루프
	E_ANI_ONE = 0,					//!< 한번만 애니
	E_ANI_PINGPONG_LOOP,			//!< 핑퐁 무한 루프
	E_ANI_PINGPONG_ONE				//!< 핑퐁 한번만
}eAniStyle;


//! 이 옵션은 애니메이션이 한번만 실행될때만 적용됩니다. 무한루프
typedef enum eanimationedingtype
{	
	E_ANI_ENDING_TYPE_DESTROY,			//! 애니메이션이 끝나면 메모리 해제한다.
	E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT,	//! 애니메이션이 끝나면 애니메이션 끝프레임만 계속 출력한다.
	E_ANI_ENDING_TYPE_SHOW_FALSE		//! 애니메이션이 끝나면 안보이게 한다.
}eAniEndingType;

/**
	@file    : EMAnimation.h
	@author  : wo
	@version : 1.0f
	@brief   : 애니메이션 클래스
 */
class CEMAnimation : public CEMPlane
{
protected:
	float						m_fAniTimeCtrl;		//!< 애니메이션 시간 컨트롤
	float						m_nCurTime;			//!< 현재 시간 저장 변수 이곳에 dt가 계속 더해진다.
	bool						m_bCreateAniStop;	//!< 어떤특정한 이유로 만들어지면 안될때 이곳에 TRUE를 넣어주면 생성되지 않습니다.
	eAniEndingType				m_eAniEndingType;	//!< 애니메이션 끝날을때 지울건지,안보이게만할것인지등을 결정하는 변수(기본값은 삭제)
	eAniStyle					m_eLoopType;		//!<
	int							m_nFrames;			//!< 총 프레임 개수
	int							m_nCurFrameNumber;	//!< 현재 프레임 번호
	std::vector<stdEMString>	m_stdTexturePath;	//!< 그림데이타 위치 저장 벡터
	std::vector<stdEMString>	m_stdTextureName;	//!< 그림데이타 이름
	std::vector<CEMPlane*>		m_stdPlaneList;		//!<  CEMPlane 저장 list

	std::vector<CEMPlane*>::iterator m_stdIt;		//!< Iterator;

	bool						m_bPause;			//!< 잠시멈춤
	bool						m_bDestroy;			//!< 메모리 제거 명령^^

	int		m_nStartAniNum;		//!< 애니멘이션 시작 프레임 번호
	int		m_nEndAniNum;		//!< 애니메이션 끝 프레임 번호

	int		m_nFrameCnt;
	bool	m_nFrmaeEndCheck;	//!< 프레임이 끝인지 체크합니다.
	bool	m_nFrameNoCnt;		//!< 프레임 카운드 못하게 하는 변수
	bool	m_bPingPongTurn;	//!< 핑퐁 턴 체크 변수
	bool	m_bStartEndFlag;	//!< 시작과 끝을 사용자가 지정했다면 true가 넘어온다.

	stdEMString			m_sEmaName;	//!< 윤영재 Ema이름
	int					m_nPrevFrame; //!< 전 frame번호
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
	@brief 	텍스쳐 설정합니다
			- nCnt 개수와 CEMAnimation(4)생성자에서 만들어진 4의 개수가 서로 다르면 만들어지지 않습니다. 주의하세요
			- 텍스쳐 주소가 다르면 흰색으로 표시됩니다. 기본 사이즈 100, 100입니다. 
			- 이미 불러온 이미지라면 내부적으로 로딩하지 않습니다.(이름으로 구분합니다)

	@param 	현재 씬포인터
	@param 	텍스쳐 수
	@param 	텍스쳐 이름들...
	@return 하나라도 텍스쳐 설정에 문제가 발생하면 false를 리턴합니다.
	*/
	virtual bool SetTexture(CRootScene* pScene, int nCnt, ...);

private:
	void SetTexture();	//!< 윤영재 ema에 있는 정보로 내부에서 setTexture를 해준다.
	void UpdateTexture(int nCurFrame);	//!< 윤영재 현재 frame에 해당하는 texture정보로 계산
										//!< 바운딩 박스 등등

protected:
	/**
		@brief 	애니메이션 생성을 해도 되는지 알아보는 함수
				특정한 상황발생히 이함수로 애니메이션 생성을 막을 수 있다. 
		@param 	bool bAniCreate : true/false
		@param 	
		@param 	
		@return 
	*/
	void SetCreateAni(bool bAniCreate)			{m_bCreateAniStop = bAniCreate;}
	void AnimationEndingProcess();

public:
	/**
		@brief 애니메이션되고있는 현재 프레임 번호를 알아온다.
				 
		@param 	
		@param 	
		@param 	
		@return 
	*/
	int GetCurFrameNumber()		{return m_nCurFrameNumber;}


		/**
		@brief 	E_ANI_ONE은 애니메이션이 끝나고 
				1. Destory를 호출할것인지 아니면
				2. 안보이게 만 할것인지 아니면 
				3. 마지막 프레임만 보이게 할것인지를 결정한다. 
				 
		@param 	
		@param 	
		@param 	
		@return 
	*/
	void SetAnimationEndingType(eAniEndingType eType)			{m_eAniEndingType = eType;}

	/**
		@brief 	애니메이션 생서중 특정이유로 인해 정지 당했는지를 알아보는 함수 
			    사용자가 사용할일은없을듯 하다.
		@param 	
		@param 	
		@param 	
		@return bool
	*/
	bool GetCreateAni()					{return m_bCreateAniStop;}

/**
		@brief 	애니메이션 잠시 멈춤
		@param 	bool bTrue;
		@return void
	*/
	void SetPause(bool bTrue)			{m_bPause = bTrue;}
	bool GetPause()						{return m_bPause;}

/**
		@brief 등록되어진 총 프레임 개수 알아오기
		@param 
		@return 총프레임 리턴
	*/
	int  GetTotalFrame()				{return m_nFrames;}
	
	/**
		@brief nStart->nEnd까지 애니메이션 합니다.
			   실시간으로 이함수 호출시 모든값이 초기화되어 다시 시작합니다. (주의)

		@param eAniStyle eLoopType : eAniStyle 참조
		@param int nStart : 시작 애니메이션 프레임 번호
		@param int nEnd : 끝 애니메이션 프레임 번호
		@param eAniEndingType eType : eLoopType이 E_ANI_ONE일경우 애니메이션 끝났을때 처리 타입
		@return 없음
	*/
	void SetLoopType(eAniStyle eLoopType, int nStart, int nEnd, eAniEndingType eType = E_ANI_ENDING_TYPE_DESTROY);

	/**
	@brief 애니메이션프레임 시작 번호를 지정할 수 있다.
	       실시간으로 이함수 호출시 모든값이 초기화되어 다시 시작합니다. (주의)

	@param eAniStyle eLoopType : eAniStyle 참조
	@param int nStart : 시작 애니메이션 프레임 번호
	@param eAniEndingType eType : eLoopType이 E_ANI_ONE일경우 애니메이션 끝났을때 처리 타입
	@param 
	@return 없음
	*/
	void SetLoopType(eAniStyle eLoopType, int nStart, eAniEndingType eType = E_ANI_ENDING_TYPE_DESTROY);

	/**
	@brief 애니메이션 타입  설정
		  실시간으로 이함수 호출시 모든값이 초기화되어 다시 시작합니다. (주의)

	@param eAniStyle eLoopType : eAniStyle 참조
	@param eAniEndingType eType : eLoopType이 E_ANI_ONE일경우 애니메이션 끝났을때 처리 타입
	@param 
	@return 없음
	*/
	void SetLoopType(eAniStyle eLoopType, eAniEndingType eType = E_ANI_ENDING_TYPE_DESTROY);

	eAniStyle GetLoopType()					{ return m_eLoopType; }
	eAniEndingType GetEndingType()			{ return m_eAniEndingType;}

	/**
		@brief 애니메이션 시간조절 설정 함수입니다
		@param fTime : 조절 시간
		@param 
		@return 없음
	*/
	void SetTime(float fTime)			{ m_fAniTimeCtrl = fTime; }
	float GetTime()						{ return m_fAniTimeCtrl; }

	/**
		@brief vector에 저장되어져있는 텍스쳐 위치정보를 전부 제거한다.
			   실제 그림 데이타는 지워지지 않습니다. 하지만 CEMPlane 메모리 할당되어진건 다 지워집니다.
			   실제 그림 데이타는 씬전환시 혹은 게임 종료시 자동 해제 됩니다.
		@param 
		@param 
		@param 
		@param 
		@param 
		@param 
		@param 
		@return 없음
	*/
	void  PlaneRelease();
	/**
		@brief index에 해당하는 frame의 파일 이름을 얻어 옴니다.
		@param 찾고자 하는 index
		@return 파일이름
	*/
	stdEMString GetFileName(int index);
	/**
		@brief index에 해당하는 frame의 파일 경로를 얻어 옴니다.
	    @param 찾고자하는 index
		@return 파일 경로
	*/
	stdEMString GetFilePath(int index);
};