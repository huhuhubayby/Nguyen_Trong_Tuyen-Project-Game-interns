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

void GSTaiXiu::Exit()
{
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
}

void GSTaiXiu::Draw()
{
	m_background->Draw();
	//m_score->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
}