#ifndef GRAPHICS_H_INCLUDED
#define GRAPHICS_H_INCLUDED

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

class Graphics
{
private:
    int width, height;
    int glversmajor, glversminor;
    char* title;
    GLFWwindow* window = NULL;
public:
    Graphics(int glmajor, int glminor);
    GLFWwindow* createWindow(int width, int height, char* title);
    bool initGL();
    GLFWwindow* getWindow();
    int getWidth();
    int getHeight();
};

#endif // GRAPHICS_H_INCLUDED
