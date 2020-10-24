#include "../include/Ship.h"

void Ship::controller(SDL_Event& event){
    isMoving = false;
    if(event.type == SDL_KEYDOWN){
        std::cout << event.key.keysym.sym << std::endl;
        switch(event.key.keysym.sym) {
            case SDLK_w:
                moveForward(10);
                isMoving = true;
                break;
            case SDLK_s:
                moveDown(10);
                break;
            case SDLK_d:
                rotateRight(8.0);
                break;
            case SDLK_a:
                rotateLeft(8.0);
                break;
        }
    }
}

void Ship::render(std::unique_ptr<SDL_Renderer, std::function<void(SDL_Renderer *)> >& renderer){
    advanceFrame(isMoving ? -1 : 8);
    auto texture = SDL_CreateTextureFromSurface(renderer.get(), spriteSheet.get());
    SDL_RenderCopyEx(renderer.get(),
        texture, 
        &currentSpriteFrameBounds, 
        &gameObjectBounds, 
        angle, 
        NULL, 
        SDL_FLIP_NONE);
}

void Ship::moveForward(int val){
    gameObjectBounds.y += val * sin(angle);
    gameObjectBounds.x += val * cos(angle);
}
void Ship::moveDown(int val){
    gameObjectBounds.y += val;
}
void Ship::moveLeft(int val){
    gameObjectBounds.x += val;
}
void Ship::moveRight(int val){
    gameObjectBounds.x -= val;
}
void Ship::rotateLeft(float val){
    angle -= val;
}
void Ship::rotateRight(float val){
    angle += val;
}