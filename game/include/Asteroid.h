#ifndef ASTEROID_H
#define ASTEROID_H
#include "GameObject.h"
#include "Math_ext.h"

class Asteroid: public GameObject{

    public:
    Asteroid(int x, int y, int w, int h, std::string path, int frameNum):
            GameObject(path, frameNum, asteroid) {
        gameObjectBounds.x = x;
        gameObjectBounds.y = y;
        gameObjectBounds.w = w;
        gameObjectBounds.h = h;
    }

    void controller(bool status, SDL_Event& event);
    void collision(Entity e);
    void idle();
    virtual ~Asteroid() = default;


};


#endif
