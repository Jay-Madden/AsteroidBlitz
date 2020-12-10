#include "../include/Sprite.h"

void Sprite::loadSpriteSheet(SDL_Renderer* renderer) {
    path = path+"/spriteSheet.png";
    auto surface = std::shared_ptr<SDL_Surface > (
        IMG_Load(path.c_str()), 
        SDL_FreeSurface);

    spriteSheet = std::unique_ptr<SDL_Texture, std::function<void(SDL_Texture *)> >
        (SDL_CreateTextureFromSurface(renderer, surface.get()),
        SDL_DestroyTexture);
}

SDL_Rect Sprite::getNextFrame(int frameNum) {
    auto bounds = spriteData.frames[frameNum].frame;
    SDL_Rect r;
    r.h = bounds.h;
    r.w = bounds.w;
    r.x = bounds.x;
    r.y = bounds.y;
    return r;
}

void Sprite::advanceFrame() {
    currentFrame = (currentFrame + 1) % spriteFrames;
    currentSpriteFrameBounds = getNextFrame(currentFrame);
}

void Sprite::setFrame(int frame) {
    currentSpriteFrameBounds = getNextFrame(frame);
}