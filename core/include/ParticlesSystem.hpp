#ifndef PARTICLESYSTEM_HPP
#define PARTICLESYSTEM_HPP 
#include "core/include/Vector2.hpp"
#include "SDL2/SDL.h"
#include <cstdlib>
#include <ctime>

class Particle {
    public:
    Vector2 position;
    Vector2 velocity;
    double life;
    Particle(double x, double y){
        position.x = Vector2(x, y);
        velocity = Vector2((rand() % 10 - 5), (rand() % 10 - 5));
        life = rand() % 100 / 10.0 + 1.0;
    }
    void Update(){
        position.x += velocity.x;
        position.y += velocity.y;
        life -= 0.1;
    }
    bool IsAlive() const {
        return life > 0;
    }
}
#endif