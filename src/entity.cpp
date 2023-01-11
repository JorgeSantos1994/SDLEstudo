#include "entity.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

Entity::Entity(const Window &window, int x, int y, int w, int h) : 
Window(window), _x(x), _y(y), _w(w), _h(h)
{

};


SDL_Texture *Entity::loadTexture(const char *filePath)
{
 
    SDL_Texture* tex = NULL;
    tex = IMG_LoadTexture(_renderer, filePath);

    if(tex == NULL) {

            std::cout << "Image load error" << "Error:" << SDL_GetError() << std::endl;

    }


    return tex;
}

void Entity::render(SDL_Texture* tex) {
    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = _w;
    src.h = _h;

    SDL_Rect dst;
    dst.x = _x;
    dst.y = _y;
    dst.w = _w;
    dst.h = _h;
    
    
    SDL_RenderCopy(_renderer,tex,&src,&dst);
    SDL_RenderPresent(_renderer);
    SDL_RenderClear(_renderer);
    SDL_Delay(50);
    
}


void Entity::moveEvent(){

    SDL_Event moveEvent;

    if(SDL_PollEvent(&moveEvent)){
        if(moveEvent.type == SDL_KEYDOWN){
            switch(moveEvent.key.keysym.sym){
                case SDLK_LEFT:
                    _x -=10;
                    break;
                case SDLK_RIGHT:
                    _x +=10;
                    break;
                case SDLK_UP:
                    _y -=10;
                    break;
                case SDLK_DOWN:
                    _y +=10;
                    break;
            }
        }
    }

}






