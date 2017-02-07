#include "TestConsumer.h"

TestConsumer::~TestConsumer()
{
}

void TestConsumer::update(std::shared_ptr<Message> message)
{
    std::cout << message->messageId() << " : " << TestObject().fromBinary(message->getMessage()).toString() << std::endl;
}
