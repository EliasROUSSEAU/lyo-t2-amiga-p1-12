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
    void GetPosition(int& out_x, int& out_y);
    void GetSpeed(int& out_xspeed, int& out_yspeed);
    int GetRadius();
    void Update();
};

#endif
