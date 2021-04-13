#include <iostream>
#include <SFML/Graphics.hpp>

#include "Menu.h"
#include "Game.h"

int main()
{
	Menu menu;

	while (menu.running())
	{
		menu.update();;

		menu.render();
	}
}