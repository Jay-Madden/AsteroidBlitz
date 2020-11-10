#include "../include/Engine.h"
#include "../include/Ship.h"
#include "../include/Asteroid.h"
//Screen dimension
const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 700;

auto main() -> int { 

    auto engine = std::unique_ptr<Engine>(new Engine(SCREEN_WIDTH, SCREEN_HEIGHT));
    engine->initialize();

    engine->registerEntity<Ship>(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 75, 75, "sprites/player", 8);
    engine->registerEntity<Asteroid>(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 200, 200, "sprites/asteroid1", 8);

    engine->startGameLoop();

    engine->stop();
    IMG_Quit();
    atexit(SDL_Quit);

    return 1; 
}
