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
        if(velocity > 15){
            acceleration = 0;
        }
        else {
            acceleration = 3.0;
        }
        sprite->advanceFrame();
    }
    else {
        acceleration = -0.5;
        sprite->setFrame(8);
    }
    if(state[SDL_SCANCODE_SPACE]) {
        if(shootingCooldown <= 0){
            isShooting = true;
            shootingCooldown = 2;
        }
        else {
            shootingCooldown--;
        }
    }
    if(state[SDL_SCANCODE_D]) {
        rotateRight(8.0);
    }
    if(state[SDL_SCANCODE_A]) {
        rotateLeft(8.0);
    }
}
void Ship::collision(Entity e){
    particleGenerator->status = false;
    switch(e) {
        case enemy:
        case enemy_bullet:
        case asteroid:
            particleGenerator->status = true;
            if(deadTime > 7) {
                isActive = false;
            }
            velocity = 0;
            deadTime++;
            break;
        default:
        break;
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