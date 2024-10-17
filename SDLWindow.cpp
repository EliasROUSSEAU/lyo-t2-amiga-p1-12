#include "SDLWindow.h"
#include <iostream>
#include <SDL2/SDL.h>
#include "SDLSprite.h"

#define FPS_INTERVAL 1.0

SDLWindow::SDLWindow(const std::string& _title, int _width, int _height)
    : win(nullptr), winSurface(nullptr), fps_lasttime(0), fps_current(0), fps_frames(0),
    renderer(nullptr), texture(nullptr), ballSprite(nullptr), font(nullptr), fpsTexture(nullptr)
{
}

SDLWindow::~SDLWindow()
{
    Close();
}

void SDLWindow::Init() {

    // Initialiser SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Failed to initialize SDL! Error: " << SDL_GetError() << std::endl;
        return;
    }

    // Initialiser SDL_ttf
    if (TTF_Init() == -1) {
        std::cout << "Failed to initialize SDL_ttf! Error: " << TTF_GetError() << std::endl;
        SDL_Quit();
        return;
    }

    Create();

    // Créer le renderer
    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cout << "Failed to create renderer! Error: " << SDL_GetError() << std::endl;
        Close();
        return;
    }

    fps_lasttime = SDL_GetTicks();

    // Charger la police
    font = TTF_OpenFont("Sandra.ttf", 24);
    if (!font) {
        std::cout << "Failed to load font! Error: " << TTF_GetError() << std::endl;
    }
}

void SDLWindow::Surface()
{
    winSurface = SDL_GetWindowSurface(win);
    if (!winSurface) {
        std::cout << "Failed to get window surface! Error: " << SDL_GetError() << std::endl;
    }
}

void SDLWindow::Draw(Sprite* sprite)
{
    SDL_SetRenderDrawColor(renderer, 255, 90, 120, 255);
    SDL_RenderClear(renderer);

    if (sprite) {
        DrawSprite(*sprite);
    }

    // Présenter le renderer
    SDL_RenderPresent(renderer);

    FPS();
}

void SDLWindow::FPS() {
    fps_frames++;

    if (fps_lasttime < SDL_GetTicks() - FPS_INTERVAL * 1000) {
        fps_lasttime = SDL_GetTicks();
        fps_current = fps_frames;
        fps_frames = 0;

        // Convertir les FPS en chaîne de caractères
        std::string fpsText = "FPS: " + std::to_string(fps_current);

        // Créer une surface de texte
        SDL_Color color = { 255, 255, 255 };
        SDL_Surface* textSurface = TTF_RenderText_Solid(font, fpsText.c_str(), color);
        if (textSurface == nullptr) {
            std::cout << "Unable to render FPS text! Error: " << TTF_GetError() << std::endl;
            return;
        }

        // Créer une texture à partir de la surface
        fpsTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        SDL_FreeSurface(textSurface);

        // Rendre le texte dans la fenêtre
        SDL_Rect renderQuad = { 10, 10, 100, 50 };
        SDL_RenderCopy(renderer, fpsTexture, nullptr, &renderQuad);

        SDL_DestroyTexture(fpsTexture);
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
    if (font) {
        TTF_CloseFont(font);
        font = nullptr;
    }

    if (renderer) {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }

    if (win) {
        SDL_DestroyWindow(win);
        win = nullptr;
    }

    winSurface = nullptr;
    TTF_Quit();
    SDL_Quit();
}

void SDLWindow::DrawSprite(Sprite& sprite)
{
    if (auto* sdlSprite = dynamic_cast<SDLSprite*>(&sprite)) {
        float x = sdlSprite->GetPosX();
        float y = sdlSprite->GetPosY();
        float width = sdlSprite->GetSizeWidth();
        float height = sdlSprite->GetSizeHeight();
        SDL_Rect rect = { static_cast<int>(x), static_cast<int>(y), static_cast<int>(width), static_cast<int>(height) };

        if (sdlSprite->GetTexture() == nullptr) {
            std::cout << "Texture is null!" << std::endl;
            return;
        }

        SDL_RenderCopy(renderer, sdlSprite->GetTexture(), nullptr, &rect);
    }
}

SDL_Renderer* SDLWindow::GetRenderer()
{
    return renderer;
}
