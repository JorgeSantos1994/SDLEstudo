#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "entity.h"
#include "button.h"
#include "frog.h"
#include "window.h"
#include "render.h"
#include "controller.h"
#include "timer.h"




int main(int argc, char* argv[]){

    const int SCREEN_FPS = 60;
    
    const int SCREEN_TICK_PER_FRAME = 1000 / SCREEN_FPS;
    
    int _screenWith = 1024;
    
    int _screenHeight = 800;
    
    enum class GameState {ON, OFF};
    
    GameState gameState;
    
    Window window("Badjoras", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWith, _screenHeight, SDL_WINDOW_SHOWN);
     
    SDL_Event event;

    Controller controller(event); 
    
    //Time management
    Timer fpsTimer;

    Timer capTimer;

    int countedFrames = 0;

    fpsTimer.start();
          
    float timeStep = 0.25;
    
    Render render(window);
 
    SDL_Renderer* _renderer = render.getRenderer();
    
    Entity backGround("vfx/background.png",_renderer, 0, 0, 0, 0, _screenWith, _screenHeight);
    
    
    Frog frog[15];

     for(int i = 0; i < 5; ++i){
        
        int x = i * 128;
      
        frog[i] = {"vfx/frog_lg.png",_renderer, 0, 0, x, 0, 128, 128};
               
    }
   
   
    Button button("vfx/button.png",_renderer, 0, 0, _screenWith - 100, _screenHeight - 100, 64, 64);


   
    

    while(gameState != GameState::OFF){


        capTimer.start();
        controller.getController();
       

        float avgFPS = countedFrames / ( fpsTimer.getTicks() / 1000.f );
		if( avgFPS > 2000000 ){
			avgFPS = 0;
		}

       

        while(SDL_PollEvent(&event) != 0){

            switch(event.type) {
                case SDL_QUIT:
                    gameState = GameState::OFF;
                    std::cout << "quit" << std::endl;
                    break;
        }
        };

        
        
        backGround.drawEntity();

        button.drawEntity();

        button.handleButtonEvents(controller, 70);

       
        std::cout << controller.arrowDown << " : " << controller.mRight << std::endl;
        std::cout << controller.mx << " : " << controller.my << std::endl;
        
        for(int i = 0; i < 5; ++i){
           
            bool readyReset;
            
            frog[i].handleEvents(controller);

            frog[i].fallEvent(_screenWith, _screenHeight, timeStep);

            frog[i].drawEntity(); 
            
            if(frog[i].getFrogState() == FrogStop){

                readyReset = true;
            }

            if(button.getButtonState()){
                
                if(!readyReset){
                     frog[i].setFrogState(FrogFall); 

                } else {
                    
                    frog[i].setFrogState(FrogReset);
                      readyReset = false;
                      

                }
               

            };
                
        

        };



            render.renderEntities();
                
            ++countedFrames;
   
            int frameTicks = capTimer.getTicks();
            
                
            if(frameTicks < SCREEN_TICK_PER_FRAME){

            SDL_Delay(SCREEN_TICK_PER_FRAME - frameTicks);
            }


    

}

    window.~Window();   
    return 0; 
}

