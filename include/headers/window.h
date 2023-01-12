#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

class Window {

public:
    Window(const char* title, int x, int y, int w, int h, Uint32 flags);
    ~Window();
    void renderer();
    SDL_Texture* loadTexture(const char *filePath);
    void render(SDL_Texture* tex);

protected:
    SDL_Window* _window = nullptr;
    SDL_Renderer* _renderer = nullptr;
    SDL_Texture* _texBckGround = nullptr;

};
