#ifndef MESSAGE_H_INCLUDED
#define MESSAGE_H_INCLUDED

class Message
{
protected:
    long MessageId = 0;
    std::string& mMessage;
public:
    Message(long messageId, std::string& message) : MessageId(messageId), mMessage(message){}
    virtual ~Message() {};
    virtual long messageId() = 0;
    virtual std::string& getMessage(void) = 0;
};

#endif // MESSAGE_H_INCLUDED
