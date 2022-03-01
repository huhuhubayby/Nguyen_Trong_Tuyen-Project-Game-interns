#pragma once
#include "GameStateBase.h"
#include "GameButton.h"

class GSMenu :
	public GameStateBase
{
public:
	GSMenu();
	~GSMenu();

	void	Init() override;
	void	Exit() override;

	void	Pause() override;
	void	Resume() override;

	void	HandleEvents() override;
	void	HandleKeyEvents(int key, bool bIsPressed) override;
	void	HandleTouchEvents(int x, int y, bool bIsPressed) override;
	void	HandleMouseMoveEvents(int x, int y) override;
	void	Update(float deltaTime) override;
	void	Draw() override;
	void    CheckOverMouse();

private:
	std::shared_ptr<Sprite2D>				m_background;
	std::shared_ptr<Sprite2D>				m_dollarsIco;
	std::list<std::shared_ptr<GameButton>>	m_listButton;
	std::list<std::shared_ptr<GameButton>>  m_listButtonMenu;
	
	std::shared_ptr<Sprite2D>				m_music_off;
	std::shared_ptr<Text>					m_textGameName;
	std::shared_ptr<Text>					m_money;

	int  m_xBegin;
	int  m_yBegin;
	int  m_xOver;
	int  m_yOver;

	bool music_on_off;
	
};

