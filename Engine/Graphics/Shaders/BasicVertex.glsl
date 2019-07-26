#version 410 core

layout (location = 0) in vec3 inPos;
layout (location = 1) in vec3 inColor;

uniform mat4 u_ModelMatrix;
uniform mat4 u_ProjectionView;

out vec3 Color;

void main()
{
	gl_Position = u_ProjectionView * u_ModelMatrix * vec4(inPos, 1.0f);
	Color = inColor;
}
