#ifndef GameObject_H
#define GameObject_H

#include <iostream>
#include <memory>
#include "SDL.h"
#include "SDL_image.h"


class GameObject {

public:
    std::shared_ptr<SDL_Surface > activeSurface;
    SDL_Rect bounds;
    virtual void controller(SDL_Event& event) = 0;
    virtual ~GameObject() = default;

};

#endif
