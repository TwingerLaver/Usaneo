#pragma once
#include <cstdint>
struct Color {float r, g, b, a;};
class OpenGLBackend {
    public:
    virtual ~OpenGLBackend() {}
    virtual bool Init() = 0;
    virtual void Clear(const Color& color) = 0;
    virtual void DrawTriangle(float* vertices, uint32_t vertexCount) = 0;
    virtual void Present() = 0;
    virtual void Cleanup() = 0;
};