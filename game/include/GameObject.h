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
#include <SDL2/SDL_ttf.h> 

#include "Math_ext.h"
#include "Sprite.h"
#include "ParticleGenerator.h"
enum Entity{ bullet,enemy_bullet, enemy, asteroid, ship };

class GameObject {

public:
    SDL_Rect gameObjectBounds;
    float angle = 0;
    double velocity = 0;
    double acceleration = 0;
    bool isShooting = false;
    int shootingCooldown = 0;
    bool isActive = true;
    Entity entity;
    int id;

    std::unique_ptr<Sprite> sprite;
    std::unique_ptr<ParticleGenerator> particleGenerator;

    GameObject(std::string sPath, int numFrames, Entity e) {
        sprite = std::make_unique<Sprite>(sPath, numFrames);
        entity = e;
        id = rand();
    }

    double distance(int x1, int y1, int x2, int y2) {
        return sqrt(pow(x2 - x1, 2) +  
            pow(y2 - y1, 2) * 1.0); 
    }


    virtual void controller(bool status, SDL_Event& event) = 0;
    virtual ~GameObject() = default;
    virtual void collision(Entity e) = 0;

    void setAngle(float val){
        float mod = fmod(val, 360); 
        angle = mod;
    }

    std::pair<int, int> getMiddle() {
        int x = gameObjectBounds.x + (gameObjectBounds.w/ 2 );
        int y = gameObjectBounds.y + (gameObjectBounds.y/ 2 );
        return std::make_pair(x,y);
    }

    template <typename... Args>
    void setParticleGenerator(Args&&... args){
        particleGenerator = std::make_unique<ParticleGenerator>(args...);
    }

    void setVelocity(){
        double new_vel = velocity + acceleration;

        if(new_vel > 50) {
            velocity = 50;
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
