#ifndef ENEMY_H
#define ENEMY_H
#include "GameObject.h"

class Enemy: public GameObject {

private:
    void moveForward();
    void rotateLeft(float val);
    void rotateRight(float val);
    void handleIdle();
    int deadTime = 0;

public:
    Enemy(int x, int y, int w, int h, std::string path, int frameNum):
            GameObject(path, frameNum, enemy) {
        gameObjectBounds.x = x;
        gameObjectBounds.y = y;
        gameObjectBounds.w = w;
        gameObjectBounds.h = h;
        setParticleGenerator(235,52,32,0,100,14);
    }

    void controller(bool status, SDL_Event& event);
    void collision(Entity e);
    void idle();
    virtual ~Enemy() = default;

};

#endif
