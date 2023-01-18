#include "entity.h"


Entity::Entity(const char *texPath, SDL_Renderer* renderer, int x, int y, int w, int h) : 
 _texPath(texPath), _x(x), _y(y), _w(w), _h(h), _renderer(renderer)
{
    
setTex();

};

void Entity::setTex(){

 SDL_Surface* surf = IMG_Load(_texPath);
   
    if(!surf) {

            std::cout << "Image load error" << "Error:" << SDL_GetError() << std::endl;

    }

    _tex = SDL_CreateTextureFromSurface(_renderer, surf);

}

SDL_Texture* Entity::getTex(){

    return _tex;
}

void Entity::setSrc(int _x, int _y){
    
    _src.x = 0;
    _src.y = 0;
    _src.w = _w;
    _src.h = _h;
   
}

SDL_Rect Entity::getSrc()
 {

    return _src;
}

void Entity::setDst(int _x, int _y){
    
    _dst.x = _x;
    _dst.y = _y;
    _dst.w = _w;
    _dst.h = _h;
}

SDL_Rect Entity::getDst(){
 
    return _dst;

}

void Entity :: drawEntity() {

    setSrc(_x, _y);
    setDst(_x, _y);
    SDL_RenderCopy(_renderer,_tex,&_src,&_dst);

    

}



void Entity :: fallEvent(SDL_Event event, Mousecontroller& mouse, int screenWith, int screenHeight, Uint32 tick, Uint32 elapsed) {
 

    std::cout << _dst.y << " : " << screenHeight << std::endl;

    if(mouse.mx <= _dst.x + _dst.w && mouse.mx >= _dst.x  && mouse.my <= _dst.y + _dst.h && mouse.my >= _dst.y)  {
          if(_dst.y < screenHeight - 100){
            if(mouse.mLeft == true){
        
                _y += 10;
                           
            }
            }               
        }                  
      
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






