#ifndef SDLWINDOW_H__
#define SDLWINDOW_H__

#include "Window.h"
#include <SDL2/SDL.h>
#include <string>


class SDLWindow : public Window {
private:

    SDL_Window* win;
    SDL_Surface* winSurface;

    Uint32 fps_lasttime = SDL_GetTicks();
    Uint32 fps_current;
    Uint32 fps_frames = 0;


public:

    SDLWindow(const std::string& _title, int _width, int _height);
    ~SDLWindow();

    void Init() override;
    void Surface() override;
    void Draw() override;
    void FPS() override;
    void Create() override;
    void Close() override;


};

#endif
