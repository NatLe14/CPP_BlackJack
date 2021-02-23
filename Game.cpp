/*
	This class Game is the engine of the program.
	Will run the game until it is over
*/

#include "Game.h"

Game::Game()
{
	this->m_running = true;
	this->m_command;
	this->m_GameOver = false;
}

// Function to check if game is over
void Game::endGame()
{
	if (this->player.getHand() == 21 || this->robot.getHand() > 21)
	{
		this->m_GameOver = true;
		std::cout << "You Win! \n";
	}
	else if (this->player.getHand() > 21 || this->robot.getHand() == 21)
	{
		this->m_GameOver = true;
		std::cout << "You Lose! \n";
	}
	else
	{
		std::cout << "It's anyones game!\n";
	}
	
}

// Function to update the game as the game goes on
void Game::update()
{
	std::cout << "Enter D to draw a card or H to hold. First person that is closer to 21 wins! \n";
	std::cin >> this->m_command;

	switch (this->m_command)
	{
	case 'd':
	case 'D':
		std::cout << this->player.getName() << " drew - " << this->player.randomCard() << "\n";
		//Check player
		if (player.checkIfOver())
		{
			this->endGame();
		}
		std::cout << this->robot.getName() << " drew - " << this->robot.randomCard() << "\n\n\n";

		std::cout << this->player.getName() << "'s Hand - " << this->player.getHand() << "\n";
		std::cout << this->robot.getName() << "'s Hand - " << this->robot.getHand() << "\n\n\n";

		this->endGame();

		std::cout << "Press [Enter] to continue... \n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.ignore();
		system("cls");
		break;

	case 'h':
	case 'H':
		if (player.getHand() > robot.getHand())
		{
			while (true)
			{
				std::cout << this->player.getName() << " holds, no card is drawn - \n";
				std::cout << this->robot.getName() << " drew - " << this->robot.randomCard() << "\n\n\n";

				std::cout << this->player.getName() << "'s Hand - " << this->player.getHand() << "\n";
				std::cout << this->robot.getName() << "'s Hand - " << this->robot.getHand() << "\n\n\n";
				if (robot.getHand() >= player.getHand() && robot.getHand() <= 21)
				{
					this->m_GameOver = true;
					std::cout << "You Lose! \n";
					break;
				}
				else if (robot.getHand() == 21)
				{
					this->m_GameOver = true;
					std::cout << "You Lose! \n";
					break;
				}
				
				else
				{
					std::cout << "Press [Enter] to continue... \n";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cin.ignore();
					system("cls");
				}
			}
			
		}
		else if (player.getHand() <= robot.getHand())
		{
			std::cout << "Invalid. Must draw since you are tied with Computer or Computer is closer to 21.\n";
		}

		std::cout << "Press [Enter] to continue... \n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.ignore();
		system("cls");
		break;

	default:
		std::cout << "Not a valid command please try again.\nPress [Enter] to continue...\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.ignore();
		system("cls");
		break;
		
	}
}
