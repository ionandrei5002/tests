/*
 * Game.h
 *
 *  Created on: Feb 8, 2017
 *      Author: andrei
 */

#ifndef GAME_H_
#define GAME_H_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "usual.h"

namespace pong
{

class Game
{
public:
	static void Start();
	static Bus eventBus;

private:
	static bool IsExiting();
	static void GameLoop();

public:
	enum GameState
	{
		Uninitialized, ShowingSplash, Paused, ShowingMenu, Playing, Exiting
	};
	static GameState _gameState;
	static sf::RenderWindow _mainWindow;
};

} /* namespace pong */

#endif /* GAME_H_ */
