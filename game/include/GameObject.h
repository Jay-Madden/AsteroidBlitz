#ifndef GameObject_H
#define GameObject_H

#include <iostream>
#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>


class GameObject {

public:
    virtual void draw(std::unique_ptr<SDL_Renderer, std::function<void(SDL_Renderer *)> >& r) = 0;
    virtual void controller(SDL_Event& event) = 0;
    virtual ~GameObject() = default;

};

#endif
