#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "entity.h"
#include "window.h"

class Render {

public:

    Render(Window& window);
    void initRenderer();
    void loadEntity(Entity& entity);
    void drawEntity(Entity& entity);
    

private:
    SDL_Rect _src;
    SDL_Rect _dst;
    SDL_Texture* _tex;
    SDL_Window* _window;
    SDL_Renderer* _renderer;





};