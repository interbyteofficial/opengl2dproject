#ifndef RECT2D_H_INCLUDED
#define RECT2D_H_INCLUDED

#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include "shader.h"

using namespace std;
using namespace glm;

class Rect2d
{
private:
    float quads[8];
    unsigned int indixes[6];
    int x,y,w,h;
    vec4 color = vec4(0.0,0.0,0.0,1.0);
    GLuint VAO, VBO, EBO;
    Shader shader;
    static mat4 projection;

public:
    Rect2d();
    Rect2d(int x,int y,int w,int h);
    void setColor(int r,int g,int b,int alpha = 255);
    void setShader(Shader shader);
    static void setResolution(int width, int height);
    void render();
};

#endif // RECT2D_H_INCLUDED
