#include "../include/Engine.h"
#include "../include/Ship.h"
//Screen dimension
const int SCREEN_WIDTH = 1500;
const int SCREEN_HEIGHT = 1000;

auto main() -> int { 

    auto engine = std::unique_ptr<Engine>(new Engine(SCREEN_WIDTH, SCREEN_HEIGHT));
    engine->initialize();

    engine->registerEntity<Ship>(0, 0, 75, 75, "sprites/player", 8);

    engine->startGameLoop();

    engine->stop();
    IMG_Quit();
    atexit(SDL_Quit);

    return 1; 
}
