#pragma once
#include "GameStates/GameStateBase.h"

class Sprite2D;
class Sprite3D;
class Text;
class GameButton;

class GSXocDia :
	public GameStateBase
{
public:
	GSXocDia();
	~GSXocDia();

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

private:
	std::shared_ptr<Sprite2D>				m_background;
	std::shared_ptr<Sprite2D>				m_BatDia;
	std::shared_ptr<Sprite2D>				m_Bat;
	std::shared_ptr<Sprite2D>				m_Dia;
	std::list<std::shared_ptr<GameButton>>	m_listButton;
	

};