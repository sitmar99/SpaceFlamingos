#include "Player.h"

Player::Player(sf::Vector2f nPos) : Ship(nPos)
{
	this->setHP(3);
	this->setSize(30);

	sf::Texture* t = this->getTexture();
	sf::Sprite* s = this->getSprite();

	t->loadFromFile("sprites/Witch.png");
	s->setTexture(*t);
	s->setTextureRect(sf::IntRect(97, 164, 30, 30));
	s->setPosition(this->getPos());
	s->setScale(sf::Vector2f(2.2, 2.2));
}
