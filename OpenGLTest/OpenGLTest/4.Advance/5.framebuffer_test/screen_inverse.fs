#version 330 core

out vec4 FragColor;

in vec2 Texcoords;

uniform sampler2D texture1;

void main()
{
	FragColor = vec4(vec3(1.0 - texture(texture1, Texcoords)), 1.0);
}