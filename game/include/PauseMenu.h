#include "Engine.h"
#include <SDL2/SDL_tff.h>


class PauseMenu: public Engine {

    private:
        bool isPaused = false;
        SDL_Rect position;
        std::string labelText;
        std::string labelFont;
        SDL_Color textColor;
        SDL_Texture * labelTexture;


    public:
        PauseMenu(int xpos, int ypos, std::string text, std::string font, SDL_Color& color) :
            labelText(text), labelFont(font), textColor(color), 
            {
                position.x  = xpos;
                position.y = ypos;

            }
        ~PauseMenu()
        void setLabelText()
        void drawMenu();



}
