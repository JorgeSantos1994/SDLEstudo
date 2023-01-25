#include "button.h"


Button :: Button(){}

void Button :: handleButtonEvents(Mousecontroller& mouse, int selectableOffset){


_dst = getDst();
buttonState = false;


    if(mouse.mx <= _dst.x + _dst.w && mouse.mx >= _dst.x  && mouse.my <= _dst.y + _dst.h && mouse.my >= _dst.y)  {
        
         setSrc(_srcx + selectableOffset,_srcy);
         
         if(mouse.mLeft == true)
        {
                                
            buttonState = true; 
            
        } 

} else{setSrc(_srcx,_srcy);}      

};


bool Button :: getButtonState(){

    return buttonState;

}
