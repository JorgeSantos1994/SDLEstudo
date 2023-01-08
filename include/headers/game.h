#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>


enum class GameState {ON, OFF};


class Game {

    public:
        Game(const char* title, int x, int y, int w, int h, Uint32 flags);
        GameState gameState;
        SDL_Texture* loadTexture(const char*  filePath);
        void render(SDL_Texture* tex);
        void run();
    
    private:
        void clear();
        void display();
        void cleanUp();
        SDL_Window* window;
        SDL_Renderer* renderer;


};



