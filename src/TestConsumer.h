#ifndef TESTCONSUMER_H
#define TESTCONSUMER_H

#include <iostream>

#include "Entity.h"
#include "Message.h"

#include "TestObject.h"

class TestConsumer : public Entity
{
public:
    TestConsumer() {};
    virtual ~TestConsumer();
    void update(std::shared_ptr<Message> message) override;
};

#endif // TESTCONSUMER_H
