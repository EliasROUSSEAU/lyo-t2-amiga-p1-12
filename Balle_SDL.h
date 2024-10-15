#ifndef BALLE_SDL_H__
#define BALLE_SDL_H__
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <iostream>
#include "Sprite.h"

class Balle_SDL : public Sprite {
private:
    int x;
    int y;
    int radius;
    int xspeed;
    int yspeed;
    SDL_Texture* texture;
    SDL_Renderer* renderer;

public:
    Balle_SDL(int _x, int _y, int _radius, SDL_Renderer* _renderer);
    ~Balle_SDL();

    void LoadTexture() override;
    void SetPosition(int _x, int _y) override;
    void SetSpeed(int _xspeed, int _yspeed) override;
    void GetPosition(int& out_x, int& out_y) override;
    void GetSpeed(int& out_xspeed, int& out_yspeed) override;
    void GetRadius() override;
    void Draw() override;
    void Update() override;
};

#endif