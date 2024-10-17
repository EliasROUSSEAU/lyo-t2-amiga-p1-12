#ifndef WINDOW_H__
#define WINDOW_H__

#include "Sprite.h"

class Window {
public:
    virtual void Init() = 0;
    virtual void Surface()= 0;
    virtual void Draw(Sprite* sprite)= 0;
    virtual void FPS()= 0;
    virtual void Create() = 0;
    virtual void Close() = 0;

    virtual ~Window() {}
};

#endif
