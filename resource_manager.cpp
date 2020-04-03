#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include "resource_manager.h"
#include "shader.h"

using namespace std;

vector<Shader> ResourceManager::shaders;

bool ResourceManager::loadShader(string name, string vertexpath, string fragmentpath)
{
    Shader shader(name);
    if(!shader.loadShader(vertexpath, fragmentpath))
        return false;
    shaders.push_back(shader);
    return true;
}

Shader ResourceManager::getShader(string name)
{
    for(auto it : shaders)
    {
        if(it.getName()==name){
            return it;
        }
    }
    cout<<"cant find shader\n";
}

