#ifndef Menu_H
#define Menu_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_ttf.h> 

#include<iostream> 
#include<string> 

class Menu{
private:

    int type;
    int selection;
    bool gameStart;

    int setWidth;
    int setHeight;
public:
    Menu(){
        gameStart = true;
        selection = 1;
    };
    
    // give type 1 for main menu. give type 2 for gameover screen
    void menuStart(int type, int height, int width);
    void menuListener(SDL_Renderer* renderer);
    void changeSelection();
    void screenSetup(SDL_Renderer* renderer);
    void buttonPlace(const char* buttonFile, int x, int y, int h, int w, SDL_Renderer* renderer);
    void textPlace(const char* text, SDL_Renderer* renderer);
    void backgroundPlace(const char* file, SDL_Renderer* renderer);
    
    int getSelection() {return selection;};
    bool startGame() {return gameStart;};
};

#endif
