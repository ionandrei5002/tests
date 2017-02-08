/*
 * SplashScreen.h
 *
 *  Created on: Feb 8, 2017
 *      Author: andrei
 */

#ifndef SPLASHSCREEN_H_
#define SPLASHSCREEN_H_

#include "usual.h"

namespace pong
{

class SplashScreen: public Entity
{
private:
	sf::RenderWindow& window;
public:
	SplashScreen(sf::RenderWindow& _window) :
			window(_window)
	{
	}
	virtual ~SplashScreen()
	{
	}
	void Show();
	void update(std::shared_ptr<Message> message) override;
};

} /* namespace pong */

#endif /* SPLASHSCREEN_H_ */
