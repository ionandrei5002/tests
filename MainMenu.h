/*
 * MainMenu.h
 *
 *  Created on: Feb 8, 2017
 *      Author: andrei
 */

#ifndef MAINMENU_H_
#define MAINMENU_H_

#include "usual.h"

namespace pong
{

class MainMenu: public Entity
{
private:
	sf::RenderWindow& window;
public:
	enum MenuResult
	{
		Nothing, Exit, Play
	};

	struct MenuItem
	{
	public:
		sf::Rect<int> rect;
		MenuResult action;
	};

	MainMenu(sf::RenderWindow& _window) :
			window(_window)
	{
		//Setup clickable regions

		//Play menu item coordinates
		MenuItem playButton;
		playButton.rect.top = 145;
		playButton.rect.height = (380 - 145);
		playButton.rect.left = 0;
		playButton.rect.width = 1023;
		playButton.action = Play;

		//Exit menu item coordinates
		MenuItem exitButton;
		exitButton.rect.left = 0;
		exitButton.rect.width = 1023;
		exitButton.rect.top = 383;
		exitButton.rect.height = (560 - 383);
		exitButton.action = Exit;

		_menuItems.push_back(playButton);
		_menuItems.push_back(exitButton);
	}

	virtual ~MainMenu()
	{
	}

	void Show();
	void update(std::shared_ptr<Message> message) override;

	void menuResponse(sf::Event event);
	void handleClick(int x, int y);
private:
	std::list<MenuItem> _menuItems;
};

} /* namespace pong */

#endif /* MAINMENU_H_ */
