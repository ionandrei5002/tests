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
#include "PlayerPaddle.h"
#include "GameBall.h"

namespace pong {

void Game::Start(void) {
	if (_gameState != Uninitialized)
		return;

	Game::_mainWindow.create(sf::VideoMode(1024, 768, 32), "Pang!");
	Game::_gameState = Game::Playing;

	pong::SplashScreen splash(_mainWindow);
	pong::MainMenu menu(_mainWindow);
	pong::PlayerPaddle player(_mainWindow);
	pong::GameBall ball(_mainWindow);

	eventBus.submitEntity(std::make_shared<pong::SplashScreen>(splash));
	eventBus.submitEntity(std::make_shared<pong::MainMenu>(menu));
	eventBus.submitEntity(std::make_shared<pong::PlayerPaddle>(player));
	eventBus.submitEntity(std::make_shared<pong::GameBall>(ball));

	while (!IsExiting()) {
		Game::GameLoop();
	}

	_mainWindow.close();
}

bool Game::IsExiting() {
	if (_gameState == Game::Exiting)
		return true;
	else
		return false;
}

void Game::GameLoop() {
	sf::Event currentEvent;

	sf::Clock clock;

	Game::_gameState = Game::ShowingSplash;

	while (true) {
		while (_mainWindow.pollEvent(currentEvent)) {
			Event<sf::Event> evn(0, &currentEvent);

			eventBus.submitMessage(
					std::make_shared<GenericMessage>(1, (void*) &evn));

			eventBus.trigger();

			if (currentEvent.type == sf::Event::Closed) {
				Game::_gameState = Game::Exiting;
				break;
			}
		}

		float Time = clock.getElapsedTime().asSeconds();
		clock.restart();

		Event<sf::Event> evn(0, &currentEvent);
		eventBus.submitMessage(
				std::make_shared<GenericMessage>((int) (Time * 100000), (void*) &evn));

		eventBus.trigger();

		sf::sleep(sf::microseconds(10000 - (1.f / Time)));

		if (Game::_gameState == Game::Exiting) {
			break;
		}
	}
}

Game::GameState Game::_gameState = Game::Uninitialized;
sf::RenderWindow Game::_mainWindow;

Bus Game::eventBus;

} /* namespace pong */
