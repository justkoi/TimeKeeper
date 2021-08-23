#include "stdafx.h"

void CCredit::Enter(CSceneWork* pSceneWork)
{
	m_Topni = new CEMPlane;
	m_Topni->SetTexture(this,"Data/Image/Wheel/Topni.png");
	m_Topni->SetPos(-250.0f,0.f);
	m_Topni->SetBlend(true);
	m_Topni->SetSize(0.3f);
	m_Topni->SetShow(true);

	Commit(0,"톱니",m_Topni);
	
	
	m_Maker1 = new CEMPlane;
	m_Maker1->SetTexture(this,"Data/Maker/Maker1.png");
	m_Maker1->SetPos(0.0f,0.0f);
	m_Maker1->SetBlend(true);
	m_Maker1->SetSize(0.3f);
	m_Maker1->SetShow(false);

	Commit(0,"제작자1",m_Maker1);

	m_Maker2 = new CEMPlane;
	m_Maker2->SetTexture(this,"Data/Maker/Maker2.png");
	m_Maker2->SetPos(0.0f,0.0f);
	m_Maker2->SetBlend(true);
	m_Maker2->SetSize(0.3f);
	m_Maker2->SetShow(false);

	Commit(0,"제작자2",m_Maker2);

	m_Maker3 = new CEMPlane;
	m_Maker3->SetTexture(this,"Data/Maker/Maker3.png");
	m_Maker3->SetPos(0.0f,0.0f);
	m_Maker3->SetBlend(true);
	m_Maker3->SetSize(0.3f);
	m_Maker3->SetShow(false);

	Commit(0,"제작자3",m_Maker3);

	m_BackGround = new CEMPlane;
	m_BackGround->SetTexture(this,"Data/Maker/Maker_BackGround.png");
	m_BackGround->SetPos(0.0f,0.0f);
	m_BackGround->SetBlend(true);
	m_BackGround->SetSize(0.75f);
	m_BackGround->SetShow(true);

	Commit(1,"배경",m_BackGround);

	m_BackButton = new CEMPlane;
	m_BackButton->SetTexture(this,"Data/Button/뒤로가기.png");
	m_BackButton->SetSize(0.5f);
	m_BackButton->SetPos(-200.0f,-150.0f,1.0f);
	m_BackButton->SetBlend(true);
	m_BackButton->SetShow(true);

	Commit(0,"뒤로가기버튼",m_BackButton);
	//!=====================================================
	//!화면에 Plane출력하기
	
	//!=====================================================
	m_TeamName = new CEMPlane;
	m_TeamName->SetTexture(this,"Data/Maker/TeamName4.png");
	m_TeamName->SetPos(100.0f,50.0f);
	m_TeamName->SetSize(0.5f);
	m_TeamName->SetBlend(true);
	m_TeamName->SetAlpha(m_Alpha);
	m_TeamName->SetShow(true);
	m_TeamName->SetZRot(90);
	
	Commit(0,"팀이름",m_TeamName);

	m_pStar = new CEMPlane;
	m_pStar->SetTexture(this,"Data/SoundGage.png");
	m_pStar->SetPos(m_stStar);
	m_pStar->SetSize(0.1f);
	m_pStar->SetBlend(true);
	m_pStar->SetShow(true);
	
	Commit(0,"별",m_pStar);

	m_pStar2 = new CEMPlane;
	m_pStar2->SetTexture(this,"Data/SoundGage.png");
	m_pStar2->SetPos(m_stStar2);
	m_pStar2->SetSize(0.1f);
	m_pStar2->SetBlend(true);
	m_pStar2->SetShow(true);
	
	Commit(0,"별2",m_pStar2);


	m_MouseAni = new CEMAnimation(4);
	m_MouseAni->SetTexture(this,4,"Data/Ani1.png",
								  "Data/Ani2.png",
								  "Data/Ani3.png",
								  "Data/Ani4.png");
	m_MouseAni->SetPos(g_fMouseX,g_fMouseY,0.0f);
	m_MouseAni->SetBlend(true);
	m_MouseAni->SetSize(0.6f);
	m_MouseAni->SetShow(true);

	Commit(-2,"우헤헤헤",m_MouseAni);

	m_SHandle = D_SOUND->Play(D_SOUND->FileOpen("Data/Sound/Logo_BGM.mp3",true),g_SVolume,true);
	CRootScene::Enter(pSceneWork);
}
void CCredit::Init()
{
	m_Alpha = 0.0f;
	m_fGetCount =0.0f;
	m_fTriangleFx = 0.0f;
}
void CCredit::Update(CSceneWork* pSceneWork, float dt)
{
	m_fGetCount += dt;
	
	if(g_bSoundCheck == true && D_SOUND->IsPlaying(m_SHandle) == true)
		D_SOUND->Pause(m_SHandle,true);
		

	if(m_fGetCount >= 1.4f)
	{
		m_fTriangleFx = 60.0f;
	}

	if(m_fGetCount <= 1.7f)
	{
		m_pStar->MoveX(cosf(m_fTriangleFx)*3);
		m_pStar->MoveY(sinf(m_fTriangleFx2)*3);
	}

	m_pStar2->MoveX(cosf(m_fTriangleFx3)*3);
	m_pStar2->MoveY(sinf(m_fTriangleFx4)*3);
	//int n = 2;

	//m_Maker1->MoveX(cos(m_TriangleFx)*n);
	//m_Maker1->MoveY(sin(m_TriangleFx)*n); // 늘어날수록 범위랑 속도 증가

	//m_TriangleFx += dt; // 늘어날수록 범위 줄음
	//if(m_TriangleFx >= 360)
	//	m_TriangleFx = 0.0f;
	//
	//m_Maker1->SetShow(true);

	//m_Maker2->MoveX(cos(m_TriangleFx2)*n);
	//m_Maker2->MoveY(sin(m_TriangleFx2)*n);

	//m_TriangleFx2 += dt;
	//if(m_TriangleFx2 >= 360)
	//	m_TriangleFx2 = 0.0f;

	//m_Maker2->SetShow(true);

	//m_Maker3->MoveX(cos(m_TriangleFx3)*n);
	//m_Maker3->MoveY(sin(m_TriangleFx3)*n);

	//m_TriangleFx3 += dt;
	//if(m_TriangleFx3 >= 360)
	//	m_TriangleFx3 = 0.0f;

	//m_Maker3->SetShow(true);

	m_ZRot += 1.0f;
	if(m_ZRot >= 360.0f)
		m_ZRot = 0.0f;
	if(m_ZRot <= 90.0f)
		m_CountCheck = 1;
	else if(m_ZRot > 90.0f && m_ZRot <180.0f)				// 톱니바퀴의 각도 마다 체크를해서 CountCheck를 바꿔준다
		m_CountCheck = 2;
	else if(m_ZRot >= 180.0f && m_ZRot <270.0f)
		m_CountCheck = 3;
	else if(m_ZRot >=270.0f)
		m_CountCheck = 4;

	if(m_CountCheck == 1)									// 효과 변경 // 1번 효과 흔들림 + 순차적
	{
		m_Maker1->SetPos(-100.0f,0.0f);
		m_Maker1->SetShow(true);
	}
	if(m_CountCheck != 1 )
		m_Maker1->SetShow(false);
	if(m_CountCheck == 2)
	{
		m_Maker2->SetPos(-100.0f,0.0f);
		m_Maker2->SetShow(true);
	}
	if(m_CountCheck != 2 )
		m_Maker2->SetShow(false);
	if(m_CountCheck == 3)
	{
		m_Maker3->SetPos(-100.0f,0.0f);
		m_Maker3->SetShow(true);
	}
	if(m_CountCheck != 3)
		m_Maker3->SetShow(false);
	if(m_CountCheck == 4)
	{
		m_Maker1->SetShow(true);
		m_Maker1->SetPos(-100.0f,50.0f);
		m_Maker2->SetShow(true);
		m_Maker2->SetPos(-100.0f,0.0f);
		m_Maker3->SetShow(true);
		m_Maker3->SetPos(-100.0f,-50.0f);
	}
	
	m_Maker1->MoveX(cosf(m_fEffect));
	m_Maker1->MoveY(sinf(m_fEffect));
	m_Maker2->MoveX(cosf(m_fEffect));
	m_Maker2->MoveY(sinf(m_fEffect));
	m_Maker3->MoveX(cosf(m_fEffect));
	m_Maker3->MoveY(sinf(m_fEffect));

	m_fEffect += 1.0f;

	if(m_Alpha <= 1.0f)
		m_Alpha += 0.3f*dt;


	m_Topni->SetZRot(m_ZRot);
	D_CAMERA->SetPos(m_stCamPos);
	m_TeamName->SetAlpha(m_Alpha);
	m_MouseAni->SetPos(g_fMouseX+10.0f,g_fMouseY-10.0f);
	if(D_INPUT->IsKeyDown(VK_SPACE))
	{
		Init();
		D_SOUND->Pause(m_SHandle,true);
		D_SCENE->ChangeScene("Menu");
	}
	CRootScene::Update(pSceneWork, dt);
}

void CCredit::Render(CSceneWork* pSceneWork)
{


	CRootScene::Render(pSceneWork);
}

void CCredit::Exit(CSceneWork* pSceneWork)
{
	Destroy();				//!< 현재 씬에서 메모리 잡은거 전부 해제


	CRootScene::Exit(pSceneWork);
}

void CCredit::fuck(stMouseInfo	stPos)
{
	g_fMouseX = CEMMath::ScreenToWorld(stPos.m_nX , stPos.m_nY).m_fX;
	g_fMouseY =  CEMMath::ScreenToWorld(stPos.m_nX , stPos.m_nY).m_fY;
}

void CCredit::MouseDownEvent(stMouseInfo stPos, enumMouseButton eButton)
{
	CEMPlane* pPlane = (CEMPlane*)AABBvsRay(stPos.m_nX, stPos.m_nY,-1);
	if(pPlane != NULL)
	{
		if(g_bEffectSoundCheck == false)
			D_SOUND->Play(D_SOUND->FileOpen("Data/Sound/Tick.mp3",false),g_SVolume,false);

		g_MousePosition =  CEMMath::ScreenToWorld(stPos.m_nX , stPos.m_nY);
		for(int i =0; i<5; i++)
		{
			stdEMString sCommitName  = FloatToEMString(CEMMath::RandomIntInRange(0, 1000000));
			Particles(g_MousePosition,sCommitName);
		}
	}
	
	if(pPlane == m_BackButton)
	{
		D_SOUND->Stop(m_SHandle);
		D_SCENE->ChangeSceneFade("Menu");
	}

	CEMAnimation* pPlane2 = (CEMAnimation*)AABBvsRay(stPos.m_nX, stPos.m_nY,-1);
	
}

void CCredit::MouseUpEvent(stMouseInfo stPos, enumMouseButton eButton)
{
 		CEMPlane* pPlane = (CEMPlane*)AABBvsRay(stPos.m_nX, stPos.m_nY,-1);
	
}

void CCredit::MouseMoveEvent(stMouseInfo stPos)
{
	CEMPlane* pPlane = (CEMPlane*)AABBvsRay(stPos.m_nX, stPos.m_nY,-1);
	if(pPlane == m_BackButton)
		m_BackButton->SetSize(0.7f);
	else
		m_BackButton->SetSize(0.5f);
	fuck(stPos);

}

HRESULT CCredit::WindowMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
	case WM_LBUTTONDOWN:
		{
			int x = 0;
		}break;
	}
	return msg;
}


void CCredit::BeginContact(b2Contact* contact)
{
	CEMPhysicRoot::BeginContact(contact);
	//아래에 코드를 작성하세요


}

void CCredit::EndContact(b2Contact* contact)
{
	CEMPhysicRoot::EndContact(contact);
	//아래에 코드를 작성하세요

}

void CCredit::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
{
	CEMPhysicRoot::PreSolve(contact, oldManifold);
	//아래에 코드를 작성하세요

}

void CCredit::PostSolve(const b2Contact* contact, const b2ContactImpulse* impulse)
{
	CEMPhysicRoot::PostSolve(contact, impulse);
	//아래에 코드를 작성하세요

}
void CCredit::Particles(stEMVec2 stPos,stdEMString sCommitName)
{
	m_MouseParticle = new CEMParticle();
	m_MouseParticle->SetColor(10.0f, 10.0f, 10.0f);
	m_MouseParticle->SetPos(stPos);
	m_MouseParticle->SetSize(3.6f, 3.6f);      
	//m_pParticle->ResetTextureInfo();
	m_MouseParticle->SetTexture("Data/Star.png"); 
	m_MouseParticle->SetMaxParticles(4);      
	m_MouseParticle->SetPerSecond(75.0f);      
	m_MouseParticle->SetParticleLifetime(0.8f);     
	m_MouseParticle->SetSpread(3500.0f);     
	m_MouseParticle->SetBlend(true);
	m_MouseParticle->SetFrustumCulling(false);
	m_MouseParticle->SetBoundingBoxCalc(false);
	m_MouseParticle->SetEndScale(1.0f);
	m_MouseParticle->SetSpeedRange(55.0f, 20.0f); 
	m_MouseParticle->SetGravity(stEMVec3(0.0f, -100.0f,0.0f)); 
	m_MouseParticle->SetShow(true);
	m_MouseParticle->SetLifeTime(0.8f);
	
	Commit(-3, sCommitName, m_MouseParticle);
}