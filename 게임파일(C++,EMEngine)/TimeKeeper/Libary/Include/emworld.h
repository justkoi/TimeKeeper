#pragma once

typedef std::vector<CEMObject*>	stdObjectList;
typedef std::map<int, stdObjectList> stdObjectLayers;

typedef enum etype
{
	E_FRAMESKIP_KEYINPUT,
	E_FRAMESKIP_PHYSIC,
	E_FRAMESKIP_OBJECT,
	E_FRAMESKIP_MAX
}E_FRAMESKIP_TYPE;

typedef struct wininfo
{
	RECT m_stRt;			//!< left = 윈도우출력 위치 x  top = 윈도우 출력위치 y    right = 윈도우 사이즈 width   bottom = 윈도우사이즈 height
	bool m_bFullScreen;
}stWinInfo;

class CEMWorld				// : public CEMPhysicRoot //: public b2ContactListener
{
private:
	//static CEMWorld*	m_pWorldyo;			//!< 싱글톤
	bool 				m_bWorldInitState;		//!< WorldInit함수 호출 한 산태 저장
	bool 				m_bGameLoopState;		//!< 게임 루프 진행 상태
	bool 				m_bGameLoopStart;		//!< 게임 루프 스타트 했는지 여부
	bool 				m_bUpdateCal;			//!< 게임 내에서의 Update(계산)을 할지 안할지를 결정하는 Flag
	float				m_fPrevTime;			//!< 전 시간


public:
	DWORD				m_fCurrTime;			//!< 현재시간

	
private:
	float				m_fDt;					//!< 현재시간 - 전시간
	int	 				m_nTotalLoadFonts;		//!< 읽어들인 총 폰트 개수
	stWinInfo			m_stWinSizeInfo;		//!< 윈도우 생성 위치및 기타등등
	stdObjectLayers		m_stdLayers;			//!< 추가한 오브젝트들
	bool				m_bObjectLocked;		
	HWND				m_hWnd;					//!< 생성되어진 윈도우 핸들 저장변수
	CEMText*			m_pFpsText;				//!< fps 출력
	CEMOpenglCerate		m_WinInfo;				//!< 윈도우 생성시 정보입니다 
	stMouseInfo			m_stMouse;				

	//!<fps관련 변수선언
	int 				m_nFrame;
	float				m_fFps;
	float 				m_fTimeElapseds;

	int					m_nActiveFlag;
	
	CEMFrameSkip		m_FrameSkip[E_FRAMESKIP_MAX];				//!< 종류별 고정/가변 프레임 제어 클래스
	float				m_fStaticFrame[E_FRAMESKIP_MAX];			//!< 종류별 고정프레임 값 (ex) 키보드 40fps, 오브젝트 업데이트(40fps)등등
	float				m_fTotalStaticFrame;						//!< 모든 종류의 프레임률을 똑같이 변경 하고자 한다면 이값을 조절해 주세요 기본값 40
	
	typedef struct EMObjectLayerPair	
	{
		CEMObject* m_pObject;
		int	m_nLayer;
	}stEMObjectLayerPair;

	std::vector<stEMObjectLayerPair> 	m_stdDefferedAdds;			//!< lock이 걸렸고 추가 해야되는데 못 넣었을 경우 이곳에 저장되어진다.
	std::vector<stEMObjectLayerPair> 	m_stdDeferredLayerChanges;	//!< 레이어 교체 해야하는데 못했을때 
	std::vector<CEMObject*>			 	m_stdDeferredRemoves;		//!< lock이 걸렸을 경우 지워야될놈들을 미리 지정한다.

	bool			m_bRightMouseDown;
	b2Vec2			m_LastpVec2;

	CEMPlane*		m_pMouseDownPlane;		//!< 마우스 다운 Plane
	CEMPlane*		m_pMouseUpUPlane;		//!< 마우스 업 Plane

	bool			m_bMouseSetFlag;		//!< 마우스 포인터 세팅 되었는지 아닌지 파악
	bool			m_bBoundingBoxShowflag;	//!< 바운딩 박스 보여줄지 말지 결정
	bool			m_bFpsShowFlag;			//!< fps 보여주고 안보여주고
	bool			m_bPhysicDebugFlag;		//!< 물리 바운딩 박스 등 디버그 정보 보여줄지 말지

	CEMColor		m_BackColor;

public:
	bool			m_bCalcTimeDt;			//!< 각씬에서의 Update함수가 호출되면 그때부터 시간 계산하게 해야합니다
	float			oldtime;
	unsigned long	m_nStartT;

protected:
	CEMWorld()
	{
		//m_pWorldyo = NULL;
		m_fCurrTime = ::GetTickCount();
		m_bCalcTimeDt = false;
		m_bRightMouseDown = false;
		m_LastpVec2.Set(0.0f, 0.0f);
		//m_fFps2 = 0.0f;
		m_nActiveFlag = true;
		m_pFpsText = NULL;
		m_nFrame = 0;
		m_nFrame = 0;
		m_fFps = 0.0f;	
		m_fTimeElapseds = 0.0f;
		m_bFpsShowFlag = false;
		//m_pMouseJoint = NULL;
		
		m_nStartT = ::GetTickCount();

		m_bWorldInitState = false;
		m_bGameLoopState = false;
		m_bGameLoopStart = false;
		m_bUpdateCal = true;
		m_fPrevTime = 0.0f;
		//m_fCurrTime = timeGetTime();
		m_fDt = 0.0f;
		m_bObjectLocked = false;
		m_nTotalLoadFonts = 0;
		//m_pPhysicWorld = NULL;
		//m_bPhysicSetFlag = false;
		//m_pPhysicDebug = NULL;
		//m_fPhysicReDt = 0.0f;
		m_pMouseDownPlane = NULL;
		m_pMouseUpUPlane = NULL;
		m_bMouseSetFlag = false;
		m_stWinSizeInfo.m_stRt.left = 0;
		m_stWinSizeInfo.m_stRt.top = 0;
		m_stWinSizeInfo.m_stRt.bottom = 0;
		m_stWinSizeInfo.m_stRt.right = 0;
		m_stWinSizeInfo.m_bFullScreen = false;
		m_bBoundingBoxShowflag = false;
		//m_bPhysicDebugFlag = false;

		m_stMouse.m_nX = 0;
		m_stMouse.m_nY = 0;

		m_fStaticFrame[E_FRAMESKIP_KEYINPUT] = 50.0f;
		m_fStaticFrame[E_FRAMESKIP_PHYSIC] = 50.0f;
		m_fStaticFrame[E_FRAMESKIP_OBJECT] = 50.0f;

// 		m_FrameSkip[E_FRAMESKIP_KEYINPUT].m_fSecPerFrame = (m_fStaticFrame[E_FRAMESKIP_KEYINPUT]);
// 		m_FrameSkip[E_FRAMESKIP_PHYSIC].m_fSecPerFrame = (m_fStaticFrame[E_FRAMESKIP_PHYSIC]);
// 		m_FrameSkip[E_FRAMESKIP_OBJECT].m_fSecPerFrame = (m_fStaticFrame[E_FRAMESKIP_OBJECT]);
		
	};

public:
	CEMWorld(int ID);
	virtual ~CEMWorld(void);
	static CEMWorld* Instance();

	bool GetFpsShowFlag()		{return m_bFpsShowFlag;}
	void FpsCalcUpdate();		

private:
	void SetWindowStyle(LONG* wndStyle);

	void MouseButton(int button, int state, int x, int y);
	void MouseMotion(int x, int y);
	b2Vec2 ConvertScreenToWorld(int32 x, int32 y);
	
	public:
	/**
	@brief 싱글톤이 동적 메모리 할당을 했기때문에 이 함수로 delete해주고 있다.

	@param 
	@param 	
	@param 	
	@return 없음
	*/
	void Destroy();	

public:
	LRESULT WinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	CEMOpenglCerate* GetWinCreateInfo()	{return &m_WinInfo;}
	//void GetWinCreateInfo(CEMOpenglCerate* pWinInfo);
	bool GetLoopState()					{return m_bGameLoopState;}
	void SetLoopState(bool bState)		{m_bGameLoopStart = m_bGameLoopStart;}
	HWND GetWinHandle()					{return m_hWnd;}

	CEMFrameSkip* GetFrameSkipPt()		{return m_FrameSkip;}

	/**
	@brief fps보여줄지 말지를 결정짓는 함수

	@param bool bFlag : true/false
	@return 없음
	*/
	void SetFpsShowFlag(bool bFlag);

	void SetMaxFrame(E_FRAMESKIP_TYPE eType, float fFrame);
	float GetMaxFrame(E_FRAMESKIP_TYPE eType)						{return m_fStaticFrame[eType];}

	stMouseInfo GetMouse()	{return m_stMouse;}

	float GetCurFPS()		{return m_fFps;}

	/**
	@brief 바운딩박스 출력 유무(기본값 false)
	@param bool bFlag : true/false
	@return 없음
	*/
	void SetBoundingBoxShowFlag(bool bFlag)			{ m_bBoundingBoxShowflag = bFlag; }
	bool GetBoundingBoxshowflag()					{ return m_bBoundingBoxShowflag; }

// 	void SetPhysicBoundingBoxShowFlag(bool bFlag)	{m_bPhysicDebugFlag = bFlag;}
// 	bool GetPhysicBoundingBoxShowFlag()				{ return m_bPhysicDebugFlag;}

	/**
	@brief 엔진 초기화하는 함수(OGL세팅)
	@param sName		: 윈도우 타이틀 이름
	@param hInst		: 인스턴스
	@param nWinPosX		: 윈도우 위치 
	@param nWinPosY		: 윈도우 위치
	@param nWinWidth	: 윈도우 넓이 
	@param nWinHeight	: 윈도우 높이
	@param 
	@return 성공유무
	*/
	//bool WorldInit(char* sName = "노는자 망하노니 명심하시오", int nWinPosX = 0, int nWinPosY = 0, int nWinWidth = 1024, int nWinHeight=768, bool bFullScreen = false);
	bool WorldInit(char* sName = "노는자 망하노니 명심하시오",  int nWinWidth = 800, int nWinHeight=600, bool bFullScreen = false, HICON hIcon = NULL);

	/**
	@brief MFC에서 WorldInit()세팅입니다
	@param HWND hWnd : 윈도우 핸들
	@param dc : dc
	@param HINSTANCE : 인스턴스 핸들
	@return 성공유무
	*/
	bool WorldMFCInit(HWND hWnd, HDC dc, HINSTANCE hInstance);
	bool WorldMFCInit(HWND* hWnd, HDC* dc,HINSTANCE hInstance, int nCnt);
	//bool WorldInit(stdEMString sName = "노는자 망하노니 명심하시오", HINSTANCE hInst, int nWinPosX = 0, int nWinPosY = 0, int nWinWidth = 1024, int nWinHeight=768, bool bAntiFlag = FALSE, bool bFullScreen = false);


	/**
	@brief 엔진에서 Data/Font안에 있는 폰트들을 몇개 읽어들였는지는 얻어온다.
	@param 
	@return 폰트 개수(int)
	*/
	int GetTotalFonts()					{ return m_nTotalLoadFonts;   }

	/**
	@brief Data/Font/안에 있는 폰트 데이타를 읽어들인후 엔진에서 읽어들인 개수를 저장시켜둡니다( 엔진에서 호출)
	@param int nCnt : 개수
	@return 없음
	*/
	void SetTotalFonts(int nCnt)		{m_nTotalLoadFonts = nCnt;}

	/**
	@brief 월드에 등록된 마우스 다운 Plane 포인터를 리턴한다.
	@param 
	@return CEMPlane* 
	*/
	CEMPlane* GetMouseDownPlanePt()		{ return m_pMouseDownPlane;	  }

	/**
	@brief 월드에 등록된 마우스 업 Plane 포인터를 리턴한다.
	@param 
	@return CEMPlane* 
	*/
	CEMPlane* GetMouseUpPlanePt()		{ return m_pMouseUpUPlane;	  }


	/**
	@brief 마우스 세팅을 했는지 여부 얻기
	@param 
	@return bool
	*/
	bool GetMouseSetState()				{ return m_bMouseSetFlag;	  }

	/**
	@brief 윈도우 정보 설정(엔진에서 호출)
	@param stWinInfo stInfo : 윈도우 정보 저장 구조체
	@return 없음
	*/
	void SetWinInfo(stWinInfo stInfo)	{ m_stWinSizeInfo = stInfo;	  }

	/**
	@brief 윈도우 정보 얻기
	@param 
	@return stWinInfo
	*/
	stWinInfo GetWinInfo()				{ return m_stWinSizeInfo;	  }
	
	/**
	@brief 모든 화면에 출력되는 오브젝트들을 제거합니다
	@param 
	@return 없음
	*/
	void Release();

	/**
	@brief 월드 초기화 및 카메라 초기화하는 함수
	@return void
	*/
	void WorldReset();

	/**
	@brief m_stdDefferedAdds; m_stdDeferredLayerChanges;	m_stdDeferredRemoves;		이놈들 제거 하는 함수입니다. ^^ 
	@return void
	*/
	void RemoveObject();

	/**
	@brief 배경색을 변경합니다
	@param bgColor : 배경색
	@return void
	*/
	void SetBackColor(CEMColor bgColor);

	/**
	@brief 메인 루프 돌리는 함수
	@return void
	*/
	void RunLoop();

	/**
	@brief 랜더링 한다고 생각하시면 됩니다 MFC에서 OnIdle() 선언하시고 OnDraw에서 호출해서 호출해주세요
	@return void
	*/
	//void MFCRunLoop(HDC dc, HGLRC hRC);
	void MFCRunLoop( stdEMString strSceneName, int nIndex=0);
	void MFCRunLoop();

	/**
	@brief while(1) 무한루프 잠시 멈춤입니다.
	@return void
	*/
	void StopLoop();

	/**
	@brief 업데이트와 랜더링 하는 함수입니다.
	@return void
	*/
	void UpdateRender(float dt);
	void MFCUpdateRender(int nCameraNum, float dt);

	/**
	@brief m_stdLayers에 Add로 추가되어진 오브젝트들을 업데이트 해주고 그려주는 함수입니다. 
	@return voidㄴ
	*/
	void ObjectUpdate(float dt);
 	void ObjectRender();

	/**
	@brief 지난 시간 업데이트 함수입니다.
	@return void
	*/
	float UpdateDT();

	/**
	@brief 업데이트할 레이어 지정합니다.
	@param CEMObject* pObject : 등록할 오브젝트
	@param int nLayer : 레이어
	@return void
	*/
	void Commit(CEMObject* pObject, int nLayer = 0);


	/**
	@brief 윈도우 탈출
	@return void
	*/
	static int GLFWCALL WindowExit();
	int WindowExit_Ext();

	/**
	@brief Object제거 함수 입니다.
	@param CEMObject* pObject : 월드에 등록한 오브젝트 제거
	@return void
	*/
	void RemoveObject(CEMObject* pObject);


	/**
	@brief World에 추가한 map을 돌면서 다 체크해요6^ 
		   Object들을 체크해서(isDestroyed() 지워야 할 것들이 있으면 제거한다.
	@return void
	*/
	void DestroyObjectCheck();


	/**
	@brief lock이 걸려 추가가 안되었을때 다시 추가해주는 함수입니다.
	@return void
	*/
	void UpdateDeferredAdds();

	/**
	@brief lock이 걸려 레이어 변경이 안되었을경우 변경해주는 부분입니다.
	@return void
	*/
	void UpdateDeferredLayerChanges();

	/**
	@brief lock이 걸려제거를 못했을 경우 제거해주는 함수입니다.
	@return void
	*/
	void UpdateDeferredDestroy();

	/**
	@brief UPdate를 할지 안할지를 결정한다고 보시면 됩니다. 업데이트를 안하게 되면 일시 정지하는 효과를 얻을 수 있어요^^
	@param bFlag : true/false
	@return bool  결과 리턴 true면 Update 하는 것이고 false면 업데이트 안하는 것이죠
	*/
	bool SetUpdateFlag(bool bFlag);
	bool GetUpdateFlag()				{return m_bUpdateCal;}

	/**
	@brief 월드에 등록되어져있는 폰트들의 위치를 화면사이즈가 변하면 다시 계산해줘야할 필요성이 있을때 이함수를 호출하면됩니다.
	@return 없음
	*/
	void CalcFontPos();


	/**
	@brief 마우스 커서 설정
		   마우스 커서 설정은 한번만 할 수 있습니다. 
		   추후 변경 불가 합니다. 

	@param pMouseUp			: 마우스 업 이미지
	@param stfMOuseUpoffset	: 기준점
	@param pMouseDown		: 마우스 다운 이미지
	@param stfMouseDownOffset : 기준점
	@param fSize			: 마우스 크기 20.0f가 기본 크기입니다 (직교투영이므로 좀 큽니다)
	@return 실패/성공 유무
	*/
	bool SetMouseCursor( stdEMString strMouseUpImg, 
						 stEMVec2 stfMOuseUpoffset,
						 stdEMString strMouseDownImg, 
						 stEMVec2 stfMouseDownOffset, 
						 float fSize = 1.0f
					   );	

	/**
	@brief 13:53:24 (시:분:초)형식이며, 24시간으로 표시된다.
		   이런식으로 현재 시간을 리턴해줍니다

	@return 시간 리턴
	*/
	stdEMString GetCurTime();


	/**
	@brief 04/17/09 (월/일/년)형식으로 표시된다.
		   오늘 날짜를 리턴해 줍니다

	@return 날짜 리턴
	*/
	stdEMString GetCurDate();
};