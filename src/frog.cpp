#include "frog.h"

Frog :: Frog(){}


FrogState Frog :: getFrogState(){

   return frogstate;

  }

void Frog :: setFrogState(FrogState state){

   frogstate = state;



}

void Frog :: handleEvents(Mousecontroller& mouse){

_dst = getDst();

   if(mouse.mx <= _dst.x + _dst.w && mouse.mx >= _dst.x  && mouse.my <= _dst.y + _dst.h && mouse.my >= _dst.y)  {
        
          
         if(mouse.mLeft == true)
        {
                                
            frogstate = FrogFall; 

     

        }

        if(mouse.mRight == true)
        {
                                
            frogstate = FrogReset; 

        }      
                                           
}       
 



}

void Frog :: fallEvent(int screenWith, int screenHeight, float timeStep) {
                       
    
    
    if(frogstate == FrogFall) {
                  
        
        if(_dst.y < screenHeight - 100){
                            
            _dst.y += 25 * timeStep;
            
            setDst(_dst.x, _dst.y); 

        } else {
            frogstate = FrogStop;
            
            }


    }


    if(frogstate == FrogReset){

        setDst(_dstx, _dsty);

        
    }             
   
     
}




void Frog::moveEvent(SDL_Event event){

    std::cout << "event" << std::endl;

    while(SDL_PollEvent(&event) != 0){
        std::cout << "poll" << std::endl;
        if(event.type == SDL_KEYDOWN){
         
          std::cout << "key" << std::endl;

            switch(event.key.keysym.sym){
                case SDLK_LEFT:
                    _dst.x -=10;
                     setDst(_dst.x, _dst.y); 
                    break;
                case SDLK_RIGHT:
                    _dst.x +=10;
                     setDst(_dst.x, _dst.y); 
                    break;
                case SDLK_UP:
                    _dst.y -=10;
                     setDst(_dst.x, _dst.y); 
                    break;
                case SDLK_DOWN:
                    _dst.y +=10;
                     setDst(_dst.x, _dst.y); 
                    break;
            }
        }
    }
}

