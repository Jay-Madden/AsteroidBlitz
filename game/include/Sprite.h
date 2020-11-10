#ifndef SPRITE_H
#define SPRITE_H
#include "GameObject.h"
#include "json.hpp"
#include "SpriteSheet.h"

// for convenience
using json = nlohmann::json;

class Sprite: public GameObject {
private:
    int spriteFrames;
    int currentFrame = 0;


    SpriteSheet spriteData;

    SDL_Rect getNextFrame(int frameNum);

    void loadSpriteSheet(std::string path);
    void loadSurfaces();

    void loadSpriteSheetData(std::string path) {
        std::cout << path+"/data.json" << std::endl;
        std::ifstream i(path + "/data.json");
        json j;
        i >> j;

        spriteData = j.get<SpriteSheet>();
    }

public:
    std::shared_ptr<SDL_Surface> spriteSheet;
    SDL_Rect currentSpriteFrameBounds;

    Sprite(std::string sPath, int frameNum):
     spriteFrames(frameNum) { 
         loadSpriteSheetData(sPath);
         loadSpriteSheet(sPath+"/spriteSheet.png");
     }

    void advanceFrame(int frameNum);


};

#endif