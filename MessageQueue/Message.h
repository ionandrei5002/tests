#ifndef MESSAGE_H_INCLUDED
#define MESSAGE_H_INCLUDED

class Message
{
protected:
	long MessageId = 0;
	void* mMessage;
public:
	Message(long messageId, void* message) :
			MessageId(messageId), mMessage(message)
	{
	}
	virtual ~Message()
	{
	}
	;
	virtual long messageId() = 0;
	virtual void* getMessage(void) = 0;
};

#endif // MESSAGE_H_INCLUDED
