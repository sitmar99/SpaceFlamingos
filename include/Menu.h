#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "Game.h"
#include "About.h"
#include "HiScore.h"

class Menu
{
private:
	int option;
	int nOfOptions;
	Game* game;
	About* about;
	HiScore* hiScore;

	sf::RenderWindow* okno;
	sf::VideoMode videoMode;
	sf::Event ev;

	sf::Font font;
	sf::Text text;

	void initVar();
	void initWindow();

public:
	const bool running();

	void pollEvents();
	void update();
	void render();

	Menu();
	~Menu();
};

