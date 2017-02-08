/*
 * MainMenu.cpp
 *
 *  Created on: Feb 8, 2017
 *      Author: andrei
 */

#include "Game.h"
#include "MainMenu.h"

namespace pong
{

void MainMenu::Show()
{

	//Load menu image from file
	sf::Texture image;
	image.loadFromFile("images/mainmenu.png");
	sf::Sprite sprite(image);

	window.draw(sprite);
	window.display();
}

void MainMenu::update(std::shared_ptr<Message> message)
{
	if (Game::_gameState == Game::ShowingMenu)
	{
		std::string msg = message->getMessage();
		Event evn = Event().fromBinary(msg);

		sf::Event event = evn.getEvent();

		if (event.type == sf::Event::MouseButtonReleased)
		{
			this->Show();
		}

		if (Game::_gameState == Game::ShowingMenu)
		{
			this->menuResponse(event);
		}
	}
}

void MainMenu::menuResponse(sf::Event event)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		int x, y;

		x = event.mouseButton.x;
		y = event.mouseButton.y;

		this->handleClick(x, y);
	}
}

void MainMenu::handleClick(int x, int y)
{
	std::list<MenuItem>::iterator it;

	for (it = _menuItems.begin(); it != _menuItems.end(); ++it)
	{
		sf::Rect<int> menuItemRect = (*it).rect;

		int left, right, top, bottom;
		left = menuItemRect.left;
		right = left + menuItemRect.width;
		top = menuItemRect.top;
		bottom = top + menuItemRect.height;

		if (left < x && right > x && top < y && bottom > y)
		{
			if ((*it).action == MainMenu::Exit)
			{
				Game::_gameState = Game::Exiting;
			}
		}
	}

	std::cout << Game::_gameState << std::endl;
}

} /* namespace pong */
