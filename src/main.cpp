#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "entity.h"
#include "window.h"


int main(int argc, char* argv[]){

    int _screenWith = 1024;
    int _screenHeight = 800;

    Window window("Badjoras", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWith, _screenHeight, SDL_WINDOW_SHOWN);
   
    window.renderer();
    
    Entity entity(window, 0, 0, 128, 128);

    SDL_Texture* frog = entity.loadTexture("vfx/frog_lg.png");
    SDL_Texture* backGround = window.loadTexture("vfx/background.png");

    while(entity.gameState != GameState::OFF){

        SDL_Event event;

        SDL_PollEvent(&event);

        switch(event.type) {
            case SDL_QUIT:
                    entity.gameState = GameState::OFF;
                    break;

        }

        window.render(backGround);
        entity.render(frog);
        entity.moveEvent();


    }

return 0;
}

