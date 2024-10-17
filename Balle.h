#ifndef BALLE_H__
#define BALLE_H__

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <iostream>

class Balle {
private:
    int x;
    int y;
    int radius;
    int xspeed;
    int yspeed;

public:
    Balle(int _x, int _y, int _radius);
    ~Balle();

    void SetPosition(int _x, int _y);
    void SetSpeed(int _xspeed, int _yspeed);
    int GetPosX();
    int GetPosY();
    int GetRadius();
    void Update();
};

#endif
