#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/vec4.hpp>
#include <glm/common.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include "shader.h"
#include "rect2d.h"

using namespace std;
using namespace glm;

mat4 Rect2d::projection;

Rect2d::Rect2d()
{

}

Rect2d::Rect2d(int x,int y,int w,int h)
{
    this->x=x;
    this->y=y;
    this->w=w;
    this->h=h;
//    quads[0]=x;
//    quads[1]=y+h;
//    quads[2]=x;
//    quads[3]=y;
//    quads[4]=x+w;
//    quads[5]=y;
//    quads[6]=x;
//    quads[7]=y+h;
//    quads[8]=x+w;
//    quads[9]=y;
//    quads[10]=x+w;
//    quads[11]=y+h;

    float quads[] = { 0, 0,
              0, 1,
              1, 1,
              1, 0};
    float indexes[] = {0,1,2,
                       0,2,3};
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glGenVertexArrays(1, &VAO);

    //set up vbo
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(quads), quads, GL_DYNAMIC_DRAW);
    //set up ebo
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexes), indexes, GL_DYNAMIC_DRAW);
    //set up vao
    glBindVertexArray(VAO);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float)*2, 0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Rect2d::setShader(Shader shader)
{
    this->shader = shader;
}

void Rect2d::setResolution(int width, int height)
{
    projection = ortho(0.0f, (float)width, 0.0f, (float)height, -1.0f, 1.0f);
}
void Rect2d::setColor(int r, int g, int b, int alpha)
{
    color = vec4(1.0,0.0,0.0,1.0);
}

void Rect2d::render()
{
    cout<<"use shader\n";
    shader.use();

    cout<<1<<endl;
    shader.setVec4("color",color);
    cout<<1<<endl;
    shader.setMat4("projection",projection);
    cout<<1<<endl;
    glm::mat4 model;
    model = glm::translate(model, glm::vec3(x, y, 0.0f));
    model = glm::scale(model, glm::vec3(w, h, 1.0f));
    shader.setMat4("model", model);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
}
