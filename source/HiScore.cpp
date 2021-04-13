#include "HiScore.h"

void HiScore::initVar()
{
	this->okno = nullptr;

	//ladowanie czcionek
	font.loadFromFile("fonts/machine_font.ttf");
	text.setFont(font);
	text.setFillColor(sf::Color(252, 142, 172));
	text.setCharacterSize(20);
}

void HiScore::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 600;
	this->okno = new sf::RenderWindow(this->videoMode, "Space Flamingos");
}

const bool HiScore::running()
{
	return this->okno->isOpen();
}

void HiScore::pollEvents()
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

void HiScore::update()
{
	this->pollEvents();
}

void HiScore::render()
{
	this->okno->clear(sf::Color::Black);

	text.setString("HiScore: " + best);
	text.setPosition(sf::Vector2f(250, 250));
	this->okno->draw(text);

	this->okno->display();
}

HiScore::HiScore()
{
	this->initVar();
	this->initWindow();

	myFile.open("HiScore.txt");
	getline(myFile, best);
	myFile.close();
}

HiScore::~HiScore()
{
	delete this->okno;
}
