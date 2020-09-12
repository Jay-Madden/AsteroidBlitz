#ifndef SHIP_H
#define SHIP_H
#include "GameObject.h"

class Ship: public GameObject {
private:


    void moveUp(int val);
    void moveDown(int val);
    void moveLeft(int val);
    void moveRight(int val);

public:
    Ship(int x, int y, int w, int h){
        bounds.x = x;
        bounds.y = y;
        bounds.w = w;
        bounds.h = h;
    }


    bool loadTexture(std::string path);
    void controller(SDL_Event& event);
    virtual ~Ship() = default;


};

#endif
