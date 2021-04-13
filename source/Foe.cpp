#include "Foe.h"

void Foe::update()
{
	this->setPos(this->getPos() + this->getVel());
	this->setVel(sf::Vector2f(this->getVel().x, 0));

	this->getSprite()->setPosition(this->getPos());
}

Foe::Foe(sf::Vector2f nPos, int pts, bool bot)
	: Ship(nPos)
	, points(pts)
	, bottom(bot)
{
	sf::Texture* t = this->getTexture();
	sf::Sprite *s = this->getSprite();
	t->loadFromFile("sprites/Flaming.png");
	s->setTexture(*t);
	s->setTextureRect(sf::IntRect(0, 0, 200, 200));
	s->setPosition(this->getPos());
	s->setScale(sf::Vector2f(0.3, 0.3));
}
