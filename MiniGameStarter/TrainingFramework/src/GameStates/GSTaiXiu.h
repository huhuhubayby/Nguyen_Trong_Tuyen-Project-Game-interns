#pragma once
#include "GameStateBase.h"

class Sprite2D;
class Sprite3D;
class Text;
class GameButton;

class GSTaiXiu :
	public GameStateBase
{
public:
	GSTaiXiu();
	~GSTaiXiu();

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
	std::shared_ptr<Sprite2D>	m_background;
	std::shared_ptr<Sprite2D>   m_FontChan;
	std::shared_ptr<Sprite2D>   m_FontLe;
	std::shared_ptr<Sprite2D>	m_ChanLe_Yellow;
	std::shared_ptr<Sprite2D>   m_EffectChose;

	std::shared_ptr<Sprite2D>   m_BoderChip;
	std::shared_ptr<Text>		m_score;
	std::shared_ptr<Text>		m_money;

	std::list<std::shared_ptr<GameButton>>	m_listButton;

	std::shared_ptr<GameButton> m_BatDau;
	std::shared_ptr<Sprite2D>   m_Huy;
	std::shared_ptr<GameButton> m_Btn_Chan;
	std::shared_ptr<GameButton> m_Btn_Le;



	int  m_diem;
	int  m_cuoc;
	int  m_tong_cuoc;
	bool m_FlagBatDau;
	bool m_Chose_chan;
	bool m_Chose_le;
};

