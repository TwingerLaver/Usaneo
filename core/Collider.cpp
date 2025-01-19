#ifdef DEBUG
#include <cmath>
#include <iostream>
#include <SDL2/SDL.h>
#endif  // DEBUG 
#include "Collider.hpp"
#include "GameData.hpp"
#include "GameObject.hpp"

Collider::Collider(GameObject& assc, Vector2 scale, Vector2 offset) : Component(), scale(scale), offset(offset) {

}
void Collider::Update(float dt) {

}

bool Collider::Is(GameData::Types types) const {
    return types == this->Type;
}
