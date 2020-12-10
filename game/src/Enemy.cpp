#include "../include/Enemy.h"

void Enemy::controller(bool status, SDL_Event& event){
    sprite->setFrame(0);
    if(acceleration > 8) {
        acceleration = 0;
    } else {
        acceleration = 3.0;
    }
    setAngle(angle + 8);
}

void Enemy::collision(Entity e) {
    particleGenerator->status = false;
    switch(e) {
        case bullet:
            particleGenerator->status = true;
            if(deadTime > 10) {
                isActive = false;
            }
            velocity = 0;
            deadTime++;
            break;
        case ship:
            break;
        default:
        break;
    }
}