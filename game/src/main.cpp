#include "../include/Engine.h"
#include "../include/Ship.h"
#include "../include/Asteroid.h"
#include "../include/Menu.h"

//Screen dimension
const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 700;

auto main() -> int { 

    srand (time(NULL));
    
    Menu mainMenuController;
    mainMenuController.menuStart(1, SCREEN_HEIGHT, SCREEN_WIDTH);
    while(mainMenuController.startGame()) {
		mainMenuController.menuListener();
	}
    
    auto engine = std::make_unique<Engine>(SCREEN_WIDTH, SCREEN_HEIGHT);
    engine->initialize();

    engine->registerEntity<Ship>(20, 20, 75, 75, "sprites/player", 8);
    engine->registerEntity<Asteroid>(SCREEN_WIDTH/2, SCREEN_HEIGHT/2+100, 100, 100, "sprites/asteroid1", 1);
    engine->registerEntity<Asteroid>(30,200, 110, 120, "sprites/asteroid1", 1);
    engine->registerEntity<Asteroid>(SCREEN_WIDTH-300, 75, 200, 200, "sprites/asteroid1", 1);

    engine->startGameLoop();

    engine->stop();
    IMG_Quit();
    atexit(SDL_Quit);

    return 1; 
}
