#ifndef MATHS_H
constexpr double MATH_PI = 3.141592653589793;
constexpr double DEG_TO_RAD = MATH_PI / 180.0;

template <typename T> 
constexpr T Clamp(T value, T min, T max){
    return (value < min) ? min : (value > max) ? max : value;
}
template <typename T>
constexpr T Lerp(T a, T b, float t){
    return a + t * (b - a);
}

#endif