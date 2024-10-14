#ifndef SPRITE_H__
#define SPRITE_H__

class Sprite {
public:
    virtual void draw() = 0;
    virtual void update() = 0;

    virtual ~Sprite() {}
};

#endif
