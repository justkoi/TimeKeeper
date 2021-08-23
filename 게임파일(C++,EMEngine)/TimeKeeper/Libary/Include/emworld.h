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
	RECT m_stRt;			//!< left = ��������� ��ġ x  top = ������ �����ġ y    right = ������ ������ width   bottom = ����������� height
	bool m_bFullScreen;
}stWinInfo;

class CEMWorld				// : public CEMPhysicRoot //: public b2ContactListener
{
private:
	//static CEMWorld*	m_pWorldyo;			//!< �̱���
	bool 				m_bWorldInitState;		//!< WorldInit�Լ� ȣ�� �� ���� ����
	bool 				m_bGameLoopState;		//!< ���� ���� ���� ����
	bool 				m_bGameLoopStart;		//!< ���� ���� ��ŸƮ �ߴ��� ����
	bool 				m_bUpdateCal;			//!< ���� �������� Update(���)�� ���� �������� �����ϴ� Flag
	float				m_fPrevTime;			//!< �� �ð�


public:
	DWORD				m_fCurrTime;			//!< ����ð�

	
private:
	float				m_fDt;					//!< ����ð� - ���ð�
	int	 				m_nTotalLoadFonts;		//!< �о���� �� ��Ʈ ����
	stWinInfo			m_stWinSizeInfo;		//!< ������ ���� ��ġ�� ��Ÿ���
	stdObjectLayers		m_stdLayers;			//!< �߰��� ������Ʈ��
	bool				m_bObjectLocked;		
	HWND				m_hWnd;					//!< �����Ǿ��� ������ �ڵ� ���庯��
	CEMText*			m_pFpsText;				//!< fps ���
	CEMOpenglCerate		m_WinInfo;				//!< ������ ������ �����Դϴ� 
	stMouseInfo			m_stMouse;				

	//!<fps���� ��������
	int 				m_nFrame;
	float				m_fFps;
	float 				m_fTimeElapseds;

	int					m_nActiveFlag;
	
	CEMFrameSkip		m_FrameSkip[E_FRAMESKIP_MAX];				//!< ������ ����/���� ������ ���� Ŭ����
	float				m_fStaticFrame[E_FRAMESKIP_MAX];			//!< ������ ���������� �� (ex) Ű���� 40fps, ������Ʈ ������Ʈ(40fps)���
	float				m_fTotalStaticFrame;						//!< ��� ������ �����ӷ��� �Ȱ��� ���� �ϰ��� �Ѵٸ� �̰��� ������ �ּ��� �⺻�� 40
	
	typedef struct EMObjectLayerPair	
	{
		CEMObject* m_pObject;
		int	m_nLayer;
	}stEMObjectLayerPair;

	std::vector<stEMObjectLayerPair> 	m_stdDefferedAdds;			//!< lock�� �ɷȰ� �߰� �ؾߵǴµ� �� �־��� ��� �̰��� ����Ǿ�����.
	std::vector<stEMObjectLayerPair> 	m_stdDeferredLayerChanges;	//!< ���̾� ��ü �ؾ��ϴµ� �������� 
	std::vector<CEMObject*>			 	m_stdDeferredRemoves;		//!< lock�� �ɷ��� ��� �����ߵɳ���� �̸� �����Ѵ�.

	bool			m_bRightMouseDown;
	b2Vec2			m_LastpVec2;

	CEMPlane*		m_pMouseDownPlane;		//!< ���콺 �ٿ� Plane
	CEMPlane*		m_pMouseUpUPlane;		//!< ���콺 �� Plane

	bool			m_bMouseSetFlag;		//!< ���콺 ������ ���� �Ǿ����� �ƴ��� �ľ�
	bool			m_bBoundingBoxShowflag;	//!< �ٿ�� �ڽ� �������� ���� ����
	bool			m_bFpsShowFlag;			//!< fps �����ְ� �Ⱥ����ְ�
	bool			m_bPhysicDebugFlag;		//!< ���� �ٿ�� �ڽ� �� ����� ���� �������� ����

	CEMColor		m_BackColor;

public:
	bool			m_bCalcTimeDt;			//!< ���������� Update�Լ��� ȣ��Ǹ� �׶����� �ð� ����ϰ� �ؾ��մϴ�
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
	@brief �̱����� ���� �޸� �Ҵ��� �߱⶧���� �� �Լ��� delete���ְ� �ִ�.

	@param 
	@param 	
	@param 	
	@return ����
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
	@brief fps�������� ������ �������� �Լ�

	@param bool bFlag : true/false
	@return ����
	*/
	void SetFpsShowFlag(bool bFlag);

	void SetMaxFrame(E_FRAMESKIP_TYPE eType, float fFrame);
	float GetMaxFrame(E_FRAMESKIP_TYPE eType)						{return m_fStaticFrame[eType];}

	stMouseInfo GetMouse()	{return m_stMouse;}

	float GetCurFPS()		{return m_fFps;}

	/**
	@brief �ٿ���ڽ� ��� ����(�⺻�� false)
	@param bool bFlag : true/false
	@return ����
	*/
	void SetBoundingBoxShowFlag(bool bFlag)			{ m_bBoundingBoxShowflag = bFlag; }
	bool GetBoundingBoxshowflag()					{ return m_bBoundingBoxShowflag; }

// 	void SetPhysicBoundingBoxShowFlag(bool bFlag)	{m_bPhysicDebugFlag = bFlag;}
// 	bool GetPhysicBoundingBoxShowFlag()				{ return m_bPhysicDebugFlag;}

	/**
	@brief ���� �ʱ�ȭ�ϴ� �Լ�(OGL����)
	@param sName		: ������ Ÿ��Ʋ �̸�
	@param hInst		: �ν��Ͻ�
	@param nWinPosX		: ������ ��ġ 
	@param nWinPosY		: ������ ��ġ
	@param nWinWidth	: ������ ���� 
	@param nWinHeight	: ������ ����
	@param 
	@return ��������
	*/
	//bool WorldInit(char* sName = "����� ���ϳ�� ����Ͻÿ�", int nWinPosX = 0, int nWinPosY = 0, int nWinWidth = 1024, int nWinHeight=768, bool bFullScreen = false);
	bool WorldInit(char* sName = "����� ���ϳ�� ����Ͻÿ�",  int nWinWidth = 800, int nWinHeight=600, bool bFullScreen = false, HICON hIcon = NULL);

	/**
	@brief MFC���� WorldInit()�����Դϴ�
	@param HWND hWnd : ������ �ڵ�
	@param dc : dc
	@param HINSTANCE : �ν��Ͻ� �ڵ�
	@return ��������
	*/
	bool WorldMFCInit(HWND hWnd, HDC dc, HINSTANCE hInstance);
	bool WorldMFCInit(HWND* hWnd, HDC* dc,HINSTANCE hInstance, int nCnt);
	//bool WorldInit(stdEMString sName = "����� ���ϳ�� ����Ͻÿ�", HINSTANCE hInst, int nWinPosX = 0, int nWinPosY = 0, int nWinWidth = 1024, int nWinHeight=768, bool bAntiFlag = FALSE, bool bFullScreen = false);


	/**
	@brief �������� Data/Font�ȿ� �ִ� ��Ʈ���� � �о�鿴������ ���´�.
	@param 
	@return ��Ʈ ����(int)
	*/
	int GetTotalFonts()					{ return m_nTotalLoadFonts;   }

	/**
	@brief Data/Font/�ȿ� �ִ� ��Ʈ ����Ÿ�� �о������ �������� �о���� ������ ������ѵӴϴ�( �������� ȣ��)
	@param int nCnt : ����
	@return ����
	*/
	void SetTotalFonts(int nCnt)		{m_nTotalLoadFonts = nCnt;}

	/**
	@brief ���忡 ��ϵ� ���콺 �ٿ� Plane �����͸� �����Ѵ�.
	@param 
	@return CEMPlane* 
	*/
	CEMPlane* GetMouseDownPlanePt()		{ return m_pMouseDownPlane;	  }

	/**
	@brief ���忡 ��ϵ� ���콺 �� Plane �����͸� �����Ѵ�.
	@param 
	@return CEMPlane* 
	*/
	CEMPlane* GetMouseUpPlanePt()		{ return m_pMouseUpUPlane;	  }


	/**
	@brief ���콺 ������ �ߴ��� ���� ���
	@param 
	@return bool
	*/
	bool GetMouseSetState()				{ return m_bMouseSetFlag;	  }

	/**
	@brief ������ ���� ����(�������� ȣ��)
	@param stWinInfo stInfo : ������ ���� ���� ����ü
	@return ����
	*/
	void SetWinInfo(stWinInfo stInfo)	{ m_stWinSizeInfo = stInfo;	  }

	/**
	@brief ������ ���� ���
	@param 
	@return stWinInfo
	*/
	stWinInfo GetWinInfo()				{ return m_stWinSizeInfo;	  }
	
	/**
	@brief ��� ȭ�鿡 ��µǴ� ������Ʈ���� �����մϴ�
	@param 
	@return ����
	*/
	void Release();

	/**
	@brief ���� �ʱ�ȭ �� ī�޶� �ʱ�ȭ�ϴ� �Լ�
	@return void
	*/
	void WorldReset();

	/**
	@brief m_stdDefferedAdds; m_stdDeferredLayerChanges;	m_stdDeferredRemoves;		�̳�� ���� �ϴ� �Լ��Դϴ�. ^^ 
	@return void
	*/
	void RemoveObject();

	/**
	@brief ������ �����մϴ�
	@param bgColor : ����
	@return void
	*/
	void SetBackColor(CEMColor bgColor);

	/**
	@brief ���� ���� ������ �Լ�
	@return void
	*/
	void RunLoop();

	/**
	@brief ������ �Ѵٰ� �����Ͻø� �˴ϴ� MFC���� OnIdle() �����Ͻð� OnDraw���� ȣ���ؼ� ȣ�����ּ���
	@return void
	*/
	//void MFCRunLoop(HDC dc, HGLRC hRC);
	void MFCRunLoop( stdEMString strSceneName, int nIndex=0);
	void MFCRunLoop();

	/**
	@brief while(1) ���ѷ��� ��� �����Դϴ�.
	@return void
	*/
	void StopLoop();

	/**
	@brief ������Ʈ�� ������ �ϴ� �Լ��Դϴ�.
	@return void
	*/
	void UpdateRender(float dt);
	void MFCUpdateRender(int nCameraNum, float dt);

	/**
	@brief m_stdLayers�� Add�� �߰��Ǿ��� ������Ʈ���� ������Ʈ ���ְ� �׷��ִ� �Լ��Դϴ�. 
	@return void��
	*/
	void ObjectUpdate(float dt);
 	void ObjectRender();

	/**
	@brief ���� �ð� ������Ʈ �Լ��Դϴ�.
	@return void
	*/
	float UpdateDT();

	/**
	@brief ������Ʈ�� ���̾� �����մϴ�.
	@param CEMObject* pObject : ����� ������Ʈ
	@param int nLayer : ���̾�
	@return void
	*/
	void Commit(CEMObject* pObject, int nLayer = 0);


	/**
	@brief ������ Ż��
	@return void
	*/
	static int GLFWCALL WindowExit();
	int WindowExit_Ext();

	/**
	@brief Object���� �Լ� �Դϴ�.
	@param CEMObject* pObject : ���忡 ����� ������Ʈ ����
	@return void
	*/
	void RemoveObject(CEMObject* pObject);


	/**
	@brief World�� �߰��� map�� ���鼭 �� üũ�ؿ�6^ 
		   Object���� üũ�ؼ�(isDestroyed() ������ �� �͵��� ������ �����Ѵ�.
	@return void
	*/
	void DestroyObjectCheck();


	/**
	@brief lock�� �ɷ� �߰��� �ȵǾ����� �ٽ� �߰����ִ� �Լ��Դϴ�.
	@return void
	*/
	void UpdateDeferredAdds();

	/**
	@brief lock�� �ɷ� ���̾� ������ �ȵǾ������ �������ִ� �κ��Դϴ�.
	@return void
	*/
	void UpdateDeferredLayerChanges();

	/**
	@brief lock�� �ɷ����Ÿ� ������ ��� �������ִ� �Լ��Դϴ�.
	@return void
	*/
	void UpdateDeferredDestroy();

	/**
	@brief UPdate�� ���� �������� �����Ѵٰ� ���ø� �˴ϴ�. ������Ʈ�� ���ϰ� �Ǹ� �Ͻ� �����ϴ� ȿ���� ���� �� �־��^^
	@param bFlag : true/false
	@return bool  ��� ���� true�� Update �ϴ� ���̰� false�� ������Ʈ ���ϴ� ������
	*/
	bool SetUpdateFlag(bool bFlag);
	bool GetUpdateFlag()				{return m_bUpdateCal;}

	/**
	@brief ���忡 ��ϵǾ����ִ� ��Ʈ���� ��ġ�� ȭ������ ���ϸ� �ٽ� ���������� �ʿ伺�� ������ ���Լ��� ȣ���ϸ�˴ϴ�.
	@return ����
	*/
	void CalcFontPos();


	/**
	@brief ���콺 Ŀ�� ����
		   ���콺 Ŀ�� ������ �ѹ��� �� �� �ֽ��ϴ�. 
		   ���� ���� �Ұ� �մϴ�. 

	@param pMouseUp			: ���콺 �� �̹���
	@param stfMOuseUpoffset	: ������
	@param pMouseDown		: ���콺 �ٿ� �̹���
	@param stfMouseDownOffset : ������
	@param fSize			: ���콺 ũ�� 20.0f�� �⺻ ũ���Դϴ� (���������̹Ƿ� �� Ů�ϴ�)
	@return ����/���� ����
	*/
	bool SetMouseCursor( stdEMString strMouseUpImg, 
						 stEMVec2 stfMOuseUpoffset,
						 stdEMString strMouseDownImg, 
						 stEMVec2 stfMouseDownOffset, 
						 float fSize = 1.0f
					   );	

	/**
	@brief 13:53:24 (��:��:��)�����̸�, 24�ð����� ǥ�õȴ�.
		   �̷������� ���� �ð��� �������ݴϴ�

	@return �ð� ����
	*/
	stdEMString GetCurTime();


	/**
	@brief 04/17/09 (��/��/��)�������� ǥ�õȴ�.
		   ���� ��¥�� ������ �ݴϴ�

	@return ��¥ ����
	*/
	stdEMString GetCurDate();
};