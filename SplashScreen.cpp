/*
 * SplashScreen.cpp
 *
 *  Created on: Feb 8, 2017
 *      Author: andrei
 */

#include "Game.h"
#include "SplashScreen.h"

namespace pong
{
void SplashScreen::Show()
{
	sf::Texture image;
	if (image.loadFromFile("images/Splashscreen.png") != true)
	{
		return;
	}

	sf::Sprite sprite(image);

	window.draw(sprite);
	window.display();
}

void SplashScreen::update(std::shared_ptr<Message> message)
{
	if (Game::_gameState == Game::ShowingSplash)
	{
		Event<sf::Event> evn = *(Event<sf::Event>*) message->getMessage();

		sf::Event event = evn.getEvent();

		this->Show();

		if (event.type == sf::Event::MouseButtonReleased)
		{
			Game::_gameState = Game::ShowingMenu;
		}
	}
}

} /* namespace pong */
