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
    
    SDL_FreeSurface(surf);
   
    // SDL_SetTextureColorMod( _tex, 0, 0, 0);
}

SDL_Texture* Entity::getTex(){

    return _tex;
}

void Entity::setSrc(int _x, int _y){
    
    _src.x = _x;
    _src.y = _y;
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
  
    setDst(_dst.x, _dst.y);
    SDL_RenderCopy(_renderer,_tex,&_src,&_dst);


}



void Entity :: handleEvents(SDL_Event event, Mousecontroller& mouse){


   if(mouse.mx <= _dst.x + _dst.w && mouse.mx >= _dst.x  && mouse.my <= _dst.y + _dst.h && mouse.my >= _dst.y)  {
        
          
         if(mouse.mLeft == true)
        {
                                
            entitystate = entityFall; 

        }

        if(mouse.mRight == true)
        {
                                
            entitystate = entityReset; 

        }      
                                           
}       
 



}

void Entity :: fallEvent(SDL_Event event, int screenWith, int screenHeight, float timeStep) {
 
                        
    
    
    if(entitystate == entityFall) {
                           
        if(_dst.y < screenHeight - 100){
                            
            _dst.y += 10 * timeStep;
            
                            
        }


    }


    if(entitystate == entityReset){

        setDst(_dstx, _dsty);

        
    }             
   
     
}

void Entity :: testEvent(SDL_Event event, Mousecontroller& mouse, int screenWith, int screenHeight) {

    if(mouse.mLeft == true){

        setDst(_dstx + _dst.w + 25, _dsty + _dst.y + 25);
        
    }

}


void Entity::moveEvent(SDL_Event event){

    

    while(SDL_PollEvent(&event) != 0){
        std::cout << "event1" << std::endl;
        if(event.type == SDL_KEYDOWN){
            std::cout << "keydown" << std::endl;

            switch(event.key.keysym.sym){
                case SDLK_LEFT:
                    _dst.x -=10;
                     std::cout << _dst.x << std::endl;
                    break;
                case SDLK_RIGHT:
                    _dst.x +=10;
                    
                    break;
                case SDLK_UP:
                    _dst.y -=10;
                    
                    break;
                case SDLK_DOWN:
                    _dst.y +=10;
                    
                    break;
            }
        }
    }
}







