#include "stdafx.h"

void CLogo::Enter(CSceneWork* pSceneWork)
{
	//!=====================================================
	//!���� ���̱�

	//!=====================================================

	//!=====================================================
	//!ȭ�鿡 �ؽ��� ����ϱ�
	m_pText = new CEMText("����ü", "Press Any Key");		//!< ȭ�鿡 ��µ� ����
	m_pText->SetColor(CEMColor(128, 33, 121, 200));					//!< ���� r,g,b,a
	m_pText->SetPos(340.0f,500.0f);									//!< �����ġ x,y
	

	Commit(0, "�׽�Ʈ", m_pText);

	m_SchoolLogo = new CEMPlane;
	m_SchoolLogo->SetTexture(this,"Data/KGLogo/k.png");
	m_SchoolLogo->SetPos(0.0f,0.0f,0.0f);
	m_SchoolLogo->SetSize(m_LogoSize);
	m_SchoolLogo->SetBlend(true);
	m_SchoolLogo->SetShow(false);

	Commit(0,"�б��ΰ�",m_SchoolLogo);
	//!=====================================================
	m_KGLogo = new CEMPlane;
	m_KGLogo->SetTexture(this,"Data/KGLogo/kglogo2.png");
	m_KGLogo->SetPos(m_KGXY);
	m_KGLogo->SetSize(m_LogoSize);
	m_KGLogo->SetBlend(true);
	m_KGLogo->SetShow(true);

	Commit(0,"�б��ΰ�1",m_KGLogo);
	
	m_KGLogo2 = new CEMPlane;
	m_KGLogo2->SetTexture(this,"Data/KGLogo/kglogo3.png");
	m_KGLogo2->SetPos(m_KGXY2);
	m_KGLogo2->SetSize(m_LogoSize);
	m_KGLogo2->SetBlend(true);
	m_KGLogo2->SetShow(true);

	Commit(0,"�б��ΰ�2",m_KGLogo2);
	
	m_BackGround = new CEMPlane;
	m_BackGround->SetTexture(this,"Data/KGLogo/kgback.png");
	m_BackGround->SetPos(0.0f,0.0f);
	m_BackGround->SetSize(35.0f);
	m_BackGround->SetBlend(true);
	m_BackGround->SetShow(true);

	Commit(1,"���",m_BackGround);

	m_pClock = new CEMPlane();
	m_pClock->SetTexture(this,"Data/Image/Clock.png");
	m_pClock->SetPos(m_stShakeX.m_fX,0.0f);
	m_pClock->SetBlend(true);
	m_pClock->SetSize(0.09f);
	m_pClock->SetShow(true);

	Commit(0,"�ð�",m_pClock);

	m_pPin = new CEMPlane();
	m_pPin->SetTexture(this,"Data/Image/Pin.png");
	m_pPin->SetPos(m_stShakeX.m_fX,0.0f);
	m_pPin->SetBlend(true);
	m_pPin->SetSize(0.3f);
	m_pPin->SetZRot(m_fPinZRot);
	m_pPin->SetShow(true);

	Commit(0,"��ħ",m_pPin);

	m_pClockBody = new CEMPlane();
	m_pClockBody->SetTexture(this,"Data/Image/ClockBody.png");
	m_pClockBody->SetPos(m_stShakeX.m_fX,23.0f);
	m_pClockBody->SetBlend(true);
	m_pClockBody->SetSize(0.9f);
	m_pClockBody->SetShow(true);

	Commit(0,"�ð����",m_pClockBody);

	
	m_pFlyAttack = new CEMPlane();
	m_pFlyAttack->SetTexture(this,"Data/KGLogo/FlyAttack.png");
	m_pFlyAttack->SetPos(-90.0f,0.0f);
	m_pFlyAttack->SetBlend(true);
	m_pFlyAttack->SetSize(0.5f);
	m_pFlyAttack->SetMirrorType(E_RIGHT_MIRROR);
	m_pFlyAttack->SetShow(false);

	Commit(0,"��Ǯ���ݹ���",m_pFlyAttack);

	m_AniFly = new CEMAnimation(6);
	m_AniFly->SetTexture(this,6,"Data/KGLogo/Fly1.png",
								"Data/KGLogo/Fly2.png",
								"Data/KGLogo/Fly3.png",
								"Data/KGLogo/Fly4.png",
								"Data/KGLogo/Fly5.png",
								"Data/KGLogo/Fly6.png");
	m_AniFly->SetPos(m_stFly);
	m_AniFly->SetSize(0.5f);
	m_AniFly->SetTime(0.15f);
	m_AniFly->SetBlend(true);
	m_AniFly->SetMirrorType(E_RIGHT_MIRROR);
	m_AniFly->SetShow(true);

	Commit(0,"��Ǯ������",m_AniFly);

	if(g_bSoundCheck == false)
		m_SHandle = D_SOUND->Play(D_SOUND->FileOpen("Data/Sound/TickTock.mp3"),g_SVolume,true);

	CRootScene::Enter(pSceneWork);
}
void Init()
{

}
void CLogo::Update(CSceneWork* pSceneWork, float dt)
{

	if(m_stFly.m_fX < -90.0f)
		m_stFly.m_fX += 60.0f*dt;
	else if(m_stFly.m_fX >= -90.0f && m_flyFirstEffect == false)		// ���Ϳͼ� �浹�޴���üũ 
	{
		
		m_flyEffect = true;
		m_flyFirstEffect = true;
	
	}
	if(m_flyFirstEffect == true)										// �浹������ �ִϸ��̼Ǻ���
	{
		m_fFlyAttackTimer += dt;
		if(m_fFlyAttackTimer <= 0.3f)
		{
			m_AniFly->SetShow(false);
			m_pFlyAttack->SetShow(true);
		}
		if(m_fFlyAttackTimer >= 0.4f)
		{
			m_pFlyAttack->SetShow(false);
			m_AniFly->SetMirrorType(E_LEFT_MIRROR);
			m_AniFly->SetShow(true);
			m_stFly.m_fX -= 170.0f*dt;
		}
		if(m_stFly.m_fX <= -350.0f)
			m_AniFly->SetShow(false);
	}



	if(m_bTimerEffect == false && m_flyEffect == true)					// �ð� �����ִ�ȿ�� + ��ħ �����̴�ȿ��
	{
		if(m_bShakeControl	== false)
			m_stShakeX.m_fX -= 5.0f;
		if(m_bShakeControl	== true)
			m_stShakeX.m_fX += 5.0f;
		m_fPinZRot -= 90.0f*dt;
	}
	if(m_stShakeX.m_fX >= 10.0f)
			m_bShakeControl	= false;
	if(m_stShakeX.m_fX <= -10.0f)
			m_bShakeControl	= true;

	if(m_fPinZRot <= 0.0f)
	{
		D_SOUND->Stop(m_SHandle);
		m_fPinZRot = 0.0f;
		m_pPin->SetShow(false);
		m_pClock->SetShow(false);
		m_pClockBody->SetShow(false);
		m_AniFire = new CEMAnimation(6);
		m_AniFire->SetTexture(this,6,"Data/KGLogo/Fire1_1.png",
									 "Data/KGLogo/Fire1_2.png",
									 "Data/KGLogo/Fire1_3.png",
									 "Data/KGLogo/Fire1_4.png",
									 "Data/KGLogo/Fire1_5.png",
									 "Data/KGLogo/Fire1_6.png");
		m_AniFire->SetPos(0.0f,0.0f);
		m_AniFire->SetSize(1.0f);
		m_AniFire->SetLoopType(E_ANI_ONE,E_ANI_ENDING_TYPE_SHOW_FALSE);
		m_AniFire->SetBlend(true);
		m_AniFire->SetTime(0.1f);
		m_AniFire->SetShow(true);
		
		Commit(0,"���߾ִϸ��̼�",m_AniFire);
		if(m_bBombEffect == false)
		{
			D_SOUND->Play(D_SOUND->FileOpen("Data/Sound/Bomb.mp3"),1.0f,false);
			m_bBombEffect = true;
		}
		if(m_AniFire->GetShow() == true)
			m_bTimerEffect = true;
	}
	

	if(m_bTimerEffect == true && m_KGXY.m_fY >= 0.0f)
		m_KGXY.m_fY -= 200.0f*dt;
	else if(m_bTimerEffect == true)
	{
		m_EffectCheck1 = true;
		m_KGCheck1 =		true;
	}
	if(m_bTimerEffect == true &&  m_KGXY2.m_fY <= 0.0f)
		m_KGXY2.m_fY += 200.0f*dt;
	else if(m_bTimerEffect == true)
	{
		m_KGCheck2 = true;
	}

	if(m_EffectCheck1 == true)
	{
		if(m_KGZRot <= 360.0f)
			m_KGZRot += 10.0f;
	}

	if(m_KGCheck1 == true)
		m_KGXY.m_fY =0.0f;
	if( m_KGCheck2 == true)
		m_KGXY2.m_fY =0.0f;


	m_AniFly->SetPos(m_stFly);
	m_pPin->SetZRot(m_fPinZRot);
	m_pClock->SetPos(m_stShakeX.m_fX,0.0f);
	m_pPin->SetPos(m_stShakeX.m_fX,0.0f);
	m_pClockBody->SetPos(m_stShakeX.m_fX,23.0f);
	m_pPin->SetZRot(m_fPinZRot);
	D_CAMERA->SetPos(m_stCamPos);
	m_KGLogo2->SetPos(m_KGXY2);
	m_KGLogo->SetPos(m_KGXY);
	m_KGLogo->SetZRot(m_KGZRot);
	CRootScene::Update(pSceneWork, dt);
}

void CLogo::Render(CSceneWork* pSceneWork)
{


	CRootScene::Render(pSceneWork);
}

void CLogo::Exit(CSceneWork* pSceneWork)
{
	Destroy();				//!< ���� ������ �޸� ������ ���� ����
	

	CRootScene::Exit(pSceneWork);
}

void CLogo::MouseDownEvent(stMouseInfo stPos, enumMouseButton eButton)
{
	CEMPlane* pPlane = (CEMPlane*)AABBvsRay(stPos.m_nX, stPos.m_nY,-1);
	if(pPlane != NULL)
	{
		D_SOUND->Stop(m_SHandle);
		D_SCENE->ChangeSceneFade("Menu");
	}

	CEMAnimation* pPlane2 = (CEMAnimation*)AABBvsRay(stPos.m_nX, stPos.m_nY,-1);
	
}

void CLogo::MouseUpEvent(stMouseInfo stPos, enumMouseButton eButton)
{
 		CEMPlane* pPlane = (CEMPlane*)AABBvsRay(stPos.m_nX, stPos.m_nY,-1);
	
}

void CLogo::MouseMoveEvent(stMouseInfo stPos)
{
	CEMPlane* pPlane = (CEMPlane*)AABBvsRay(stPos.m_nX, stPos.m_nY,-1);
	
	MousePoint(stPos);

}

HRESULT CLogo::WindowMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
	case WM_KEYDOWN:
		D_SCENE->ChangeSceneFade("Menu");
	}
	return msg;
}


void CLogo::BeginContact(b2Contact* contact)
{
	CEMPhysicRoot::BeginContact(contact);
	//�Ʒ��� �ڵ带 �ۼ��ϼ���


}

void CLogo::EndContact(b2Contact* contact)
{
	CEMPhysicRoot::EndContact(contact);
	//�Ʒ��� �ڵ带 �ۼ��ϼ���

}

void CLogo::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
{
	CEMPhysicRoot::PreSolve(contact, oldManifold);
	//�Ʒ��� �ڵ带 �ۼ��ϼ���

}

void CLogo::PostSolve(const b2Contact* contact, const b2ContactImpulse* impulse)
{
	CEMPhysicRoot::PostSolve(contact, impulse);
	//�Ʒ��� �ڵ带 �ۼ��ϼ���

}
void CLogo::MousePoint(stMouseInfo stPos)
{
	g_fMouseX = CEMMath::ScreenToWorld(stPos.m_nX , stPos.m_nY).m_fX;
	g_fMouseY =  CEMMath::ScreenToWorld(stPos.m_nX , stPos.m_nY).m_fY;
}
