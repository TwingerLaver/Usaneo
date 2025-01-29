#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_image.h>
#include "core/utils/LoaderTexture.h"
#include "SDL2/SDL_ttf.h"
#include "core/include/InputManager.hpp"
#define RQUIT SDLK_DELETE

void use_windows() {
     #ifdef USE_WINDOWS
     SDL_Rect rect;
     
     #endif
}
void debug(){
    // Add Debug Mode
    
}
const int _WIDTH = 650;
const int _HEIGHT = 512;
int main(int argc, char* argv[]) {
    use_windows();
    SDL_Init(SDL_INIT_VIDEO);
    std::string windowTitle = "Usaneo Engine";
    SDL_Window* window = SDL_CreateWindow(windowTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _WIDTH, _HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_Renderer* render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Event evt;
    bool quit = false;
    
    
    // if(!(IMG_Init(IMG_INIT_PNG))){
    //     std::cout << "Error loading image" << std::endl;
    // }
    while(!quit) { 
        while(SDL_PollEvent(&evt) != 0){
            if (evt.type == SDL_QUIT) { 
                quit = true;
            }
            // Note: This statement Function pressed D close Alternative X 
            if(evt.type == RQUIT){
                quit = true;
            }
        }
    }

    SDL_RenderClear(render);
    SDL_RenderPresent(render);
    return 0;
}