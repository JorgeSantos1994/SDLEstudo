#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "game.h"


int main(int argc, char* argv[]){

    int _screenWith = 1024;
    int _screenHeight = 800;

    Game game("Badjoras", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWith, _screenHeight, SDL_WINDOW_SHOWN);

    SDL_Texture* frog = game.loadTexture("vfx/frog_lg.png");

    while(game.gameState != GameState::OFF){

        SDL_Event event;

        SDL_PollEvent(&event);

        switch(event.type) {
            case SDL_QUIT:
                    game.gameState = GameState::OFF;
                    break;

        }

        game.render(frog);
        game.run();


    }

return 0;
}

