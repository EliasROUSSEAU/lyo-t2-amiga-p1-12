#define SDL_MAIN_HANDLED
#include <iostream>
#include <SDL2/SDL.h>
#include <cmath>
#include "SDLWindow.h"

int main(int argc, char* argv[])
{
    SDLWindow window("Test Window", 640, 480);

    window.Init();
    window.Create();

    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }
        window.Surface();
        window.Draw();

        SDL_Delay(16);
    }

    window.Close();

    return 0;
}