#ifndef CONTROLLER
#define CONTROLLER

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

class Controller {


public:
    Controller(SDL_Event event);
    void mousePos();
    void mouseClicks();
    void arrowKeys();
    void getController();

    int mx;
    int my;
    bool mLeft = false;
    bool mRight = false;
    bool arrowUp = false;
    bool arrowDown = false;
    bool arrowLeft = false;
    bool arrowRight = false;

private:

    SDL_Event _event;
   

};


#endif