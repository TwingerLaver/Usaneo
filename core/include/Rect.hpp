#ifndef RECT_H
#define RECT_H
#include "Vector2.hpp"
#include <string>
class Rect {
    public:
    Rect(float x, float y, float w, float h);
    Vector2 Center() const;
    Rect GetCentered(Vector2 pos) const;
    Rect GetCentered(float x, float y) const;
    float Distance(const Rect& rect) const;
    bool Contains(const Vector2& point) const;
    Rect& operator+=(const Rect& rect);
    Rect& operator=(const Rect& rect);
    void Destroy_Object();
    friend Rect operator+(Rect lhs, const Vector2& rhs) { 
        // Not Defined
        return lhs;
    }
    const std::string& ToString() const {
        return std::string("x:") + std::to_string(x) + std::string(" y:") + std::to_string(y)
        + std::string(" w:") + std::to_string(w) + std::string(" h:") + std::to_string(h) + std::string(" center: ");
    }
    float x;
    float y;
    float w;
    
    float h;
};
#endif