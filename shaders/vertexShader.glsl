#version 100

attribute vec3 position;
attribute vec2 texcoord;
attribute vec3 color;

varying vec2 Texcoord;
varying vec3 Color;

uniform mat4 trans;
uniform mat4 view;
uniform mat4 proj;

void main()
{
    Texcoord = texcoord;
    Color = color;
    gl_Position = proj * view * trans * vec4(position, 1.0);
}
