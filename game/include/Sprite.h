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

    std::vector<std::shared_ptr<SDL_Surface> > cachedSurfaces;
    std::string getNextFrame(int frameNum);

    std::shared_ptr<SDL_Surface> loadSpriteSheet(std::string path);
    void loadSurfaces();

public:

    std::shared_ptr<SDL_Surface> activeSurface;

    Sprite(std::string sPath, int frameNum):
     spriteFrames(frameNum) { 
         loadSurfaces();
         std::ifstream i("file.json");

         spriteData = nlohmann::json::parse(jsonString);

     }

    void advanceFrame();


};

#endif