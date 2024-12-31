#include <SDL.h>
#include "glad/glad.h"
#include <SFML/Graphics.hpp>
int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* window = SDL_CreateWindow("Usaneo Engine", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer, 255, 50, 40, 255);
	SDL_GetCurrentVideoDriver();
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}