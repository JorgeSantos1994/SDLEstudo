#ifndef ENTITY
#define ENTITY

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "mousecontroller.h"

enum EntityState {
    
    
    entityStop, 
    entityFall,
    entityReset

    };


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
        void handleEvents(SDL_Event event, Mousecontroller& mouse);
        void moveEvent(SDL_Event event);
        void fallEvent(SDL_Event event, int screenWith, int screenHeight, float timeStep);
        void testEvent(SDL_Event event, Mousecontroller& mouse, int screenWith, int screenHeight);



    private:
        float _srcx, _srcy;
        float _dstx, _dsty;
        int _w, _h;
        const char* _texPath;
        EntityState entitystate;
        SDL_Texture* _tex = nullptr;
        SDL_Renderer* _renderer = nullptr;
        SDL_Rect _src;
        SDL_Rect _dst;
       
       
};

#endif

