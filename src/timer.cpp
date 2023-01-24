#include "timer.h"

Timer :: Timer(){

    //Initialize variables
    mStartTicks = 0;
    mPausedTicks = 0;

    mPaused = false;
    mStarted = false;

};

void Timer::start(){

    //Start Timer
    mStarted = true;
    
    //Unpause timer if paused
    mPaused = false;

    //Get current tick
    mStartTicks = SDL_GetTicks();
    mPausedTicks = 0;


};


void Timer::stop(){

    //Stop timer
    mStarted = false;

    //Unpause timer
    mPaused = false;

    //Clear variables
    mStartTicks = 0;
    mPausedTicks = 0;

};


void Timer::pause(){

    //If timer is running and not already paused
    if( mStarted && !mPaused ){

        mPaused = true;

        //Paused ticks
        mPausedTicks = SDL_GetTicks() - mStartTicks;
        
        mStartTicks = 0;

    }
};



void Timer::unpause(){

    //If timer is running and paused
    if( mStarted && mPaused) {
        
        mPaused = false;

        //Reset the starting ticks
        mStartTicks = SDL_GetTicks() -  mPausedTicks;

        //Reset the paused ticks
        mPausedTicks = 0;

    }

};

Uint32 Timer::getTicks(){

    //Current time varible
    Uint32 currTime = 0;

    if(mStarted){

        if(mPaused){

            currTime = mPausedTicks;

        }
        else{

            currTime = SDL_GetTicks() - mStartTicks;

        }
    }

    return currTime;
};


bool Timer::isStarted(){

    return mStarted;


};



bool Timer::isPaused(){

    return mPaused && mStarted;

};