#include "../include/Menu.h"

void Menu::menuStart(int typeSet, SDL_Window* window) {
    //Enable gpu_enhanced textures
    type = typeSet;
    SDL_GetWindowSize(window, &setWidth, &setHeight);
    
    gameStart = true;
}

void Menu::menuListener(SDL_Renderer* renderer) {
    SDL_RenderClear(renderer);
    changeSelection();
    screenSetup(renderer);
    SDL_RenderPresent(renderer);
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
                    if (selection == 1) {
						gameStart = false;
						replayGame = true;
					}
                    if (selection == 2) {
                        TTF_Quit();
                        SDL_Quit(); 
                        exit(0); 
                    }
                break;
            }
        }
    }
    
    if (selection > 2) selection = 1;
    if (selection < 1) selection = 2;
}

void Menu::screenSetup(SDL_Renderer* renderer) {
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
            backgroundPlace("background/backgroundMainMenu.png", renderer);
            textPlace("Asteroid Blitz", renderer);
            break;
            
        // Gameover setup
        case 2:
            // NEXT TO DO
            backgroundPlace("background/backgroundMainMenu.png", renderer);
            textPlace("GAME OVER", renderer);
            break;
    }
    buttonPlace(playLoc, ((setWidth)-256)/2, (setHeight/2)-256, 256, 256, renderer);
    buttonPlace(exitLoc, ((setWidth)-256)/2, ((setHeight/2)-256)+150, 256, 256, renderer);
}

void Menu::buttonPlace(const char* buttonFile, int x, int y, int h, int w, SDL_Renderer* renderer) {
    SDL_Texture* textureHolder = NULL;
    SDL_Surface* surfaceHolder;
    
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;

    surfaceHolder = IMG_Load(buttonFile);
    textureHolder = SDL_CreateTextureFromSurface(renderer, surfaceHolder);
    
    SDL_FreeSurface(surfaceHolder);
    SDL_RenderCopy(renderer, textureHolder, NULL, &rect);
}

void Menu::backgroundPlace(const char* file, SDL_Renderer* renderer) {
    SDL_Texture* textureHolder = NULL;
    SDL_Surface* surfaceHolder;
    
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = setWidth;
    rect.h = setHeight;

    surfaceHolder = IMG_Load(file);
    textureHolder = SDL_CreateTextureFromSurface(renderer, surfaceHolder);
    
    SDL_FreeSurface(surfaceHolder);
    SDL_RenderCopy(renderer, textureHolder, NULL, &rect);
}

void Menu::textPlace(const char* text, SDL_Renderer* renderer) {
    TTF_Init(); 
    TTF_Font *font = TTF_OpenFont("fonts/GengarRegular.ttf", 80);
    SDL_Color textColor = {255, 14, 11, 255};
    SDL_Surface *textSurf = TTF_RenderText_Solid(font, text, textColor);
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurf);
    
    SDL_Rect textRect;
    textRect.x = (setWidth/2)-250;
    textRect.y = 25;
    
    SDL_QueryTexture(textTexture, NULL, NULL, &textRect.w, &textRect.h);
    
    SDL_FreeSurface(textSurf);
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
    TTF_CloseFont(font); 
    TTF_Quit(); 
}
