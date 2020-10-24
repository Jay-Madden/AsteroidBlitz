#include "../include/Engine.h"

void Engine::initialize(){
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
    }

    //Enable gpu_enhanced textures
    IMG_Init(IMG_INIT_PNG);

    window = std::unique_ptr<SDL_Window, std::function<void(SDL_Window *)> >(SDL_CreateWindow(windowName.c_str(),
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                screenWidth,
                                screenHeight, 0),
                                SDL_DestroyWindow);
    
    renderer = std::unique_ptr<SDL_Renderer, std::function<void(SDL_Renderer *)> >(
        SDL_CreateRenderer(window.get(), -1, 0),
        SDL_DestroyRenderer);
}

void Engine::startGameLoop(){
    SDL_Event event;
    bool is_running = true;
    while (is_running) {
        draw();
        auto eventStatus = SDL_PollEvent(&event);
        if(eventStatus) {
            for(auto& e : activeSprites){
                e->controller(event);
            }
            if (event.type == SDL_QUIT) {
                is_running = false;
            }
        }
        else {
            for(auto& e : activeSprites){
                event.type = 12345;
                e->controller(event);
            }
        }

        SDL_Delay(30);
    }
}

void Engine::draw() {
    SDL_RenderClear(renderer.get());
    SDL_SetRenderDrawColor(renderer.get(),0,0,0,255);

    for(auto& e : activeSprites){
        e->render(renderer);
    }

    SDL_RenderPresent(renderer.get());
}

