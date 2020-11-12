#include "../include/Asteroid.h"

void Asteroid::controller(bool status, SDL_Event& event){
    sprite->setFrame(0);
}

/*
void Asteroid::render(std::unique_ptr<SDL_Renderer, std::function<void(SDL_Renderer *)> >& renderer){
    setFrame(0);
    auto texture = SDL_CreateTextureFromSurface(renderer.get(), spriteSheet.get());
    SDL_RenderCopyEx(renderer.get(),
        texture, 
        &currentSpriteFrameBounds, 
        &gameObjectBounds, 
        angle, 
        NULL, 
        SDL_FLIP_NONE);
}
*/