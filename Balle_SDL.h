#ifndef BALLE_SDL_H__
#define BALLE_SDL_H__
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

#include <iostream>
#include "Sprite.h"

class Balle_SDL : public Sprite {

	int x;
	int y;
	int radius;
	int x_speed;
	int y_speed;

public:

	Balle_SDL(int _x, int _y, int _radius);
	~Balle_SDL();

	void Poll_events(SDL_Event& _event);
	void Render(SDL_Renderer* _renderer, int _cx, int _cy, int _radius, Uint8 _r, Uint8 _g, Uint8 _b, Uint8 _a);

	inline int get_x() const { return x; }
	inline int get_y() const { return y; }

	void Update();

};

#endif