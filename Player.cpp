/*
	This class Player is where we get the player/robot name and get random card for game
*/

#include "Player.h"

Player::Player()
{
	std::cout << "Enter a name , then press the [Enter] key - ";
	std::getline(std::cin, this->m_name);
	std::cout << "\n";

	this->m_hand = 0;
	this->m_card = 0;

	system("cls");
}

// Function to get a random card number
int Player::randomCard()
{
	this->m_card = rand() % 11 + 1;

	this->m_hand += this->m_card;

	return this->m_card;

}

bool Player::checkIfOver()
{
	if (this->m_hand > 21)
		return true;
	else
		return false;
}