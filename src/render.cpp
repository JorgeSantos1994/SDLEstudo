#include "render.h"



Render :: Render(Window& window) {


_window = window.getWindow();

}

void Render :: initRenderer(){

 _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

}

void Render :: loadEntity(Entity& entity) {

entity.setTex(_renderer);
_tex = entity.getTex();

}

void Render :: drawEntity(Entity& entity) {

entity.setSrc();
_src = entity.getSrc();
entity.setDst();
_dst = entity.getDst();

SDL_RenderClear(_renderer);
SDL_RenderCopy(_renderer,_tex,&_src,&_dst);
SDL_RenderPresent(_renderer);
        


}