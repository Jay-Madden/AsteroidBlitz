#include "../include/Ship.h"

void Ship::controller(bool status, SDL_Event& event){
    const uint8_t* kbState = SDL_GetKeyboardState(NULL); 
    handleInput(kbState);

    if(!status) {
        handleIdle();
    }

    moveForward();
}

void Ship::handleInput(const uint8_t* state) {
    if(state[SDL_SCANCODE_W]) {
        acceleration = 3.0;
    }
    else {
        acceleration = -0.75;
    }
    if(state[SDL_SCANCODE_D]) {
        rotateRight(8.0);
    }
    if(state[SDL_SCANCODE_A]) {
        rotateLeft(8.0);
    }
}

void Ship::handleIdle(){
    // decreaseSpeed(0.75);
}

void Ship::render(std::unique_ptr<SDL_Renderer, std::function<void(SDL_Renderer *)> >& renderer){

    if(acceleration > 0) {
        advanceFrame();
    }
    else {
        setFrame(8);
    }

    auto texture = SDL_CreateTextureFromSurface(renderer.get(), spriteSheet.get());
    SDL_RenderCopyEx(renderer.get(),
        texture, 
        &currentSpriteFrameBounds, 
        &gameObjectBounds, 
        angle, 
        NULL, 
        SDL_FLIP_NONE);
}

void Ship::moveForward(){
    setVelocity();
    gameObjectBounds.x += velocity * sin(deg2rad(angle));
    gameObjectBounds.y -= velocity * cos(deg2rad(angle));
}

void Ship::moveLeft(int val){
    gameObjectBounds.x += val;
}
void Ship::moveRight(int val){
    gameObjectBounds.x -= val;
}
void Ship::rotateLeft(float val){
    setAngle(angle - val);
}
void Ship::rotateRight(float val){
    setAngle(angle + val);
    std::cout << "the angle is " << angle << std::endl;
}