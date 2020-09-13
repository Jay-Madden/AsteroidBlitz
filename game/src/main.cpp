// CS 4160 - starter code written by Victor Zordan

#include "../include/Engine.h"
#include "../include/Ship.h"
//Screen dimension
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

auto main(int argc, char ** argv) -> int { 

    auto engine = std::unique_ptr<Engine>(new Engine(SCREEN_WIDTH, SCREEN_HEIGHT));
    engine->initialize();
    auto ship = Ship(0, 0, 100, 200);
    ship.loadTextures("xwingoutline.png");
    engine->registerEntity(ship);

    engine->startGameLoop();

/*
  SDL_DestroyRenderer(engine->rend);
  SDL_DestroyWindow(my_window);

  IMG_Quit();
  SDL_Quit();
  */
  
  return 0; 
}
