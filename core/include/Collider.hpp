#ifndef COLLIDER_H
#define COLLIDER_H

#include "Component.hpp"
#include "GameData.hpp"
#include "Vector2.hpp"
#include <string>
#include <memory>

class Collider : public Component {
    public:
    Collider(GameObject& ass, Vector2 scale = {1, 1}, Vector2 offset = {0,0});
    void Update(float dt) override;
    bool Is(GameData::Types types) const override;
    void Render() override;

    const GameData::Types Type = GameData::Types::Collider;

    private:
    Vector2 scale;
    Vector2 offset;
    
};
#endif 