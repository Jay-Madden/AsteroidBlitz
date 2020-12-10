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
    double bearing(double a1, double a2, double b1, double b2) {
        static const double TWOPI = 6.2831853071795865;
        static const double RAD2DEG = 57.2957795130823209;

        double theta = atan2(b1 - a1, a2 - b2);
        if (theta < 0.0)
            theta += TWOPI;
        return RAD2DEG * theta;
    }
public:
    Enemy(int x, int y, int w, int h, std::string path, int frameNum):
            GameObject(path, frameNum, enemy) {
        gameObjectBounds.x = x;
        gameObjectBounds.y = y;
        gameObjectBounds.w = w;
        gameObjectBounds.h = h;
        setParticleGenerator(235,52,32,0,100,14);
        angle = rand() % 360;
    }

    void controller(bool status, SDL_Event& event);
    void aiController(std::unique_ptr<GameObject>& e);
    void collision(Entity e);
    void idle();
    virtual ~Enemy() = default;

};

#endif
