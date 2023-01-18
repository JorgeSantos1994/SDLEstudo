#ifndef MOUSECONTROLLER
#define MOUSECONTROLLER

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

class Mousecontroller {


public:
    Mousecontroller(SDL_Event event);
    void mousePos();
    void mouseClicks();
    int mx;
    int my;
    bool mLeft = false;
    bool mRight = false;


private:

    SDL_Event _event;
   

};


#endif