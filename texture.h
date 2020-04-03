#ifndef TEXTURE_H_INCLUDED
#define TEXTURE_H_INCLUDED

#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

class Texture
{
private:
    GLuint id;
    string name;

public:
    Texture();
    Texture(string name, string path);

    GLuint getId();
    string getName();
};

#endif // TEXTURE_H_INCLUDED
