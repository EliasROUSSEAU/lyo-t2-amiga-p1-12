#ifndef RAYLIBSPRITE_H__
#define RAYLIBSPRITE_H__

extern "C" {
#include "raylib.h"
}

#include "Sprite.h"
#include "raylib.h"

class RaylibSprite : public Sprite {
public:
    float x, y;
    float xSpeed, ySpeed;
    float radius;

    RaylibSprite();

    void setPosition(float x, float y) override;
    void drawCircle(float x, float y, float radius) override;
    void moveCircle(float, float) override;
    void setSpeed(float xSpeed, float ySpeed);
    ~RaylibSprite() override;
     
};

#endif