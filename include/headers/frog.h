#ifndef FROG
#define FROG

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "entity.h"
#include "controller.h"


enum FrogState {
    
    
    FrogStop, 
    FrogFall,
    FrogReset,
    

    };


class Frog : public Entity {

public:
    Frog();
    using Entity::Entity;
    FrogState getFrogState();
    void setFrogState(FrogState state);
    void handleEvents(Controller& mouse);
    void fallEvent(int screenWith, int screenHeight, float timeStep);
    
   

private:
    const char* _texPath;
    FrogState frogstate;
    SDL_Texture* _tex = nullptr;
    SDL_Renderer* _renderer = nullptr;
    SDL_Rect _src;
    SDL_Rect _dst;















};








#endif