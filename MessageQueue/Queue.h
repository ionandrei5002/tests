#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <iostream>

#include "Message.h"
#include <queue>
#include <memory>

class Queue
{
private:
    std::queue<std::shared_ptr<Message>> bus;
public:
    Queue();
    ~Queue();
    Queue(const Queue& other) = delete;
    Queue& operator=(const Queue& other) = delete;
    Queue(Queue&& other) = delete;
    Queue&& operator=(Queue&& other) = delete;

    bool isEmpty();
    std::shared_ptr<Message> pop();
    void push(std::shared_ptr<Message> message);
};

#endif // QUEUE_H_INCLUDED
