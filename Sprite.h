#ifndef SPRITE_H__
#define SPRITE_H__

#include "Vect2.h"

class Sprite
{
public:
    Sprite() : position(0, 0), velocity(100, 100) {} 
        virtual ~Sprite();
        virtual void setPosition(float x, float y) = 0;
        virtual void draw(float x, float y, float radius) = 0;
       // move()
        virtual void update(float deltaTime, float, float) = 0;

protected:
    Vector2 position;
    Vector2 velocity;
    };

#endif 