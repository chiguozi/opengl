#version 330 core

out vec4 FragColor;

in vec2 Texcoords;

uniform sampler2D texture1;

void main()
{
	vec3 texColor = texture(texture1, Texcoords).rgb;
	FragColor = vec4(texColor, 1.0);
}