#include "Game.h"

//Funkcje private

void Game::initVar()
{
	//zerowanie wskaznika na okno
	this->okno = nullptr;

	//zerowanie zmiennych
	this->points = 0;
	this->maxPoints = 0;

	//zapewnienie losowosci
	std::srand(time(NULL));

	//ladowanie czcionek
	font.loadFromFile("fonts/machine_font.ttf");
	score.setFont(font);
	score.setFillColor(sf::Color(252, 142, 172));
	score.setCharacterSize(24);

	life.setFont(font);
	life.setFillColor(sf::Color(252, 142, 172));
	life.setCharacterSize(24);
	life.setPosition(sf::Vector2f(0, 25));


	//dodanie gracza
	this->entities.push_back(new Player(sf::Vector2f(WIDTH/2 - SIZE/2, HEIGHT-3*SIZE)));

	//dodanie przeciwikow
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			//najnizszy rzad przeciwnikow
			if (i == 1)
				this->entities.push_back(new Foe(sf::Vector2f(3*SIZE + 2*j*SIZE, HEIGHT/2 - 2*i*SIZE), i*10, 1));
			//pozostale rzedy
			else
				this->entities.push_back(new Foe(sf::Vector2f(3*SIZE + 2*j*SIZE, HEIGHT/2 - 2*i*SIZE), i*10, 0));
			//nadanie predkosci poczatkowej
			this->entities.back()->setVel(sf::Vector2f(0.05, 0));
			this->maxPoints += i * 10;
		}
	}

	//dodanie scian
	for (int i = 0; i < WIDTH - 15; i+=30)
	{
		if (rand() % 100 > 60)
			this->entities.push_back(new Wall(sf::Vector2f(i, HEIGHT - 5 * SIZE)));
	}
}

void Game::initWindow()
{
	this->videoMode.height = this->HEIGHT;
	this->videoMode.width = this->WIDTH;
	this->okno = new sf::RenderWindow(this->videoMode, "Space Flamingos");
}

//Gettery
const bool Game::running()
{
	return (this->okno->isOpen() && this->entities[0]->getHP() != 0 && this->points != this->maxPoints && this->lowestEnemy() < this->entities[0]->getPos().y);
}

//Funkcje
void Game::pollEvents()
{
	while (this->okno->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->okno->close();
			break;
		case sf::Event::KeyPressed:
			Player* gracz = static_cast<Player*>(this->entities[0]);
			switch (this->ev.key.code)
			{
			case sf::Keyboard::Escape:
				this->okno->close();
				break;
			case sf::Keyboard::A:
				//move left
				if(gracz->getPos().x > 0)
					gracz->setVel(sf::Vector2f(-(gracz->getMaxSpeed()),0));
				break;
			case sf::Keyboard::D:
				//move right
				if (gracz->getPos().x + SIZE < WIDTH)
					gracz->setVel(sf::Vector2f(gracz->getMaxSpeed(), 0));
				break;
			case sf::Keyboard::Space:
				//shoot
				if (gracz->canShoot())
				{
					this->entities.push_back(new PProjectile(gracz->getPos() + sf::Vector2f(5, -31)));
					gracz->setLST(time(NULL));
				}
				break;
			}
			break;
		}
	}
}

void Game::moveNShootEnemies()
{
	for (auto it = entities.begin()+1; it != entities.end(); it++)
	{
		if ((*it)->getSize() != 20)
			break;

		float left = posXMostLeftEnemy();
		float right = posXMostRightEnemy();

		if (right < WIDTH && right > WIDTH - SIZE - 1)
			(*it)->setVel(sf::Vector2f(-0.15, SIZE / 2));
		if (left + SIZE > 0 && left + SIZE < SIZE + 1)
			(*it)->setVel(sf::Vector2f(0.15, SIZE / 2));

		//enemy shoot
		Foe* enemy = static_cast<Foe*>(*it);
		if (enemy->isBottom() && enemy->canShoot() && std::rand() % 1000 > 998)
		{
			this->entities.push_back(new FProjectile((*it)->getPos() + sf::Vector2f(5, 60)));
			enemy->setLST(time(NULL));
		}
	}
}

float Game::posXMostLeftEnemy()
{
	auto it = entities.begin() + 1;
	float mPos = (*it)->getPos().x;
	it++;

	for ( ; it != entities.end(); it++)
	{
		if ((*it)->getSize() != 20)
			break;

		float pos = (*it)->getPos().x;
		if (pos < mPos)
			mPos = pos;
	}

	return mPos;
}

float Game::posXMostRightEnemy()
{
	auto it = entities.begin() + 1;
	float mPos = (*it)->getPos().x;
	it++;

	for (; it != entities.end(); it++)
	{
		if ((*it)->getSize() != 20)
			break;

		float pos = (*it)->getPos().x;
		if (pos > mPos)
			mPos = pos;
	}

	return mPos;
}

float Game::lowestEnemy()
{
	auto it = entities.begin() + 1;
	float mPos = (*it)->getPos().y;
	it++;

	for (; it != entities.end(); it++)
	{
		if ((*it)->getSize() != 20)
			break;

		float pos = (*it)->getPos().y;
		if (pos > mPos)
			mPos = pos;
	}

	return mPos;

}

float Game::lowestEnemyAt(int nPos)
{
	auto it = entities.begin() + 1;
	float mPos = 0;

	for (; it != entities.end(); it++)
	{		
		if ((*it)->getSize() != 20)
			break;

		float pos = (*it)->getPos().y;
		if ((*it)->getPos().x == nPos && pos > mPos)
			mPos = pos;
	}
	std::cout << mPos << std::endl;
	return mPos;
}

void Game::update()
{
	this->pollEvents();
	this->moveNShootEnemies();

	for (auto ent=this->entities.begin(); ent != this->entities.end(); ent++)
	{
		//sprites' boxes #2
		//sf::FloatRect rect = ent->getSprite()->getGlobalBounds();
		//re.push_back(new sf::RectangleShape(sf::Vector2f(rect.width, rect.height)));
		//re.back()->setPosition(sf::Vector2f(rect.left, rect.top));

		//collision detection
		if ((*ent)->getSize() == 10)
		{
			for (auto target : this->entities)
			{
				if ((*ent) != target && (*ent)->getSprite()->getGlobalBounds().intersects(target->getSprite()->getGlobalBounds()))
				{
					(*ent)->setHP((*ent)->getHP() - 1);
					target->setHP(target->getHP() - 1);
				}
			}
		}

		//usuwanie obiektow martwych lub poza ekranem lub upadate zywych
		if ((*ent)->getHP() == 0 || (*ent)->getPos().y < 0 || (*ent)->getPos().y > HEIGHT)
		{
			if ((*ent)->getSize() == 20)	//jesli zestrzelono przeciwnika to dodaj punkty
				this->points += static_cast<Foe*>(*ent)->getPoints();
			delete *ent;
			this->entities.erase(ent--);
		}
		else
			(*ent)->update();
	}
}

void Game::render()
{
	this->okno->clear(sf::Color::Black);

	//rysowanie obiektow
	for (auto ent : this->entities)
		this->okno->draw(*ent);

	//wypisanie wyniku i zyc
	score.setString("score: " + std::to_string(this->points));
	this->okno->draw(score);
	life.setString("life: " + std::to_string(this->entities[0]->getHP()));
	this->okno->draw(life);


	//sprites' boxes #3
	//for (auto ent : this->re)
	//{
	//	this->okno->draw(*ent);
	//	this->re.pop_back();
	//}

	this->okno->display();
}

//Konstruktory i destruktory
Game::Game()
{
	this->initVar();
	this->initWindow();
}

Game::~Game()
{
	delete this->okno;

	for (auto ent : this->entities)
		delete ent;

	this->entities.clear();

	myFile.open("HiScore.txt");
	myFile >> best;
	myFile.close();
	remove("HiScore.txt");

	if (int(best) < this->points)
		best = this->points;

	myFile.open("HiScore.txt", std::ios::out);
	myFile << best;
	myFile.close();
}
