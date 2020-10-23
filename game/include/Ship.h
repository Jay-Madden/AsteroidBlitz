#ifndef SHIP_H
#define SHIP_H
#include "Sprite.h"

class Ship: public Sprite{

private:
    void moveUp(int val);
    void moveDown(int val);
    void moveLeft(int val);
    void moveRight(int val);
    std::shared_ptr<SDL_Surface> shipStillSurface;
    std::shared_ptr<SDL_Surface> shipMoveSurface;

public:
    Ship(int x, int y, int w, int h, std::string path, int frameNum):
            Sprite(path, frameNum) {
        bounds.x = x;
        bounds.y = y;
        bounds.w = w;
        bounds.h = h;
    }


    void controller(SDL_Event& event);
    virtual ~Ship() = default;


};

#endif
