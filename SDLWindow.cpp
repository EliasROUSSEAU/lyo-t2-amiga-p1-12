#include "SDLWindow.h"
#include <iostream>
#include <SDL2/SDL.h>
#include "SDLSprite.h"

#define FPS_INTERVAL 1.0

SDLWindow::SDLWindow(const std::string& _title, int _width, int _height)
    : win(nullptr), winSurface(nullptr), fps_lasttime(0), fps_current(0), fps_frames(0),
    renderer(nullptr), texture(nullptr)
{
}

SDLWindow::~SDLWindow()
{
    Close();
}

void SDLWindow::Init()
{
    SDL_Init(SDL_INIT_VIDEO);
    Create();
    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cout << "Failed to create renderer! Error: " << SDL_GetError() << std::endl;
    }
    fps_lasttime = SDL_GetTicks();
}

void SDLWindow::Surface()
{
    winSurface = SDL_GetWindowSurface(win);
    if (!winSurface) {
        std::cout << "Failed to get window surface! Error: " << SDL_GetError() << std::endl;
    }
}

void SDLWindow::Draw()
{
    SDL_FillRect(winSurface, NULL, SDL_MapRGB(winSurface->format, 255, 90, 120));
    SDL_UpdateWindowSurface(win);
    FPS();
}

void SDLWindow::FPS()
{
    fps_frames++;

    if (fps_lasttime < SDL_GetTicks() - FPS_INTERVAL * 1000) {
        fps_lasttime = SDL_GetTicks();
        fps_current = fps_frames;
        fps_frames = 0;
        std::cout << "FPS: " << fps_current << std::endl;
    }
}

void SDLWindow::Create()
{
    win = SDL_CreateWindow("my window", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if (!win) {
        std::cout << "Failed to create a window! Error: " << SDL_GetError() << std::endl;
    }
}

void SDLWindow::Close()
{
    if (renderer) {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }

    if (win) {
        SDL_DestroyWindow(win);
        win = nullptr;
    }

    winSurface = nullptr;
}

void SDLWindow::DrawSprite(Sprite& sprite)
{
    if (auto* sdlSprite = dynamic_cast<SDLSprite*>(&sprite)) {
        float x, y, width, height;
        sdlSprite->GetPosition(x, y);
        sdlSprite->GetSize(width, height);
        SDL_Rect rect = { static_cast<int>(x), static_cast<int>(y), static_cast<int>(width), static_cast<int>(height) };

        SDL_RenderCopy(renderer, sdlSprite->GetTexture(), nullptr, &rect);
    }
}

SDL_Renderer* SDLWindow::GetRenderer()
{
    return renderer;
}
