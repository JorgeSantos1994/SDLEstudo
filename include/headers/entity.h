#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "window.h"

enum class GameState {ON, OFF};


class Entity : public Window{

    public:
        Entity(const Window &Window, const char *texPath, int x, int y, int w, int h);
        GameState gameState;
        void render();
        void moveEvent(SDL_Event event);
        

    private:
        int _x, _y;
        int _w, _h;
        SDL_Texture* _tex = nullptr;
        const char * _texPath;
};



