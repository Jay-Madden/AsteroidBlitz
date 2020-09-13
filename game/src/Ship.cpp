#include "../include/Ship.h"

bool Ship::loadTextures(std::string path){
    shipStillSurface = std::shared_ptr<SDL_Surface > (
        IMG_Load("xwingstill.png"), 
        SDL_FreeSurface);

	shipMoveSurface = std::shared_ptr<SDL_Surface> (
        IMG_Load("xwingmoving.png"), 
        SDL_FreeSurface);
    
    activeSurface = shipStillSurface;

    return 0;
}

void Ship::controller(SDL_Event& event){
    if(event.type == SDL_KEYDOWN){
        std::cout << event.key.keysym.sym << std::endl;
        switch(event.key.keysym.sym) {
            case SDLK_w:
                if(activeSurface == shipStillSurface)
                    activeSurface = shipMoveSurface;
                moveUp(10);
                break;
            case SDLK_s:
                if(activeSurface == shipStillSurface)
                    activeSurface = shipMoveSurface;
                moveDown(10);
                break;
            case SDLK_d:
                if(activeSurface == shipStillSurface)
                    activeSurface = shipMoveSurface;
                moveLeft(10);
                break;
            case SDLK_a:
                if(activeSurface == shipStillSurface)
                    activeSurface = shipMoveSurface;
                moveRight(10);
                break;
        }
    }
    else if(event.type == 12345){
        if(activeSurface == shipMoveSurface)
            activeSurface = shipStillSurface;
    }
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