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

	void    EffectChose();
	void    XucXac(int chose,float x,float y);
	void    radomXuc();
	void    Cuoc(int cuoc);
private:
	std::shared_ptr<Sprite2D>				m_background;
	std::shared_ptr<Text>					m_money;
	std::shared_ptr<Sprite2D>				m_BatDia;
	std::shared_ptr<Sprite2D>				m_Bat;
	std::shared_ptr<Sprite2D>				m_Dia;
	std::shared_ptr<Sprite2D>				m_BoderChip;
	std::shared_ptr<Sprite2D>				m_EffectChose;
	std::shared_ptr<Sprite2D>				m_EffectChose_cx;
	

	std::shared_ptr<Model>					m_model;
	std::shared_ptr<Shader>					m_shader;
	std::shared_ptr<Texture>				m_texture;
	std::list<std::shared_ptr<GameButton>>	m_listButton;

	int     m_cuoc;
	bool    m_Click1;
	bool    m_Click2 ;
	bool    m_Click3;
	bool    m_timeClick;
	clock_t m_timeBegin;
	clock_t m_times;
	int     m_Vel;
	int     m_PosX;


	bool    m_bau;
	bool	m_cua;
	bool    m_ga;
	bool    m_tom;
	bool    m_ca;
	bool    m_huou;

	int				m_xuc1;
	int				m_xuc2;
	int				m_xuc3;

	int m_cuoc_bau, m_cuoc_cua, m_cuoc_ga, m_cuoc_tom, m_cuoc_ca, m_cuoc_huou;

	int   m_flagChose;
	
};