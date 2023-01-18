#ifndef ENTITY
#define ENTITY

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "mousecontroller.h"

enum entityType {fixed, movable};


class Entity{

    public:
        Entity();
        Entity(const char *texPath, SDL_Renderer* renderer, int srcx, int srcy, int dstx, int dsty, int w, int h);
        void setTex();
        SDL_Texture* getTex();
        void setSrc(int _x, int _y);
        SDL_Rect getSrc();
        void setDst(int _x, int _y);
        SDL_Rect getDst();
        void drawEntity();
        void moveEvent(SDL_Event event);
        void fallEvent(SDL_Event event, Mousecontroller& mouse, int screenWith, int screenHeight);
        void testEvent(SDL_Event event, Mousecontroller& mouse, int screenWith, int screenHeight);

    private:
        int _srcx, _srcy;
        int _dstx, _dsty;
        int _w, _h;
        const char* _texPath;
        SDL_Texture* _tex = nullptr;
        SDL_Renderer* _renderer = nullptr;
        SDL_Rect _src;
        SDL_Rect _dst;
       
       
};

#endif

