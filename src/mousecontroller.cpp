#include "mousecontroller.h"


//Initialization of the mouse input controller

Mousecontroller :: Mousecontroller(SDL_Event event) : _event(event) {

            mouseClicks();
            mousePos();  
         

}


//Gets mouse coordinates to be used by interatice entities

void Mousecontroller :: mousePos(){

  if(SDL_PollEvent(&_event)){
        if(_event.type == SDL_MOUSEMOTION){
            
            SDL_GetMouseState(&mx, &my);
           
        }
  }
}

//Detects mouse clicks, either left or right for selection of interactive entities

void Mousecontroller :: mouseClicks(){
 if(SDL_PollEvent(&_event)){
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
    }
}

