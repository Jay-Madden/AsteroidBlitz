#include "../include/Bullet.h"

void Bullet::controller(bool status, SDL_Event& event){
    sprite->setFrame(0);
    acceleration = 3.0;
}

void Bullet::collision(Entity e) {


    particleGenerator->status = false;
    switch(e) {
        case asteroid:
            particleGenerator->status = true;
            isActive = false;
            break;
        case ship:
            break;
        default:
        break;
    }
}