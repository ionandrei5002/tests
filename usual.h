/*
 * usual.h
 *
 *  Created on: Feb 8, 2017
 *      Author: andrei
 */

#ifndef USUAL_H_
#define USUAL_H_

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <map>
#include <iostream>
#include <cassert>
#include <memory>
#include <memory.h>
#include <list>

#include "MessageQueue/Bus.h"
#include "MessageQueue/Entity.h"
#include "MessageQueue/Message.h"
#include "MessageQueue/Serialize.h"

class GenericMessage: public Message
{
public:
	GenericMessage(long messageId, void* message) :
			Message(messageId, message)
	{
	}
	~GenericMessage()
	{
	}

	long messageId() override
	{
		return this->MessageId;
	}

	void* getMessage(void) override
	{
		return this->mMessage;
	}
};

template<typename T>
class Event
{
private:
	int msgId = 0;
	T* currentEvent;
public:
	Event() :
			msgId(0), currentEvent(nullptr)
	{
	}

	Event(int id, T* event) :
			msgId(id), currentEvent(event)
	{
	}

	virtual ~Event()
	{
	}

	T getEvent()
	{
		return *currentEvent;
	}
};

#endif /* USUAL_H_ */
