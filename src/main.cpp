#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "entity.h"
#include "window.h"


int main(int argc, char* argv[]){

    Uint32 now = SDL_GetTicks();
    const Uint32 timeout = now + 16;
    int _screenWith = 1024;
    int _screenHeight = 800;

    Window window("Badjoras", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWith, _screenHeight, SDL_WINDOW_SHOWN);
   
    window.renderer();
    
    Entity entity(window, "vfx/frog_lg.png", 0, 0, 128, 128);

    
    SDL_Texture* backGround = window.loadTexture("vfx/background.png");

    while(entity.gameState != GameState::OFF){

        SDL_Event event;

        SDL_PollEvent(&event);

        switch(event.type) {
            case SDL_QUIT:
                    entity.gameState = GameState::OFF;
                    break;

        }
        
        
        
   
    while(!SDL_TICKS_PASSED(now, timeout)){
        window.render(backGround);
        entity.moveEvent(event);
        entity.render();
    }

       
    }

return 0;
}

