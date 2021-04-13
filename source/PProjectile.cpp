#include "PProjectile.h"

void PProjectile::update()
{
	this->setPos(this->getPos() + this->getVel());

	this->getSprite()->setPosition(this->getPos());
}

PProjectile::PProjectile(sf::Vector2f nPos) : Entity(nPos)
{
	this->setVel(sf::Vector2f(0, -0.2));
	this->setSize(10);

	sf::Texture* t = this->getTexture();
	sf::Sprite* s = this->getSprite();
	t->loadFromFile("sprites/Potion.png");
	s->setTexture(*t);
	s->setTextureRect(sf::IntRect(0, 0, 440, 370));
	s->setPosition(this->getPos());
	s->setScale(sf::Vector2f(0.07, 0.07));
}
