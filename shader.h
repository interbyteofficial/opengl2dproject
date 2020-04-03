#ifndef SHADER_H_INCLUDED
#define SHADER_H_INCLUDED

#include <GLFW/glfw3.h>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <iostream>

using namespace std;
using namespace glm;

class Shader
{
private:
    GLuint id;
    string shadername;

public:
    Shader();
    Shader(string name);
    Shader(string name, string vertexpath, string fragmentpath);

    void use();
    bool loadShader(string vertexpath, string fragmentpath);

    void setVec4(string name, vec4 value);
    void setMat4(string name, mat4 value);

    string getName();
    GLuint getId();
};

#endif // SHADER_H_INCLUDED
