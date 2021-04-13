#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Sprite.hpp>
class About
{
private:
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

	About();
	~About();
};

