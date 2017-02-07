#include "Queue.h"

Queue::Queue(): bus()
{
}

Queue::~Queue()
{
}

bool Queue::isEmpty() {
    return this->bus.empty();
}

std::shared_ptr<Message> Queue::pop()
{
    std::shared_ptr<Message> message = nullptr;

    if (this->bus.empty() == false)
    {
        message = this->bus.front();
        this->bus.pop();
    }

    return message;
}

void Queue::push(std::shared_ptr<Message> message)
{
    this->bus.push(message);
}
