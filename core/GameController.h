#define GAME_CONTROLLER_H
#include <SDL2/SDL_gamecontroller.h>
class GameController {
public:
    SDL_GameController* controller; 
    GameController();
    ~GameController();
    void input();
};