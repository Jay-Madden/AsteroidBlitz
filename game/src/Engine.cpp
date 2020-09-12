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
        while (SDL_PollEvent(&event)) {
            for(auto& e : activeEntities){
                e->controller(event);
            }
            if (event.type == SDL_QUIT) {
                is_running = false;
            }
        }
        draw();
    }
}

void Engine::draw() {
    SDL_SetRenderDrawColor(renderer.get(),0,0,0,255);
    SDL_RenderClear(renderer.get());

    for(auto& e : activeEntities){
        auto texture = SDL_CreateTextureFromSurface(renderer.get(), e->surface.get());
        SDL_RenderCopy(renderer.get(), texture, NULL, &e->bounds);

    }

    SDL_RenderPresent(renderer.get());
    SDL_Delay(10);
}

