#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "window.h"

enum class GameState {ON, OFF};


class Entity : public Window{

    public:
        Entity(const Window &Window, int x, int y, int w, int h);
        GameState gameState;
        SDL_Texture* loadTexture(const char *filePath);
        void render(SDL_Texture* tex);
        void moveEvent();
        
    private:
        int _x, _y;
        int _w, _h;


};



