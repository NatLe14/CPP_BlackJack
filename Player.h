#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <limits>


class Player
{
private:
	std::string m_name;
	int m_hand;
	int m_card;

public:
	Player();

	//getters
	const std::string getName() const { return this->m_name; }
	const int getHand() const { return this->m_hand; }

	//functions
	int randomCard();
	bool checkIfOver();
};

