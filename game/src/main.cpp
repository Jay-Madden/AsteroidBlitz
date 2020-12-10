#include "../include/Engine.h"
#include "../include/Ship.h"
#include "../include/Asteroid.h"
#include "../include/Menu.h"

#include "../include/Enemy.h"
//Screen dimension
const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 700;

auto main() -> int { 

    srand (time(NULL));
    auto engine = std::make_unique<Engine>(SCREEN_WIDTH, SCREEN_HEIGHT);
    engine->initialize();
    
    Menu mainMenuController;
    mainMenuController.menuStart(1, engine->getWindow());

    while(mainMenuController.startGame()) {
        mainMenuController.menuListener(engine->getRenderer());
    }

    while (mainMenuController.getReplay()) {
        engine->registerEntity<Ship>(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 75, 75, "sprites/player", 8);
        int h, w;
        SDL_GetWindowSize(engine->window.get(), &h, &w);

        for(int i = 0; i < rand() % 10+3; i++){
            engine->registerEntity<Asteroid>(rand()%h , rand()%w, rand()%70+20, rand()%70+20, "sprites/asteroid1", 1);
        }

        engine->startGameLoop();

        mainMenuController.menuStart(2, engine->getWindow());
        while(mainMenuController.startGame()) {
            mainMenuController.menuListener(engine->getRenderer());
        }
    }
    engine->stop();
    IMG_Quit();
    atexit(SDL_Quit);

    return 1; 
}
