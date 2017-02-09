/*
 * VisibleGameObject.h
 *
 *  Created on: Feb 9, 2017
 *      Author: andrei
 */

#ifndef VISIBLEGAMEOBJECT_H_
#define VISIBLEGAMEOBJECT_H_

#include "usual.h"

namespace pong
{

class VisibleGameObject: public Entity
{
protected:
	sf::RenderWindow& window;
	sf::Sprite _sprite;
	sf::Texture _image;
	std::string _filename;
	bool _isLoaded;
public:
	VisibleGameObject(sf::RenderWindow& _window) :
			window(_window), _isLoaded(false)
	{
	}
	virtual ~VisibleGameObject();
	virtual void Load(std::string filename);
	virtual void Draw();
	virtual void SetPosition(float x, float y);
};

} /* namespace pong */

#endif /* VISIBLEGAMEOBJECT_H_ */
