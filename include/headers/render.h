#ifndef RENDER
#define RENDER

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>


#include "window.h"

class Render {

public:

    Render(Window& window);
    void initRenderer();
    void renderEntities();
    SDL_Renderer* getRenderer();

private:
    SDL_Window* _window;
    SDL_Renderer* _renderer;





};

#endif