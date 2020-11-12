#ifndef PARTICLE_H
#define PARTICLE_H
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <fstream>      
#include <math.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h> 


class Particle {
    public:
    int r,g,b,a;
    SDL_Rect particleBounds;
    double velocity = 0;
    double acceleration = 0;
    int angle;


    Particle(int _r, int _g, int _b, int _a, int _x, int _y) {
        r = _r;
        g = _g;
        b = _b;
        a = _a;

        particleBounds.x = _x;
        particleBounds.y = _y;
        particleBounds.w = rand() % 7 +1;
        particleBounds.h = rand() % 7 + 1;

        angle = rand() % 360;
        std::cout << angle << std::endl;
        acceleration = rand() % 4 + 1;
    }

    void controller(bool status, SDL_Event& event);
};

#endif
