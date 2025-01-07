#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>

class LoadTexture {
    public:
    SDL_Texture* load_texture(const char* p_filePath);
};