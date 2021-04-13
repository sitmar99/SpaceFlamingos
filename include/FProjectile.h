#pragma once
#include "Entity.h"
class FProjectile : public Entity
{
private:

public:
	//Funckje
	void update();

	//Konstruktory i destruktor
	FProjectile() : Entity() {};
	FProjectile(sf::Vector2f nPos);
	~FProjectile() {};

};

