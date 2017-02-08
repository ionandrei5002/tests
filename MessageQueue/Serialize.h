#ifndef SERIALIZE_H_INCLUDED
#define SERIALIZE_H_INCLUDED

#include <memory>
#include <string>

template<typename T>
class Serialize {
public:
    virtual ~Serialize(){};

    virtual std::string toBinary(T& object) = 0;
    virtual T fromBinary(std::string& object) = 0;
    virtual std::string toString() = 0;
};

#endif // SERIALIZE_H_INCLUDED
