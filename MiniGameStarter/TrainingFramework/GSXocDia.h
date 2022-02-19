#pragma once
#include "GameStates/GameStateBase.h"
//#include <ctime>
#include<time.h>
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
	std::shared_ptr<Sprite2D>				m_ChanLe_Yellow;
	std::shared_ptr<Sprite2D>				m_EffectChose;
	std::shared_ptr<Sprite2D>				m_FontChan;
	std::shared_ptr<Sprite2D>				m_FontLe;

	std::shared_ptr<GameButton>				m_Btn_Chan;
	std::shared_ptr<GameButton>				m_Btn_Le;
	std::shared_ptr<GameButton>				m_Btn_XocDia;

	std::list<std::shared_ptr<GameButton>>	m_listButton;
	
	int      m_count;
	//time_t   times;
	float    m_Vel;
	float    m_PosX;
	clock_t  m_times;
	clock_t  m_timeBegin;
	bool	 m_Chose;
	//bool	 m_Chose_Chan_Le;
};