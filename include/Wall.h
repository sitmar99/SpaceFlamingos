#pragma once
#include "Entity.h"
class Wall : public Entity
{
private:

public:
	Wall() : Entity() {};
	Wall(sf::Vector2f nPos);
	~Wall() {};
};

