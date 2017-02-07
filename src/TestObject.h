#ifndef TESTOBJECT_H_INCLUDED
#define TESTOBJECT_H_INCLUDED

#include "Serialize.h"
#include <memory.h>
#include <string>
#include <sstream>

class TestObject: public Serialize<TestObject>
{
private:
	int n = 0;
	long t = 1;
public:
	TestObject()
	{
	}
	;
	TestObject(int n, long t) :
			n(n), t(t)
	{
	}
	virtual ~TestObject()
	{
	}

	std::string toBinary(TestObject& object) override
	{
		std::string buff;
		buff.resize(12);

		memcpy((char*) buff.data(), (char*) &n, 4);
		memcpy((char*) &buff.data()[4], (char*) &t, 8);
		return buff;
	}

	TestObject fromBinary(std::string& object) override
	{
		char* buff = (char*)object.data();

		int n = *(int*) buff;
		long t = *(long*) &buff[4];
		return TestObject(n, t);
	}

	std::string toString() override
	{
		std::string out;

		out = out + std::to_string(this->n) + " : " + std::to_string(this->t);
		return out;
	}
};

#endif // TESTOBJECT_H_INCLUDED
