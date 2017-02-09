/*
 * PlayerPaddle.h
 *
 *  Created on: Feb 9, 2017
 *      Author: andrei
 */

#ifndef PLAYERPADDLE_H_
#define PLAYERPADDLE_H_

#include "usual.h"
#include "VisibleGameObject.h"

namespace pong
{
class PlayerPaddle: public VisibleGameObject
{
public:
	PlayerPaddle(sf::RenderWindow& _window);
	~PlayerPaddle();
	void update(std::shared_ptr<Message> message) override;
};
}

#endif /* PLAYERPADDLE_H_ */
