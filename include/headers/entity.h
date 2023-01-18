#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "window.h"

enum entityType {fixed, movable};


class Entity{

    public:
        Entity(const char *texPath, int x, int y, int w, int h);
        void setTex(SDL_Renderer* _renderer);
        SDL_Texture* getTex();
        void setSrc();
        SDL_Rect getSrc();
        void setDst();
        SDL_Rect getDst();
        void moveEvent(SDL_Event event);
        

    private:
        int _x, _y;
        int _w, _h;
        const char * _texPath;
        SDL_Texture* _tex = nullptr;
        SDL_Rect _src;
        SDL_Rect _dst;
       
       
};



