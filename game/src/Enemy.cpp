#include "../include/Enemy.h"

void Enemy::controller(bool status, SDL_Event& event){
    sprite->advanceFrame();
    if(velocity > 4) {
        acceleration = 0;
    } else {
        acceleration = 3.0;
    }

}

void Enemy::aiController(std::unique_ptr<GameObject>& e) {
    auto e_mid = e->getMiddle();
    auto this_mid = getMiddle();
    if(e->entity == ship) {
        if(distance(this_mid.first, this_mid.second, e_mid.first, e_mid.second) < 200) {
            isShooting = (rand() % 5) == 1;
        }
        isShooting = (rand() % 40) == 1;
        angle = bearing(gameObjectBounds.x, gameObjectBounds.y, e->gameObjectBounds.x, e->gameObjectBounds.y);
    }
}

void Enemy::collision(Entity e) {
    particleGenerator->status = false;
    switch(e) {
        case bullet:
        case asteroid:
            particleGenerator->status = true;
            if(deadTime > 3) {
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
