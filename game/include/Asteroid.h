#ifndef ASTEROID_H
#define ASTEROID_H
#include "Sprite.h"
#include "Math_ext.h"

class Asteroid: public Sprite {

    public:
    Asteroid(int x, int y, int w, int h, std::string path, int frameNum):
            Sprite(path, frameNum) {
        gameObjectBounds.x = x;
        gameObjectBounds.y = y;
        gameObjectBounds.w = w;
        gameObjectBounds.h = h;
    }

    void controller(bool status, SDL_Event& event);
    void idle();
    virtual void render(std::unique_ptr<SDL_Renderer, std::function<void(SDL_Renderer *)> >& renderer);
    virtual ~Asteroid() = default;


};


#endif
