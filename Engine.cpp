#include <SDL2/SDL.h>
#include <iostream>



int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Usaneo Engine", 100, 100, 600, 512,SDL_WINDOW_SHOWN);
    SDL_Renderer* render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(render, 84, 85, 255, 255);
    SDL_GetCurrentVideoDriver();
    SDL_RenderClear(render);
    SDL_RenderPresent(render);
    SDL_Delay(5000);
}
