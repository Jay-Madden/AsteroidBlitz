#include "../include/Bullet.h"

void Bullet::controller(bool status, SDL_Event& event){
    sprite->setFrame(0);
    if(velocity > 8) {
        acceleration = 0;
    } else {
        acceleration = 3;
    }
}

void Bullet::collision(Entity e) {

    particleGenerator->status = false;
    switch(e) {
        case asteroid:
            particleGenerator->status = true;
            isActive = false;
            break;
        default:
        break;
    }
}