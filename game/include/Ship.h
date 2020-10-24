#ifndef SHIP_H
#define SHIP_H
#include "Sprite.h"

class Ship: public Sprite{

private:
    void moveForward(int val);
    void moveDown(int val);
    void moveLeft(int val);
    void moveRight(int val);
    void rotateLeft(float val);
    void rotateRight(float val);

    float angle = 0;
    bool isMoving = false;

public:
    Ship(int x, int y, int w, int h, std::string path, int frameNum):
            Sprite(path, frameNum) {
        gameObjectBounds.x = x;
        gameObjectBounds.y = y;
        gameObjectBounds.w = w;
        gameObjectBounds.h = h;
    }


    void controller(SDL_Event& event);
    virtual void render(std::unique_ptr<SDL_Renderer, std::function<void(SDL_Renderer *)> >& renderer);
    virtual ~Ship() = default;


};

#endif
