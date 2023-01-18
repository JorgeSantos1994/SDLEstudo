#include "window.h"


Window::Window(const char* title, int x, int y, int w, int h, Uint32 flags){

    SDL_Init(SDL_INIT_EVERYTHING);
    _window = SDL_CreateWindow(title, x , y, w,  h, flags);


}

Window::~Window(){
    SDL_DestroyWindow(_window);
    SDL_Quit();

}

SDL_Window* Window::getWindow(){

return _window;


}



