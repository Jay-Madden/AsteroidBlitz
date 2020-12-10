#ifndef BULLET_H
#define BULLET_H

#include "GameObject.h"

class Bullet: public GameObject {

public:
    Bullet(int x, int y, int acc, int ang, std::string path, Entity e):
            GameObject(path, 1, e) {
        gameObjectBounds.x = x;
        gameObjectBounds.y = y;
        gameObjectBounds.w = 10;
        gameObjectBounds.h = 10;
        acceleration = acc;
        angle = ang;
        setParticleGenerator(255,128,0,0,50,6);
    }
    void controller(bool status, SDL_Event& event);
    void idle();
    virtual ~Bullet() = default;
    void collision(Entity e);
};

#endif