#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <memory>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h> 

#include "GameObject.h"
#include "Bullet.h"
#include "Sprite.h"
#include "PauseMenu.h"

class Engine {
private:
    int screenWidth;
    int screenHeight;
    bool is_running;
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
	SDL_Renderer* getRenderer() {return renderer.get();};
    SDL_Window* getWindow() {return window.get();}

    template <typename T, typename... Args>
    void registerEntity(Args&&... args) {
        activeSprites.push_back(std::make_unique<T>(std::forward<Args>(args)...));
    }

};

#endif
