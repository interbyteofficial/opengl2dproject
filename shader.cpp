#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "shader.h"

using namespace std;

Shader::Shader() {}

Shader::Shader(string name)
    : shadername(name)
{

}

Shader::Shader(string name, string vertexpath, string fragmentpath)
    : shadername(name)
{
    if(!loadShader(vertexpath,fragmentpath)) cout<<"cannot load shader\n";
}

bool Shader::loadShader(string vertexpath, string fragmentpath)
{
    GLuint shaderid, vertexid, fragmentid;
    string code_vertex, code_fragment;
    ifstream file_vertex, file_fragment;

    file_vertex.open(vertexpath);
    stringstream ssvertex;
    ssvertex << file_vertex.rdbuf();
    code_vertex = ssvertex.str();
    file_vertex.close();
    if(code_vertex.size()==0){
        cout<<"ERROR: SHADER LOAD ERROR\n File \""<<vertexpath<<"\" is empty!\n"<<endl;
    }

    file_fragment.open(fragmentpath);
    stringstream ssfragment;
    ssfragment << file_fragment.rdbuf();
    code_fragment = ssfragment.str();
    file_fragment.close();
    if(code_fragment.size()==0){
        cout<<"ERROR: SHADER LOAD ERROR\n File \""<<fragmentpath<<"\" is empty!\n"<<endl;
    }

    const char* buffer_vertex = code_vertex.c_str();
    vertexid = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexid, 1, &buffer_vertex, NULL);
    glCompileShader(vertexid);
    GLint success;
    GLchar infolog[1024];
    glGetShaderiv(vertexid, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(vertexid, 1024, NULL, infolog);
        cout<<"SHADER ERROR: COMPILE "<<vertexpath<<"\n"<<infolog<<endl;
        return false;
    }

    const char* buffer_fragment = code_fragment.c_str();
    fragmentid = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentid, 1, &buffer_fragment, NULL);
    glCompileShader(fragmentid);
    glGetShaderiv(fragmentid, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(fragmentid, 1024, NULL, infolog);
        cout<<"SHADER ERROR: COMPILE "<<fragmentpath<<"\n"<<infolog<<endl;
        return false;
    }

    id = glCreateProgram();
    glAttachShader(id, vertexid);
    glAttachShader(id, fragmentid);
    glLinkProgram(id);

    glDeleteShader(vertexid);
    glDeleteShader(fragmentid);
    return true;
}

void Shader::use(){
    glUseProgram(id);
}

void Shader::setVec4(string name, vec4 value)
{
    glUniform4f(glGetUniformLocation(id, name.c_str()), value.x, value.y, value.z, value.w);
}

void Shader::setMat4(string name, mat4 value)
{
    glUniformMatrix4fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, &value[0][0]);
}

string Shader::getName(){
    return shadername;
}
GLuint Shader::getId(){
    return id;
}
