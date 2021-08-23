#include "stdafx.h"

void COption::Enter(CSceneWork* pSceneWork)
{


	m_OptionImage = new CEMPlane;
	m_OptionImage->SetTexture(this,"Data/Option/Option.png");
	m_OptionImage->SetPos(0.0f,0.0f);
	m_OptionImage->SetSize(0.5);
	m_OptionImage->SetBlend(true);
	m_OptionImage->SetShow(true);

	Commit(0,"Option",m_OptionImage);

	m_SoundPlus = new CEMPlane;
	m_SoundPlus->SetTexture(this,"Data/Option/volumeup.png");
	m_SoundPlus->SetPos(180.0f,-30.0f,0.0f);
	m_SoundPlus->SetSize(0.5f);
	m_SoundPlus->SetBlend(true);
	m_SoundPlus->SetShow(true);

	Commit(-3,"Up",m_SoundPlus);

	m_SoundMinus = new CEMPlane;
	m_SoundMinus->SetTexture(this,"Data/Option/volumeminus.png");
	m_SoundMinus->SetPos(-180.0f,-35.0f,0.0f);
	m_SoundMinus->SetSize(0.5f);
	m_SoundMinus->SetBlend(true);
	m_SoundMinus->SetShow(true);

	Commit(-3,"Minus",m_SoundMinus);

	m_SoundGage = new CEMPlane;
	m_SoundGage->SetTexture(this,"Data/Option/SoundGage.png");
	m_SoundGage->SetPos(m_stSoundGageXY);
	m_SoundGage->SetSize(0.4f,0.7f);
	m_SoundGage->SetBlend(true);
	m_SoundGage->SetShow(true);

	Commit(-1,"Gage",m_SoundGage);

	m_pVolumeControl = new CEMPlane;
	m_pVolumeControl->SetTexture(this,"Data/Button/SoundOff.png");
	m_pVolumeControl->SetPos(100.0f,-100.0f);
	m_pVolumeControl->SetSize(0.2f);
	m_pVolumeControl->SetBlend(false);
	m_pVolumeControl->SetShow(true);

	Commit(0,"배경음온오프",m_pVolumeControl);

	m_pEffectSound = new CEMPlane;
	m_pEffectSound->SetTexture(this,"Data/Button/SoundOff.png");
	m_pEffectSound->SetPos(-100.0f,-100.0f);
	m_pEffectSound->SetSize(0.2f);
	m_pEffectSound->SetBlend(true);
	m_pEffectSound->SetShow(true);

	Commit(0,"효과음온오프",m_pEffectSound);

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

	m_pBackButton = new CEMPlane;
	m_pBackButton->SetTexture("Data/Button/뒤로가기.png");
	m_pBackButton->SetPos(-200.0f,-150.0f,1.0f);
	m_pBackButton->SetBlend(true);
	m_pBackButton->SetSize(0.5f);
	m_pBackButton->SetShow(true);

	Commit(-2,"뒤로가기버튼",m_pBackButton);

	//!=====================================================
	if(g_bSoundCheck == false)
	m_SHandle =D_SOUND->Play(D_SOUND->FileOpen("Data/Sound/GamePlay.mp3"),g_SVolume,true);

	//!=====================================================

	CRootScene::Enter(pSceneWork);
}
void COption::Update(CSceneWork* pSceneWork, float dt)
{
	if(g_bSoundCheck == false)
		D_SOUND->SetVolume(m_SHandle,g_SVolume);

	if(g_bSoundCheck == true && D_SOUND->IsPlaying(m_SHandle) == true)
		D_SOUND->Pause(m_SHandle,true);

	if(g_bSoundCheck == false && D_SOUND->IsPaused(m_SHandle) == true)
		D_SOUND->Pause(m_SHandle,false);
		

	if(g_SVolume >= 1.0f)	
		g_SVolume = 1.0f;	  
	if(g_SVolume <= 0.0f)	
		g_SVolume = 0.0f;	

	if(m_fGageSize >= 5.0f)
		m_fGageSize = 5.0f;
	if(m_fGageSize <= 2.0f)
		m_fGageSize = 2.0f;

	if(D_INPUT->IsKeyDown(VK_SPACE))
	{
		D_SOUND->Stop(m_SHandle);
		D_SCENE->ChangeScene("Menu");
	}
	D_CAMERA->SetPos(m_stCamPos);
	m_MouseAni->SetPos(g_fMouseX,g_fMouseY);
	m_SoundGage->SetSize(m_fGageSize,0.4f);
	m_SoundGage->SetPos(m_stSoundGageXY);
	CRootScene::Update(pSceneWork, dt);
}

void COption::Render(CSceneWork* pSceneWork)
{
	CRootScene::Render(pSceneWork);
}

void COption::Exit(CSceneWork* pSceneWork)
{
	Destroy();				//!< 현재 씬에서 메모리 잡은거 전부 해제

	
	CRootScene::Exit(pSceneWork);
}

void COption::MouseDownEvent(stMouseInfo stPos, enumMouseButton eButton)
{
	CEMPlane* pPlane2 = (CEMPlane*)AABBvsRay(stPos.m_nX, stPos.m_nY,-2);
	if(pPlane2 != NULL)
	{
		D_SOUND->Play(D_SOUND->FileOpen("Data/Sound/Tick.mp3",false),g_SVolume,false);
		g_MousePosition =  CEMMath::ScreenToWorld(stPos.m_nX , stPos.m_nY);
		for(int i =0; i<5; i++)
		{
			stdEMString sCommitName  = FloatToEMString(CEMMath::RandomIntInRange(0, 1000000));
			Particles(g_MousePosition,sCommitName);
		}
	}
	if(pPlane2 == m_pBackButton)
	{
		D_SOUND->Stop(m_SHandle);
		D_SCENE->ChangeSceneFade("Menu");
	}
	CEMPlane* pPlane = (CEMPlane*)AABBvsRay(stPos.m_nX, stPos.m_nY,-3);
	if(pPlane == m_SoundPlus)
	{
		if(g_bEffectSoundCheck == false)
				D_SOUND->Play(D_SOUND->FileOpen("Data/Sound/Button.wav"),g_SVolume,false);
		     
		g_SVolume += 0.1f;
		m_fGageSize += 0.3f;
		if(m_fGageSize <= 5.0f)
			m_stSoundGageXY.m_fX += 10.0f;
	}
	if(pPlane == m_SoundMinus)
	{
		if(g_bEffectSoundCheck == false)
				D_SOUND->Play(D_SOUND->FileOpen("Data/Sound/Button.wav"),g_SVolume,false);

		g_SVolume -= 0.1f;
		m_fGageSize -= 0.3f;
		if(m_fGageSize >= 2.0f)
			m_stSoundGageXY.m_fX -= 10.0f;
	}
	CEMPlane* pPlane3 = (CEMPlane*)AABBvsRay(stPos.m_nX, stPos.m_nY,0);
	if(pPlane3 == m_pEffectSound)
	{
		if(g_bEffectSoundCheck == false)
				D_SOUND->Play(D_SOUND->FileOpen("Data/Sound/Button.wav"),g_SVolume,false);

		if(m_bEffectVolume == false)
		{
			m_bEffectVolume = true;
			g_bEffectSoundCheck = true;
			m_pEffectSound->SetTexture(this,"Data/Button/SoundON.png"); 
		}		
		else if(m_bEffectVolume == true)
		{
				m_pEffectSound->SetTexture(this,"Data/Button/SoundOff.png");
				m_bEffectVolume = false;
				g_bEffectSoundCheck = false;
		}
	}
	if(pPlane3 == m_pVolumeControl)
	{
		if(g_bEffectSoundCheck == false)
				D_SOUND->Play(D_SOUND->FileOpen("Data/Sound/Button.wav"),g_SVolume,false);

		if(g_bSoundCheck == false)
		{
			m_pVolumeControl->SetTexture(this,"Data/Button/SoundON.png");
			g_bSoundCheck = true;
		}
		else if(g_bSoundCheck == true)
		{
			m_pVolumeControl->SetTexture(this,"Data/Button/SoundOff.png");
			g_bSoundCheck = false;
		}
	}
}

void COption::MouseUpEvent(stMouseInfo stPos, enumMouseButton eButton)
{
 	
}

void COption::MouseMoveEvent(stMouseInfo stPos)
{
	CEMPlane* pPlane = (CEMPlane*)AABBvsRay(stPos.m_nX, stPos.m_nY,-1);
	if(pPlane == m_SoundPlus || pPlane == m_SoundMinus || pPlane == m_pVolumeControl || pPlane == m_pEffectSound)
	{
		if(g_bEffectSoundCheck == false && m_bMouseMoveCheck == false)
				D_SOUND->Play(D_SOUND->FileOpen("Data/Sound/Button.wav"),g_SVolume,false);

		if(m_bMouseMoveCheck == false)
			m_bMouseMoveCheck = true;
	}
	else 
		m_bMouseMoveCheck = false;

	if(pPlane == m_pBackButton)
		m_pBackButton->SetSize(0.7f);
	else
		m_pBackButton->SetSize(0.5f);
	fuck(stPos);


}

HRESULT COption::WindowMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
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


void COption::BeginContact(b2Contact* contact)
{
	CEMPhysicRoot::BeginContact(contact);
	//아래에 코드를 작성하세요


}

void COption::EndContact(b2Contact* contact)
{
	CEMPhysicRoot::EndContact(contact);
	//아래에 코드를 작성하세요

}

void COption::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
{
	CEMPhysicRoot::PreSolve(contact, oldManifold);
	//아래에 코드를 작성하세요

}

void COption::PostSolve(const b2Contact* contact, const b2ContactImpulse* impulse)
{
	CEMPhysicRoot::PostSolve(contact, impulse);
	//아래에 코드를 작성하세요

}
void COption::fuck(stMouseInfo stPos)
{
	g_fMouseX = CEMMath::ScreenToWorld(stPos.m_nX , stPos.m_nY).m_fX;
	g_fMouseY =  CEMMath::ScreenToWorld(stPos.m_nX , stPos.m_nY).m_fY;
}
void COption::Particles(stEMVec2 stPos,stdEMString sCommitName)
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