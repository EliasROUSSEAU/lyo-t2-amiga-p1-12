#ifndef WINDOW_H__
#define WINDOW_H__
#include <SDL2/>

class Window
{
public:
	int width;
	int height;
	
	virtual ~Window();
	virtual void init(int width, int height) = 0;
	virtual void update() = 0;
	virtual bool isRunning() = 0;
	virtual void displayFPS() = 0;
	virtual void init(int width, int height, const char* title) = 0;

	Window();
};

#endif 
