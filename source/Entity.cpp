#include "Entity.h"

void Entity::update()
{
	this->pos += this->vel;
	this->vel = sf::Vector2f();

	this->sprite.setPosition(this->getPos());
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->sprite, states);
}

Entity::Entity()
{
	this->hp = 1;
	this->vel = sf::Vector2f();
	this->pos = sf::Vector2f(200.f, 200.f);
	this->size = 20;
	this->maxSpeed = 5;

}

Entity::Entity(sf::Vector2f nPos)
{
	this->hp = 1;
	this->vel = sf::Vector2f();
	this->pos = nPos;
	this->size = 20;
	this->maxSpeed = 5;
}