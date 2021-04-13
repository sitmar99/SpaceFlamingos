#pragma once

#include "Entity.h"

#include <ctime>

class Ship : public Entity
{
private:
	//Zmienne
	int direction;
	int lastShotTime;
	int shotDelay;	

	//Funkcje

public:
	//Funkcje
	bool shoot();
	int getLST() { return lastShotTime; };
	void setLST(int nLST) { lastShotTime = nLST; };
	bool canShoot();

	//Konstruktory i destruktor
	Ship() : Entity() {};
	Ship(sf::Vector2f nPos)
		: Entity(nPos)
		, lastShotTime(0) 
		, shotDelay(1) {};
	~Ship() {};
};

