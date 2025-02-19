#include "AudioComponent.h"

void AudioComponent::music(Mix_Music* music){
    if (music == NULL){
        std::cerr << "i not imported Music" << std::endl;
        return;
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0){
        std::cerr << "Error opening the audio" << Mix_GetError << std::endl;

    }
    if(Mix_PlayMusic(music, -1) == -1){
        std::cerr << "Error to Playing music" << Mix_GetError << std::endl;
        Mix_CloseAudio();
        return;
    }
    while(Mix_PlayingMusic()){
        SDL_Delay(5000);
    }
}