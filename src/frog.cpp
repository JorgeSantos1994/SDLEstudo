#include "frog.h"

Frog :: Frog(){}


FrogState Frog :: getFrogState(){

   return frogstate;

  }

void Frog :: setFrogState(FrogState state){

   frogstate = state;



}

void Frog :: handleEvents(Controller& controller){

_dst = getDst();

if(controller.mx <= _dst.x + _dst.w && controller.mx >= _dst.x  && controller.my <= _dst.y + _dst.h && controller.my >= _dst.y)  {
        
          
    if(controller.mLeft == true)
    {
                                
        frogstate = FrogFall; 

    }

    if(controller.mRight == true)
    {
                                
        frogstate = FrogReset; 

    }      
                                           
}       
        
if(controller.arrowDown == true){

        _dst.y +=10;
         setDst(_dst.x, _dst.y); 
    }

if(controller.arrowUp == true){

        _dst.y -=10;
         setDst(_dst.x, _dst.y);  
    }

if(controller.arrowLeft == true){

         _dst.x -=10;
         setDst(_dst.x, _dst.y); 
    }
if(controller.arrowRight == true){

        _dst.x +=10;
         setDst(_dst.x, _dst.y); 
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




