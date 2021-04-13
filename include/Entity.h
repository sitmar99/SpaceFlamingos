#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <iostream>


class Entity: public sf::Sprite
{
private:
	//Zmienne:
	int hp;
	sf::Vector2f vel;
	sf::Vector2f pos;
	int size;
	int maxSpeed;

	//Tekstury:
	sf::IntRect rect;
	sf::Texture texture;
	sf::Sprite sprite;

	//Funckje:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
	//Funkcje
	int getSize() { return size; };
	void setSize(int nSize) { size = nSize; };
	int getMaxSpeed() { return maxSpeed; };
	sf::Vector2f getPos() { return pos; };
	void setPos(sf::Vector2f nPos) { pos = nPos; };
	int getHP() { return hp; };
	void setHP(int nHP) { hp = nHP; };
	sf::Vector2f getVel() { return vel; };
	void setVel(sf::Vector2f nVel) { vel = nVel; };

	//Tekstury
	void setRect(sf::IntRect nRect) { rect = nRect; };
	sf::Texture* getTexture() { return &this->texture; };
	sf::Sprite* getSprite() { return &this->sprite; };

	virtual void update();

	//Konstruktory i destruktor
	Entity();
	Entity(sf::Vector2f nPos);
	~Entity() {};
};

