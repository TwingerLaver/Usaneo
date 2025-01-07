#include <SDL2/SDL_mixer.h>
#include <iostream>
class AudioComponent { 
    private:
    std::string p_file;
    int init_audio = Mix_Init(0);
    
};