#include <iostream>
#include <memory>
#include <vector>
#include <chrono>

#include <thread>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/freeglut.h>

#include <GLFW/glfw3.h>

#include "Message.h"
#include "Bus.h"
#include "TestConsumer.h"

#include "TestObject.h"

Bus bus;

class TestMessage: public Message
{
public:
	TestMessage(long messageId, std::string& message) :
			Message(messageId, message)
	{
	}
	~TestMessage()
	{
	}
	;

	long messageId() override
	{
		return this->MessageId;
	}

	std::string& getMessage(void) override
	{
		return this->mMessage;
	}
};

void move(int x, int y)
{
//	std::cout << "a" << std::endl;

	TestObject tttt(x, y);

	std::string buff = tttt.toBinary(tttt);

	std::shared_ptr<Message> msg = std::make_shared<TestMessage>(
			TestMessage(x, buff));
	bus.submitMessage(msg);
	bus.trigger();
}
;

void draw(void)
{
	// Black background
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	//Draw i
	glFlush();
}

int main(int argc, char **argv)
{
	std::chrono::time_point<std::chrono::high_resolution_clock> start, end;

	start = std::chrono::high_resolution_clock::now();
	std::shared_ptr<Entity> entity = std::make_shared<TestConsumer>(
			TestConsumer());
	bus.submitEntity(entity);

	glutInit(&argc, argv);
	/*Setting up  The Display
	 /    -RGB color model + Alpha Channel = GLUT_RGBA
	 */
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	//Configure Window Postion
	glutInitWindowPosition(50, 25);
	//Configure Window Size
	glutInitWindowSize(480, 480);
	//Create Window
	glutCreateWindow("Hello OpenGL");
	//Call to the drawing function
	glutDisplayFunc(draw);

	glutMotionFunc(move);

	glutMainLoop();

	/*
	 std::shared_ptr<Entity> entity = std::make_shared<TestConsumer>(
	 TestConsumer());
	 bus.submitEntity(entity);

	 for (int i = 0; i < 10000; i++)
	 {
	 TestObject tttt(i + 2, i + 4);

	 std::string buff = tttt.toBinary(tttt);

	 std::shared_ptr<Message> msg = std::make_shared<TestMessage>(
	 TestMessage(i, buff));

	 bus.submitMessage(msg);
	 bus.trigger();
	 }

	 end = std::chrono::high_resolution_clock::now();
	 std::chrono::duration<double> elapsed_time = end - start;

	 std::cout << "duration = " << elapsed_time.count() << "s" << std::endl;
	 */
	return 0;
}
