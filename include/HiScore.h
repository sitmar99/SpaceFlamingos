#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <fstream>
#include <string>

class HiScore
{
private:
	sf::RenderWindow* okno;
	sf::VideoMode videoMode;
	sf::Event ev;

	sf::Font font;
	sf::Text text;

	std::fstream myFile;
	std::string best;

	void initVar();
	void initWindow();

public:
	const bool running();

	void pollEvents();
	void update();
	void render();

	HiScore();
	~HiScore();
};

