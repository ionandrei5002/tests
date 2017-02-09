/*
 * GameBall.cpp
 *
 *  Created on: Feb 9, 2017
 *      Author: andrei
 */

#include "GameBall.h"
#include "Game.h"

namespace pong {

GameBall::GameBall(sf::RenderWindow& _window) :
		VisibleGameObject(_window) {
	this->Load("images/ball.png");
	this->SetPosition(startX, startY);
}

GameBall::~GameBall() {
}

void GameBall::update(std::shared_ptr<Message> message) {
	if (Game::_gameState == Game::Playing) {
		int time = message->messageId();

		Event<sf::Event> evn = *(Event<sf::Event>*) message->getMessage();
		sf::Event event = evn.getEvent();

		if (time > 1) {
			this->Draw();
			this->move();
		}
	}
}

void GameBall::move() {
	if (startX <= 0) {
		forwardX = true;
	} else if (startX >= 1000) {
		forwardX = false;
	}

	if (forwardX == true) {
		startX = startX + 2.f;
	} else {
		startX = startX - 2.f;
	}

	if (startY <= 0) {
		forwardY = true;
	} else if (startY >= 700) {
		forwardY = false;
	}

	if (forwardY == true) {
		startY = startY + 2.f;
	} else {
		startY = startY - 2.f;
	}

	this->SetPosition(startX, startY);
}

} /* namespace pong */
