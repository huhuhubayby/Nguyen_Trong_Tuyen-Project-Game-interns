#pragma once
#include "GameStates/GameStateBase.h"
//#include <ctime>
#include<time.h>
class Sprite2D;
class Sprite3D;
class Text;
class GameButton;

class GSBauCua :
	public GameStateBase
{
public:
	GSBauCua();
	~GSBauCua();

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
	//std::shared_ptr<Text>					m_score;
	std::shared_ptr<Sprite2D>				m_BatDia;
	std::shared_ptr<Sprite2D>				m_Bat;
	std::shared_ptr<Sprite2D>				m_Dia;
	std::shared_ptr<Sprite2D>				m_BoderChip;

	std::shared_ptr<GameButton>				m_btnBau;
	std::shared_ptr<GameButton>				m_btnCua;
	std::shared_ptr<GameButton>				m_btnTom;
	std::shared_ptr<GameButton>				m_btnCa;
	std::shared_ptr<GameButton>				m_btnHuou;
	std::shared_ptr<GameButton>				m_btnGa;

	std::list<std::shared_ptr<GameButton>>	m_listButton;

	int     m_cuoc;
	bool    m_Press_Xuc;
	clock_t m_timeBegin;
	clock_t m_times;
	int     m_Vel;
	int     m_PosX;

};