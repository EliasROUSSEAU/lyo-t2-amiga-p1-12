#ifndef WINDOW_H__
#define WINDOW_H__

class Window {
public:
    virtual void create() = 0;
    virtual void close() = 0;

    virtual ~Window() {}
};

#endif
