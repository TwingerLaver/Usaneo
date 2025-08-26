#pragma once
#include "OpenGLBackend.h"
#include <SDL2/SDL.h>
#include <glad/glad.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "rendering/OpenGL/2d/2d_camera.h"

struct RendererSettings { 
    int msaaSamples = 1;
    bool vsync = true;
    
    void SetMsaa(int samples) { msaaSamples = samples; }
    void SetVSync(bool enabled) { vsync = enabled; }
};

struct Object3D {
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale = glm::vec3(1.0f);
    GLuint shaderProgram;
    GLuint vao = 0;
    GLuint texture = 0;
    GLsizei indexCount = 0;
    GLuint vbo = 0;

    glm::mat4 getModelMatrix() const {
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, position);
        model = glm::rotate(model, glm::radians(rotation.x), glm::vec3(1,0,0));
        model = glm::rotate(model, glm::radians(rotation.y), glm::vec3(0,1,0));
        model = glm::rotate(model, glm::radians(rotation.z), glm::vec3(0,0,1));
        model = glm::scale(model, scale);
        return model;
    }
};

class RendererOpenGL : public OpenGLBackend {
    SDL_Window* window;
    SDL_GLContext context;
    GLuint vao, vbo;
    GLuint texture;
    GLuint shaderProgram;
    RendererSettings settings;
    Camera* camera;
    
   
    int windowWidth, windowHeight;

public:
    RendererOpenGL(SDL_Window* win);
    ~RendererOpenGL() override;
    bool Init() override;
    void Clear(const Color& color) override;
    bool LoadTexture(const char *path);
    void DrawTriangle(float *vertices, uint32_t vertexCount) override;
    void DrawObject(const Object3D& obj);
    void Cleanup() override;
    void Present() override;


    void SetCamera(Camera* cam) { camera = cam; }
    Camera* GetCamera() { return camera; }
    
    void UpdateWindowSize(int width, int height) { 
        windowWidth = width; 
        windowHeight = height; 
        glViewport(0, 0, width, height);
    }

    RendererSettings& GetSettings() { return settings; }
};