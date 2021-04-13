#include "Wall.h"

Wall::Wall(sf::Vector2f nPos) : Entity(nPos)
{
	this->setSize(15);

	sf::Texture* t = this->getTexture();
	sf::Sprite* s = this->getSprite();
	t->loadFromFile("sprites/Frog.png");
	s->setTexture(*t);
	s->setTextureRect(sf::IntRect(8, 18, 15, 15));
	s->setPosition(this->getPos());
	s->setScale(sf::Vector2f(2, 2));
}
