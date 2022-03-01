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
	m_cuoc = 0;
	m_Vel = 250;
	m_PosX = (float)Globals::screenWidth / 2;
	m_Chose = false;
	m_Chose_chan = false;
	m_Chose_le = false;
	//m_Chose_Chan_Le = false;
	m_Press_Xuc = true;
	m_Mo_Bat = false;
	m_Action_Xuc = false;
	m_Dong_bat = false;

	m_Anyo = false;
}


GSXocDia::~GSXocDia()
{
}

GSXocDia::GSXocDia(GSXocDia& ob)
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


	// dia
	texture = ResourceManagers::GetInstance()->GetTexture("Dia.tga");
	m_Dia = std::make_shared<Sprite2D>(model, shader, texture);
	m_Dia->Set2DPosition((float)Globals::screenWidth / 2, ((float)Globals::screenHeight / 2) - 200);
	m_Dia->SetSize(200, 200);

	// bat
	texture = ResourceManagers::GetInstance()->GetTexture("Bat.tga");
	m_Bat = std::make_shared<Sprite2D>(model, shader, texture);
	m_Bat->Set2DPosition((float)Globals::screenWidth / 2, ((float)Globals::screenHeight / 2) - 200);
	m_Bat->SetSize(200, 200);
	
	// dia do
	texture = ResourceManagers::GetInstance()->GetTexture("mauDia_do.tga");
	m_Dia_Do = std::make_shared<Sprite2D>(model, shader, texture);
	m_Dia_Do->Set2DPosition(((float)Globals::screenWidth / 2)-20, ((float)Globals::screenHeight / 2) - 200);
	m_Dia_Do->SetSize(30, 30);

	// dia den
	texture = ResourceManagers::GetInstance()->GetTexture("mauDia_den.tga");
	m_Dia_Den = std::make_shared<Sprite2D>(model, shader, texture);
	m_Dia_Den->Set2DPosition(((float)Globals::screenWidth / 2)+20, ((float)Globals::screenHeight / 2) - 200);
	m_Dia_Den->SetSize(30, 30);

	// boder chip
	texture = ResourceManagers::GetInstance()->GetTexture("boder_chip.tga");
	m_BoderChip = std::make_shared<Sprite2D>(model, shader, texture);
	m_BoderChip->Set2DPosition(100, 550);
	m_BoderChip->SetSize(62, 62);

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

	// button chip 2
	texture = ResourceManagers::GetInstance()->GetTexture("chip2.tga");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(100,550);
	button->SetSize(60, 60);
	button->SetOnClick([this]() {
		
		m_BoderChip->Set2DPosition(100, 550);
		if (Globals::moneys >= 2 && !m_Anyo) {
			Globals::moneys -= 2;
			m_cuoc += 2;
		}
		
		});
	m_listButton.push_back(button);

	// button chip 5
	texture = ResourceManagers::GetInstance()->GetTexture("chip5.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(100+60+30, 550);
	button->SetSize(60, 60);
	button->SetOnClick([this]() {
		
		m_BoderChip->Set2DPosition(100 + 60 + 30, 550);
		if (Globals::moneys >= 5 && !m_Anyo) {
			Globals::moneys -= 5;
			m_cuoc += 5;
		}
		});
	m_listButton.push_back(button);

	// button chip 10
	texture = ResourceManagers::GetInstance()->GetTexture("chip10.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(100 + 60*2 + 30*2, 550);
	button->SetSize(60, 60);
	button->SetOnClick([this]() {
		
		m_BoderChip->Set2DPosition(100 + 60 * 2 + 30 * 2, 550);
		if (Globals::moneys >= 10 && !m_Anyo) {
			Globals::moneys -= 10;
			m_cuoc += 10;
		}
		});
	m_listButton.push_back(button);

	// button chip 20
	texture = ResourceManagers::GetInstance()->GetTexture("chip20.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(100 + 60 * 3 + 30 * 3, 550);
	button->SetSize(60, 60);
	button->SetOnClick([this]() {
		
		m_BoderChip->Set2DPosition(100 + 60 * 3 + 30 * 3, 550);
		if (Globals::moneys >= 20 && !m_Anyo) {
			Globals::moneys -= 20;
			m_cuoc += 20;
		}
		});
	m_listButton.push_back(button);

	// button chip 25
	texture = ResourceManagers::GetInstance()->GetTexture("chip25.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(100 + 60 * 0 + 30 * 0, 550+60+30);
	button->SetSize(60, 60);
	button->SetOnClick([this]() {
		
		m_BoderChip->Set2DPosition(100 + 60 * 0 + 30 * 0, 550 + 60 + 30);
		if (Globals::moneys >= 25 && !m_Anyo) {
			Globals::moneys -= 25;
			m_cuoc += 25;
		}
		});
	m_listButton.push_back(button);

	// button chip 50
	texture = ResourceManagers::GetInstance()->GetTexture("chip50.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(100 + 60 * 1 + 30 * 1, 550 + 60 + 30);
	button->SetSize(60, 60);
	button->SetOnClick([this]() {
		
		m_BoderChip->Set2DPosition(100 + 60 * 1 + 30 * 1, 550 + 60 + 30);
		if (Globals::moneys >= 50 && !m_Anyo) {
			Globals::moneys -= 50;
			m_cuoc += 50;
		}
		});
	m_listButton.push_back(button);

	// button chip 100
	texture = ResourceManagers::GetInstance()->GetTexture("chip100.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(100 + 60 * 2 + 30 * 2, 550 + 60 + 30);
	button->SetSize(60, 60);
	button->SetOnClick([this]() {
		
		m_BoderChip->Set2DPosition(100 + 60 * 2 + 30 * 2, 550 + 60 + 30);
		if (Globals::moneys >= 100 && !m_Anyo) {
			Globals::moneys -= 100;
			m_cuoc += 100;
		}
		});
	m_listButton.push_back(button);

	// button chip 200
	texture = ResourceManagers::GetInstance()->GetTexture("chip200.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(100 + 60 * 3 + 30 * 3, 550 + 60 + 30);
	button->SetSize(60, 60);
	button->SetOnClick([this]() {
		
		m_BoderChip->Set2DPosition(100 + 60 * 3 + 30 * 3, 550 + 60 + 30);
		if (Globals::moneys >= 200 && !m_Anyo) {
			Globals::moneys -= 200;
			m_cuoc += 200;
		}
		});
	m_listButton.push_back(button);

	// button clode
	texture = ResourceManagers::GetInstance()->GetTexture("btn_close.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth - 50, 50);
	button->SetSize(50, 50);
	button->SetOnClick([]() {
		
		GameStateMachine::GetInstance()->PopState();
		});
	m_listButton.push_back(button);

	//// score
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arialbd.ttf");
	m_money = std::make_shared< Text>(shader, font,"$" +std::to_string(Globals::moneys), Vector4(1.0f, 1.0f, 1.0f, 1.0f), 1.5f);
	m_money->Set2DPosition(Vector2(0, 50));
}



void GSXocDia::Exit()
{
	if (m_cuoc > 0) {
		Globals::moneys += m_cuoc;
	}
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
	if (m_Btn_XocDia->HandleTouchEvents(x, y, bIsPressed) ) {
		if (m_Press_Xuc) {
			m_timeBegin = clock();
			m_Press_Xuc = false;
			
		}
		if(m_Action_Xuc && !m_Dong_bat)  {
			m_Anyo = true;
			m_timeBegin1 = clock();
			m_Mo_Bat = true;
			m_times = clock();
			/*m_Action_Xuc = false;*/
			
		}
		if (m_Dong_bat)
		{
			m_Anyo = false;
			m_Dong_bat = false;
			m_Press_Xuc = true;
			m_Action_Xuc = false;
			m_Mo_Bat = false;
		}

	}

	if (m_Btn_Chan->HandleTouchEvents(x, y, bIsPressed))
	{
		m_Chose = true;
		m_EffectChose->Set2DPosition(((float)Globals::screenWidth / 2) - 100, 400);
		m_Chose_le = false;
		m_Chose_chan = true;
	}

	if (m_Btn_Le->HandleTouchEvents(x, y, bIsPressed))
	{
		m_Chose = true;
		m_EffectChose->Set2DPosition(((float)Globals::screenWidth / 2) + 100, 400);
		m_Chose_chan = false;
		m_Chose_le = true;
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
	
	if (m_Press_Xuc==false && !m_Action_Xuc) {
		if (((clock() - m_timeBegin) / 1000.f) <= 1.0f) {


			m_PosX += m_Vel * ((float)(clock() - m_times) / 1000.f);
			if (m_PosX > (((float)Globals::screenWidth / 2) + 20)) {
				m_Vel *= (-1);
			}
			if (m_PosX < (((float)Globals::screenWidth / 2) - 20)) {
				m_Vel *= (-1);
			}

			m_PosX += m_Vel * ((float)(clock() - m_times) / 1000.f);
			m_times = clock();

			m_BatDia->Set2DPosition(m_PosX, ((float)Globals::screenHeight / 2) - 200);
		}
		else
		{
			m_BatDia->Set2DPosition((float)Globals::screenWidth / 2, ((float)Globals::screenHeight / 2) - 200);
			m_PosX = (float)Globals::screenWidth / 2;
			// chan-le
			srand(time(NULL));
			int res = rand() % (100 - 2 + 1) + 2;
			if (res % 2==0) {
				m_le = true;
			}
			else
			{
				m_le = false;
			}
			
			res= rand() % (200 - 15 + 1) + 15;
			if (res % 2 == 0) {
				m_chan = true;
			}
			else
			{
				m_chan = false;
			}
			m_Action_Xuc = true;

			if ((m_le && m_chan) || (!m_le && !m_chan)) {
				m_ChanLe_Yellow->Set2DPosition(((float)Globals::screenWidth / 2) - 100, 400);
			}
			else {
				m_ChanLe_Yellow->Set2DPosition(((float)Globals::screenWidth / 2) + 100, 400);
			}
		}
		m_BatDia->Update(deltaTime);
	}
	if(m_Mo_Bat && !m_Dong_bat)
	{
		
		if (((clock() - m_timeBegin1) / 1000.f) <= 1.0f) {
			m_PosX += (200) * ((float)(clock() - m_times) / 1000.f);
			m_times = clock();
			m_Bat->Set2DPosition(m_PosX, ((float)Globals::screenHeight / 2) - 200);
		}
		else
		{

			m_PosX = (float)Globals::screenWidth / 2;
			/*m_Bat->Set2DPosition((float)Globals::screenWidth / 2, ((float)Globals::screenHeight / 2) - 200);*/
			m_Dong_bat = true;
			
			if (m_Chose_le ) {
				if ((m_le && !m_chan) || (!m_le && m_chan))
				{
					
					Globals::moneys += (m_cuoc + ((m_cuoc * 70) / 100));
					
					m_cuoc = 0;
				}
				else {
					
					m_cuoc = 0;
				}
			}
			if (m_Chose_chan)
			{
				if ((m_le && m_chan) || (!m_le && !m_chan) ) {
					
					Globals::moneys += (m_cuoc+(( m_cuoc * 70) / 100));
					
					m_cuoc = 0;
				}
				else {
					m_cuoc = 0;
				}
			}
			
			//m_ChanLe_Yellow->Update(deltaTime);
		}
		m_Dia->Update(deltaTime);
		m_Bat->Update(deltaTime);
	}
	
	
	m_Btn_Chan->Update(deltaTime);
	m_Btn_Le->Update(deltaTime);
	

	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
	//m_count++;
	m_money->SetText("$"+std::to_string(Globals::moneys));
	m_money->Update(deltaTime);
}

void GSXocDia::Draw()
{
	m_background->Draw();
	
	if (!m_Mo_Bat) {
		m_BatDia->Draw();
	}
	if(m_Mo_Bat) {
		m_Dia->Draw();
		CreateDia();
		m_Bat->Draw();
		
		//m_Dia_Den->Draw();
		//m_Dia_Do->Draw();
		
	}
	
	
	/*m_score->Draw();*/

	// draw list button
	m_Btn_XocDia->Draw();

	

	m_Btn_Chan->Draw();
	m_Btn_Le->Draw();

	if (m_Mo_Bat) {
		m_ChanLe_Yellow->Draw();
	}

	for (auto it : m_listButton)
	{
		it->Draw();
	}

	// draw font chan le
	m_FontChan->Draw();
	m_FontLe->Draw();

	m_BoderChip->Draw();
	/*m_chip2->Draw();
	m_chip5->Draw();
	m_chip10->Draw();
	m_chip20->Draw();
	m_chip25->Draw();
	m_chip50->Draw();
	m_chip100->Draw();
	m_chip200->Draw();*/
	// draw effect chose
	
	if (m_Chose)
	{
		m_EffectChose->Draw();
	}
	
	
	
	m_money->Draw();
}

void GSXocDia::CreateDia() {
	if (m_chan && m_le) {


		auto texture = ResourceManagers::GetInstance()->GetTexture("mauDia_do.tga");
		auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
		auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
		auto a = std::make_shared<Sprite2D>(model, shader, texture);
		a->Set2DPosition(((float)Globals::screenWidth / 2) - 20, ((float)Globals::screenHeight / 2) - 200);
		a->SetSize(30, 30);
		a->Draw();

		auto b = std::make_shared<Sprite2D>(model, shader, texture);
		b->Set2DPosition(((float)Globals::screenWidth / 2) + 20, ((float)Globals::screenHeight / 2) - 200);
		b->SetSize(30, 30);
		b->Draw();
	}
	else if(!m_chan && !m_le) {


		auto texture = ResourceManagers::GetInstance()->GetTexture("mauDia_den.tga");
		auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
		auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
		auto a = std::make_shared<Sprite2D>(model, shader, texture);
		a->Set2DPosition(((float)Globals::screenWidth / 2) - 20, ((float)Globals::screenHeight / 2) - 200);
		a->SetSize(30, 30);
		a->Draw();

		auto b = std::make_shared<Sprite2D>(model, shader, texture);
		b->Set2DPosition(((float)Globals::screenWidth / 2) + 20, ((float)Globals::screenHeight / 2) - 200);
		b->SetSize(30, 30);
		b->Draw();
	}
	else
	{
		m_Dia_Den->Draw();
		m_Dia_Do->Draw();
	}

	
}