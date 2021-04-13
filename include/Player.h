#pragma once
#include "Ship.h"
class Player : public Ship
{
private:

public:
	//Konstruktory i destruktor
	Player() : Ship() {};
	Player(sf::Vector2f nPos);
	~Player() {};
};

