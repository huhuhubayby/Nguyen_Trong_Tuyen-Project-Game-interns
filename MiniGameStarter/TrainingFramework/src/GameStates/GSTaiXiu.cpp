#include "GSTaiXiu.h"

#include "Shader.h"
#include "Texture.h"
#include "Model.h"
#include "Camera.h"
#include "Font.h"
#include "Sprite2D.h"
#include "Sprite3D.h"
#include "Text.h"
#include "GameButton.h"

GSTaiXiu::GSTaiXiu()
{
	m_diem = 0;
	m_tong_cuoc = 0;
	m_cuoc = 0;
	m_FlagBatDau = true;
	m_Chose_chan = false;
	m_Chose_le = false;
}


GSTaiXiu::~GSTaiXiu()
{
}


void GSTaiXiu::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg_taiXiu.tga");

	// background
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition((float)Globals::screenWidth / 2, (float)Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);


	// font_chan
	texture = ResourceManagers::GetInstance()->GetTexture("font_chan.tga");
	m_FontChan = std::make_shared<Sprite2D>(model, shader, texture);
	m_FontChan->Set2DPosition(((float)Globals::screenWidth / 2) - 100, 320);
	m_FontChan->SetSize(100, 100);

	// font_le
	texture = ResourceManagers::GetInstance()->GetTexture("font_le.tga");
	m_FontLe = std::make_shared<Sprite2D>(model, shader, texture);
	m_FontLe->Set2DPosition(((float)Globals::screenWidth / 2) + 100, 320);
	m_FontLe->SetSize(100, 100);

	// boder chip
	texture = ResourceManagers::GetInstance()->GetTexture("boder_chip.tga");
	m_BoderChip = std::make_shared<Sprite2D>(model, shader, texture);
	m_BoderChip->Set2DPosition(100, 550);
	m_BoderChip->SetSize(62, 62);

	// effect chose
	texture = ResourceManagers::GetInstance()->GetTexture("btn_effectChose.tga");
	m_EffectChose = std::make_shared<Sprite2D>(model, shader, texture);
	m_EffectChose->Set2DPosition(((float)Globals::screenWidth / 2) + 100, 320);
	m_EffectChose->SetSize(100, 100);

	// button chan_le green
	texture = ResourceManagers::GetInstance()->GetTexture("btn_green_chan_le.tga");
	m_ChanLe_Yellow = std::make_shared<Sprite2D>(model, shader, texture);
	m_ChanLe_Yellow->Set2DPosition(((float)Globals::screenWidth / 2) + 100, 320);
	m_ChanLe_Yellow->SetSize(100, 100);

	// button chan white
	texture = ResourceManagers::GetInstance()->GetTexture("btn_white_chan_le.tga");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(((float)Globals::screenWidth / 2) - 100, 320);
	button->SetSize(100, 100);
	button->SetOnClick([this]() {
		//
		if (!m_FlagBatDau)
		{
			if (m_Chose_le)
			{
				m_Chose_le = false;
			}
			m_Chose_chan = true;
		}
		});
	m_listButton.push_back(button);

	// button le white
	texture = ResourceManagers::GetInstance()->GetTexture("btn_white_chan_le.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(((float)Globals::screenWidth / 2) + 100, 320);
	button->SetSize(100, 100);
	button->SetOnClick([this]() {
		if (!m_FlagBatDau)
		{

			if (m_Chose_chan)
			{
				m_Chose_chan = false;
			}
			m_Chose_le = true;
		}
		});
	m_listButton.push_back(button);

	// button chip 2
	texture = ResourceManagers::GetInstance()->GetTexture("chip2.tga");
	 button = std::make_shared<GameButton>(model, shader, texture);
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(100, 550);
	button->SetSize(60, 60);
	button->SetOnClick([this]() {
		std::cout << "click chip 2" << std::endl;
		m_BoderChip->Set2DPosition(100, 550);
		if (Globals::moneys >= 2 && (!m_Chose_chan && !m_Chose_le)) {
			Globals::moneys -= 2;
			m_cuoc += 2;
			m_tong_cuoc += 2;
		}

		});
	m_listButton.push_back(button);

	// button chip 5
	texture = ResourceManagers::GetInstance()->GetTexture("chip5.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(100 + 60 + 30, 550);
	button->SetSize(60, 60);
	button->SetOnClick([this]() {
		std::cout << "click chip 5" << std::endl;
		m_BoderChip->Set2DPosition(100 + 60 + 30, 550);
		if (Globals::moneys >= 5 && (!m_Chose_chan && !m_Chose_le)) {
			Globals::moneys -= 5;
			m_cuoc += 5;
			m_tong_cuoc += 5;
		}
		});
	m_listButton.push_back(button);

	// button chip 10
	texture = ResourceManagers::GetInstance()->GetTexture("chip10.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(100 + 60 * 2 + 30 * 2, 550);
	button->SetSize(60, 60);
	button->SetOnClick([this]() {
		std::cout << "click chip 10" << std::endl;
		m_BoderChip->Set2DPosition(100 + 60 * 2 + 30 * 2, 550);
		if (Globals::moneys >= 10 && (!m_Chose_chan && !m_Chose_le)) {
			Globals::moneys -= 10;
			m_cuoc += 10;
			m_tong_cuoc + 10;
		}
		});
	m_listButton.push_back(button);

	// button chip 20
	texture = ResourceManagers::GetInstance()->GetTexture("chip20.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(100 + 60 * 3 + 30 * 3, 550);
	button->SetSize(60, 60);
	button->SetOnClick([this]() {
		std::cout << "click chip 20" << std::endl;
		m_BoderChip->Set2DPosition(100 + 60 * 3 + 30 * 3, 550);
		if (Globals::moneys >= 20 && (!m_Chose_chan && !m_Chose_le)) {
			Globals::moneys -= 20;
			m_cuoc += 20;
			m_tong_cuoc += 20;
		}
		});
	m_listButton.push_back(button);

	// button chip 25
	texture = ResourceManagers::GetInstance()->GetTexture("chip25.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(100 + 60 * 0 + 30 * 0, 550 + 60 + 30);
	button->SetSize(60, 60);
	button->SetOnClick([this]() {
		std::cout << "click chip 25" << std::endl;
		m_BoderChip->Set2DPosition(100 + 60 * 0 + 30 * 0, 550 + 60 + 30);
		if (Globals::moneys >= 25 && (!m_Chose_chan && !m_Chose_le)) {
			Globals::moneys -= 25;
			m_cuoc += 25;
			m_tong_cuoc += 25;
		}
		});
	m_listButton.push_back(button);

	// button chip 50
	texture = ResourceManagers::GetInstance()->GetTexture("chip50.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(100 + 60 * 1 + 30 * 1, 550 + 60 + 30);
	button->SetSize(60, 60);
	button->SetOnClick([this]() {
		std::cout << "click chip 50" << std::endl;
		m_BoderChip->Set2DPosition(100 + 60 * 1 + 30 * 1, 550 + 60 + 30);
		if (Globals::moneys >= 50 && (!m_Chose_chan && !m_Chose_le)) {
			Globals::moneys -= 50;
			m_cuoc += 50;
			m_tong_cuoc += 50;
		}
		});
	m_listButton.push_back(button);

	// button chip 100
	texture = ResourceManagers::GetInstance()->GetTexture("chip100.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(100 + 60 * 2 + 30 * 2, 550 + 60 + 30);
	button->SetSize(60, 60);
	button->SetOnClick([this]() {
		std::cout << "click chip 100" << std::endl;
		m_BoderChip->Set2DPosition(100 + 60 * 2 + 30 * 2, 550 + 60 + 30);
		if (Globals::moneys >= 100 && (!m_Chose_chan && !m_Chose_le)) {
			Globals::moneys -= 100;
			m_cuoc += 100;
			m_tong_cuoc += 100;
		}
		});
	m_listButton.push_back(button);

	// button chip 200
	texture = ResourceManagers::GetInstance()->GetTexture("chip200.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(100 + 60 * 3 + 30 * 3, 550 + 60 + 30);
	button->SetSize(60, 60);
	button->SetOnClick([this]() {
		std::cout << "click chip 200" << std::endl;
		m_BoderChip->Set2DPosition(100 + 60 * 3 + 30 * 3, 550 + 60 + 30);
		if (Globals::moneys >= 200 && (!m_Chose_chan && !m_Chose_le)) {
			Globals::moneys -= 200;
			m_cuoc += 200;
			m_tong_cuoc += 200;
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

	// button bat dau
	texture= ResourceManagers::GetInstance()->GetTexture("batdau_taiXiu.tga");
	m_BatDau = std::make_shared<GameButton>(model, shader, texture);
	m_BatDau->Set2DPosition(Globals::screenWidth/2 , 440);
	m_BatDau->SetSize(90, 50);
	m_BatDau->SetOnClick([this]() {
		if (m_FlagBatDau) {
			m_FlagBatDau = false;
			m_diem = 0;
			m_Chose_chan = false;
			m_Chose_le = false;
		}
		else {
			m_FlagBatDau = true;
			m_diem = 0;
			Globals::moneys += m_cuoc;
			m_cuoc = 0;
			m_tong_cuoc = 0;
		}
		});
	

	// button huy
	texture = ResourceManagers::GetInstance()->GetTexture("huy_taiXiu.tga");
	m_Huy = std::make_shared<Sprite2D>(model, shader, texture);
	m_Huy->Set2DPosition(Globals::screenWidth / 2, 440);
	m_Huy->SetSize(90, 50);
	
	

	// score
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Brightly Crush Shine.otf");
	m_score = std::make_shared< Text>(shader, font, std::to_string(m_diem), TextColor::WHITE, 3.0);
	m_score->Set2DPosition(Vector2((Globals::screenWidth/2)-30, 200));

	//// score
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	 font = ResourceManagers::GetInstance()->GetFont("arialbd.ttf");
	m_money = std::make_shared< Text>(shader, font,"$: " + std::to_string(Globals::moneys), Vector4(1.0f, 1.0f, 1.0f, 1.0f), 1.5f);
	m_money->Set2DPosition(Vector2(0, 50));
}

void GSTaiXiu::Exit()
{
	if (m_tong_cuoc > 0) {
		Globals::moneys += m_cuoc;
	}
}


void GSTaiXiu::Pause()
{
}

void GSTaiXiu::Resume()
{
}


void GSTaiXiu::HandleEvents()
{
}

void GSTaiXiu::HandleKeyEvents(int key, bool bIsPressed)
{
}

void GSTaiXiu::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	if (m_BatDau->HandleTouchEvents(x, y, bIsPressed)) {
		std::cout<<"click bat dau"<<std::endl;
	}
	
	for (auto button : m_listButton)
	{
		if(button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
}

void GSTaiXiu::HandleMouseMoveEvents(int x, int y)
{
}

void GSTaiXiu::Update(float deltaTime)
{
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
	
	if (m_diem >= 100 && m_diem<=999) {
		m_score->Set2DPosition(Vector2((Globals::screenWidth / 2) - 50, 200));
	}
	else if(m_diem>=1000 && m_diem<=5000)
	{
		m_score->Set2DPosition(Vector2((Globals::screenWidth / 2) - 65, 200));
	}
	else {
		m_score->Set2DPosition(Vector2((Globals::screenWidth / 2) - 30, 200));
	}

	m_score->SetText(std::to_string(m_diem));
	if (!m_FlagBatDau) {
		if (!m_Chose_chan && !m_Chose_le) {
			if (m_diem > 5000) {
				m_diem = 0;
				m_FlagBatDau = true;
			}
			else
			{
				m_diem += 1;
			}
			
		}
		else
		{
			/*m_Chose_chan = false;
			m_Chose_le = false;*/
			m_FlagBatDau = true;
			if (m_Chose_chan)
			{
				if (m_diem % 2 == 0) {
					Globals::moneys += (m_cuoc + ((m_cuoc * 70) / 100));
					
				}
			}
			if (m_Chose_le)
			{
				if (m_diem % 2 != 0) {
					Globals::moneys += (m_cuoc + ((m_cuoc * 70) / 100));
					
					
				}
			}
			if (m_diem % 2 == 0) {
				m_ChanLe_Yellow->Set2DPosition(((float)Globals::screenWidth / 2) - 100, 320);
			}
			else
			{
				m_ChanLe_Yellow->Set2DPosition(((float)Globals::screenWidth / 2) + 100, 320);
			}
			m_cuoc = 0;
			m_tong_cuoc = 0;
		}
	}
	
	m_score->Update(deltaTime);
	m_money->SetText("$"+std::to_string(Globals::moneys));
}

void GSTaiXiu::Draw()
{
	m_background->Draw();
	

	

	m_score->Draw();

	if (m_FlagBatDau) {
		m_BatDau->Draw();
	}
	else {
		m_Huy->Draw();
	}
	

	for (auto it : m_listButton)
	{
		it->Draw();
	}
	if (m_Chose_chan || m_Chose_le)
	{
		m_ChanLe_Yellow->Draw();
	}
	
	m_FontChan->Draw();
	m_FontLe->Draw();
	if (m_Chose_chan) {
		m_EffectChose->Set2DPosition(((float)Globals::screenWidth / 2) - 100, 320);
		m_EffectChose->Draw();
	}
	if (m_Chose_le) {
		m_EffectChose->Set2DPosition(((float)Globals::screenWidth / 2) + 100, 320);
		m_EffectChose->Draw();
	}

	m_BoderChip->Draw();
	m_money->Draw();

}