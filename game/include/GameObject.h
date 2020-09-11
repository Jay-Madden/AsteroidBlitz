#ifndef GameObject_H
#define GameObject_H

#include <iostream>
#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h> 

class GameObject {

public:
    virtual void draw(SDL_Renderer& r) = 0;

};

#endif
