#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_sdlrenderer2.h>
#include <SDL.h>
#include <SDL_mixer.h>
#include <iostream>
int main(int argc, char* argv[]) {
   
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0){
        return -1;
    }
      if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "Mix_OpenAudio Error: " << Mix_GetError() << std::endl;
    }

    SDL_Window* window = SDL_CreateWindow("Usaneo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_SHOWN);

    if(!window){
        SDL_Quit();
        return -1;
    }
    SDL_Renderer* render = SDL_CreateRenderer(window, -1, 0);
    std::string basePath = SDL_GetBasePath();
    if(!render){
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    std::string soundPath = basePath + "soundscrate-SciFi_Weapon_Blast_10.wav";
    Mix_Chunk* sound = Mix_LoadWAV(soundPath.c_str());
    // initialize ImGui
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui_ImplSDL2_InitForSDLRenderer(window, render);
    ImGui_ImplSDLRenderer2_Init(render);
    bool running = true;
    SDL_Event e; 
    while(running) {

        while(SDL_PollEvent(&e)) {
            if(e.type == SDL_QUIT){ 
                running = false;
            }

            if(e.type == SDL_MOUSEBUTTONUP) { 
                Mix_PlayChannel(-1, sound, 0);
            }
            ImGui_ImplSDL2_ProcessEvent(&e);
        }
        ImGui_ImplSDLRenderer2_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();
        ImGui::Begin("Tesrt");
        ImGui::Text("Hello, world!");
        ImGui::End();
        ImGui::Text("Fps: %.1f", ImGui::GetIO().Framerate);
        ImGui::Render();
        SDL_SetRenderDrawColor(render, 0, 0, 1, 255); 
        SDL_RenderClear(render);
        ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), render);
        SDL_RenderPresent(render);
    }
    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
