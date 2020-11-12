#ifndef GameObject_H
#define GameObject_H

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <fstream>      
#include <math.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h> 

#include "Math_ext.h"
#include "Sprite.h"
#include "ParticleGenerator.h"

class GameObject {

public:
    SDL_Rect gameObjectBounds;
    float angle = 0;
    double velocity = 0;
    double acceleration = 0;
    int id;

    std::unique_ptr<Sprite> sprite;
    std::unique_ptr<ParticleGenerator> particleGenerator;

    GameObject(std::string sPath, int numFrames) {
        sprite = std::make_unique<Sprite>(sPath, numFrames);
        id = rand();
    }


    virtual void controller(bool status, SDL_Event& event) = 0;
    virtual ~GameObject() = default;
    void didCollide();

    void setAngle(float val){
        float mod = fmod(val, 360); 
        angle = mod;
    }

    template <typename... Args>
    void setParticleGenerator(Args&&... args){
        particleGenerator = std::make_unique<ParticleGenerator>(args...);
    }

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
