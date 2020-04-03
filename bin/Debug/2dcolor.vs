#version 330 core

layout (location = 0) in vec2 pos;

uniform mat4 projection;
uniform vec4 color;
uniform mat4 model;

out vec4 color_out;

void main()
{
    gl_Position = model * projection * vec4(pos.x, pos.y, 0.0, 1.0);
    color_out = color;
}