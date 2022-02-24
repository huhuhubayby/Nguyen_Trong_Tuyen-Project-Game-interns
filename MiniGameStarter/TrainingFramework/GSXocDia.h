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
	GSXocDia(GSXocDia& ob);

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

	void    CreateDia();


	
	
private:
	std::shared_ptr<Sprite2D>				m_background;
	std::shared_ptr<Sprite2D>				m_BatDia;
	std::shared_ptr<Sprite2D>				m_Bat;
	std::shared_ptr<Sprite2D>				m_Dia;
	std::shared_ptr<Sprite2D>				m_ChanLe_Yellow;
	std::shared_ptr<Sprite2D>				m_EffectChose;
	std::shared_ptr<Sprite2D>				m_FontChan;
	std::shared_ptr<Sprite2D>				m_FontLe;
	std::shared_ptr<Sprite2D>				m_BoderChip;
	std::shared_ptr<Sprite2D>				m_Dia_Den;
	std::shared_ptr<Sprite2D>				m_Dia_Do;

	std::shared_ptr<GameButton>				m_Btn_Chan;
	std::shared_ptr<GameButton>				m_Btn_Le;
	std::shared_ptr<GameButton>				m_Btn_XocDia;

	/*std::shared_ptr<GameButton>				m_chip2;
	std::shared_ptr<GameButton>				m_chip5;
	std::shared_ptr<GameButton>				m_chip10;
	std::shared_ptr<GameButton>				m_chip20;
	std::shared_ptr<GameButton>				m_chip25;
	std::shared_ptr<GameButton>				m_chip50;
	std::shared_ptr<GameButton>				m_chip100;
	std::shared_ptr<GameButton>				m_chip200;*/

	std::shared_ptr<Text>					m_money;

	std::list<std::shared_ptr<GameButton>>	m_listButton;
	
	int      m_cuoc;
	//time_t   times;
	float    m_Vel;
	float    m_PosX;
	clock_t  m_times;
	clock_t  m_timeBegin;
	clock_t  m_timeBegin1;
	bool	 m_Chose_chan;
	bool	 m_Chose_le;
	bool	 m_Chose;
	bool	 m_Press_Xuc;
	bool	 m_Action_Xuc;
	bool	 m_Mo_Bat;
	bool	 m_Dong_bat;
	bool	 m_le;
	bool	 m_chan;

	//bool	 m_Chose_Chan_Le;
};