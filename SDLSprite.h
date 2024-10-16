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
    SDLSprite(SDL_Renderer* _renderer, const std::string& _texturePath, float _x, float _y, float _width, float _height);
    ~SDLSprite();
    void LoadTexture() override;
    void SetPosition(float _x, float _y) override;
    float GetPosX() override;
    float GetPosY() override;
    void SetSize(float _width, float _height) override;
    float GetSizeWidth() override;
    float GetSizeHeight() override;
    SDL_Texture* GetTexture();
};

#endif
