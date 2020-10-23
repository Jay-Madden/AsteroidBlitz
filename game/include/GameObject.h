#ifndef GameObject_H
#define GameObject_H

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h> 


class GameObject {

public:
    SDL_Rect bounds;
    virtual void controller(SDL_Event& event) = 0;
    virtual ~GameObject() = default;

};

#endif
