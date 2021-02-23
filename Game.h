#pragma once

#include "Player.h"

class Game
{
private:
	bool m_running;
	char m_command;
	bool m_GameOver;

	//My types
	Player player;
	Player robot;

	//private functions
	void endGame();

public:
	Game();

	//getters
	const bool& Run() const { return this->m_running; }
	const bool& IsGameOver() const { return this->m_GameOver; }

	void update();
};

