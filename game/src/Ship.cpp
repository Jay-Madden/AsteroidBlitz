#include "../include/Ship.h"

void Ship::controller(bool status, SDL_Event& event){
    const uint8_t* kbState = SDL_GetKeyboardState(NULL); 
    handleInput(kbState);

    if(!status) {
        handleIdle();
    }
}

void Ship::handleInput(const uint8_t* state) {
    if(state[SDL_SCANCODE_W]) {
        acceleration = 3.0;
        sprite->advanceFrame();
    }
    else {
        acceleration = -0.75;
        sprite->setFrame(8);
    }
    if(state[SDL_SCANCODE_D]) {
        rotateRight(8.0);
    }
    if(state[SDL_SCANCODE_A]) {
        rotateLeft(8.0);
    }
}

void Ship::handleIdle(){

}

void Ship::rotateLeft(float val){
    setAngle(angle - val);
}
void Ship::rotateRight(float val){
    setAngle(angle + val);
}