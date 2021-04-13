#pragma once
#include "Entity.h"
class PProjectile : public Entity
{
private:
	//Funkcje
	//virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
	//Funckje
	void update();

	//Konstruktory i destruktor
	PProjectile() : Entity() {};
	PProjectile(sf::Vector2f nPos);
	~PProjectile() {};
};