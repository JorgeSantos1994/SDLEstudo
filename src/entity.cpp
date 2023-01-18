#include "entity.h"

Entity::Entity(){}

Entity::Entity(const char *texPath, SDL_Renderer* renderer, int srcx, int srcy, int dstx, int dsty, int w, int h) : 
 _texPath(texPath), _srcx(srcx), _srcy(srcy), _dstx(dstx), _dsty(dsty), _w(w), _h(h), _renderer(renderer)
{
    
    setTex();
    setSrc(_srcx, _srcy);
    setDst(_dstx, _dsty);

};

void Entity::setTex(){

 SDL_Surface* surf = IMG_Load(_texPath);
   
    if(!surf) {

            std::cout << "Image load error" << "Error:" << SDL_GetError() << std::endl;

    }

    _tex = SDL_CreateTextureFromSurface(_renderer, surf);
   
    // SDL_SetTextureColorMod( _tex, 0, 0, 0);
}

SDL_Texture* Entity::getTex(){

    return _tex;
}

void Entity::setSrc(int _srcx, int _srcy){
    
    _src.x = _srcx;
    _src.y = _srcy;
    _src.w = _w;
    _src.h = _h;
   
}

SDL_Rect Entity::getSrc()
 {

    return _src;
}

void Entity::setDst(int _dstx, int _dsty){
    
    _dst.x = _dstx;
    _dst.y = _dsty;
    _dst.w = _w;
    _dst.h = _h;
}

SDL_Rect Entity::getDst(){
 
    return _dst;

}

void Entity :: drawEntity() {

   
    SDL_RenderCopy(_renderer,_tex,&_src,&_dst);

    

}



void Entity :: fallEvent(SDL_Event event, Mousecontroller& mouse, int screenWith, int screenHeight) {
 

    // std::cout << _dst.y << std::endl;

    if(mouse.mx <= _dst.x + _dst.w && mouse.mx >= _dst.x  && mouse.my <= _dst.y + _dst.h && mouse.my >= _dst.y)  {
          
        //  std::cout << "selected" << std::endl;
          
          if(_dst.y < screenHeight - 100){
            if(mouse.mLeft == true){
        
                _dsty += 10;
                setDst(_dstx, _dsty);         
            }
            }               
        }                  
      
}

void Entity :: testEvent(SDL_Event event, Mousecontroller& mouse, int screenWith, int screenHeight) {

    if(mouse.mLeft == true){

        setDst(_dstx + _dst.w + 25, _dsty + _dst.y + 25);
        
    }

}


void Entity::moveEvent(SDL_Event event){

   

    if(SDL_PollEvent(&event)){
        if(event.type == SDL_KEYDOWN){
            switch(event.key.keysym.sym){
                case SDLK_LEFT:
                    _dstx -=10;
                    break;
                case SDLK_RIGHT:
                    _dstx +=10;
                    break;
                case SDLK_UP:
                    _dsty -=10;
                    break;
                case SDLK_DOWN:
                    _dsty +=10;
                    break;
            }
        }
    }
}







