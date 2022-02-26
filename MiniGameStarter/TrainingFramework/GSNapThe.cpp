#include "GSNapThe.h"

#include "Shader.h"
#include "Texture.h"
#include "Model.h"
#include "Camera.h"
#include "Font.h"
#include "Sprite2D.h"
#include "Sprite3D.h"
#include "Text.h"
#include "GameButton.h"

GSNapThe::GSNapThe()
{
	
}


GSNapThe::~GSNapThe()
{
}


void GSNapThe::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg_napthe.tga");

	// background
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition((float)Globals::screenWidth / 2, (float)Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);

	// the
	texture= ResourceManagers::GetInstance()->GetTexture("Qr.tga");
	m_the= std::make_shared<Sprite2D>(model, shader, texture);
	m_the->Set2DPosition((float)Globals::screenWidth / 2, (float)Globals::screenHeight / 2);
	m_the->SetSize(300, 300);

	// button clode
	texture = ResourceManagers::GetInstance()->GetTexture("btn_close.tga");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth - 50, 50);
	button->SetSize(50, 50);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->PopState();
		});
	m_listButton.push_back(button);

	// score
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arialbd.ttf");
	m_text = std::make_shared< Text>(shader, font, "Quet Ma QR Nap The",TextColor::PURPLE , 1.5f);
	m_text->Set2DPosition(Vector2(50, 200));
}

void GSNapThe::Exit()
{
	
}


void GSNapThe::Pause()
{
}

void GSNapThe::Resume()
{
}


void GSNapThe::HandleEvents()
{
}

void GSNapThe::HandleKeyEvents(int key, bool bIsPressed)
{
}

void GSNapThe::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	

	for (auto button : m_listButton)
	{
		if (button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
}

void GSNapThe::HandleMouseMoveEvents(int x, int y)
{
}

void GSNapThe::Update(float deltaTime)
{
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}

	
}

void GSNapThe::Draw()
{
	m_background->Draw();

	m_the->Draw();

	for (auto it : m_listButton)
	{
		it->Draw();
	}
	m_text->Draw();
}