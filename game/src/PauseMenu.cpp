#include "../include/PauseMenu.h"


void setLabelText() {

    SDL_Surface * surf = TTF_RenderText_Blended(labelFont, labelText.c_str(), textColor);
    labelTexture = SDL_CreateTextureFromSurface(Engine::renderer, surf)
    SDL_FreeSurface(surf);
    SDL_QueryTexture(labelTexture, nullptr, nullptr, &position.w, &position.h);

}


void PauseMenu::drawPauseMenu() {

    SDL_RenderCopy(Engine::renderer, labelTexture, nullptr, &position);

}