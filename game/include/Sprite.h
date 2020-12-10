#ifndef SPRITE_H
#define SPRITE_H
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <fstream>      
#include <math.h>

#include "json.hpp"
#include "SpriteSheet.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h> 


// for convenience
using json = nlohmann::json;

class Sprite {
private:
    int spriteFrames;
    int currentFrame = 0;


    SpriteSheet spriteData;

    SDL_Rect getNextFrame(int frameNum);

    void loadSurfaces();

    void loadSpriteSheetData(std::string path) {
        std::cout << path+"/data.json" << std::endl;
        std::ifstream i(path + "/data.json");
        json j;
        i >> j;

        spriteData = j.get<SpriteSheet>();
    }

public:
    std::unique_ptr<SDL_Texture, std::function<void(SDL_Texture *)> > spriteSheet;
    SDL_Rect currentSpriteFrameBounds;
    std::string path;
    bool isCreated = false;
    void loadSpriteSheet(SDL_Renderer* renderer);

    Sprite(std::string sPath, int frameNum) : spriteFrames(frameNum) { 
        loadSpriteSheetData(sPath);
        path = sPath;
    }

    void advanceFrame();
    void setFrame(int frame);


};

#endif