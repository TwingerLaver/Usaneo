#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_image.h>
#include "core/utils/LoaderTexture.h"
#include "SDL2/SDL_ttf.h"
#include <core/maths/maths.h>
#include "core/include/InputManager.hpp"
#include "core/Image.h"
void debug(SDL_Renderer* renderer){
    
    // Add Debug Mode
    SDL_Rect RCDebug;
    RCDebug.w = 75;
    RCDebug.h = 86;
    RCDebug.x = 0.0;
    RCDebug.y = 0.7;

    SDL_SetRenderDrawColor(renderer, 180, 212, 188, 100);
    SDL_RenderFillRect(renderer, &RCDebug);
}
const int _WIDTH = 650;
const int _HEIGHT = 512;
int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    std::string windowTitle = "Usaneo Engine";
    SDL_Window* window = SDL_CreateWindow(windowTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _WIDTH, _HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_Renderer* render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Event evt;
    bool quit = false;
    SDL_Surface sf; 
    // if(!(IMG_Init(IMG_INIT_PNG))){
    //     std::cout << "Error loading image" << std::endl;
    // }
    while(!quit) { 
        while(SDL_PollEvent(&evt) != 0){
            if (evt.type == SDL_QUIT) { 
                quit = true;
            }
        }
        debug(render); // Target Render on Rect Debug
    }
    SDL_RenderClear(render);
    SDL_RenderPresent(render);
    return 0;
}