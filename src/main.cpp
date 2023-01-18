#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "entity.h"
#include "window.h"
#include "render.h"
#include "mousecontroller.h"

int main(int argc, char* argv[]){

    Uint32 tick = SDL_GetTicks();
    Uint32 elapsed = tick + 64;
    int _screenWith = 1024;
    int _screenHeight = 800;
    enum class GameState {ON, OFF};
    GameState gameState;
    
    Window window("Badjoras", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWith, _screenHeight, SDL_WINDOW_SHOWN);
    
    



    Render render(window);
 
    SDL_Renderer* _renderer = render.getRenderer();
    
    
    Entity backGround("vfx/background.png",_renderer, 0, 0, 0, 0, _screenWith, _screenHeight);
    
    
    Entity entity[3];

    for(int i = 0; i < 2; ++i){
        
        int x = i * 128;
        int y = i * 128;
        entity[i] = {"vfx/frog_lg.png",_renderer, 0, 0, x, y, 128, 128};
               
    }
   

    while(gameState != GameState::OFF){

        SDL_Event event;

        SDL_PollEvent(&event);

        switch(event.type) {
            case SDL_QUIT:
                    gameState = GameState::OFF;
                    
                    break;

        }
         
    
        while(!SDL_TICKS_PASSED(tick, elapsed)){
             
            Mousecontroller mouse(event);
            backGround.drawEntity();
            
          
            for(int i = 0; i < 2; ++i){
                entity[i].drawEntity();
                entity[i].fallEvent(event, mouse, _screenWith, _screenHeight);
            }
            


           
            
            

            render.renderEntities();
          
            elapsed = tick + 64;
        }
        
     
    
       
    }

return 0;
}

