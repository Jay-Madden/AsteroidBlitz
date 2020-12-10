#include "../include/PauseMenu.h"


PauseMenu::PauseMenu(SDL_Window * window) {

    SDL_GetWindowSize(window, &width, &height);
    int resumeXY = width - 500;
    int quitXY = height - 400;

    resumeRec.x = resumeXY;
    resumeRec.y = resumeXY;

    quitRec.x = quitXY;
    quitRec.y = quitXY;

}


void PauseMenu::renderLabelText(SDL_Renderer * renderer) {

    //Creates Resume and Quit labels for screen

    TTF_Init();
    resumeColor = {102, 233, 46, 255};
    quitColor = {255, 14, 11, 255};

    TTF_Font *font = TTF_OpenFont("fonts/GengarRegular.ttf", 80);
    SDL_Surface * surf = TTF_RenderText_Blended(font, labelText1.c_str(), resumeColor);
    labelTexture1 = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_FreeSurface(surf);
    SDL_QueryTexture(labelTexture1, NULL, NULL, &resumeRec.w, &resumeRec.h);
    SDL_RenderCopy(renderer, labelTexture1, NULL, &resumeRec);

    SDL_Surface * surf2 = TTF_RenderText_Blended(font, labelText2.c_str(), quitColor);
    labelTexture2 = SDL_CreateTextureFromSurface(renderer, surf2);
    SDL_FreeSurface(surf2);
    SDL_QueryTexture(labelTexture2, NULL, NULL, &quitRec.w, &quitRec.h);
    SDL_RenderCopy(renderer, labelTexture2, NULL, &quitRec);
    TTF_CloseFont(font);

}


bool PauseMenu::drawPauseMenu(SDL_Renderer * renderer) {
    
    SDL_Rect backRec;
    backRec.x = 0;
    backRec.y = 0;
    backRec.w = 900;
    backRec.h = 700;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderFillRect(renderer, &backRec);

    renderLabelText(renderer);

    SDL_RenderPresent(renderer);

    SDL_Event handler;
    while(SDL_PollEvent(&handler) != 0) {
        if (handler.type == SDL_QUIT || handler.key.keysym.sym == SDLK_q) {
            std::cout << "Quiting" << std::endl;
            TTF_Quit();
            SDL_Quit(); 
        }
        else if (handler.key.keysym.sym == SDLK_r) {
            return false;
        }
    }
    return true;
}

