#include "window.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>


Window::Window(const char* title, int x, int y, int w, int h, Uint32 flags){

    SDL_Init(SDL_INIT_EVERYTHING);
    _window = SDL_CreateWindow(title, x , y, w,  h, flags);


}

Window::~Window(){
    SDL_DestroyWindow(_window);
    SDL_Quit();

}
void Window::renderer(){

    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
   

}

SDL_Texture * Window::loadTexture(const char *filePath){

    SDL_Texture* tex = NULL;
    tex = IMG_LoadTexture(_renderer, filePath);

    if(tex == NULL) {

            std::cout << "Image load error" << "Error:" << SDL_GetError() << std::endl;

    }


    return tex;
}

void Window::render(SDL_Texture* tex) {
   
   
    SDL_RenderCopy(_renderer,tex,NULL,NULL);
    SDL_RenderPresent(_renderer);
    
    
    
}





