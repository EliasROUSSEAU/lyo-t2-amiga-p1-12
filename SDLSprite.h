#ifndef SDLSprite_H__
#define SDLSprite_H__

#include "Sprite.h"
#include <SDL2/SDL.h>
#include <string>
#include <iostream>

class SDLSprite : public Sprite {
private:
    SDL_Texture* texture;
    SDL_Rect rect;
    std::string texturePath;
    SDL_Renderer* renderer; 

public:
    SDLSprite(SDL_Renderer* _renderer, const std::string& _texturePath, float x, float y, float width, float height);
    ~SDLSprite();
    void LoadTexture() override;
    void SetPosition(float x, float y) override;
    void GetPosition(float& x, float& y) override;
    void SetSize(float width, float height) override;
    void GetSize(float& width, float& height) override;
    SDL_Texture* GetTexture();
};

#endif
