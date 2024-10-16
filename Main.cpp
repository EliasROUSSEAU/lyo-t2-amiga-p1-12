#define SDL_MAIN_HANDLED
#include <iostream>
#include <SDL2/SDL.h>
#include "SDLWindow.h"
#include "SDLSprite.h"

int main(int argc, char* argv[]) {
    SDLWindow window("Test Window", 640, 480);
    window.Init();
    window.Create();

    // Créez le sprite
    SDLSprite sprite(window.GetRenderer(), "C:\\Users\\elrousseau\\Documents\\lyo-t2-amiga-p1-12\\Boule.bmp", 100, 100, 50, 50);

    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }
        window.Surface();
        window.Draw();  // Assurez-vous d'appeler Draw() après avoir configuré le renderer

        SDL_Delay(16);
    }

    window.Close();
    return 0;
}

