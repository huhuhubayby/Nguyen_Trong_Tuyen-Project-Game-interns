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
	
	m_Click1 = false;
	m_Click2 = false;
	m_Click3 = false;

	m_Vel = 2;
	m_PosX = (float)Globals::screenWidth / 2;

	m_bau = false;
	m_cua=false;
	m_ga=false;
	m_tom=false;
	m_ca=false;
	m_huou=false;

	m_model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	m_shader = ResourceManagers::GetInstance()->GetShader("TextureShader");

	m_cuoc_bau = 0;
	m_cuoc_ca = 0;
	m_cuoc_cua = 0;
	m_cuoc_ga = 0;
	m_cuoc_huou = 0;
	m_cuoc_tom = 0;

	m_xuc1 = 0;
	m_xuc2 = 0;
	m_xuc3 = 0;

	m_flagChose = 0;
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

	// effect chose
	texture = ResourceManagers::GetInstance()->GetTexture("chose_baucua.tga");
	m_EffectChose = std::make_shared<Sprite2D>(model, shader, texture);
	m_EffectChose->Set2DPosition(100, 400);
	m_EffectChose->SetSize(100, 80);

	// effect chinh xac
	texture = ResourceManagers::GetInstance()->GetTexture("chinhxac_baucua.tga");
	m_EffectChose_cx = std::make_shared<Sprite2D>(model, shader, texture);
	m_EffectChose_cx->Set2DPosition(100, 400);
	m_EffectChose_cx->SetSize(100, 80);

	

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
		if (!m_Click1 && !m_Click2) {
			
			m_Click1 = true;
			/*m_times = clock();*/
			m_timeBegin = clock();
			//return;
		}
		else if (!m_Click2 && m_Click1) {
			
			m_Click2 = true;
			m_Click1 = false;
			m_times = clock();
			m_timeBegin = clock();
			radomXuc();
			//return;
		}
		else if (!m_Click3 && m_Click2) {
			
			//m_Click3 = true;
			m_Click1 = false;
			m_Click2 = false;

			m_bau = false;
			m_cua = false;
			m_ga = false;
			m_tom = false;
			m_ca = false;
			m_huou = false;

			m_xuc1 = 0;
			m_xuc2 = 0;
			m_xuc3 = 0;
			m_flagChose = 0;
		}
		});
	m_listButton.push_back(button);

	// button chip 2
	texture = ResourceManagers::GetInstance()->GetTexture("chip2.tga");
	 button = std::make_shared<GameButton>(model, shader, texture);
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(100, 650);
	button->SetSize(60, 60);
	button->SetOnClick([this]() {
		
		m_BoderChip->Set2DPosition(100, 650);
		if (Globals::moneys >= 2 && m_xuc1==0) {
			
			Cuoc(2);
		}

		});
	m_listButton.push_back(button);

	// button chip 5
	texture = ResourceManagers::GetInstance()->GetTexture("chip5.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(100 + 60 + 30, 650);
	button->SetSize(60, 60);
	button->SetOnClick([this]() {
		
		m_BoderChip->Set2DPosition(100 + 60 + 30, 650);
		if (Globals::moneys >= 5 && m_xuc1 == 0) {
			
			Cuoc(5);
		}
		});
	m_listButton.push_back(button);

	// button chip 10
	texture = ResourceManagers::GetInstance()->GetTexture("chip10.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(100 + 60 * 2 + 30 * 2, 650);
	button->SetSize(60, 60);
	button->SetOnClick([this]() {
		
		m_BoderChip->Set2DPosition(100 + 60 * 2 + 30 * 2, 650);
		if (Globals::moneys >= 10 && m_xuc1 == 0) {
			
			Cuoc(10);
		}
		});
	m_listButton.push_back(button);

	// button chip 20
	texture = ResourceManagers::GetInstance()->GetTexture("chip20.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(100 + 60 * 3 + 30 * 3, 650);
	button->SetSize(60, 60);
	button->SetOnClick([this]() {
		
		m_BoderChip->Set2DPosition(100 + 60 * 3 + 30 * 3, 650);
		if (Globals::moneys >= 20 && m_xuc1 == 0) {
			
			Cuoc(20);
		}
		});
	m_listButton.push_back(button);

	// button chip 25
	texture = ResourceManagers::GetInstance()->GetTexture("chip25.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(100 + 60 * 0 + 30 * 0, 650 + 60 + 30);
	button->SetSize(60, 60);
	button->SetOnClick([this]() {
		
		m_BoderChip->Set2DPosition(100 + 60 * 0 + 30 * 0, 650 + 60 + 30);
		if (Globals::moneys >= 25 && m_xuc1 == 0) {
			
			Cuoc(25);
		}
		});
	m_listButton.push_back(button);

	// button chip 50
	texture = ResourceManagers::GetInstance()->GetTexture("chip50.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(100 + 60 * 1 + 30 * 1, 650 + 60 + 30);
	button->SetSize(60, 60);
	button->SetOnClick([this]() {
		
		m_BoderChip->Set2DPosition(100 + 60 * 1 + 30 * 1, 650 + 60 + 30);
		if (Globals::moneys >= 50 && m_xuc1 == 0) {
			
			Cuoc(50);
		}
		});
	m_listButton.push_back(button);

	// button chip 100
	texture = ResourceManagers::GetInstance()->GetTexture("chip100.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(100 + 60 * 2 + 30 * 2, 650 + 60 + 30);
	button->SetSize(60, 60);
	button->SetOnClick([this]() {
		
		m_BoderChip->Set2DPosition(100 + 60 * 2 + 30 * 2, 650 + 60 + 30);
		if (Globals::moneys >= 100 && m_xuc1 == 0) {
			
			Cuoc(100);
		}
		});
	m_listButton.push_back(button);

	// button chip 200
	texture = ResourceManagers::GetInstance()->GetTexture("chip200.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(100 + 60 * 3 + 30 * 3, 650 + 60 + 30);
	button->SetSize(60, 60);
	button->SetOnClick([this]() {
		
		m_BoderChip->Set2DPosition(100 + 60 * 3 + 30 * 3, 650 + 60 + 30);
		if (Globals::moneys >= 200 && m_xuc1 == 0) {
			
			Cuoc(200);
		}
		});
	m_listButton.push_back(button);

	// button bau
	texture = ResourceManagers::GetInstance()->GetTexture("btn_bau_ico.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(100, 400);
	button->SetSize(100, 80);
	button->SetOnClick([this]() {
		if (m_bau) {
			m_bau = false;
			m_flagChose = 0;
			Globals::moneys += m_cuoc_bau;
			m_cuoc_bau = 0;
		}
		else {
			m_bau = true;
			m_flagChose = 1;
		}
		});
	m_listButton.push_back(button);

	// button cua
	texture = ResourceManagers::GetInstance()->GetTexture("btn_cua_ico.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(100 + 100 + 50, 400);
	button->SetSize(100, 80);
	button->SetOnClick([this]() {
		if (m_cua) {
			m_cua = false;
			m_flagChose = 0;
			Globals::moneys += m_cuoc_cua;
			m_cuoc_cua = 0;
		}
		else {
			m_cua = true;
			m_flagChose = 2;
		}
		});
	m_listButton.push_back(button);

	// button tom
	texture = ResourceManagers::GetInstance()->GetTexture("btn_tom_ico.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(100 + 100 + 100 + 50 + 50, 400);
	button->SetSize(100, 80);
	button->SetOnClick([this]() {
		if (m_tom) {
			m_tom = false;
			m_flagChose = 0;
			Globals::moneys += m_cuoc_tom;
			m_cuoc_tom;

		}
		else {
			m_tom = true;
			m_flagChose = 3;
		}
		});
	m_listButton.push_back(button);

	// button ca
	texture = ResourceManagers::GetInstance()->GetTexture("btn_ca_ico.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(100, 400 + 80 + 50);
	button->SetSize(100, 80);
	button->SetOnClick([this]() {
		if (m_ca) {
			m_ca = false;
			m_flagChose = 0;
			Globals::moneys += m_cuoc_ca;
			m_cuoc_ca = 0;
		}
		else {
			m_ca = true;
			m_flagChose = 4;
		}
		});
	m_listButton.push_back(button);

	// button huou
	texture = ResourceManagers::GetInstance()->GetTexture("btn_huou_ico.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(100 + 100 + 50, 400 + 80 + 50);
	button->SetSize(100, 80);
	button->SetOnClick([this]() {
		if (m_huou) {
			m_huou = false;
			m_flagChose = 0;
			Globals::moneys += m_cuoc_huou;
			m_cuoc_huou = 0;
		}
		else {
			m_huou = true;
			m_flagChose = 5;
		}
		});
	m_listButton.push_back(button);

	// button ga
	texture = ResourceManagers::GetInstance()->GetTexture("btn_ga_ico.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(100 + 100 + 100 + 50 + 50, 400 + 80 + 50);
	button->SetSize(100, 80);
	button->SetOnClick([this]() {
		if (m_ga) {
			m_ga = false;
			m_flagChose = 0;
			Globals::moneys += m_cuoc_ga;
			m_cuoc_ga = 0;
		}
		else {
			m_ga = true;
			m_flagChose = 6;
		}
		});
	m_listButton.push_back(button);

	//// score
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arialbd.ttf");
	m_money = std::make_shared< Text>(shader, font, "$" + std::to_string(Globals::moneys), Vector4(1.0f, 1.0f, 1.0f, 1.0f), 1.5f);
	m_money->Set2DPosition(Vector2(0, 50));
}

void GSBauCua::Exit()
{
	Globals::moneys += (m_cuoc_bau + m_cuoc_ca + m_cuoc_cua + m_cuoc_ga + m_cuoc_huou + m_cuoc_tom);
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
	if (m_Click1) {
		if (((clock() - m_timeBegin) / 1000.f) <= 1.2f) {


			//m_PosX += m_Vel * ((float)(clock() - m_times) / 1000.f);
			if (m_PosX > (((float)Globals::screenWidth / 2) + 20)) {
				m_Vel *= (-1);
			}
			if (m_PosX < (((float)Globals::screenWidth / 2) - 20)) {
				m_Vel *= (-1);
			}

			m_PosX += m_Vel /** ((float)(clock() - m_times) / 1000.f)*/;
			/*m_times = clock();*/
			
			m_BatDia->Set2DPosition(m_PosX, ((float)Globals::screenHeight / 2) - 200);
		}
		else
		{
			
			m_BatDia->Set2DPosition((float)Globals::screenWidth / 2, ((float)Globals::screenHeight / 2) - 200);
			m_PosX = (float)Globals::screenWidth / 2;
			
		}

		
		m_BatDia->Update(deltaTime);
	}
	if (m_Click2) {
		if (((clock() - m_timeBegin) / 1000.f) <= 1.0f) {
			m_PosX -= (200) * ((float)(clock() - m_times) / 1000.f);
			m_times = clock();
			m_Bat->Set2DPosition(m_PosX, ((float)Globals::screenHeight / 2) - 200);
		}
		else
		{

			m_PosX = (float)Globals::screenWidth / 2;
			/*m_Bat->Set2DPosition((float)Globals::screenWidth / 2, ((float)Globals::screenHeight / 2) - 200);*/
			
		}
		m_Bat->Update(deltaTime);
	}
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
	m_money->SetText("$" + std::to_string(Globals::moneys));
}

void GSBauCua::Draw()
{
	m_background->Draw();


	/*m_btnBau->Draw();
	m_btnCua->Draw();
	m_btnTom->Draw();
	m_btnCa->Draw();
	m_btnHuou->Draw();
	m_btnGa->Draw();*/

	//m_score->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}

	m_BoderChip->Draw();
	EffectChose();
	if (!m_Click2) {
		m_BatDia->Draw();
	}
	else
	{
		m_Dia->Draw();
		XucXac(m_xuc1, (float)Globals::screenWidth / 2, ((float)Globals::screenHeight / 2) - 200 - 20);
		XucXac(m_xuc2, ((float)Globals::screenWidth / 2) - 25, ((float)Globals::screenHeight / 2) - 200 + 20);
		XucXac(m_xuc3, ((float)Globals::screenWidth / 2) + 25, ((float)Globals::screenHeight / 2) - 200 + 20);
		m_Bat->Draw();

		m_cuoc_bau = 0;
		m_cuoc_ca = 0;
		m_cuoc_cua = 0;
		m_cuoc_ga = 0;
		m_cuoc_huou = 0;
		m_cuoc_tom = 0;

	}
	m_money->Draw();
}

void GSBauCua::EffectChose() {
	
	auto texture = ResourceManagers::GetInstance()->GetTexture("chose_baucua.tga");
	
	if (m_bau) {
		auto bau = std::make_shared<Sprite2D>(m_model, m_shader, texture);
		bau->Set2DPosition(100, 400);
		bau->SetSize(100, 80);
		bau->Draw();
	}
	if (m_cua) {
		auto cua = std::make_shared<Sprite2D>(m_model, m_shader, texture);
		cua->Set2DPosition(100 + 100 + 50, 400);
		cua->SetSize(100, 80);
		cua->Draw();
	}
	if (m_tom) {
		auto tom = std::make_shared<Sprite2D>(m_model, m_shader, texture);
		tom->Set2DPosition(100 + 100 + 100 + 50 + 50, 400);
		tom->SetSize(100, 80);
		tom->Draw();
	}
	if (m_ca) {

		auto ca= std::make_shared<Sprite2D>(m_model, m_shader, texture);
		ca->Set2DPosition(100, 400 + 80 + 50);
		ca->SetSize(100, 80);
		ca->Draw();
	}
	if (m_huou) {
		auto huou = std::make_shared<Sprite2D>(m_model, m_shader, texture);
		huou->Set2DPosition(100 + 100 + 50, 400 + 80 + 50);
		huou->SetSize(100, 80);
		huou->Draw();
	}
	if (m_ga) {

		auto ga = std::make_shared<Sprite2D>(m_model, m_shader, texture);
		ga->Set2DPosition(100 + 100 + 100 + 50 + 50, 400 + 80 + 50);
		ga->SetSize(100, 80);
		ga->Draw();
	}
}

void GSBauCua::radomXuc() {
	srand(time(NULL));
	m_xuc1 = rand() % (6 - 1 + 1) + 1;
	m_xuc2 = rand() % (6 - 1 + 1) + 1;
	m_xuc3 = rand() % (6 - 1 + 1) + 1;
}

void GSBauCua::XucXac(int chose,float x, float y) {
	m_texture = ResourceManagers::GetInstance()->GetTexture("chinhxac_baucua.tga");
	auto effect= std::make_shared<Sprite2D>(m_model, m_shader, m_texture);
	auto xs = std::make_shared<Sprite2D>(m_model, m_shader, m_texture);
	switch (chose)
	{
	case 1:
		m_texture = ResourceManagers::GetInstance()->GetTexture("bau_ico.tga");
		xs = std::make_shared<Sprite2D>(m_model, m_shader, m_texture);
		xs->Set2DPosition(x, y);
		xs->SetSize(40, 40);

		
		effect->Set2DPosition(100, 400);
		effect->SetSize(100, 80);
		xs->Draw();
		effect->Draw();

		Globals::moneys += (2*m_cuoc_bau*80)/100;
		m_cuoc_bau = 0;

		break;
	case 2:
		m_texture = ResourceManagers::GetInstance()->GetTexture("cua_ico.tga");
		xs = std::make_shared<Sprite2D>(m_model, m_shader, m_texture);
		xs->Set2DPosition(x, y);
		xs->SetSize(40, 40);

		effect->Set2DPosition(100 + 100 + 50, 400);
		effect->SetSize(100, 80);

		xs->Draw();
		effect->Draw();

		Globals::moneys += (2 * m_cuoc_cua * 80) / 100;
		m_cuoc_cua = 0;
		break;
	case 3:
		m_texture = ResourceManagers::GetInstance()->GetTexture("tom_ico.tga");
		xs = std::make_shared<Sprite2D>(m_model, m_shader, m_texture);
		xs->Set2DPosition(x, y);
		xs->SetSize(40, 40);

		effect->Set2DPosition(100 + 100 + 100 + 50 + 50, 400);
		effect->SetSize(100, 80);

		xs->Draw();
		effect->Draw();

		Globals::moneys += (2 * m_cuoc_tom * 80) / 100;
		m_cuoc_tom = 0;
		break;
	case 4:
		m_texture = ResourceManagers::GetInstance()->GetTexture("ca_ico.tga");
		xs = std::make_shared<Sprite2D>(m_model, m_shader, m_texture);
		xs->Set2DPosition(x, y);
		xs->SetSize(40, 40);

		effect->Set2DPosition(100, 400 + 80 + 50);
		effect->SetSize(100, 80);

		xs->Draw();
		effect->Draw();

		Globals::moneys += (2 * m_cuoc_ca * 80) / 100;
		m_cuoc_ca = 0;
		break;
	case 5:
		m_texture = ResourceManagers::GetInstance()->GetTexture("huou_ico.tga");
		xs = std::make_shared<Sprite2D>(m_model, m_shader, m_texture);
		xs->Set2DPosition(x, y);
		xs->SetSize(40, 40);

		effect->Set2DPosition(100 + 100 + 50, 400 + 80 + 50);
		effect->SetSize(100, 80);

		xs->Draw();
		effect->Draw();

		Globals::moneys += (2 * m_cuoc_huou * 80) / 100;
		m_cuoc_huou = 0;
		break;
	case 6:
		m_texture = ResourceManagers::GetInstance()->GetTexture("ga_ico.tga");
		xs = std::make_shared<Sprite2D>(m_model, m_shader, m_texture);
		xs->Set2DPosition(x, y);
		xs->SetSize(40, 40);

		effect->Set2DPosition(100 + 100 + 100 + 50 + 50, 400 + 80 + 50);
		effect->SetSize(100, 80);

		xs->Draw();
		effect->Draw();

		Globals::moneys += (2 * m_cuoc_ga * 80) / 100;
		m_cuoc_ga = 0;
		break;
	default:
		break;
	}
}
void GSBauCua::Cuoc(int cuoc) {
	switch (m_flagChose)
	{
	case 1:
		Globals::moneys -= cuoc;
		m_cuoc_bau += cuoc;
		break;
	case 2:
		Globals::moneys -= cuoc;
		m_cuoc_cua += cuoc;
		break;
	case 3:
		Globals::moneys -= cuoc;
		m_cuoc_tom += cuoc;
		break;
	case 4:
		Globals::moneys -= cuoc;
		m_cuoc_ca += cuoc;
		break;
	case 5:
		Globals::moneys -= cuoc;
		m_cuoc_huou += cuoc;
		break;
	case 6:
		Globals::moneys -= cuoc;
		m_cuoc_ga += cuoc;
		break;
	default:
		break;
	}
}