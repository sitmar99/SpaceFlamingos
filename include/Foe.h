#pragma once
#include "Ship.h"
class Foe : public Ship
{
private:
	//Zmienne
	bool bottom;
	int points;

public:
	//Funkcje
	bool isBottom() { return bottom; };
	void setBottom(bool nBottom) { bottom = nBottom; };
	int getPoints() { return points; };
	void update();

	//Konstruktory i destruktor
	Foe() : Ship() {};
	Foe(sf::Vector2f nPos, int pts, bool bot);
	~Foe() {};
};

