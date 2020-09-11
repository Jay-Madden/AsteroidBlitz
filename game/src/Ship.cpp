#include "../include/Ship.h"

bool Ship::loadTexture(std::string path){

    return false;

}

void Ship::draw(SDL_Renderer& render){
    SDL_Rect rect;
    rect.x = 250;
    rect.y = 150;
    rect.w = 59;
    rect.h = 104;
    SDL_SetRenderDrawColor(&render, 255, 25, 255, 255);
    SDL_RenderFillRect(&render, &rect);
}
