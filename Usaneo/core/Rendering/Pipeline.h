#pragma once
#include <SDL.h>
class Pipeline {
public:
	Pipeline();
	~Pipeline();
	void render() {
		SDL_Renderer* renderer = SDL_CreateRenderer(NULL, -1, SDL_RENDERER_ACCELERATED);
	}
};