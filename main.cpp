#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "resource_manager.h"
#include "graphics.h"
#include "rect2d.h"

using namespace std;

int main()
{
    Graphics graphics(3,3);
    graphics.createWindow(512,512,"quake");
    glClearColor(0.0,1.0,1.0,1.0);

    ResourceManager::loadShader("2d_color","2dcolor.vs","2dcolor.fs");

    Rect2d rect(10,10,64,64);
    rect.setShader(ResourceManager::getShader("2d_color"));
    rect.setColor(1.0,1.0,0.0,1.0);

    GLFWwindow* window = graphics.getWindow();
    while(!glfwWindowShouldClose(window)){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glfwPollEvents();

        rect.render();

        glfwSwapBuffers(window);
    }

    return 0;
}
