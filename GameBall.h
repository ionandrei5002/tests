/*
 * GameBall.h
 *
 *  Created on: Feb 9, 2017
 *      Author: andrei
 */

#ifndef GAMEBALL_H_
#define GAMEBALL_H_

#include "usual.h"
#include "VisibleGameObject.h"

namespace pong {

class GameBall: public VisibleGameObject {
private:
	float startX = 15, startY = 15;
	bool forwardX = true, forwardY = true;
public:
	GameBall(sf::RenderWindow& _window);
	virtual ~GameBall();
	void update(std::shared_ptr<Message> message) override;

	void move();
};

} /* namespace pong */

#endif /* GAMEBALL_H_ */
