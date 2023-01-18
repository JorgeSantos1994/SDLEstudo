#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

class Window {

public:
    Window(const char* title, int x, int y, int w, int h, Uint32 flags);
    ~Window();
    SDL_Window* getWindow();
  
protected:
    SDL_Window* _window = nullptr;
    SDL_Texture* _texBckGround = nullptr;

};
