#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "entity.h"
#include "window.h"
#include "render.h"

int main(int argc, char* argv[]){

    Uint32 now = SDL_GetTicks();
    const Uint32 timeout = now + 64;
    int _screenWith = 1024;
    int _screenHeight = 800;
    enum class GameState {ON, OFF};
    GameState gameState;
    
    Window window("Badjoras", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWith, _screenHeight, SDL_WINDOW_SHOWN);
   
    
    Entity entity("vfx/frog_lg.png", 0, 0, 128, 128);
    Entity backGround("vfx/background.png", 0, 0, _screenWith, _screenHeight);
    Render render(window);
    render.initRenderer();
    render.loadEntity(entity);
    render.loadEntity(backGround);

    while(gameState != GameState::OFF){

        SDL_Event event;

        SDL_PollEvent(&event);

        switch(event.type) {
            case SDL_QUIT:
                    gameState = GameState::OFF;
                    
                    break;

        }
        
    
        while(!SDL_TICKS_PASSED(now, timeout)){
            
            render.drawEntity(entity);
            // render.drawEntity(backGround);
            entity.moveEvent(event);
            
        }

        
     
    
       
    }

return 0;
}

