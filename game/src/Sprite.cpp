#include "../include/Sprite.h"

void Sprite::loadSpriteSheet(std::string path) {
    spriteSheet = std::shared_ptr<SDL_Surface > (
        IMG_Load(path.c_str()), 
        SDL_FreeSurface);
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

void Sprite::advanceFrame(int frameNum = -1) {
    currentFrame = (currentFrame + 1) % spriteFrames;

    currentSpriteFrameBounds = getNextFrame(frameNum == -1 ? currentFrame : frameNum);
}