#version 330 core

out vec4 FragColor;
in vec4 color_out;

void main()
{
    FragColor = color_out;
}