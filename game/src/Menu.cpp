#include "../include/Menu.h"

void Menu::menuStart(int typeSet, int height, int width) {
    //Enable gpu_enhanced textures
    IMG_Init(IMG_INIT_PNG);
  
	menuWindow = SDL_CreateWindow("Asteroid Blitz: Main Menu", 
			       SDL_WINDOWPOS_CENTERED, 
			       SDL_WINDOWPOS_CENTERED, 
			       width,
			       height, 0);
			       
	menuRenderer = SDL_CreateRenderer(menuWindow,-1,0);
	// Need to import the ttf stuff. text currently doesn't work
	//TTF_Init(); 
	type = typeSet;
	setWidth = width;
	setHeight = height;
}

void Menu::menuListener() {
	SDL_RenderClear(menuRenderer);
	changeSelection();
	screenSetup();
	SDL_RenderPresent(menuRenderer);
}

void Menu::changeSelection() {
	SDL_Event handler;	
	while(SDL_PollEvent(&handler) != 0) {
		if (handler.type == SDL_QUIT) {
			std::cout << "Quiting" << std::endl;
		} else if (handler.type == SDL_KEYDOWN) {
			switch(handler.key.keysym.sym ) {
			
				case SDLK_w:
					selection--;
				break;
				
				case SDLK_s:
					selection++;
				break;
				
				case SDLK_RETURN:
					if (selection == 1) gameStart = false;
					//if (selection == 2) ;
				break;
			}
		}
	}
	
	if (selection > 2) selection = 1;
	if (selection < 1) selection = 2;
}

void Menu::screenSetup() {
	const char* playLoc;
	const char* exitLoc;
	
	switch(selection) {
		case 1:
			playLoc = "sprites/menucomponents/play_buttons_pressed_blue.png";
			exitLoc = "sprites/menucomponents/exit_buttons.png";
		break;
		
		case 2:
			playLoc = "sprites/menucomponents/play_buttons.png";
			exitLoc = "sprites/menucomponents/exit_buttons_pressed.png";
		break;
		
		default:
			playLoc = "sprites/menucomponents/play_buttons.png";
			exitLoc = "sprites/menucomponents/exit_buttons.png";
		break;
	}
	
	switch(type) {
		// Main menu setup
		case 1:
			buttonPlace(playLoc, ((setWidth)-256)/2, (setHeight/2)-256, 256, 256);
			buttonPlace(exitLoc, ((setWidth)-256)/2, ((setHeight/2)-256)+150, 256, 256);
			break;
			
		// Gameover setup
		case 2:
			// NEXT TO DO
			break;
	}
}

void Menu::buttonPlace(const char* buttonFile, int x, int y, int h, int w) {
	SDL_Texture* textureHolder = NULL;
	SDL_Surface* surfaceHolder;
	
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	surfaceHolder = IMG_Load(buttonFile);
	textureHolder = SDL_CreateTextureFromSurface(menuRenderer, surfaceHolder);
	
	SDL_FreeSurface(surfaceHolder);
    SDL_RenderCopy(menuRenderer, textureHolder, NULL, &rect);
}
