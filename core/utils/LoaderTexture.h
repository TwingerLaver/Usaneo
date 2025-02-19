#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>

class LoadTexture {
    public:
    SDL_Renderer* render;
    SDL_Texture* texture;

    LoadTexture(SDL_Renderer* render) : render(), texture(nullptr) {}

    bool load_texture(const std::string& filepath){
        texture = IMG_LoadTexture(render, filepath.c_str());
        if(!texture){ 
            std::cerr << "Error" << IMG_GetError << std::endl;
            return false;
        }
        return true;
    }
};