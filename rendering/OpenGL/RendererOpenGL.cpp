#include "RendererOpenGL.h"
#include <stdio.h>

RendererOpenGL::RendererOpenGL(SDL_Window* win) 
    : window(win), vao(0), vbo(0), context(nullptr), shaderProgram(0), camera(nullptr), windowWidth(800), windowHeight(600) {}

RendererOpenGL::~RendererOpenGL() { Cleanup(); }

bool RendererOpenGL::Init() {
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, settings.msaaSamples > 1 ? 1 : 0);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, settings.msaaSamples);
    
    context = SDL_GL_CreateContext(window);
    if (!context) return false;
    
    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
        printf("Failed to initialize GLAD\n");
        return false;
    }
    
    if(settings.msaaSamples > 1) { 
        glEnable(GL_MULTISAMPLE);
    }
    glEnable(GL_DEPTH_TEST);

    // Setup triangolo base
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Shader con supporto per matrici MVP
    const char* vertexShaderSource = R"(#version 460 core
    layout(location = 0) in vec3 aPos;
    
    uniform mat4 uModel;
    uniform mat4 uView;
    uniform mat4 uProjection;
    uniform mat4 uMVP;
    
    void main(){
        gl_Position = uMVP * vec4(aPos, 1.0);
    })";

    const char* fragmentShaderSource = R"(#version 460 core
    out vec4 FragColor;
    void main(){
        FragColor = vec4(1.0, 0.5, 0.2, 1.0);
    })";

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    // Controlla errori di compilazione del vertex shader
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        printf("Vertex shader compilation failed: %s\n", infoLog);
    }

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    // Controlla errori di compilazione del fragment shader
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        printf("Fragment shader compilation failed: %s\n", infoLog);
    }

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // Controlla errori di linking del programma
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        printf("Shader program linking failed: %s\n", infoLog);
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return true;
}

void RendererOpenGL::Clear(const Color& color) {
    glClearColor(color.r, color.g, color.b, color.a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void RendererOpenGL::DrawTriangle(float* vertices, uint32_t count) {
    if (!camera) {
        printf("Warning: No camera set for rendering\n");
        return;
    }

    glUseProgram(shaderProgram);
    
    // Calcola le matrici
    glm::mat4 model = glm::mat4(1.0f); // Matrice identità per il triangolo
    glm::mat4 view = camera->GetViewMatrix();
    glm::mat4 projection = camera->GetProjectionMatrix(windowWidth, windowHeight);
    glm::mat4 mvp = projection * view * model;

    // Passa le matrici agli shader
    GLint modelLoc = glGetUniformLocation(shaderProgram, "uModel");
    GLint viewLoc = glGetUniformLocation(shaderProgram, "uView");
    GLint projLoc = glGetUniformLocation(shaderProgram, "uProjection");
    GLint mvpLoc = glGetUniformLocation(shaderProgram, "uMVP");

    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
    glUniformMatrix4fv(mvpLoc, 1, GL_FALSE, glm::value_ptr(mvp));

    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
    glUseProgram(0);
}

void RendererOpenGL::DrawObject(const Object3D& obj) {
    if (!camera) {
        printf("Warning: No camera set for rendering\n");
        return;
    }

    glUseProgram(obj.shaderProgram);
    
    glm::mat4 model = obj.getModelMatrix();
    glm::mat4 view = camera->GetViewMatrix();
    glm::mat4 projection = camera->GetProjectionMatrix(windowWidth, windowHeight);
    glm::mat4 mvp = projection * view * model;

    GLint mvpLoc = glGetUniformLocation(obj.shaderProgram, "uMVP");
    glUniformMatrix4fv(mvpLoc, 1, GL_FALSE, glm::value_ptr(mvp));

    glBindVertexArray(obj.vao);
    glDrawElements(GL_TRIANGLES, obj.indexCount, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    glUseProgram(0);
}

void RendererOpenGL::Present() {
    SDL_GL_SwapWindow(window);
}

void RendererOpenGL::Cleanup() {
    if (shaderProgram) glDeleteProgram(shaderProgram);
    if (context) SDL_GL_DeleteContext(context);
    if (vao) glDeleteVertexArrays(1, &vao);
    if (vbo) glDeleteBuffers(1, &vbo);
}