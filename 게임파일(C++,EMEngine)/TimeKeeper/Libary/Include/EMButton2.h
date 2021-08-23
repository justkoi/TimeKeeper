// #pragma once
// 
// class CEMButton2 : public CEMUIEvent
// {
// private:
// 	enum BUTTONSOUND {CLICK = 0, OVER};
// 
// private:
// 	stEMVec3 m_vPos;
// 	stEMVec3 m_vParent;
// 	stEMVec3 m_vRender;
// 	stEMRect m_rtRect;
// 
// 	CEMPlane* m_pButton;
// 
// 	stdEMString	m_sParentName;			//!< 현재 버튼의 window이름
// 
// 	bool m_Disable;
// 	bool m_Visible;
// 
// 
// 	SAMPLE_HANDLE m_shSound[2];
// 
// 	CRITICAL_SECTION m_csLock;
// 
// public:
// 	IMPLEMENT_GET_SET(bool, Disable);
// 	IMPLEMENT_GET_SET(bool, Visible);
// 	void SetPos(stEMVec3& vPos);
// 	stEMVec3 GetPos(bool bFlag = true);
// 
// public:
// 	UINT m_id;
// 
// public:
// 	void Update			(float dt);											//!< Update
// 	void Render			();													//!< Render
// 	void MouseDownEvent (stMouseInfo stPos, enumMouseButton eButton);		//!< 마우스 다운 이벤트
// 	void MouseUpEvent	(stMouseInfo stPos, enumMouseButton eButton);		//!< 마우스 업 이벤트
// 	void MouseMoveEvent (stMouseInfo stPos);								//!< 마우스 이동 이벤트
// 	void SetSound		(const char* pOverSound, const char* pClickSound);
// 	bool Collision		(int x, int y);
// 	void SetCoordinator	(stEMVec3& vPos);
// 
// protected:
// 	CEMPlane* Create(const char* cpTexture, stEMVec3& vPos);
// 
// public:
// 	CEMButton2(UINT id, const char* pParent, const char* cpTexture, stEMVec3& vParent, stEMVec3& vPos, UIEvent* pUIEvent);
// 	~CEMButton2();
// 
// };