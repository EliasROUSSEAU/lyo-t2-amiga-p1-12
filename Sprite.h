#ifndef SPRITE_H__
#define SPRITE_H__

class Sprite {
public:
    virtual void LoadTexture() = 0;
    virtual void SetPosition(int x, int y) = 0;
    virtual void SetSpeed(int xspeed, int yspeed) = 0;
    virtual void GetPosition(int& x, int& y) = 0;
    virtual void GetSpeed(int& xspeed, int& yspeed) = 0;
    virtual void GetRadius() = 0;
    virtual void Draw() = 0;
    virtual void Update() = 0;

    virtual ~Sprite() {}
};

#endif
