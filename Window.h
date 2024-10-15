#ifndef WINDOW_H__
#define WINDOW_H__

class Window {
public:
    virtual void Init() = 0;
    virtual void Surface()= 0;
    virtual void Draw()= 0;
    virtual void FPS()= 0;
    virtual void Create() = 0;
    virtual void Close() = 0;

    virtual ~Window() {}
};

#endif
