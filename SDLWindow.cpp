#include "SDLWindow.h"
#include <iostream>
#include <SDL2/SDL.h>

#define FPS_INTERVAL 1.0

SDLWindow::SDLWindow(const std::string& _title, int _width, int _height)
    : win(nullptr), winSurface(nullptr), fps_lasttime(0), fps_current(0), fps_frames(0)
{
}

SDLWindow::~SDLWindow()
{
    Close();
}

void SDLWindow::Init()
{
    SDL_Init(SDL_INIT_EVERYTHING);
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
    if (win) {
        SDL_DestroyWindow(win);
        win = NULL;
    }

    winSurface = NULL;
}
