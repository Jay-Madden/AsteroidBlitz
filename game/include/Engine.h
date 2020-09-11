#ifndef Engine_H
#define Engine_H

#include <iostream>
#include <memory>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h> 

#include "GameObject.h"

class Engine {
private:
    int screenWidth;
    int screenHeight;
    std::string windowName;
    std::unique_ptr<SDL_Window, std::function<void(SDL_Window *)> > window;
    std::unique_ptr<SDL_Renderer, std::function<void(SDL_Renderer *)> > renderer;

    std::vector<std::unique_ptr<GameObject> > activeEntities;

public: 
    Engine( int w, int h, std::string name="Window1"): 
        screenWidth(w), 
        screenHeight(h),
        windowName(name) { }

    void initialize();
    void draw();
    void startGameLoop();

    template <typename T>
    void registerEntity(T& entity) {
        activeEntities.push_back(std::make_unique<T>(entity));
    }

};

#endif
