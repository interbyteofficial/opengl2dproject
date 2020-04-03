#ifndef RESOURCE_MANAGER_H_INCLUDED
#define RESOURCE_MANAGER_H_INCLUDED

#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include "shader.h"
#include "texture.h"

using namespace std;

class ResourceManager
{
private:
    static vector<Shader> shaders;
    static vector<Texture> textures;

public:
    static bool loadShader(string name, string vertexpath, string fragmentpath);
    static bool loadTexture(string name, string path);
    static Shader getShader(string name);
    static Texture* getTexture(string name);

};

#endif // RESOURCE_MANAGER_H_INCLUDED
