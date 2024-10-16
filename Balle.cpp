#include "Balle.h"

Balle::Balle(int _x, int _y, int _radius)
    : x(_x), y(_y), radius(_radius), xspeed(0), yspeed(0) {}

Balle::~Balle() {}

void Balle::SetPosition(int _x, int _y) {
    x = _x;
    y = _y;
}

void Balle::SetSpeed(int _xspeed, int _yspeed) {
    xspeed = _xspeed;
    yspeed = _yspeed;
}

float Balle::GetPosX() {
    return x;
}

float Balle::GetPosY() {
    return y;
}

float Balle::GetRadius() {
    return radius;
}

void Balle::Update() {
    x += xspeed;
    y += yspeed;
}
