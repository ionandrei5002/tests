/*
 * VisibleGameObject.cpp
 *
 *  Created on: Feb 9, 2017
 *      Author: andrei
 */

#include "VisibleGameObject.h"

namespace pong
{
VisibleGameObject::~VisibleGameObject()
{
}

void VisibleGameObject::Load(std::string filename)
{
	if (_image.loadFromFile(filename) == false)
	{
		_filename = "";
		_isLoaded = false;
	}
	else
	{
		_filename = filename;
		_sprite.setTexture(_image);
		_isLoaded = true;
	}
}

void VisibleGameObject::Draw()
{
	if (_isLoaded)
	{
		window.draw(_sprite);
		window.display();
	}
}

void VisibleGameObject::SetPosition(float x, float y)
{
	if (_isLoaded)
	{
		_sprite.setPosition(x, y);
	}
}
}

