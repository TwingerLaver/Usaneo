#define SDL_MAIN_HANDLED
#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_sdlrenderer2.h>
#include <SDL.h>
int main(int argc, char* argv[]) {
   
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        return -1;
    }
    SDL_Window* window = SDL_CreateWindow("Usaneo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_SHOWN);

    if(!window){
        SDL_Quit();
        return -1;
    }
    SDL_Renderer* render = SDL_CreateRenderer(window, -1, 0);
    if(!render){
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }   
    // initialize ImGui
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui_ImplSDL2_InitForSDLRenderer(window, render);
    ImGui_ImplSDLRenderer2_Init(render);
    bool running = true; 

    while(running) {
        SDL_Event e;

        while(SDL_PollEvent(&e)) {
            if(e.type == SDL_QUIT){ 
                running = false;
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
