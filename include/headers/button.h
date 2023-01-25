#ifndef BUTTON
#define BUTTON

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "entity.h"
#include "controller.h"



class Button : public Entity {

public:
    Button();
    using Entity::Entity;
    void handleButtonEvents(Controller& controller, int selectableOffset);
    bool getButtonState();

private:
    const char* _texPath;
    bool buttonState = false;
    SDL_Texture* _tex = nullptr;
    SDL_Renderer* _renderer = nullptr;
    SDL_Rect _src;
    SDL_Rect _dst;













};















#endif
