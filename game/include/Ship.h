#ifndef SHIP_H
#define SHIP_H
#include "GameObject.h"

class Ship: public GameObject {

private:
    void moveForward();
    void moveDown(int val);
    void moveLeft(int val);
    void moveRight(int val);
    void rotateLeft(float val);
    void rotateRight(float val);
    void handleIdle();
    void handleInput(const uint8_t* state);

public:
    Ship(int x, int y, int w, int h, std::string path, int frameNum):
            GameObject(path, frameNum) {
        gameObjectBounds.x = x;
        gameObjectBounds.y = y;
        gameObjectBounds.w = w;
        gameObjectBounds.h = h;
        setParticleGenerator(255,128,0,0,50,6);
    }

    void controller(bool status, SDL_Event& event);
    void idle();
    virtual ~Ship() = default;

};

#endif
