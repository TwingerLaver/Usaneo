#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL.h>
#include <iostream>
class AudioComponent { 
    private:
    std::string p_file;

    public:
    void music(Mix_Music* music);
};