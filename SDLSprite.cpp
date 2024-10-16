#include "SDLSprite.h"

SDLSprite::SDLSprite(SDL_Renderer* _renderer, const std::string& _texturePath, float x, float y, float width, float height)
    : renderer(_renderer), texturePath(_texturePath), texture(nullptr) {
    rect.x = static_cast<int>(x);
    rect.y = static_cast<int>(y);
    rect.w = static_cast<int>(width);
    rect.h = static_cast<int>(height);
    LoadTexture();
}

SDLSprite::~SDLSprite() {
    if (texture) {
        SDL_DestroyTexture(texture);
    }
}

void SDLSprite::LoadTexture() {
    SDL_Surface* surface = SDL_LoadBMP(texturePath.c_str());
    if (!surface) {
        std::cerr << "Erreur de chargement de la texture: " << SDL_GetError() << std::endl;
        return;
    }
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (!texture) {
        std::cerr << "Erreur de création de la texture: " << SDL_GetError() << std::endl;
    }
    else {
        std::cout << "Texture chargée avec succès: " << texturePath << std::endl;
    }
}

void SDLSprite::SetPosition(float x, float y) {
    rect.x = static_cast<int>(x);
    rect.y = static_cast<int>(y);
}

float SDLSprite::GetPosX()
{
    return rect.x;
}

float SDLSprite::GetPosY()
{
    return rect.y;
}

void SDLSprite::SetSize(float width, float height) {
    rect.w = static_cast<int>(width);
    rect.h = static_cast<int>(height);
}

float SDLSprite::GetSizeWidth()
{
    return rect.w;
}

float SDLSprite::GetSizeHeight()
{
    return rect.h;
}

SDL_Texture* SDLSprite::GetTexture() {
    return texture;
}
