#ifndef SHIP_H
#define SHIP_H
#include "GameObject.h"

class Ship: public GameObject {

private:
    void moveUp(int val);
    void moveDown(int val);
    void moveLeft(int val);
    void moveRight(int val);
    std::shared_ptr<SDL_Surface> shipStillSurface;
    std::shared_ptr<SDL_Surface> shipMoveSurface;

public:
    Ship(int x, int y, int w, int h){
        bounds.x = x;
        bounds.y = y;
        bounds.w = w;
        bounds.h = h;
    }


    bool loadTextures(std::string path);
    void controller(SDL_Event& event);
    virtual ~Ship() = default;


};

#endif
