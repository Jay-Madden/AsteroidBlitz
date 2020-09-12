#ifndef GameObject_H
#define GameObject_H

#include <iostream>
#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>


class GameObject {

public:
    std::unique_ptr<SDL_Surface, std::function<void(SDL_Surface *)> > surface;
    SDL_Rect bounds;
    virtual void controller(SDL_Event& event) = 0;
    virtual ~GameObject() = default;

};

#endif
