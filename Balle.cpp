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

void Balle::GetPosition(int& out_x, int& out_y) {
    out_x = x;
    out_y = y;
}

void Balle::GetSpeed(int& out_xspeed, int& out_yspeed) {
    out_xspeed = xspeed;
    out_yspeed = yspeed;
}

int Balle::GetRadius() {
    return radius;
}

void Balle::Update() {
    x += xspeed;
    y += yspeed;
}
