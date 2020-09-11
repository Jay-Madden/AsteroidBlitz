#include "../include/Ship.h"

bool Ship::loadTexture(std::string path){
	surface = std::unique_ptr<SDL_Surface, std::function<void(SDL_Surface *)> > (
        IMG_Load("xwingoutline.png"), 
        SDL_FreeSurface);

    return 0;
}

void Ship::draw(std::unique_ptr<SDL_Renderer, std::function<void(SDL_Renderer *)> >& render){
    /*
    auto texture = SDL_CreateTextureFromSurface(render.get(), surface.get());
    SDL_RenderCopy(render.get(), texture, NULL, NULL);
    */
        SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    SDL_SetRenderDrawColor(render.get(), 255, 25, 255, 255);
    SDL_RenderFillRect(render.get(), &rect);
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
    y -= val;
}
void Ship::moveDown(int val){
    y += val;
}
void Ship::moveLeft(int val){
    x += val;
}
void Ship::moveRight(int val){
    x -= val;
}