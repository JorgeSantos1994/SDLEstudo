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
  
    
    SDL_RenderCopy(_renderer,_tex,&_src,&_dst);


}










