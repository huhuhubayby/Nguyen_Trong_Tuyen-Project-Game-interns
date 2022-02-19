#include "GSXocDia.h"

#include "Shader.h"
#include "Texture.h"
#include "Model.h"
#include "Camera.h"
#include "Font.h"
#include "Sprite2D.h"
#include "Sprite3D.h"
#include "Text.h"
#include "GameButton.h"


#include<iostream>

GSXocDia::GSXocDia()
{
	m_times = clock();
	m_count = 0;
	m_Vel = 200;
	m_PosX = (float)Globals::screenWidth / 2;
	m_Chose = false;
	//m_Chose_Chan_Le = false;
}


GSXocDia::~GSXocDia()
{
}


void GSXocDia::Init()
{
	
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg_xocDia.tga");

	// background
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition((float)Globals::screenWidth / 2, (float)Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);

	// Bat Dia
	texture= ResourceManagers::GetInstance()->GetTexture("batDia.tga");
	m_BatDia = std::make_shared<Sprite2D>(model, shader, texture);
	m_BatDia->Set2DPosition((float)Globals::screenWidth / 2, ((float)Globals::screenHeight / 2)-200);
	m_BatDia->SetSize(200, 200);


	//// dia
	//texture = ResourceManagers::GetInstance()->GetTexture("Dia.tga");
	//m_Dia = std::make_shared<Sprite2D>(model, shader, texture);
	//m_Dia->Set2DPosition((float)Globals::screenWidth / 2, (float)Globals::screenHeight / 2);
	//m_Dia->SetSize(200, 200);

	//// bat
	//texture = ResourceManagers::GetInstance()->GetTexture("Bat.tga");
	//m_Bat = std::make_shared<Sprite2D>(model, shader, texture);
	//m_Bat->Set2DPosition((float)Globals::screenWidth / 2, (float)Globals::screenHeight / 2);
	//m_Bat->SetSize(200, 200);
		

	// font_chan
	texture = ResourceManagers::GetInstance()->GetTexture("font_chan.tga");
	m_FontChan = std::make_shared<Sprite2D>(model, shader, texture);
	m_FontChan->Set2DPosition(((float)Globals::screenWidth / 2) - 100, 400);
	m_FontChan->SetSize(100, 100);

	// font_le
	texture = ResourceManagers::GetInstance()->GetTexture("font_le.tga");
	m_FontLe = std::make_shared<Sprite2D>(model, shader, texture);
	m_FontLe->Set2DPosition(((float)Globals::screenWidth / 2) + 100, 400);
	m_FontLe->SetSize(100, 100);

	// effect chose
	texture= ResourceManagers::GetInstance()->GetTexture("btn_effectChose.tga");
	m_EffectChose = std::make_shared<Sprite2D>(model, shader, texture);
	m_EffectChose->Set2DPosition(((float)Globals::screenWidth / 2) + 100, 400);
	m_EffectChose->SetSize(100, 100);

	// button chan_le yellow
	texture = ResourceManagers::GetInstance()->GetTexture("btn_yellow_chan_le.tga");
	m_ChanLe_Yellow = std::make_shared<Sprite2D>(model, shader, texture);
	m_ChanLe_Yellow->Set2DPosition(((float)Globals::screenWidth / 2) + 100, 400);
	m_ChanLe_Yellow->SetSize(100, 100);

	// button chan white
	texture = ResourceManagers::GetInstance()->GetTexture("btn_white_chan_le.tga");
	m_Btn_Chan = std::make_shared<GameButton>(model, shader, texture);
	m_Btn_Chan->Set2DPosition(((float)Globals::screenWidth / 2) - 100, 400);
	m_Btn_Chan->SetSize(100, 100);
	m_Btn_Chan->SetOnClick([]() {
		//
		std::cout<<"Click Chan"<<std::endl;
		
		});
	

	// button le white
	texture = ResourceManagers::GetInstance()->GetTexture("btn_white_chan_le.tga");
	m_Btn_Le = std::make_shared<GameButton>(model, shader, texture);
	m_Btn_Le->Set2DPosition(((float)Globals::screenWidth / 2) + 100, 400);
	m_Btn_Le->SetSize(100, 100);
	m_Btn_Le->SetOnClick([]() {
		std::cout << "click le" << std::endl;
		});
	
	// Xoc dia
	texture = ResourceManagers::GetInstance()->GetTexture("btn_XocDia.tga");
	m_Btn_XocDia = std::make_shared<GameButton>(model, shader, texture);
	m_Btn_XocDia->Set2DPosition((float)Globals::screenWidth / 2, ((float)Globals::screenHeight / 2) - 200);
	m_Btn_XocDia->SetSize(200, 200);
	m_Btn_XocDia->SetOnClick([]() {
		std::cout << "click xoc dia" << std::endl;
		});

	// button clode
	texture = ResourceManagers::GetInstance()->GetTexture("btn_close.tga");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth - 50, 50);
	button->SetSize(50, 50);
	button->SetOnClick([]() {
		
		GameStateMachine::GetInstance()->PopState();
		});
	m_listButton.push_back(button);

	//// score
	//shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	//std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Brightly Crush Shine.otf");
	//m_score = std::make_shared< Text>(shader, font, "score: 10", TextColor::RED, 1.0);
	//m_score->Set2DPosition(Vector2(5, 25));
}



void GSXocDia::Exit()
{
}


void GSXocDia::Pause()
{
}

void GSXocDia::Resume()
{
}


void GSXocDia::HandleEvents()
{
}

void GSXocDia::HandleKeyEvents(int key, bool bIsPressed)
{
}

void GSXocDia::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	if (m_Btn_XocDia->HandleTouchEvents(x, y, bIsPressed)) {
		m_timeBegin=clock();
	}

	if (m_Btn_Chan->HandleTouchEvents(x, y, bIsPressed))
	{
		m_Chose = true;
		m_EffectChose->Set2DPosition(((float)Globals::screenWidth / 2) - 100, 400);
	}

	if (m_Btn_Le->HandleTouchEvents(x, y, bIsPressed))
	{
		m_Chose = true;
		m_EffectChose->Set2DPosition(((float)Globals::screenWidth / 2) + 100, 400);
	}

	for (auto button : m_listButton)
	{
		if (button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
}

void GSXocDia::HandleMouseMoveEvents(int x, int y)
{
}

void GSXocDia::Update(float deltaTime)
{
	
	// S=V*T
	/*std::cout <<"time(0): " << clock() << std::endl;
	std::cout <<"times: " << m_times << std::endl;*/
	// animation
	if (((clock() - m_timeBegin) / 1000.f) <= 2.f) {


		m_PosX += m_Vel * ((float)(clock() - m_times) / 1000.f);
		if (m_PosX > (((float)Globals::screenWidth / 2) + 30)) {
			m_Vel *= (-1);
		}
		if (m_PosX < (((float)Globals::screenWidth / 2) - 30)) {
			m_Vel *= (-1);
		}

		m_PosX += m_Vel * ((float)(clock() - m_times) / 1000.f);
		m_times = clock();

		m_BatDia->Set2DPosition(m_PosX, ((float)Globals::screenHeight / 2) - 200);
	}
	else
	{
		m_BatDia->Set2DPosition((float)Globals::screenWidth / 2, ((float)Globals::screenHeight / 2) - 200);
	}

	m_Btn_Chan->Update(deltaTime);
	m_Btn_Le->Update(deltaTime);

	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
	//m_count++;
}

void GSXocDia::Draw()
{
	m_background->Draw();
	/*m_Dia->Draw();
	m_Bat->Draw();*/
	m_BatDia->Draw();
	
	
	/*m_score->Draw();*/

	// draw list button
	m_Btn_XocDia->Draw();

	m_Btn_Chan->Draw();
	m_Btn_Le->Draw();

	for (auto it : m_listButton)
	{
		it->Draw();
	}

	// draw font chan le
	m_FontChan->Draw();
	m_FontLe->Draw();

	// draw effect chose
	if (m_Chose )
	{
		m_EffectChose->Draw();
	}
	
	
}