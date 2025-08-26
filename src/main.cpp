#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include "rendering/OpenGL/RendererOpenGL.h"
#include "rendering/OpenGL/2d/2d_camera.h"
#include <stdio.h>

int main() {
    // initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL Init failed: %s\n", SDL_GetError());
        return -1;
    }

    // set attribute OpenGL
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;

    SDL_Window* window = SDL_CreateWindow(
        "Usaneo - Camera Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL
    );
    if (!window) {
        printf("SDL CreateWindow failed: %s\n", SDL_GetError());
        SDL_Quit();
        return -1;
    }
    RendererOpenGL renderer(window);
    if (!renderer.Init()) {
        printf("OpenGL initialization failed\n");
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    printf("OpenGL %d.%d\n", GLVersion.major, GLVersion.minor);

    // crate and configure camera
    Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));  
    renderer.SetCamera(&camera);
    renderer.UpdateWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);

 
    Uint32 lastTime = SDL_GetTicks();
    float deltaTime = 0.0f;

   
    bool firstMouse = true;
    float lastX = WINDOW_WIDTH / 2.0f;
    float lastY = WINDOW_HEIGHT / 2.0f;

    
    SDL_SetRelativeMouseMode(SDL_TRUE);

    bool running = true;
    SDL_Event event;
    
    while (running) {

        Uint32 currentTime = SDL_GetTicks();
        deltaTime = (currentTime - lastTime) / 1000.0f;
        lastTime = currentTime;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    running = false;
                }
            }
            else if (event.type == SDL_MOUSEMOTION) {
                float xoffset = event.motion.xrel;
                float yoffset = -event.motion.yrel; 
                camera.ProcessMouseMovement(xoffset, yoffset);
            }
            else if (event.type == SDL_MOUSEWHEEL) {
                camera.ProcessMouseScroll(event.wheel.y);
            }
        }

        const Uint8* keystate = SDL_GetKeyboardState(NULL);
        
        if (keystate[SDL_SCANCODE_W])
            camera.ProcessKeyboard(FORWARD, deltaTime);
        if (keystate[SDL_SCANCODE_S])
            camera.ProcessKeyboard(BACKWARD, deltaTime);
        if (keystate[SDL_SCANCODE_A])
            camera.ProcessKeyboard(LEFT, deltaTime);
        if (keystate[SDL_SCANCODE_D])
            camera.ProcessKeyboard(RIGHT, deltaTime);
        if (keystate[SDL_SCANCODE_Q])
            camera.ProcessKeyboard(UP, deltaTime);
        if (keystate[SDL_SCANCODE_E])
            camera.ProcessKeyboard(DOWN, deltaTime);

        // Render
        renderer.Clear({0.3f, 0.3f, 0.5f, 1.0f});
        renderer.DrawTriangle(nullptr, 3);
        renderer.Present();
    }

    renderer.Cleanup();
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}