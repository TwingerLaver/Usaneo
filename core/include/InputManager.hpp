#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H
#include "SDL2/SDL.h"
#include <string>
#include <unordered_map>
#define LEFT_ARROW  // Not Defined Input
#define RIGHT_ARROW // Not Defined Input 
#define UP_ARROW SDLK_UP
#define W_KEY SDLK_w
#define A_KEY SDLK_a
#define E_Key SDLK_e
#define QUIT SDLK_F4

class InputManager {
    public: 
    void Update();

    bool KeyPress(int key);
    bool KeyRelease(int key);
    bool IsKeyDown(int key);
    bool Quit(int key);
    bool MousePress(int button) const;
    bool MouseRelease(int button) const;
    bool IsMouseButtonDown(int button) const;

    int GetMouseX() const;
    int GetMouseY() const;
    
    bool QuitRequested() const;
    
    static InputManager& GetInstance();
  private:
  static InputManager instance;
    InputManager();
    ~InputManager();
    
    bool mouseState[6];
    int mouseUpdate[6];
    bool KeyQuit[1];
    std::unordered_map<int, bool> keyState;
    std::unordered_map<int, bool> KeyUpdate;
    std::unordered_map<int, bool> KeysQuiter;
    bool QuitRequest;
    int UpdaterCounter; 
    int MouseX;
    int MouseY;
};

#endif