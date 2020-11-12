#ifndef Engine_H
#define Engine_H

#include <iostream>
#include <memory>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h> 

#include "GameObject.h"
#include "Sprite.h"

class Engine {
private:
    int screenWidth;
    int screenHeight;
    std::string windowName;
    std::unique_ptr<SDL_Window, std::function<void(SDL_Window *)> > window;
    std::unique_ptr<SDL_Renderer, std::function<void(SDL_Renderer *)> > renderer;

    std::vector<std::unique_ptr<GameObject> > activeSprites;

public: 
    Engine( int w, int h, std::string name="Window1"): 
        screenWidth(w), 
        screenHeight(h),
        windowName(name) { }

    void initialize();
    void startGameLoop();

    void drawEntity(std::unique_ptr<GameObject>& e);
    void drawParticles(std::unique_ptr<GameObject>& e);
    void handleEntities(std::unique_ptr<GameObject>& e);
    void handleParticles(std::unique_ptr<GameObject>& e);
    void stop();
    bool checkCollision(SDL_Rect e1, SDL_Rect e2);

    template <typename T, typename... Args>
    void registerEntity(Args&&... args) {
        activeSprites.push_back(std::make_unique<T>(std::forward<Args>(args)...));
    }

};

#endif
