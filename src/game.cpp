#include "game.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

Game::Game(const char* title, int x, int y, int w, int h, Uint32 flags) {

    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow(title, x, y, w, h, flags);
    renderer = SDL_CreateRenderer(window,-1, SDL_RENDERER_ACCELERATED);

};

void Game::run(){
    display();
    clear();


}

SDL_Texture* Game::loadTexture(const char* filePath) {
   
    SDL_Texture* tex = NULL;
    tex = IMG_LoadTexture(renderer, filePath);

    if(tex == NULL) {

            std::cout << "Image load error" << "Error:" << SDL_GetError() << std::endl;

    }


    return tex;

}

void Game::render(SDL_Texture* tex) {
    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = 256;
    src.h = 256;

    SDL_Rect dst;
    dst.x = 0;
    dst.y = 0;
    dst.w = 256;
    dst.h = 256;

    SDL_RenderCopy(renderer,tex,&src,&dst);
}

void Game::display() {
    SDL_RenderPresent(renderer);
}

void Game::clear() {
    SDL_RenderClear(renderer);
}

void Game::cleanUp() {
    SDL_DestroyWindow(window);
}







