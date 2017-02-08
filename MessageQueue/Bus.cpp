#include "Bus.h"

Bus::Bus(): mQueue(), mEntities() {}

Bus::~Bus() {}

void Bus::submitMessage(std::shared_ptr<Message> message)
{
    this->mQueue.push(message);
}

void Bus::submitEntity(std::shared_ptr<Entity> entity)
{
    this->mEntities.push_back(entity);
}

void Bus::trigger()
{
    while(!this->mQueue.isEmpty())
    {
        std::shared_ptr<Message> message = this->mQueue.pop();
        for(auto it = this->mEntities.begin(); it != this->mEntities.end(); ++it)
        {
            (*it)->update(message);
        }
    }
}
