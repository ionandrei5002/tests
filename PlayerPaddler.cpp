/*
 * PlayerPaddler.cpp
 *
 *  Created on: Feb 9, 2017
 *      Author: andrei
 */

#include "PlayerPaddle.h"
#include "Game.h"

namespace pong {
PlayerPaddle::PlayerPaddle(sf::RenderWindow& _window) :
		VisibleGameObject(_window) {
	this->Load("images/paddle.png");
	this->SetPosition((1024 / 2) - 45, 700);
}

PlayerPaddle::~PlayerPaddle() {
}

void PlayerPaddle::update(std::shared_ptr<Message> message) {
	if (Game::_gameState == Game::Playing) {
		this->window.clear(sf::Color(0, 0, 0));

		Event<sf::Event> evn = *(Event<sf::Event>*) message->getMessage();
		sf::Event event = evn.getEvent();

		int x = 0, y = 700;
		if (event.type == sf::Event::MouseMoved) {
			if (event.mouseMove.x < 0) {
				x = 0;
			} else if (event.mouseMove.x > (1024 - 90)) {
				x = (1024 - 90);
			} else {
				x = event.mouseMove.x;
			}

			this->SetPosition((float) x, (float) y);
		}

		this->Draw();

		if (event.type == sf::Event::KeyReleased) {
			Game::_gameState = Game::ShowingMenu;

			Game::eventBus.submitMessage(
					std::make_shared<GenericMessage>(1, (void*) &evn));

			return;
		}
	}
}
}
