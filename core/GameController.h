#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H
#include <SDL2/SDL_gamecontroller.h>
#include <iostream>
class GameController {
public:
    #ifdef USE_PS5
    if(SDL_CONTROLLER_TYPE_PS5) { 
        printf("USE PS5");
    }
    #endif
    GameController();
    SDL_Joystick* joystick;
    SDL_GameController* controller;
    ~GameController();
    void input() {
        if(SDL_JoystickGetButton(joystick, 1)){
            std::cerr << "EEEH i not idea what button 8 is" << std::endl;
        } 
    }
};
#endif