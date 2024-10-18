#ifndef RAYLIBWINDOW_H__
#define RAYLIBWINDOW_H__

#include "Window.h"
#include "raylib.h"

class RaylibWindow : public Window {
public:
    RaylibWindow(const char*, int, int);

    void init(int, int, const char*) override;
    void beginDrawing();
    void endDrawing();
    void update() override;
    void displayFPS() override;
    bool isRunning() override;
    bool shouldClose();
    void close();

    ~RaylibWindow() override;
};

#endif