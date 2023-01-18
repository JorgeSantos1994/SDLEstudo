#include "render.h"



Render :: Render(Window& window) {


    _window = window.getWindow();
    initRenderer();

}

void Render :: initRenderer(){

    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

}

SDL_Renderer* Render :: getRenderer(){

    return _renderer;
}


void Render :: renderEntities() {

    SDL_RenderPresent(_renderer);
    SDL_RenderClear(_renderer);       


}