#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "graphics.h"
#include "rect2d.h"

using namespace std;

Graphics::Graphics(int glmajor, int glminor)
    : glversmajor(glmajor), glversminor(glminor)
{

}
GLFWwindow* Graphics::createWindow(int width, int height, char* title)
{
    this->width = width;
    this->height = height;

    glfwInit();
    window = glfwCreateWindow(width,height,title,NULL,NULL);
    glfwMakeContextCurrent(window);
    glfwWindowHint(GLFW_VERSION_MAJOR, glversmajor);
    glfwWindowHint(GLFW_VERSION_MINOR, glversminor);
    //glewExperimental = GL_TRUE;
    glewInit();

    Rect2d::setResolution(width, height);
}
bool Graphics::initGL()
{
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    glViewport(0,0,width,height);
}
GLFWwindow* Graphics::getWindow()
{
    return window;
}
int Graphics::getWidth()
{
    return width;
}
int Graphics::getHeight()
{
    return height;
}
