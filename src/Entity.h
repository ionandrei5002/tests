#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include <memory>

#include "Message.h"

class Entity{
public:
    virtual ~Entity(){};
    virtual void update(std::shared_ptr<Message> message) = 0;
};

#endif // ENTITY_H_INCLUDED
