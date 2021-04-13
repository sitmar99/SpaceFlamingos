#include "Menu.h"

void Menu::initVar()
{
	this->okno = nullptr;
	this->game = nullptr;
	this->about = nullptr;
	this->hiScore = nullptr;

	this->option = 0;
	this->nOfOptions = 4;

	//ladowanie czcionek
	font.loadFromFile("fonts/machine_font.ttf");
	text.setFont(font);
	text.setFillColor(sf::Color(252, 142, 172));
	text.setCharacterSize(24);
}

void Menu::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 600;
	this->okno = new sf::RenderWindow(this->videoMode, "Space Flamingos");
}

const bool Menu::running()
{
	return this->okno->isOpen();
}

void Menu::pollEvents()
{
	while (this->okno->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->okno->close();
			break;
		case sf::Event::KeyPressed:
			switch (this->ev.key.code)
			{
			case::sf::Keyboard::Escape:
				this->okno->close();
				break;
			case sf::Keyboard::W:
				this->option = (option + this->nOfOptions - 1) % this->nOfOptions;
				break;
			case sf::Keyboard::S:
				this->option = (option + 1) % this->nOfOptions;
				break;
			case sf::Keyboard::Enter:
				switch (this->option)
				{
				case 0:
					this->okno->setVisible(0);
					game = new Game();
					while (game->running())
					{
						game->update();
						game->render();
					}
					delete game;
					this->okno->setVisible(1);
					break;
				case 1:
					this->okno->setVisible(0);
					about = new About();
					while (about->running())
					{
						about->update();
						about->render();
					}
					delete about;
					this->okno->setVisible(1);
					break;
				case 2:
					this->okno->setVisible(0);
					hiScore = new HiScore();
					while (hiScore->running())
					{
						hiScore->update();
						hiScore->render();
					}
					delete hiScore;
					this->okno->setVisible(1);
					break;
				case 3:
					this->okno->close();
					break;
				}
			}
		}
	}
}

void Menu::update()
{
	this->pollEvents();
}

void Menu::render()
{
	this->okno->clear(sf::Color::Black);

	text.setString("PLAY");
	text.setPosition(sf::Vector2f(250, 180));
	this->okno->draw(text);
	text.setString("ABOUT");
	text.setPosition(sf::Vector2f(250, 220));
	this->okno->draw(text);
	text.setString("HI SCORE");
	text.setPosition(sf::Vector2f(250, 260));
	this->okno->draw(text);
	text.setString("EXIT");
	text.setPosition(sf::Vector2f(250, 300));
	this->okno->draw(text);
	text.setString(">");
	text.setPosition(sf::Vector2f(230, 180 + this->option*40));
	this->okno->draw(text);

	

	this->okno->display();
}

Menu::Menu()
{
	this->initVar();
	this->initWindow();
}

Menu::~Menu()
{
	delete this->okno;
	delete this->game;
	delete this->about;
	delete this->hiScore;
}

