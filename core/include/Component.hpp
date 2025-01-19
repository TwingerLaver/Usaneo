#ifndef COMPONENT_H
#define COMPONENT_H
#include <string>
#include "GameData.hpp"
class GameObject; 
class Component {
    public:
    virtual ~Component() {}
    virtual void Update(float dt) = 0;
    virtual void Render() = 0;
    virtual bool Is(GameData::Types types) const = 0;
    protected:
    GameObject* owner;

};
#endif