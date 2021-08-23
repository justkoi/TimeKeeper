#include "stdafx.h"

void CMenu::Enter(CSceneWork* pSceneWork)
{
	//!=====================================================
	//!화면에 Plane출력하기
	m_GameOverCheck	 = false;
	m_OptionOverCheck	 = false;
	m_CreditOverCheck	 = false;
	m_ExitOverCheck	 = false;
	
	m_pPin = new CEMPlane();
	m_pPin->SetPos(0.0f,40.0f,0.0f);
	m_pPin->SetTexture(this,"Data/Image/Pin.png");
	m_pPin->SetBlend(true);
	m_pPin->SetAlpha(m_fBackGroundAlpha);
	m_pPin->SetSize(0.5f);
	m_pPin->SetShow(true);

	Commit(-2,"바늘",m_pPin);

	m_pPin2 = new CEMPlane();
	m_pPin2->SetPos(0.0f,40.0f,0.0f);
	m_pPin2->SetTexture(this,"Data/Image/Pin2.png");
	m_pPin2->SetBlend(true);
	m_pPin2->SetAlpha(m_fBackGroundAlpha);
	m_pPin2->SetSize(0.5f);
	m_pPin2->SetShow(true);

	Commit(-2,"바늘2",m_pPin2);


	m_pClock = new CEMPlane();
	m_pClock->SetPos(0.0f,40.0f,0.0f);
	m_pClock->SetTexture(this,"Data/Image/Clock.png");
	m_pClock->SetBlend(true);
	m_pClock->SetAlpha(m_fBackGroundAlpha);
	m_pClock->SetSize(0.15f);
	m_pClock->SetShow(true);

	Commit(-2,"시계",m_pClock);

	m_Particle2 = new CEMParticle();
	m_Particle2->SetPos(160.0f, 10.0f, 0.0f);
	m_Particle2->SetColor(10.0f, 10.0f, 10.0f);
	m_Particle2->SetSize(3.6f, 3.6f);      
	//m_Particle2->ResetTextureInfo();
	m_Particle2->SetTexture("Data/Image/Number/0.png"); 
	m_Particle2->SetMaxParticles(7);      
	m_Particle2->SetPerSecond(75.0f);      
	m_Particle2->SetParticleLifetime(2.5f);     
	m_Particle2->SetSpread(500.0f);     
	m_Particle2->SetBlend(true);
	m_Particle2->SetFrustumCulling(false);
	m_Particle2->SetBoundingBoxCalc(false);
	m_Particle2->SetEndScale(1.0f);
	m_Particle2->SetSpeedRange(3.0f, 5.0f); 
	m_Particle2->SetEndColor(m_EndColor);
	m_Particle2->SetGravity(stEMVec3(0.0f,-10.0f,0.0f)); 
	m_Particle2->SetShow(false);

	Commit(-2, "parti2", m_Particle2);
	
	m_Particle = new CEMParticle();
	m_Particle->SetPos(140.0f, -10.0f, 0.0f);
	m_Particle->SetColor(10.0f, 10.0f, 10.0f);
	m_Particle->SetSize(3.6f, 3.6f);      
	//m_pParticle->ResetTextureInfo();
	m_Particle->SetTexture("Data/Image/Number/0.png"); 
	m_Particle->SetMaxParticles(7);      
	m_Particle->SetPerSecond(75.0f);      
	m_Particle->SetParticleLifetime(2.5f);     
	m_Particle->SetSpread(500.0f);     
	m_Particle->SetBlend(true);
	m_Particle->SetFrustumCulling(false);
	m_Particle->SetBoundingBoxCalc(false);
	m_Particle->SetEndScale(1.0f);
	m_Particle->SetSpeedRange(3.0f, 5.0f); 
	m_Particle->SetEndColor(m_EndColor);
	m_Particle->SetGravity(stEMVec3(0.0f, -10.0f,0.0f)); 
	m_Particle->SetShow(false);

	Commit(-2, "parti", m_Particle);


	

	m_Game = new CEMPlane;
	m_Game->SetTexture(this,"Data/Button/GameStart.png");
	m_Game->SetPos(m_GameXY);
	m_Game->SetSize(0.2f);
	m_Game->SetShow(true);

	Commit(-2,"Game",m_Game);
	
	m_Option = new CEMPlane;
	m_Option->SetTexture(this,"Data/Button/Game Option.png");
	m_Option->SetPos(m_OptionXY);
	m_Option->SetSize(0.2f);
	m_Option->SetShow(true);

	Commit(-2,"Option",m_Option);
	
	m_Credit = new CEMPlane;
	m_Credit->SetTexture(this,"Data/Button/Game Credit.png");
	m_Credit->SetPos(m_CreditXY);
	m_Credit->SetSize(0.2f);
	m_Credit->SetShow(true);

	Commit(-2,"Credit",m_Credit);

	m_Exit = new CEMPlane();
	m_Exit->SetTexture(this,"Data/Button/Game Quit.png");
	m_Exit->SetPos(m_ExitXY);
	m_Exit->SetSize(0.2f);
	m_Exit->SetBlend(true);
	m_Exit->SetShow(true);

	Commit(-2,"Exit",m_Exit);

	m_Title = new CEMPlane;
	m_Title->SetTexture(this,"Data/Title.png");
	m_Title->SetPos(m_TitleXY);
	m_Title->SetSize(0.5f);
	m_Title->SetShow(true);
	m_Title->SetBlend(true);

	Commit(-2,"제목",m_Title);


	m_BackGround = new CEMPlane;
	m_BackGround ->SetTexture(this,"Data/BackGround.png");
	m_BackGround ->SetSize(2.0,2.0f);
	m_BackGround->SetBlend(true);
	m_BackGround ->SetPos(0.0f,0.0f,0.0f);
	m_BackGround->SetAlpha(m_fBackGroundAlpha);
	m_BackGround ->SetShow(true);

	Commit(-2,"BackGround",m_BackGround);


	

	m_Wheel1 = new CEMPlane;
	m_Wheel1->SetTexture(this,"Data/Image/Wheel/Wheel1.png");
	m_Wheel1->SetPos(120.0f,30.0f,0.0f);
	m_Wheel1->SetSize(1.0f);
	m_Wheel1->SetBlend(true);
	m_Wheel1->SetShow(true);

	Commit(-2,"Wheel1",m_Wheel1);

	m_Wheel2 = new CEMPlane;
	m_Wheel2->SetTexture(this,"Data/Image/Wheel/Wheel2.png");
	m_Wheel2->SetPos(150.0f,-35.0f,0.0f);
	m_Wheel2->SetSize(1.0f);
	m_Wheel2->SetBlend(true);
	m_Wheel2->SetShow(true);

	Commit(-2,"Wheel2",m_Wheel2);

	m_Wheel3 = new CEMPlane;
	m_Wheel3->SetTexture(this,"Data/Image/Wheel/Wheel1.png");
	m_Wheel3->SetPos(195.0f,0.0f,0.0f);
	m_Wheel3->SetSize(0.7f);
	m_Wheel3->SetBlend(true);
	m_Wheel3->SetShow(true);

	Commit(-2,"Wheel3",m_Wheel3);
	
	m_MouseAni = new CEMAnimation(4);
	m_MouseAni->SetTexture(this,4,"Data/Ani1.png",
								  "Data/Ani2.png",
								  "Data/Ani3.png",
								  "Data/Ani4.png");
	m_MouseAni->SetPos(g_fMouseX+10.0f,g_fMouseY-10.0f);
	m_MouseAni->SetBlend(true);
	m_MouseAni->SetSize(0.6f);
	m_MouseAni->SetShow(true);

	Commit(-3,"우헤헤헤",m_MouseAni);

	
	m_pBackShadow = new CEMPlane;
	m_pBackShadow->SetTexture(this,"Data/BlackShadow.png");
	m_pBackShadow->SetPos(0.0f,0.0f,0.0f);
	m_pBackShadow->SetBlend(true);
	m_pBackShadow->SetSize(0.8f);
	m_pBackShadow->SetAlpha(m_fShadowAlpha);
	m_pBackShadow->SetShow(true);

	Commit(-2,"검은장막",m_pBackShadow);

	

	m_SHandle = D_SOUND->Play(D_SOUND->FileOpen("Data/Sound/GamePlay.mp3"),g_SVolume,true);
	//!=====================================================
	CRootScene::Enter(pSceneWork);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CMenu::Update(CSceneWork* pSceneWork, float dt)
{
	Twinkl(dt);
	Clock(dt);

	if(g_bSoundCheck == true && D_SOUND->IsPaused(m_SHandle) == false)
		D_SOUND->Pause(m_SHandle,true);

	if(g_bSoundCheck == false && D_SOUND->IsPlaying(m_SHandle) == false)
		D_SOUND->Play(m_SHandle,g_SVolume,true);
	
	if(m_fShadowAlpha <= 0.5f)
		m_TitleShow = true;

	if(m_TitleShow == true)                 // 타이틀이 도착햇는지체크하고 타이틀 위아래로흔들기
	{
		if(m_TitleXY.m_fY >= 35.0f)
			m_TitleMoveCheck = true;

		if(m_TitleXY.m_fY <= 26.0f)
			m_TitleMoveCheck = false;

		if(m_TitleMoveCheck == true)
			m_TitleXY.m_fY -= 0.2f;

		if(m_TitleMoveCheck == false)
			m_TitleXY.m_fY += 0.2f;
		
		m_Particle->SetShow(true);
		m_Particle2->SetShow(true);

		m_WheelZRot += 1.0f;
		m_WheelZRot2 -= 1.0f;
		if(m_WheelZRot >= 360.0f)
			m_WheelZRot = 0.0f;

		if(m_WheelZRot2 <= -360.0f)
			m_WheelZRot2 = 0.0f;

		m_Wheel1->SetZRot(m_WheelZRot);
		m_Wheel2->SetZRot(m_WheelZRot);
		m_Wheel3->SetZRot(m_WheelZRot2);
	}

	if(D_INPUT->IsKeyDown(VK_RETURN) && m_SkipCheck == false)					      // (스킵)엔터를누르면 효과안보고 넘어감
	{
		
		m_SkipCheck = true;
	}

	if(m_GameClickCheck == true)     // 게임버튼 눌렷는지 체크
		m_GameChange = true;
	if(m_OptionClickCheck == true)
		m_OptionChange = true;
	if(m_CreditClickCheck == true)
		m_CreditChange = true;
	if(m_ExitClickCheck == true)
		m_ExitChange = true;
	
	

	if(m_GameOverCheck == true)			//게임버튼위에 마우스올라가면 체크해서 크기변경
	{
		m_Game->SetTexture(this,"Data/Button/GameStart.png");
		m_Game->SetSize(0.4f);
	}
	else
	{
		m_Game->SetTexture(this,"Data/Button/GameStart.png");
		m_Game->SetSize(0.2f);
	}
	if(m_OptionOverCheck == true)
	{
		m_Option->SetTexture(this,"Data/Button/Game Option.png");
		m_Option->SetSize(0.4f);
	}
	else
	{
		m_Option->SetTexture(this,"Data/Button/Game Option.png");
		m_Option->SetSize(0.2f);
	}
	if(m_CreditOverCheck == true)
	{
		m_Credit->SetTexture(this,"Data/Button/Game Credit.png");
		m_Credit->SetSize(0.4f);
	}
	else
	{

		m_Credit->SetTexture(this,"Data/Button/Game Credit.png");
		m_Credit->SetSize(0.2f);
	}

	if(m_ExitOverCheck == true)
	{
		m_Exit->SetTexture(this,"Data/Button/Game Quit.png");
		m_Exit->SetSize(0.4f);
	}
	else
	{
		m_Exit->SetTexture(this,"Data/Button/Game Quit.png");
		m_Exit->SetSize(0.2f);
	}

	

	

	if(m_GameClickCheck == true)
		m_Game->SetTexture(this,"Data/Button/GameStart.png");
	if(m_OptionClickCheck == true)
		m_Option->SetTexture(this,"Data/Button/Game Option.png");
	if(m_CreditClickCheck == true)
		m_Credit->SetTexture(this,"Data/Button/Game Credit.png");
	if(m_ExitClickCheck == true)
		m_Exit->SetTexture(this,"Data/Button/Game Quit.png");

	if(m_GameChange ==true)
	{
		m_GameOverCheck = false;
		m_GameChange = false;
	}
	if(m_CreditChange ==true)
	{
		m_CreditOverCheck = false;
		m_CreditChange = false;
	}
	if(m_OptionChange ==true)
	{
		m_OptionOverCheck = false;
		m_OptionChange = false;
	}
	if(m_ExitChange == true)
	{
		m_ExitOverCheck = false;
		m_ExitChange = false;
	}
	
	
	m_pPin2->SetZRot(m_fClockPinZRot);
	m_pPin->SetZRot(m_fClockZRot);
	m_pBackShadow->SetAlpha(m_fShadowAlpha);
	m_BackGround->SetAlpha(m_fBackGroundAlpha);
	m_pPin->SetAlpha(m_fBackGroundAlpha);
	m_pPin2->SetAlpha(m_fBackGroundAlpha);
	m_pClock->SetAlpha(m_fBackGroundAlpha);
	m_MouseAni->SetPos(g_fMouseX,g_fMouseY);
	m_Title->SetPos(m_TitleXY);
	D_SOUND->SetVolume(m_SHandle,g_SVolume);
	D_CAMERA->SetPos(m_stCamPos);

	CRootScene::Update(pSceneWork, dt);
}

void CMenu::Render(CSceneWork* pSceneWork)
{


	CRootScene::Render(pSceneWork);
}



void CMenu::Exit(CSceneWork* pSceneWork)
{
	Destroy();				//!< 현재 씬에서 메모리 잡은거 전부 해제

	CRootScene::Exit(pSceneWork);
}

void CMenu::MouseDownEvent(stMouseInfo stPos, enumMouseButton eButton)
{
	CEMPlane* pPlane = (CEMPlane*)AABBvsRay(stPos.m_nX, stPos.m_nY,-2);
	if(pPlane != NULL && m_SkipCheck == false)					      // 클릭를누르면 효과안보고 넘어감
	{
		m_fShadowAlpha = 0.0f;
		m_fBackGroundAlpha = 1.0f;
		m_SkipCheck = true;
		
	}
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

	if(pPlane == m_Credit)												//마우스 눌렷는지체크 안눌리면 다시false로
		m_CreditClickCheck = true;
	else
		m_CreditClickCheck = false;
	if(pPlane == m_Option)
		m_OptionClickCheck = true;
	else
		m_OptionClickCheck = false;
	if(pPlane == m_Game)
		m_GameClickCheck = true;
	else
		m_GameClickCheck = false;
	if(pPlane == m_Exit)
	{
		m_ExitClickCheck = true;
		exit(1);
	}
	
	


	CEMAnimation* pPlane2 = (CEMAnimation*)AABBvsRay(stPos.m_nX, stPos.m_nY,-1);

}

void CMenu::MouseUpEvent(stMouseInfo stPos, enumMouseButton eButton)
{
 		CEMPlane* pPlane = (CEMPlane*)AABBvsRay(stPos.m_nX, stPos.m_nY,-2);
		if(pPlane == m_Credit)								//마우스 업된위치체크 버튼위면 효과발동 아니면 눌렷던거 취소
		{
			if(m_CreditClickCheck == true)
			{
				D_SOUND->Play(D_SOUND->FileOpen("Data/Sound/Button.wav"),g_SVolume,false);
				m_CreditClickCheck = false;
				D_SOUND->Pause(m_SHandle,true);
				D_SCENE->ChangeSceneFade("Credit");
			}
		}
		else
			m_CreditClickCheck = false;

		if(pPlane == m_Option)
		{
			if(m_OptionClickCheck == true)
			{
				D_SOUND->Play(D_SOUND->FileOpen("Data/Sound/Button.wav"),g_SVolume,false);
				m_OptionClickCheck = false;
				D_SOUND->Pause(m_SHandle,true);
				D_SCENE->ChangeSceneFade("Option");
			}
		}
		else
			m_OptionClickCheck = false;

		if(pPlane == m_Game)
		{
			if(m_GameClickCheck == true)
			{
				D_SOUND->Play(D_SOUND->FileOpen("Data/Sound/Button.wav"),g_SVolume,false);
				m_GameClickCheck = false;
				D_SOUND->Pause(m_SHandle,true);
				D_SCENE->ChangeSceneFade("Stage");
			}
		}
		else
			m_GameClickCheck = false;

		if(pPlane == m_Exit)
		{
			if(m_ExitClickCheck == true)
			{
				m_ExitClickCheck = false;
				
			}
		}
		else
			m_ExitClickCheck = false;
}

void CMenu::MouseMoveEvent(stMouseInfo stPos)
{
	CEMPlane* pPlane = (CEMPlane*)AABBvsRay(stPos.m_nX, stPos.m_nY,-2);

	MousePoint(stPos);
	if(pPlane != NULL)									// 마우스가 버튼위에잇는지없는지 체크
	{
		if(pPlane == m_Game && m_GameOverCheck == false)
		{
			if(g_bEffectSoundCheck == false)
				D_SOUND->Play(D_SOUND->FileOpen("Data/Sound/Button.wav"),g_SVolume,false);
			
			m_GameOverCheck = true;
		}
		else if(pPlane != m_Game)
			m_GameOverCheck = false;

		if(pPlane == m_Option && m_OptionOverCheck == false)
		{
			if(g_bEffectSoundCheck == false)
				D_SOUND->Play(D_SOUND->FileOpen("Data/Sound/Button.wav"),g_SVolume,false);
			
			m_OptionOverCheck = true;
		}
		else if(pPlane != m_Option)
			m_OptionOverCheck = false;

		if(pPlane ==m_Credit && m_CreditOverCheck == false)
		{
			if(g_bEffectSoundCheck == false)
				D_SOUND->Play(D_SOUND->FileOpen("Data/Sound/Button.wav"),g_SVolume,false);
			
			m_CreditOverCheck = true;
		}
		else if(pPlane != m_Credit)
			m_CreditOverCheck = false;

		if(pPlane == m_Exit && m_ExitOverCheck == false)
		{
			if(g_bEffectSoundCheck == false)
				D_SOUND->Play(D_SOUND->FileOpen("Data/Sound/Button.wav"),g_SVolume,false);
			
			m_ExitOverCheck = true;
		}
		else if(pPlane != m_Exit)
			m_ExitOverCheck = false;
		
	}
}

HRESULT CMenu::WindowMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
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


void CMenu::BeginContact(b2Contact* contact)
{
	CEMPhysicRoot::BeginContact(contact);
	//아래에 코드를 작성하세요
	 
	
}

void CMenu::EndContact(b2Contact* contact)
{
	CEMPhysicRoot::EndContact(contact);
	//아래에 코드를 작성하세요

}

void CMenu::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
{
	CEMPhysicRoot::PreSolve(contact, oldManifold);
	//아래에 코드를 작성하세요

}

void CMenu::PostSolve(const b2Contact* contact, const b2ContactImpulse* impulse)
{
	CEMPhysicRoot::PostSolve(contact, impulse);
	//아래에 코드를 작성하세요
}

void CMenu::Twinkl(float dt)
{
	m_fAlphaCount += dt;
	if(m_fAlphaCount >=0.3f && m_fAlphaCount <= 0.4f)
	{
		m_Game->SetShow(false);
		m_Option->SetShow(false);
		m_Credit->SetShow(false);
		m_Exit->SetShow(false);
		m_Title->SetShow(false);
	}
	if(m_fAlphaCount >= 0.5f && m_fAlphaCount <= 0.6f)
	{
		m_Game->SetShow(true);
		m_Option->SetShow(true);
		m_Credit->SetShow(true);
		m_Exit->SetShow(true);
		m_Title->SetShow(true);
	}
	if(m_fAlphaCount >= 0.7f && m_fAlphaCount <= 0.8f)
	{
		m_Game->SetShow(false);
		m_Option->SetShow(false);
		m_Credit->SetShow(false);
		m_Exit->SetShow(false);
		m_Title->SetShow(false);
	}
	if(m_fAlphaCount >= 0.9f && m_fAlphaCount <= 1.0f)
	{
		m_Game->SetShow(true);
		m_Option->SetShow(true);
		m_Credit->SetShow(true);
		m_Exit->SetShow(true);
		m_Title->SetShow(true);
	}
	if(m_fAlphaCount >= 1.0f)
	{
		m_fShadowAlpha -= 0.4f*dt;
		m_fBackGroundAlpha += 0.4f*dt;
	}
}

void CMenu::Clock(float dt)
{
	m_fClockZRot -= 50*dt;
	if(m_fClockZRot <= -360.0f)
		m_fClockZRot = 0.0f;
	
	m_fClockPinZRot -= 4*dt;
}
void CMenu::MousePoint(stMouseInfo stPos)
{
	g_fMouseX = CEMMath::ScreenToWorld(stPos.m_nX , stPos.m_nY).m_fX;
	g_fMouseY =  CEMMath::ScreenToWorld(stPos.m_nX , stPos.m_nY).m_fY;
}

void CMenu::Particles(stEMVec2 stPos,stdEMString sCommitName)
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