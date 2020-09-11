#ifndef SHIP_H
#define SHIP_H
#include "GameObject.h"

class Ship: public GameObject {
private:
    int x;
    int y;
    int w;
    int h;

public:
    Ship(int x, int y, int w, int h): x(x), y(y), w(w), h(h){ }

    bool loadTexture(std::string path);
    void draw(SDL_Renderer& r);
    void moveUp(int val);
    void moveDown(int val);
    void moveLeft(int val);
    void moveRight(int val);

};

#endif
