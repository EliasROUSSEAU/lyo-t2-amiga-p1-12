#ifndef SDLWINDOW_H__
#define SDLWINDOW_H__

#include "Window.h"
#include "Sprite.h"
#include <SDL2/SDL.h>
#include <string>

class SDLWindow : public Window {
private:
    SDL_Window* win;
    SDL_Surface* winSurface;
    SDL_Texture* texture;
    SDL_Renderer* renderer;

    Uint32 fps_lasttime;
    Uint32 fps_current;
    Uint32 fps_frames;

public:
    SDLWindow(const std::string& _title, int _width, int _height);
    ~SDLWindow();

    void Init() override;
    void Surface() override;
    void Draw() override;
    void FPS() override;
    void Create() override;
    void Close() override;
    void DrawSprite(Sprite& sprite);
    SDL_Renderer* GetRenderer();
};

#endif
