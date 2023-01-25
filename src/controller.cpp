#include "controller.h"


//Initialization of the mouse input controller

Controller :: Controller(SDL_Event event) : _event(event) {
       

}


//Gets mouse coordinates to be used by interatice entities

void Controller :: mousePos(){
 
    if(_event.type == SDL_MOUSEMOTION){
            
        SDL_GetMouseState(&mx, &my);
           
    }          

}

//Detects mouse clicks, either left or right for selection of interactive entities

void Controller :: mouseClicks(){
 
    if(_event.type == SDL_MOUSEBUTTONDOWN){
            switch(_event.button.button){
                case SDL_BUTTON_LEFT:
                mLeft = true;
                break;
                case SDL_BUTTON_RIGHT:
                mRight = true;
                break;
            }
    
        }
    if(_event.type == SDL_MOUSEBUTTONUP){
            switch(_event.button.button){
                case SDL_BUTTON_LEFT:
                mLeft = false;
                break;
                case SDL_BUTTON_RIGHT:
                mRight = false;
                break;
            }
    
        }
    
}





void Controller :: arrowKeys(){

if(_event.type == SDL_KEYDOWN){
         
            switch(_event.key.keysym.sym){
                case SDLK_LEFT:
                    arrowLeft = true;
                    break;
                case SDLK_RIGHT:
                   
                    arrowRight = true;
                    break;
                case SDLK_UP:
                    
                    arrowUp = true;
                    break;
                case SDLK_DOWN:
                   
                    arrowDown = true;
                    break;
            }
}
if(_event.type == SDL_KEYUP){
         
            switch(_event.key.keysym.sym){
                case SDLK_LEFT:
                    arrowLeft = false;
                    break;
                case SDLK_RIGHT:
                   
                    arrowRight = false;
                    break;
                case SDLK_UP:
                    
                    arrowUp = false;
                    break;
                case SDLK_DOWN:
                   
                    arrowDown = false;
                    break;
            }

}

}





//gets current mouse state
void Controller :: getController(){

     while(SDL_PollEvent(&_event) != 0){
            mouseClicks();
            mousePos();  
            arrowKeys();
    } 



}



