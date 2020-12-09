#ifndef Menu_H
#define Menu_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_ttf.h> 

#include<iostream> 
#include<string> 

class Menu{
private:
	SDL_Window* menuWindow;
	SDL_Renderer* menuRenderer;

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
	void menuListener();
	void changeSelection();
	void screenSetup();
	void buttonPlace(const char* buttonFile, int x, int y, int h, int w);
	void textPlace(const char* text);
	void backgroundPlace(const char* file);
	
	int getSelection() {return selection;};
	bool startGame() {return gameStart;};
};

#endif
