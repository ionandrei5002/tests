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
	GenericMessage(long messageId, std::string& message) :
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

	std::string& getMessage(void) override
	{
		return this->mMessage;
	}
};

class Event: public Serialize<Event>
{
private:
	int msgId = 0;
	sf::Event* currentEvent;
public:
	Event() :
			msgId(0), currentEvent(nullptr)
	{
	}

	Event(int id, sf::Event* event) :
			msgId(id), currentEvent(event)
	{
	}

	virtual ~Event()
	{
	}

	sf::Event getEvent()
	{
		return *currentEvent;
	}

	std::string toBinary(Event& object) override
	{
		std::string buff;
		buff.resize(12);

		memcpy((char*) buff.data(), (char*) &msgId, 4);
		memcpy((char*) &buff.data()[4], (char*) &currentEvent, 8);
		return buff;
	}

	Event fromBinary(std::string& object) override
	{
		char* buff = (char*) object.data();

		int n = *(int*) buff;
		long t = *(long*) &buff[4];
		return Event(n, (sf::Event*) t);
	}

	std::string toString() override
	{
		std::string out;

		out = out + std::to_string(this->msgId) + " : "
				+ std::to_string((long) &this->currentEvent);
		return out;
	}
};

#endif /* USUAL_H_ */
