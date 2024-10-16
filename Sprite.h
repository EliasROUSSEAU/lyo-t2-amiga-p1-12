#ifndef SPRITE_H__
#define SPRITE_H__

class Sprite {
public:
    virtual void LoadTexture() = 0;
    virtual void SetPosition(float x, float y) = 0;
    virtual void GetPosition(float& x, float& y) = 0;
    virtual void SetSize(float width, float height) = 0;
    virtual void GetSize(float& width, float& height) = 0;

    virtual ~Sprite() {}
};

#endif
