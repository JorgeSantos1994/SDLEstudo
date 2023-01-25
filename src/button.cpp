#include "button.h"


Button :: Button(){}

void Button :: handleButtonEvents(Controller& controller, int selectableOffset){


_dst = getDst();
buttonState = false;


    if(controller.mx <= _dst.x + _dst.w && controller.mx >= _dst.x  && controller.my <= _dst.y + _dst.h && controller.my >= _dst.y)  {
        
         setSrc(_srcx + selectableOffset,_srcy);
         
         if(controller.mLeft == true)
        {
                                
            buttonState = true; 
            
        } 

} else{setSrc(_srcx,_srcy);}      

};


bool Button :: getButtonState(){

    return buttonState;

}
