#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

#include "Entity.h"
#include "Player.h"
#include "PProjectile.h"
#include "FProjectile.h"
#include "Foe.h"
#include "Wall.h"

/*
	Og�lna klasa gry.
*/

class Game
{
private:
	//Zmienne
	const int HEIGHT = 800;
	const int WIDTH = 1000;
	const int SIZE = 40;
	int points;
	int maxPoints;

	std::fstream myFile;
	int best;

	sf::RenderWindow* okno;
	sf::VideoMode videoMode;
	sf::Event ev;

	sf::Font font;
	sf::Text score;
	sf::Text life;

	std::vector<Entity*> entities;

	//sprites' boxes #1
	//std::vector<sf::RectangleShape*> re;

	//Funkcje
	void initVar();
	void initWindow();

public:
	//Gettery
	const bool running();

	//Funkcje
	void moveNShootEnemies();
	float posXMostLeftEnemy();
	float posXMostRightEnemy();
	float lowestEnemy();
	float lowestEnemyAt(int nPos);

	void pollEvents();
	void update();
	void render();

	//Konstruktory i Destruktor
	Game();
	~Game();
};
