#include <InputManager.hpp>
#include <SDL2/SDL.h>
#include <unordered_map>
#include <memory>


InputManager InputManager::instance;

InputManager& InputManager::GetInstance() {
    return instance;
}
InputManager::InputManager() {
   MouseX = 0;
   MouseY = 0;
   ::SDL_memset(mouseState, 0, sizeof(bool)*6);
   ::SDL_memset(mouseState, 0, sizeof(bool)*6);
}
InputManager::~InputManager() {}

void InputManager::Update() {
    SDL_Event event;
    UpdaterCounter += 1;
    
    SDL_GetMouseState(&MouseX, &MouseY);

    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT) { 
            QuitRequest = true;
        } else if(event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP) {
            mouseState[event.button.button] = event.type == SDL_MOUSEBUTTONDOWN;
            mouseUpdate[event.button.button] = UpdaterCounter;
        } else if(!event.key.repeat && (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)) {
            keyState[event.key.keysym.sym] = event.type == SDL_KEYDOWN;
            KeyUpdate[event.key.keysym.sym] = UpdaterCounter;
        }
    }
}
bool InputManager::MousePress(int button) const {
    return mouseState[button] && (mouseUpdate[button] != UpdaterCounter);
}
bool InputManager::IsKeyDown(int key) { 
    return keyState[key];
}
int InputManager::GetMouseX() const  {
    return MouseX;
}

bool InputManager::QuitRequested () const {
    return QuitRequest;
}
bool InputManager::Quit(int key){
     SDL_Quit();
}