#ifndef PARTICLEGENERATOR_H
#define PARTICLEGENERATOR_H

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <fstream>      
#include <math.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h> 

#include "Particle.h"

class ParticleGenerator {
    private:
    int numParticles;
    int r,g,b,a;
    
    public:

    int duration;
    int currentDuration = 0;
    bool isActive = false;

    std::vector<Particle> particles;

    ParticleGenerator(int _r, int _g, int _b, int _a, int _num, int _duration) {
        r = _r;
        g = _g;
        b = _b;
        a = _a;
        numParticles = _num;
        duration = _duration;
    }

   void moveParticles();

   void generateParticles(int x, int y);
};

#endif
