/*
	This is a C++ Black Jack game
	The Player enters his/her name and then Computer's name
	Then they play Black Jack!
	Made by Nathan Le
	2/23/2021
*/


#include "Game.h"

int main()
{
	srand((unsigned)time(nullptr));

	Game game;

	while (game.Run() && !game.IsGameOver())
	{
		game.update();
	}

}