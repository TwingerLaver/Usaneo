#include "GameObject.hpp"
#include "Component.hpp"

GameObject::GameObject(double priority) : isStarted(false), angleDrag(0), priority(priority), box(box) {}

GameObject::~GameObject() { 
    
}
void GameObject::RemoveComponent(){
    
}