/*
 * Game.cpp
 *
 *  Created on: Feb 8, 2017
 *      Author: andrei
 */

#include "usual.h"
#include "Game.h"
#include "SplashScreen.h"
#include "MainMenu.h"

namespace pong
{

void Game::Start(void)
{
	if (_gameState != Uninitialized)
		return;

	Game::_mainWindow.create(sf::VideoMode(1024, 768, 32), "Pang!");
	Game::_gameState = Game::Playing;

	pong::SplashScreen splash(_mainWindow);
	pong::MainMenu menu(_mainWindow);

	eventBus.submitEntity(std::make_shared < pong::SplashScreen > (splash));
	eventBus.submitEntity(std::make_shared < pong::MainMenu > (menu));

	while (!IsExiting())
	{
		Game::GameLoop();
	}

	_mainWindow.close();
}

bool Game::IsExiting()
{
	if (_gameState == Game::Exiting)
		return true;
	else
		return false;
}

void Game::GameLoop()
{
	sf::Event currentEvent;

	Game::_gameState = Game::ShowingSplash;

	while (true)
	{
		while (_mainWindow.pollEvent(currentEvent))
		{
			Event evn(0, &currentEvent);
			std::string msg = evn.toBinary(evn);

			eventBus.submitMessage(
					std::make_shared < GenericMessage > (1, msg));

			if (currentEvent.type == sf::Event::Closed)
			{
				Game::_gameState = Game::Exiting;
				break;
			}
		}

		eventBus.trigger();

		if (Game::_gameState == Game::Exiting)
		{
			break;
		}
	}
}

Game::GameState Game::_gameState = Game::Uninitialized;
sf::RenderWindow Game::_mainWindow;

Bus Game::eventBus;

} /* namespace pong */
