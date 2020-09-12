#include "../include/Ship.h"

bool Ship::loadTexture(std::string path){
    auto cSurface = IMG_Load(path.c_str());
    if(cSurface == NULL) {
        std::cout << "Texture not found" << std::endl;
    }
	surface = std::unique_ptr<SDL_Surface, std::function<void(SDL_Surface *)> > (
        cSurface, 
        SDL_FreeSurface);

    return 0;
}

void Ship::controller(SDL_Event& event){
    if(event.type == SDL_KEYDOWN){
        std::cout << event.key.keysym.sym << std::endl;
        switch(event.key.keysym.sym) {
            case SDLK_w:
                moveUp(5);
                break;
            case SDLK_s:
                moveDown(5);
                break;
            case SDLK_d:
                moveLeft(5);
                break;
            case SDLK_a:
                moveRight(5);
                break;
        }
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