#include "entity.h"


Entity::Entity(const char *texPath, int x, int y, int w, int h) : 
 _texPath(texPath), _x(x), _y(y), _w(w), _h(h)
{
    

};

void Entity::setTex(SDL_Renderer* _renderer){

 SDL_Surface* surf = IMG_Load(_texPath);
   
    if(!surf) {

            std::cout << "Image load error" << "Error:" << SDL_GetError() << std::endl;

    }

    _tex = SDL_CreateTextureFromSurface(_renderer, surf);

}

SDL_Texture* Entity::getTex(){

    return _tex;
}

void Entity::setSrc(){
    
    _src.x = 0;
    _src.y = 0;
    _src.w = _w;
    _src.h = _h;
   
}

SDL_Rect Entity::getSrc()
 {

    return _src;
}

void Entity::setDst(){
    
    _dst.x = _x;
    _dst.y = _y;
    _dst.w = _w;
    _dst.h = _h;
}

SDL_Rect Entity::getDst(){
 
    return _dst;

}



void Entity::draw(SDL_Renderer* _renderer){





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






