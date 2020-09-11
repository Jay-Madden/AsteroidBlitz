// CS 4160 - starter code written by Victor Zordan

#include "../include/Engine.h"
#include "../include/Ship.h"
//Screen dimension
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

auto main() -> int { 

    auto engine = std::unique_ptr<Engine>(new Engine(SCREEN_WIDTH, SCREEN_HEIGHT));
    engine->initialize();
    auto ship = Ship(0, 0, 100, 100);
    engine->registerEntity(ship);

    engine->startGameLoop();
  

/*
    SDL_Rect rect;
    rect.x = 250;
    rect.y = 150;
    rect.w = 59;
    rect.h = 104;
    SDL_Texture* texture;

    SDL_SetRenderDrawColor(my_renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(my_renderer, &rect);
    SDL_RenderCopy(my_renderer, texture, NULL, &rect);
    SDL_RenderPresent(my_renderer);


    bool is_running = true;
    SDL_Event event;
    while (is_running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                is_running = false;
            }
            if(event.type == SDL_KEYDOWN){
                std::cout << event.key.keysym.sym << std::endl;
                switch(event.key.keysym.sym) {
                    case SDLK_w:
                        rect.y -= 5;
                        break;
                    case SDLK_s:
                        rect.y += 5;
                        break;
                    case SDLK_d:
                        rect.x += 5;
                        break;
                    case SDLK_a:
                        rect.x -= 5;
                        break;
                }
            }
        }

        SDL_SetRenderDrawColor(my_renderer,0,0,0,255);
        SDL_RenderClear(my_renderer);

        SDL_RenderCopy(my_renderer, texture, NULL, &rect);

        SDL_RenderPresent(my_renderer);

        SDL_Delay(10);
    }

  SDL_DestroyRenderer(my_renderer);
  SDL_DestroyWindow(my_window);

  IMG_Quit();
  SDL_Quit();
  
  */
  return 0; 
}
