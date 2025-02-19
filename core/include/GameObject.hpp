#ifndef GAMEOBJECT_H 
#define GAMEOBJECT_H
#include <memory.h>
#include <vector>
#include <string>
#include "Component.hpp"
#include "Rect.hpp"
class GameObject {
    public:
    GameObject(double priority = 1000);
    ~GameObject();

    void Update(float dt); 
    void Render(); 
    void Start(); 
    void AddComponent();
    void RemoveComponent();
    std::weak_ptr<Component> GetComponet(GameData::Types types);

    Rect box;
    double angleDrag;

    double priority;
    private:
        bool isStarted;
};
#endif