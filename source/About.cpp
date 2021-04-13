#include "About.h"

void About::initVar()
{
	this->okno = nullptr;

	//ladowanie czcionek
	font.loadFromFile("fonts/machine_font.ttf");
	text.setFont(font);
	text.setFillColor(sf::Color(252, 142, 172));
	text.setCharacterSize(20);
}

void About::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 600;
	this->okno = new sf::RenderWindow(this->videoMode, "Space Flamingos");
}

const bool About::running()
{
	return this->okno->isOpen();
}

void About::pollEvents()
{
	while (this->okno->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->okno->close();
			break;
		case sf::Event::KeyPressed:
			this->okno->close();
			break;
		}
	}
}

void About::update()
{
	this->pollEvents();
}

void About::render()
{
	this->okno->clear(sf::Color::Black);

	text.setString("'A' & 'D' - move enemy left/right");
	text.setPosition(sf::Vector2f(150, 220));
	this->okno->draw(text);
	text.setString("space - shoot");
	text.setPosition(sf::Vector2f(150, 250));
	this->okno->draw(text);
	text.setString("Your objective is to kill all enemies,\nbefore they reach your ship");
	text.setPosition(sf::Vector2f(150, 280));
	this->okno->draw(text);


	this->okno->display();
}

About::About()
{
	this->initVar();
	this->initWindow();
}

About::~About()
{
	delete this->okno;
}
