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


class GameObject {

public:
    SDL_Rect gameObjectBounds;
    virtual void controller(SDL_Event& event) = 0;
    virtual void render(std::unique_ptr<SDL_Renderer, std::function<void(SDL_Renderer *)> >& renderer) = 0;
    virtual ~GameObject() = default;

};

#endif
