#include "RaylibSprite.h"

RaylibSprite::RaylibSprite()
    : x(0), y(0), xSpeed(0), ySpeed(0), radius(20)
{
}

void RaylibSprite::setPosition(float x, float y)
{
    this->x = x;
    this->y = y;
}
void RaylibSprite::setSpeed(float xSpeed, float ySpeed)
{
    this->xSpeed = xSpeed;
    this->ySpeed = ySpeed;
}
void RaylibSprite::drawCircle(float x, float y, float radius)
{
    DrawCircle(static_cast<int>(x), static_cast<int>(y), radius, RED);
}

void RaylibSprite::moveCircle(float xSpeed, float ySpeed)
{
    this->x += xSpeed;
    this->y += ySpeed;

    if (this->x - radius <= 0 || this->x + radius >= GetScreenWidth()) {
        this->xSpeed = -this->xSpeed; 
    }
    if (this->y - radius <= 0 || this->y + radius >= GetScreenHeight()) {
        this->ySpeed = -this->ySpeed;
    }

    drawCircle(this->x, this->y, radius);
}

RaylibSprite::~RaylibSprite()
{

}