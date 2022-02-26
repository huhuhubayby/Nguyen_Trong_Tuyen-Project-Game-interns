#include "GSBauCua.h"

#include "Shader.h"
#include "Texture.h"
#include "Model.h"
#include "Camera.h"
#include "Font.h"
#include "Sprite2D.h"
#include "Sprite3D.h"
#include "Text.h"
#include "GameButton.h"

GSBauCua::GSBauCua()
{
	m_times = clock();
	m_Press_Xuc = false;
	m_Vel = 250;
	m_PosX = (float)Globals::screenWidth / 2;
}


GSBauCua::~GSBauCua()
{
}


void GSBauCua::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg_bauCua.tga");

	// background
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition((float)Globals::screenWidth / 2, (float)Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);

	// boder chip
	texture = ResourceManagers::GetInstance()->GetTexture("boder_chip_yellow.tga");
	m_BoderChip = std::make_shared<Sprite2D>(model, shader, texture);
	m_BoderChip->Set2DPosition(100, 650);
	m_BoderChip->SetSize(62, 62);

	// Bat Dia
	texture = ResourceManagers::GetInstance()->GetTexture("batDia.tga");
	m_BatDia = std::make_shared<Sprite2D>(model, shader, texture);
	m_BatDia->Set2DPosition((float)Globals::screenWidth / 2, ((float)Globals::screenHeight / 2) - 200);
	m_BatDia->SetSize(200, 200);

	// button bau
	texture= ResourceManagers::GetInstance()->GetTexture("btn_bau_ico.tga");
	m_btnBau= std::make_shared<GameButton>(model, shader, texture);
	m_btnBau->Set2DPosition(100, 400);
	m_btnBau->SetSize(100, 80);
	m_btnBau->SetOnClick([]() {
		std::cout << "click bau" << std::endl;
		});

	// button cua
	texture = ResourceManagers::GetInstance()->GetTexture("btn_cua_ico.tga");
	m_btnCua = std::make_shared<GameButton>(model, shader, texture);
	m_btnCua->Set2DPosition(100+100+50, 400);
	m_btnCua->SetSize(100, 80);
	m_btnCua->SetOnClick([]() {
		std::cout << "click cua" << std::endl;
		});

	// button tom
	texture = ResourceManagers::GetInstance()->GetTexture("btn_tom_ico.tga");
	m_btnTom = std::make_shared<GameButton>(model, shader, texture);
	m_btnTom->Set2DPosition(100 + 100+100 + 50+50, 400);
	m_btnTom->SetSize(100, 80);
	m_btnTom->SetOnClick([]() {
		std::cout << "click tom" << std::endl;
		});

	// button ca
	texture = ResourceManagers::GetInstance()->GetTexture("btn_ca_ico.tga");
	m_btnCa = std::make_shared<GameButton>(model, shader, texture);
	m_btnCa->Set2DPosition(100 , 400+80+50);
	m_btnCa->SetSize(100, 80);
	m_btnCa->SetOnClick([]() {
		std::cout << "click ca" << std::endl;
		});

	// button huou
	texture = ResourceManagers::GetInstance()->GetTexture("btn_huou_ico.tga");
	m_btnHuou = std::make_shared<GameButton>(model, shader, texture);
	m_btnHuou->Set2DPosition(100+100+50, 400 + 80 + 50);
	m_btnHuou->SetSize(100, 80);
	m_btnHuou->SetOnClick([]() {
		std::cout << "click huou" << std::endl;
		});

	// button ga
	texture = ResourceManagers::GetInstance()->GetTexture("btn_ga_ico.tga");
	m_btnGa = std::make_shared<GameButton>(model, shader, texture);
	m_btnGa->Set2DPosition(100 + 100 +100+50+ 50, 400 + 80 + 50);
	m_btnGa->SetSize(100, 80);
	m_btnGa->SetOnClick([]() {
		std::cout << "click ga" << std::endl;
		});

	// button clode
	texture = ResourceManagers::GetInstance()->GetTexture("btn_close.tga");
	std::shared_ptr<GameButton>  button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth - 50, 50);
	button->SetSize(50, 50);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->PopState();
		});
	m_listButton.push_back(button);

	// Xoc dia
	texture = ResourceManagers::GetInstance()->GetTexture("btn_XocDia.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition((float)Globals::screenWidth / 2, ((float)Globals::screenHeight / 2) - 200);
	button->SetSize(200, 200);
	button->SetOnClick([this]() {
		m_Press_Xuc = true;
		m_timeBegin = clock();
		});
	m_listButton.push_back(button);

	// button chip 2
	texture = ResourceManagers::GetInstance()->GetTexture("chip2.tga");
	 button = std::make_shared<GameButton>(model, shader, texture);
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(100, 650);
	button->SetSize(60, 60);
	button->SetOnClick([this]() {
		std::cout << "click chip 2" << std::endl;
		m_BoderChip->Set2DPosition(100, 650);
		if (Globals::moneys >= 2) {
			Globals::moneys -= 2;
			m_cuoc += 2;
		}

		});
	m_listButton.push_back(button);

	// button chip 5
	texture = ResourceManagers::GetInstance()->GetTexture("chip5.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(100 + 60 + 30, 650);
	button->SetSize(60, 60);
	button->SetOnClick([this]() {
		std::cout << "click chip 5" << std::endl;
		m_BoderChip->Set2DPosition(100 + 60 + 30, 650);
		if (Globals::moneys >= 5) {
			Globals::moneys -= 5;
			m_cuoc += 5;
		}
		});
	m_listButton.push_back(button);

	// button chip 10
	texture = ResourceManagers::GetInstance()->GetTexture("chip10.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(100 + 60 * 2 + 30 * 2, 650);
	button->SetSize(60, 60);
	button->SetOnClick([this]() {
		std::cout << "click chip 10" << std::endl;
		m_BoderChip->Set2DPosition(100 + 60 * 2 + 30 * 2, 650);
		if (Globals::moneys >= 10) {
			Globals::moneys -= 10;
			m_cuoc += 10;
		}
		});
	m_listButton.push_back(button);

	// button chip 20
	texture = ResourceManagers::GetInstance()->GetTexture("chip20.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(100 + 60 * 3 + 30 * 3, 650);
	button->SetSize(60, 60);
	button->SetOnClick([this]() {
		std::cout << "click chip 20" << std::endl;
		m_BoderChip->Set2DPosition(100 + 60 * 3 + 30 * 3, 650);
		if (Globals::moneys >= 20) {
			Globals::moneys -= 20;
			m_cuoc += 20;
		}
		});
	m_listButton.push_back(button);

	// button chip 25
	texture = ResourceManagers::GetInstance()->GetTexture("chip25.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(100 + 60 * 0 + 30 * 0, 650 + 60 + 30);
	button->SetSize(60, 60);
	button->SetOnClick([this]() {
		std::cout << "click chip 25" << std::endl;
		m_BoderChip->Set2DPosition(100 + 60 * 0 + 30 * 0, 650 + 60 + 30);
		if (Globals::moneys >= 25) {
			Globals::moneys -= 25;
			m_cuoc += 25;
		}
		});
	m_listButton.push_back(button);

	// button chip 50
	texture = ResourceManagers::GetInstance()->GetTexture("chip50.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(100 + 60 * 1 + 30 * 1, 650 + 60 + 30);
	button->SetSize(60, 60);
	button->SetOnClick([this]() {
		std::cout << "click chip 50" << std::endl;
		m_BoderChip->Set2DPosition(100 + 60 * 1 + 30 * 1, 650 + 60 + 30);
		});
	m_listButton.push_back(button);

	// button chip 100
	texture = ResourceManagers::GetInstance()->GetTexture("chip100.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(100 + 60 * 2 + 30 * 2, 650 + 60 + 30);
	button->SetSize(60, 60);
	button->SetOnClick([this]() {
		std::cout << "click chip 100" << std::endl;
		m_BoderChip->Set2DPosition(100 + 60 * 2 + 30 * 2, 650 + 60 + 30);
		});
	m_listButton.push_back(button);

	// button chip 200
	texture = ResourceManagers::GetInstance()->GetTexture("chip200.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(100 + 60 * 3 + 30 * 3, 650 + 60 + 30);
	button->SetSize(60, 60);
	button->SetOnClick([this]() {
		std::cout << "click chip 200" << std::endl;
		m_BoderChip->Set2DPosition(100 + 60 * 3 + 30 * 3, 650 + 60 + 30);
		});
	m_listButton.push_back(button);

	// score
	/*shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Brightly Crush Shine.otf");
	m_score = std::make_shared< Text>(shader, font, "score: 10", TextColor::RED, 1.0);
	m_score->Set2DPosition(Vector2(5, 25));*/
}

void GSBauCua::Exit()
{
}


void GSBauCua::Pause()
{
}

void GSBauCua::Resume()
{
}


void GSBauCua::HandleEvents()
{
}

void GSBauCua::HandleKeyEvents(int key, bool bIsPressed)
{
}

void GSBauCua::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if (button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
}

void GSBauCua::HandleMouseMoveEvents(int x, int y)
{
}

void GSBauCua::Update(float deltaTime)
{
	if (m_Press_Xuc) {
		if (((clock() - m_timeBegin) / 1000.f) <= 1.5f) {


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
			m_Press_Xuc = false;
		}
		m_BatDia->Update(deltaTime);
	}
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}

void GSBauCua::Draw()
{
	m_background->Draw();
	m_BatDia->Draw();

	m_btnBau->Draw();
	m_btnCua->Draw();
	m_btnTom->Draw();
	m_btnCa->Draw();
	m_btnHuou->Draw();
	m_btnGa->Draw();

	//m_score->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	m_BoderChip->Draw();
}