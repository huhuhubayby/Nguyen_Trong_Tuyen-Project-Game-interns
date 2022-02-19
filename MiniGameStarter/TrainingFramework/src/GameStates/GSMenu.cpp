#include "GSMenu.h"
#include "Camera.h"


GSMenu::GSMenu() : GameStateBase(StateType::STATE_MENU), 
	m_background(nullptr), m_listButton(std::list<std::shared_ptr<GameButton>>{}), m_listButtonMenu(std::list<std::shared_ptr<GameButton>>{}), m_textGameName(nullptr)
{
	m_xBegin = 100;
	m_yBegin = 300;
	
	m_xOver = 0;
	m_yOver = 0;
}


GSMenu::~GSMenu()
{
}



void GSMenu::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("background_menu.tga");
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");

	// background
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);

	//// play button
	//texture = ResourceManagers::GetInstance()->GetTexture("btn_play.tga");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	//button->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
	//button->SetSize(200, 200);
	//button->SetOnClick([]() {
	//	GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PLAY);
	//	});
	//m_listButton.push_back(button);

	// sprite dollars
	texture = ResourceManagers::GetInstance()->GetTexture("dolar_ico.tga");
	m_dollarsIco = std::make_shared<GameButton>(model, shader, texture);
	m_dollarsIco->Set2DPosition(Globals::screenWidth/2, 40);
	m_dollarsIco->SetSize(80, 40);
	

	// button shop
	texture = ResourceManagers::GetInstance()->GetTexture("shop_ico.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(50+10, 50+10);
	button->SetSize(80, 80);
	m_listButtonMenu.push_back(button);

	// button setting
	texture = ResourceManagers::GetInstance()->GetTexture("setting_ico.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth- 50,50+10);
	button->SetSize(80, 80);
	m_listButtonMenu.push_back(button);

	// tai xiu
	texture = ResourceManagers::GetInstance()->GetTexture("tai_xiu_ico.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(m_xBegin, m_yBegin+50);
	button->SetSize(80, 80);
	m_listButton.push_back(button);

	// bau cua
	texture = ResourceManagers::GetInstance()->GetTexture("bau_cua_ico.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(m_xBegin+120, m_yBegin+50);
	button->SetSize(80, 80);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_BAUCUA);
		});
	m_listButton.push_back(button);

	// xoc dia
	texture = ResourceManagers::GetInstance()->GetTexture("xoc_dia_ico.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(m_xBegin+120*2, m_yBegin+50);
	button->SetSize(80, 80);
	button->SetOnClick([]() {
			GameStateMachine::GetInstance()->ChangeState(StateType::STATE_XOCDIA);
			});
	m_listButton.push_back(button);

	// exit button
	/*texture = ResourceManagers::GetInstance()->GetTexture("btn_close.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth - 50, 50);
	button->SetSize(50, 50);
	button->SetOnClick([]() {
		exit(0);
		});
	m_listButton.push_back(button);*/

	// game title
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Brightly Crush Shine.otf");
	m_textGameName = std::make_shared< Text>(shader, font, "Game Bai", Vector4(1.0f, 0.5f, 0.0f, 1.0f), 3.0f);
	m_textGameName->Set2DPosition(Vector2(60, 200+50));

	// money
	//shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	font = ResourceManagers::GetInstance()->GetFont("Athletic Outfit.ttf");
	m_money = std::make_shared< Text>(shader, font, "100", Vector4(1.0f, 1.0f, 1.0f, 1.0f), 1.5f);
	m_money->Set2DPosition(Vector2(Globals::screenWidth/2-20, 100));
}

void GSMenu::Exit()
{
}


void GSMenu::Pause()
{
}

void GSMenu::Resume()
{
}


void GSMenu::HandleEvents()
{
}

void GSMenu::HandleKeyEvents(int key, bool bIsPressed)
{
}

void GSMenu::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	// list button menu
	for (auto btMenu : m_listButtonMenu) {
		if (btMenu->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}

	// list butoon ico
	for (auto button : m_listButton)
	{
		if (button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}


}

// change size ico when over mouse
void GSMenu::HandleMouseMoveEvents(int x, int y)
{   
	for (auto button : m_listButton) 
	{
		if (button->HandleOverEvents(x, y))
		{
			button->SetSize(110, 110);
			
		}
	}
	m_xOver = x;
	m_yOver = y;
}

// check mouse over
void GSMenu::CheckOverMouse()
{
	for (auto button : m_listButton)
	{
		if (button->HandleOverEvents(m_xOver, m_yOver))
		{
			button->SetSize(110, 110);
			
		}
		else
		{
			button->SetSize(80, 80);
		}
	}
}

void GSMenu::Update(float deltaTime)
{

	m_background->Update(deltaTime);
	m_dollarsIco->Update(deltaTime);

	// update list button menu
	for (auto mn : m_listButtonMenu)
	{
		mn->Update(deltaTime);
	}

	// update list button ico
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}

void GSMenu::Draw()
{
	CheckOverMouse(); // kiem tra mouse over
	m_background->Draw();
	m_dollarsIco->Draw();

	// draw list butoon menu
	for (auto mn : m_listButtonMenu)
	{
		mn->Draw();
	}

	// draw list button ico
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	m_textGameName->Draw();
	m_money->Draw();
}
