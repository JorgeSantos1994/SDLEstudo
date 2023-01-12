#include "entity.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

Entity::Entity(const Window &window, const char *texPath, int x, int y, int w, int h) : 
Window(window), _texPath(texPath), _x(x), _y(y), _w(w), _h(h)
{
 
    SDL_Surface* surf = IMG_Load(_texPath);
   
    if(!surf) {

            std::cout << "Image load error" << "Error:" << SDL_GetError() << std::endl;

    }

    _tex = SDL_CreateTextureFromSurface(_renderer, surf);

};




void Entity::render() {
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
    
       
        SDL_RenderCopy(_renderer,_tex,&src,&dst);
        SDL_RenderPresent(_renderer);
        SDL_RenderClear(_renderer);

    
   
    
    
}


void Entity::moveEvent(SDL_Event event){

   

    if(SDL_PollEvent(&event)){
        if(event.type == SDL_KEYDOWN){
            switch(event.key.keysym.sym){
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






