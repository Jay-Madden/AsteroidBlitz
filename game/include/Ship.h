#ifndef SHIP_H
#define SHIP_H
#include "GameObject.h"

class Ship: public GameObject {
private:
    int x;
    int y;
    int w;
    int h;

    std::unique_ptr<SDL_Surface, std::function<void(SDL_Surface *)> > surface;
    std::unique_ptr<SDL_Rect> bounds;

    void moveUp(int val);
    void moveDown(int val);
    void moveLeft(int val);
    void moveRight(int val);

public:
    Ship(int x, int y, int w, int h): x(x), y(y), w(w), h(h){ }

    bool loadTexture(std::string path);
    void draw(std::unique_ptr<SDL_Renderer, std::function<void(SDL_Renderer *)> >& r);
    void controller(SDL_Event& event);
    virtual ~Ship() = default;


};

#endif
