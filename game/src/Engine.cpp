#include "../include/Engine.h"

void Engine::initializeEngine(){
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
    }

    //Enable gpu_enhanced textures
    IMG_Init(IMG_INIT_PNG);

    window = std::unique_ptr<SDL_Window>(SDL_CreateWindow("my_game",
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                screenWidth,
                                screenHeight, 0));

    renderer = std::unique_ptr<SDL_Renderer>(SDL_CreateRenderer(window.get(), -1, 0));
}
