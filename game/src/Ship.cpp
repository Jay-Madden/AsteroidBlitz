#include "../include/Ship.h"

bool Ship::loadTextures(std::string path){
    auto cSurface = IMG_Load("xwingstill.png");
    shipStillSurface = std::shared_ptr<SDL_Surface > (
        cSurface, 
        SDL_FreeSurface);
 
	activeSurface = std::shared_ptr<SDL_Surface> (
        cSurface, 
        SDL_FreeSurface);

	shipMoveSurface = std::shared_ptr<SDL_Surface> (
        IMG_Load("xwingmoving.png"), 
        SDL_FreeSurface);
    
    activeSurface = shipMoveSurface;
    

    return 0;
}

void Ship::controller(SDL_Event& event){
    if(event.type == SDL_KEYDOWN){
        std::cout << event.key.keysym.sym << std::endl;
        switch(event.key.keysym.sym) {
            case SDLK_w:
                if(activeSurface == shipStillSurface)
                    activeSurface = shipMoveSurface;
                moveUp(5);
                break;
            case SDLK_s:
                if(activeSurface == shipStillSurface)
                    activeSurface = shipMoveSurface;
                moveDown(5);
                break;
            case SDLK_d:
                if(activeSurface == shipMoveSurface) {
                    if(shipStillSurface == NULL){
                        std::cout << "SHIP WAS NULL" << std::endl;
                    }
                    activeSurface = shipStillSurface;
                    std::cout << activeSurface << std::endl;
                }
                moveLeft(5);
                break;
            case SDLK_a:
                if(activeSurface == shipStillSurface)
                    activeSurface = shipMoveSurface;
                moveRight(5);
                break;
        }
    }
    /*
    else if(event.type == 12345){
        if(activeSurface == shipMoveSurface)
            activeSurface = std::move(shipStillSurface);
    }
    */
}

void Ship::moveUp(int val){
    bounds.y -= val;
}
void Ship::moveDown(int val){
    bounds.y += val;
}
void Ship::moveLeft(int val){
    bounds.x += val;
}
void Ship::moveRight(int val){
    bounds.x -= val;
}