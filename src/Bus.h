#ifndef BUS_H_INCLUDED
#define BUS_H_INCLUDED

#include <vector>
#include <memory>

#include "Entity.h"
#include "Queue.h"

class Bus {
private:
    Queue mQueue;
    std::vector<std::shared_ptr<Entity>> mEntities;
public:
    Bus();
    ~Bus();
    void submitMessage(std::shared_ptr<Message> message);
    void submitEntity(std::shared_ptr<Entity> entity);
    void trigger();
};

#endif // BUS_H_INCLUDED
