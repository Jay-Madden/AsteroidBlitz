#include "../include/Sprite.h"

std::shared_ptr<SDL_Surface> Sprite::loadSpriteSheet(std::string path) {
    return std::shared_ptr<SDL_Surface > (
        IMG_Load(path.c_str()), 
        SDL_FreeSurface);
}

std::string Sprite::getNextFrame(int frameNum) {
    return spriteSheetPath + std::to_string(frameNum) + ".png";
}

void Sprite::advanceFrame() {
    currentFrame = (currentFrame + 1) % spriteFrames;

    activeSurface = cachedSurfaces[currentFrame];
}

void Sprite::loadSurfaces() {
    cachedSurfaces.push_back(NULL);
    for(int i = 0; i < spriteFrames; i++){
        cachedSurfaces.push_back(loadSpriteSheet(getNextFrame(i)));
    }
}