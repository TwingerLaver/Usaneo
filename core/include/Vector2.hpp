#ifndef VECTOR2_H
#define VECTOR2_H


#include <string>

class Vector2 {
    public: 
    Vector2();

    Vector2(float x, float y);
    Vector2 GetNormalized() const;
    Vector2 GetRotated(const float& dd) const;
    float Magnitude() const;
    float Distance(const Vector2& v) const;
    float XAxisInToInclination() const;

    Vector2& operator+=(const Vector2& rhs);
    Vector2& operator-=(const Vector2& rhs);
    Vector2& operator*=(const float& rhs);
    Vector2& operator=(const float& rhs);

    friend Vector2 operator+(Vector2& lhs, const Vector2& rhs) { 
        lhs += rhs;
        return lhs;
    }
    friend Vector2 operator-(Vector2& lhs, const Vector2& rhs) {
        lhs -= rhs;
        return lhs;
    }
    friend Vector2 operator*(Vector2& lhs, const float& rhs) {
        lhs *= rhs;
        //TODO: FIX Return rhs return rhs;
    }
    friend Vector2 operator*(const float& lhs, Vector2& rhs) {
        rhs *= lhs;
        return rhs;
    }
    std::string ToString() const {
        return std::to_string(X) + " " + std::to_string(Y);
    }
    float X;
    float Y;
};
#endif