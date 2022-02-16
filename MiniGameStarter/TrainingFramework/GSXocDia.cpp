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

GSXocDia::GSXocDia()
{
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

	// button clode
	texture = ResourceManagers::GetInstance()->GetTexture("btn_close.tga");
	std::shared_ptr<GameButton>  button = std::make_shared<GameButton>(model, shader, texture);
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
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}

void GSXocDia::Draw()
{
	m_background->Draw();
	/*m_Dia->Draw();
	m_Bat->Draw();*/
	m_BatDia->Draw();
	
	/*m_score->Draw();*/
	for (auto it : m_listButton)
	{
		it->Draw();
	}
}