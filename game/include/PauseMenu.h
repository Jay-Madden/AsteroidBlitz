#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include "Engine.h"
#include <SDL2/SDL_ttf.h>

class PauseMenu {

    private:
        std::string labelText1 = "Press R To Resume Game";
        std::string labelText2 = "Press Q To Quit Game";
        SDL_Color resumeColor;
        SDL_Color quitColor;
        SDL_Texture * labelTexture1;
        SDL_Texture * labelTexture2;
        SDL_Rect resumeRec;
        SDL_Rect quitRec;
        int height;
        int width;


    public:
        PauseMenu(SDL_Window * window);
        ~PauseMenu();
        void renderLabelText(SDL_Renderer * renderer);
        bool drawPauseMenu(SDL_Renderer * renderer, SDL_Event event);


};

#endif
