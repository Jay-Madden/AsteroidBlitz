#ifndef SHIP_H
#define SHIP_H
#include "Sprite.h"
#include "Math_ext.h"

class Ship: public Sprite{

private:
    void moveForward();
    void moveDown(int val);
    void moveLeft(int val);
    void moveRight(int val);
    void rotateLeft(float val);
    void rotateRight(float val);
    void handleIdle();
    void handleInput(const uint8_t* state);

    double velocity = 0;
    double acceleration = 0;


public:
    Ship(int x, int y, int w, int h, std::string path, int frameNum):
            Sprite(path, frameNum) {
        gameObjectBounds.x = x;
        gameObjectBounds.y = y;
        gameObjectBounds.w = w;
        gameObjectBounds.h = h;
    }


    void controller(bool status, SDL_Event& event);
    void idle();
    virtual void render(std::unique_ptr<SDL_Renderer, std::function<void(SDL_Renderer *)> >& renderer);
    virtual ~Ship() = default;

    void setVelocity(){
        double new_vel = velocity + acceleration;

        if(new_vel > 20) {
            velocity = 20;
            return;
        }
        if(new_vel < 0) {
            velocity = 0;
            return;
        }
        velocity = new_vel;
    }


};

#endif
